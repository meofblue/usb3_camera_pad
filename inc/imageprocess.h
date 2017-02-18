#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtCore>
//#include "qimage.h"
#include "qpixmap.h"
#include <Windows.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

class ImageProcess : public QObject
{
	Q_OBJECT

public:
	ImageProcess(int height, int width);
	~ImageProcess();

	enum ImageColorFlag
	{
		GRAY_IMAGE,
		COLOR_IMAGE,
		GRAY_INVERSE_IMAGE,
		RAINBOW_IMAGE
	}m_image_color_flag;

	ImageColorFlag flag;

	void setDataSavingSpace(unsigned char *data);
	void setWidth(int width);
	void setHeight(int height);
	//void imageToPixmap(QImage &image);
	void saveOriginalData(unsigned short *data);
	void enableSaveData();
	void setImageColorFlag(ImageColorFlag flag);

	void setContrastUpper(int up);
	void setContrastLower(int low);
	
	void disableImageProcess();
	void enableImageProcess();

	void setIsSelfAdaptive(bool flag);

	void setPauseFlag(bool flag);
	
	void beginVideo();
	void finishVideo();
	void setVideoFlag(bool flag);
	void setVideoSavePath();
	void setVideoWriter(String str);
	void releaseVideoWriter();
	QString video_path;

	//void autoWhiteBalance(cv::Mat &src, cv::Mat &dst);

	void gray14bitTo8bit(Mat &src);
	void dataToImage(unsigned char *data, int bitsPerPixel, int width, int height);
	void setLookUpTable();

	void setSavingPath(QString path);
	void takeOriginalImage(const cv::Mat& image,  const QPixmap& pixmap);
	void takeShowingImage(const QPixmap& pixmap);
	void setTakingImageFlag(bool flag);

	QPixmap m_pixmap;

	void openFile();

signals:
	void showImage(QPixmap image);

public slots:
	void dataToImage();

private:
	unsigned char *m_imageData;

	double m_min_pixel;
	double m_max_pixel;
	Scalar m_avg_pixel;
	Point m_max_pixel_position;
	Mat m_image_16bit;

	int m_contrast_upper;
	int m_contrast_lower;

	bool m_is_self_adaptive;


	int m_imageWidth;
	int m_imageHeight;

	int m_data_height;
	int m_data_width;

	Mat m_look_up_table_color;
	Mat m_look_up_table_rainbow;
	Mat m_look_up_table_gray_inv;
	Mat m_final_image;
	bool m_flag_work;
	bool m_flag_video;
	VideoWriter m_video_writer;
	QImage m_image;
	QString m_path;

	bool m_saveOriginalDataFlag;
//	bool m_isColor;

	bool m_imageProcessingFlag;
	bool m_pauseFlag;
	bool m_isTakingImage;
};

#endif