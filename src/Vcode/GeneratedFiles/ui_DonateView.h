/********************************************************************************
** Form generated from reading UI file 'DonateView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONATEVIEW_H
#define UI_DONATEVIEW_H

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

class Ui_DonateDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *DonateDialog)
    {
        if (DonateDialog->objectName().isEmpty())
            DonateDialog->setObjectName(QStringLiteral("DonateDialog"));
        DonateDialog->resize(500, 300);
        verticalLayoutWidget = new QWidget(DonateDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 501, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS

        verticalLayout->addWidget(label);


        retranslateUi(DonateDialog);

        QMetaObject::connectSlotsByName(DonateDialog);
    } // setupUi

    void retranslateUi(QDialog *DonateDialog)
    {
        DonateDialog->setWindowTitle(QApplication::translate("DonateDialog", "How To Donate", 0));
        label->setText(QApplication::translate("DonateDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class DonateDialog: public Ui_DonateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONATEVIEW_H
