#include "principal.h"
#include "ui_principal.h"
#include <iostream>
#include <string.h>
using namespace std;
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

//.......................................................................................................
//Para calcular el qoe unificado
//.......................................................................................................
float calc_qoe (int qoe_j1, int qoe_j2){
    float qoe_final;
    if (qoe_j1 == qoe_j2)
        qoe_final = qoe_j1;
    else
        qoe_final = (float(qoe_j1) + qoe_j2) / 2.0;
    return qoe_final;
}

//.......................................................................................................
//Para calcular el balor base de un salto una vez se le introduce si es completo o no
//.......................................................................................................
float SJu_BaseVal (string tipo_salto, int rot){
    float punt = 0;
    if (tipo_salto == "Ll") {
        punt = 2.0;
    } else if (tipo_salto == "Pi") {
        punt = 3.0;
    } else if (tipo_salto == "W") {
        if (rot == 0)
            punt = 4.0;
        else
            punt = 0.0;
    } else if (tipo_salto == "T") {
        switch (rot){
        case 0:
            punt = 6.0;
            break;
        case 1:
            punt = 4.3;
            break;
        case 2:
            punt = 3.1;
            break;
        case 3:
            punt = 0.0;
            break;
        default:
            break;
        }
    } else if (tipo_salto == "S") {
        switch (rot){
        case 0:
            punt = 6.0;
            break;
        case 1:
            punt = 4.3;
            break;
        case 2:
            punt = 3.1;
            break;
        case 3:
            punt = 0.0;
            break;
        default:
            break;
        }
    } else if (tipo_salto == "F") {
        switch (rot){
        case 0:
            punt = 8.0;
            break;
        case 1:
            punt = 6.0;
            break;
        case 2:
            punt = 4.3;
            break;
        case 3:
            punt = 0.0;
            break;
        default:
            break;
        }
    } else if (tipo_salto == "Lz") {
        switch (rot){
        case 0:
            punt = 9.0;
            break;
        case 1:
            punt = 6.7;
            break;
        case 2:
            punt = 4.8;
            break;
        case 3:
            punt = 0.0;
            break;
        default:
            break;
        }
    } else if (tipo_salto == "Lo") {
        switch (rot){
        case 0:
            punt = 9.0;
            break;
        case 1:
            punt = 6.7;
            break;
        case 2:
            punt = 4.8;
            break;
        case 3:
            punt = 0.0;
            break;
        default:
            break;
        }
    } else if (tipo_salto == "Th") {
        switch (rot){
        case 0:
            punt = 9.0;
            break;
        case 1:
            punt = 6.7;
            break;
        case 2:
            punt = 4.8;
            break;
        case 3:
            punt = 0.0;
            break;
        default:
            break;
        }
    } else if (tipo_salto == "A") {
        switch (rot){
        case 0:
            punt = 13.0;
            break;
        case 1:
            punt = 9.8;
            break;
        case 2:
            punt = 7.0;
            break;
        case 3:
            punt = 4.0;
            break;
        default:
            break;
        }
    }
    return punt;
}

//.......................................................................................................
//para sacar la puntuacion final de un salto una vez se le añade qoe
//.......................................................................................................
float SJu_punt(string tipo_salto, float qoe, int BaseVal){
    float punt = 0;

    if (tipo_salto == "Ll") { //acabado
        if (qoe == 3){
            punt = BaseVal + 1.5;
        }else if (qoe == 2.5){
            punt = BaseVal + 1.25;
        }else if (qoe == 2){
            punt = BaseVal + 1;
        }else if (qoe == 1.5){
            punt = BaseVal + 0.85;
        }else if (qoe == 1){
            punt = BaseVal + 0.7;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.35;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.35;
        }else if (qoe == -1){
            punt = BaseVal - 0.7;
        }else if (qoe == -1.5){
            punt = BaseVal - 0.85;
        }else if (qoe == -2){
            punt = BaseVal - 1;
        }else if (qoe == -2.5){
            punt = BaseVal - 1.25;
        }else if (qoe == -3){
            punt = BaseVal - 1.5;
        }
    } else if (tipo_salto == "Pi") {    //acabado
        if (qoe == 3){
            punt = BaseVal + 2;
        }else if (qoe == 2.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 2){
            punt = BaseVal + 1;
        }else if (qoe == 1.5){
            punt = BaseVal + 0.85;
        }else if (qoe == 1){
            punt = BaseVal + 0.7;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.35;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.35;
        }else if (qoe == -1){
            punt = BaseVal - 0.7;
        }else if (qoe == -1.5){
            punt = BaseVal - 0.85;
        }else if (qoe == -2){
            punt = BaseVal - 1;
        }else if (qoe == -2.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -3){
            punt = BaseVal - 2;
        }
    } else if (tipo_salto == "W") {     //acabado
        if (qoe == 3){
            punt = BaseVal + 3;
        }else if (qoe == 2.5){
            punt = BaseVal + 2.5;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 2.5;
        }else if (qoe == -3){
            punt = BaseVal - 3;
        }
    } else if (tipo_salto == "T") {     //acabado
        if (qoe == 3){
            punt = BaseVal + 3;
        }else if (qoe == 2.5){
            punt = BaseVal + 2.5;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 2.5;
        }else if (qoe == -3){
            punt = BaseVal - 3;
        }
    } else if (tipo_salto == "S") {     //acabado
        if (qoe == 3){
            punt = BaseVal + 3;
        }else if (qoe == 2.5){
            punt = BaseVal + 2.5;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 2.5;
        }else if (qoe == -3){
            punt = BaseVal - 3;
        }
    } else if (tipo_salto == "F") {     //acabado
        if (qoe == 3){
            punt = BaseVal + 4;
        }else if (qoe == 2.5){
            punt = BaseVal + 3;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 3;
        }else if (qoe == -3){
            punt = BaseVal - 4;
        }
    } else if (tipo_salto == "Lz") {        //acabado
        if (qoe == 3){
            punt = BaseVal + 4;
        }else if (qoe == 2.5){
            punt = BaseVal + 3;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 3;
        }else if (qoe == -3){
            punt = BaseVal - 4;
        }
    } else if (tipo_salto == "Lo") {        //acabado
        if (qoe == 3){
            punt = BaseVal + 4;
        }else if (qoe == 2.5){
            punt = BaseVal + 3;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 3;
        }else if (qoe == -3){
            punt = BaseVal - 4;
        }
    } else if (tipo_salto == "Th") {        //acabado
        if (qoe == 3){
            punt = BaseVal + 4;
        }else if (qoe == 2.5){
            punt = BaseVal + 3;
        }else if (qoe == 2){
            punt = BaseVal + 2;
        }else if (qoe == 1.5){
            punt = BaseVal + 1.5;
        }else if (qoe == 1){
            punt = BaseVal + 1;
        }else if (qoe == 0.5){
            punt = BaseVal + 0.5;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 0.5;
        }else if (qoe == -1){
            punt = BaseVal - 1;
        }else if (qoe == -1.5){
            punt = BaseVal - 1.5;
        }else if (qoe == -2){
            punt = BaseVal - 2;
        }else if (qoe == -2.5){
            punt = BaseVal - 3;
        }else if (qoe == -3){
            punt = BaseVal - 4;
        }
    } else if (tipo_salto == "A") {     //acabado
        if (qoe == 3){
            punt = BaseVal + 4;
        }else if (qoe == 2.5){
            punt = BaseVal + 3.5;
        }else if (qoe == 2){
            punt = BaseVal + 3;
        }else if (qoe == 1.5){
            punt = BaseVal + 2.5;
        }else if (qoe == 1){
            punt = BaseVal + 2;
        }else if (qoe == 0.5){
            punt = BaseVal + 1;
        }else if (qoe == 0){
            punt = BaseVal;
        }else if (qoe == -0.5){
            punt = BaseVal - 1;
        }else if (qoe == -1){
            punt = BaseVal - 2;
        }else if (qoe == -1.5){
            punt = BaseVal - 2.5;
        }else if (qoe == -2){
            punt = BaseVal - 3;
        }else if (qoe == -2.5){
            punt = BaseVal - 3.5;
        }else if (qoe == -3){
            punt = BaseVal - 4;
        }
    }

    return punt;
}

//.......................................................................................................
//para calcular el valor base de una pirueta
//.......................................................................................................
float SSp_BaseVal(string tipo_pir, string dif_var, bool dif_entry, bool rotac, bool stand_var, bool valid){
    float valor = 0;

    if (valid == true){
        if (tipo_pir == "Tf"){
            valor = 3.0;
        }else if (tipo_pir == "U"){
            valor = 5.0;
            if (dif_var == "Forward"){
                valor = valor + 10;
            }else if (dif_var == "Layback"){
                valor = valor + 10 + (valor * 0.2);
            }else if (dif_var == "Split"){
                valor = valor + 10 + (valor * 0.5);
            }else if (dif_var == "Heel"){
                valor = valor + (valor * 0.5);
            }else if (dif_var == "Heel_Biellmann"){
                valor = valor + 20 + (valor * 0.8);
            }else if (dif_var == "Torso"){
                valor = valor + 10 + (valor * 0.4);
            }

        }else if (tipo_pir == "Ud"){
            valor = 6.0;
            if (dif_var == "Forward"){
                valor = valor + 10;
            }else if (dif_var == "Layback"){
                valor = valor + 10 + (valor * 0.2);
            }else if (dif_var == "Split"){
                valor = valor + 10 + (valor * 0.5);
            }else if (dif_var == "Heel"){
                valor = valor + (valor * 0.5);
            }else if (dif_var == "Heel_Biellmann"){
                valor = valor + 20 + (valor * 0.8);
            }else if (dif_var == "Torso"){
                valor = valor + 10 + (valor * 0.4);
            }

        }else if (tipo_pir == "S"){
            valor = 8.0;
            if (dif_var == "Sideways"){
                valor = valor + (valor * 0.6);
            }else if (dif_var == "Twist"){
                valor = valor + (valor * 0.6);
            }else if (dif_var == "Forward"){
                valor = valor + (valor * 0.4);
            }else if (dif_var == "Behind"){
                valor = valor + (valor * 0.2);
            }

        }else if (tipo_pir == "CBD"){
            valor = 10.0;
            if (dif_var == "Layover"){
                valor = valor + (valor * 0.2);
            }else if (dif_var == "Forward"){
                valor = valor + (valor * 0.4);
            }else if (dif_var == "Sideways"){
                valor = valor + (valor * 0.6);
            }
        }else if (tipo_pir == "CFD"){
            valor = 12.0;
            if (dif_var == "Layover"){
                valor = valor + (valor * 0.2);
            }else if (dif_var == "Forward"){
                valor = valor + (valor * 0.4);
            }else if (dif_var == "Sideways"){
                valor = valor + (valor * 0.6);
            }
        }
    }

    if (dif_entry == true)
        valor = valor + (valor * 0.15);
    if (stand_var == true)
        valor = valor + (valor * 0.2);
    if (rotac == true)
        valor = valor + (valor * 0.2);
    return valor;
}
