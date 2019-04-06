#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>
#include "ui_SearchWindow.h"
#include "M_Search.h"

class SearchWindow : public QWidget
{
	Q_OBJECT

public:
	SearchWindow(QWidget *parent = 0);
	~SearchWindow();

private:
	Ui::SearchWindow ui;
	M_Search *M_win;
private slots:
	int OnBtnShow();
	int OnBtnSearch();
};

#endif // SEARCHWINDOW_H
