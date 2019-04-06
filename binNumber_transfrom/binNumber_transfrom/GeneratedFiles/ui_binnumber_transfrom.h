/********************************************************************************
** Form generated from reading UI file 'binnumber_transfrom.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINNUMBER_TRANSFROM_H
#define UI_BINNUMBER_TRANSFROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_binNumber_transfromClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *binNumber_transfromClass)
    {
        if (binNumber_transfromClass->objectName().isEmpty())
            binNumber_transfromClass->setObjectName(QStringLiteral("binNumber_transfromClass"));
        binNumber_transfromClass->resize(600, 400);
        centralWidget = new QWidget(binNumber_transfromClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        binNumber_transfromClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(binNumber_transfromClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        binNumber_transfromClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(binNumber_transfromClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        binNumber_transfromClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(binNumber_transfromClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        binNumber_transfromClass->setStatusBar(statusBar);

        retranslateUi(binNumber_transfromClass);

        QMetaObject::connectSlotsByName(binNumber_transfromClass);
    } // setupUi

    void retranslateUi(QMainWindow *binNumber_transfromClass)
    {
        binNumber_transfromClass->setWindowTitle(QApplication::translate("binNumber_transfromClass", "binNumber_transfrom", 0));
        label->setText(QApplication::translate("binNumber_transfromClass", "\344\272\214\350\277\233\345\210\266\346\225\260\357\274\232", 0));
        pushButton->setText(QApplication::translate("binNumber_transfromClass", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class binNumber_transfromClass: public Ui_binNumber_transfromClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINNUMBER_TRANSFROM_H
