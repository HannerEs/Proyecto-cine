#include <iostream>
#include <string>
#include "pelicula.h"

Pelicula::Pelicula() {}

Pelicula::Pelicula(int idPelicula[], string titulo[], int duracion[], bool estreno[], string hora[]) {

    for (int i = 0; i < 5; i++) {
        this->idPelicula[i] = idPelicula[i];
        this->titulo[i] = titulo[i];
        this->duracion[i] = duracion[i];
        this->estreno[i] = estreno[i];
        this->hora[i] = hora[i];
    }
}

int Pelicula::buscarPelicula(int buscarId) {

    int i = 0;
    while (i < 5 && buscarId != idPelicula[i]) {
        i++;
    }

    if (buscarId == idPelicula[i]) {
        return i;
    }else {
        return -1;
    }
}

void Pelicula::mostrarPelicula(int buscarId) {

    if (estreno[buscarId]) {
        cout << idPelicula[buscarId] << " - " << " [" << hora[buscarId] << "]" << " " << titulo[buscarId] << " " << duracion[buscarId] << " " << "* ESTRENO *" <<endl;
    }else {

        cout << idPelicula[buscarId] << " - " << " [" << hora[buscarId] << "]" << " " << titulo[buscarId] << " " << duracion[buscarId] << " " << endl;
    }
}

void Pelicula::mostrarPeliculas() {

    for (int i = 0; i < 5; i++) {
        if (estreno[i]) {
            cout << idPelicula[i] << " - " << " [" << hora[i] << "]" << " " << titulo[i] << " " << duracion[i] << " " << "* ESTRENO *" << endl;
        }else {
            cout << idPelicula[i] << " - " << " [" << hora[i] << "]" << " " << titulo[i] << " " << duracion[i] << " " << endl;
        }
    }
}

string Pelicula::getTitulo(int posicion) {

    string titu = titulo[posicion];
    return titu;
}
string Pelicula::getHora(int posicion) {

    string horario = hora[posicion];
    return horario;
}
