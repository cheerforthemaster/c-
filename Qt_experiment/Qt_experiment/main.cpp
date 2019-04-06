#include "qt_experiment.h"
#include <QtWidgets/QApplication>

#include "MyWin.h"
#include "experiment_two.h"
#include "experiment_three.h"
#include "experiment_four.h"
#include "SearchWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//Qt_experiment w;   //复选框控制按钮的enable
	//w.show();

	//MyWin w;  //点击按钮，文本框出现字符串
	//w.show();

 	experiment_two ex;  //下拉选择框  点击按钮出现对话框
 	ex.show();

	//experiment_three th;  //按钮 图标
	//th.show();

	//experiment_four fo;  //打开 选择文件框  保存文件框
	//fo.show();

// 	SearchWindow ms;
// 	ms.show();

	return a.exec();
}
