/********************************************************************************
** Form generated from reading UI file 'creatbinarytree.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATBINARYTREE_H
#define UI_CREATBINARYTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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

class Ui_CreatBinaryTreeClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *twovisitButton;
    QPushButton *showButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QPushButton *findButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *swapButton;
    QPlainTextEdit *plainTextEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CreatBinaryTreeClass)
    {
        if (CreatBinaryTreeClass->objectName().isEmpty())
            CreatBinaryTreeClass->setObjectName(QStringLiteral("CreatBinaryTreeClass"));
        CreatBinaryTreeClass->resize(606, 625);
        CreatBinaryTreeClass->setMinimumSize(QSize(0, 0));
        CreatBinaryTreeClass->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(CreatBinaryTreeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(60, 0));
        comboBox->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(comboBox);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(comboBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        twovisitButton = new QPushButton(centralWidget);
        twovisitButton->setObjectName(QStringLiteral("twovisitButton"));

        horizontalLayout_2->addWidget(twovisitButton);

        showButton = new QPushButton(centralWidget);
        showButton->setObjectName(QStringLiteral("showButton"));

        horizontalLayout_2->addWidget(showButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setMinimumSize(QSize(0, 100));
        plainTextEdit->setMaximumSize(QSize(16777215, 16777215));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_6->addWidget(lineEdit_2);

        findButton = new QPushButton(centralWidget);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout_6->addWidget(findButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setReadOnly(true);

        horizontalLayout_7->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        swapButton = new QPushButton(centralWidget);
        swapButton->setObjectName(QStringLiteral("swapButton"));

        horizontalLayout_8->addWidget(swapButton);


        verticalLayout->addLayout(horizontalLayout_8);

        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setMinimumSize(QSize(0, 100));
        plainTextEdit_2->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit_2);

        CreatBinaryTreeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CreatBinaryTreeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 606, 26));
        CreatBinaryTreeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CreatBinaryTreeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CreatBinaryTreeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CreatBinaryTreeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CreatBinaryTreeClass->setStatusBar(statusBar);

        retranslateUi(CreatBinaryTreeClass);

        QMetaObject::connectSlotsByName(CreatBinaryTreeClass);
    } // setupUi

    void retranslateUi(QMainWindow *CreatBinaryTreeClass)
    {
        CreatBinaryTreeClass->setWindowTitle(QApplication::translate("CreatBinaryTreeClass", "CreatBinaryTree", 0));
        label->setText(QApplication::translate("CreatBinaryTreeClass", "\347\251\272\347\273\223\347\202\271\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CreatBinaryTreeClass", "#", 0)
         << QApplication::translate("CreatBinaryTreeClass", "-1", 0)
         << QApplication::translate("CreatBinaryTreeClass", ";", 0)
         << QApplication::translate("CreatBinaryTreeClass", ",", 0)
         << QApplication::translate("CreatBinaryTreeClass", ".", 0)
        );
        label_2->setText(QApplication::translate("CreatBinaryTreeClass", "\345\210\233\345\273\272\346\226\271\345\274\217\357\274\232", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("CreatBinaryTreeClass", "\345\261\202\346\254\241\345\210\233\345\273\272", 0)
         << QApplication::translate("CreatBinaryTreeClass", "\345\211\215\345\272\217\345\210\233\345\273\272", 0)
        );
        twovisitButton->setText(QApplication::translate("CreatBinaryTreeClass", "\345\211\215\345\272\217\345\212\240\344\270\255\345\272\217\345\210\233\345\273\272", 0));
        showButton->setText(QApplication::translate("CreatBinaryTreeClass", "\346\230\276\347\244\272\345\233\276\345\203\217", 0));
        label_3->setText(QApplication::translate("CreatBinaryTreeClass", "\346\240\221\347\232\204\347\273\223\347\202\271\357\274\232", 0));
        lineEdit->setPlaceholderText(QApplication::translate("CreatBinaryTreeClass", "\347\251\272\346\240\274\344\270\272\351\227\264\351\232\224\347\254\246; eg :1 2 3 # # # #", 0));
        pushButton->setText(QApplication::translate("CreatBinaryTreeClass", "\345\210\233\345\273\272", 0));
        label_4->setText(QApplication::translate("CreatBinaryTreeClass", "\351\201\215\345\216\206\357\274\232", 0));
        plainTextEdit->setPlaceholderText(QApplication::translate("CreatBinaryTreeClass", "\346\230\276\347\244\272\346\240\221\347\232\204\344\277\241\346\201\257", 0));
        label_5->setText(QApplication::translate("CreatBinaryTreeClass", "\346\237\245\350\257\242\357\274\232", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("CreatBinaryTreeClass", "\350\276\223\345\205\245\344\270\200\344\270\252\347\273\223\347\202\271", 0));
        findButton->setText(QApplication::translate("CreatBinaryTreeClass", "\346\237\245\350\257\242", 0));
        label_6->setText(QApplication::translate("CreatBinaryTreeClass", "\347\273\223\346\236\234\357\274\232", 0));
        label_7->setText(QApplication::translate("CreatBinaryTreeClass", "\344\272\244\346\215\242\345\267\246\345\217\263\345\255\220\346\240\221\357\274\232", 0));
        swapButton->setText(QApplication::translate("CreatBinaryTreeClass", "\344\272\244\346\215\242", 0));
        plainTextEdit_2->setPlaceholderText(QApplication::translate("CreatBinaryTreeClass", "\344\272\244\346\215\242\345\220\216\346\230\276\347\244\272\346\240\221\347\232\204\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatBinaryTreeClass: public Ui_CreatBinaryTreeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATBINARYTREE_H
