
#include "match.h"
    #include "button.h"
    #include <stdlib.h>
    #include <QComboBox>
    #include <CQCustomCombo.h>
    #include <QDebug>
    #include <QMessageBox>
    #include <QImage>
    #include <QColor>
    #include <QFileInfo>
    #include <QTime>


    match::match(QWidget *parent){
        //postavljanjamo ekrana
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(1000, 960); //Fiksiranje prozora



        QPixmap background("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/teren.jpg"); //postavljamo sliku za teren
        background.scaledToWidth(1000);
        background.scaledToHeight(960);

        QPainter p( &background );
        QPalette palette;
        palette.setBrush(QPalette::Background, background);
        this->setPalette(palette);

        scene=new QGraphicsScene();
        scene->setSceneRect(0, 0, 600,960);
        setScene(scene);
        scene->setPalette(palette);

        QImage image("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/teren.jpg");
        setFixedSize(800,1000);

        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        item->setScale(1.0);
        item->setPos(0, 0);
        scene->addItem(item);




    }

    //metod za random brojeve, ispisuje broj golova unutar aplikacije koji su postignuti
    int match::getRandomNo(int low, int high)
    {
        return qrand() % ((high + 1) - low) + low;
    }

        int match::stvaranje_Golova_PrviTim(int koordX, int koordY){
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        const int arrayNum[15] = {0, 1, 2}; //pravimo array brojeva
        int RandIndex = getRandomNo(0, 2);  //ubacujemo randon brojeve u varijablu u rasponu od 0-4

        int postignuti_Golovi = arrayNum[RandIndex];
        qDebug() << "Broj golova: " + QString::number(postignuti_Golovi);

        int iteracija = 1;
        while(postignuti_Golovi < 3){
            int pomakniX = koordX + (iteracija*20);
            QImage slika_lopte("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/lopta.png"); // LOPTA
            QGraphicsPixmapItem* item_slika_lopte = new QGraphicsPixmapItem(QPixmap::fromImage(slika_lopte));
            item_slika_lopte->setScale(1.0);
            item_slika_lopte->setPos(pomakniX, koordY+90);
            scene->addItem(item_slika_lopte);

            postignuti_Golovi++;
            iteracija++;
            brojac_Golova_PrviTim++;
        }
        const int arrayNum2[15] = {0, 1, 2};
        int RandIndex2 = getRandomNo(0, 2);

        int asistencija = arrayNum2[RandIndex2];
        qDebug() << "Asistencija: " + QString::number(asistencija);

        int iteracija2 = 1;
        while(asistencija < 3){
            int pomakniX = koordX + (iteracija2*20);
            QImage slika_lopte("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/asis1.jpg");  // ASIS1
            QGraphicsPixmapItem* item_slika_lopte = new QGraphicsPixmapItem(QPixmap::fromImage(slika_lopte));
            item_slika_lopte->setScale(1.0);
            item_slika_lopte->setPos(pomakniX, koordY+110);
            scene->addItem(item_slika_lopte);

            asistencija++;
            iteracija2++;

        }
    }

    int match::stvaranje_Golova_DrugiTim(int koordX, int koordY){
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        const int arrayNum[15] = {0, 1, 2};
        int RandIndex = getRandomNo(0, 2);

        int postignuti_Golovi = arrayNum[RandIndex];
        qDebug() << "Broj golova: " + QString::number(postignuti_Golovi);

        int iteracija = 1;
        while(postignuti_Golovi < 3){
            int pomakniX = koordX + (iteracija*20);
            QImage slika_lopte("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/lopta.png"); // LOPTA
            QGraphicsPixmapItem* item_slika_lopte = new QGraphicsPixmapItem(QPixmap::fromImage(slika_lopte));
            item_slika_lopte->setScale(1.0);
            item_slika_lopte->setPos(pomakniX, koordY+90);
            scene->addItem(item_slika_lopte);

            postignuti_Golovi++;
            iteracija++;
            brojac_Golova_DrugiTim++;
        }


        const int arrayNum2[15] = {0, 1, 2};
        int RandIndex2 = getRandomNo(0, 2);

        int asistencija = arrayNum2[RandIndex2];
        qDebug() << "Asistencija: " + QString::number(asistencija);

        int iteracija2 = 1;
        while(asistencija < 3){
            int pomakniX = koordX + (iteracija2*20);
            QImage slika_lopte("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/asis1.jpg"); // ASIS1
            QGraphicsPixmapItem* item_slika_lopte = new QGraphicsPixmapItem(QPixmap::fromImage(slika_lopte));
            item_slika_lopte->setScale(1.0);
            item_slika_lopte->setPos(pomakniX, koordY+110);
            scene->addItem(item_slika_lopte);

            asistencija++;
            iteracija2++;

        }
    }

        void match::displayMainMenu(QStringList prvi_tim, QStringList drugi_tim){
        qDebug() << "Prvi tim igraci: " << prvi_tim.join(";;;;");
        qDebug() << "Drugi tim igraci: " << drugi_tim.join(";;;;");
        QFont FontIgraca("comic sans", 10);
        QFont FontBroja("comic sans", 16);
        FontIgraca.setBold(true);
        FontBroja.setBold(true);

        QGraphicsTextItem* PrviTimIgrac_1 = new QGraphicsTextItem(QString(prvi_tim[0])); //pravimo prvog igraca tima 1
        PrviTimIgrac_1->setFont(FontIgraca);
        PrviTimIgrac_1->setDefaultTextColor(Qt::white);

        QImage dres1("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresdomaci.png");       //dresdomaci.png.png
        QGraphicsPixmapItem* dres11 = new QGraphicsPixmapItem(QPixmap::fromImage(dres1));
        //dres11->setScale(2.0);
        dres11->setPos(245, 45);
        scene->addItem(dres11);
        QGraphicsTextItem* broj1 = new QGraphicsTextItem(QString("6"));
        broj1->setFont(FontBroja);
        broj1->setDefaultTextColor(Qt::white);
        scene->addItem(broj1);
        broj1->setPos(290,75);

        PrviTimIgrac_1->setPos(275, 50); //postavljamo poziciju igraca 1
        scene->addItem(PrviTimIgrac_1);
        stvaranje_Golova_PrviTim(275, 50); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QGraphicsTextItem* PrviTimIgrac_2 = new QGraphicsTextItem(QString(prvi_tim[1])); //pravimo drugog igraca tima 1
            PrviTimIgrac_2->setFont(FontIgraca);
            PrviTimIgrac_2->setDefaultTextColor(Qt::white);
            PrviTimIgrac_2->setPos(120, 220); //postavljamo poziciju drugog igraca
            scene->addItem(PrviTimIgrac_2);
            stvaranje_Golova_PrviTim(120, 220); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage dres2("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresdomaci.png");  //dresdomaci.png
            QGraphicsPixmapItem* dres12 = new QGraphicsPixmapItem(QPixmap::fromImage(dres2));
            //dres11->setScale(2.0);
            dres12->setPos(90, 215);
            scene->addItem(dres12);
            QGraphicsTextItem* broj2 = new QGraphicsTextItem(QString("7"));
            broj2->setFont(FontBroja);
            broj2->setDefaultTextColor(Qt::white);
            scene->addItem(broj2);
            broj2->setPos(135,245);

            QGraphicsTextItem* PrviTimIgrac_3 = new QGraphicsTextItem(QString(prvi_tim[2]));
            PrviTimIgrac_3->setFont(FontIgraca);
            PrviTimIgrac_3->setDefaultTextColor(Qt::white);
            PrviTimIgrac_3->setPos(415, 220); //postavljamo poziciju treceg igraca
            scene->addItem(PrviTimIgrac_3);
            stvaranje_Golova_PrviTim(415, 220); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage dres3("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresdomaci.png");
            QGraphicsPixmapItem* dres13 = new QGraphicsPixmapItem(QPixmap::fromImage(dres3));
            //dres11->setScale(2.0);
            dres13->setPos(390, 215);
            scene->addItem(dres13);
            QGraphicsTextItem* broj3 = new QGraphicsTextItem(QString("8"));
            broj3->setFont(FontBroja);
            broj3->setDefaultTextColor(Qt::white);
            scene->addItem(broj3);
            broj3->setPos(435,245);

            QGraphicsTextItem* PrviTimIgrac_4 = new QGraphicsTextItem(QString(prvi_tim[3]));
            PrviTimIgrac_4->setFont(FontIgraca);
            PrviTimIgrac_4->setDefaultTextColor(Qt::white);
            PrviTimIgrac_4->setPos(470, 360); //postavljamo poziciju cetvrtog igraca
            scene->addItem(PrviTimIgrac_4);
            stvaranje_Golova_PrviTim(470, 360);   //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage dres4("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresdomaci.png");   //dresdomac.png
            QGraphicsPixmapItem* dres14 = new QGraphicsPixmapItem(QPixmap::fromImage(dres4));
            //dres11->setScale(2.0);
            dres14->setPos(440, 355);
            scene->addItem(dres14);
            QGraphicsTextItem* broj4 = new QGraphicsTextItem(QString("9"));
            broj4->setFont(FontBroja);
            broj4->setDefaultTextColor(Qt::white);
            scene->addItem(broj4);
            broj4->setPos(485,385);

            QGraphicsTextItem* PrviTimIgrac_5_Fix = new QGraphicsTextItem(QString(prvi_tim[4]));
            PrviTimIgrac_5_Fix->setFont(FontIgraca);
            PrviTimIgrac_5_Fix->setDefaultTextColor(Qt::white);
            PrviTimIgrac_5_Fix->setPos(290, 370); //postavljamo poziciju petog igraca
            scene->addItem(PrviTimIgrac_5_Fix);
            stvaranje_Golova_PrviTim(290, 370);

            QImage dres5("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresdomaci.png");    //dresdomac.png
            QGraphicsPixmapItem* dres15 = new QGraphicsPixmapItem(QPixmap::fromImage(dres5));
            //dres11->setScale(2.0);
            dres15->setPos(260, 365);
            scene->addItem(dres15);
            QGraphicsTextItem* broj5 = new QGraphicsTextItem(QString("0"));
            broj5->setFont(FontBroja);
            broj5->setDefaultTextColor(Qt::white);
            scene->addItem(broj5);
            broj5->setPos(305,395);

            QGraphicsTextItem* PrviTimIgrac_6 = new QGraphicsTextItem(QString(prvi_tim[5]));
            PrviTimIgrac_6->setFont(FontIgraca);
            PrviTimIgrac_6->setDefaultTextColor(Qt::white);
            PrviTimIgrac_6->setPos(60, 350); //postavljamo poziciju sestog igraca
            scene->addItem(PrviTimIgrac_6);
            stvaranje_Golova_PrviTim(60, 350); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage dres6("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresdomaci.png");
            QGraphicsPixmapItem* dres16 = new QGraphicsPixmapItem(QPixmap::fromImage(dres6));
            //dres11->setScale(2.0);
            dres16->setPos(50, 345);
            scene->addItem(dres16);
            QGraphicsTextItem* broj6 = new QGraphicsTextItem(QString("1"));
            broj6->setFont(FontBroja);
            broj6->setDefaultTextColor(Qt::white);
            scene->addItem(broj6);
            broj6->setPos(95,385);





            // DRUGI TIM !!




            QGraphicsTextItem* DrugiTimIgrac_1 = new QGraphicsTextItem(QString(drugi_tim[0]));
            DrugiTimIgrac_1->setFont(FontIgraca);
            DrugiTimIgrac_1->setDefaultTextColor(Qt::white);
            DrugiTimIgrac_1->setPos(226, 776); // 226 776
            scene->addItem(DrugiTimIgrac_1);
            stvaranje_Golova_DrugiTim(226, 776); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage bdres1("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresgosti.png");      // dresgosti.png
            QGraphicsPixmapItem* bdres11 = new QGraphicsPixmapItem(QPixmap::fromImage(bdres1));
            //dres11->setScale(2.0);
            bdres11->setPos(216, 771);
            scene->addItem(bdres11);
            QGraphicsTextItem* bbroj1 = new QGraphicsTextItem(QString("2"));
            bbroj1->setFont(FontBroja);
            bbroj1->setDefaultTextColor(Qt::white);
            scene->addItem(bbroj1);
            bbroj1->setPos(261,801);

            QGraphicsTextItem* DrugiTimIgrac_2 = new QGraphicsTextItem(QString(drugi_tim[1]));
            DrugiTimIgrac_2->setFont(FontIgraca);
            DrugiTimIgrac_2->setDefaultTextColor(Qt::white);
            DrugiTimIgrac_2->setPos(50, 506);
            scene->addItem(DrugiTimIgrac_2);
            stvaranje_Golova_DrugiTim(50, 506); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage bdres2("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresgosti.png");     // dresgosti.png
            QGraphicsPixmapItem* bdres12 = new QGraphicsPixmapItem(QPixmap::fromImage(bdres2));
            //dres11->setScale(2.0);
            bdres12->setPos(20, 501);
            scene->addItem(bdres12);
            QGraphicsTextItem* bbroj2 = new QGraphicsTextItem(QString("3"));
            bbroj2->setFont(FontBroja);
            bbroj2->setDefaultTextColor(Qt::white);
            scene->addItem(bbroj2);
            bbroj2->setPos(65,531);

            QGraphicsTextItem* DrugiTimIgrac_3 = new QGraphicsTextItem(QString(drugi_tim[2]));
            DrugiTimIgrac_3->setFont(FontIgraca);
            DrugiTimIgrac_3->setDefaultTextColor(Qt::white);
            DrugiTimIgrac_3->setPos(470, 490);
            scene->addItem(DrugiTimIgrac_3);
            stvaranje_Golova_DrugiTim(470, 490); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage bdres3("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresgosti.png");   // dresgosti.png
            QGraphicsPixmapItem* bdres13 = new QGraphicsPixmapItem(QPixmap::fromImage(bdres3));
            //dres11->setScale(2.0);
            bdres13->setPos(440, 485);
            scene->addItem(bdres13);
            QGraphicsTextItem* bbroj3 = new QGraphicsTextItem(QString("4"));
            bbroj3->setFont(FontBroja);
            bbroj3->setDefaultTextColor(Qt::white);
            scene->addItem(bbroj3);
            bbroj3->setPos(485,515);

            QGraphicsTextItem* DrugiTimIgrac_4 = new QGraphicsTextItem(QString(drugi_tim[3]));
            DrugiTimIgrac_4->setFont(FontIgraca);
            DrugiTimIgrac_4->setDefaultTextColor(Qt::white);
            DrugiTimIgrac_4->setPos(340, 606);
            scene->addItem(DrugiTimIgrac_4);
            stvaranje_Golova_DrugiTim(340, 606); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage bdres4("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresgosti.png");     // dresgosti.png
            QGraphicsPixmapItem* bdres14 = new QGraphicsPixmapItem(QPixmap::fromImage(bdres4));
            //dres11->setScale(2.0);
            bdres14->setPos(310, 601);
            scene->addItem(bdres14);
            QGraphicsTextItem* bbroj4 = new QGraphicsTextItem(QString("5"));
            bbroj4->setFont(FontBroja);
            bbroj4->setDefaultTextColor(Qt::white);
            scene->addItem(bbroj4);
            bbroj4->setPos(355,631);

            QGraphicsTextItem* DrugiTimIgrac_5 = new QGraphicsTextItem(QString(drugi_tim[4]));
            DrugiTimIgrac_5->setFont(FontIgraca);
            DrugiTimIgrac_5->setDefaultTextColor(Qt::white);
            DrugiTimIgrac_5->setPos(147, 596);
            scene->addItem(DrugiTimIgrac_5);
            stvaranje_Golova_DrugiTim(147, 596); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage bdres5("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresgosti.png");    // dresgosti.png
            QGraphicsPixmapItem* bdres15 = new QGraphicsPixmapItem(QPixmap::fromImage(bdres5));
            //dres11->setScale(2.0);
            bdres15->setPos(120, 591);
            scene->addItem(bdres15);
            QGraphicsTextItem* bbroj5 = new QGraphicsTextItem(QString("10"));
            bbroj5->setFont(FontBroja);
            bbroj5->setDefaultTextColor(Qt::white);
            scene->addItem(bbroj5);
            bbroj5->setPos(160,621);

            QGraphicsTextItem* DrugiTimIgrac_6 = new QGraphicsTextItem(QString(drugi_tim[5]));
            DrugiTimIgrac_6->setFont(FontIgraca);
            DrugiTimIgrac_6->setDefaultTextColor(Qt::white);
            DrugiTimIgrac_6->setPos(50, 690);
            scene->addItem(DrugiTimIgrac_6);
            stvaranje_Golova_DrugiTim(50, 690); //postavljamo poziciju lopte koju smo prethodno stvorili kako bi bila pored igracca

            QImage bdres6("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/dresgosti.png");      // dresgosti.png
            QGraphicsPixmapItem* bdres16 = new QGraphicsPixmapItem(QPixmap::fromImage(bdres6));
            //dres11->setScale(2.0);
            bdres16->setPos(20, 685);
            scene->addItem(bdres16);
            QGraphicsTextItem* bbroj6 = new QGraphicsTextItem(QString("12"));
            bbroj6->setFont(FontBroja);
            bbroj6->setDefaultTextColor(Qt::white);
            scene->addItem(bbroj6);
            bbroj6->setPos(55,715);

            PrviTimIgrac_1->setZValue(10);
            PrviTimIgrac_2->setZValue(10);
            PrviTimIgrac_3->setZValue(10);
            PrviTimIgrac_4->setZValue(10);
            PrviTimIgrac_5_Fix->setZValue(10);
            PrviTimIgrac_6->setZValue(10);
            DrugiTimIgrac_1->setZValue(10);
            DrugiTimIgrac_2->setZValue(10);
            DrugiTimIgrac_3->setZValue(10);
            DrugiTimIgrac_4->setZValue(10);
            DrugiTimIgrac_5->setZValue(10);
            DrugiTimIgrac_6->setZValue(10);

            //rezultat tekme
            qDebug() << "Rezultat: "+ QString::number(brojac_Golova_PrviTim) + "-" + QString::number(brojac_Golova_DrugiTim);

            //ispisuje rezultat
            QGraphicsTextItem* titleText= new QGraphicsTextItem(QString("Rezultat: ") + QString::number(brojac_Golova_PrviTim) + "-" + QString::number(brojac_Golova_DrugiTim));
            QFont titleFont("comic sans",20);
            titleText->setFont(titleFont);
            titleText->setDefaultTextColor(Qt::white);
            titleText->setPos(14, 10);
            scene->addItem(titleText);

            //ispisuje vrijeme
            QGraphicsTextItem *titleText2= new QGraphicsTextItem(QString("Vrijeme - 21:00"));
            titleText2->setFont(titleFont);
            titleText2->setDefaultTextColor(Qt::white);
            titleText2->setPos(400, 10);
            scene->addItem(titleText2);

            //ispisuje datum
            QGraphicsTextItem *titleText3= new QGraphicsTextItem(QString("Datum - 10.09.2017"));
            titleText3->setFont(titleFont);
            titleText3->setDefaultTextColor(Qt::white);
            titleText3->setPos(350, 920);
            scene->addItem(titleText3);
        }

            void match::mouseMoveEvent(QMouseEvent *event)
            {
            QGraphicsView::mouseMoveEvent(event);

            }

            void match::mousePressEvent(QMouseEvent *event)
            {
            QGraphicsView::mousePressEvent(event);
            }



