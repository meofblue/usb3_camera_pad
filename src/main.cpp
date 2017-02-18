#include "mainwindow.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	MainWindow w;
	w.show();
	return a.exec();
}
