#ifndef FINDREPLACEDIALOG_H
#define FINDREPLACEDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class FindReplaceDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindReplaceDialog(QWidget *parent = nullptr);

    void setEditor(QPlainTextEdit *editor){
        myEditor = editor;
    }
    QPlainTextEdit *getEditor(){
        return myEditor;
    }

private slots:
    void find();
    void replace();
    void replaceAll();
    void regexMode();

private:
    bool lastMatch = false;
    QPlainTextEdit *myEditor;

    QLabel *label;
    QLabel *replaceLabel;
    QLineEdit *lineEdit;
    QCheckBox *regexCheckBox;
    QLineEdit *replaceField;
    QCheckBox *caseCheckBox;
    QCheckBox *fromStartCheckBox;
    QCheckBox *wholeWordsCheckBox;
    QCheckBox *searchSelectionCheckBox;
    QCheckBox *backwardCheckBox;
    QDialogButtonBox *buttonBox;
    QPushButton *findButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QPushButton *moreButton;
    QWidget *extension;

    QTextCursor cursor;

};

#endif // FINDREPLACEDIALOG_H
