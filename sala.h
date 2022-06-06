#ifndef SALA_H
#define SALA_H

class Sala {

    private:

      char sala[5][5];
        int columna;
        char fila;

    public:

        Sala();
        void mostrarSala();
        void modificarSalar();
        int obtenerFila(char);
        char getFila();
        int getColumna();

};

#endif // SALA_H
