#ifndef GENERETEDCODEWIN_H
#define GENERETEDCODEWIN_H

#include <QWidget>
#include <QTextEdit>

class GeneretedCodeWin : public QWidget
{
    Q_OBJECT

public:
    explicit GeneretedCodeWin();
    ~GeneretedCodeWin();

private:
    QFont *font;
    QTextEdit *generatedClass;

public slots:
    QString* receptionGeneratedCode(QString*);
};

#endif // GENERETEDCODEWIN_H
