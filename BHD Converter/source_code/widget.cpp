#include "widget.h"
#include "ui_widget.h"
#include<regex>
#include<string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pbtn_switcn_clicked()
{
    input_checked(ui->lineEdit_input->text());
    bool ok;

    long long number;

    if(ui->rbtn_BIN->isChecked()){
        number=ui->lineEdit_input->text().toLongLong(&ok,2);
    }
    else if(ui->rbtn_OCT->isChecked()){
        number=ui->lineEdit_input->text().toLongLong(&ok,8);
    }
    else if(ui->rbtn_DEC->isChecked()){
        number=ui->lineEdit_input->text().toLongLong(&ok,10);
    }
    else if(ui->rbtn_HEX->isChecked()){
        number=ui->lineEdit_input->text().toLongLong(&ok,16);
    }

    QString str;
    if(ok){
        ui->ledit_BIN->setText(formatString(str.setNum(number,2)));
        ui->ledit_OCT->setText(formatString(str.setNum(number,8)));
        ui->ledit_DEC->setText(formatString(str.setNum(number,10)));
        ui->ledit_HEX->setText(formatString(str.setNum(number,16)));
    }
}

QString & Widget::formatString(QString & str){
    QString temp=str;
    str.clear();
    for(int i=0,k=0;i<temp.size();i++){
        str.append(temp.at(i));
        k++;
        if(k==4){
            str.append(' ');
            k=0;
        }
    }
    return str;
}

void Widget::input_checked(const QString &text)
{
    std::string s=text.toStdString();
    if(ui->rbtn_BIN->isChecked()){
        std::regex pattern("^[0-1]+$");
        if(!std::regex_match(s, pattern)){
            ui->lineEdit_input->clear();
        }
    }
    else if(ui->rbtn_OCT->isChecked()){
        std::regex pattern("^[0-7]+$");
        if(!std::regex_match(s, pattern)){
            ui->lineEdit_input->clear();
        }
    }
    else if(ui->rbtn_DEC->isChecked()){
        std::regex pattern("^[0-9]+$");
        if(!std::regex_match(s, pattern)){
            ui->lineEdit_input->clear();
        }
    }
    else if(ui->rbtn_HEX->isChecked()){
        std::regex pattern("^[0-9ABCDEFabcdef]+$");
        if(!std::regex_match(s, pattern)){
            ui->lineEdit_input->clear();
        }
    }
}

void Widget::on_rbtn_BIN_clicked()
{
    input_checked(ui->lineEdit_input->text());
}


void Widget::on_rbtn_OCT_clicked()
{
    input_checked(ui->lineEdit_input->text());
}


void Widget::on_rbtn_DEC_clicked()
{
    input_checked(ui->lineEdit_input->text());
}


void Widget::on_rbtn_HEX_clicked()
{
    input_checked(ui->lineEdit_input->text());
}

