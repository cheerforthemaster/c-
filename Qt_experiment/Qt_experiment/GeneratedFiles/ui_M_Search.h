/********************************************************************************
** Form generated from reading UI file 'M_Search.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_SEARCH_H
#define UI_M_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_M_Search
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *M_Search)
    {
        if (M_Search->objectName().isEmpty())
            M_Search->setObjectName(QStringLiteral("M_Search"));
        M_Search->resize(377, 106);
        horizontalLayout_2 = new QHBoxLayout(M_Search);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(M_Search);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(M_Search);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(M_Search);

        QMetaObject::connectSlotsByName(M_Search);
    } // setupUi

    void retranslateUi(QWidget *M_Search)
    {
        M_Search->setWindowTitle(QApplication::translate("M_Search", "M_Search", 0));
        pushButton->setText(QApplication::translate("M_Search", "Find", 0));
    } // retranslateUi

};

namespace Ui {
    class M_Search: public Ui_M_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_SEARCH_H
