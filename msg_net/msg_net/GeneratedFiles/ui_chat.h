/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QTextBrowser *msgRecvText;
    QTextEdit *msg_sendText;
    QPushButton *sendMsg_btn;

    void setupUi(QDialog *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(400, 444);
        msgRecvText = new QTextBrowser(chat);
        msgRecvText->setObjectName(QStringLiteral("msgRecvText"));
        msgRecvText->setGeometry(QRect(0, 0, 401, 311));
        msgRecvText->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        msgRecvText->setOverwriteMode(false);
        msg_sendText = new QTextEdit(chat);
        msg_sendText->setObjectName(QStringLiteral("msg_sendText"));
        msg_sendText->setGeometry(QRect(0, 320, 401, 71));
        sendMsg_btn = new QPushButton(chat);
        sendMsg_btn->setObjectName(QStringLiteral("sendMsg_btn"));
        sendMsg_btn->setGeometry(QRect(130, 390, 113, 32));

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QDialog *chat)
    {
        chat->setWindowTitle(QString());
        sendMsg_btn->setText(QApplication::translate("chat", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
