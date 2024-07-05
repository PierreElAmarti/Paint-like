#include "dessin.h"

dessin::dessin(QWidget * parent)
    :QWidget(parent), file(""), pixmap(new QPixmap(800,600)){
    this->setMinimumSize(800,600);
    QPainter painter = QPainter(pixmap);
    painter.fillRect(pixmap->rect(),Qt::white);
    painter.drawText(QPoint(300,300),tr("Load a picture to annotate it..."));
    this->update();
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
}

dessin::~dessin(){
}

void dessin::paintEvent(QPaintEvent *event){
    QPainter painter = QPainter(this);
    painter.drawPixmap(event->rect(),*pixmap);
}

void dessin::mousePressEvent(QMouseEvent *event){
    QPainter painter(pixmap);
    painter.setPen(pen);
    painter.drawPoint(event->pos());
    this->update();
    point = event->pos();
}

void dessin::mouseMoveEvent(QMouseEvent *event){
    QPainter painter(pixmap);
    painter.setPen(pen);
    painter.drawLine(point,event->pos());
    point = event->pos();
    this->update();
}

void dessin::mouseReleaseEvent(QMouseEvent *){
    point = QPoint(-1,-1);
}

void dessin::setPenColorBlack(){
    pen.setColor(Qt::black);
}

void dessin::setPenColorRed(){
    pen.setColor(Qt::red);
}

void dessin::setPenColorBlue(){
    pen.setColor(Qt::blue);
}

void dessin::setPenColorGreen(){
    pen.setColor(Qt::green);
}

void dessin::setErase(){
    delete pixmap;
    if(file == "") pixmap =new QPixmap(800,600);
    else pixmap = new QPixmap(file);
    QPainter p = QPainter(pixmap);
    if(file == "") p.fillRect(pixmap->rect(), Qt::white);
    if(file == "") p.drawText(QPoint(300,300),tr("Load a picture to annotate it..."));
    this->update();
}

void dessin::setImage(){
    file = QFileDialog::getOpenFileName(this, tr("Directory"), "/home", tr("Images (*.png *.jpg)"));
    delete pixmap;
    pixmap = new QPixmap(file);
    QPainter p = QPainter(pixmap);
    this->update();
}

void dessin::setPenWidth(int i){
    pen.setWidth(i);
}
