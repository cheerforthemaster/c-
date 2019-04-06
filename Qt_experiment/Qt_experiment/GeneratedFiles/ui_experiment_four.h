/********************************************************************************
** Form generated from reading UI file 'experiment_four.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENT_FOUR_H
#define UI_EXPERIMENT_FOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_experiment_four
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *BtnOpen;
    QPushButton *BtnSave;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *experiment_four)
    {
        if (experiment_four->objectName().isEmpty())
            experiment_four->setObjectName(QStringLiteral("experiment_four"));
        experiment_four->resize(565, 344);
        verticalLayout = new QVBoxLayout(experiment_four);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BtnOpen = new QPushButton(experiment_four);
        BtnOpen->setObjectName(QStringLiteral("BtnOpen"));

        horizontalLayout->addWidget(BtnOpen);

        BtnSave = new QPushButton(experiment_four);
        BtnSave->setObjectName(QStringLiteral("BtnSave"));

        horizontalLayout->addWidget(BtnSave);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(experiment_four);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(experiment_four);

        QMetaObject::connectSlotsByName(experiment_four);
    } // setupUi

    void retranslateUi(QWidget *experiment_four)
    {
        experiment_four->setWindowTitle(QApplication::translate("experiment_four", "experiment_four", 0));
        BtnOpen->setText(QApplication::translate("experiment_four", "\346\211\223\345\274\200", 0));
        BtnSave->setText(QApplication::translate("experiment_four", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class experiment_four: public Ui_experiment_four {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENT_FOUR_H
