#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>

class CustomLabel: public QLabel
{
    Q_OBJECT
public:
    CustomLabel(QWidget *parent = 0);
    
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *e);

private:
    bool _pressed;
};

#endif // CUSTOMLABEL_H
