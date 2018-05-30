#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[200];
    char genero[200];
    int duracion;
    int estado;
    int id;
    char descripcion[300];
    int puntaje;
    char linkImagen[100];
}EMovie;

typedef struct
{
    int listSize;
    EMovie** movie;
    int index;
}MovieList;

//int buscarPorid(EMovie* p, int tam,int id);

int list_enterMovie(EMovie* p,MovieList* P1,char titulo[]);
void list_printMovie(EMovie* p);
int list_getSize(MovieList* pl);
EMovie* list_get(MovieList* pl,int i);



MovieList* list_initMovieList(void);
void list_addMovie(MovieList* pl, EMovie* p);
EMovie* list_newMovie(void);

EMovie* list_get(MovieList* pl,int i);
void list_free(MovieList* pl);

void list_remove(MovieList* pl,int indexToDelete);




/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */



#endif // FUNCIONES_H_INCLUDED
