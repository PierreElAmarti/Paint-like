#include "app.h"

App::App(QWidget *parent)
    :QMainWindow(parent){
    this->setWindowTitle("Dessin");

    statusBar();


    //Déclaration des menus

    QMenuBar * file = menuBar();
    QMenuBar * edit = menuBar();

    QMenu *menufile = file->addMenu(tr("File"));
    QMenu *menuedit = edit->addMenu(tr("Edit"));
    dessin * d = new dessin();

    QAction * picture = new QAction(QString("Load a picture"),this);
    QAction * exit = new QAction(QString("Exit"),this);
    QAction * change = new QAction(QString("Change the color to .."),this);
    QAction * black = new QAction(QString("Black"),this);
    QAction * green = new QAction(QString("Green"),this);
    QAction * red = new QAction(QString("Red"),this);
    QAction * blue = new QAction(QString("Blue"),this);
    QAction * erase = new QAction(QString("Erase the annotation"),this);

    QObject::connect(picture,&QAction::triggered,d,&dessin::setImage);
    QObject::connect(exit,&QAction::triggered,this,&QWidget::close);
    QObject::connect(black,&QAction::triggered,d,&dessin::setPenColorBlack);
    QObject::connect(green,&QAction::triggered,d,&dessin::setPenColorGreen);
    QObject::connect(red,&QAction::triggered,d,&dessin::setPenColorRed);
    QObject::connect(blue,&QAction::triggered,d,&dessin::setPenColorBlue);
    QObject::connect(erase,&QAction::triggered,d,&dessin::setErase);

    picture->setStatusTip(tr("To load a picture"));
    exit->setStatusTip(tr("To exit the app"));
    change->setStatusTip(tr("To change the pen color"));
    black->setStatusTip(tr("To make the pen black"));
    green->setStatusTip(tr("To make the pen green"));
    blue->setStatusTip(tr("To make the pen blue"));
    red->setStatusTip(tr("To make the pen red"));
    erase->setStatusTip(tr("To Erase the annotation"));

    picture->setShortcut(QKeySequence(tr("Ctrl+O")));
    exit->setShortcut(QKeySequence(tr("Ctrl+Q")));

    menufile->addAction(picture);
    menufile->addSeparator();
    menufile->addAction(exit);
    menuedit->addAction(change);
    menuedit->addSeparator();
    menuedit->addAction(black);
    menuedit->addAction(red);
    menuedit->addAction(green);
    menuedit->addAction(blue);
    menuedit->addSeparator();
    menuedit->addAction(erase);


    //Déclaration de la barre d'outils

    QToolBar * toolbar = addToolBar(tr("ToolBar"));

    QLabel * pensize = new QLabel(tr("Size of the pen :"),this);
    QSpinBox * spinbox = new QSpinBox();
    QObject::connect(spinbox,qOverload<int>(&QSpinBox::valueChanged),d,&dessin::setPenWidth);

    spinbox->setMinimum(1);
    spinbox->setValue(3);

    toolbar->addWidget(pensize);
    toolbar->addWidget(spinbox);
    toolbar->addSeparator();
    toolbar->addAction(black);
    toolbar->addAction(red);
    toolbar->addAction(green);
    toolbar->addAction(blue);
    toolbar->addSeparator();
    toolbar->addAction(erase);


    //Déclaration de la main window


    this->setCentralWidget(d);
}

App::~App(){
}
