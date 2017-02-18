#include "mainwindow.h"
#include "qsettings.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	m_imageModel(this, 256, 324),
//	m_frame_count(0),
	m_isClosed(false)
{
	m_imageHeight = 256;
	m_imageWidth = 324;
	
	m_imageModel.setResolution(m_imageHeight, m_imageWidth);

 	ui.setupUi(this);
	//ui.m_showFrame->setFixedSize(QSize(384, 288));
	//ui.m_showLabel->setFixedSize(QSize(m_imageWidth, m_imageHeight));
		
	m_frameRateLabel = new QLabel(ui.statusBar);
	ui.statusBar->addWidget(m_frameRateLabel);
	//ui.statusBar->addWidget(m_label_frame_rate);
	m_frameRateLabel->setText(QStringLiteral("就绪"));

	//Qt4的信号槽使用方式
	connect(ui.m_startButton, SIGNAL(clicked()), this, SLOT(openCamera()));
	connect(ui.m_stopButton, SIGNAL(clicked()), this, SLOT(closeCamera()));
	connect(ui.m_pauseButton, SIGNAL(clicked()), this, SLOT(pauseCamera()));

//	connect(ui.m_8bitsChoosed, SIGNAL(toggled(bool)), this, SLOT(changeWidthTo8bitsPerPixel(bool)));
	connect(ui.radioButton_gray, SIGNAL(toggled(bool)), this, SLOT(changeToGrayImage(bool)));
	connect(ui.radioButton_gray_inverse, SIGNAL(toggled(bool)), this, SLOT(changeToGrayInverseImage(bool)));
	connect(ui.radioButton_color, SIGNAL(toggled(bool)), this, SLOT(changeToColorImage(bool)));
	connect(ui.radioButton_rainbow, SIGNAL(toggled(bool)), this, SLOT(changeToRainbowImage(bool)));

	connect(ui.pushButton_begin_video, SIGNAL(clicked()), this, SLOT(beginVideo()));
	connect(ui.pushButton_finish_video, SIGNAL(clicked()), this, SLOT(finishVideo()));

	connect(ui.m_pathChoosingButton, &QPushButton::clicked, this, &MainWindow::chooseSavingPath);
	connect(ui.m_imageTakingButton, &QPushButton::clicked, this, &MainWindow::takeImage);
	//connect(&m_timer, SIGNAL(timeout()), this, SLOT(showFrameRate()));
	connect(ui.m_open_file, &QPushButton::clicked, this, &MainWindow::openFile);
}

MainWindow::~MainWindow()
{
	//m_imageModel.closeUSBCamera();
}

void MainWindow::openCamera()
{
	if (m_imageModel.openUSBCamera())
	{
		ui.m_startButton->setEnabled(false);
		ui.m_pauseButton->setEnabled(true);
		ui.m_stopButton->setEnabled(true);
		ui.m_open_file->setEnabled(true);
		
		m_isClosed = false;
		m_imageModel.readData();
//		m_timer.start(1000);

		ui.m_imageTakingButton->setEnabled(true);
		ui.pushButton_begin_video->setEnabled(true);
		ui.radioButton_color->setEnabled(true);
		ui.radioButton_gray->setEnabled(true);
		ui.radioButton_gray_inverse->setEnabled(true); 
		ui.radioButton_rainbow->setEnabled(true);
	}
	else
	{
		QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("设备打开失败，请重新连接"));
	}
}

void MainWindow::closeCamera()
{
	finishVideo();
	ui.m_stopButton->setEnabled(false);
	ui.m_pauseButton->setEnabled(false);

	ui.m_imageTakingButton->setEnabled(false);
	ui.pushButton_begin_video->setEnabled(false);
	ui.radioButton_color->setEnabled(false);
	ui.radioButton_gray->setEnabled(false);
	ui.radioButton_gray_inverse->setEnabled(false);
	ui.radioButton_rainbow->setEnabled(false);
	m_imageModel.closeUSBCamera();
//	m_timer.stop();

	if (ui.m_pauseButton->text() != "暂  停")
	{
		ui.m_pauseButton->setText(QStringLiteral("暂  停"));
		m_imageModel.whetherPausingUSBCamera(false);
	}

	m_frameRateLabel->setText(QStringLiteral("就绪"));
	ui.m_startButton->setEnabled(true);
	m_isClosed = true;
	ui.m_showLabel->clear();
//	ui.m_receiveRateLabel->setText(QString::number(0));
}

void MainWindow::updateImage(QPixmap image)
{
	if (m_isClosed)
		return;
	//qDebug() << "updateImage";
	//ui.m_showLabel->resize(image.size());
	//ui.m_showLabel->clear();
	ui.m_showLabel->setPixmap(image);
	//m_frame_count++;
	//DWORD start1 = GetTickCount();

	/*DWORD end1 = GetTickCount();
	qDebug() << end1 - start1;*/
}

void MainWindow::changeToGrayImage(bool flag)
{
	if (flag)
	{
		m_imageModel.setImageColorFlag(ImageProcess::GRAY_IMAGE);
	}
}

void MainWindow::changeToGrayInverseImage(bool flag)
{
	if (flag)
	{
		m_imageModel.setImageColorFlag(ImageProcess::GRAY_INVERSE_IMAGE);
	}
}

void MainWindow::changeToColorImage(bool flag)
{
	if (flag)
	{
		m_imageModel.setImageColorFlag(ImageProcess::COLOR_IMAGE);
	}
}

void MainWindow::changeToRainbowImage(bool flag)
{
	if (flag)
	{
		m_imageModel.setImageColorFlag(ImageProcess::RAINBOW_IMAGE);
	}
}

void MainWindow::saveData()
{
	m_imageModel.saveData();
}


void MainWindow::pauseCamera()
{
	if (ui.m_pauseButton->text() == QStringLiteral("暂  停"))
	{
		ui.m_imageTakingButton->setEnabled(false);
		m_imageModel.whetherPausingUSBCamera(true);
		ui.pushButton_begin_video->setEnabled(false);
		ui.m_pauseButton->setText(QStringLiteral("取消暂停"));
		ui.radioButton_color->setEnabled(false);
		ui.radioButton_gray->setEnabled(false);
		ui.radioButton_gray_inverse->setEnabled(false);
		ui.radioButton_rainbow->setEnabled(false);
	}
	else
	{
		m_imageModel.whetherPausingUSBCamera(false);
		ui.m_pauseButton->setText(QStringLiteral("暂  停"));
		ui.m_imageTakingButton->setEnabled(true);
		ui.pushButton_begin_video->setEnabled(true);
		ui.radioButton_color->setEnabled(true);
		ui.radioButton_gray->setEnabled(true);
		ui.radioButton_gray_inverse->setEnabled(true);
		ui.radioButton_rainbow->setEnabled(true);
	}
}

/*
bool MainWindow::initCameraConfig()
{
	QSettings settings("camconfig.ini", QSettings::IniFormat);

	m_imageWidth = settings.value("Camera034/width").toInt();
	m_imageHeight = settings.value("Camera034/height").toInt();

	if (m_imageHeight == 0 || m_imageWidth == 0)
		return false;
	else
		return true;
}
*/

void MainWindow::chooseSavingPath()
{
	path = QFileDialog::getExistingDirectory(this, QStringLiteral("存储路径选择"), ".");
	if (path == "")
		path = ".";
	m_imageModel.setSavingPath(path);
}

void MainWindow::beginVideo()
{
	m_imageModel.beginVideo();
	ui.pushButton_begin_video->setText(QStringLiteral("录制中..."));
	ui.pushButton_begin_video->setEnabled(false);
	ui.pushButton_finish_video->setEnabled(true);
	ui.m_pauseButton->setEnabled(false);
	ui.m_imageTakingButton->setEnabled(false);
}

void MainWindow::finishVideo()
{
	m_imageModel.finishVideo();
	ui.pushButton_begin_video->setText(QStringLiteral("开始录制"));
	ui.pushButton_begin_video->setEnabled(true);
	ui.pushButton_finish_video->setEnabled(false);
	ui.m_pauseButton->setEnabled(true);
	ui.m_imageTakingButton->setEnabled(true);
}

void MainWindow::takeImage()
{
	m_imageModel.takeImage();
	//QMessageBox::about(NULL, "About", "About this application");
}

void MainWindow::openFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("打开图片或视频"), path, QStringLiteral("图片和视频(*.avi *.bmp);;图片(*.bmp);;视频(*.avi)"));
	//QFileInfo fileInfo = QFileInfo::QFileInfo(fileName);	
	if (!fileName.isNull()) 
	{ 
	//	if (fileInfo.suffix() == "bmp")
	//	{
	//		QProcess image_process;
	//		image_process.startDetached("C:\windows\system32\shimgvw.dll", QStringList(fileName));
	//	}
	//	else
	//	{
	//		QProcess video_process;
	//		video_process.startDetached("C:/Program Files (x86)/Windows Media Player/wmplayer.exe", QStringList(fileName));
	//	}
	bool is_open = QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
	if (!is_open)
	{
		QMessageBox::about(NULL, QString::fromLocal8Bit("错误提示"), QStringLiteral("文件无法打开"));
	}
	}
}

void MainWindow::showFrameRate()
{
	QString str = QString::number(m_frame_count) + "  fps";
	m_frameRateLabel->setText(str);
	m_frame_count = 0;
}