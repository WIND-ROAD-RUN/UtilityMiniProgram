#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_pbtn_switcn_clicked();
    void input_checked(const QString &text);
    void on_rbtn_BIN_clicked();

    void on_rbtn_OCT_clicked();

    void on_rbtn_DEC_clicked();

    void on_rbtn_HEX_clicked();

private:
    Ui::Widget *ui;
    QString & formatString(QString & str);
};
#endif // WIDGET_H
