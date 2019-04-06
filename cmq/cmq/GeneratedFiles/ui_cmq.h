/********************************************************************************
** Form generated from reading UI file 'cmq.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMQ_H
#define UI_CMQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cmqClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cmqClass)
    {
        if (cmqClass->objectName().isEmpty())
            cmqClass->setObjectName(QStringLiteral("cmqClass"));
        cmqClass->resize(600, 400);
        centralWidget = new QWidget(cmqClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        cmqClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cmqClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        cmqClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cmqClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        cmqClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cmqClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        cmqClass->setStatusBar(statusBar);

        retranslateUi(cmqClass);

        QMetaObject::connectSlotsByName(cmqClass);
    } // setupUi

    void retranslateUi(QMainWindow *cmqClass)
    {
        cmqClass->setWindowTitle(QApplication::translate("cmqClass", "cmq", 0));
        pushButton->setText(QApplication::translate("cmqClass", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class cmqClass: public Ui_cmqClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMQ_H
