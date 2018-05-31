#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/** \brief Inicializa el array de estructuras
 * \return void
 */
MovieList* list_initMovieList(void)
{
    MovieList* pl = (MovieList*)malloc(sizeof(MovieList)); // creamos una estructura que contiene las variables que antes eran globales

    pl->index=0;
    pl->listSize=2;
    pl->movie = (EMovie*)malloc(sizeof(EMovie*)*pl->listSize); // Ahora cada item del array es un puntero a una estructura

    return pl;
}
EMovie* list_get(MovieList* pl,int i)
{
    if(i<pl->index)
        return pl->movie[i];

    return NULL;
}
int list_getSize(MovieList* pl)
{
    return pl->index;
}
// A partir de aca, todas las funciones que interactuaban con la lista (que era global) ahora reciben como primer argumento, la struct PeopleList
//***********************************************************************************************************************************************
int list_getid(EMovie* Movie)
{
 return Movie->id;
}


void list_addMovie(MovieList* pl, EMovie* p)
{
    pl->movie[pl->index]=p; // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
    pl->index++;
// si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(pl->index>=pl->listSize)
    {
     // printf("no hay mas lugar, redefinimos el array\r\n");
      pl->listSize+=2; // agregamos dos mas
      pl->movie = (EMovie**)realloc(pl->movie,sizeof(EMovie*)*pl->listSize);
    }

}

/** \brief Crea una estructura del tipo EMovie en forma dinámica
 * \return Devuelve un puntero a la estructura creada
 */
EMovie* list_newMovie(void)
{
    EMovie* p = (EMovie*)malloc(sizeof(EMovie));
    return p;
}




/** \brief Libera la memoria pedida para crear el array
 * \return void
 */
void list_free(MovieList* pl)
{
    free(pl->movie);
}



/** \brief Elimina un item del array
 * \param indice a borrar
 * \return void
 */
void list_remove(MovieList* pl,int indexToDelete)
{
    int i;
    if(pl->index!=0 && indexToDelete<pl->index)
    {
        for(i=indexToDelete ; i<(pl->index-1); i++)
        {
            pl->movie[i] = pl->movie[i+1];
        }
        pl->index--;
    }
}




/** \brief Pide al usuario que se ingresen los datos de una pelicula y los carga en una estructura pasada por referencia.
 * \param Person p : Puntero a estructura Person
 * \return 1 si se ingreso salir, de lo contrario 0
 */
int list_enterMovie(EMovie* p,MovieList* P1,char titulo[])
{
    int realizado=0;
    int existe;


             p->estado=1;

             strcpy(p->titulo,titulo);

             printf("Ingrese Genero:");
             fflush(stdin);
             gets(p->genero);
             printf("Ingrese Descripcion:");
             fflush(stdin);
             gets(p->descripcion);
             printf("Ingrese la duracion:");
             scanf("%d",&p->duracion);
              printf("Ingrese el puntaje:");
             scanf("%d",&p->puntaje);
             printf("Ingrese link de imagen:");
            fflush(stdin);
             gets(p->linkImagen);

            realizado=1;

 return realizado;
}

int list_modicaMovie(EMovie* p,MovieList* p1,int existe)
{
    int realizado=0;
    int salir=0;
    char confirma;
      do{
                    printf("\nConfirma Modificacion? [s|n]: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                }while(confirma != 's' && confirma != 'n');

            if(confirma == 's'){
                     do{
                switch(menuModifica()){
                    case 1:
                        printf("Ingrese nuevo el Titulo:");
                        fflush(stdin);
                        gets((p+existe)->titulo);
                        break;
                    case 2:
                          printf("Ingrese nuevo id:");
                         scanf("%d",&(p+existe)->id);
                        break;
                    case 3:
                        printf("Ingrese nuevo Genero:");
                        fflush(stdin);
                        gets((p+existe)->genero);
                      break;
                     case 4:
                         printf("Ingrese nueva Descripcion:");
                         fflush(stdin);
                         gets((p+existe)->descripcion);
                         break;
                     case 5:
                         printf("Ingrese nueva duracion:");
                         scanf("%d",&(p+existe)->duracion);
                         break;
                     case 6:
                         printf("Ingrese nuevo puntaje:");
                        scanf("%d",&(p+existe)->puntaje);
                        break;
                     case 7:
                        salir = 1;
                        break;
                    default:
                        printf("Opcion incorrecta");
                        system("pause");

                    }

        }while(salir != 1);
            p->estado=1;
            realizado=1;
        }

    return realizado;
  }


int menuModifica()
{
    int opcion;

    system("cls");
    printf("---Modificar Pelicula---\n\n");
    printf("1-TITULO\n");
    printf("2-ID\n");
    printf("3-GENERO\n");
    printf("4-DESCRIPCION\n");
    printf("5-DURACION\n");
    printf("6-PUNTAJE\n");
    printf("7-SALIR\n");
    printf("\nIndique opcion a modificar: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief Imprime los datos de una estructura Person
 * \param Person p : Puntero a estructura Person
 * \return void
 */
void list_printMovie(EMovie* p)
{
    printf("Titulo:\t%s Genero: \t%s Descripcion:\t%s Puntaje:\t %d\tduracion:\t%d\r\n",p->titulo,p->genero,p->descripcion,p->puntaje,p->duracion);

}
void list_printMovies(EMovie* p,MovieList* p1)
{
    int i;
    for(i=0; i<list_getSize(p1);i++){
                    if(p->estado==1){
                        list_printMovie(list_get(p1,i));
                }
               }
}
void list_printMoviesName(EMovie* p,MovieList* p1,int existe)
{
    int i;
    for(i=0; i<list_getSize(p1);i++){
                    if(p->estado==1 && existe==i){
                        list_printMovie(list_get(p1,i));
                }
               }
}
int buscarPorNombre(EMovie* p, MovieList* p1,char titulo[])
{
    int aux=-1;
    int i;
    for(i=0; i<list_getSize(p1);i++){
                    if(p->estado==1 && strcmp(p->titulo,titulo)==0){
                        //list_printMovie(list_get(p1,i));
                        aux=i;
                }
               }

    return aux;
}


void list_printHtlm(EMovie* p,FILE* parch)
{
    fprintf(parch,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul>                <p>%s.</p></article>",p->linkImagen,p->titulo,p->genero,p->puntaje,p->duracion,p->descripcion);

}
void list_printBinario(EMovie* p,FILE* parch){

        fseek(parch , 0L, SEEK_END);
        fflush(stdin);
        fwrite(&p, sizeof(EMovie), 1,parch);
}

void list_readMovie(EMovie* p,FILE* parch)
{
        fread(&p, sizeof(EMovie*), 1, parch);
}
