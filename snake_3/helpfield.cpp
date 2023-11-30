#include "helpfield.h"

HelpField::HelpField()
{
    setFixedSize(300, 50);
    m_text = "Счёт : 0\nПауза - ПРОБЕЛ";
}

void HelpField::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter;
    painter.begin(this);

    painter.setPen(QColor(250,235,215));
    painter.setFont(QFont("Minecraft Ten font cyrillic", 9, 50));


    painter.drawText(QRect(0, 0, width(), height()), Qt::AlignCenter, m_text);
    painter.end();
}

void HelpField::ChangeTextSlot(QString text)
{
    m_text = text;
    repaint();
}
