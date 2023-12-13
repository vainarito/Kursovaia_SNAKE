
#ifndef HELPFIELD_H
#define HELPFIELD_H

#include <QWidget>
#include <QPainter>

//класс для вспомогательного поля во время игры
class HelpField : public QWidget
{

public:
    HelpField();

private:
    QString m_text;

protected:
    void paintEvent(QPaintEvent *e) override;

public slots:
    void ChangeTextSlot(QString text);
};

#endif // HELPFIELD_H
