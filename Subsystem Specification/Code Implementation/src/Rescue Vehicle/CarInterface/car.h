#ifndef CAR_H
#define CAR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class car; }
QT_END_NAMESPACE

class car : public QMainWindow
{
    Q_OBJECT

public:
    car(QWidget *parent = nullptr);
    ~car();



private slots:

    void on_statusButton_3_clicked();

    void on_cameraButton_3_clicked();

    void on_helpButton_3_clicked();

private:
    Ui::car *ui;

};
#endif // CAR_H
