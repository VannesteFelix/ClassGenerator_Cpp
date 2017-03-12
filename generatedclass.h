#ifndef GENERATEDCLASS_H
#define GENERATEDCLASS_H

#include <QtWidgets>

class GeneratedClass : public QDialog{

    public:
        GeneratedClass(QString &txt, QWidget *parent);
        ~GeneratedClass();

    private:
        QTextEdit *generatedText;
        QPushButton *exit;

};

#endif // GENERATEDCLASS_H
