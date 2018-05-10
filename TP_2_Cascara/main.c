#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


#define TAM 20
int main()
{
    char seguir='s';
    int opcion=0;

    ePersona persona[TAM];
    inicializarLibre(persona,TAM);


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(persona,TAM);
                break;
            case 2:
                borrarPersona(persona,TAM);
                break;
            case 3:
                mostrarPersonas(persona,TAM);
                system("pause");
                break;
            case 4:
                mostrarGrafico(persona, TAM);
                system("pause");

                break;
            case 5 :
                seguir = 'n';
                break;
            default:
                printf("Opcion Incorrecta\n");
                system("pause");
        }
    }

    return 0;
}
