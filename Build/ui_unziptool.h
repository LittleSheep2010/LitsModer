/********************************************************************************
** Form generated from reading UI file 'unziptool.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNZIPTOOL_H
#define UI_UNZIPTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_unzipTool
{
public:
    QLabel *unzip_fileNameTitle_label;
    QGroupBox *groupBox;
    QProgressBar *unzip_unzipComplete_progressBar;
    QTextEdit *textEdit;
    QPushButton *unzip_Ok_pushButton;

    void setupUi(QDialog *unzipTool)
    {
        if (unzipTool->objectName().isEmpty())
            unzipTool->setObjectName(QString::fromUtf8("unzipTool"));
        unzipTool->resize(438, 348);
        unzip_fileNameTitle_label = new QLabel(unzipTool);
        unzip_fileNameTitle_label->setObjectName(QString::fromUtf8("unzip_fileNameTitle_label"));
        unzip_fileNameTitle_label->setGeometry(QRect(17, 20, 401, 20));
        QFont font;
        font.setPointSize(15);
        unzip_fileNameTitle_label->setFont(font);
        unzip_fileNameTitle_label->setStyleSheet(QString::fromUtf8("font-style: bold;"));
        unzip_fileNameTitle_label->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(unzipTool);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 421, 281));
        unzip_unzipComplete_progressBar = new QProgressBar(groupBox);
        unzip_unzipComplete_progressBar->setObjectName(QString::fromUtf8("unzip_unzipComplete_progressBar"));
        unzip_unzipComplete_progressBar->setGeometry(QRect(20, 250, 381, 23));
        unzip_unzipComplete_progressBar->setValue(0);
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 401, 221));
        unzip_Ok_pushButton = new QPushButton(unzipTool);
        unzip_Ok_pushButton->setObjectName(QString::fromUtf8("unzip_Ok_pushButton"));
        unzip_Ok_pushButton->setEnabled(false);
        unzip_Ok_pushButton->setGeometry(QRect(310, 310, 112, 32));

        retranslateUi(unzipTool);

        QMetaObject::connectSlotsByName(unzipTool);
    } // setupUi

    void retranslateUi(QDialog *unzipTool)
    {
        unzipTool->setWindowTitle(QCoreApplication::translate("unzipTool", "unzipTool", nullptr));
        unzip_fileNameTitle_label->setText(QCoreApplication::translate("unzipTool", "Unzipping: ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("unzipTool", "Unzip log", nullptr));
        unzip_Ok_pushButton->setText(QCoreApplication::translate("unzipTool", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class unzipTool: public Ui_unzipTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNZIPTOOL_H
