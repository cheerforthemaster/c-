/********************************************************************************
** Form generated from reading UI file 'twovisit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOVISIT_H
#define UI_TWOVISIT_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_twovisit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *twovisit)
    {
        if (twovisit->objectName().isEmpty())
            twovisit->setObjectName(QStringLiteral("twovisit"));
        twovisit->resize(611, 113);
        verticalLayout = new QVBoxLayout(twovisit);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(twovisit);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(twovisit);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(twovisit);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(twovisit);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(twovisit);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(twovisit);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(twovisit);

        QMetaObject::connectSlotsByName(twovisit);
    } // setupUi

    void retranslateUi(QDialog *twovisit)
    {
        twovisit->setWindowTitle(QApplication::translate("twovisit", "twovisit", 0));
        label->setText(QApplication::translate("twovisit", "\345\211\215\345\272\217\351\201\215\345\216\206\357\274\232", 0));
        lineEdit->setPlaceholderText(QApplication::translate("twovisit", "\344\273\245\347\251\272\346\240\274\344\270\272\351\227\264\351\232\224\347\254\246", 0));
        label_2->setText(QApplication::translate("twovisit", "\344\270\255\345\272\217\351\201\215\345\216\206\357\274\232", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("twovisit", "\344\273\245\347\251\272\346\240\274\344\270\272\351\227\264\351\232\224\347\254\246", 0));
        pushButton->setText(QApplication::translate("twovisit", "\345\210\233\345\273\272", 0));
        pushButton_2->setText(QApplication::translate("twovisit", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class twovisit: public Ui_twovisit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOVISIT_H
