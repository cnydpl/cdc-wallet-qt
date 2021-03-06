// Copyright (c) 2017-2018 The CDC developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "chooseaddaccountdialog.h"
#include "ui_chooseaddaccountdialog.h"
#include "pubic_define.h"

#ifdef WIN32
#include "Windows.h"
#endif

ChooseAddAccountDialog::ChooseAddAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseAddAccountDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Popup);

    ui->newBtn->setStyleSheet("QPushButton{color:rgb("STR_BUTTON_COLOR");border:1px solid white;border-top-left-radius:10px;border-top-right-radius:10px;background-color: white}QPushButton:hover{color:white;border:1px solid  rgb("STR_BUTTON_COLOR");background-color: rgb("STR_BUTTON_COLOR");}");
    ui->importBtn->setStyleSheet("QPushButton{color:rgb("STR_BUTTON_COLOR");border:1px solid white;border-bottom-left-radius:10px;border-bottom-right-radius:10px;background-color: white}QPushButton:hover{color:white;border:1px solid  rgb("STR_BUTTON_COLOR");background-color: rgb("STR_BUTTON_COLOR");}");
}

ChooseAddAccountDialog::~ChooseAddAccountDialog()
{
    delete ui;
}

bool ChooseAddAccountDialog::event(QEvent *event)
{
#ifdef WIN32
    // class_ameneded 不能是custommenu的成员, 因为winidchange事件触发时, 类成员尚未初始化
    static bool class_amended = false;
    if (event->type() == QEvent::WinIdChange)
    {
        HWND hwnd = reinterpret_cast<HWND>(winId());
        if (class_amended == false)
        {
            class_amended = true;
            DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
            class_style &= ~CS_DROPSHADOW;
            ::SetClassLong(hwnd, GCL_STYLE, class_style); // windows系统函数
        }
    }
#endif
	
    return QWidget::event(event);
}


void ChooseAddAccountDialog::on_newBtn_clicked()
{
    close();
    emit newAccount();
}

void ChooseAddAccountDialog::on_importBtn_clicked()
{
    close();
    emit importAccount();
}
