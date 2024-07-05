#pragma once
#include <string>
#include <QWidget>
#include <QMainWindow>
#include <QEvent>
#include <QKeyEvent>
#include <QMenuBar>
#include <QMenu>
#include <QKeySequence>
#include <QAction>
#include <QToolBar>
#include <QLabel>
#include <QSpinBox>
#include <QPixmap>
#include <QPen>
#include <QColor>
#include <QPoint>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QFileDialog>

class dessin : public QWidget{
    Q_OBJECT
public:
    dessin(QWidget *parent = nullptr);
    ~dessin();
    void paintEvent(QPaintEvent * event) override;
    void dessine();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
public slots:
    void setPenColorBlack();
    void setPenColorRed();
    void setPenColorBlue();
    void setPenColorGreen();
    void setPenWidth(int i);
    void setErase();
    void setImage();
private:
    QString file;
    QPoint point;
    bool press;
    QPen pen;
    QPixmap * pixmap;
};
