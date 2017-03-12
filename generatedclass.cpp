#include "generatedclass.h"

GeneratedClass::GeneratedClass(QString &txt, QWidget *parent = 0) : QDialog(parent){

    resize(420, 480);

    generatedText = new QTextEdit();
    QVBoxLayout *layout = new QVBoxLayout;
    exit = new QPushButton("Fermer");

    generatedText->setCurrentFont(QFont("Courier New"));
    generatedText->setReadOnly(true);
    generatedText->setText(txt);

    layout->addWidget(generatedText);
    layout->addWidget(exit);
    setLayout(layout);

    connect(exit, SIGNAL(clicked()), this, SLOT(accept()));
}

GeneratedClass::~GeneratedClass(){

}

