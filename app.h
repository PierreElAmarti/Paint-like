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
#include <QFileDialog>

#include "dessin.h"

class App : public QMainWindow{
    Q_OBJECT
public:
    App(QWidget *parent=nullptr);
    ~App();
    void createMenus();
};
