#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class mainMenu;
}

class mainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr);
    ~mainMenu();

private slots:
    void on_exit_clicked();

    void on_tutorial_clicked();

    void on_start_clicked();

   // void on_shop_clicked();

private:
    Ui::mainMenu *ui;
};

#endif // MAINMENU_H
