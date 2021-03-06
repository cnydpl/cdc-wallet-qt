// Copyright (c) 2017-2018 The CDC developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "commontip.h"
#include "ui_commontip.h"
#include "debug_log.h"

CommonTip::CommonTip( QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommonTip)
{
    DLOG_QT_WALLET_FUNCTION_BEGIN;
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    DLOG_QT_WALLET_FUNCTION_END;
}

CommonTip::~CommonTip()
{
    DLOG_QT_WALLET_FUNCTION_BEGIN;
    delete ui;
    DLOG_QT_WALLET_FUNCTION_END;
}

void CommonTip::setText(QString text)
{
    ui->label->setText( text);
    ui->label->adjustSize();
    ui->label->move(0,0);
    setFixedSize( ui->label->size());
}
