#include "start.h"
#include "ui_start.h"
#include "apple.h"
#include "body.h"

#include <QDebug>
#include <QMessageBox>
#include <QStackedWidget>
#include <QString>
int Start::ile=0;

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ile=0;
    ui->setupUi(this);
    this->resize(1520,780);

    scene = new customScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0,0,1480,750);

    // Tworzenie obiektu QPixmap z pliku graficznego
    QPixmap backgroundPixmap("://assets/images/istockphoto.png");

    // Tworzenie obiektu QGraphicsPixmapItem i ustawienie obrazu
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(backgroundPixmap);

    // Ustawienie pozycji i rozmiaru obiektu tła
    backgroundItem->setPos(0, 0);
    backgroundItem->setZValue(-1);
    backgroundItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
    backgroundItem->setFlag(QGraphicsItem::ItemIsMovable, false);

    // Dodanie obiektu tła do sceny
    scene->addItem(backgroundItem);

    // tworzenie kursoru ...
    QCursor cursor = QCursor();
    ui->graphicsView->setCursor(cursor);



    snake = new Snake();
    snake->setPos(700,400);
    snake->setZValue(2);
    scene->addItem(snake);


    ui->graphicsView->setMouseTracking(true);

    body *bd = new body();
    connect(scene, &customScene::signalTargetCoordinate, snake, &Snake::slotTarget);


    timerCreateApple = new QTimer();
    connect(timerCreateApple, &QTimer::timeout, this, &Start::slotCreateApple);
    timerCreateApple->start(5);

    // podłączenie signal do znalezionego obiektu
    connect(snake, &Snake::signalCheckItem, this, &Start::slotDeleteApple);

    connect(snake, &Snake::signalkoniec1, this, &Start::slotStopGame);
    connect(snake, &Snake::signalkoniec1, snake, &Snake::slotStopGame2);
    connect(snake, &Snake::signalkoniec1, bd, &body::slotStopGame3);
}

Start::~Start()
{
    foreach (QGraphicsItem *item, body::partbody) {
        scene->removeItem(item);
        delete item;
    }
    body::partbody.clear();
    foreach (QGraphicsItem *item, apples) {
        scene->removeItem(item);
        delete item;
    }

    apples.clear();
        delete ui;
}


void Start::slotDeleteApple(QGraphicsItem *item)
{
    // działania z obiektami
    foreach (QGraphicsItem *apple, apples) {
        if(apple == item){
            scene->removeItem(apple);
            apples.removeOne(item);
            delete apple;

            body *bd = new body();
            scene->addItem(bd);
            body::partbody.append(bd);
            Start::ile=ile+1;
            ui->label_2->setText(QString::number(ile));
        }
    }
}

void Start::slotCreateApple()
{
    if (apples.isEmpty()) {
        apple *app = new apple();
        scene->addItem(app);
        app->setPos((rand() % (1440 - 100 + 1)) + 50,
                    (rand() % (710 - 100 + 1)) + 50);

        app->setZValue(-1);


        apples.append(app);


    }
}

void Start::slotStopGame(){
    timerCreateApple->stop();

    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        stack->setCurrentIndex(0);
        delete this;
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game over!");
        msgBox.setText("Your score:" + QString::number(ile));
                       msgBox.setStandardButtons(QMessageBox::Ok);
                       msgBox.exec();
       // stack->setCurrentIndex(0);

}

}

