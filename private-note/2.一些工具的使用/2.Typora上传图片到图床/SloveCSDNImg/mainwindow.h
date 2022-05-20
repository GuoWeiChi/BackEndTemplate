#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_textEdit_src_textChanged();
    bool eventFilter(QObject *watched, QEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void solveCtrlC();

signals:
    void getCtrlC();
    void solveStr();



private:
    Ui::MainWindow *ui;

    QString originalText;
    QClipboard *clipboard;   //获取系统剪贴板指针
};

#endif // MAINWINDOW_H
