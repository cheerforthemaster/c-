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

	//Qt_experiment w;   //��ѡ����ư�ť��enable
	//w.show();

	//MyWin w;  //�����ť���ı�������ַ���
	//w.show();

 	experiment_two ex;  //����ѡ���  �����ť���ֶԻ���
 	ex.show();

	//experiment_three th;  //��ť ͼ��
	//th.show();

	//experiment_four fo;  //�� ѡ���ļ���  �����ļ���
	//fo.show();

// 	SearchWindow ms;
// 	ms.show();

	return a.exec();
}
