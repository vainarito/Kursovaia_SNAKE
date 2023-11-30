#include "game.h"

QTimer *pauseTimer;

void GameField::changeSnakeColor(int color) {
    snakeColor = color;
}

void GameField::updateScore(int gameScore) {
    std::string authPath = "C:/Kursovaia_ver_3/auth.txt";
    std::string scorePath = "C:/Kursovaia_ver_3/snake_gamer_score.txt";

    std::ifstream authFile(authPath);
    if (!authFile) {
        // Файл auth.txt не найден или пуст, поэтому ничего не делаем
        return;
    }

    std::string line;
    std::getline(authFile, line);
    std::istringstream iss(line);
    std::vector<std::string> authData((std::istream_iterator<std::string>(iss)),
                                       std::istream_iterator<std::string>());

    if (authData.size() < 3) {
        // Недостаточно данных в auth.txt, поэтому ничего не делаем
        return;
    }

    std::string username = authData[0];
    int oldScore = std::stoi(authData[2]);
    if (gameScore > oldScore) {
        // Обновляем счет в auth.txt, если новый счет больше старого
        authData[2] = std::to_string(gameScore);
        std::ofstream outFile(authPath);
        outFile << authData[0] << " " << authData[1] << " " << authData[2] << "\n";
    }

    std::ifstream scoreFile(scorePath);
    std::vector<std::string> scoreLines;
    bool userFound = false;

    while (std::getline(scoreFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> scoreData((std::istream_iterator<std::string>(iss)),
                                            std::istream_iterator<std::string>());

        if (scoreData.size() >= 3 && scoreData[0] == username) {
            userFound = true;
            int oldScore = std::stoi(scoreData[2]);
            if (gameScore > oldScore) {
                // Обновляем счет пользователя в базе данных, если новый счет больше старого
                scoreData[2] = std::to_string(gameScore);
                line = scoreData[0] + " " + scoreData[1] + " " + scoreData[2];
            }
        }
        scoreLines.push_back(line);
    }

    // Если пользователь не найден, добавляем его данные в конец файла
    if (!userFound) {
        scoreLines.push_back(username + " " + authData[1] + " " + std::to_string(gameScore));
    }

    // Записываем обновленные данные обратно в файл
    std::ofstream outFile(scorePath);
    for (const auto &line : scoreLines) {
        outFile << line << "\n";
    }
}


GameField::GameField()
{

    setFixedSize(300, 300);
    setFocusPolicy(Qt::StrongFocus);

    m_sizeItem = 10;
    m_fieldSize = width()/m_sizeItem;
    StartNewGame();
}

void GameField::SetGameStatus()
{
    QString text;
    if(m_isPause)
    {
        m_moveSnakeTimer->stop();
        m_bonusTimer->stop();
        text = "Счёт : " + QString::number(m_score) + "\nПродолжить - ПРОБЕЛ" ;
    }
    else
    {
        m_moveSnakeTimer->start(100);
        m_bonusTimer->start(7000);
        text = "Счёт : " + QString::number(m_score) + "\nПауза - ПРОБЕЛ";
    }
    emit ChangeTextSignal(text);
}

void GameField::GameOver()
{
    updateScore(m_score);
    m_isGameOver = true;
    QString text = "Начать заново - ПРОБЕЛ\n";
    emit ChangeTextSignal(text);
    m_moveSnakeTimer->stop();
    repaint();
    delete m_snake;
    delete m_moveSnakeTimer;
    delete m_food;
    if(m_bonus!=nullptr)
    {
        delete m_bonus;
    }
}

void GameField::StartNewGame()
{
    m_isPause = false;
    m_isMoveBlocked = false;
    m_isGameOver = false;
    m_snake = new Snake();
    m_food = new SnakeFood(m_fieldSize/2, m_fieldSize/2);
    m_bonus = nullptr;

    //таймеры
    m_bonusTimeLeft = 0;
    m_moveSnakeTimer = new QTimer();
    connect(m_moveSnakeTimer, &QTimer::timeout, this, &GameField::MoveSnakeSlot); // движение
    m_bonusTimer = new QTimer(this);
    connect(m_bonusTimer, &QTimer::timeout, this, &GameField::RemoveBonus);

    m_moveSnakeTimer->start(100);
    m_score = 0;
    QString text = "Счёт : " + QString::number(m_score) + "\nПауза - ПРОБЕЛ";
    emit ChangeTextSignal(text);
}

void GameField::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QBrush gameFieldBrush(QColor(47, 79, 79), Qt::SolidPattern);
    QBrush foodBrush(QColor(247, 103, 123), Qt::SolidPattern);
    QBrush bonusBrushDown(QColor(255, 228, 181), Qt::SolidPattern);
    QBrush bonusBrushUp(QColor(123, 104, 238), Qt::SolidPattern);

    QPixmap gameFieldPixmap("C:/kursach_imege/buliga.png");
    QPainter painter;
    painter.begin(this);

    if(m_isGameOver)
    {
        painter.setPen(QColor(250,235,215));
        painter.setFont(QFont("Minecraft Ten font cyrillic", 15, 700));
        painter.drawText(QRect(0, 0, width(), height()), Qt::AlignCenter, "ИГРА ПРОИРАННА\nсчёт : " + QString::number(m_score));
        return;
    }

    //отрисовка игрового поля
    painter.setRenderHint(QPainter::Antialiasing, true);
    QBrush brush(gameFieldPixmap);
    painter.setBrush(brush);
    QRect rect(0, 0, width()-1, height()-1);
    QPainterPath path;
    path.addRoundedRect(rect, 10, 10); // Задаем радиус скругления
    painter.setClipPath(path);
    painter.drawPixmap(rect, gameFieldPixmap);

   //  отрисовка змейки
    QColor snakeColorValue; // переменная для цвета змейки
    QColor snakeColorValueHead; // переменная для цвета головы змейки



    if (color_snake == " Red") {
        snakeColorValue = QColor(192, 49, 49);
        snakeColorValueHead = QColor(137, 42, 42);
    }
    else if (color_snake == " Green") {
        snakeColorValue = QColor(32, 230, 131);
        snakeColorValueHead = QColor(25, 158, 91);
    }
    else if (color_snake == " Yellow") {
        snakeColorValue = QColor(236, 229, 34);
        snakeColorValueHead = QColor(212, 173, 45);
    }
    else if (color_snake == " Blue") {
        snakeColorValue = QColor(41, 109, 226);
        snakeColorValueHead = QColor(45, 82, 146);
    }
    else if (color_snake == " White") {
        snakeColorValue = QColor(250, 250, 250);
        snakeColorValueHead = QColor(199, 199, 199);
    }
    else
    {
         snakeColorValue = QColor(32, 230, 131);
         snakeColorValueHead = QColor(25, 158, 91);
    }

QBrush snakeBrush(snakeColorValue, Qt::SolidPattern);
QBrush snakeBrushHead(snakeColorValueHead, Qt::SolidPattern);

    painter.setBrush(snakeBrush);
    painter.setPen(QColor(50, 50, 50));
    for(int i = 0; i< m_snake->m_SnakeBody.size(); i++)
    {
        // Если это голова змейки, изменяем цвет кисти
        if(i == 0) {
            painter.setBrush(snakeBrushHead); // Замените QColor на цвет, который вы хотите использовать для головы
        } else {
            painter.setBrush(snakeBrush);
        }
        painter.drawRect(m_snake->m_SnakeBody[i]->m_x * m_sizeItem, m_snake->m_SnakeBody[i]->m_y * m_sizeItem, m_sizeItem, m_sizeItem);
    }



    //отрисовка еды
    painter.setBrush(foodBrush);
    painter.setPen(QColor(50, 50, 50));
    painter.drawEllipse(m_food->m_x * m_sizeItem, m_food->m_y * m_sizeItem, m_sizeItem, m_sizeItem);

    //отрисовка бонуса
    if(m_score!=0 && m_score%5==0 && m_bonus!=nullptr)
    {
        if(m_bonus->m_isSpeedUp)
            {
                painter.setBrush(bonusBrushUp);
            }
            else
            {
                painter.setBrush(bonusBrushDown);
            }

    painter.drawEllipse(m_bonus->m_x * m_sizeItem, m_bonus->m_y * m_sizeItem, (m_sizeItem), (m_sizeItem) );
    }
    painter.end();
    m_isMoveBlocked = false;
}



void GameField::ExitToMenu()
{
    updateScore(m_score);
    m_isGameOver = true;
    //QString text = "Начать заново - ПРОБЕЛ\n";
    //emit ChangeTextSignal(text);
    m_moveSnakeTimer->stop();

    // Очистка всех данных игры
    if(m_snake != nullptr)
    {
    delete m_snake;
    }
    if(m_moveSnakeTimer != nullptr)
    {
        delete m_moveSnakeTimer;
    }
    if(m_food != nullptr)
    {
    delete m_food;
    }
    if(m_bonus != nullptr)
    {
        delete m_bonus;
    }

    // Отправка сигнала, что пользователь хочет выйти в меню
    emit altPressed();
}




void GameField::keyPressEvent(QKeyEvent *e)
{

    if(e->key() == Qt::Key_Alt)
        {
            //emit altPressed();
            ExitToMenu();
        }

    if(e->key()==Qt::Key_Space)
    {
        if(m_isGameOver)
        {
            StartNewGame();
            return;
        }
        m_isPause = !m_isPause;
        SetGameStatus();
    }

    if(m_isMoveBlocked)
    {
        return;
    }
    if(e->key()==Qt::Key_Left && m_snake->m_snakeDirection != Snake::SnakeDirection::right)
    {
        m_snake->m_snakeDirection = Snake::SnakeDirection::left;
    }
    if(e->key()==Qt::Key_Right && m_snake->m_snakeDirection != Snake::SnakeDirection::left)
    {
        m_snake->m_snakeDirection = Snake::SnakeDirection::right;
    }
    if(e->key()==Qt::Key_Down && m_snake->m_snakeDirection != Snake::SnakeDirection::up)
    {
        m_snake->m_snakeDirection = Snake::SnakeDirection::down;
    }
    if(e->key()==Qt::Key_Up && m_snake->m_snakeDirection != Snake::SnakeDirection::down)
    {
        m_snake->m_snakeDirection = Snake::SnakeDirection::up;
    }
    m_isMoveBlocked = true;
}

void GameField::MoveSnakeSlot()
{
    ItemElements *newSnakeItem;
    if(m_snake->m_snakeDirection == Snake::SnakeDirection::right)
    {
        newSnakeItem = new ItemElements(m_snake->m_SnakeBody[0]->m_x + 1, m_snake->m_SnakeBody[0]->m_y);
    }
    else if(m_snake->m_snakeDirection == Snake::SnakeDirection::left)
    {
        newSnakeItem = new ItemElements(m_snake->m_SnakeBody[0]->m_x - 1, m_snake->m_SnakeBody[0]->m_y);
    }
    else if(m_snake->m_snakeDirection == Snake::SnakeDirection::up)
    {
        newSnakeItem = new ItemElements(m_snake->m_SnakeBody[0]->m_x, m_snake->m_SnakeBody[0]->m_y - 1);
    }
    else
    {
        newSnakeItem = new ItemElements(m_snake->m_SnakeBody[0]->m_x, m_snake->m_SnakeBody[0]->m_y + 1);
    }

    //ограничение игрового поля
    if(newSnakeItem->m_x >= m_fieldSize)
    {
        newSnakeItem->m_x = 0;
    }
    else if(newSnakeItem->m_x < 0)
    {
        newSnakeItem->m_x = m_fieldSize - 1;
    }
    if(newSnakeItem->m_y >= m_fieldSize)
    {
        newSnakeItem->m_y = 0;
    }
    else if(newSnakeItem->m_y < 0)
    {
        newSnakeItem->m_y = m_fieldSize - 1;
    }

    //проигрыш
    for(int i = 0; i<m_snake->m_SnakeBody.size(); i++)
    {
        if(newSnakeItem->m_x == m_snake->m_SnakeBody[i]->m_x && newSnakeItem->m_y == m_snake->m_SnakeBody[i]->m_y)
        {
            GameOver();
            return;
        }
    }

    //получение бонуса

    if(m_bonus != nullptr && newSnakeItem->m_x == m_bonus->m_x && newSnakeItem->m_y == m_bonus->m_y)
    {
        if(m_bonus->m_isSpeedUp == true)
        {
            m_moveSnakeTimer->setInterval(200);
        }
        else if(m_bonus->m_isSpeedUp == false)
        {
            m_moveSnakeTimer->setInterval(50);
        }

    m_score++;
    QString  text = "Счёт : " + QString::number(m_score) + "\nПауза - ПРОБЕЛ";
    emit ChangeTextSignal(text);

    m_bonusTimeLeft += 10000; // добавляем 10 секунд к оставшемуся времени
    delete m_bonus;
    m_bonus = nullptr;

    m_bonusTimer->stop();
    }


    // уменьшаем оставшееся время действия бонуса
    m_bonusTimeLeft -= m_moveSnakeTimer->interval();

    // проверяем, не истекло ли время действия бонуса
    if(m_bonusTimeLeft <= 0)
    {
        // возвращаем скорость змейки к нормальной
        m_moveSnakeTimer->setInterval(100);
        m_bonusTimeLeft = 0;
    }

    // создание нового бонуса, когда счет делится на 5 без остатка
    if(m_score != 0 && m_score % 5 == 0 && m_bonus == nullptr)
    {
        m_bonus->CreateBonus(m_snake, m_fieldSize, m_food, m_bonus, m_bonusTimer);
    }

    //получение еды
    if(newSnakeItem->m_x == m_food->m_x && newSnakeItem->m_y == m_food->m_y)
    {
        m_score++;
        m_food->CreateFood(m_snake, m_fieldSize);
        QString text = "Счёт : " + QString::number(m_score) + "\nПауза - ПРОБЕЛ";
        emit ChangeTextSignal(text);
    }
    else
    {
        m_snake->m_SnakeBody.removeLast();
    }
    m_snake->m_SnakeBody.insert(0, newSnakeItem);

    repaint();
}

void GameField::RemoveBonus()
{
        delete m_bonus;
        m_bonus = nullptr;
}

ItemElements::ItemElements(int x, int y)
{
    m_x = x;
    m_y = y;
}

Snake::Snake() : ItemElements(0, 0)
{
    m_SnakeBeginSize = 4;
    for(int i  = 0; i < m_SnakeBeginSize; i++)
    {
        m_SnakeBody.insert(0, new ItemElements(i, 0));
    }
    m_snakeDirection = SnakeDirection::right;
}

void SnakeFood::CreateFood(Snake* m_snake, int m_fieldSize)
{

    m_x = QRandomGenerator::global()->bounded(0, m_fieldSize - 1);
    m_y = QRandomGenerator::global()->bounded(0, m_fieldSize - 1);
    for(int i=0; i<m_snake->getBody().size();i++)
    {
        if(m_x == m_snake->getBody()[i]->m_x && m_y == m_snake->getBody()[i]->m_y )
        {
            return CreateFood(m_snake, m_fieldSize);
        }
    }
}

SnakeFood::SnakeFood(int x, int y) : ItemElements(x, y)
{
    m_x = x;
    m_y = y;
}

SnakeBonus::SnakeBonus(int x, int y, bool isSpeedUp): ItemElements(x, y)
{
    m_x = x;
    m_y = y;
    m_isSpeedUp = isSpeedUp;
}



void SnakeBonus::CreateBonus(Snake* m_snake, int m_fieldSize, SnakeFood* m_food, SnakeBonus *&m_bonus, QTimer *m_bonusTimer)
{
    int m_x = QRandomGenerator::global()->bounded(0, m_fieldSize-1);
    int m_y = QRandomGenerator::global()->bounded(0, m_fieldSize-1);
    int SpeedUp = QRandomGenerator::global()->bounded(2);
    bool SpeedUpOrDown = SpeedUp;

    for(int i= 0; i<m_snake->getBody().size();i++)
    {
        if((m_x == m_snake->getBody()[i]->m_x && m_y == m_snake->getBody()[i]->m_y)
                || (m_x == m_food->m_x && m_y == m_food->m_y))
        {
            return CreateBonus(m_snake, m_fieldSize, m_food, m_bonus, m_bonusTimer);
        }
    }
    m_bonus = new SnakeBonus(m_x, m_y, SpeedUpOrDown);
    m_bonusTimer->start(7000);
}
