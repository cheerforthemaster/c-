#ifndef M_SEARCH_H
#define M_SEARCH_H

#include <QWidget>
#include "ui_M_Search.h"

class M_Search : public QWidget
{
	Q_OBJECT

public:
	M_Search(QWidget *parent = 0);
	~M_Search();

public:
	Ui::M_Search ui;
};

#endif // M_SEARCH_H
