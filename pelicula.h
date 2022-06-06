#ifndef PELICULA_H

#define PELICULA_H

#include <iostream>

using namespace std;

class Pelicula {

    private:

        int idPelicula[5];
        string titulo[5];
        float duracion[5];
        bool estreno[5];
        string hora[5];

    public:

        Pelicula();
        Pelicula(int [],string [], int [], bool[], string[]);
        int buscarPelicula(int );
        void mostrarPelicula(int );
        void mostrarPeliculas();
        string getTitulo(int);
        string getHora(int);
};


#endif // PELICULA_H
