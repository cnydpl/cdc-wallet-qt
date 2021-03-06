// Copyright (c) 2017-2018 The CDC developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "shadowwidget.h"
#include "ui_shadowwidget.h"
#include "pubic_define.h"
#include <QDebug>
#include <QMovie>

ShadowWidget::ShadowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShadowWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    setAutoFillBackground(true);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(MENU_BACKGROUND_COLOR));
    setPalette(palette);

    ui->gifLabel->setGeometry(0,0,34,34);
    ui->gifLabel->show();
    ui->tipLabel->hide();

    retranslator();

}

ShadowWidget::~ShadowWidget()
{

}

void ShadowWidget::init(QSize size)
{
    resize(size);
    ui->gifLabel->move( size.width() / 2 - 17, size.height() / 2 - 17);
    ui->tipLabel->move( ( this->width() - ui->tipLabel->width() ) / 2, 400);
}

void ShadowWidget::retranslator()
{
    ui->retranslateUi(this);
    ui->tipLabel->adjustSize();
    ui->tipLabel->move( ( this->width() - ui->tipLabel->width() ) / 2, 400);
}

