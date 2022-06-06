#include "fc.h"

Fc::Fc()
{
    this->ruCine=9999999999991;
    this->direccionCine="Av.Moran Valverde";
    this->telefonoCine=999999999;


    this->nombreCliente="";
    this->CI=0;
    this->direCli="";
    this->telefCli=0;
}

Fc::Fc(string nombreCliente, int ced, string direCli, int telefCli)
{
    this->nombreCliente=nombreCliente;
    this->CI=ced;
    this->direCli=direCli;
    this->telefCli=telefCli;

}

string Fc::datosCine()
{
    string str="| RUC: "+to_string(this->ruCine)+"\t\t\t |"+"\n"+
            "| Dir: "+this->direccionCine+"\t\t |"+"\n| Telefono cine: "+to_string(telefonoCine)+"\t\t |";
    return str;
}

void Fc::datosCliente()
{
    string nombreCliente;
    int CI;
    string direCli;
    int telefCli;
    cout <<"\nIngrese nombre del Cliente: ";
    getline(cin>>ws,nombreCliente);
    cout <<"Ingrese cedula del cliente: ";
    cin>>CI;
    cout <<"Ingrese direccion del Cliente: ";
    cin>>direCli;
    cout <<"Ingrese telefono del Cliente: ";
    cin>>telefCli;

    Fc j(nombreCliente,CI,direCli,telefCli);
    this->fac.push_back(j);
    system("cls");

}
void Fc::impresionDatosCliente()
{

    for(Fc j:this->fac)
        cout<<j.datos();


}

string Fc::datos()
{
    string str="| Nombre: "+nombreCliente+"\t\t |"+"\n"+"| Cedula: "+to_string(this->CI)+"\t\t\t |"+"\n"+
            "| Direccion: "+this->direCli+"\t\t |"+"\n"+"| Telefono: "+to_string(this->telefCli)+"\t\t\t |";
    return str;
}

void Fc::consumidorFinal()
{
    cout<<"| Nombre: Consumidor final\t\t |\n";
    cout<<"| CI/RUC: 99999999999\t\t\t |\n";
    cout<<"| DIRECCION: N/A\t\t\t |\n";
    cout<<"| TELEFONO: 999999999999\t\t |\n";
    cout<<"| Correo: N/A\t\t\t\t |";

}

