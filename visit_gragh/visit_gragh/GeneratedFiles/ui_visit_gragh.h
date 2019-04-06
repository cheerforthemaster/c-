/********************************************************************************
** Form generated from reading UI file 'visit_gragh.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISIT_GRAGH_H
#define UI_VISIT_GRAGH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visit_graghClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *visit_graghClass)
    {
        if (visit_graghClass->objectName().isEmpty())
            visit_graghClass->setObjectName(QStringLiteral("visit_graghClass"));
        visit_graghClass->resize(600, 400);
        menuBar = new QMenuBar(visit_graghClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        visit_graghClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(visit_graghClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        visit_graghClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(visit_graghClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        visit_graghClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(visit_graghClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        visit_graghClass->setStatusBar(statusBar);

        retranslateUi(visit_graghClass);

        QMetaObject::connectSlotsByName(visit_graghClass);
    } // setupUi

    void retranslateUi(QMainWindow *visit_graghClass)
    {
        visit_graghClass->setWindowTitle(QApplication::translate("visit_graghClass", "visit_gragh", 0));
    } // retranslateUi

};

namespace Ui {
    class visit_graghClass: public Ui_visit_graghClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISIT_GRAGH_H
