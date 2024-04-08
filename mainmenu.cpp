#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>
#include <QMessageBox>
#include <QStackedWidget>
#include "start.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

mainMenu::mainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);

}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::on_exit_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Exit");
    msgBox.setText("Do you want exit the game?\t");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        QApplication::exit();
    }
}


void mainMenu::on_tutorial_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack)
        stack->setCurrentIndex(2);

}


void mainMenu::on_start_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        Start *game = new Start(stack);
        stack->addWidget(game);
        stack->setCurrentIndex(3);
    }
}


/*void mainMenu::on_shop_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack)
        stack->setCurrentIndex(1);
}*/

