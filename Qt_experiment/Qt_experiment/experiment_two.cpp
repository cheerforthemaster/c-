#include "experiment_two.h"
#include "dialog.h"
#include <QMessageBox>

experiment_two::experiment_two(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//ui.comboBox->addItem("Chinese");
	//ui.comboBox->addItem("English");
	//ui.comboBox->addItem("French");
	//ui.comboBox->insertItem(2, "Japenese");

	connect(ui.pushButton, SIGNAL(clicked()),this, SLOT(OnBtnOk()));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)),this,SLOT(OnTextChanged(int)));
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(OnBtnNext()));
}

experiment_two::~experiment_two()
{

}

int experiment_two::OnBtnOk()
{
	int index = ui.comboBox->currentIndex();
	//QString data = ui.comboBox->itemData(index).toString();
	QString text = ui.comboBox->itemText(index);

	return 0;
}

int experiment_two::OnTextChanged(int index)
{

	return 0;
}

int experiment_two::OnBtnNext()
{
	dialog dia(this);
	int ret = dia.exec();
// 	if (ret==QDialog::Accepted)
// 	{
// 		QMessageBox::information(this, "yes", "Enter!");
// 	}
// 	else
// 	{
// 		QMessageBox::information(this, "no", "Cancel");
// 	}
// 

	return 0;
}
