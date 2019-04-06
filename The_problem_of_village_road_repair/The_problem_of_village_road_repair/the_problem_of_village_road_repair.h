#ifndef THE_PROBLEM_OF_VILLAGE_ROAD_REPAIR_H
#define THE_PROBLEM_OF_VILLAGE_ROAD_REPAIR_H

#include <QtWidgets/QMainWindow>
#include "ui_the_problem_of_village_road_repair.h"
#include "LinkQueue.h"
#include "graph.h"
#include <QMessageBox>
#include <QDebug>
#include "drawgraph.h"
#include "draworiginalgraph.h"

class The_problem_of_village_road_repair : public QMainWindow
{
	Q_OBJECT

public:
	The_problem_of_village_road_repair(QWidget *parent = 0);
	~The_problem_of_village_road_repair();
private slots:
	bool getMatrix();
	bool DrawGraph();
	bool drawOriginalGraph();
private:
	Ui::The_problem_of_village_road_repairClass ui;
	unsigned matrixSize;
	int **matrix;
	int edgeNum;
	graph<char, int>* minVillage;
	graph<char, int>* villageGraph;
	graph<char, int>* temGraph;
};

#endif // THE_PROBLEM_OF_VILLAGE_ROAD_REPAIR_H
