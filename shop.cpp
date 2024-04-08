#include "shop.h"
#include "ui_shop.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>
#include <QMessageBox>
#include <QStackedWidget>

Shop::Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);

}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_exit_clicked()
{
    //Change to game window
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack)
        stack->setCurrentIndex(1);
}


void Shop::on_Menu_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack)
        stack->setCurrentIndex(1);
}

