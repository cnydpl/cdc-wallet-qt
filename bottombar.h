// Copyright (c) 2017-2018 The CDC developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>

namespace Ui {
class BottomBar;
}

class CommonTip;

class BottomBar : public QWidget
{
    Q_OBJECT

public:
    explicit BottomBar(QWidget *parent = 0);
    ~BottomBar();
    void retranslator();
    void refresh();

private slots:

    void updateNumOfConnections();

    void jsonDataUpdated(QString id);

private:
    Ui::BottomBar *ui;
    int numOfConnections;
    QTimer* timer;
    CommonTip* connectionTip;


};

#endif // BOTTOMBAR_H
