#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 2
int main()
{
    MovieList* pl = list_initMovieList();
    EMovie* p = list_newMovie(); // creamos una estructura Person de forma dinámica
    int i,id,existe;
    FILE* archivo;
    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        system("cls");
        printf("\n******PELICULAS******\n\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
                p = list_newMovie();
                list_enterMovie(p);
                 list_addMovie(pl,p);
                system("pause");
                break;
            case 2:
                 printf("Ingrese el id de la pelicula que desa eliminar");
                 scanf("%d",&id);
                 existe = buscarPorid(p,list_getSize(pl),id);
                list_remove(pl,existe);


                break;
            case 3:
               list_modicaMovie(p,pl);
               iniciaArchivoHtml(p,pl);
               system("pause");
               break;
            case 4:
                iniciaArchivoHtml(p,pl);
               break;
            case 5:
                 for(i=0; i<list_getSize(pl);i++){
                    if(p->estado=1){
                        list_printMovie(list_get(pl,i));
                }
               }
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta\n");
                system("pause");
        }
    }



    list_free(pl);

    return 0;
}
