#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(261, 420);
    ui->lineEdit->setMaxLength(28);
    ui->actionExpression_calculation->setChecked(true);
    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->label_2->setText("x<sup>4</sup>+");
    ui->label_3->setText("x<sup>3</sup>+");
    ui->label_4->setText("x<sup>2</sup>+");
    ui->label_5->setText("x+");
    ui->lineEdit_3->setMaxLength(4);
    ui->lineEdit_4->setMaxLength(4);
    ui->lineEdit_5->setMaxLength(4);
    ui->lineEdit_6->setMaxLength(4);
    ui->lineEdit_7->setMaxLength(4);
    curindex = 4;
    ui->lineEdit_3->setStyleSheet("background-color: rgb(164, 225, 236);");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//ac
{
    curexpression.clear();
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_2_clicked()//(
{
    curexpression = curexpression + "(";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_3_clicked()//)
{
    curexpression = curexpression + ")";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_4_clicked()// /
{
    curexpression = curexpression + "/";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_5_clicked()//7
{
    curexpression = curexpression + "7";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_6_clicked()//8
{
    curexpression = curexpression + "8";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_7_clicked()//9
{
    curexpression = curexpression + "9";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_8_clicked()//*
{
    curexpression = curexpression + "*";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_9_clicked()//4
{
    curexpression = curexpression + "4";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_10_clicked()//5
{
    curexpression = curexpression + "5";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_11_clicked()//6
{
    curexpression = curexpression + "6";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_12_clicked()//-
{
    curexpression = curexpression + "-";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_13_clicked()//1
{
    curexpression = curexpression + "1";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_14_clicked()//2
{
    curexpression = curexpression + "2";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_15_clicked()//3
{
    curexpression = curexpression + "3";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_16_clicked()//+
{
    curexpression = curexpression + "+";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_33_clicked()//0
{
    curexpression = curexpression + "0";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_51_clicked()//.
{
    curexpression = curexpression + ".";
    ui->lineEdit->setText(curexpression);
}

void MainWindow::on_pushButton_52_clicked()//=
{
    if(curexpression == "001229"){
        this->setWindowTitle("Administrator");
        QMessageBox::information(this, "Information", "Enter administrator mode!");
        ui->lineEdit->setMaxLength(50);
        EnterSu = true;
    }
    if(curexpression.isEmpty()){
        return;
    }
    calc *calculator = new calc();
    string current = curexpression.toStdString();
    double ans = calculator->RunCalc(current);
    if(ans == -0x3f3f3f3f){
        QMessageBox::warning(this,"Error","Numbers have repeated decimal points");
        curexpression.clear();
    }
    else if(ans == (-0x3f3f3f3f-1)){
        QMessageBox::warning(this,"Error","Parentheses do not match");
        curexpression.clear();
    }
    else if(ans == (-0x3f3f3f3f-2)){
        QMessageBox::warning(this,"Error","Illegal expression");
        curexpression.clear();
    }
    else{
        curexpression = QString::number(ans);
    }
    ui->lineEdit->setText(curexpression);
    delete calculator;
}

void MainWindow::on_actionExpression_calculation_triggered()
{
    if(EnterSu == false) this->setWindowTitle("Expression calculation");
    ui->actionsolve_equations->setChecked(false);
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_actionsolve_equations_triggered()
{
    if(EnterSu == false) this->setWindowTitle("Solve equations");
    ui->actionExpression_calculation->setChecked(false);
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_pushButton_17_clicked()//7(2)
{
    if(curindex == 4) {
        x4 = x4 + "7";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "7";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "7";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "7";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "7";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_18_clicked()//8(2)
{
    if(curindex == 4) {
        x4 = x4 + "8";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "8";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "8";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "8";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "8";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_19_clicked()//9(2)
{
    if(curindex == 4) {
        x4 = x4 + "9";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "9";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "9";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "9";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "9";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_20_clicked()//4(2)
{
    if(curindex == 4) {
        x4 = x4 + "4";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "4";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "4";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "4";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "4";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_21_clicked()//5(2)
{
    if(curindex == 4) {
        x4 = x4 + "5";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "5";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "5";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "5";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "5";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_22_clicked()//6(2)
{
    if(curindex == 4) {
        x4 = x4 + "6";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "6";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "6";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "6";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "6";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_23_clicked()//1(2)
{
    if(curindex == 4) {
        x4 = x4 + "1";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "1";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "1";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "1";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "1";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_24_clicked()//2(2)
{
    if(curindex == 4) {
        x4 = x4 + "2";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "2";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "2";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "2";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "2";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_25_clicked()//3(2)
{
    if(curindex == 4) {
        x4 = x4 + "3";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "3";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "3";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "3";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "3";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_26_clicked()//.(2)
{
    if(curindex == 4) {
        x4 = x4 + ".";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + ".";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + ".";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + ".";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + ".";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_27_clicked()//0(2)
{
    if(curindex == 4) {
        x4 = x4 + "0";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "0";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "0";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "0";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "0";
        ui->lineEdit_7->setText(e);
    }
}

void MainWindow::on_pushButton_29_clicked()
{
    if(curindex == 4){
        int len = x4.length();
        int points = 0;
        bool sur = true;
        for(int i = 0; i < len; ++i){
            if(x4[i] == '.') points++;
            if(x4[i] == '-' && i != 0) sur = false;
        }
        if(points > 1){
            QMessageBox::warning(this,"Error","Numbers have repeated decimal points");
            x4.clear();
            ui->lineEdit_3->setText(x4);
        }
        else if(sur == false){
            QMessageBox::warning(this,"Error","Wrong negative sign");
            x4.clear();
            ui->lineEdit_3->setText(x4);
        }
        else{
            curindex--;
            if(x4.isEmpty()) x4 = "0";
            ui->lineEdit_3->setText(x4);
            ui->lineEdit_3->setStyleSheet("background-color: white;");
            ui->lineEdit_4->setStyleSheet("background-color: rgb(164, 225, 236);");
        }
    }
    else if(curindex == 3){
        int len = x3.length();
        int points = 0;
        bool sur = true;
        for(int i = 0; i < len; ++i){
            if(x3[i] == '.') points++;
            if(x4[i] == '-' && i != 0) sur = false;
        }
        if(points > 1){
            QMessageBox::warning(this,"Error","Numbers have repeated decimal points");
            x3.clear();
            ui->lineEdit_4->setText(x3);
        }
        else if(sur == false){
            QMessageBox::warning(this,"Error","Wrong negative sign");
            x4.clear();
            ui->lineEdit_3->setText(x4);
        }
        else{
            curindex--;
            if(x3.isEmpty()) x3 = "0";
            ui->lineEdit_4->setText(x3);
            ui->lineEdit_4->setStyleSheet("background-color: white;");
            ui->lineEdit_5->setStyleSheet("background-color: rgb(164, 225, 236);");
        }
    }
    else if(curindex == 2){
        int len = x2.length();
        int points = 0;
        bool sur = true;
        for(int i = 0; i < len; ++i){
            if(x2[i] == '.') points++;
            if(x4[i] == '-' && i != 0) sur = false;
        }
        if(points > 1){
            QMessageBox::warning(this,"Error","Numbers have repeated decimal points");
            x2.clear();
            ui->lineEdit_5->setText(x2);
        }
        else if(sur == false){
            QMessageBox::warning(this,"Error","Wrong negative sign");
            x4.clear();
            ui->lineEdit_3->setText(x4);
        }
        else{
            curindex--;
            if(x2.isEmpty()) x2 = "0";
            ui->lineEdit_5->setText(x2);
            ui->lineEdit_5->setStyleSheet("background-color: white;");
            ui->lineEdit_6->setStyleSheet("background-color: rgb(164, 225, 236);");
        }
    }
    else if(curindex == 1){
        int len = x.length();
        int points = 0;
        bool sur = true;
        for(int i = 0; i < len; ++i){
            if(x[i] == '.') points++;
            if(x4[i] == '-' && i != 0) sur = false;
        }
        if(points > 1){
            QMessageBox::warning(this,"Error","Numbers have repeated decimal points");
            x.clear();
            ui->lineEdit_6->setText(x);
        }
        else if(sur == false){
            QMessageBox::warning(this,"Error","Wrong negative sign");
            x4.clear();
            ui->lineEdit_3->setText(x4);
        }
        else{
            curindex--;
            if(x.isEmpty()) x = "0";
            ui->lineEdit_6->setText(x);
            ui->lineEdit_6->setStyleSheet("background-color: white;");
            ui->lineEdit_7->setStyleSheet("background-color: rgb(164, 225, 236);");
        }
    }
    else if(curindex == 0){
        int len = e.length();
        int points = 0;
        bool sur = true;
        for(int i = 0; i < len; ++i){
            if(e[i] == '.') points++;
            if(x4[i] == '-' && i != 0) sur = false;
        }
        if(points > 1){
            QMessageBox::warning(this,"Error","Numbers have repeated decimal points");
            e.clear();
            ui->lineEdit_7->setText(e);
        }
        else if(sur == false){
            QMessageBox::warning(this,"Error","Wrong negative sign");
            x4.clear();
            ui->lineEdit_3->setText(x4);
        }
        else{
            curindex--;
            if(e.isEmpty()) e = "0";
            ui->lineEdit_7->setText(e);
            ui->lineEdit_7->setStyleSheet("background-color: white;");
            equations *equ = new equations();
            float x_4 = x4.toFloat();
            float x_3 = x3.toFloat();
            float x_2 = x2.toFloat();
            float x_1 = x.toFloat();
            float e_1 = e.toFloat();
            equ->RunCalc(x_4, x_3, x_2, x_1, e_1);
            int num = equ->r[0];
            if(num == 0) ans = "No real root";
            else{
                for(int i = 0; i < num; ++i){
                    ans = ans + "r[" + QString::number(i + 1) + "]:" + QString::number(equ->r[i + 1]) + "\r\n";
                }
                ans = ans + "Note: only count real roots";
            }
            ui->textEdit->setText(ans);
            delete equ;
        }
    }
    else if(curindex == -1){
        curindex = 4;
        x4.clear(), x3.clear(), x2.clear(), x.clear(), e.clear();
        ans.clear();
        ui->textEdit->setText(ans);
        ui->lineEdit_3->setText(x4);
        ui->lineEdit_4->setText(x3);
        ui->lineEdit_5->setText(x2);
        ui->lineEdit_6->setText(x);
        ui->lineEdit_7->setText(e);
        ui->lineEdit_3->setStyleSheet("background-color: rgb(164, 225, 236);");
    }
}

void MainWindow::on_pushButton_30_clicked()
{
    if(curindex == 4) {
        x4 = x4 + "-";
        ui->lineEdit_3->setText(x4);
    }
    else if(curindex == 3){
        x3 = x3 + "-";
        ui->lineEdit_4->setText(x3);
    }
    else if(curindex == 2){
        x2 = x2 + "-";
        ui->lineEdit_5->setText(x2);
    }
    else if(curindex == 1){
        x = x + "-";
        ui->lineEdit_6->setText(x);
    }
    else if(curindex == 0){
        e = e + "-";
        ui->lineEdit_7->setText(e);
    }
}
