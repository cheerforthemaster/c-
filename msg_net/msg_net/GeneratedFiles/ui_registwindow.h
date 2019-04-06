/********************************************************************************
** Form generated from reading UI file 'registwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTWINDOW_H
#define UI_REGISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *registerUsername;
    QLabel *confirmPasswd_2;
    QLabel *username_2;
    QLineEdit *confirmPasswd;
    QLineEdit *registerPasswd;
    QLabel *passwd_2;
    QPushButton *register_button;

    void setupUi(QWidget *registWindow)
    {
        if (registWindow->objectName().isEmpty())
            registWindow->setObjectName(QStringLiteral("registWindow"));
        registWindow->resize(524, 243);
        gridLayoutWidget = new QWidget(registWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 30, 461, 158));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        registerUsername = new QLineEdit(gridLayoutWidget);
        registerUsername->setObjectName(QStringLiteral("registerUsername"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(registerUsername->sizePolicy().hasHeightForWidth());
        registerUsername->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(registerUsername, 0, 2, 1, 1);

        confirmPasswd_2 = new QLabel(gridLayoutWidget);
        confirmPasswd_2->setObjectName(QStringLiteral("confirmPasswd_2"));

        gridLayout_2->addWidget(confirmPasswd_2, 3, 1, 1, 1);

        username_2 = new QLabel(gridLayoutWidget);
        username_2->setObjectName(QStringLiteral("username_2"));
        username_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(username_2, 0, 1, 1, 1);

        confirmPasswd = new QLineEdit(gridLayoutWidget);
        confirmPasswd->setObjectName(QStringLiteral("confirmPasswd"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(confirmPasswd->sizePolicy().hasHeightForWidth());
        confirmPasswd->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(confirmPasswd, 3, 2, 1, 1);

        registerPasswd = new QLineEdit(gridLayoutWidget);
        registerPasswd->setObjectName(QStringLiteral("registerPasswd"));
        sizePolicy1.setHeightForWidth(registerPasswd->sizePolicy().hasHeightForWidth());
        registerPasswd->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(registerPasswd, 1, 2, 1, 1);

        passwd_2 = new QLabel(gridLayoutWidget);
        passwd_2->setObjectName(QStringLiteral("passwd_2"));
        passwd_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(passwd_2, 1, 1, 1, 1);

        register_button = new QPushButton(registWindow);
        register_button->setObjectName(QStringLiteral("register_button"));
        register_button->setGeometry(QRect(180, 200, 113, 32));
        register_button->setCheckable(false);
        register_button->setChecked(false);
        register_button->setAutoDefault(false);

        retranslateUi(registWindow);

        register_button->setDefault(true);


        QMetaObject::connectSlotsByName(registWindow);
    } // setupUi

    void retranslateUi(QWidget *registWindow)
    {
        registWindow->setWindowTitle(QApplication::translate("registWindow", "Register", 0));
        confirmPasswd_2->setText(QApplication::translate("registWindow", "confim passwod", 0));
        username_2->setText(QApplication::translate("registWindow", "username", 0));
        passwd_2->setText(QApplication::translate("registWindow", "password", 0));
        register_button->setText(QApplication::translate("registWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class registWindow: public Ui_registWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTWINDOW_H
