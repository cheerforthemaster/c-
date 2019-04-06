#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H

#include <QDialog>
#include <QPainter>
#include <cmath>
#include "ui_drawgraph.h"
#include "graph.h"

class drawgraph : public QDialog
{
	Q_OBJECT

public:
	drawgraph(QWidget *parent = 0);
	~drawgraph();
	bool GetGraph(graph<char, int>* one);
private:
	Ui::drawgraph ui;
	graph<char, int>* theGraph;
	void paintEvent(QPaintEvent * event);

};

#endif // DRAWGRAPH_H
