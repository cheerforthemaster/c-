/********************************************************************************
** Form generated from reading UI file 'experiment_three.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENT_THREE_H
#define UI_EXPERIMENT_THREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_experiment_three
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *experiment_three)
    {
        if (experiment_three->objectName().isEmpty())
            experiment_three->setObjectName(QStringLiteral("experiment_three"));
        experiment_three->resize(400, 300);
        verticalLayout = new QVBoxLayout(experiment_three);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(experiment_three);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/windows/GeneratedFiles/OS_Windows_8_48px_1180143_easyicon.net.png")));
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(experiment_three);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/GeneratedFiles/ligthbulb_on_help_48px_1112252_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(48, 48));
        toolButton->setCheckable(true);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(experiment_three);

        QMetaObject::connectSlotsByName(experiment_three);
    } // setupUi

    void retranslateUi(QWidget *experiment_three)
    {
        experiment_three->setWindowTitle(QApplication::translate("experiment_three", "experiment_three", 0));
        label->setText(QString());
        toolButton->setText(QApplication::translate("experiment_three", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class experiment_three: public Ui_experiment_three {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENT_THREE_H
