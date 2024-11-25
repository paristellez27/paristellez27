#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <iostream>
#include <string.h>
using namespace std;
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Principal;
}
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private:
    Ui::Principal *ui;
    float SJu_punt(string tipo_salto, int qoe);
    float SJu_BaseVal (string tipo_salto, int rot);
    float calc_qoe (int qoe_j1, int qoe_j2);
    float SSp_BaseVal(string tipo_pir, string dif_var, bool dif_entry, bool rotac, bool stand_var, bool valid);
};
#endif // PRINCIPAL_H
