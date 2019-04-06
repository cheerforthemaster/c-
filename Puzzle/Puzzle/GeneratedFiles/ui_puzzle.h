/********************************************************************************
** Form generated from reading UI file 'puzzle.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLE_H
#define UI_PUZZLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuzzleClass
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PuzzleClass)
    {
        if (PuzzleClass->objectName().isEmpty())
            PuzzleClass->setObjectName(QStringLiteral("PuzzleClass"));
        PuzzleClass->resize(518, 745);
        action = new QAction(PuzzleClass);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(PuzzleClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(PuzzleClass);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(PuzzleClass);
        action_4->setObjectName(QStringLiteral("action_4"));
        centralWidget = new QWidget(PuzzleClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PuzzleClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PuzzleClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 518, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        PuzzleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PuzzleClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PuzzleClass->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PuzzleClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PuzzleClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_4);
        menu_2->addAction(action_3);

        retranslateUi(PuzzleClass);

        QMetaObject::connectSlotsByName(PuzzleClass);
    } // setupUi

    void retranslateUi(QMainWindow *PuzzleClass)
    {
        PuzzleClass->setWindowTitle(QApplication::translate("PuzzleClass", "Puzzle", 0));
        action->setText(QApplication::translate("PuzzleClass", "\351\200\211\346\213\251\346\226\207\344\273\266", 0));
        action_2->setText(QApplication::translate("PuzzleClass", "\351\207\215\346\226\260\345\274\200\345\247\213(F5)", 0));
        action_3->setText(QApplication::translate("PuzzleClass", "\351\232\276\345\272\246\350\256\276\347\275\256", 0));
        action_4->setText(QApplication::translate("PuzzleClass", "\346\237\245\347\234\213\345\216\237\345\233\276", 0));
        menu->setTitle(QApplication::translate("PuzzleClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("PuzzleClass", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class PuzzleClass: public Ui_PuzzleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLE_H
