#include <iostream>
#include "sala.h"
#include "pelicula.h"
#include "boleto.h"
#include "fc.h"

using namespace std;

int main(){
    system("color 0E");
    cout<<"\n";
    cout<<"= = = = U N I V E R S I D A D  P O L I T E C N I C A  S A L E S I A N A = = = =\n\n";
    cout<<"                       PROGRAMACION ORIENTADA A OBJETOS \n";
    cout<<"                                  GRUPO 2\n";
    cout<<"                        PROYECTO: BOLETERIA DE UN CINE\n\n";
    cout <<"Autores: Hanner Joan Delgado Espino\n"
           "         Byron Geovanny Jaramillo Namicela\n"
           "         Tobar Soberon Justin Edu\n"
           "         Jorge Sebastian Reinoso Reyes\n\n";

    int opcion, numeroSala, posicion, totalBoletos, idBuscar, columna;
    char fila;

    bool continuar = true;

    int idPelicula[] = { 1, 2, 3, 4, 5 };

    string hora[] = { "14:30", "16:00", "18:20", "16:15", "11:30" };

    string titulo[] = { "El Rey Leon", "Spiderma: Lejos de Casa", "Annabelle 3: Vuelve a Casa", "Avengers: End Game", "Toy Story 4" };

    int duracion[] = { 117, 130, 106, 188, 104 };

    bool estreno[] = { true, true, false, false, false};

    Sala sala[5];

    Pelicula pelicula(idPelicula, titulo, duracion, estreno, hora);

    Boleto boletos[25];

    const float precioBoleto = 3.15;

    while (continuar) {

        cout << "- - C I N E  D O N  B O S Q U I T O - -" << endl<<endl;

        cout << "+ + MENU PRINCIPAL + +" << endl;
        cout << "1. Mostrar Cartelera\n"
                "2. Mostrar Sala\n"
                "3. Comprar Boletos\n"
                "4. Factura\n"
                "5. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\n\n- - C A R T E L E R A - -" << endl << endl;

                 pelicula.mostrarPeliculas();

                break;

            case 2:

                cout << "\nIngrese el numero de sala: ";
                cin >> numeroSala;

                posicion = pelicula.buscarPelicula(numeroSala);

                if (posicion != -1) {

                    pelicula.mostrarPelicula(posicion);

                    cout << "\n- - A S I E N T O S - -" << endl;

                    sala[posicion].mostrarSala();

                }else {

                    cout << "No se encontro la sala del cine" << endl;

                }

                break;

            case 3:

                cout << "\nIngrese el ID de la pelicula: ";
                cin >> idBuscar;

                do {

                    cout << "\nIngrese el numero de boletos: ";
                    cin >> totalBoletos;
                    cout<<"\n";
                    //-----------------------------------------------------------------------


                    posicion = pelicula.buscarPelicula(idBuscar);

                    if (posicion != -1) {

                        pelicula.mostrarPelicula(posicion);

                        cout << "\n- - A S I E N T O S - -" << endl;

                        sala[posicion].mostrarSala();

                    }else {

                        cout << "No se encontro la sala del cine" << endl;
                    }

                    //----------------------------------------------------------------------

                    if (totalBoletos < 1) {

                        cout << "El numero de boletos no pueden ser negativos" << endl;

                    }

                } while (totalBoletos < 1);

                posicion = pelicula.buscarPelicula(idBuscar);

                if (posicion != -1) {

                    cout << "\nSeleccione los asientos" << endl;

                    for (int i = 0; i < totalBoletos; i++) {

                        sala[posicion].modificarSalar();

                        fila = sala[posicion].getFila();

                        columna = sala[posicion].getColumna();

                        boletos[i] = Boleto(idBuscar, pelicula, fila, columna);

                    }
                    cout << "\nTOTAL DE LA COMPRA: " << endl;

                    for (int i = 0; i < totalBoletos; i++) {

                        cout << "\n\nBoleto #" << i + 1 <<endl;

                        cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

                        boletos[i].mostrarBoleto();

                        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
                    }
                    cout << "\nTOTAL: " << ((float)totalBoletos * precioBoleto);

                }else {

                    cout << "No se encontro la sala del cine" << endl;
                }
                break;

        case 4:
            float iva; //IVA DEL 12%
            float subtotal;
            bool consumidor_final;
            iva=(totalBoletos*precioBoleto)*0.12;
            subtotal=(totalBoletos*precioBoleto)-iva;
            cout<<"Consumidor final?\n";
            cout<<"1: Si\n0: No\n";
            cin>>consumidor_final;
            if(consumidor_final==true){

            cout<<" \t+ + F A C T U R A  C I N E + +\n";

            Fc facturaCaso1;
             cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout<<facturaCaso1.datosCine();
             cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
            facturaCaso1.consumidorFinal();
             cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout<<"| Subtotal: "<<subtotal<<"\t\t\t |\n";
            cout<<"| IVA: "<<iva<<"\t\t\t\t |\n";
            cout << "| TOTAL: " << ((float)totalBoletos * precioBoleto)<<"\t\t\t\t |";

            cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
            }else if(consumidor_final==false){
                cout<<" \t+ + D A T O S  F A C T U R A + +\n";

               Fc facturaCaso2;

                facturaCaso2.datosCliente();
                cout<<"\n + + F A C T U R A  C L I E N T E + +";
                cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
                cout<<facturaCaso2.datosCine();
                cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
                facturaCaso2.impresionDatosCliente();
                cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;
                cout<<"| Subtotal: "<<subtotal<<"\t\t\t |\n";
                cout<<"| IVA: "<<iva<<"\t\t\t\t |\n";
                cout << "| TOTAL: " << ((float)totalBoletos * precioBoleto)<<"\t\t\t\t |";
                cout << "\n::::::::::::::::::::::::::::::::::::::::::" << endl;

            }
        break;
            system("cls");
        case 5:

            continuar = false;

            cout << "Saliendo del programa" << endl;

            break;

        default: cout << "Opcion invalida" << endl;
        }

        if (opcion != 5) {

            cout << endl;
            system("pause");
            system("cls");

        }

    }
}

