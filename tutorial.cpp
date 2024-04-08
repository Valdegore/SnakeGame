#include "tutorial.h"
#include "ui_tutorial.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>
#include <QMessageBox>
#include <QStackedWidget>
#include <QStackedWidget>
#include "start.h"

Tutorial::Tutorial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tutorial)
{
    ui->setupUi(this);

}

Tutorial::~Tutorial()
{
    delete ui;
}

void Tutorial::on_exit_clicked()
{
    //Change to game window
    /*QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack)
        stack->setCurrentIndex(1);*/

    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        Start *game = new Start(stack);
        stack->addWidget(game);
        stack->setCurrentIndex(3);
    }
}


void Tutorial::on_Menu_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack)
        stack->setCurrentIndex(0);
}

