#include "generetedcodewin.h"

GeneretedCodeWin::generetedCodeWin(){

    generatedClass = new QTextEdit(this);
    font = new QFont("Courier New");
    generatedClass->setCurrentFont(&font);
    generatedClass->setReadOnly(TRUE);
}

GeneretedCodeWin::~GeneretedCodeWin(){

}
