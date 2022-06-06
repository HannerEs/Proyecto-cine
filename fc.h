#ifndef FC_H
#define FC_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Fc
{
private:
    //Datos Cine
    int ruCine;
    string direccionCine;
    int telefonoCine;

    //Datos cliente
    string nombreCliente;
    int CI;
    string direCli;
    int telefCli;
    vector<Fc> fac;

public:
    Fc();
    Fc(string nombreCliente, int ced, string direCli, int telefCli);
    string datosCine();
    void datosCliente();
    void consumidorFinal();
    void impresionDatosCliente();
    string datos();

};

#endif // FC_H
