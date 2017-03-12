#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

private:

    //  Push Button

    QPushButton *generate;
    QPushButton *exit;

    //  First grp BOX

    QLineEdit   *name;
    QLineEdit   *motherClass;

    //  Second grp BOX

    QCheckBox   *protectHeader;
    QCheckBox   *defaultConstructor;
    QCheckBox   *defaultDestructor;

    //  Third grp BOX

    QGroupBox   *addComment;
    QLineEdit   *author;
    QDateEdit   *creationDate;
    QTextEdit   *classPurpose;

public slots:
    void sendGeneratedCode();

};

#endif // MAINWINDOW_H
