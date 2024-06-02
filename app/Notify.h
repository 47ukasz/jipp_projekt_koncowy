#ifndef NOTIFY_H
#define NOTIFY_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Notify;
}

class Notify : public QWidget
{
    Q_OBJECT

public:
    explicit Notify(QWidget *parent = nullptr, QString text = "Tresc notatki");
    ~Notify();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::Notify *ui;
    void setPosition(QWidget * parent, int x, int y);
    void handleStyling();
};

#endif // NOTIFY_H
