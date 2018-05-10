#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}ePersona;

void inicializarLibre(ePersona vec[] , int tam);
int obtenerEspacioLibre(ePersona lista[],int tam);
int buscarPorDni(ePersona vec[],int tam, int dni);
void agregarPersona(ePersona vec[], int tam);
void mostrarDato(ePersona vec);
void mostrarPersonas(ePersona vec[] , int tam);
void borrarPersona(ePersona vec[], int tam);


#endif // FUNCIONES_H_INCLUDED
