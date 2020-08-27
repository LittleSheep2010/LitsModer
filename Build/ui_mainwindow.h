/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *fileSelector_groupBox;
    QToolButton *fileSelector_fileButton_toolButton;
    QComboBox *fileSelector_modpackClass_comboBox;
    QLineEdit *fileSelector_filePath_lineShow;
    QPushButton *fileSelector_clearFilePath_pushButton;
    QGroupBox *scanner_groupBox;
    QPushButton *scanner_scan_pushButton;
    QPushButton *scanner_resultShow_pushButton;
    QProgressBar *scanner_completeValue_progressBar;
    QLineEdit *scanner_processingTask_lineShow;
    QPushButton *scanner_reset_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(436, 529);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        fileSelector_groupBox = new QGroupBox(centralwidget);
        fileSelector_groupBox->setObjectName(QString::fromUtf8("fileSelector_groupBox"));
        fileSelector_groupBox->setGeometry(QRect(10, 0, 411, 101));
        fileSelector_fileButton_toolButton = new QToolButton(fileSelector_groupBox);
        fileSelector_fileButton_toolButton->setObjectName(QString::fromUtf8("fileSelector_fileButton_toolButton"));
        fileSelector_fileButton_toolButton->setGeometry(QRect(370, 60, 26, 22));
        fileSelector_modpackClass_comboBox = new QComboBox(fileSelector_groupBox);
        fileSelector_modpackClass_comboBox->setObjectName(QString::fromUtf8("fileSelector_modpackClass_comboBox"));
        fileSelector_modpackClass_comboBox->setGeometry(QRect(10, 30, 261, 31));
        fileSelector_filePath_lineShow = new QLineEdit(fileSelector_groupBox);
        fileSelector_filePath_lineShow->setObjectName(QString::fromUtf8("fileSelector_filePath_lineShow"));
        fileSelector_filePath_lineShow->setGeometry(QRect(12, 60, 351, 21));
        fileSelector_filePath_lineShow->setReadOnly(true);
        fileSelector_clearFilePath_pushButton = new QPushButton(fileSelector_groupBox);
        fileSelector_clearFilePath_pushButton->setObjectName(QString::fromUtf8("fileSelector_clearFilePath_pushButton"));
        fileSelector_clearFilePath_pushButton->setGeometry(QRect(270, 30, 131, 32));
        scanner_groupBox = new QGroupBox(centralwidget);
        scanner_groupBox->setObjectName(QString::fromUtf8("scanner_groupBox"));
        scanner_groupBox->setGeometry(QRect(10, 100, 411, 111));
        scanner_scan_pushButton = new QPushButton(scanner_groupBox);
        scanner_scan_pushButton->setObjectName(QString::fromUtf8("scanner_scan_pushButton"));
        scanner_scan_pushButton->setGeometry(QRect(270, 30, 131, 32));
        scanner_resultShow_pushButton = new QPushButton(scanner_groupBox);
        scanner_resultShow_pushButton->setObjectName(QString::fromUtf8("scanner_resultShow_pushButton"));
        scanner_resultShow_pushButton->setGeometry(QRect(140, 30, 131, 32));
        scanner_completeValue_progressBar = new QProgressBar(scanner_groupBox);
        scanner_completeValue_progressBar->setObjectName(QString::fromUtf8("scanner_completeValue_progressBar"));
        scanner_completeValue_progressBar->setGeometry(QRect(17, 80, 371, 23));
        scanner_completeValue_progressBar->setValue(0);
        scanner_processingTask_lineShow = new QLineEdit(scanner_groupBox);
        scanner_processingTask_lineShow->setObjectName(QString::fromUtf8("scanner_processingTask_lineShow"));
        scanner_processingTask_lineShow->setGeometry(QRect(22, 60, 361, 21));
        scanner_processingTask_lineShow->setAlignment(Qt::AlignCenter);
        scanner_processingTask_lineShow->setReadOnly(true);
        scanner_reset_pushButton = new QPushButton(scanner_groupBox);
        scanner_reset_pushButton->setObjectName(QString::fromUtf8("scanner_reset_pushButton"));
        scanner_reset_pushButton->setGeometry(QRect(10, 30, 131, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 436, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LitsModer", nullptr));
        fileSelector_groupBox->setTitle(QCoreApplication::translate("MainWindow", "FileSelector", nullptr));
        fileSelector_fileButton_toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        fileSelector_filePath_lineShow->setPlaceholderText(QCoreApplication::translate("MainWindow", " File path", nullptr));
        fileSelector_clearFilePath_pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        scanner_groupBox->setTitle(QCoreApplication::translate("MainWindow", "Scanner", nullptr));
        scanner_scan_pushButton->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        scanner_resultShow_pushButton->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        scanner_processingTask_lineShow->setPlaceholderText(QCoreApplication::translate("MainWindow", "Processing task", nullptr));
        scanner_reset_pushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
