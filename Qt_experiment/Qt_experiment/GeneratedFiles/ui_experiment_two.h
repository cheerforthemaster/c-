/********************************************************************************
** Form generated from reading UI file 'experiment_two.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENT_TWO_H
#define UI_EXPERIMENT_TWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_experiment_two
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *experiment_two)
    {
        if (experiment_two->objectName().isEmpty())
            experiment_two->setObjectName(QStringLiteral("experiment_two"));
        experiment_two->resize(400, 300);
        horizontalLayout = new QHBoxLayout(experiment_two);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(experiment_two);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(experiment_two);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(experiment_two);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(experiment_two);

        QMetaObject::connectSlotsByName(experiment_two);
    } // setupUi

    void retranslateUi(QWidget *experiment_two)
    {
        experiment_two->setWindowTitle(QApplication::translate("experiment_two", "experiment_two", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("experiment_two", "Chinese", 0)
         << QApplication::translate("experiment_two", "English", 0)
         << QApplication::translate("experiment_two", "French", 0)
        );
        pushButton->setText(QApplication::translate("experiment_two", "\347\241\256\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("experiment_two", "\344\270\213\344\270\200\351\241\265", 0));
    } // retranslateUi

};

namespace Ui {
    class experiment_two: public Ui_experiment_two {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENT_TWO_H
