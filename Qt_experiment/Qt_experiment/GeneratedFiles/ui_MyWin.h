/********************************************************************************
** Form generated from reading UI file 'MyWin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIN_H
#define UI_MYWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWin
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;

    void setupUi(QWidget *MyWin)
    {
        if (MyWin->objectName().isEmpty())
            MyWin->setObjectName(QStringLiteral("MyWin"));
        MyWin->resize(542, 427);
        verticalLayout = new QVBoxLayout(MyWin);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(MyWin);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(MyWin);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 300));

        verticalLayout->addWidget(textEdit);

        lineEdit = new QLineEdit(MyWin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit);


        retranslateUi(MyWin);

        QMetaObject::connectSlotsByName(MyWin);
    } // setupUi

    void retranslateUi(QWidget *MyWin)
    {
        MyWin->setWindowTitle(QApplication::translate("MyWin", "MyWin", 0));
        pushButton->setText(QApplication::translate("MyWin", "\346\214\211\351\222\256", 0));
        lineEdit->setPlaceholderText(QApplication::translate("MyWin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWin: public Ui_MyWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIN_H
