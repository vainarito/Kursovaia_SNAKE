
#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H

#include <QPushButton>
#include <QMediaPlayer>

// класс для появления звуков при навелении курсора на кнопки
class SoundButton : public QPushButton
{
    Q_OBJECT

public:
    SoundButton(const QString &text, QWidget *parent = nullptr);
    static bool soundEnabled;

protected:
    void enterEvent(QEvent *event) override;
};

#endif // SOUNDBUTTON_H
