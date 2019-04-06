#include "mine_clearance.h"

mine_clearance::mine_clearance(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	difficulty = 1;//默认为初级
	group = NULL;
	rec = NULL;
	setDifficulty();

	Qpix = new QPixmap[36];
	blankQpix.load(":/mine_clearance/Resources/blank.gif");
	Qpix[0].load(":/mine_clearance/Resources/0.gif");
	Qpix[1].load(":/mine_clearance/Resources/1.gif");
	Qpix[2].load(":/mine_clearance/Resources/2.gif");
	Qpix[3].load(":/mine_clearance/Resources/3.gif");
	Qpix[4].load(":/mine_clearance/Resources/4.gif");
	Qpix[5].load(":/mine_clearance/Resources/5.gif");
	Qpix[6].load(":/mine_clearance/Resources/6.gif");
	Qpix[7].load(":/mine_clearance/Resources/7.gif");
	Qpix[8].load(":/mine_clearance/Resources/8.gif");

	Qpix[10].load(":/mine_clearance/Resources/blood.gif");
	Qpix[11].load(":/mine_clearance/Resources/mine.gif");
	Qpix[12].load(":/mine_clearance/Resources/flag.gif");
	Qpix[13].load(":/mine_clearance/Resources/ask.gif");

	Qpix[14].load(":/mine_clearance/Resources/face0.gif");
	Qpix[15].load(":/mine_clearance/Resources/face4.gif");
	Qpix[16].load(":/mine_clearance/Resources/face3.gif");


	isContinue = true;


	connect(ui.action, SIGNAL(triggered()), this, SLOT(setDifficulty()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(setDifficulty()));
	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(primary()));
	connect(ui.action_3, SIGNAL(triggered()), this, SLOT(intermediate()));
	connect(ui.action_4, SIGNAL(triggered()), this, SLOT(senior()));
	connect(ui.action_5, SIGNAL(triggered()), this, SLOT(EXIT()));


}

mine_clearance::~mine_clearance()
{
	initialGroup();
	initialRect();
	delete[]Qpix;
}

void mine_clearance::setGroup()
{
	group = new int*[heNum];
	for (int i = 0; i < heNum; i++)
		group[i] = new int[wiNum];

	for (int i = 0; i < heNum; i++)
		for (int j = 0; j < wiNum; j++)
			group[i][j] = -1;//初始方格

	srand((unsigned)time(NULL));
	int x = 0, y = 0;
	int n = 0;
	while (n<mine)
	{
		x = rand() % heNum;
		y = rand() % wiNum;
		if (group[x][y] != 9)//9为未翻开的雷
		{
			group[x][y] = 9;
			n++;
		}
	}

}

void mine_clearance::initialGroup()
{
	if (group != NULL)
	{
		for (int i = 0; i < heNum; i++)
			delete[]group[i];
		delete[]group;
	}
	group = NULL;
}

void mine_clearance::setRect()
{
	rec = new QRect *[heNum];
	for (int i = 0; i < heNum; i++)
		rec[i] = new QRect[wiNum];

	for (int i = 0; i < heNum; i++)
		for (int j = 0; j < wiNum; j++)
			rec[i][j].setRect(original.x() + j * 16, original.y() + i * 16, 16, 16);
}

void mine_clearance::initialRect()
{
	if (rec != NULL)
	{
		for (int i = 0; i < heNum; i++)
			delete[]rec[i];
		delete[]rec;
	}
	rec = NULL;
}


void mine_clearance::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	original = ui.Mwidget->pos();
	original.setY(original.y() + 26);//偏差调整
	height = ui.Mwidget->height();
	width = ui.Mwidget->width();
	endPoint.setX(original.x() + width);
	endPoint.setY(original.y() + height);
	setRect();
	int n = 0;
	for (int i = 0; i < heNum; i++)
		for (int j = 0; j < wiNum; j++)
		{
			if (group[i][j] == 9 || group[i][j] == -1)//9为没有点击的雷 -1为初始方块
			{

				painter.drawPixmap(rec[i][j], blankQpix);
				if (isContinue)
				{
					ui.pushButton->setIcon(Qpix[14]);
					ui.pushButton->setIconSize(QSize(28, 28));
				}
			}
			else
			{
				if (group[i][j] == 20)
				{
					painter.drawPixmap(rec[i][j], Qpix[12]);
					continue;
				}
				if (group[i][j] == 21)
				{
					painter.drawPixmap(rec[i][j], Qpix[13]);
					continue;
				}
				n++;
				painter.drawPixmap(rec[i][j], Qpix[group[i][j]]);
				if (group[i][j] == 10&&isContinue)//踩到雷了
				{
					ui.pushButton->setIcon(Qpix[16]);
					ui.pushButton->setIconSize(QSize(28, 28));
					for (int k = 0; k < heNum; k++)
					{
						for (int g = 0; g < wiNum; g++)
						{
							if (group[k][g] == 9)
							{
								group[k][g] = 11;
								painter.drawPixmap(rec[k][g], Qpix[group[k][g]]);
							}
						}
					}
					isContinue=false;
					update();
					return;
				}
			}
		}
	if (wiNum*heNum - n == mine)
	{
		isContinue = false;
		ui.pushButton->setIcon(Qpix[15]);
		ui.pushButton->setIconSize(QSize(28, 28));
	}
}

bool mine_clearance::primary()
{
	difficulty = 1;
	setDifficulty();
	return true;
}

bool mine_clearance::intermediate()
{
	difficulty = 2;
	setDifficulty();
	return true;
}

bool mine_clearance::senior()
{
	difficulty = 3;
	setDifficulty();
	return true;
}

void mine_clearance::setDifficulty()
{
	isContinue = true;
	switch (difficulty)
	{
	case 1:
		initialGroup();
		initialRect();
		wiNum = 9;
		heNum = 9;
		mine = 10;
		setGroup();
		setRect();
		resize(166, 254);
		update();
		break;
	case 2:
		initialGroup();
		initialRect();
		wiNum = 16;
		heNum = 16;
		mine = 40;
		setGroup();
		setRect();
		resize(278, 366);
		update();
		break;
	case 3:
		initialGroup();
		initialRect();
		wiNum = 32;
		heNum = 16;
		mine = 99;
		setGroup();
		setRect();
		resize(534, 366);
		update();
		break;
	default:
		exit(1);
	}
}

void mine_clearance::mousePressEvent(QMouseEvent *event)
{
	QPoint Pos = event->pos();
	int x = Pos.x();
	int y = Pos.y();
	if (x > original.x() && x<endPoint.x() && y>original.y() && y < endPoint.y()&&isContinue)
	{
		x = (x - original.x()) / 16;
		y = (y - original.y()) / 16;

		if (event->button() == Qt::LeftButton)
		{
			if (group[y][x] == -1)
				flood(y, x);
			if (group[y][x] == 9)
				group[y][x] = 10;
			update();
		}
		else if (event->button() == Qt::RightButton)
		{
			if (group[y][x] == -1)//不是雷的方块放旗
			{
				group[y][x] = 12;
				update();
				return;
			}
			if (group[y][x] == 12)
			{
				group[y][x] = 13;
				update();
				return;
			}
			if (group[y][x] == 13)
			{
				group[y][x] = -1;
				update();
				return;
			}
			if (group[y][x] == 9)//是雷的方格放旗
			{
				group[y][x] = 20;
				update();
				return;
			}
			if (group[y][x] == 20)
			{
				group[y][x] = 21;
				update();
				return;
			}
			if (group[y][x] == 21)
			{
				group[y][x] = 9;
				update();
				return;
			}
		}
	}

}

int mine_clearance::flood(int x, int y)
{
	if (x<0 || y<0 || x>=heNum || y>=wiNum)
		return 0;

	if (group[x][y] != -1)
	{
		if (group[x][y] == 9)
			group[x][y] = 10;
		return group[x][y];
	}

	group[x][y] = haveMine(x, y);

	if (group[x][y] != 0)
	{
		return group[x][y];
	}

	flood(x, y - 1);
	flood(x - 1, y);
	flood(x + 1, y);
	flood(x, y + 1);

	return 0;
}

int mine_clearance::haveMine(int x, int y)
{
	int n = 0;
	if (y - 1 >= 0)
	{
		if (x - 1 >= 0)
			if (group[x - 1][y - 1] == 9|| group[x - 1][y - 1] == 20 || group[x - 1][y - 1] == 21)
				n++;
		if (group[x][y - 1] == 9 || group[x][y - 1] == 20 || group[x][y - 1] == 21)
			n++;
		if (x + 1 < heNum)
			if (group[x + 1][y - 1] == 9 || group[x + 1][y - 1] == 20 || group[x + 1][y - 1] == 21)
				n++;
	}
	if (x - 1 >= 0)
		if (group[x - 1][y] == 9 || group[x - 1][y] == 20 || group[x - 1][y] == 21)
			n++;
	if (x + 1 < heNum)
		if (group[x + 1][y] == 9 || group[x + 1][y] == 20 || group[x + 1][y] == 21)
			n++;
	if (y + 1 < wiNum)
	{
		if (x - 1 >= 0)
			if (group[x - 1][y + 1] == 9 || group[x - 1][y + 1] == 20 || group[x - 1][y + 1] == 21)
				n++;
		if (group[x][y + 1] == 9 || group[x][y + 1] == 20 || group[x][y + 1] == 21)
			n++;
		if (x + 1 < heNum)
			if (group[x + 1][y + 1] == 9 || group[x + 1][y + 1] == 20 || group[x + 1][y + 1] == 21)
				n++;
	}
	return n;
}

bool mine_clearance::EXIT()
{
	exit(0);
	return true;
}