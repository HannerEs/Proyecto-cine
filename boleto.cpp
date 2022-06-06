#include <iostream>
#include "pelicula.h"
#include "boleto.h"

Boleto::Boleto(){}

Boleto::Boleto(int sala, Pelicula pelicula, char fila, int columna) {

    this->sala = sala;
    this->pelicula = pelicula;
    this->fila = fila;
    this->columna = columna;

}


void Boleto::mostrarBoleto() {

    cout << "| Sala: " << sala << "\t\t\t\t\t\t    |" << endl;
    cout << "| Hora: " << pelicula.getHora(sala - 1) << "\t\t\t\t\t\t    |" << endl;
    cout << "| Asiento: " << fila << columna << "\t\t\t\t\t\t    |" << endl;
    cout << "| Pelicula: " << pelicula.getTitulo(sala - 1) << "\t\t\t\t\t    |" << endl;


}

