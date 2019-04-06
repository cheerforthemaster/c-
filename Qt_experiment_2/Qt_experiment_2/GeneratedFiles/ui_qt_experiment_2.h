/********************************************************************************
** Form generated from reading UI file 'qt_experiment_2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_EXPERIMENT_2_H
#define UI_QT_EXPERIMENT_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_experiment_2Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QFrame *frame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_experiment_2Class)
    {
        if (Qt_experiment_2Class->objectName().isEmpty())
            Qt_experiment_2Class->setObjectName(QStringLiteral("Qt_experiment_2Class"));
        Qt_experiment_2Class->resize(649, 592);
        centralWidget = new QWidget(Qt_experiment_2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        Qt_experiment_2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qt_experiment_2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 649, 26));
        Qt_experiment_2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_experiment_2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Qt_experiment_2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qt_experiment_2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Qt_experiment_2Class->setStatusBar(statusBar);

        retranslateUi(Qt_experiment_2Class);

        QMetaObject::connectSlotsByName(Qt_experiment_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_experiment_2Class)
    {
        Qt_experiment_2Class->setWindowTitle(QApplication::translate("Qt_experiment_2Class", "Qt_experiment_2", 0));
        pushButton->setText(QApplication::translate("Qt_experiment_2Class", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Qt_experiment_2Class: public Ui_Qt_experiment_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_EXPERIMENT_2_H
