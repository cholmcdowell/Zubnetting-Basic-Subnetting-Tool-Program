#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bdnEnter_clicked()
{
    NetworkInput input;

    input.ip_address = ui->txtIP->text().toStdString();
    input.cidr = ui->txtCIDR->text().toStdString();

    if (!isValid(input)) {
        ui->txtSubnet->setPlainText("Invalid IP/CIDR");
        ui->txtSubnet_2->setPlainText("Invalid IP/CIDR");
        ui->txtNetworkAddress->setPlainText("Invalid IP/CIDR");
        ui->txtBroadcastAddress->setPlainText("Invalid IP/CIDR");
        return;
    }

    int cidr = stoi(input.cidr);

    ui->txtSubnet->setPlainText(
        QString::fromStdString(QSubnetMask(cidr))
    );
    ui->txtSubnet_2->setPlainText(
        QString::fromStdString(QSubnetBinary(cidr))
    );

    ui->txtNetworkAddress->setPlainText(
        QString::fromStdString(QNetworkAddress(input.ip_address, cidr))
    );
    ui->txtBroadcastAddress->setPlainText(
        QString::fromStdString(QBroadcastAddress(input.ip_address, cidr))
    );
}


void MainWindow::on_bdnClear_clicked()
{
    ui->txtIP->clear();
    ui->txtCIDR->clear();
    ui->txtSubnet->clear();
    ui->txtSubnet_2->clear();
    ui->txtNetworkAddress->clear();
    ui->txtBroadcastAddress->clear();
}

