#include "mainwindow.h"
#include "generatedclass.h"

MainWindow::MainWindow(){

    setFixedSize(420, 480);

    QGroupBox *m_grpBox1 = new QGroupBox("Définition de la classe",this);
    m_grpBox1->setGeometry(10,10,400,80);

    name = new QLineEdit(this);
    motherClass = new QLineEdit(this);
    QFormLayout *layout1 = new QFormLayout;

    layout1->addRow("&Nom", name);
    layout1->addRow("Classe &mère", motherClass);

    m_grpBox1->setLayout(layout1);

    //  ------------------------------------------------------------------

    QGroupBox *m_grpBox2 = new QGroupBox("Options",this);
    m_grpBox2->setGeometry(10,100,400,150);

    protectHeader = new QCheckBox("Protéger les Header contre les inclusions multiple");
    defaultConstructor = new QCheckBox("Générer un constructeur par défaut");
    defaultDestructor = new QCheckBox("Générer un destructeur");

    QVBoxLayout *layout2 = new QVBoxLayout;

    layout2->addWidget(protectHeader);
    layout2->addWidget(defaultConstructor);
    layout2->addWidget(defaultDestructor);

    m_grpBox2->setLayout(layout2);

    //  ------------------------------------------------------------------

    addComment = new QGroupBox(tr("Ajouter des commentaires"),this);
    addComment->setGeometry(10,260,400,150);
    addComment->setCheckable(true);
    addComment->setChecked(false);

    author = new QLineEdit(this);
    creationDate = new QDateEdit(this);
    classPurpose = new QTextEdit (this);
    QFormLayout *layout3 = new QFormLayout;

    layout3->addRow("&Auteur",author);
    layout3->addRow("Da&te de création",creationDate);
    layout3->addRow("&Rôle de la classe",classPurpose);

    addComment->setLayout(layout3);

    //  ------------------------------------------------------------------

//    mainLayout = new QGridLayout;
//    generate = new QPushButton("Générer",this);
//    exit = new QPushButton("Quitter",this);
//    generate->setGeometry(200,420,100,50);
//    exit->setGeometry(310,420,100,50);

//    mainLayout->addWidget(m_grpBox1,0,0,2,4);
//    mainLayout->addWidget(m_grpBox2,2,0,2,4);
//    mainLayout->addWidget(m_grpBox3,4,0,2,4);
//    mainLayout->addWidget(generate,6,2);
//    mainLayout->addWidget(exit,6,3);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    generate = new QPushButton("Générer");
    exit = new QPushButton("Quitter");

    mainLayout->addWidget(m_grpBox1);
    mainLayout->addWidget(m_grpBox2);
    mainLayout->addWidget(addComment);
    mainLayout->addWidget(generate);
    mainLayout->addWidget(exit);

    this->setLayout(mainLayout);

    //  ------------------------------------------------------------------

    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(generate, SIGNAL(clicked()), this, SLOT(sendGeneratedCode()));

}

void MainWindow::sendGeneratedCode(){
    QString wholeText;
    QString nameUp = name->text();
    nameUp = nameUp.toUpper();

    if (name->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
        return;
    }
    if (addComment->isChecked()){
        wholeText = "/* \nAuteur: "+author->text()+"\n"
                    +"Date de création: "+creationDate->text()+"\n"
                    +"Rôle: \n"
                    +classPurpose->toPlainText()+"\n*/\n\n";
    }
    if (protectHeader->isChecked()) wholeText += "#ifndef    HEADER_"+nameUp+"_H\n"
                                            +"#define    HEADER_"+nameUp+"_H\n\n";

    wholeText += "class "+name->text();

    if (!motherClass->text().isEmpty()) wholeText +=" : public "+motherClass->text();

    wholeText +="\n{\n  public:\n\n";

    if (defaultConstructor->isChecked()) wholeText +="      "+name->text()+"();\n";
    if (defaultConstructor->isChecked()) wholeText +="      ~"+name->text()+"();\n\n";

    wholeText += "  protected:\n\n  private:\n\n}; #endif // "+nameUp+"_H";

    GeneratedClass *newClass = new GeneratedClass(wholeText,this);
    newClass->exec();
}

MainWindow::~MainWindow()
{

}
