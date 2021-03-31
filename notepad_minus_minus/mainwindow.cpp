#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // Constructor of our applicztion window.
    : QMainWindow(parent)               // Parent constructor.
    , ui(new Ui::MainWindow)            // Create object of class Ui.
{
    ui->setupUi(this);                      // Set up the UI.
    this->setCentralWidget(ui->textEdit);   // Set textEdit as central widget.
                                            // textEdit now fills the application window.
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    if (currFile != "")
    {
        QFileDialog::getSaveFileName(this, "Save the stuff");
    }
    currFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currFile = filename;

    file.open(QIODevice::ReadOnly | QFile::Text);

    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
}
