#pragma once
#include"ui_DonateView.h"
class DonateWindow :public QDialog {
	Q_OBJECT
public:
	DonateWindow(QWidget *parent = Q_NULLPTR);
private:
	Ui::DonateDialog ui;
	QPixmap* donatePixmap;
};

