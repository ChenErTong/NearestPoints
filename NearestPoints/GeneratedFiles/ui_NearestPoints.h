/********************************************************************************
** Form generated from reading UI file 'NearestPoints.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEARESTPOINTS_H
#define UI_NEARESTPOINTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NearestPointsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NearestPointsClass)
    {
        if (NearestPointsClass->objectName().isEmpty())
            NearestPointsClass->setObjectName(QStringLiteral("NearestPointsClass"));
        NearestPointsClass->resize(600, 400);
        menuBar = new QMenuBar(NearestPointsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        NearestPointsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NearestPointsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NearestPointsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NearestPointsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NearestPointsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NearestPointsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NearestPointsClass->setStatusBar(statusBar);

        retranslateUi(NearestPointsClass);

        QMetaObject::connectSlotsByName(NearestPointsClass);
    } // setupUi

    void retranslateUi(QMainWindow *NearestPointsClass)
    {
        NearestPointsClass->setWindowTitle(QApplication::translate("NearestPointsClass", "NearestPoints", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NearestPointsClass: public Ui_NearestPointsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEARESTPOINTS_H
