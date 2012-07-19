#include "customlabel.h"
#include <QMouseEvent>

CustomLabel::CustomLabel(QWidget *parent):
    QLabel(parent),
    _pressed(false)
{}

void CustomLabel::mousePressEvent(QMouseEvent *ev)
{
    _pressed = true;
    ev->accept();
}

void CustomLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if (_pressed)
        emit clicked();
    _pressed = false;
    ev->accept();
}

void CustomLabel::leaveEvent(QEvent *e)
{
    _pressed = false;
    e->accept();
}
