#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menuBar = new QMenuBar();
    QMenu *fileMenu = menuBar->addMenu("&File");
    QAction *exitAction = fileMenu->addAction("E&xit");

    exitAction->setShortcut(QKeySequence("Ctrl+q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    //    here is nothing showed on OSX because  File->Exit collapses with System menu, it's automatically hiden
    setMenuBar(menuBar);

//    a way to write with conveniece function, again, nothing showed because it's taken by OS X System
    menuBar->addMenu("&Help")->addAction("&About", this, SLOT(showAboutBox()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::showAboutBox()
{
    QMessageBox::information(this, "About Hello GL", "Written by 1337 H4Xx0r!");
}
