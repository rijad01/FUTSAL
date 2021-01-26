    #include "play.h"
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
    #include <QFileDialog>
    #include <QMessageBox>
    #include <QGraphicsView>
    #include <QDesktopServices>
   #include <QAbstractButton>
   #include <QTextStream>
   #include <QFile>
   #include <QPushButton>
#include <QButtonGroup>

    play::play(QWidget *parent){
        //postavljanje ekrana
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(1024,700); //velicina ekrana




        QPixmap background("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/pozadina.jpg"); //postavljamo pozadinu
        background.scaledToWidth(1024); //sirina pozadine
        background.scaledToHeight(700); //visina pozadine

        QPainter p(&background);
        QPalette palette;
        palette.setBrush(QPalette::Background, background);
        this->setPalette(palette);

        scene=new QGraphicsScene();
        scene->setSceneRect(0, 0, 1024, 700);
        setScene(scene);
        scene->setPalette(palette);


        QImage image("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/pozadina.jpg"); // Ucitavanje pozadine
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        item->setScale(1.0);
        item->setPos(-100,-200); // pozicioniranje pozadine
        scene->addItem(item);


        QImage image_grb_Chelsea("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/chelsea.png"); //postavljanje Zastave
        QGraphicsPixmapItem* grb_Chelsea = new QGraphicsPixmapItem(QPixmap::fromImage(image_grb_Chelsea));
        grb_Chelsea->setScale(0.3);  // Podesavanje Velicine grba Chelsea
        grb_Chelsea->setPos(100, 45);
        scene->addItem(grb_Chelsea);

        QImage image_grb_Real("C:/Users/Rijad/Downloads/Objektno Programiranje/Futsal/slike/real.png"); //postavljanje Zastave
        QGraphicsPixmapItem* grb_Real = new QGraphicsPixmapItem(QPixmap::fromImage(image_grb_Real));
        grb_Real->setScale(0.3);  // Podesavanje Velicine grba Real Madrida
        grb_Real->setPos(740, 45);   // Podesavanje pozicije Grba
        scene->addItem(grb_Real);

        //box u koji unosimo igrace prvog tima
        QGraphicsRectItem* item1_box = new QGraphicsRectItem(100,500,200,260);
        item1_box->setPen(Qt::NoPen);

        scene->addItem(item1_box);

        //box u koji unosimo igrace drugog tima
        QGraphicsRectItem* item2_box = new QGraphicsRectItem(760,500,200,260);
        item2_box->setPen(Qt::NoPen);

        scene->addItem(item2_box);

    }

      //metod pomocu kojeg dodajemo igrace u prvi tim
    void play::DodajUPrviTim(QString velChange){
        qDebug() << "Nova veličina: " << velChange;
        prviObiljezen   = velChange;
    }

    //metod pomocu kojeg dodajemo igrace u drugi tim
    void play::DodajUDrugiTim(QString velChange2){
        qDebug() << "Nova veličina: " << velChange2;
        drugiObiljezen   = velChange2;
    }


    QString izbrisiPolja(){
       QString vrati = "";
       for(int i = 1; i <= 6; i++){
          vrati = vrati + QString("                         \n");
       }

       return vrati;
    }



    void play::obiljeziPrviTim(){
        qDebug() << "Brišem: " << prviObiljezen;
        entrys_prvi_tim.removeOne(prviObiljezen);
        combo_prvi->update();

        if(!prvi_tim.contains(prviObiljezen)){
            if(prviObiljezen.length() > 1){
                if(prvi_tim.length() < 6){
                    prvi_tim << prviObiljezen;

                    QGraphicsTextItem* igraciPrviTim= new QGraphicsTextItem(QString(prvi_tim.join("\n")));
                    QFont titleFontPrvi("comic sans", 13);
                    igraciPrviTim->setFont(titleFontPrvi);
                    igraciPrviTim->setDefaultTextColor(Qt::white);
                    igraciPrviTim->setPos(100, 500);
                    scene->addItem(igraciPrviTim);
                }
             else
             {
                    QMessageBox msgBox;
                    msgBox.setText("Unijeli ste 6 igrača za prvi tim!");
                    msgBox.exec();
             }
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Odaberite igrača!");
                msgBox.exec();
            }
        }
        else{
            prvi_tim.removeOne(prviObiljezen);



            QGraphicsTextItem* igraciPrviTim= new QGraphicsTextItem(QString(prvi_tim.join("\n")));
            QFont titleFontPrvi("comic sans", 13);
            igraciPrviTim->setFont(titleFontPrvi);
            igraciPrviTim->setDefaultTextColor(Qt::white);
            igraciPrviTim->setPos(100, 500);



            QGraphicsRectItem* item1 = new QGraphicsRectItem(100,500,200,260);
            item1->setPen(Qt::NoPen);
            item1->setBrush(QBrush(QColor("#161616")));
            scene->addItem(item1);

            scene->addItem(igraciPrviTim);

            QMessageBox msgBox;
            msgBox.setText("Igrač postoji u timu !");
            msgBox.exec();
        }

    }

    void play::obiljeziDrugiTim(){
        qDebug() << "Brišem: " << drugiObiljezen;
        entrys_drugi_tim.removeOne(drugiObiljezen);
        combo_drugi->update();

        if(!drugi_tim.contains(drugiObiljezen)){
            if(drugiObiljezen.length() > 1){
                if(drugi_tim.length() < 6){
                    drugi_tim << drugiObiljezen;

                    QGraphicsTextItem* igraciDrugiTim= new QGraphicsTextItem(QString(drugi_tim.join("\n")));
                    QFont titleFontDrugi("comic sans", 13);
                    igraciDrugiTim->setFont(titleFontDrugi);
                    igraciDrugiTim->setDefaultTextColor(Qt::white);
                    igraciDrugiTim->setPos(760, 500);
                    scene->addItem(igraciDrugiTim);
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setText("Unijeli ste 6 igrača za drugi tim!");
                    msgBox.exec();
                }

            }
            else{
                QMessageBox msgBox;
                msgBox.setText("Odaberite igrača!");
                msgBox.exec();
            }
        }
        else{
            drugi_tim.removeOne(drugiObiljezen);

            QGraphicsTextItem* igraciDrugiTim= new QGraphicsTextItem(QString(drugi_tim.join("\n")));
            QFont titleFontDrugi("comic sans", 13);
            igraciDrugiTim->setDefaultTextColor(Qt::white);
            igraciDrugiTim->setFont(titleFontDrugi);
            igraciDrugiTim->setPos(760, 500);

            QGraphicsRectItem* item2 = new QGraphicsRectItem(760,500,200,260);
            item2->setPen(Qt::NoPen);
            item2->setBrush(QBrush(QColor("#161616")));
            scene->addItem(item2);

            scene->addItem(igraciDrugiTim);


            QMessageBox msgBox;
            msgBox.setText("Igrač je vec odabran!");
            msgBox.exec();
        }
    }


    void play::pokreniMec(){
        if(prvi_tim.size() != 6 && drugi_tim.size() != 6){
            QMessageBox msgBox;
            msgBox.setText("Unesite 6 igrača");
            msgBox.exec();
        }
        else{
            // klasa mec
            match *mec;

            mec=new match();
            mec->show();
            mec->displayMainMenu(prvi_tim, drugi_tim);
        }
    }


    void play::displayMainMenu(){
        QGraphicsTextItem* titleText= new QGraphicsTextItem(QString("Chelsea - Real M"));
        QFont titleFont("comic sans",37);
        titleText->setFont(titleFont);
        titleText->setDefaultTextColor(Qt::white);
        int txPos=this->width()/2 - titleText->boundingRect().width()/2;
        int tyPos=90;
        titleText->setPos(txPos,tyPos);
        scene->addItem(titleText);

        button* playButton1=new button(QString("Dodaj igrača u prvi tim"));
        playButton1->setPos(100, 310);
        connect(playButton1, SIGNAL(clicked()), this, SLOT(obiljeziPrviTim()));
        scene->addItem(playButton1);

        button* playButton2=new button(QString("Dodaj igrača u drugi tim"));
        playButton2->setPos(760, 310);
        connect(playButton2, SIGNAL(clicked()), this, SLOT(obiljeziDrugiTim()));
        scene->addItem(playButton2);

        button* igrajButton=new button(QString("PLAY"));
        int ixPos=this->width()/2 - igrajButton->boundingRect().width()/2;
        int iyPos=310;
        igrajButton->setPos(ixPos,iyPos);
        connect(igrajButton, SIGNAL(clicked()), this, SLOT(pokreniMec()));
        scene->addItem(igrajButton);

        button* quitButton=new button(QString("CLOSE"));
        int qxPos=this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos=370;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
        scene->addItem(quitButton);


       //dugme za snimanje u file
       button* slikajButton = new button(QString("Slikaj"));
       int sxPos=this->width()/2 - slikajButton->boundingRect().width()/2;
       int syPos=430;
       slikajButton->setPos(sxPos,syPos);
       connect(slikajButton, SIGNAL(clicked()), this, SLOT(slikajMec()));
       scene->addItem(slikajButton);


       button* saveButton=new button(QString("Snimi postavu"));
           int fxPos=this->width()/2 - saveButton->boundingRect().width()/2;
           int fyPos=530;
           saveButton->setPos(fxPos,fyPos);
           connect(saveButton, SIGNAL(clicked()), this, SLOT(snimiPodatke()));
           scene->addItem(saveButton);


        combo_prvi->setStyleSheet("QComboBox { padding: 1px 0px 1px 3px; border: 1px solid rgb(228,228,228); border-radius: 2px; font-family: \"Helvetica Neue Med\"; font-size: 11px; }");
        combo_prvi->addItems(entrys_prvi_tim);
        combo_prvi->setGeometry(100, 270, 202, 35);
        scene->addWidget(combo_prvi);
        connect(combo_prvi,SIGNAL(currentIndexChanged(const QString&)), this, SLOT(DodajUPrviTim(const QString&)));


        combo_drugi->setStyleSheet("QComboBox { padding: 1px 0px 1px 3px; border: 1px solid rgb(228,228,228); border-radius: 2px; font-family: \"Helvetica Neue Med\"; font-size: 11px; }");
        combo_drugi->addItems(entrys_drugi_tim);
        combo_drugi->setGeometry(760, 270, 202, 35);
        scene->addWidget(combo_drugi);
        connect(combo_drugi,SIGNAL(currentIndexChanged(const QString&)), this, SLOT(DodajUDrugiTim(const QString&)));
    }

    //Metod za slikanje meca
    void play::slikajMec(){
        if(prvi_tim.size() != 6 && drugi_tim.size() != 6){
            QMessageBox msgBox;
            msgBox.setText("Niste popunili timove sa svim igračima!");
            msgBox.exec();
        }
        else{
            match *mec;

            mec=new match();
            mec->show();
            mec->displayMainMenu(prvi_tim, drugi_tim);

            QString fileName = QFileDialog::getSaveFileName(this, "Save Scene", "", "Image (*.png)");
            QPixmap pixMap = QPixmap::grabWidget(mec);
            pixMap.save(fileName);
            close();
        }
    }




    void play::snimiPodatke()
    {


            QString nazivFajla = "C:/Mali_Fudbal/snimiPodatke.txt";

            QFile file(nazivFajla);

            QStringList imena1 = entrys_prvi_tim;
            QString igrac1 = imena1[0];
            QString igrac2 = imena1[1];
            QString igrac3 = imena1[2];
            QString igrac4 = imena1[3];
            QString igrac5 = imena1[4];
            QString igrac6 = imena1[5];

            QStringList imena2 = entrys_drugi_tim;

            QString igrac7 = imena2[0];
            QString igrac8 = imena2[1];
            QString igrac9 = imena2[2];
            QString igrac10 = imena2[3];
            QString igrac11 = imena2[4];
            QString igrac12 = imena2[5];


            if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) )
            {
                QTextStream stream(&file);

                stream <<"Tim 1:" + igrac1 + "," + igrac2 + "," + igrac3 + "," + igrac4 + "," + igrac5 + "," + igrac6 + "|"  "Tim 2:"
                         + igrac7 + "," + igrac8 + "," + igrac9 + "," + igrac10 + "," + igrac11 + "," + igrac12 << endl;
                QMessageBox::information(this,"Info","Vaši podaci su  sačuvani!");
            }



            QMessageBox MessageBox;
            MessageBox.setText(tr("Želite li otvoriti vaš file?"));
            MessageBox.setWindowTitle("Info");
            QAbstractButton* otvoriFajl = MessageBox.addButton(tr("Da"), QMessageBox::YesRole);
            MessageBox.addButton(tr("Ne"), QMessageBox::NoRole);

            MessageBox.exec();

            if (MessageBox.clickedButton()==otvoriFajl) {
                QDesktopServices::openUrl(QUrl("snimiPodatke.txt", QUrl::TolerantMode));
            }

        }






    void play::mouseMoveEvent(QMouseEvent *event){
        QGraphicsView::mouseMoveEvent(event);
    }

    void play::mousePressEvent(QMouseEvent *event){
        QGraphicsView::mousePressEvent(event);
    }



