// Copyright (c) 2017-2018 The CDC developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#ifndef LOCKPAGE_H
#define LOCKPAGE_H

#include <QWidget>
#include <QLibrary>
#include <QTimer>

namespace Ui {
class LockPage;
}

typedef short(*FUN)(int);

class LockPage : public QWidget
{
    Q_OBJECT

public:
    explicit LockPage(QWidget *parent = 0);
    ~LockPage();

signals:
    void unlock();
    void minimum();
    void closeWallet();
    void tray();
    void showShadowWidget();
    void hideShadowWidget();

private slots:
    void on_enterBtn_clicked();

    void on_pwdLineEdit_returnPressed();

    void on_minBtn_clicked();

    void on_closeBtn_clicked();

    void on_pwdLineEdit_textChanged(const QString &arg1);

    void jsonDataUpdated(QString id);

private:
    Ui::LockPage *ui;

    void keyPressEvent(QKeyEvent* e);
};

#endif // LOCKPAGE_H
