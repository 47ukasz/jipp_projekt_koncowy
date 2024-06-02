#ifndef TYPEDIALOG_H
#define TYPEDIALOG_H

#include <QDialog>

namespace Ui {
class TypeDialog;
}

class TypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TypeDialog(QWidget *parent = nullptr);
    ~TypeDialog();

    QString getInputValue() const;
    void setInputValue(const QString &newInputValue);

private slots:
    void on_addBtn_clicked();
    void on_cancelBtn_clicked();
    void on_typeInput_textChanged(const QString &arg1);

private:
    QString inputValue;
    Ui::TypeDialog *ui;
    void handleStyling();
};

#endif // TYPEDIALOG_H
