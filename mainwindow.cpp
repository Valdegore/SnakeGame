
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"
#include "tutorial.h"
#include "shop.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    mainMenu *mainmenu = new mainMenu(this);
    Tutorial *tutorial = new Tutorial(this);
    Shop *shop = new Shop(this);
    ui->stackedWidget->addWidget(mainmenu);
    ui->stackedWidget->addWidget(shop);
    ui->stackedWidget->addWidget(tutorial);

}

MainWindow::~MainWindow()
{
    delete ui;
}
