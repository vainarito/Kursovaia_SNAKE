#include "soundbutton.h"

SoundButton::SoundButton(const QString &text, QWidget *parent) : QPushButton(text, parent) {
    setMouseTracking(true); // Включаем отслеживание мыши
}
bool SoundButton::soundEnabled = true;  // Инициализируйте переменную
void SoundButton::enterEvent(QEvent *event) {
    if (soundEnabled) {
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl("C:/Kursovaia_ver_3/music_snake/tic.wav"));
    player->setVolume(25);
    player->play();

    // Когда звук закончит воспроизводиться, удаляем объект QMediaPlayer
    connect(player, &QMediaPlayer::stateChanged, this, [player](QMediaPlayer::State state) {
        if (state == QMediaPlayer::StoppedState) {
            player->deleteLater();
        }
    });
}
    QPushButton::enterEvent(event);
}
