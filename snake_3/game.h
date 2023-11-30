
#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <QWidget>
#include <QPainter>
#include <QList>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPropertyAnimation>

class GameField;
class ItemElements;
class Snake;
class SnakeFood;
class SnakeBonus;

//класс игрового поля ==================================
class GameField : public QWidget
{

    Q_OBJECT;
public:
    GameField();
    QString color_snake;

private:
    Snake *m_snake;
    SnakeFood *m_food;
    SnakeBonus *m_bonus;

    int m_sizeItem;
    int m_fieldSize;
    int m_score;
    int m_bonusTimeLeft;
    int snakeColor = 0;
    QTimer *m_moveSnakeTimer;
    QTimer *m_bonusTimer;

    bool m_isPause;
    bool m_isMoveBlocked;
    bool m_isGameOver;

    void ExitToMenu();
    void SetGameStatus();
    void GameOver();
    void StartNewGame();
    void GameOverAndGoInMenu();
    void updateScore(int gameScore);
protected:
    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;

private slots:
    void MoveSnakeSlot();
    void RemoveBonus();

signals:
    void ChangeTextSignal(QString text);
    void altPressed();

public slots:
    void changeSnakeColor(int color);
};

//Класс координат для змейки ===========================
class ItemElements
{

    friend GameField;
    friend SnakeFood;
    friend SnakeBonus;
protected:
    int m_x;
    int m_y;
public:
    ItemElements(int x, int y);
};

//Класс змейки =========================================
class Snake : ItemElements
{
    friend GameField;
public:
    Snake();

private:
    QList<ItemElements*> m_SnakeBody;
    int m_SnakeBeginSize;

    enum SnakeDirection
    {
        up,
        left,
        down,
        right
    };
    SnakeDirection m_snakeDirection;

public:
    QList<ItemElements*> getBody() { return m_SnakeBody; }
};

//Класс еды для змейки =================================
class SnakeFood : public ItemElements
{
    public:
    void CreateFood(Snake* m_snake, int m_fieldSize);
    SnakeFood(int x, int y);
};

//Класс бонусов для змейки =============================
class SnakeBonus : public ItemElements
{
    friend GameField;
public:
    SnakeBonus(int x, int y, bool isSpeedUp);
    void CreateBonus(Snake* m_snake, int m_fieldSize, SnakeFood* m_food, SnakeBonus *&m_bonus, QTimer *m_bonusTimer);

private:
    bool m_isSpeedUp; // true - ускорение, false - замедление

};

#endif // GAME_H
