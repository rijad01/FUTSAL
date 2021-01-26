#ifndef DUGMIC_H
#define DUGMIC_H


#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    //konstruktor
    button(QString name, QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // button_H
