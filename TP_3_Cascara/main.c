#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 2
int main()
{
    MovieList* pl = list_initMovieList();
    EMovie* p = list_newMovie(); // creamos una estructura Person de forma dinámica
    int i,existe,cont,agregar,modificar;
    char tituloaux[100];
    char confirma;
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
                p = list_newMovie();
                printf("Ingrese el titulo de la pelicula: ");
                  fflush(stdin);
                gets(tituloaux);
                existe=buscarPorNombre(p,pl,tituloaux);
                if(existe==-1)
                {
                     agregar=list_enterMovie(p,pl,tituloaux);
                     list_addMovie(pl,p);
                }
                 if(agregar==1){
                    printf("La pelicula fue agregada correctamente\n");
                    system("pause");
                 }else{
                     printf("No se pudo agregar la pelicula\n");
                      system("pause");
                 }

                break;
            case 2:
                 printf("Ingrese el titulo de la pelicula que desa eliminar: ");
                   fflush(stdin);
                 gets(tituloaux);
                 existe = buscarPorNombre(p,pl,tituloaux);
                 if(existe==-1)
                 {
                     printf("no se encontro l pelicula.");
                     system("pause");
                 }else{
                   list_printMoviesName(p,pl,existe);
                        do{
                    printf("\nConfirma Modificacion? [s|n]: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                    }while(confirma != 's' && confirma != 'n');
                 }
                 if(confirma=='s')
                 {
                     list_remove(pl,existe);
                     printf("Pelicula eliminada\n");
                     system("pause");
                 }else{

                    printf("Se cancelo la accion\n");
                    system("pause");
                 }



                break;
            case 3:
                printf("Ingrese el titulo de la pelicula que desa modificar: \n");
                fflush(stdin);
                gets(tituloaux);
                existe=buscarPorNombre(p,pl,tituloaux);
                if(existe==-1)
                {
                    printf("No se ah encontrado la pelicula");
                } else{
                        list_printMoviesName(p,pl,existe);

                    modificar = list_modicaMovie(p,pl,existe);
                    }
                    if(modificar==1){
                            printf("La moficacion se a realizado correctamente\n");
                            system("pause");
                        iniciaArchivoHtml(p,pl);
                    }else{
                        printf("No se a realizado la modificaion");
                     system("pause");
                    }

               break;
            case 4:
                iniciaArchivoHtml(p,pl);
               break;
            case 5:
                list_printMovies(p,pl);
               /*  for(i=0; i<list_getSize(pl);i++){
                    if(p->estado=1){
                        list_printMovie(list_get(pl,i));
                }
               }*/
               cont=list_getSize(pl);
               printf("La cantidad de peliculas agregadas es %d:",cont);
               system("pause");
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
