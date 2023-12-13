#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "soundbutton.h"
#include "game.h"
#include "helpfield.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>
#include <QWidget>
#include <QToolTip>
#include <QTextStream>
#include <QtMultimedia/QMediaPlayer>
#include <QSlider>
#include <QMediaPlayer>
#include <QGroupBox>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QCheckBox>
#include <QScrollArea>

class GameWindow;
class MainWindow;
class CustomTitleBar;
class ClickableLabel;


// кастомная панель с кнопкой свернуть
class CustomTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTitleBar(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint m_dragPosition;
};

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR)
        : QLabel(parent) {}

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent*) {
        emit clicked();
    }
};

//класс для интерфейса
class MainWindow : public QMainWindow
{
   Q_OBJECT

   public:
   MainWindow(QWidget *parent = nullptr);
      QString SNAKE_COLOR;
   ~MainWindow();


   private slots:
       void playGame();
       void enterName();
       void openSettings(QString&);
       void createRegistrationDialog();
       void createAuthorizationDialog();
       void openImageWindow();

   public slots:
       void showMainWindow();

   private:
       int snakeColor = 0;
       QMediaPlayer* player;
       GameField* m_gameField;
};

// класс для отображеня процесса игры
class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
     GameWindow(MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    MainWindow *m_mainWindow;
    GameField *m_gameField;
    HelpField *m_helpField;
    QWidget *m_centralWidget;
    QGridLayout *m_gridLayout;

public slots:
    void handleAltPressed();

};

#endif // MAINWINDOW_H
