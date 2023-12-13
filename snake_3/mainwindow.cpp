#include "mainwindow.h"


void MainWindow::playGame() {

    GameWindow *gameWindow = new GameWindow(this);
    gameWindow->show();
    close();
}

void MainWindow::enterName()
{
        // Создание нового диалогового окна
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(tr(" "));
        dialog->setWindowFlags(dialog->windowFlags() | Qt::FramelessWindowHint);
        dialog->setFixedSize(this->size());
        dialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); }");

        // Создание вертикального макета для диалогового окна
        QVBoxLayout *layout = new QVBoxLayout;

        // Создание метки для изображения и добавление ее в макет
        QLabel *imageLabel = new QLabel;
        QPixmap imagePixmap("C:/Kursovaia_ver_3/snake.png");
        imageLabel->setPixmap(imagePixmap.scaled(320, 210, Qt::KeepAspectRatio));
        layout->addWidget(imageLabel, 0, Qt::AlignCenter);

        // Создание кнопок "Регистрация" и "Авторизация" и добавление их в макет
        SoundButton *registrationButton = new SoundButton(tr("Registration"));
        registrationButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                           "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(250,235,215, 150);" "border-radius: 15px;" "}");
        layout->addWidget(registrationButton);

        SoundButton *authorizationButton = new SoundButton(tr("Authorization"));
        authorizationButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                            "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(250,235,215, 150);" "border-radius: 15px;" "}");
        layout->addWidget(authorizationButton);

        // Создание кнопки "Назад" и добавление ее в макет
        SoundButton *backButton = new SoundButton(tr("Back"));
        backButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                  "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(255,0,0, 50);" "border-radius: 15px;" "}");
        layout->addWidget(backButton);

        // Установка макета для диалогового окна
        dialog->setLayout(layout);

        // Подключение сигналов нажатия на кнопки к соответствующим слотам
        connect(backButton, &QPushButton::clicked, this, [dialog, this] {
            dialog->close();
            this->show();
        });


        connect(registrationButton, &QPushButton::clicked, this, &MainWindow::createRegistrationDialog);
        connect(authorizationButton, &QPushButton::clicked, this, [this] {
            createAuthorizationDialog();
        });


        // Создание объекта QPainterPath и добавление скругленного прямоугольника (скругление углов окна)
        QPainterPath path;
        path.addRoundedRect(dialog->frameGeometry(), 15, 15);
        dialog->setMask(path.toFillPolygon().toPolygon());

        // Выравнивание окна по тем же координатам, что и у основного окна
        int x = this->geometry().center().x() - dialog->width() / 2;
        int y = this->geometry().center().y() - dialog->height() / 2;
        dialog->move(x, y);

        // Запуск диалогового окна
        dialog->exec();
}

void MainWindow::createAuthorizationDialog()
{
    // Создание нового диалогового окна
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(tr("Authorization"));
        dialog->setWindowFlags(dialog->windowFlags() | Qt::FramelessWindowHint);
        dialog->setFixedSize(this->size());
        dialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); }");

        // Создание вертикального макета для диалогового окна
        QVBoxLayout *layout = new QVBoxLayout;

        // Создание метки для изображения и добавление ее в макет
        QLabel *imageLabel = new QLabel;
        QPixmap imagePixmap("C:/Kursovaia_ver_3/snake.png");
        imageLabel->setPixmap(imagePixmap.scaled(320, 210, Qt::KeepAspectRatio));
        layout->addWidget(imageLabel, 0, Qt::AlignCenter);


        // Создание полей для ввода ника и пароля и добавление их в макет
        QLineEdit *nickLineEdit = new QLineEdit;
        nickLineEdit->setPlaceholderText(tr("Enter your nickname"));
        nickLineEdit->setStyleSheet("QLineEdit { background-color: #232339; border-radius: 9px; color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; padding-left: 50px; }"
                                    "QLineEdit::placeholder { color: #2D2D42; }");
        layout->addWidget(nickLineEdit);

        QLineEdit *passwordLineEdit = new QLineEdit;
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLineEdit->setPlaceholderText(tr("Enter your password"));
        passwordLineEdit->setStyleSheet("QLineEdit { background-color: #232339; border-radius: 9px; color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; padding-left: 50px; }"
                                        "QLineEdit::placeholder { color: #2D2D42; }");
        layout->addWidget(passwordLineEdit);

        SoundButton *saveButton = new SoundButton(tr("Save"));
        saveButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                  "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(136,186, 99, 150);" "border-radius: 15px;" "}");
        layout->addWidget(saveButton);

        // Создание кнопок "Назад" и "Сохранить" и добавление их в макет
        SoundButton *backButton = new SoundButton(tr("Back"));
        backButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                  "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(255,0,0, 50);" "border-radius: 15px;" "}");
        layout->addWidget(backButton);

        // Установка макета для диалогового окна
        dialog->setLayout(layout);

        // Подключение сигнала нажатия на кнопку "Назад" к слоту, который закрывает диалоговое окно
        connect(backButton, &SoundButton::clicked, dialog, &QDialog::reject);

        // Подключение сигнала нажатия на кнопку "Сохранить" к слоту, который проверяет введенные данные и, если они допустимы, закрывает диалоговое окно
        connect(saveButton, &SoundButton::clicked, this, [dialog, nickLineEdit, passwordLineEdit] {
            QString nick = nickLineEdit->text();
            QString password = passwordLineEdit->text();

            // Проверка, что поля для ввода ника и пароля не пустые
            if (nick.isEmpty() || password.isEmpty()) {
                QMessageBox msgBox;
                msgBox.setWindowTitle(tr("Error"));
                msgBox.setText(tr("Nickname and password fields must not be empty."));
                msgBox.setStyleSheet("QMessageBox { background-color: rgb(45, 45, 66); border-radius: 15px; width: 200px; }"
                                     "QLabel { color: #FF0000; font: 15px 'Minecraft Ten font cyrillic'; }"
                                     "QPushButton { font: 15px 'Minecraft Ten font cyrillic'; color: #FAEBD7; padding: 15px; background-color: rgba(250,235,215, 50); border-radius: 15px; }"
                                     "QPushButton:hover { font: 15px 'Minecraft Ten font cyrillic'; color: #2d2d42; padding: 15px; background-color: rgba(250,235,215, 150); border-radius: 15px; }");
                msgBox.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);
                msgBox.exec();
                return;
            }

            QString score;  // Добавьте это поле для хранения счета

            // Проверка, что введенный ник существует и пароль совпадает
            QFile file("C:/Kursovaia_ver_3/snake_gamer_score.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                bool nickExists = false;
                QString correctPassword;

                while (!in.atEnd()) {
                    QString line = in.readLine();
                    QStringList parts = line.split(" ");
                    if (parts[0] == nick) {
                        nickExists = true;
                        correctPassword = parts[1];
                        score = parts[2];  // Сохраните счет пользователя
                        break;
                    }
                }
                file.close();

                if (!nickExists) {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle(tr("Error"));
                    msgBox.setText(tr("This nickname does not exist."));
                    msgBox.setStyleSheet("QMessageBox { background-color: rgb(45, 45, 66); border-radius: 15px; width: 200px; }"
                                         "QLabel { color: #FF0000; font: 15px 'Minecraft Ten font cyrillic'; }"
                                         "QPushButton { font: 15px 'Minecraft Ten font cyrillic'; color: #FAEBD7; padding: 15px; background-color: rgba(250,235,215, 50); border-radius: 15px; }"
                                         "QPushButton:hover { font: 15px 'Minecraft Ten font cyrillic'; color: #2d2d42; padding: 15px; background-color: rgba(250,235,215, 150); border-radius: 15px; }");
                    msgBox.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);

                    msgBox.exec();
                    return;
                }

                if (password != correctPassword) {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle(tr("Error"));
                    msgBox.setText(tr("Incorrect password."));
                    msgBox.setStyleSheet("QMessageBox { background-color: rgb(45, 45, 66); border-radius: 15px; width: 200px; }"
                                         "QLabel { color: #FF0000; font: 15px 'Minecraft Ten font cyrillic'; }"
                                         "QPushButton { font: 15px 'Minecraft Ten font cyrillic'; color: #FAEBD7; padding: 15px; background-color: rgba(250,235,215, 50); border-radius: 15px; }"
                                         "QPushButton:hover { font: 15px 'Minecraft Ten font cyrillic'; color: #2d2d42; padding: 15px; background-color: rgba(250,235,215, 150); border-radius: 15px; }");
                    msgBox.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);
                    msgBox.exec();
                    return;
                }
            }

            // Запись введенного ника и пароля в файл авторизации
            QFile authFile("C:/Kursovaia_ver_3/auth.txt");
                if (authFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&authFile);
                    out << nick << " " << password << " " << score << "\n";  // Добавьте счет в вывод
                    authFile.close();
                }

            dialog->accept();
        });

        // Создание объекта QPainterPath и добавление скругленного прямоугольника (скругление углов окна)
        QPainterPath path;
        path.addRoundedRect(dialog->frameGeometry(), 15, 15);
        dialog->setMask(path.toFillPolygon().toPolygon());

        // Выравнивание окна по тем же координатам, что и у основного окна
        int x = this->geometry().center().x() - dialog->width() / 2;
        int y = this->geometry().center().y() - dialog->height() / 2;
        dialog->move(x, y);

    // Запуск диалогового окна
    dialog->exec();
}

void MainWindow::createRegistrationDialog()
{
    // Создание нового диалогового окна
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(tr("Registration"));
        dialog->setWindowFlags(dialog->windowFlags() | Qt::FramelessWindowHint);
        dialog->setFixedSize(this->size());
        dialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); }");

        // Создание вертикального макета для диалогового окна
        QVBoxLayout *layout = new QVBoxLayout;

        // Создание метки для изображения и добавление ее в макет
        QLabel *imageLabel = new QLabel;
        QPixmap imagePixmap("C:/Kursovaia_ver_3/snake.png");
        imageLabel->setPixmap(imagePixmap.scaled(320, 210, Qt::KeepAspectRatio));
        layout->addWidget(imageLabel, 0, Qt::AlignCenter);

        // Создание полей для ввода ника и пароля и добавление их в макет
        QLineEdit *nickLineEdit = new QLineEdit;
        nickLineEdit->setPlaceholderText(tr("Enter new nickname"));
        nickLineEdit->setStyleSheet("QLineEdit { background-color: #232339; border-radius: 9px; color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; padding-left: 45px; }"
                                    "QLineEdit::placeholder { color: #2D2D42; }");
        layout->addWidget(nickLineEdit);

        QLineEdit *passwordLineEdit = new QLineEdit;
        passwordLineEdit->setPlaceholderText(tr("Enter new password"));
        passwordLineEdit->setStyleSheet("QLineEdit { background-color: #232339; border-radius: 9px; color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; padding-left: 43px; }"
                                        "QLineEdit::placeholder { color: #2D2D42; }");
        layout->addWidget(passwordLineEdit);

        SoundButton *saveButton = new SoundButton(tr("Save"));
        saveButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                  "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(136,186, 99, 150);" "border-radius: 15px;" "}");
        layout->addWidget(saveButton);


        // Создание кнопок "Назад" и "Сохранить" и добавление их в макет
        SoundButton *backButton = new SoundButton(tr("Back"));
        backButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                                  "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(255,0,0, 50);" "border-radius: 15px;" "}");
        layout->addWidget(backButton);

        // Установка макета для диалогового окна
        dialog->setLayout(layout);

        // Подключение сигнала нажатия на кнопку "Назад" к слоту, который закрывает диалоговое окно
        connect(backButton, &SoundButton::clicked, dialog, &QDialog::reject);

        // Подключение сигнала нажатия на кнопку "Сохранить" к слоту, который проверяет введенные данные и, если они допустимы, закрывает диалоговое окно
        connect(saveButton, &SoundButton::clicked, [dialog, nickLineEdit, passwordLineEdit] {
            QString nick = nickLineEdit->text();
            QString password = passwordLineEdit->text();

            // Проверка, что поля для ввода ника и пароля не пустые
            if (nick.isEmpty() || password.isEmpty()) {
                QDialog *errorDialog = new QDialog;
                errorDialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); border-radius: 15px; width: 200px; }"
                                           "QLabel { color: #FF0000; font: 15px 'Minecraft Ten font cyrillic'; }"
                                           "QPushButton { font: 15px 'Minecraft Ten font cyrillic'; color: #FAEBD7; padding: 15px; background-color: rgba(250,235,215, 50); border-radius: 15px; }"
                                           "QPushButton:hover { font: 15px 'Minecraft Ten font cyrillic'; color: #2d2d42; padding: 15px; background-color: rgba(250,235,215, 150); border-radius: 15px; }");
                errorDialog->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);

                QVBoxLayout *layout = new QVBoxLayout;
                QLabel *errorLabel = new QLabel(tr("Nickname and password fields must not be empty."));
                layout->addWidget(errorLabel);
                SoundButton *okButton = new SoundButton(tr("OK"));
                layout->addWidget(okButton);
                errorDialog->setLayout(layout);

                connect(okButton, &SoundButton::clicked, errorDialog, &QDialog::accept);

                errorDialog->exec();
                return;
                }


            if (nick.contains(" ") || password.contains(" ")) {
                QDialog *errorDialog = new QDialog;
                errorDialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); border-radius: 15px; }"
                                           "QLabel { color: #FF0000; font: 15px 'Minecraft Ten font cyrillic'; }"
                                           "QPushButton { font: 15px 'Minecraft Ten font cyrillic'; color: #FAEBD7; padding: 15px; background-color: rgba(250,235,215, 50); border-radius: 15px; }"
                                           "QPushButton:hover { font: 15px 'Minecraft Ten font cyrillic'; color: #2d2d42; padding: 15px; background-color: rgba(250,235,215, 150); border-radius: 15px; }");
                errorDialog->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);

                QVBoxLayout *layout = new QVBoxLayout;
                QLabel *errorLabel = new QLabel(tr("Nickname and password must not contain spaces."));
                layout->addWidget(errorLabel);
                SoundButton *okButton = new SoundButton(tr("OK"));
                layout->addWidget(okButton);
                errorDialog->setLayout(layout);

                connect(okButton, &SoundButton::clicked, errorDialog, &QDialog::accept);

                errorDialog->exec();
                return;
            }


            // Проверка, что введенный ник уникален
            QFile file("C:/Kursovaia_ver_3/snake_gamer_score.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    QStringList parts = line.split(" ");
                    if (parts[0] == nick) {
                        QDialog *errorDialog = new QDialog;
                        errorDialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); border-radius: 15px; width: 200px; }"
                                                   "QLabel { color: #FF0000; font: 15px 'Minecraft Ten font cyrillic'; }"
                                                   "QPushButton { font: 15px 'Minecraft Ten font cyrillic'; color: #FAEBD7; padding: 15px; background-color: rgba(250,235,215, 50); border-radius: 15px; }"
                                                   "QPushButton:hover { font: 15px 'Minecraft Ten font cyrillic'; color: #2d2d42; padding: 15px; background-color: rgba(250,235,215, 150); border-radius: 15px; }");
                        errorDialog->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);

                        QVBoxLayout *layout = new QVBoxLayout;
                        QLabel *errorLabel = new QLabel(tr("This nickname is already taken."));
                        layout->addWidget(errorLabel);
                        QPushButton *okButton = new QPushButton(tr("OK"));
                        layout->addWidget(okButton);
                        errorDialog->setLayout(layout);

                        connect(okButton, &QPushButton::clicked, errorDialog, &QDialog::accept);
                        errorDialog->exec();
                        return;
                    }
                }
                file.close();
            }



            // Запись введенного ника и пароля в файл
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                out << nick << " " << password << " " << "0" << "\n";
                file.close();
            }

            dialog->accept();
        });

        // Создание объекта QPainterPath и добавление скругленного прямоугольника (скругление углов окна)
        QPainterPath path;
        path.addRoundedRect(dialog->frameGeometry(), 15, 15);
        dialog->setMask(path.toFillPolygon().toPolygon());

        // Выравнивание окна по тем же координатам, что и у основного окна
        int x = this->geometry().center().x() - dialog->width() / 2;
        int y = this->geometry().center().y() - dialog->height() / 2;
        dialog->move(x, y);

        // Запуск диалогового окна
        dialog->exec();
}


void MainWindow::openSettings(QString& COLOR) {

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(tr("Настройки"));
    dialog->setWindowFlags(dialog->windowFlags() | Qt::FramelessWindowHint);
    dialog->setFixedSize(this->size());
    dialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); }");

    //---------------------------------------------------------------------------- настройка звука
    int tempVolumeValue = player->volume();
    int originalVolume = player->volume();
    bool tempSoundEnabled = SoundButton::soundEnabled;
    bool originalSoundEnabled = SoundButton::soundEnabled;  // Сохраните исходное состояние флажка

    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = new QLabel(tr("Settings"));
        label->setStyleSheet("QLabel { color: #232339; font: 15px 'Minecraft Ten font cyrillic'; }");
        layout->addWidget(label, 0, Qt::AlignCenter);

        // Создайте виджет для настройки звука
        QWidget *volumeWidget = new QWidget();
        volumeWidget->setStyleSheet("background-color: #232339; border-radius: 10px;"); // Установите цвет фона и закругление углов

        QVBoxLayout *volumeLayout = new QVBoxLayout;

        QLabel *volumeLabel = new QLabel(tr("music volume"));
        volumeLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 17px 'Minecraft Ten font cyrillic'; }");
        volumeLayout->addWidget(volumeLabel);

        QSlider *volumeSlider = new QSlider(Qt::Horizontal);
        volumeSlider->setRange(0, 100);
        volumeSlider->setValue(tempVolumeValue);
        volumeSlider->setStyleSheet(R"(
            QSlider::groove:horizontal {
                border: 1px solid #2D2D42;
                height: 8px;
                border-radius: 4px;
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #2D2D42, stop:1 #2D2D42);
            }
            QSlider::handle:horizontal {
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FAEBD7, stop:1 #FAEBD7);
                border: 2px solid #2D2D42;
                width: 18px;
                margin: -10px 0;
                border-radius: 9px;
            }
        )");

        volumeSlider->disconnect();
        connect(volumeSlider, &QSlider::valueChanged, this, [&](int value){
            tempVolumeValue = value;
        });

        volumeLayout->addWidget(volumeSlider);
        volumeWidget->setLayout(volumeLayout);
        layout->addWidget(volumeWidget);

    //---------------------------------------------------------------------------- настройка звука

    //---------------------------------------------------------------------------- цвета змейки
        QWidget *colorWidget = new QWidget();
        colorWidget->setStyleSheet("background-color: #232339; border-radius: 10px;");

        QVBoxLayout *colorLayout = new QVBoxLayout;

        QLabel *colorLabel = new QLabel(tr("Snake color"));
        colorLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 17px 'Minecraft Ten font cyrillic'; }");
        colorLayout->addWidget(colorLabel);




        QComboBox *colorComboBox = new QComboBox;
        colorComboBox->addItem(" Green");
        colorComboBox->addItem(" Red");
        colorComboBox->addItem(" Yellow");
        colorComboBox->addItem(" Blue");
        colorComboBox->addItem(" White");


        //настройка отображения цвета в меню настроек
        int index = colorComboBox->findText(COLOR);
        if (index != -1) {
            colorComboBox->setCurrentIndex(index);
        }


        QPalette palette = colorComboBox->palette();
        palette.setColor(QPalette::ButtonText, QColor("#FAEBD7"));
        colorComboBox->setPalette(palette);


        colorComboBox->setItemDelegate(new QStyledItemDelegate(colorComboBox));

        colorComboBox->setStyleSheet(R"(
            QComboBox {
                font: 15px 'Minecraft Ten font cyrillic';
                color: #FAEBD7;
                background-color: rgb(45,45,66);
            }

            QComboBox QAbstractItemView {
                font: 15px 'Minecraft Ten font cyrillic';
                color: #FAEBD7;
                background-color: rgb(45,45,66);
                selection-background-color: rgb(45,45,66);
            }
            QComboBox QAbstractItemView::item {
                border: 1px solid transparent;
            }
            QComboBox QAbstractItemView::item:hover {
                border: 1px solid #FAEBD7;
            }
        )");


        colorLayout->addWidget(colorComboBox);
        colorWidget->setLayout(colorLayout);
        layout->addWidget(colorWidget);
    //---------------------------------------------------------------------------- цвета змейки


    //---------------------------------------------------------------------------- звук от кнопок
        QWidget *soundWidget = new QWidget();
        soundWidget->setStyleSheet("background-color: #232339; border-radius: 10px;"); // цвет фона и закругление углов

        QVBoxLayout *soundLayout = new QVBoxLayout;

        QLabel *soundLabel = new QLabel(tr("Sound"));
        soundLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 17px 'Minecraft Ten font cyrillic'; }");
        soundLayout->addWidget(soundLabel);

        QCheckBox *soundCheckBox = new QCheckBox(tr("Enable sound"));

        soundCheckBox->setChecked(tempSoundEnabled);
        soundCheckBox->setStyleSheet("QCheckBox { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");

        soundLayout->addWidget(soundCheckBox);
        soundWidget->setLayout(soundLayout);
        layout->addWidget(soundWidget);

       connect(soundCheckBox, &QCheckBox::stateChanged, this, [&](int state){
            SoundButton::soundEnabled = state == Qt::Checked;
            SoundButton::soundEnabled = !tempSoundEnabled;
          });

    //---------------------------------------------------------------------------- звук от кнопок


    layout->addStretch(1);
    // слот изменения значения слайдера к методу setVolume() плеера
    connect(volumeSlider, &QSlider::valueChanged, player, &QMediaPlayer::setVolume);
    SoundButton *okButton = new SoundButton(tr("Save"));
    okButton->setFixedSize(142, 60); // Задаем фиксированный размер для кнопки "OK"
    okButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                            "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(136,186, 99, 150);" "border-radius: 15px;" "}");

    SoundButton *backButton = new SoundButton(tr("Back"));
    backButton->setFixedSize(142, 60); // Задаем фиксированный размер для кнопки "Back"
    backButton->setStyleSheet("QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                              "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(255,0,0, 50);" "border-radius: 15px;" "}");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(backButton);
    buttonLayout->addWidget(okButton);

    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addLayout(buttonLayout);

    layout->setSpacing(10);

    dialog->setLayout(layout);

    connect(backButton, &SoundButton::clicked, this, [&, dialog, this] {
        player->setVolume(originalVolume);
        SoundButton::soundEnabled = originalSoundEnabled;

        dialog->close();
        this->show();
    });

    connect(okButton, &SoundButton::clicked, this, [&, dialog, this] {
        COLOR = colorComboBox->currentText();
        soundCheckBox->setChecked(tempSoundEnabled);
        player->setVolume(tempVolumeValue);
        dialog->close();
        this->show();
    });

    QPainterPath path;
    path.addRoundedRect(dialog->frameGeometry(), 15, 15);
    dialog->setMask(path.toFillPolygon().toPolygon());

    int x = this->geometry().center().x() - dialog->width() / 2;
    int y = this->geometry().center().y() - dialog->height() / 2;
    dialog->move(x, y);

    dialog->exec();
}


void MainWindow::showMainWindow()
{

      show();
      m_gameField = nullptr;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
        CustomTitleBar *titleBar = new CustomTitleBar(this);
        setMenuWidget(titleBar);

        setFixedSize(320, 400);
        setStyleSheet("QMainWindow { background-color: rgb(45, 45, 66); }");

        // Создаем виджеты для главного меню
        QWidget *widget = new QWidget;
        QVBoxLayout *layout = new QVBoxLayout;

        // Создаем QLabel для изображения
        ClickableLabel *imageLabel = new ClickableLabel;
        QPixmap imagePixmap("C:/Users/vikto/Downloads/safeimagekit-pixel-art.png");

        imageLabel->setPixmap(imagePixmap.scaled(320, 120, Qt::KeepAspectRatio));

        // Создаем горизонтальный макет и добавляем в него imageLabel, выравнивая по центру
        QHBoxLayout *imageLayout = new QHBoxLayout;
        imageLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

        // Добавляем imageLayout в основной макет
        layout->insertLayout(0, imageLayout);
        connect(imageLabel, &ClickableLabel::clicked, this, &MainWindow::openImageWindow);

        SoundButton *playButton = new SoundButton("Play");
        SoundButton *enterNameButton = new SoundButton("Enter nickname");
        SoundButton *settingsButton = new SoundButton("Settings");
        SoundButton *exitButton = new SoundButton("Quit the game");

        QString buttonStyle = "QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                              "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(250,235,215, 150);" "border-radius: 15px;" "}";
        QString buttonStyle2 = "QPushButton {" "font: 15px 'Minecraft Ten font cyrillic';" "color: #FAEBD7;" "padding: 15px;" "background-color: rgba(250,235,215, 50);" "border-radius: 15px;" "}"
                              "QPushButton:hover {""font: 15px 'Minecraft Ten font cyrillic';" "color: #2d2d42;" "padding: 15px;" "background-color: rgba(255,0,0,50);" "border-radius: 15px;" "}";
        // Изменяем стиль кнопок
        playButton->setStyleSheet(buttonStyle);
        enterNameButton->setStyleSheet(buttonStyle);
        settingsButton->setStyleSheet(buttonStyle);
        exitButton->setStyleSheet(buttonStyle2);

        layout->addWidget(playButton);
        layout->addWidget(enterNameButton);
        layout->addWidget(settingsButton);
        layout->addWidget(exitButton);

        widget->setLayout(layout);
        setCentralWidget(widget);

        connect(playButton, &SoundButton::clicked, this, &MainWindow::playGame);
        connect(enterNameButton, &SoundButton::clicked, this, &MainWindow::enterName);
        connect(settingsButton, &SoundButton::clicked, this, ([&](){
            openSettings(SNAKE_COLOR);
        }));
        connect(exitButton, &SoundButton::clicked, QApplication::instance(), &QApplication::quit);


        QPainterPath path;
        path.addRoundedRect(frameGeometry(), 15, 15);

        player = new QMediaPlayer(this);
        // медиафайл, который нужно проиграть
        player->setMedia(QUrl("C:/Kursovaia_ver_3/music_snake/music_1.mp3"));
        setMask(path.toFillPolygon().toPolygon());
        player->setVolume(1);  
        player->play();

}


void MainWindow::openImageWindow() {
    QDialog *dialog = new QDialog(this);

    dialog->setWindowFlags(dialog->windowFlags() | Qt::FramelessWindowHint);
    dialog->setFixedSize(320, 400);
    dialog->setStyleSheet("QDialog { background-color: rgb(45, 45, 66); }");

    QVBoxLayout *layout = new QVBoxLayout;

    //виджет для информации об авторизованном пользователе
    QWidget *userWidget = new QWidget();
    userWidget->setStyleSheet("background-color: #232339; border-radius: 10px;");
    userWidget->setFixedHeight(150);  // высоту плашки

    QVBoxLayout *userLayout = new QVBoxLayout;

    QLabel *authLabel = new QLabel(tr("Authorized user"));
    authLabel->setStyleSheet("QLabel { color: rgb(45, 45, 66); font: 20px 'Minecraft Ten font cyrillic'; }");
    authLabel->setAlignment(Qt::AlignCenter);
    userLayout->addWidget(authLabel);

    std::string authPath = "C:/Kursovaia_ver_3/auth.txt";

    std::ifstream authFile(authPath);
    std::string line;
    if (std::getline(authFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> authData((std::istream_iterator<std::string>(iss)),
                                           std::istream_iterator<std::string>());

        if (authData.size() >= 3) {
            QLabel *usernameLabel = new QLabel(tr("USER: ") + QString::fromStdString(authData[0]));
            usernameLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");
            usernameLabel->setAlignment(Qt::AlignCenter);
            userLayout->addWidget(usernameLabel);

            QLabel *scoreLabel = new QLabel(tr("Record user account: ") + QString::fromStdString(authData[2]));
            scoreLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");
            scoreLabel->setAlignment(Qt::AlignCenter);
            userLayout->addWidget(scoreLabel);

            SoundButton *logoutButton = new SoundButton(tr("Logout"));
            logoutButton->setStyleSheet("QPushButton { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; background-color: rgba(250,235,215, 50); border-radius: 10px; }"
                                        "QPushButton:hover { color: #2d2d42; background-color: rgba(255,0,0,50); }");
            userLayout->addWidget(logoutButton);

            connect(logoutButton, &SoundButton::clicked, this, [=]() {
                std::ofstream outFile(authPath, std::ofstream::trunc);

                QLayoutItem* item;
                while ((item = userLayout->takeAt(0)) != nullptr) {
                    delete item->widget();
                    delete item;
                }

                QLabel* noUserLabel = new QLabel(tr("No user logged in"));
                noUserLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");
                noUserLabel->setAlignment(Qt::AlignCenter);
                userLayout->addWidget(noUserLabel);
            });
        } else {
            QLabel *noUserLabel = new QLabel(tr("No user logged in"));
            noUserLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");
            noUserLabel->setAlignment(Qt::AlignCenter);
            userLayout->addWidget(noUserLabel);
        }
    } else {
        QLabel *noUserLabel = new QLabel(tr("No user logged in"));
        noUserLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");
        noUserLabel->setAlignment(Qt::AlignCenter);
        userLayout->addWidget(noUserLabel);
    }

    userWidget->setLayout(userLayout);
    layout->addWidget(userWidget);


    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setStyleSheet("QScrollArea {"
                              "background-color: #232339;"  // Цвет фона прокручиваемой области
                              "border: 1px solid #232339;"  // Цвет рамки прокручиваемой области
                              "}"
                              "QScrollBar:vertical {"
                              "border: 1px solid #FAEBD7;"  // Цвет рамки вертикального ползунка
                              "background: #232339;"  // Цвет фона вертикального ползунка
                              "width: 15px;"  // Ширина вертикального ползунка
                              "margin: 0px 0 0px 0;"  // Отступы вертикального ползунка
                              "}"
                              "QScrollBar::handle:vertical {"
                              "background: #FAEBD7;"  // Цвет ручки вертикального ползунка
                              "min-height: 20px;"  // Минимальная высота ручки вертикального ползунка
                              "}"
                              "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
                              "border: none;"  // Убрать рамку у кнопок вертикального ползунка
                              "background: none;"  // Убрать фон у кнопок вертикального ползунка
                              "}"
                              "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                              "background: none;"  // Убрать фон у страниц вертикального ползунка
                              "}");


    scrollArea->setFixedHeight(150);
    QWidget *scrollWidget = new QWidget;
    scrollWidget->setStyleSheet("QWidget { background-color: #232339; }");
    QVBoxLayout *scrollLayout = new QVBoxLayout;

    std::string scorePath = "C:/Kursovaia_ver_3/snake_gamer_score.txt";

    std::ifstream scoreFile(scorePath);
    std::string scoreLine;
    std::vector<std::pair<std::string, int>> scores;  // Вектор для хранения пар "ник-счет"
    while (std::getline(scoreFile, scoreLine)) {
        std::istringstream iss(scoreLine);
        std::vector<std::string> scoreData((std::istream_iterator<std::string>(iss)),
                                           std::istream_iterator<std::string>());

        if (scoreData.size() >= 3) {
            scores.push_back(std::make_pair(scoreData[0], std::stoi(scoreData[2])));
        }
    }

    //сортровка вектора scores по счету в порядке убывания
    std::sort(scores.begin(), scores.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    });

    // Добавление метки в scrollLayout
    for (const auto& score : scores) {
        QLabel *userScoreLabel = new QLabel(QString::fromStdString(score.first) + ": " + QString::number(score.second));
        userScoreLabel->setStyleSheet("QLabel { color: #FAEBD7; font: 15px 'Minecraft Ten font cyrillic'; }");
        scrollLayout->addWidget(userScoreLabel);
    }

    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    layout->addWidget(scrollArea);



    SoundButton *backButton = new SoundButton("Back");
    backButton->setStyleSheet("QPushButton {"
                              "font: 15px 'Minecraft Ten font cyrillic';"
                              "color: #FAEBD7;"
                              "padding: 15px;"
                              "background-color: rgba(250,235,215, 50);"
                              "border-radius: 15px;"
                              "}"
                              "QPushButton:hover {"
                              "font: 15px 'Minecraft Ten font cyrillic';"
                              "color: #2d2d42;"
                              "padding: 15px;"
                              "background-color: rgba(255,0,0,50);"
                              "border-radius: 15px;"
                              "}");

    layout->addWidget(backButton, 0, Qt::AlignCenter);
    dialog->setLayout(layout);

    connect(backButton, &SoundButton::clicked, dialog, &QDialog::close);

    QPainterPath path;
    path.addRoundedRect(dialog->frameGeometry(), 15, 15);
    dialog->setMask(path.toFillPolygon().toPolygon());

    int x = this->geometry().center().x() - dialog->width() / 2;
    int y = this->geometry().center().y() - dialog->height() / 2;
    dialog->move(x, y);

    dialog->exec();
}


MainWindow::~MainWindow()
{
}


GameWindow::GameWindow(MainWindow *mainWindow, QWidget *parent)
    :QMainWindow(parent), m_mainWindow(mainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint);

        setFixedSize(320, 380);
        // Создаем виджеты для игры
        m_gameField = new GameField();
        m_helpField = new HelpField();
        connect(m_gameField, &GameField::ChangeTextSignal, m_helpField, &HelpField::ChangeTextSlot);

        connect(m_gameField, &GameField::altPressed, this, &GameWindow::handleAltPressed);

        m_centralWidget = new QWidget();
        m_gridLayout = new QGridLayout();

        m_gameField -> color_snake = mainWindow->SNAKE_COLOR;

        m_gridLayout->addWidget(m_gameField, 0,0);
        m_gridLayout->addWidget(m_helpField, 1, 0);
        m_centralWidget->setLayout(m_gridLayout);
        setCentralWidget(m_centralWidget);
        setStyleSheet("background: rgb(45, 45, 66);");


        QPainterPath path;
        path.addRoundedRect(frameGeometry(), 15, 15);
        setMask(path.toFillPolygon().toPolygon());
}

void GameWindow::handleAltPressed()
{
    m_mainWindow->showMainWindow();
    this->close();
}

CustomTitleBar::CustomTitleBar(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(33);
    setStyleSheet("background-color: rgba(250,235,215, 50);");

    QPushButton *minimizeButton = new QPushButton("-");

    // Устанавливаем фиксированный размер для кнопок и делаем их квадратными
    minimizeButton->setFixedSize(20, 20);

    // Задаем стиль для кнопок
    QString btnStyleMinimize = "QPushButton { background-color: rgba(250,235,215, 50); border-radius: 6px; } QPushButton:hover { background-color: rgba(255,0,0,50); }";
    QString btnStyleClose = "QPushButton { background-color: rgba(250,235,215, 50); border-radius: 6px; } QPushButton:hover { background-color: rgba(255,0,0,50); }";
    minimizeButton->setStyleSheet(btnStyleMinimize);

    QHBoxLayout *layout = new QHBoxLayout(this);

    // Добавляем растягивающийся элемент, чтобы кнопки были справа
    layout->addStretch();
    layout->addWidget(minimizeButton);

    connect(minimizeButton, SIGNAL(clicked()), parent, SLOT(showMinimized()));

}
void CustomTitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - parentWidget()->frameGeometry().topLeft();
        event->accept();
    }
}
void CustomTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        parentWidget()->move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}
