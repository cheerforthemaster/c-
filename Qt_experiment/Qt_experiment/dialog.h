#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialog.h"

class dialog : public QDialog
{
	Q_OBJECT

public:
	dialog(QWidget *parent = 0);
	~dialog();

private slots:
	int OnbtnOk();
	int OnbtnCancel();
private:
	Ui::dialog ui;
	QString m_user;
	QString m_password;
};

#endif // DIALOG_H
