#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->button1->setText("123");

    //connect(ui->button1, &QPushButton::clicked, this, &MainWindow::close);

    //设置内容
    ui->lineEdit->setText("Hello World");

    //设置内容显示间隙
    ui->lineEdit->setTextMargins(15, 0, 0, 0);

    //设置内容显示方式
    //ui->lineEdit->setEchoMode(QLineEdit::Password);

    QStringList list;
    list << "hello" << "world" << "hello world" << "world hello";

    QCompleter *com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(com);

    ui->lcdNumber->display(123);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(50);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i = 0;
    i = ++i % 4;
    ui->stackedWidget->setCurrentIndex(i);
}

