/********************************************************************************
** Form generated from reading UI file 'selectfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTFRIEND_H
#define UI_SELECTFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectFriend
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *friendNameText;
    QPushButton *selectFriendButton;

    void setupUi(QDialog *selectFriend)
    {
        if (selectFriend->objectName().isEmpty())
            selectFriend->setObjectName(QStringLiteral("selectFriend"));
        selectFriend->resize(274, 136);
        horizontalLayoutWidget = new QWidget(selectFriend);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 241, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        friendNameText = new QLineEdit(horizontalLayoutWidget);
        friendNameText->setObjectName(QStringLiteral("friendNameText"));
        friendNameText->setInputMask(QStringLiteral(""));

        horizontalLayout->addWidget(friendNameText);

        selectFriendButton = new QPushButton(selectFriend);
        selectFriendButton->setObjectName(QStringLiteral("selectFriendButton"));
        selectFriendButton->setGeometry(QRect(60, 100, 113, 32));

        retranslateUi(selectFriend);

        QMetaObject::connectSlotsByName(selectFriend);
    } // setupUi

    void retranslateUi(QDialog *selectFriend)
    {
        selectFriend->setWindowTitle(QApplication::translate("selectFriend", "Select friend", 0));
        label->setText(QApplication::translate("selectFriend", "friend name", 0));
        friendNameText->setText(QString());
        selectFriendButton->setText(QApplication::translate("selectFriend", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class selectFriend: public Ui_selectFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTFRIEND_H
