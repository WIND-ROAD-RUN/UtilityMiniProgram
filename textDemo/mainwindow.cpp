#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QLabel>
#include<QSpinBox>
#include<QFontComboBox>
#include<QProgressBar>
#include<QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    build_ui_statusBar();
    build_ui_toolBar();
    connect(this->spBox_fontSize,&QSpinBox::valueChanged,this,&MainWindow::on_spbox_fontsize);
    connect(this->fontCoBox_language,&QFontComboBox::currentFontChanged,this,&MainWindow::on_cobBox_font);
    connect(this->fontCoBox_language,&QFontComboBox::currentFontChanged,this,&MainWindow::on_label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::build_ui_toolBar(){
    this->spBox_fontSize=new QSpinBox(this);
    spBox_fontSize->setMaximum(50);
    spBox_fontSize->setMinimum(5);
    ui->toolBar->addWidget(spBox_fontSize);

    fontCoBox_language=new QFontComboBox(this);
    fontCoBox_language->setMinimumWidth(150);
    ui->toolBar->addWidget(fontCoBox_language);

    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actClose);

    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actLang_CN);
    actionGroup->addAction(ui->actLang_EN);
    actionGroup->setExclusive(true);
    ui->actLang_CN->setChecked(true);

    ui->actEdit_copy->setEnabled(false);
    ui->actEdit_cut->setEnabled(false);
    ui->actEdit_paste->setEnabled(false);
    ui->actEdit_undo->setEnabled(false);
    ui->actEdit_redo->setEnabled(false);
}

void MainWindow::build_ui_statusBar(){
    lable_labFile=new QLabel(this);
    lable_labFile->setMinimumWidth(150);
    lable_labFile->setText("文件名");
    ui->statusbar->addWidget(lable_labFile);

    progressBar =new QProgressBar(this);
    progressBar->setMaximumWidth(200);
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->plainTextEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    lable_info =new QLabel(this);
    lable_info->setText("选择字体名称：");
    ui->statusbar->addPermanentWidget(lable_info);
}

void MainWindow::on_cobBox_font(const QFont & font){
    QTextCharFormat textCharFormat=ui->plainTextEdit->currentCharFormat();
    textCharFormat.setFont(font);
    ui->plainTextEdit->setCurrentCharFormat(textCharFormat);
}

void MainWindow::on_spbox_fontsize(int fontsize){
    QTextCharFormat textCharFormat=ui->plainTextEdit->currentCharFormat();
    textCharFormat.setFontPointSize(fontsize);
    ui->plainTextEdit->setCurrentCharFormat(textCharFormat);
    this->progressBar->setValue(fontsize);
}

void MainWindow::on_label(const QFont & font){
    lable_info->setText("字体名称："+font.family());
}

void MainWindow::on_actEdit_clear_triggered()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_plainTextEdit_copyAvailable(bool b)
{
    ui->actEdit_copy->setEnabled(b);
    ui->actEdit_cut->setEnabled(b);
    ui->actEdit_paste->setEnabled(b);
}


void MainWindow::on_plainTextEdit_undoAvailable(bool b)
{
    ui->actEdit_undo->setEnabled(b);
    ui->actEdit_redo->setEnabled(b);
}


void MainWindow::on_plainTextEdit_selectionChanged()
{
    QTextCharFormat textCharFormat=ui->plainTextEdit->currentCharFormat();
    ui->actFont_bold->setChecked(textCharFormat.font().bold());
    ui->actFont_italic->setChecked(textCharFormat.font().bold());
    ui->actFont_underline->setChecked(textCharFormat.font().underline());

}


void MainWindow::on_actFont_bold_triggered(bool checked)
{
    QTextCharFormat tfm=ui->plainTextEdit->currentCharFormat();
    if(checked){
        tfm.setFontWeight(QFont::Bold);
    }
    else{
        tfm.setFontWeight(QFont::Normal);
    }
    ui->plainTextEdit->setCurrentCharFormat(tfm);
}




void MainWindow::on_actFont_italic_toggled(bool arg1)
{
    QTextCharFormat tfm=ui->plainTextEdit->currentCharFormat();
    tfm.setFontItalic(arg1);
    ui->plainTextEdit->setCurrentCharFormat(tfm);

}


void MainWindow::on_actFont_underline_toggled(bool arg1)
{
    QTextCharFormat tfm=ui->plainTextEdit->currentCharFormat();
    tfm.setFontUnderline(arg1);
    ui->plainTextEdit->setCurrentCharFormat(tfm);
}

