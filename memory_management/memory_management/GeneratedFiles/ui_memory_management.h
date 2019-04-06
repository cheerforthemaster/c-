/********************************************************************************
** Form generated from reading UI file 'memory_management.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORY_MANAGEMENT_H
#define UI_MEMORY_MANAGEMENT_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memory_managementClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *apply_1;
    QPushButton *release_1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QPushButton *apply_2;
    QPushButton *release_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QPushButton *apply_3;
    QPushButton *release_3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *memory_managementClass)
    {
        if (memory_managementClass->objectName().isEmpty())
            memory_managementClass->setObjectName(QStringLiteral("memory_managementClass"));
        memory_managementClass->resize(649, 463);
        centralWidget = new QWidget(memory_managementClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        apply_1 = new QPushButton(centralWidget);
        apply_1->setObjectName(QStringLiteral("apply_1"));

        horizontalLayout->addWidget(apply_1);

        release_1 = new QPushButton(centralWidget);
        release_1->setObjectName(QStringLiteral("release_1"));

        horizontalLayout->addWidget(release_1);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_2);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        apply_2 = new QPushButton(centralWidget);
        apply_2->setObjectName(QStringLiteral("apply_2"));

        horizontalLayout_4->addWidget(apply_2);

        release_2 = new QPushButton(centralWidget);
        release_2->setObjectName(QStringLiteral("release_2"));

        horizontalLayout_4->addWidget(release_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(label_3);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_6->addWidget(lineEdit_3);

        apply_3 = new QPushButton(centralWidget);
        apply_3->setObjectName(QStringLiteral("apply_3"));

        horizontalLayout_6->addWidget(apply_3);

        release_3 = new QPushButton(centralWidget);
        release_3->setObjectName(QStringLiteral("release_3"));

        horizontalLayout_6->addWidget(release_3);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout);

        memory_managementClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(memory_managementClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 649, 26));
        memory_managementClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(memory_managementClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        memory_managementClass->setStatusBar(statusBar);

        retranslateUi(memory_managementClass);

        QMetaObject::connectSlotsByName(memory_managementClass);
    } // setupUi

    void retranslateUi(QMainWindow *memory_managementClass)
    {
        memory_managementClass->setWindowTitle(QApplication::translate("memory_managementClass", "memory_management", 0));
        label->setText(QApplication::translate("memory_managementClass", "\350\277\233\347\250\2131\357\274\232", 0));
        label_5->setText(QString());
        label_4->setText(QApplication::translate("memory_managementClass", "\347\251\272\351\227\264\347\224\263\350\257\267/\351\207\212\346\224\276\357\274\232", 0));
        apply_1->setText(QApplication::translate("memory_managementClass", "\347\224\263\350\257\267", 0));
        release_1->setText(QApplication::translate("memory_managementClass", "\351\207\212\346\224\276", 0));
        label_2->setText(QApplication::translate("memory_managementClass", "\350\277\233\347\250\2132\357\274\232", 0));
        label_6->setText(QString());
        label_8->setText(QApplication::translate("memory_managementClass", "\347\251\272\351\227\264\347\224\263\350\257\267/\351\207\212\346\224\276\357\274\232", 0));
        apply_2->setText(QApplication::translate("memory_managementClass", "\347\224\263\350\257\267", 0));
        release_2->setText(QApplication::translate("memory_managementClass", "\351\207\212\346\224\276", 0));
        label_3->setText(QApplication::translate("memory_managementClass", "\350\277\233\347\250\2133\357\274\232", 0));
        label_7->setText(QString());
        label_9->setText(QApplication::translate("memory_managementClass", "\347\251\272\351\227\264\347\224\263\350\257\267/\351\207\212\346\224\276\357\274\232", 0));
        apply_3->setText(QApplication::translate("memory_managementClass", "\347\224\263\350\257\267", 0));
        release_3->setText(QApplication::translate("memory_managementClass", "\351\207\212\346\224\276", 0));
    } // retranslateUi

};

namespace Ui {
    class memory_managementClass: public Ui_memory_managementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORY_MANAGEMENT_H
