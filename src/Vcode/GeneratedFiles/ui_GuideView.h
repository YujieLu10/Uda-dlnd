/********************************************************************************
** Form generated from reading UI file 'GuideView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDEVIEW_H
#define UI_GUIDEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuideDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;

    void setupUi(QDialog *GuideDialog)
    {
        if (GuideDialog->objectName().isEmpty())
            GuideDialog->setObjectName(QStringLiteral("GuideDialog"));
        GuideDialog->resize(500, 330);
        verticalLayoutWidget = new QWidget(GuideDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(GuideDialog);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 501, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);


        retranslateUi(GuideDialog);

        QMetaObject::connectSlotsByName(GuideDialog);
    } // setupUi

    void retranslateUi(QDialog *GuideDialog)
    {
        GuideDialog->setWindowTitle(QApplication::translate("GuideDialog", "Dialog", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GuideDialog: public Ui_GuideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDEVIEW_H
