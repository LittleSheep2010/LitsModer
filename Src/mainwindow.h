#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
using namespace std;

#include <QMainWindow>
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString userLocalFolderPath_Downloads_data;
    QString userLocalFolderPath_Home_data;

    QString downloadModpackPath_data;
    QString downloadModpackName_data;

    QVector<QString> downloadModpackMode_template = {"Select Modpack type", "Curseforge", "FTB"};
    int downloadModpackModeSelected_data;

    bool modpackScanOver_data = false;

    // modpack 数据
    QString modpackInfo_author_data;
    QString modpackInfo_modpackName_data;
    QString modpackInfo_overridesFolderName_data;
    QVector<QString> modpackInfo_modlistName_data;
    QVector<QString> modpackInfo_modlistProjectID_data;
    QVector<QString> modpackInfo_modlistFileID_data;
    QVector<bool> modpackInfo_modlistRequired_data;

    QString modpackInfo_modpackVersion_data;
    int modpackInfo_modpackProjectID_data;

    QVector<QString> modpackInfo_modloderList_data;
    QVector<bool> modpackInfo_mainModloderList_data;
    QString modpackInfo_needMinecraftVersion_data;

private slots:
    void updateAll();

    void on_fileSelector_fileButton_toolButton_clicked();

    void on_fileSelector_clearFilePath_pushButton_clicked();

    void on_scanner_scan_pushButton_clicked();

    void on_fileSelector_modpackClass_comboBox_currentIndexChanged(int index);

    void on_scanner_reset_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
