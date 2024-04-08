#ifndef SHOP_H
#define SHOP_H

#include <QWidget>

namespace Ui {
class Shop;
}

class Shop : public QWidget
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = nullptr);
    ~Shop();

private slots:
    void on_exit_clicked();

    void on_Menu_clicked();

private:
    Ui::Shop *ui;
};

#endif // SHOP_H
