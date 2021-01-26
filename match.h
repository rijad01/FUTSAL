#ifndef MEC_H
#define MEC_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QComboBox>


class match : public QGraphicsView
{
    //Q_OBJECT
public:

    //konstruktor
    match(QWidget * parent=NULL);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene *scene;
    QGraphicsView  *airview;

    QStringList prvi_tim  = QStringList(); //deklaracija QStringList/e u koju unosimo igrace prvog tima
    QStringList drugi_tim = QStringList(); //deklaracija QStringList/e u koju unosimo igrace drugog tima

    void displayMainMenu(QStringList prvi_tim, QStringList drugi_tim);
    int stvaranje_Golova_PrviTim(int koordX, int koordY); //golovi za prvi tim
    int stvaranje_Golova_DrugiTim(int koordX, int koordY); //golovi za drugi tim
    int getRandomNo(int low, int high); //uzima random brojeve za golove, min-max
    void izadji(); //izlaz iz funkcije

    int brojac_Golova_PrviTim = 0;  //broji primljene golove za prvu ekipu
    int brojac_Golova_DrugiTim = 0; //broji primljene golove za drugu ekipu
};

#endif // MEC_H
