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

MovieList* list_initMovieList(void);
EMovie* list_get(MovieList* pl,int i);
int list_getSize(MovieList* pl);
int list_getid(EMovie* Movie);
void list_addMovie(MovieList* pl, EMovie* p);
EMovie* list_newMovie(void);
void list_free(MovieList* pl);
void list_remove(MovieList* pl,int indexToDelete);
int list_enterMovie(EMovie* p,MovieList* P1,char titulo[]);
int list_modicaMovie(EMovie* p,MovieList* p1,int existe);
void list_printMovie(EMovie* p);
void list_printMovies(EMovie* p,MovieList* p1);
void list_printMoviesName(EMovie* p,MovieList* p1,int existe);
int buscarPorNombre(EMovie* p, MovieList* p1,char titulo[]);
void list_printHtlm(EMovie* p,FILE* parch);




















#endif // FUNCIONES_H_INCLUDED
