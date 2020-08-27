#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 创建计时器来更新组件
    QTimer *updateTimer = new QTimer();                                   // 新建计时器
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateAll()));     // 连接计时器时间更改的信号
    updateTimer->start(100);                                              // 启动计时器并设置一秒为 100 毫秒

    // 获取用户文件夹
    userLocalFolderPath_Downloads_data = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    userLocalFolderPath_Home_data = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    // 检查运行库 --> Start
    // 检查 awk
    qDebug(" * Start check <awk>");
    QString checkResult;                                                  // 创建检查结果存储变量
    QProcess checkLibrary_process;                                        // 创建检查进程
    checkLibrary_process.start("awk -version");                           // 执行检查命令
    checkLibrary_process.waitForStarted();                                // 开始等待执行
    checkLibrary_process.waitForFinished();                               // 等待结束执行
    checkResult =                                                         // 获取输出
            QString::fromLocal8Bit(checkLibrary_process.readAllStandardOutput());
    checkResult.replace("\n", NULL);                                      // 清除换行

    // 判断
    qDebug(" * Check over, result is(%s)", checkResult.toStdString().c_str());
    if(checkResult == NULL) {
        // 发出错误 QMessageBox
        QString msg = " Cannot found <awk>\n Please install <awk>\n If you using macOS, please try:\n <brew install awk>\n ErrorCode: #021";
        QMessageBox::critical(NULL, "Error", msg, QMessageBox::Ok, QMessageBox::Ok);
        qDebug(" * Error, because <awk> is not install");                 // 输出 Debug info
        exit(1);                                                          // 退出
    }
    // 检查 unzip
    qDebug(" * Start check <unzip>");
    checkResult.clear();                                                  // 清除上一步的返回值
    checkLibrary_process.start("unzip");                                  // 执行检查命令
    checkLibrary_process.waitForStarted();                                // 开始等待执行
    checkLibrary_process.waitForFinished();                               // 等待结束执行
    checkResult =                                                         // 获取输出
            QString::fromLocal8Bit(checkLibrary_process.readAllStandardOutput());
    checkResult.replace("\n", NULL);                                      // 清除换行

    // 判断
    qDebug(" * Check over, result is(...)");
    if(checkResult == NULL) {
        // 发出错误 QMessageBox
        QString msg = " Cannot found <unzip>\n Please install <unzip>\n If you using macOS, please try:\n <brew install unzip>\n ErrorCode: #021";
        QMessageBox::critical(NULL, "Error", msg, QMessageBox::Ok, QMessageBox::Ok);
        qDebug(" * Error, because <unzip> is not install");               // 输出 Debug info
        exit(1);                                                          // 退出
    }
    // 检查运行库 --> End

    // --------------------------------------------------

    // 检查运行脚本 --> Start
    // 检查 unzipTool
    QFile *usingScript = new QFile(userLocalFolderPath_Home_data + "/.LitsModer/runingScript/unzipTool.sh");
    // 检查 unzipTool
    if(!usingScript->exists()) {
        // 复制安装 unzipTool

    }
    // 检查运行脚本 --> End

    // 检查主文件夹是否存在
    QDir mainData_dir(userLocalFolderPath_Home_data + "/.LitsModer");
    if(!mainData_dir.exists()) { qDebug(" * Create mainData dir"); QProcess::execute("mkdir " + userLocalFolderPath_Home_data + "/.LitsModer"); }

    // 固定窗口大小
    this->setFixedSize(this->width(), this->height());

    // 导入 Modpack 模式列表
    for(int i = 0; i < downloadModpackMode_template.size(); i++) {
        ui->fileSelector_modpackClass_comboBox->addItem(downloadModpackMode_template[i]);
        qDebug(" * Success add modpack download mode(%s)", downloadModpackMode_template[i].toStdString().c_str());
    }
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::updateAll() {
    // 更新组件以显示内容
    ui->fileSelector_groupBox->update();
    ui->fileSelector_modpackClass_comboBox->update();
    ui->scanner_processingTask_lineShow->update();
    ui->scanner_completeValue_progressBar->update();

    // 固定窗口大小
    this->setFixedSize(this->width(), this->height());

    // Scanner 判断
    // 关闭 Reset 和 ShowResult 按钮
    if(!modpackScanOver_data) {
        ui->scanner_resultShow_pushButton->setEnabled(false);
        ui->scanner_reset_pushButton->setEnabled(false);
    } else {
        ui->scanner_resultShow_pushButton->setEnabled(true);
        ui->scanner_reset_pushButton->setEnabled(true);

    }
}

void MainWindow::on_fileSelector_fileButton_toolButton_clicked() {
    // 创建选择文件对话框
    QFileDialog *selectorFile_Menu = new QFileDialog();
    selectorFile_Menu->setWindowTitle("Select modpack Zip");
    selectorFile_Menu->setDirectory(userLocalFolderPath_Downloads_data);
    selectorFile_Menu->setNameFilter(tr("Zip(*.zip)"));
    selectorFile_Menu->setFileMode(QFileDialog::ExistingFile);
    selectorFile_Menu->setViewMode(QFileDialog::Detail);

    // 获取选择的文件路径
    if(selectorFile_Menu->exec()) downloadModpackPath_data = selectorFile_Menu->selectedFiles()[0];

    // 返回
    if(downloadModpackPath_data == NULL)
    { qDebug() << " * Modpack is not selected."; return; }

    qDebug() << " * Modpack is selected: " << downloadModpackPath_data;
    ui->fileSelector_filePath_lineShow->setText(" " + downloadModpackPath_data);
}

void MainWindow::on_fileSelector_clearFilePath_pushButton_clicked() {
    // 清除选择的文件目录
    downloadModpackPath_data.clear();

    // 清除选中的模组包类型
    downloadModpackModeSelected_data = 0;

    // 清理 Scanner 结果
    downloadModpackName_data.clear();
    modpackScanOver_data = false;
    ui->scanner_processingTask_lineShow->setText(NULL);
    ui->scanner_completeValue_progressBar->setValue(0);


    // 输出并设置
    qDebug() << " * Modpack selected zip is be clear";

    ui->fileSelector_modpackClass_comboBox->setCurrentIndex(downloadModpackModeSelected_data);
    ui->fileSelector_filePath_lineShow->setText(downloadModpackPath_data);
}

void MainWindow::on_fileSelector_modpackClass_comboBox_currentIndexChanged(int index) {
    MainWindow::downloadModpackModeSelected_data = index;
}

void MainWindow::on_scanner_scan_pushButton_clicked() {
    modpackScanOver_data = true;

    // 检测模组包是否选中
    if(MainWindow::downloadModpackPath_data == NULL) {
        QString msg = " You not selected modpack(*.zip)\n Please selected\n Stop scan";
        QMessageBox::warning(NULL, "Modpack is not selected", msg, QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 检测模组包模式是否选中
    if(MainWindow::downloadModpackModeSelected_data == 0) {
        QString msg = " You not selected modpack mode\n Please selected\n Stop scan";
        QMessageBox::warning(NULL, "Modpack mode is not selected", msg, QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 检测不支持的模组包类型
    if(MainWindow::downloadModpackModeSelected_data == 2) {
        QString msg = " LitsModer not support FTB modpack download\n Sorry\n Stop scan";
        QMessageBox::information(NULL, "Not support", msg, QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 创建缓存文件夹
    ui->scanner_processingTask_lineShow->setText("Create buffer folder");
    QProcess::execute("mkdir " + userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer");
    ui->scanner_completeValue_progressBar->setValue(5);

    // 移动文件整合包文件
    ui->scanner_processingTask_lineShow->setText("Copy modpack zip");
    QString fromFile_functionData = downloadModpackPath_data;
    QString copyDir_functionData = userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer";

    QFile fromFile_functionDir(fromFile_functionData);

    if(!fromFile_functionDir.exists()) {
        QString msg = " Cannot found you selected modpack zip\n Please reselect\n And sure file is exists.";
        QMessageBox::critical(NULL, "Error", msg, QMessageBox::Ok, QMessageBox::Ok);
        return;
    } else fromFile_functionDir.copy(copyDir_functionData);

    QProcess::execute("cp " + fromFile_functionData + " " + copyDir_functionData);
    ui->scanner_completeValue_progressBar->setValue(15);

    // 获取模组包名称
    ui->scanner_processingTask_lineShow->setText("Scanning");
    QProcess finderProcess;
    QString getResult;
    finderProcess.start("ls " + userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer");
    finderProcess.waitForStarted(); finderProcess.waitForFinished();      // 等待完成
    getResult =                                                           // 获取名字
            QString::fromLocal8Bit(finderProcess.readAllStandardOutput());
    downloadModpackName_data = getResult.replace("\n", NULL);             // 格式化
    qDebug(" * Get modpack name(%s)", downloadModpackName_data.toStdString().c_str());

    // 扫描压缩包里面的整合
    // 解压
    QProcess unzipProcess;
    unzipProcess.start("unzip " + userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer/" + downloadModpackName_data +
                       " -d " + userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer");
    unzipProcess.waitForStarted(); unzipProcess.waitForFinished();
    // 读取 Json
    QFile jsonReadingIO(userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer/manifest.json");

    // 文件不存在处理
    jsonReadingIO.open(QFile::ReadOnly);
    if(!jsonReadingIO.exists()) {
        QString msg = " Cannot found your modpack manifest file\n Please check your modpack manifest is exists\n Stop scan";
        QMessageBox::critical(NULL, "Cannot found manifest file", msg, QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 开始读取
    QByteArray jsonAllFile_functionData = jsonReadingIO.readAll();

    // 开始格式化和处理
    // 处理错误
    QJsonParseError jsonFileError_functionData;
    QJsonDocument jsonFileDocument_functionData(QJsonDocument::fromJson(jsonAllFile_functionData, &jsonFileError_functionData));

    if(jsonFileError_functionData.error != QJsonParseError::NoError) {
        QString msg = " Cannot read manifest file\n Because haves error\n Stop scan";
        QMessageBox::critical(NULL, "Cannot scan", msg, QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 处理数据
    QJsonObject jsonRootObject_functionData = jsonFileDocument_functionData.object();

    // 读取作者信息
    if(jsonRootObject_functionData.contains("author")) {
        // 读取出来
        MainWindow::modpackInfo_author_data = jsonRootObject_functionData["author"].toString();
        qDebug() << " * Modpack author is: " << modpackInfo_author_data;
    }

    // 读取模组列表
    if(jsonRootObject_functionData.contains("files")) {
        // 处理数据
        // 获取模组列表(Json) 数组(Array)
        QJsonArray modpackInfo_modlistArray_functionData = jsonRootObject_functionData.value("files").toArray();

        // 读取出来
        // 循环读取
        for(int i = 0; i < modpackInfo_modlistArray_functionData.size(); i++) {
            // 提取 subObject
            QJsonObject modpackInfo_modlistObject_functionData = modpackInfo_modlistArray_functionData[i].toObject();
            // 读取 projectID
            MainWindow::modpackInfo_modlistProjectID_data.append(QString::number(modpackInfo_modlistObject_functionData["projectID"].toInt()));
            // 读取 fileID
            MainWindow::modpackInfo_modlistFileID_data.append(QString::number(modpackInfo_modlistObject_functionData["fileID"].toInt()));
            // 读取 是否必须
            MainWindow::modpackInfo_modlistRequired_data.append(modpackInfo_modlistObject_functionData["required"].toBool());

            // Debug 输出
            qDebug(" * Modlist item added(projectID):(%s)", MainWindow::modpackInfo_modlistProjectID_data[i].toStdString().c_str());
            qDebug(" * Modlist item added(fileID):(%s)", MainWindow::modpackInfo_modlistFileID_data[i].toStdString().c_str());
            qDebug(" * Modlist item add(required):(%d)", MainWindow::modpackInfo_modlistRequired_data[i]);
        }
    }

    ui->scanner_completeValue_progressBar->setValue(95);

    // 释放缓存文件夹 | 执行两次以免诈尸
    ui->scanner_processingTask_lineShow->setText("Remove buffer folder");
    QProcess::execute("rm -r -f " + userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer");
    QProcess::execute("rm -r -f " + userLocalFolderPath_Home_data + "/.LitsModer/ScanBuffer");
    ui->scanner_completeValue_progressBar->setValue(100);
    ui->scanner_processingTask_lineShow->setText("Complete");

    // 扫描完成
    modpackScanOver_data = true;
}

void MainWindow::on_scanner_reset_pushButton_clicked() {
    downloadModpackName_data.clear();

    ui->scanner_processingTask_lineShow->setText(NULL);
    ui->scanner_completeValue_progressBar->setValue(0);

    // 清除完成
    modpackScanOver_data = false;
}
