/********************************************************************************
** Form generated from reading UI file 'qt_experiment.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_EXPERIMENT_H
#define UI_QT_EXPERIMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_experimentClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_experimentClass)
    {
        if (Qt_experimentClass->objectName().isEmpty())
            Qt_experimentClass->setObjectName(QStringLiteral("Qt_experimentClass"));
        Qt_experimentClass->setEnabled(true);
        Qt_experimentClass->resize(527, 349);
        centralWidget = new QWidget(Qt_experimentClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(true);

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        Qt_experimentClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qt_experimentClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 527, 26));
        Qt_experimentClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_experimentClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Qt_experimentClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qt_experimentClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Qt_experimentClass->setStatusBar(statusBar);

        retranslateUi(Qt_experimentClass);

        QMetaObject::connectSlotsByName(Qt_experimentClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_experimentClass)
    {
        Qt_experimentClass->setWindowTitle(QApplication::translate("Qt_experimentClass", "Qt_experiment", 0));
        checkBox->setText(QApplication::translate("Qt_experimentClass", "checked", 0));
        pushButton->setText(QApplication::translate("Qt_experimentClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Qt_experimentClass: public Ui_Qt_experimentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_EXPERIMENT_H
