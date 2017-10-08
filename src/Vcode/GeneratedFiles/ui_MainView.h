/********************************************************************************
** Form generated from reading UI file 'MainView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewClass
{
public:
    QAction *importPicAction;
    QAction *exitAction;
    QAction *donateAction;
    QAction *aboutAction;
    QAction *guideAction;
    QAction *saveAction;
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGraphicsView *removeBgView;
    QGraphicsView *binaryzationView;
    QGraphicsView *grayView;
    QGraphicsView *denoiseView;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QSlider *rBGSlider;
    QSlider *binarySlider;
    QSlider *denoiseSlider;
    QSpinBox *rBGSpinBox;
    QSpinBox *binarySpinBox;
    QSpinBox *denoiseSpinBox;
    QFrame *frame_6;
    QRadioButton *aveButton;
    QRadioButton *weightAveButton;
    QRadioButton *maxbutton;
    QPushButton *recognizeButton;
    QLabel *label;
    QFrame *frame;
    QRadioButton *textCodeRadioButton;
    QRadioButton *SlideCodeRadioButton;
    QGroupBox *groupBox;
    QGraphicsView *leftOriginView;
    QTextBrowser *resultText;
    QLabel *label_30;
    QGraphicsView *sliderView;
    QPushButton *importPictureButton;
    QPushButton *importSliderButton;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViewClass)
    {
        if (ViewClass->objectName().isEmpty())
            ViewClass->setObjectName(QStringLiteral("ViewClass"));
        ViewClass->resize(1115, 866);
        importPicAction = new QAction(ViewClass);
        importPicAction->setObjectName(QStringLiteral("importPicAction"));
        exitAction = new QAction(ViewClass);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        donateAction = new QAction(ViewClass);
        donateAction->setObjectName(QStringLiteral("donateAction"));
        donateAction->setCheckable(false);
        aboutAction = new QAction(ViewClass);
        aboutAction->setObjectName(QStringLiteral("aboutAction"));
        guideAction = new QAction(ViewClass);
        guideAction->setObjectName(QStringLiteral("guideAction"));
        saveAction = new QAction(ViewClass);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        action = new QAction(ViewClass);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(ViewClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(ViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 10, 460, 761));
        removeBgView = new QGraphicsView(groupBox_2);
        removeBgView->setObjectName(QStringLiteral("removeBgView"));
        removeBgView->setGeometry(QRect(160, 406, 256, 81));
        binaryzationView = new QGraphicsView(groupBox_2);
        binaryzationView->setObjectName(QStringLiteral("binaryzationView"));
        binaryzationView->setGeometry(QRect(160, 516, 256, 81));
        grayView = new QGraphicsView(groupBox_2);
        grayView->setObjectName(QStringLiteral("grayView"));
        grayView->setGeometry(QRect(160, 296, 256, 81));
        denoiseView = new QGraphicsView(groupBox_2);
        denoiseView->setObjectName(QStringLiteral("denoiseView"));
        denoiseView->setGeometry(QRect(160, 626, 256, 81));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(35, 416, 101, 51));
        label_21->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_21->setFrameShape(QFrame::Box);
        label_21->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(35, 526, 101, 51));
        label_22->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_22->setFrameShape(QFrame::Box);
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(35, 636, 101, 51));
        label_23->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_23->setFrameShape(QFrame::Box);
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(35, 316, 101, 50));
        label_24->setStyleSheet(QStringLiteral("font: 14pt \"Agency FB\";"));
        label_24->setFrameShape(QFrame::Box);
        label_24->setFrameShadow(QFrame::Plain);
        label_24->setLineWidth(1);
        label_24->setTextFormat(Qt::AutoText);
        label_24->setAlignment(Qt::AlignCenter);
        label_24->setWordWrap(false);
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(20, 62, 91, 21));
        label_25->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\"\357\274\233"));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(20, 110, 111, 21));
        label_26->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\"\357\274\233"));
        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(20, 154, 111, 21));
        label_27->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\"\357\274\233"));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(20, 198, 170, 21));
        label_28->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\"\357\274\233"));
        rBGSlider = new QSlider(groupBox_2);
        rBGSlider->setObjectName(QStringLiteral("rBGSlider"));
        rBGSlider->setGeometry(QRect(200, 110, 160, 20));
        rBGSlider->setMaximum(255);
        rBGSlider->setValue(150);
        rBGSlider->setOrientation(Qt::Horizontal);
        rBGSlider->setInvertedAppearance(false);
        rBGSlider->setInvertedControls(false);
        rBGSlider->setTickPosition(QSlider::NoTicks);
        binarySlider = new QSlider(groupBox_2);
        binarySlider->setObjectName(QStringLiteral("binarySlider"));
        binarySlider->setGeometry(QRect(200, 154, 160, 22));
        binarySlider->setMaximum(255);
        binarySlider->setValue(220);
        binarySlider->setOrientation(Qt::Horizontal);
        denoiseSlider = new QSlider(groupBox_2);
        denoiseSlider->setObjectName(QStringLiteral("denoiseSlider"));
        denoiseSlider->setGeometry(QRect(200, 198, 160, 22));
        denoiseSlider->setMinimum(0);
        denoiseSlider->setMaximum(10);
        denoiseSlider->setOrientation(Qt::Horizontal);
        rBGSpinBox = new QSpinBox(groupBox_2);
        rBGSpinBox->setObjectName(QStringLiteral("rBGSpinBox"));
        rBGSpinBox->setGeometry(QRect(380, 110, 46, 22));
        rBGSpinBox->setMaximum(255);
        rBGSpinBox->setValue(150);
        binarySpinBox = new QSpinBox(groupBox_2);
        binarySpinBox->setObjectName(QStringLiteral("binarySpinBox"));
        binarySpinBox->setGeometry(QRect(380, 154, 46, 22));
        binarySpinBox->setMaximum(255);
        binarySpinBox->setValue(220);
        denoiseSpinBox = new QSpinBox(groupBox_2);
        denoiseSpinBox->setObjectName(QStringLiteral("denoiseSpinBox"));
        denoiseSpinBox->setGeometry(QRect(380, 198, 46, 22));
        denoiseSpinBox->setMinimum(0);
        denoiseSpinBox->setMaximum(10);
        frame_6 = new QFrame(groupBox_2);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(120, 61, 341, 41));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        aveButton = new QRadioButton(frame_6);
        aveButton->setObjectName(QStringLiteral("aveButton"));
        aveButton->setGeometry(QRect(0, 3, 115, 19));
        aveButton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        weightAveButton = new QRadioButton(frame_6);
        weightAveButton->setObjectName(QStringLiteral("weightAveButton"));
        weightAveButton->setGeometry(QRect(220, 3, 115, 19));
        weightAveButton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        maxbutton = new QRadioButton(frame_6);
        maxbutton->setObjectName(QStringLiteral("maxbutton"));
        maxbutton->setGeometry(QRect(110, 3, 115, 19));
        maxbutton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        recognizeButton = new QPushButton(groupBox_2);
        recognizeButton->setObjectName(QStringLiteral("recognizeButton"));
        recognizeButton->setGeometry(QRect(190, 240, 90, 30));
        recognizeButton->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 24, 111, 21));
        label->setStyleSheet(QStringLiteral("font: 75 12pt \"Aharoni\";"));
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(140, 10, 301, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textCodeRadioButton = new QRadioButton(frame);
        textCodeRadioButton->setObjectName(QStringLiteral("textCodeRadioButton"));
        textCodeRadioButton->setGeometry(QRect(10, 14, 131, 20));
        textCodeRadioButton->setStyleSheet(QStringLiteral("font: 75 12pt \"Aharoni\";"));
        SlideCodeRadioButton = new QRadioButton(frame);
        SlideCodeRadioButton->setObjectName(QStringLiteral("SlideCodeRadioButton"));
        SlideCodeRadioButton->setGeometry(QRect(160, 14, 141, 20));
        SlideCodeRadioButton->setStyleSheet(QStringLiteral("font: 75 12pt \"Aharoni\";"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 10, 511, 761));
        leftOriginView = new QGraphicsView(groupBox);
        leftOriginView->setObjectName(QStringLiteral("leftOriginView"));
        leftOriginView->setGeometry(QRect(110, 10, 256, 192));
        resultText = new QTextBrowser(groupBox);
        resultText->setObjectName(QStringLiteral("resultText"));
        resultText->setGeometry(QRect(110, 520, 261, 201));
        resultText->setStyleSheet(QStringLiteral("font: 75 12pt \"Courier\";"));
        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(190, 480, 101, 30));
        label_30->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        label_30->setFrameShape(QFrame::Box);
        sliderView = new QGraphicsView(groupBox);
        sliderView->setObjectName(QStringLiteral("sliderView"));
        sliderView->setGeometry(QRect(120, 250, 241, 171));
        importPictureButton = new QPushButton(groupBox);
        importPictureButton->setObjectName(QStringLiteral("importPictureButton"));
        importPictureButton->setGeometry(QRect(190, 210, 97, 29));
        importSliderButton = new QPushButton(groupBox);
        importSliderButton->setObjectName(QStringLiteral("importSliderButton"));
        importSliderButton->setGeometry(QRect(180, 430, 111, 29));
        ViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1115, 27));
        file = new QMenu(menuBar);
        file->setObjectName(QStringLiteral("file"));
        file->setToolTipsVisible(false);
        help = new QMenu(menuBar);
        help->setObjectName(QStringLiteral("help"));
        ViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ViewClass->setStatusBar(statusBar);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(help->menuAction());
        file->addAction(importPicAction);
        file->addAction(saveAction);
        file->addSeparator();
        file->addAction(exitAction);
        help->addAction(donateAction);
        help->addAction(guideAction);
        help->addSeparator();
        help->addAction(aboutAction);

        retranslateUi(ViewClass);

        QMetaObject::connectSlotsByName(ViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewClass)
    {
        ViewClass->setWindowTitle(QApplication::translate("ViewClass", "Vcode", 0));
        importPicAction->setText(QApplication::translate("ViewClass", "\345\257\274\345\205\245\345\233\276\347\211\207", 0));
        exitAction->setText(QApplication::translate("ViewClass", "\351\200\200\345\207\272", 0));
        donateAction->setText(QApplication::translate("ViewClass", "\346\215\220\345\212\251", 0));
        aboutAction->setText(QApplication::translate("ViewClass", "\345\205\263\344\272\216", 0));
        guideAction->setText(QApplication::translate("ViewClass", "\346\214\207\345\215\227", 0));
        saveAction->setText(QApplication::translate("ViewClass", "\344\277\235\345\255\230\346\226\207\344\273\266", 0));
        action->setText(QApplication::translate("ViewClass", "\346\226\207\345\255\227\351\252\214\350\257\201\347\240\201", 0));
        action_2->setText(QApplication::translate("ViewClass", "\346\273\221\345\212\250\351\252\214\350\257\201\347\240\201", 0));
        groupBox_2->setTitle(QString());
        label_21->setText(QApplication::translate("ViewClass", "\345\216\273\350\203\214\346\231\257", 0));
        label_22->setText(QApplication::translate("ViewClass", "\344\272\214\345\200\274\345\214\226", 0));
        label_23->setText(QApplication::translate("ViewClass", "\345\216\273\345\231\252\347\202\271", 0));
        label_24->setText(QApplication::translate("ViewClass", "\347\201\260\345\272\246", 0));
        label_25->setText(QApplication::translate("ViewClass", "\347\201\260\345\272\246\346\226\271\345\274\217", 0));
        label_26->setText(QApplication::translate("ViewClass", "\345\216\273\350\203\214\346\231\257\351\230\210\345\200\274", 0));
        label_27->setText(QApplication::translate("ViewClass", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274", 0));
        label_28->setText(QApplication::translate("ViewClass", "\345\216\273\345\231\252\347\202\271\347\252\227\345\217\243\345\215\212\350\276\271\351\225\277", 0));
        aveButton->setText(QApplication::translate("ViewClass", "\345\271\263\345\235\207\345\200\274\346\263\225", 0));
        weightAveButton->setText(QApplication::translate("ViewClass", "\345\212\240\346\235\203\345\271\263\345\235\207", 0));
        maxbutton->setText(QApplication::translate("ViewClass", "\346\234\200\345\244\247\345\200\274\346\263\225", 0));
        recognizeButton->setText(QApplication::translate("ViewClass", "\345\274\200\345\247\213\350\257\206\345\210\253", 0));
        recognizeButton->setShortcut(QApplication::translate("ViewClass", "Ctrl+B", 0));
        label->setText(QApplication::translate("ViewClass", "\351\252\214\350\257\201\347\240\201\347\261\273\345\236\213", 0));
        textCodeRadioButton->setText(QApplication::translate("ViewClass", "\346\226\207\345\255\227\351\252\214\350\257\201\347\240\201", 0));
        SlideCodeRadioButton->setText(QApplication::translate("ViewClass", "\346\273\221\345\212\250\351\252\214\350\257\201\347\240\201", 0));
        groupBox->setTitle(QString());
        label_30->setText(QApplication::translate("ViewClass", "\350\257\206\345\210\253\347\273\223\346\236\234", 0));
        importPictureButton->setText(QApplication::translate("ViewClass", "\345\257\274\345\205\245\345\233\276\347\211\207", 0));
        importSliderButton->setText(QApplication::translate("ViewClass", "\345\257\274\345\205\245\346\273\221\345\235\227\345\233\276\347\211\207", 0));
        file->setTitle(QApplication::translate("ViewClass", "\346\226\207\344\273\266", 0));
        help->setTitle(QApplication::translate("ViewClass", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewClass: public Ui_ViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
