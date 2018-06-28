#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define TAM 50

int main()
{
    char seguir='s';

    int opcion=0;

    eMovie* movie;
    eMovie pelicula[TAM];

    movie = &pelicula;

    inicializar(movie,TAM);

    if(!fileUpload(movie, TAM))
	{
	    printf("Archivo cargado\n\n");
	}
	else
	{
		printf("No se pudo abrir el archivo\n");
	}


    while(seguir=='s')
    {
        system("cls");
        printf("---MENU---\n\n");
        printf("1. Agregar pelicula\n");
        printf("2. Modificar pelicula\n");
        printf("3. Borrar pelicula\n");
        printf("4. Generar pagina web\n");
        printf("5. Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                addMovie(movie,TAM);
                break;
            case 2:
                modificarPelicula(movie,TAM);
                break;
            case 3:
                deleteMovie(movie,TAM);
               break;
            case 4:
                generarPagWeb(movie,TAM);
                guardarArchivo(movie,TAM);
                break;
            case 5:
				seguir='n';
                break;
        }
    }

    return 0;
}
