#ifndef BUTTON_H
#define BUTTON_H
#include  <QString> //ZAWSZE QSTRING!!! ZAPOMNI O STRING
#include <QPushButton>
#include<functional>

using namespace std;

class button : public QPushButton
{
    Q_OBJECT
public:
    button(QWidget *w = nullptr);
};



#endif // BUTTON_H
