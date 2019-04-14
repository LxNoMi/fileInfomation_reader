#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDir>
#include<QFileInfo>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->openFileButton,SIGNAL(clicked()),this,SLOT(fileInfoSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileInfoSlot()
{
    QString fileName=QFileDialog::getOpenFileName(this,"打开文件:",QDir::homePath());
    QFileInfo fileInfo(fileName);
    //文件大小
    ui->fileSizeEdit->setText(QString::number(fileInfo.size())+"字节");
    //创建时间
    QDateTime creat=fileInfo.birthTime();
    ui->creatTimeEdit->setText(creat.toString("yyyy-MM-dd hh:mm:ss"));
    //最近访问时间
    QDateTime access=fileInfo.lastRead();
    ui->lastAccessTime->setText(access.toString("yyyy-MM-dd hh:hh:ss"));
    //判断是否目录文件
    if(fileInfo.isDir())
    {
        ui->isIssue->setText("是");
    }
    else
    {
        ui->isIssue->setText("否");
    }
}
