#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "imagemodel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	bool initCameraConfig();

	

public slots:
	void openCamera();
	void closeCamera();
	void pauseCamera();

	void beginVideo();
	void finishVideo();

	void updateImage(QPixmap image);

	void changeToGrayImage(bool flag);
	void changeToGrayInverseImage(bool flag);
	void changeToColorImage(bool flag);
	void changeToRainbowImage(bool flag);

	void showFrameRate();

	void saveData();


	void chooseSavingPath();
	void takeImage();
	void openFile();

private:
	Ui::MainWindowClass ui;

	ImageModel m_imageModel;


   QTimer m_timer;

	QLabel *m_frameRateLabel;
	int m_frame_count;

	int m_imageWidth;
	int m_imageHeight;

	bool m_isClosed;
	QString path;
};

#endif // MAINWINDOW_H
