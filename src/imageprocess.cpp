#include "imageprocess.h"

#include "qdebug.h"
#include <Windows.h> 
#include <QtConcurrent>
#include "imagefifo.h"

//#include "qtextstream.h"

ImageProcess::ImageProcess(int height, int width)
	:m_imageHeight(height),
	m_imageWidth(width),
	m_data_height(256),
	m_data_width(324),
	m_image_color_flag(COLOR_IMAGE),
	m_flag_video(false),
	m_is_self_adaptive(true),
	m_imageProcessingFlag(true),
	m_pauseFlag(false),
	m_path("."),
	m_isTakingImage(false)
{
	m_imageData = new uchar[height *width];
	setLookUpTable();

}

ImageProcess::~ImageProcess()
{
	delete[] m_imageData;

}

void ImageProcess::setDataSavingSpace(unsigned char *data)
{
	m_imageData = data;
}


void ImageProcess::dataToImage(unsigned char *data, int bitsPerPixel, int width, int height)
{
	m_image_16bit = Mat(height, width, CV_16UC1, data);
	medianBlur(m_image_16bit, m_image_16bit, 3);//中值模糊

	minMaxLoc(m_image_16bit, &m_min_pixel, &m_max_pixel, 0, &m_max_pixel_position);
	m_avg_pixel = mean(m_image_16bit);

	Mat image_16bit_tmp;
	image_16bit_tmp = m_image_16bit.clone();

	//16bit转8bit图像处理
	gray14bitTo8bit(image_16bit_tmp);

	//16bit转8bit图像
	Mat image_8bit;
	image_16bit_tmp.convertTo(image_8bit, CV_8UC1); 
	//单通道变为3通道
	Mat image_tmp;
	cv::cvtColor(image_8bit, image_tmp, CV_GRAY2RGB);//image_tmp是3通道的

	switch (m_image_color_flag)
	{
	case GRAY_IMAGE:
	{
		Point point1(m_max_pixel_position.x - 5, m_max_pixel_position.y);
		Point point2(m_max_pixel_position.x + 5, m_max_pixel_position.y);
		Point point3(m_max_pixel_position.x, m_max_pixel_position.y - 5);
		Point point4(m_max_pixel_position.x, m_max_pixel_position.y + 5);
		line(image_tmp, point1, point2, Scalar(255, 0, 0));
		line(image_tmp, point3, point4, Scalar(255, 0, 0));

		QImage image_final = QImage(image_tmp.data, image_tmp.cols, image_tmp.rows, image_tmp.step, QImage::Format_RGB888);
		m_pixmap = QPixmap::fromImage(image_final);

	}
	break;
	case COLOR_IMAGE:
	{
		//gray14bitToColor(m_image_16bit, image_tmp);
		//查找表法，效率高
		LUT(image_tmp, m_look_up_table_color, image_tmp);

		Point point1(m_max_pixel_position.x - 5, m_max_pixel_position.y);
		Point point2(m_max_pixel_position.x + 5, m_max_pixel_position.y);
		Point point3(m_max_pixel_position.x, m_max_pixel_position.y - 5);
		Point point4(m_max_pixel_position.x, m_max_pixel_position.y + 5);
		line(image_tmp, point1, point2, Scalar(255, 0, 0));
		line(image_tmp, point3, point4, Scalar(255, 0, 0));

		QImage image_final = QImage(image_tmp.data, image_tmp.cols, image_tmp.rows, image_tmp.step, QImage::Format_RGB888);
		m_pixmap = QPixmap::fromImage(image_final);
	}
	break;
	case RAINBOW_IMAGE:
	{
		LUT(image_tmp, m_look_up_table_rainbow, image_tmp);

		Point point1(m_max_pixel_position.x - 5, m_max_pixel_position.y);
		Point point2(m_max_pixel_position.x + 5, m_max_pixel_position.y);
		Point point3(m_max_pixel_position.x, m_max_pixel_position.y - 5);
		Point point4(m_max_pixel_position.x, m_max_pixel_position.y + 5);
		line(image_tmp, point1, point2, Scalar(0, 0, 0));
		line(image_tmp, point3, point4, Scalar(0, 0, 0));

		QImage image_final = QImage(image_tmp.data, image_tmp.cols, image_tmp.rows, image_tmp.step, QImage::Format_RGB888);
		m_pixmap = QPixmap::fromImage(image_final);
	}
	break;
	case GRAY_INVERSE_IMAGE:
	{
		//使用查找表法反转
		LUT(image_tmp, m_look_up_table_gray_inv, image_tmp);

		Point point1(m_max_pixel_position.x - 5, m_max_pixel_position.y);
		Point point2(m_max_pixel_position.x + 5, m_max_pixel_position.y);
		Point point3(m_max_pixel_position.x, m_max_pixel_position.y - 5);
		Point point4(m_max_pixel_position.x, m_max_pixel_position.y + 5);
		line(image_tmp, point1, point2, Scalar(255, 0, 0));
		line(image_tmp, point3, point4, Scalar(255, 0, 0));

		QImage image_final = QImage(image_tmp.data, image_tmp.cols, image_tmp.rows, image_tmp.step, QImage::Format_RGB888);
		m_pixmap = QPixmap::fromImage(image_final);

	}
	break;
	}

	if (m_isTakingImage)
	{
		DWORD start = GetTickCount();
		takeShowingImage(m_pixmap);
		DWORD end = GetTickCount();
		qDebug() << end - start << "this is the time";
	}

	emit showImage(m_pixmap);

	//写入视频
	m_final_image = image_tmp.clone();
	cv::cvtColor(m_final_image, m_final_image, CV_RGB2BGR);
	if (m_flag_video)
	{
		m_video_writer.write(m_final_image);
	}
	
	//QMetaObject::invokeMethod(m_imageshow, "updateImage", Qt::QueuedConnection);
}

void ImageProcess::gray14bitTo8bit(Mat &src)
{
	if (!m_is_self_adaptive)
	{
		for (int i = 0; i < m_data_height; i++)
		{
			unsigned short *data = src.ptr<unsigned short>(i);
			for (int j = 0; j < m_data_width; j++)
			{
				if (data[j] <= m_contrast_lower)
				{
					data[j] = 0;
				}
				else if (data[j] >= m_contrast_upper)
				{
					data[j] = 255;
				}
				else
				{
					data[j] = (data[j] - m_contrast_lower + 0.0) / (m_contrast_upper - m_contrast_lower) * 255;
				}
			}
		}
	}
	else
	{
		/*************自适应直方图******************/
		//计算直方图
		int histSize[1] = { 0xffff + 1 };
		float hrangs[2] = { 0, 0xffff };
		const float* ranges[1] = { hrangs };
		int channels[1] = { 0 };
		Mat hist;
		calcHist(&src, 1, channels, Mat(), hist, 1, histSize, ranges);
		int imin = 0;
		for (; imin < histSize[0]; imin++)
			if (hist.at<float>(imin) > 10)     //改为可调界限
				break;
		int imax = histSize[0] - 1;
		for (; imax >= 0; imax--)
			if (hist.at<float>(imax) > 0 || imin > imax)
				break;

		if (imin > imax)
		{
			imax = imin;
			imin = imin - 2;
		}

		for (int i = 0; i < m_data_height; i++)
		{
			unsigned short *data = src.ptr<unsigned short>(i);
			for (int j = 0; j < m_data_width; j++)
			{
				if (data[j] <= imin)
				{
					data[j] = 0;
				}
				else if (data[j] >= imax)
				{
					data[j] = 255;
				}
				else
				{
					data[j] = (data[j] - imin + 0.0) / (imax - imin) * 255;
				}
			}
		}
	}
}

void ImageProcess::setLookUpTable()
{
	//伪彩查找表 RGB排列方式
	m_look_up_table_color = Mat(1, 256, CV_8UC3);
	uchar *p1 = m_look_up_table_color.data;
	//
	for (int i = 0; i < 256; i++)
	{
		if (i >= 0 && i < 22)
		{
			p1[3 * i] = 0;//R
			p1[3 * i + 1] = 0;//G
			p1[3 * i + 2] = (i / 22.0) * 115;//B
		}
		else if (i >= 22 && i < 95)
		{
			float seg_ratio = (i - 22) / 73.0f;
			p1[3 * i] = seg_ratio * 190;
			p1[3 * i + 1] = 0;
			p1[3 * i + 2] = seg_ratio * 35 + 115;
		}
		else if (i >= 95 && i < 140)
		{
			float seg_ratio = (i - 95) / 45.0f;
			p1[3 * i] = seg_ratio * 50 + 190;
			p1[3 * i + 1] = seg_ratio * 80;
			p1[3 * i + 2] = 150 - seg_ratio * 150;
		}
		else if (i >= 140 && i < 150)
		{
			float seg_ratio = (i - 140) / 10.0f;
			p1[3 * i] = seg_ratio * 15 + 240;
			p1[3 * i + 1] = seg_ratio * 20 + 80;
			p1[3 * i + 2] = 0;
		}
		else if (i >= 150 && i < 220)
		{
			float seg_ratio = (i - 150) / 70.0f;
			p1[3 * i] = 255;
			p1[3 * i + 1] = seg_ratio * 120 + 100;
			p1[3 * i + 2] = 0;
		}
		else if (i >= 220 && i < 240)
		{
			float seg_ratio = (i - 220) / 20.0f;
			p1[3 * i] = 255;
			p1[3 * i + 1] = seg_ratio * 35 + 220;
			p1[3 * i + 2] = seg_ratio * 150;
		}
		else
		{
			float seg_ratio = (i - 240) / 15.0f;
			p1[3 * i] = 255;
			p1[3 * i + 1] = 255;
			p1[3 * i + 2] = seg_ratio * 105 + 150;
		}

	}
	//彩虹图查找表
	m_look_up_table_rainbow = Mat(1, 256, CV_8UC3);
	uchar *p2 = m_look_up_table_rainbow.data;
	for (int i = 0; i < 256; i++)
	{
		int tmp = i;
		if (i <= 51)
		{
			p2[3 * i] = 0;
			p2[3 * i + 1] = tmp * 5;
			p2[3 * i + 2] = 255;
		}
		else if (i <= 102)
		{
			tmp -= 51;
			p2[3 * i] = 0;
			p2[3 * i + 1] = 255;
			p2[3 * i + 2] = 255 - tmp * 5;
		}
		else if (i <= 153)
		{
			tmp -= 102;
			p2[3 * i] = tmp * 5;
			p2[3 * i + 1] = 255;
			p2[3 * i + 2] = 0;
		}
		else if (i <= 204)
		{
			tmp -= 153;
			p2[3 * i] = 255;
			p2[3 * i + 1] = 255 - (uchar)(128.0 * tmp / 51.0 + 0.5);
			p2[3 * i + 2] = 0;
		}
		else
		{
			tmp -= 204;
			p2[3 * i] = 255;
			p2[3 * i + 1] = 127 - (uchar)(127.0 * tmp / 51.0 + 0.5);
			p2[3 * i + 2] = 0;
		}
	}

	//灰度反转查找表
	m_look_up_table_gray_inv = Mat(1, 256, CV_8UC1);
	uchar *p3 = m_look_up_table_gray_inv.data;
	for (int i = 0; i < 256; i++)
	{
		p3[i] = 255 - i;
	}
}

void ImageProcess::setImageColorFlag(ImageColorFlag flag)
{
	 m_image_color_flag = flag;

}

//void ImageProcess::setWidth(int width)
//{
//	m_imageWidth = width;
//}

//void ImageProcess::setHeight(int height)
//{
//	m_imageHeight = height;
//}

//void ImageProcess::imageToPixmap(QImage &image)
//{
	//QPixmap pixmap = QPixmap::fromImage(image);
	//emit showImage(pixmap);
//}

void ImageProcess::saveOriginalData(unsigned short *data)
{
	int size = m_imageHeight * m_imageWidth;
	unsigned short *tempData = new unsigned short[size];
	for (int i = 0; i < size; ++i)
	{
		tempData[i] = data[i];
	}


	QTime time = QTime::currentTime();
	QString str = time.toString("hhmmsszzz");
	QString path = "./" + str + ".txt";
	QFile file(path);

	if (!file.open(QIODevice::WriteOnly))
		return;
	
	QTextStream out(&file);
	for (int i = 0; i < m_imageHeight; ++i)
	{
		int k = i * m_imageWidth;
		for (int j = 0; j < m_imageWidth; ++j)
		{
			out << tempData[k + j] << " ";
		}
		out << "\r\n";
	}
	delete tempData;
	tempData = nullptr;

}


void ImageProcess::enableSaveData()
{
	m_saveOriginalDataFlag = true;
}


//void ImageProcess::setImageColorOrBlack(bool isColor)
//{
//	m_isColor = isColor;
//}

void ImageProcess::dataToImage()
{
	ImageData* imageData;
	while (m_imageProcessingFlag)
	{
		imageData = ImageFifo::getFifoHead();
	    if (imageData == nullptr) continue;
		if (!m_pauseFlag)
		{
			dataToImage((*imageData).m_data, (*imageData).m_bitsPerPixel, (*imageData).m_imageWidth, (*imageData).m_imageHeight);
		}
		ImageFifo::outFifo();
	}

	ImageFifo::emptyFifo();
	
}


void ImageProcess::setContrastUpper(int up)
{
	m_contrast_upper = up;
}

void ImageProcess::setContrastLower(int low)
{
	m_contrast_lower = low;
}

void ImageProcess::setIsSelfAdaptive(bool flag)
{
	m_is_self_adaptive = flag;
}

void ImageProcess::disableImageProcess()
{
	m_imageProcessingFlag = false;
}

void ImageProcess::enableImageProcess()
{
	m_imageProcessingFlag = true;
}

void ImageProcess::setPauseFlag(bool flag)
{
	m_pauseFlag = flag;
}

void ImageProcess::setSavingPath(QString path)
{
	m_path = path;
}

void ImageProcess::takeOriginalImage(const cv::Mat& image, const QPixmap& pixmap)
{
	QTime time = QTime::currentTime();
	QString str = time.toString("hhmmsszzz");
	QString path = m_path + "\\" + str + ".png";
	cv::imwrite(path.toLocal8Bit().toStdString(), image);
	pixmap.save(m_path + "\\" + str + ".bmp");
	m_isTakingImage = false;
}

void ImageProcess::takeShowingImage(const QPixmap& pixmap)
{
	QTime time = QTime::currentTime();
	QString str = time.toString("hhmmsszzz");
	QString path = m_path + "\\" + str + ".bmp";
	pixmap.save(path);
	m_isTakingImage = false;
}

void ImageProcess::setTakingImageFlag(bool flag)
{
	if (m_isTakingImage)
		return;
	m_isTakingImage = flag;
}

void ImageProcess::beginVideo()
{
	setVideoSavePath();
	setVideoWriter(video_path.toLocal8Bit().toStdString());
	setVideoFlag(true);

}

void ImageProcess::finishVideo()
{
	setVideoFlag(false);
	releaseVideoWriter();
}

void ImageProcess::setVideoSavePath()
{
	QTime time = QTime::currentTime();
	QString str = time.toString("hhmmsszzz");
	video_path = m_path + "\\" + str + ".avi";
	
};

void ImageProcess::setVideoWriter(String str)
{
	Size frame_size(m_data_width, m_data_height);
	m_video_writer.open(str, CV_FOURCC('I','Y', 'U', 'V'), 25, frame_size);
}

void ImageProcess::setVideoFlag(bool flag)
{
	m_flag_video = flag;
}

void ImageProcess::releaseVideoWriter()
{
	m_video_writer.release();
}


