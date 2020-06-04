#ifndef HELP_H
#define HELP_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class help; }
QT_END_NAMESPACE


class help : public QMainWindow
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private:
    Ui::help *ui;
};

#endif // HELP_H
