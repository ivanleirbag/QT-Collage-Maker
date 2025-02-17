#include "AddCollageImagesButton.h"
#include "ui_AddCollageImagesButton.h"

AddCollageImagesButton::AddCollageImagesButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddCollageImagesButton)
{
    ui->setupUi(this);
}

AddCollageImagesButton::~AddCollageImagesButton()
{
    delete ui;
}

QPushButton *AddCollageImagesButton::getButton()
{
    return ui->pushButton;
}
