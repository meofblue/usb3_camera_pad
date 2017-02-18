/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_2;
    QPushButton *m_startButton;
    QPushButton *m_stopButton;
    QFrame *m_showFrame;
    QGridLayout *gridLayout;
    QLabel *m_showLabel;
    QFrame *frame;
    QPushButton *pushButton_begin_video;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout1;
    QRadioButton *radioButton_color;
    QRadioButton *radioButton_gray;
    QRadioButton *radioButton_rainbow;
    QRadioButton *radioButton_gray_inverse;
    QPushButton *m_imageTakingButton;
    QPushButton *m_pathChoosingButton;
    QPushButton *m_pauseButton;
    QPushButton *pushButton_finish_video;
    QPushButton *m_open_file;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(700, 432);
        MainWindowClass->setMinimumSize(QSize(0, 432));
        MainWindowClass->setMaximumSize(QSize(700, 432));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setBold(true);
        font.setWeight(75);
        MainWindowClass->setFont(font);
        MainWindowClass->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 3px;\n"
"	margin-top: 1ex;\n"
"	padding-bottom: 4px;\n"
"	padding-top: 7px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    /*subcontrol-position: top center; /* position at the top center */\n"
"    padding: 0 3px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #rgb(244, 244, 244), stop: 1 #rgb(244, 244, 244));\n"
"}\n"
"\n"
"QGroupBox#groupBox_6 {   /*\345\270\247\347\216\207\344\270\216\346\270\251\345\272\246\347\273\204\350\256\276\347\275\256\346\227\240\350\276\271\346\241\206*/\n"
"	border: none;\n"
"	margin-top: 0;\n"
"	padding-top:0px;\n"
"}\n"
"\n"
"QGroupBox#groupBox_6 {\n"
"	padding: 0 0;\n"
"\n"
"}"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 432));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font1.setPointSize(12);
        centralWidget->setFont(font1);
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(15, 3, 10, 2);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setEnabled(true);
        frame_2->setMinimumSize(QSize(384, 350));
        frame_2->setMaximumSize(QSize(384, 400));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        m_startButton = new QPushButton(frame_2);
        m_startButton->setObjectName(QStringLiteral("m_startButton"));
        m_startButton->setGeometry(QRect(60, 340, 101, 41));
        m_startButton->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        m_startButton->setFont(font2);
        m_startButton->setFlat(false);
        m_stopButton = new QPushButton(frame_2);
        m_stopButton->setObjectName(QStringLiteral("m_stopButton"));
        m_stopButton->setEnabled(false);
        m_stopButton->setGeometry(QRect(220, 340, 91, 41));
        m_stopButton->setFont(font2);
        m_showFrame = new QFrame(frame_2);
        m_showFrame->setObjectName(QStringLiteral("m_showFrame"));
        m_showFrame->setGeometry(QRect(25, 35, 324, 256));
        m_showFrame->setMinimumSize(QSize(250, 256));
        m_showFrame->setMaximumSize(QSize(324, 256));
        m_showFrame->setStyleSheet(QStringLiteral("background-color: rgb(130, 130, 130)"));
        m_showFrame->setFrameShape(QFrame::NoFrame);
        m_showFrame->setFrameShadow(QFrame::Plain);
        m_showFrame->setLineWidth(0);
        gridLayout = new QGridLayout(m_showFrame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        m_showLabel = new QLabel(m_showFrame);
        m_showLabel->setObjectName(QStringLiteral("m_showLabel"));
        m_showLabel->setMinimumSize(QSize(10, 10));
        m_showLabel->setMaximumSize(QSize(324, 256));
        m_showLabel->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(m_showLabel, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_2);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        frame->setMinimumSize(QSize(180, 0));
        frame->setMaximumSize(QSize(100, 400));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        frame->setFont(font3);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_begin_video = new QPushButton(frame);
        pushButton_begin_video->setObjectName(QStringLiteral("pushButton_begin_video"));
        pushButton_begin_video->setEnabled(false);
        pushButton_begin_video->setGeometry(QRect(20, 160, 151, 41));
        pushButton_begin_video->setFont(font2);
        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 300, 171, 111));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        font4.setKerning(true);
        groupBox_4->setFont(font4);
        groupBox_4->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox_4->setToolTipDuration(-1);
        groupBox_4->setStyleSheet(QStringLiteral("border-color: rgb(240, 240, 240);"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        gridLayout1 = new QGridLayout(groupBox_4);
        gridLayout1->setSpacing(5);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        gridLayout1->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout1->setContentsMargins(3, 3, 2, 3);
        radioButton_color = new QRadioButton(groupBox_4);
        radioButton_color->setObjectName(QStringLiteral("radioButton_color"));
        radioButton_color->setEnabled(false);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setWeight(50);
        font5.setKerning(true);
        radioButton_color->setFont(font5);
        radioButton_color->setChecked(true);

        gridLayout1->addWidget(radioButton_color, 3, 1, 1, 1);

        radioButton_gray = new QRadioButton(groupBox_4);
        radioButton_gray->setObjectName(QStringLiteral("radioButton_gray"));
        radioButton_gray->setEnabled(false);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setWeight(50);
        radioButton_gray->setFont(font6);
        radioButton_gray->setFocusPolicy(Qt::StrongFocus);
        radioButton_gray->setCheckable(true);
        radioButton_gray->setChecked(false);

        gridLayout1->addWidget(radioButton_gray, 2, 1, 1, 1);

        radioButton_rainbow = new QRadioButton(groupBox_4);
        radioButton_rainbow->setObjectName(QStringLiteral("radioButton_rainbow"));
        radioButton_rainbow->setEnabled(false);
        radioButton_rainbow->setFont(font5);

        gridLayout1->addWidget(radioButton_rainbow, 3, 2, 1, 1);

        radioButton_gray_inverse = new QRadioButton(groupBox_4);
        radioButton_gray_inverse->setObjectName(QStringLiteral("radioButton_gray_inverse"));
        radioButton_gray_inverse->setEnabled(false);
        radioButton_gray_inverse->setFont(font6);

        gridLayout1->addWidget(radioButton_gray_inverse, 2, 2, 1, 1);

        m_imageTakingButton = new QPushButton(frame);
        m_imageTakingButton->setObjectName(QStringLiteral("m_imageTakingButton"));
        m_imageTakingButton->setEnabled(false);
        m_imageTakingButton->setGeometry(QRect(20, 60, 151, 41));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        font7.setKerning(true);
        m_imageTakingButton->setFont(font7);
        m_pathChoosingButton = new QPushButton(frame);
        m_pathChoosingButton->setObjectName(QStringLiteral("m_pathChoosingButton"));
        m_pathChoosingButton->setGeometry(QRect(20, 10, 151, 41));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setWeight(50);
        font8.setKerning(true);
        m_pathChoosingButton->setFont(font8);
        m_pauseButton = new QPushButton(frame);
        m_pauseButton->setObjectName(QStringLiteral("m_pauseButton"));
        m_pauseButton->setEnabled(false);
        m_pauseButton->setGeometry(QRect(20, 110, 151, 41));
        m_pauseButton->setFont(font2);
        pushButton_finish_video = new QPushButton(frame);
        pushButton_finish_video->setObjectName(QStringLiteral("pushButton_finish_video"));
        pushButton_finish_video->setEnabled(false);
        pushButton_finish_video->setGeometry(QRect(20, 210, 151, 41));
        pushButton_finish_video->setFont(font2);
        m_open_file = new QPushButton(frame);
        m_open_file->setObjectName(QStringLiteral("m_open_file"));
        m_open_file->setEnabled(true);
        m_open_file->setGeometry(QRect(20, 260, 151, 41));
        m_open_file->setFont(font7);

        horizontalLayout_3->addWidget(frame);

        MainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "\347\272\242\345\244\226\346\210\220\345\203\217\350\275\257\344\273\266", 0));
        m_startButton->setText(QApplication::translate("MainWindowClass", "\346\211\223 \345\274\200", 0));
        m_stopButton->setText(QApplication::translate("MainWindowClass", "\345\205\263 \351\227\255", 0));
        m_showLabel->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\">\346\230\276\347\244\272</p></body></html>", 0));
        pushButton_begin_video->setText(QApplication::translate("MainWindowClass", "\345\274\200\345\247\213\345\275\225\345\210\266", 0));
        groupBox_4->setTitle(QString());
        radioButton_color->setText(QApplication::translate("MainWindowClass", "\347\203\255\351\207\221\345\261\236", 0));
        radioButton_gray->setText(QApplication::translate("MainWindowClass", "\351\273\221\347\231\275", 0));
        radioButton_rainbow->setText(QApplication::translate("MainWindowClass", "\345\275\251\350\231\271", 0));
        radioButton_gray_inverse->setText(QApplication::translate("MainWindowClass", "\347\231\275\351\273\221", 0));
        m_imageTakingButton->setText(QApplication::translate("MainWindowClass", "\346\213\215  \347\205\247", 0));
        m_pathChoosingButton->setText(QApplication::translate("MainWindowClass", "\351\200\211\346\213\251\345\255\230\345\202\250\350\267\257\345\276\204", 0));
        m_pauseButton->setText(QApplication::translate("MainWindowClass", "\346\232\202  \345\201\234", 0));
        pushButton_finish_video->setText(QApplication::translate("MainWindowClass", "\345\201\234\346\255\242\345\275\225\345\210\266", 0));
        m_open_file->setText(QApplication::translate("MainWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207/\350\247\206\351\242\221", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
