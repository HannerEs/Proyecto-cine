#ifndef BOLETO_H
#define BOLETO_H
#include <string>
#include "pelicula.h"

class Boleto {

    private:

        int sala;
        Pelicula pelicula;
        char fila;
        int columna;

    public:

        Boleto();
        Boleto(int, Pelicula , char, int);
        void mostrarBoleto();

};

#endif // BOLETO_H

