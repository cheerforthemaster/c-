#ifndef PIXMAP_H
#define PIXMAP_H

#include <QDialog>
#include "ui_pixmap.h"

class pixmap : public QDialog
{
	Q_OBJECT

public:
	pixmap(QWidget *parent = 0);
	~pixmap();

private:
	Ui::pixmap ui;
};

#endif // PIXMAP_H
