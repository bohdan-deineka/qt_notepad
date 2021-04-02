#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findreplacedialog.h"

MainWindow::MainWindow(QWidget *parent) // Constructor of our applicztion window.
    : QMainWindow(parent)               // Parent constructor.
    , ui(new Ui::MainWindow)            // Create object of class Ui.
{
    ui->setupUi(this);                      // Set up the UI.
    this->setCentralWidget(ui->plainTextEdit);   // Set plainTextEdit as central widget.
                                                 // plainTextEdit now fills the application window.
    connect(ui->plainTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(showCursorPos()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Action when New menu option clicked.
void MainWindow::on_actionNew_triggered()
{
    currFile.clear();                       // Clear current file name.
    ui->plainTextEdit->setPlainText(QString());       // Erase the editor.
}

// Action when Open menu option clicked.
void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file"); // Trigger the "Open File..." dialog. Returns path to the chosen file.
    QFile file(filename);           // Create file object with path aquired earlier.
    currFile = filename;            // Set current file name to filepath of chosen file.

    file.open(QIODevice::ReadOnly | QFile::Text);       // Open file with read-only access and assum it is text file.

    setWindowTitle(filename);                           
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save the file"); // Trigger the "Save File..." dialog.
    QFile file(filename); // Create file object with path aquired earlier.
    currFile = filename;

    file.open(QFile::WriteOnly | QFile::Text);

    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;

    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::showCursorPos()
{
    int line = ui->plainTextEdit->textCursor().blockNumber()+1;
    int pos = ui->plainTextEdit->textCursor().columnNumber()+1;
    ui->statusbar->showMessage(QString("Ln %1, Col %2").arg(line).arg(pos));
}

void MainWindow::on_actionFind_triggered()
{
    FindReplaceDialog *dialog = new FindReplaceDialog();
    dialog->setEditor(ui->plainTextEdit);
    dialog->show();
}
