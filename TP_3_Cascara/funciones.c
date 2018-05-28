#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/** \brief Inicializa el array de estructuras Person
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

/** \brief Agrega una referencia a una struct Person al array
 *  \param Person p : Puntero a estructura Person
 *  \return void
 */
void list_addMovie(MovieList* pl, EMovie* p)
{
    pl->movie[pl->index]=p; // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
    pl->index++;
// si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(pl->index>=pl->listSize)
    {
      printf("no hay mas lugar, redefinimos el array\r\n");
      pl->listSize+=2; // agregamos dos mas
      pl->movie = (EMovie**)realloc(pl->movie,sizeof(EMovie*)*pl->listSize);
    }

}

/** \brief Crea una estructura del tipo Person en forma dinámica
 * \return Devuelve un puntero a la estructura creada
 */
EMovie* list_newMovie(void)
{
    EMovie* p = (EMovie*)malloc(sizeof(EMovie)); // creamos una estructura Person de forma dinámica
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




/** \brief Pide al usuario que se ingresen los datos de una persona y los carga en una estructura pasada por referencia.
 * \param Person p : Puntero a estructura Person
 * \return 1 si se ingreso salir, de lo contrario 0
 */
int list_enterMovie(EMovie* p)
{
        printf("Ingrese el Titulo:");
        fflush(stdin);
         gets(p->titulo);
         printf("Ingrese id:");
         scanf("%d",&p->id);
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

        p->estado=1;


     return 0;
}

int list_modicaMovie(EMovie* p,MovieList* p1)
{
    int auxid,existe,salir=0;
    char confirma;

    printf("Ingrese el id de la pelicula que desa modificar\n");
    scanf("%d",&auxid);
        existe=buscarPorid(p,list_getSize(p1),auxid);
        if(existe==-1)
        {
            printf("No se ah encontrado el id");
        } else{
                        list_printMovie(p+existe);
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

            }
            else{
                printf("\nSe ha cancelado la baja\n\n");
                system("pause");
            }

        }




     return 0;
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
    int i;
    printf("Titulo:\t%s Genero: \t%s Descripcion:\t%s Puntaje:\t %d\tduracion:%d\r\n",p->titulo,p->genero,p->descripcion,p->puntaje,p->duracion);

}

int buscarPorid(EMovie* listaDato, int tam,int id)
{
    int aux=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if((listaDato+i)->id==id && (listaDato+i)->estado==1)
        {
            aux=i;
            break;
        }
    }

    return aux;
}

void leeArchivo(FILE* archivo, EMovie* lista)
{
    EMovie auxlista;
    int i=0,cantidad;
    archivo= fopen("ListaBinaria.bin","rb");

    if(archivo==NULL)
    {
        archivo= fopen("ListaBinaria.bin","wb");

        if(archivo==NULL)
        {
            printf("ERROR en archivo!!!!!");
            getch();
        }
    }

    else
    {
        rewind(archivo);
        i=0;
        while(!feof(archivo))
        {
            fflush(stdin);
            cantidad= fread(&lista[i], sizeof(EMovie), 1, archivo);
            //lista[i]=auxlista;
            i++;
            if(cantidad!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
					break;
                }
            }
        }
    }
    fclose(archivo);
}

void escribeArchivo(FILE* archivo, EMovie* lista,MovieList* p1)
{
    EMovie auxlista;
    int i=0;

        archivo= fopen("ListaBinaria.bin","wb");

        if(archivo==NULL)
        {
            printf("ERROR en archivo!!!!!");
            getch();
        }

        else
        {
            for(i=0;i<list_getSize(p1);i++)
            {
                if( (lista+i)->estado==1)
                {
                    fseek(archivo , 0L, SEEK_END);
                    fflush(stdin);
                    fwrite(&lista[i], sizeof(EMovie), 1, archivo);
                }
            }
        }
        fclose(archivo);
}

void iniciaArchivoHtml(EMovie* lista, MovieList* p1)
{
    FILE* archivoHtml;
    int i;

    archivoHtml= fopen("ListaPeliculas.html","w");

    if (archivoHtml== NULL)
    {
            printf("No se pudo abrir el archivo");
    }
    else
    {
            for(i=0;i<list_getSize(p1);i++)
            {
                if( (lista+i)->estado==1)
                {
                    fprintf(archivoHtml,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul>                <p>%s.</p></article>",(lista+i)->linkImagen,(lista+i)->titulo,(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion,(lista+i)->descripcion);
                }
            }
    }
    fclose(archivoHtml);

    printf(" \t ARCHIVO HTML GENERADO CON EXITO!!");
    getch();
}
