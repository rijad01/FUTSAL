#ifndef play_H
#define play_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QComboBox>

#include <QAbstractButton>

class play : public QGraphicsView
{
    Q_OBJECT
public:
    //konstruktor
    play(QWidget * parent=NULL);
    //Igra(QWidget *parent);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void displayMainMenu();
    void izadji();


    //postavljamo golmane
    QString prviObiljezen  = "Courtois";
    QString drugiObiljezen = "Navas";

    QGraphicsScene *scene;
    QGraphicsView  *airview;
    QHBoxLayout *comboLayout = new QHBoxLayout(this);
    QComboBox *combo_prvi    = new QComboBox ();
    QComboBox *combo_drugi   = new QComboBox ();

    QStringList prvi_tim    = QStringList(); //pravimo listu za prvi tim igraca
    QStringList drugi_tim   = QStringList(); //pravimo listu za drugi tim igraca


    //igraci prvi
    QStringList entrys_prvi_tim     = QStringList() //unosimo igrace u prvi tim
            << "Courtois"
            << "Luiz"
            << "Cahil"
            << "Azpilicueta"
            << "Zouma"
            << "Gabriel"
            << "Ivanović"
            << "Loftus-Cheek"
            << "Kante"
            << "Alonso"
            << "Moses"
            << "Pedro"
            << "Hazard"
            << "Morata";


    QStringList entrys_drugi_tim    = QStringList() //unosimo igrace u drugi tim
            << "Navas"
            << "Marcelo"
            << "Varane"
            << "Ramos"
            << "Danilo"
            << "Modric"
            << "Kroos"
            << "James"
            << "Bale"
            << "Benzema"
            << "Ronaldo"
            << "Isco"
            << "Casemiro"
            << "Pepe";



    //kreiramo slotove za dalje funkcionalnosti
    public slots:
        void DodajUPrviTim(QString velChange);
        void DodajUDrugiTim(QString velChange);
        void obiljeziPrviTim();
        void obiljeziDrugiTim();
        void pokreniMec();
        void slikajMec();
        void snimiPodatke();






};


#endif // PLAY_H
