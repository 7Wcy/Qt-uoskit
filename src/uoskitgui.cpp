#include "ui_uoskitgui.h"
#include "uoskitgui.h"

UoskitGui::UoskitGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UoskitGui)
{
    ui->setupUi(this);
    this->setFixedSize(400,600);
    this->setWindowTitle("Uoskit Gui");
    ui->path_line->setPlaceholderText("Enter directory path...");

    connect(ui->clone_btn,&QPushButton::clicked,this,&UoskitGui::onCloneProject);

}

UoskitGui::~UoskitGui()
{
    delete ui;
}
