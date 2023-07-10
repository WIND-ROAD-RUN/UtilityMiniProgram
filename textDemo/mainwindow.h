#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QSpinBox;
class QFontComboBox;
class QProgressBar;
class QActionGroup;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actEdit_clear_triggered();


    void on_plainTextEdit_copyAvailable(bool b);

    void on_plainTextEdit_undoAvailable(bool b);

    void on_plainTextEdit_selectionChanged();


    void on_actFont_bold_triggered(bool checked);


    void on_actFont_italic_toggled(bool arg1);

    void on_actFont_underline_toggled(bool arg1);

    void on_spbox_fontsize(int fontsize);
    void on_cobBox_font(const QFont & font);
    void on_label(const QFont & font);

private:
    Ui::MainWindow *ui;

    QSpinBox * spBox_fontSize;
    QFontComboBox * fontCoBox_language;
    QLabel * lable_labFile;
    QProgressBar* progressBar;
    QLabel * lable_info;
    QActionGroup * actionGroup;

private:
    void build_ui_toolBar();
    void build_ui_statusBar();
};
#endif // MAINWINDOW_H
