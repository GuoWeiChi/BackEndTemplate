#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QClipboard>
#include <QWidget>
#include "keypad/keymonitor.h"
#include "keypad/capturer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy( Qt::StrongFocus );

    connect( KeyCapturer::instance(), &KeyCapturer::getKey, [=](int key){
//            qDebug()<<QString::number(key);
            if(key == 67){
                emit(getCtrlC());
            }
        });


    startHook();

    connect(this,SIGNAL(getCtrlC()),this,SLOT(solveCtrlC()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//aaasdffasdfsdfsdf
void MainWindow::on_textEdit_src_textChanged()
{
    QString src = ui->textEdit_src->toPlainText();
    QString begin = "[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(";

    if(src.startsWith(begin)){
        QString dst = "";
        dst = dst + QString(src.data() + begin.length()-2);
        dst[0] = '!';
        dst[1] = '[';
        for(int i=1;i<dst.size();i++){
            if(dst[i] == ')'){
                dst[i] = ']';
                break;
            }
        }
//        if(dst[dst.size()-1] == ']'){
//            dst.left(dst.length() - 1);
//        }
        int left = dst.size();
        for(int i=dst.size() - 1;i>=0;i--){
            if(dst[i] == ']'){
                left--;
            }
            else{
                break;
            }
        }
        dst = dst.mid(0,left);
        ui->textEdit_dst->setText(dst);

        //复制到剪切板
        QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
        //QString originalText = clipboard->text();         //获取剪贴板上文本信息
        clipboard->setText(dst);                     //设置剪贴板内容</span>
    }


}


bool MainWindow::eventFilter(QObject *watched, QEvent *event){
    if(event->type() == QEvent::KeyPress){
        qDebug() << "press";
    }
    return QWidget::eventFilter(watched, event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "press";
    if(event->key() == Qt::Key_A){
        qDebug() << "pressA";
    }
    if( event ->matches( QKeySequence::Copy ) )
     {
           qDebug() << "pressCopy";
     }
     QMainWindow::keyPressEvent( event );


}

void MainWindow::solveCtrlC()
{
    qDebug() << "cccc";

    this->setFocus();
}

