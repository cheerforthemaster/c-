#include "draworiginalgraph.h"

draworiginalgraph::draworiginalgraph(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	theGraph = NULL;
	setAttribute(Qt::WA_DeleteOnClose);
}

draworiginalgraph::~draworiginalgraph()
{

}

bool draworiginalgraph::GetGraph(graph<char, int>* one)
{
	theGraph = one;
	return true;
}

void draworiginalgraph::paintEvent(QPaintEvent * event)
{
	if (theGraph == NULL)
		return;

	QPainter painter(this);
	int Width = this->width();
	int Height = this->height();
	int level = 0;//���;
	int levelNum = 0;//����;
	int preLevel = 0;//��ǰ����;

	int vertexNum = theGraph->getvertexNum();
	if (vertexNum == 1)
		return;
	int temVer = 0;//�Ѷ�λ�Ķ���;

	int **postion = new int *[vertexNum];
	for (int i = 0; i < vertexNum; i++)
		postion[i] = new int[2];

	if (vertexNum % 2 == 1)//���ն���ĸ�����ȷ������;
	{
		levelNum = vertexNum / 2 + 1;
		level = Height / levelNum;

		postion[0][0] = Width / 2;//x;
		postion[0][1] = level / 2;//y;
		preLevel++;
		temVer++;
	}
	else
	{
		levelNum = vertexNum / 2;
		levelNum = Height / levelNum;
	}

	int radius = (Height > Width) ? Width / 2 : Height / 2;//���ж�����һ��Բ��;
														   //(x - Width / 2) ^ 2 + (y - Height / 2) ^ 2 = radius ^ 2;
	for (int i = temVer; i < vertexNum; i++)
	{
		postion[i][1] = level / 2 + preLevel*level;//y;
		postion[i][0] = sqrt(radius*radius - (postion[i][1] - Height / 2)*(postion[i][1] - Height / 2)) + Width / 2;//x;
		i++;
		temVer++;
		postion[i][1] = level / 2 + preLevel*level;//y;
		postion[i][0] = Width - postion[i - 1][0];//x;
		preLevel++;
	}


	painter.setBrush(QBrush(QColor(0x9f, 0x9f, 0xff)));//����;
	painter.setPen(QPen(Qt::black, 5));
	int length = 0;
	int *temArrary = NULL;
	for (int i = 0; i < vertexNum; i++)
	{
		length = theGraph->getAllNeighbor(i, temArrary);
		for (int j = 0; j < length; j++)
			painter.drawLine(QPoint(postion[i][0], postion[i][1]), QPoint(postion[temArrary[j]][0], postion[temArrary[j]][1]));
	}

	painter.setPen(QPen(Qt::black, 1));//��Բ;
	for (int i = 0; i < vertexNum; i++)
		painter.drawEllipse(QPoint(postion[i][0], postion[i][1]), radius / 10, radius / 10);

	QFont font("Times", 16, QFont::Bold, true);//����������;
	painter.setFont(font);
	QString tem;
	for (int i = 0; i < vertexNum; i++)
	{
		tem = theGraph->getValue(i);
		painter.drawText(QPoint(postion[i][0], postion[i][1]), tem);
	}


	for (int i = 0; i < vertexNum; i++)
		delete[]postion[i];
	delete[]postion;
}
