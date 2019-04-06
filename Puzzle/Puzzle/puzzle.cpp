#include "puzzle.h"

Puzzle::Puzzle(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.action, SIGNAL(triggered()), this, SLOT(OnChoose()));
	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(OnNewGame()));
	connect(ui.action_3, SIGNAL(triggered()), this, SLOT(OnsetDifficulty()));
	connect(ui.action_4, SIGNAL(triggered()), this, SLOT(OnSeeSource()));

	m_mouse = false;
	num = 3;//Ĭ���Ѷ�
	rect = NULL;
	c_filename = ":/Puzzle/Resources/m.jpg";//Ĭ��ͼƬ
	prepicture.load(c_filename);
	OnNewGame();
}

Puzzle::~Puzzle()
{
	if (rect != NULL)
	{
		delete[]rect;
	}
}

void Puzzle::paintEvent(QPaintEvent * event)//��ԭͼ��������rect�ŷ�
{
	int imgWidth = prepicture.width();
	int imgHeight = prepicture.height();
	if (imgHeight == 0 || imgWidth == 0)
	{
		return;
	}
	if (rect == NULL)
	{
		return;
	}
	QPainter painter(this);
	int width = this->width();
	int height = this->height()-40;
	QRect target;//Ŀ�����

	int left = 0;
	int top = 0;
	for (int i = 0; i < num*num; i++)
	{
		left = (width / num)*(i%num);
		top = (height / num)*(i / num);

		target.setRect(left, top, width / num, height / num);
		if (rect[i] != -1)
		{
			source.setRect((imgWidth / num)*(rect[i] % num), (imgHeight / num)*(rect[i] / num), imgWidth / num, imgHeight / num);
			painter.drawPixmap(target, prepicture, source);
		}
	}
}

void Puzzle::keyPressEvent(QKeyEvent * event)//�հ������������� F5Ϊ���¿�ʼ��Ϸ
{
	if (event->key()==Qt::Key_Up)
	{
		moveKey = 1;
		keyevent();
	}
	if (event->key() == Qt::Key_Down)
	{
		moveKey = 2;
		keyevent();
	}
	if (event->key() == Qt::Key_Left)
	{
		moveKey = 3;		
		keyevent();

	}
	if (event->key() == Qt::Key_Right)
	{
		moveKey = 4;
		keyevent();
	}
	if (event->key() == Qt::Key_F5)
	{
		OnNewGame();
	}

}

void Puzzle::mousePressEvent(QMouseEvent * event)//��갴��
{
	m_mouse = true;
	vec.insert(vec.end(), event->pos());
}

void Puzzle::mouseReleaseEvent(QMouseEvent * event)//����ɿ�
{
	m_mouse = false;
	vec.insert(vec.end(), event->pos());
	QPoint beginPoint = vec[0];//��ͷ�ĵ� ��갴�µĵ�
	QPoint endPoint = vec[vec.size() - 1];//��β�ĵ� ����ɿ��ĵ�
	vec.clear();
	
	int width = this->width();
	int height = this->height() - 40;
	int beRow = 0;
	int beColumn = 0;
	int enRow = 0;
	int enColumn = 0;
	if ((beginPoint.x() > 0 && beginPoint.x() < width) && (beginPoint.y() > 0 && beginPoint.y() < height) && (endPoint.x() > 0 && endPoint.x() < width) && (endPoint.y() > 0 && endPoint.y() < height))//�Ƿ��ڽ���֮��
	{
		for (int i = 0; i < num; i++)//�ж���ʼ�����ֹ�������
		{
			if (beginPoint.x() > (width / num)*i)
			{
				beColumn = i;
			}
			if (endPoint.x() > (width / num)*i)
			{
				enColumn = i;
			}
			if (beginPoint.y() > (height / num)*i)
			{
				beRow = i;
			}
			if (endPoint.y() > (height / num)*i)
			{
				enRow = i;
			}
		}
		if ((abs(beRow - enRow) + abs(beColumn - enColumn)) == 1)//��������
		{
			if (rect[beRow*num + beColumn] == -1 || rect[enRow*num + enColumn] == -1)//�пհ���
			{
				int temint = rect[beRow*num + beColumn];
				rect[beRow*num + beColumn] = rect[enRow*num + enColumn];
				rect[enRow*num + enColumn] = temint;
				update();
				issuccess();
			}
		}
	}
	else
		return;


}

bool Puzzle::OnChoose()
{
	filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ���ļ�"));
	if (filename.isEmpty())
	{
		return false;
	}
	QByteArray bty = filename.toLocal8Bit();
	c_filename = bty.data();
	
	if (!prepicture.load(c_filename))
	{
		return false;
	}
	OnNewGame();
	return false;
}

bool Puzzle::keyevent()
{
	if (rect == NULL)
	{
		return false;
	}
	int postion = -1;
	for (int i = 0; i < num*num; i++)
	{
		if (rect[i] == -1)
		{
			postion = i;
			break;
		}
	}

	int row = postion / num;
	int column = postion%num;
	int otherPos = 0;
	//��Ϊ�ǿհ������ƶ� ����Ҫ�ߵ����� ����
	if (moveKey == 2 && row != 0)//��
	{
		row = row - 1;
	}
	if (moveKey == 1 && row != num - 1)//��
	{
		row = row + 1;
	}
	if (moveKey == 4 && column != 0)//��
	{
		column = column - 1;
	}
	if (moveKey == 3 && column != num - 1)//��
	{
		column = column + 1;
	}
	otherPos = row*num + column;
	int temint = rect[postion];
	rect[postion] = rect[otherPos];
	rect[otherPos] = temint;
	update();
	issuccess();
	return false;
}

bool Puzzle::issuccess()
{
	for (int i = 0; i < num*num - 1; i++)
	{
		if (rect[i] != i)
		{
			return false;
		}
	}
	QMessageBox::information(this,"success!",QString::fromLocal8Bit("�ɹ�������"));
	return false;
}

bool Puzzle::OnNewGame()
{
	if (rect == NULL)
	{
		rect = new int[num*num];
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < num*num; i++)
			rect[i] = i;
	rect[num*num - 1] = -1;//�հ���

	int tempostion = 0;
	int temint = 0;
	for (int i = 0; i < num*num; i++)//����ߵ�
	{
		tempostion = rand() % (num*num);
		temint = rect[tempostion];
		rect[tempostion] = rect[i];
		rect[i] = temint;
	}
	for (int i = 0; i < num*num; i++)//�հ����ŵ����½�
	{
		if (rect[i] == -1)
		{
			temint = rect[num*num - 1];
			rect[num*num - 1] = -1;
			rect[i] = temint;
			break;
		}
	}
	int inversion = 0;
	for (int i = 0; i < num*num; i++)
		for (int j = 0; j < i; j++)//����������
		{
			if (rect[j] > rect[i])
			{
				inversion++;
			}
		}
	if (inversion % 2 == 1)//��Ϊ�����-1 ����Ŀ�������Ϊż��
	{
		temint = rect[0];
		rect[0] = rect[1];
		rect[1] = temint;
	}
	update();
	return false;
}

bool Puzzle::OnsetDifficulty()
{
	if (rect != NULL)
	{
		delete[]rect;
		rect = NULL;
	}
	setDifficult *Getdiff = new setDifficult(this);
	Getdiff->getDifficult(&num);
	Getdiff->exec();
	rect = NULL;
	OnNewGame();
	return false;
}

bool Puzzle::OnSeeSource()
{
	if (!filename.isEmpty())
	{
		sourcePictrue *original = new sourcePictrue(this);
		original->getPictrue(filename);
		original->setModal(false);
		original->show();
	}
	else
	{
		sourcePictrue *original = new sourcePictrue(this);
		original->getPictrue(c_filename);
		original->setModal(false);
		original->show();
	}
	return false;
}
