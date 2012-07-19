#ifndef EDITORDIALOG_H
#define EDITORDIALOG_H

#include <QDialog>
#include <QAction>
#include "ui_editordialog.h"

class EditorDialog: public QDialog
{
    Q_OBJECT
public:
    EditorDialog(QWidget *parent = 0);
    ~EditorDialog();

    QString result() const { return _ui->counter->text(); }

public slots:
    void edit(const QString &counter);

private:
    Ui::EditorDialog *_ui;
    QAction *_okAction;
    QAction *_cancelAction;
};

#endif // EDITORDIALOG_H
