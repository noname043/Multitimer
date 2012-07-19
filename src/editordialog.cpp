#include "editordialog.h"
#include <QS60Style>

EditorDialog::EditorDialog(QWidget *parent):
    QDialog(parent),
    _ui(new Ui::EditorDialog),
    _okAction(new QAction(tr("Ok"), this)),
    _cancelAction(new QAction(tr("Cancel"), this))
{
    _ui->setupUi(this);

    addAction(_okAction);
    addAction(_cancelAction);
#ifndef S60V5
    _okAction->setIcon(qApp->style()->standardIcon(static_cast<QStyle::StandardPixmap>(SP_CustomToolBarDone)));
    _cancelAction->setIcon(qApp->style()->standardIcon(static_cast<QStyle::StandardPixmap>(SP_CustomToolBarBack)));
#endif
    _okAction->setSoftKeyRole(QAction::PositiveSoftKey);
    _cancelAction->setSoftKeyRole(QAction::NegativeSoftKey);

    connect(_okAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(_cancelAction, SIGNAL(triggered()), this, SLOT(reject()));
}

EditorDialog::~EditorDialog()
{
    delete _ui;
}

void EditorDialog::edit(const QString &counter)
{
    _ui->counter->setTime(QTime::fromString(counter, "hh:ss:mm.zzz"));
    setModal(true);
    show();
}
