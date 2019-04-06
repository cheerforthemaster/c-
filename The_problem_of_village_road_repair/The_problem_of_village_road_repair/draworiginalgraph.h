#ifndef DRAWORIGINALGRAPH_H
#define DRAWORIGINALGRAPH_H

#include <QDialog>
#include <QPainter>
#include <cmath>
#include "ui_draworiginalgraph.h"
#include "graph.h"


class draworiginalgraph : public QDialog
{
	Q_OBJECT

public:
	draworiginalgraph(QWidget *parent = 0);
	~draworiginalgraph();
	bool GetGraph(graph<char, int>* one);

private:
	Ui::draworiginalgraph ui;
	graph<char, int>* theGraph;
	void paintEvent(QPaintEvent * event);

};

#endif // DRAWORIGINALGRAPH_H
