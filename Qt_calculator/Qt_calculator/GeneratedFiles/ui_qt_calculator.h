/********************************************************************************
** Form generated from reading UI file 'qt_calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_CALCULATOR_H
#define UI_QT_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
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

class Ui_Expression_evaluationClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_14;
    QPushButton *pushButton_18;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_17;
    QPushButton *pushButton_13;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QPushButton *pushButton_16;
    QPushButton *pushButton_8;
    QPushButton *pushButton_15;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_19;
    QPushButton *pushButton_0;
    QPushButton *pushButton_10;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Expression_evaluationClass)
    {
        if (Expression_evaluationClass->objectName().isEmpty())
            Expression_evaluationClass->setObjectName(QStringLiteral("Expression_evaluationClass"));
        Expression_evaluationClass->resize(350, 524);
        Expression_evaluationClass->setMinimumSize(QSize(350, 524));
        Expression_evaluationClass->setMaximumSize(QSize(350, 524));
        Expression_evaluationClass->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(Expression_evaluationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(50, 50));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(0, 70));
        pushButton_14->setMaximumSize(QSize(80, 16777215));
        pushButton_14->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Qt_calculator/Resources/d4628535e5dde711b23510aea6efce1b9c166186.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_14, 1, 3, 1, 1);

        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(0, 70));
        pushButton_18->setMaximumSize(QSize(80, 16777215));
        pushButton_18->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Qt_calculator/Resources/QQ\345\233\276\347\211\20720170921182812.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon1);
        pushButton_18->setIconSize(QSize(45, 45));

        gridLayout->addWidget(pushButton_18, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 70));
        pushButton_5->setMaximumSize(QSize(80, 16777215));
        pushButton_5->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Qt_calculator/Resources/5_48px_1168277_easyicon.net - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon2);
        pushButton_5->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 70));
        pushButton_6->setMaximumSize(QSize(80, 16777215));
        pushButton_6->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Qt_calculator/Resources/6_48px_1168279_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(0, 70));
        pushButton_17->setMaximumSize(QSize(80, 16777215));
        pushButton_17->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Qt_calculator/Resources/QQ\345\233\276\347\211\20720170921182800.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon4);
        pushButton_17->setIconSize(QSize(45, 45));

        gridLayout->addWidget(pushButton_17, 0, 1, 1, 1);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(0, 70));
        pushButton_13->setMaximumSize(QSize(80, 16777215));
        pushButton_13->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Qt_calculator/Resources/little-minus-symbol_318-25368.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon5);

        gridLayout->addWidget(pushButton_13, 2, 3, 1, 1);

        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 70));
        pushButton_1->setMaximumSize(QSize(80, 16777215));
        pushButton_1->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Qt_calculator/Resources/1_48px_1168269_easyicon.net - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_1->setIcon(icon6);
        pushButton_1->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_1, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 70));
        pushButton_2->setMaximumSize(QSize(80, 16777215));
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Qt_calculator/Resources/2_48px_1168271_easyicon.net - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon7);
        pushButton_2->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 70));
        pushButton_3->setMaximumSize(QSize(80, 16777215));
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Qt_calculator/Resources/3_48px_1168273_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon8);
        pushButton_3->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_3, 3, 2, 1, 1);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 70));
        pushButton_12->setMaximumSize(QSize(80, 16777215));
        pushButton_12->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Qt_calculator/Resources/a08b87d6277f9e2fda25102e1d30e924b899f380 - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon9);
        pushButton_12->setIconSize(QSize(35, 35));

        gridLayout->addWidget(pushButton_12, 3, 3, 1, 1);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 70));
        pushButton_9->setMaximumSize(QSize(80, 16777215));
        pushButton_9->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Qt_calculator/Resources/9_48px_1168285_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon10);
        pushButton_9->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(0, 70));
        pushButton_16->setMaximumSize(QSize(80, 16777215));
        pushButton_16->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Qt_calculator/Resources/delete_point_26px_1073731_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon11);
        pushButton_16->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_16, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 70));
        pushButton_8->setMaximumSize(QSize(80, 16777215));
        pushButton_8->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Qt_calculator/Resources/8_48px_1168283_easyicon.net - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon12);
        pushButton_8->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(0, 70));
        pushButton_15->setMaximumSize(QSize(80, 16777215));
        pushButton_15->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Qt_calculator/Resources/a1ec08fa513d269721a8857457fbb2fb4316d8a4.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon13);
        pushButton_15->setIconSize(QSize(35, 35));

        gridLayout->addWidget(pushButton_15, 0, 3, 1, 1);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 70));
        pushButton_7->setMaximumSize(QSize(80, 16777215));
        pushButton_7->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Qt_calculator/Resources/7_48px_1168281_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon14);
        pushButton_7->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(0, 70));
        pushButton_11->setMaximumSize(QSize(80, 16777215));
        pushButton_11->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Qt_calculator/Resources/20140429190312-1688988626.png.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon15);

        gridLayout->addWidget(pushButton_11, 4, 2, 1, 1);

        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(0, 70));
        pushButton_19->setMaximumSize(QSize(80, 16777215));
        pushButton_19->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Qt_calculator/Resources/t0133292e59531bace9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon16);
        pushButton_19->setIconSize(QSize(35, 35));

        gridLayout->addWidget(pushButton_19, 4, 3, 1, 1);

        pushButton_0 = new QPushButton(centralWidget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setMinimumSize(QSize(0, 70));
        pushButton_0->setMaximumSize(QSize(80, 16777215));
        pushButton_0->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Qt_calculator/Resources/0_48px_1168267_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_0->setIcon(icon17);
        pushButton_0->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_0, 4, 1, 1, 1);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 70));
        pushButton_10->setMaximumSize(QSize(80, 16777215));
        pushButton_10->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Qt_calculator/Resources/QQ\345\233\276\347\211\20720170921184942.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon18);
        pushButton_10->setIconSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_10, 4, 0, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 70));
        pushButton_4->setMaximumSize(QSize(80, 16777215));
        pushButton_4->setStyleSheet(QLatin1String("background-color: rgba(240, 240, 240, 100);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/Qt_calculator/Resources/4_48px_1168275_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon19);
        pushButton_4->setIconSize(QSize(58, 58));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        Expression_evaluationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Expression_evaluationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 350, 26));
        Expression_evaluationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Expression_evaluationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Expression_evaluationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Expression_evaluationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Expression_evaluationClass->setStatusBar(statusBar);

        retranslateUi(Expression_evaluationClass);

        QMetaObject::connectSlotsByName(Expression_evaluationClass);
    } // setupUi

    void retranslateUi(QMainWindow *Expression_evaluationClass)
    {
        Expression_evaluationClass->setWindowTitle(QApplication::translate("Expression_evaluationClass", "\350\256\241\347\256\227\345\231\250", 0));
        lineEdit->setPlaceholderText(QApplication::translate("Expression_evaluationClass", "\344\277\235\347\225\231\345\260\217\346\225\260\347\202\271\345\220\2164\344\275\215", 0));
        pushButton_14->setText(QString());
        pushButton_18->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_17->setText(QString());
        pushButton_13->setText(QString());
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_12->setText(QString());
        pushButton_9->setText(QString());
        pushButton_16->setText(QString());
        pushButton_8->setText(QString());
        pushButton_15->setText(QString());
        pushButton_7->setText(QString());
        pushButton_11->setText(QString());
        pushButton_19->setText(QString());
        pushButton_0->setText(QString());
        pushButton_10->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Expression_evaluationClass: public Ui_Expression_evaluationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_CALCULATOR_H
