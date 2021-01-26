#include "button.h"
#include <QBrush>

button::button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //nacrtati kvadrat
    setRect(0,0,200,80); // Izmjena
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    // unosimo text u button
    text=new QGraphicsTextItem(name, this);
    int xPos=rect().width()/2 -text->boundingRect().width()/2;  //pozicija button po x osi
    int yPos=rect().height()/2-text->boundingRect().height()/2; //pozicija button po y osi
    text->setPos(xPos,yPos); //pozicija texta unutar button

    setAcceptHoverEvents(true);

}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event) //sta ce se desiti kad kliknemo na button
{
    emit clicked();
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) //sta ce se desit kad predjemo misom preko button
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) //sta ce se desiti nakon sto "napustimo" dati button
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}











