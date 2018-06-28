#include "funciones.h"
#include <stdio.h>
#include <string.h>

void inicializar(eMovie* movie, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        strcpy((movie+i)->titulo," ");
        strcpy((movie+i)->genero," ");
        (movie+i)->duracion=0;
        strcpy((movie+i)->descripcion," ");
        (movie+i)->puntaje=0;
        strcpy((movie+i)->linkimagen," ");
    }
}

int addMovie(eMovie* movie, int tam)
{
    int buscarLibre;

    buscarLibre = buscarLugarLibre(movie, tam);

    if(buscarLibre >= 0)
    {

        printf("Ingrese titulo: ");
        fflush(stdin);
        gets((movie+buscarLibre)->titulo);

        printf("Ingrese genero: ");
        fflush(stdin);
        gets((movie+buscarLibre)->genero);


        printf("Ingrese duracion: ");
        scanf("%d",&(movie+buscarLibre)->duracion);

        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets((movie+buscarLibre)->descripcion);


        printf("Ingrese puntaje: ");
        fflush(stdin);
        scanf("%d", &(movie+buscarLibre)->puntaje);


        printf("Ingrese link de imagen: ");
        fflush(stdin);
        gets((movie+buscarLibre)->linkimagen);
    }
    else
    {
        printf("No hay lugar disponible\n");
    }

}

int fileUpload(eMovie* movie,int tam)
{
    int flag = 0;

    FILE *archivo;

    archivo = fopen("archivo.bin", "rb");

    if(archivo == NULL)
    {
        archivo = fopen("archivo.bin", "wb");

        if(archivo == NULL)
        {
            return 1;
        }

        flag = 1;
    }

    if(flag ==0)
    {
        fread(movie,sizeof(eMovie),tam,archivo);
    }
    fclose(archivo);

    return 0;
}

int deleteMovie(eMovie* movie, int tam)
{
    char opcion;
    int aux;
    char auxchar[100];

    printf("Seleccione pelicula a eliminar: \n");
    fflush(stdin);
    gets(auxchar);

    aux = buscarMovie(movie,auxchar,tam);
    printMovie(movie+aux);
    printf("Esta seguro que desea eliminar? (S/N): \n");

    fflush(stdin);
    opcion=getchar();
    opcion = tolower(opcion);
    if(opcion == 's')
    {
        strcpy((movie+aux)->titulo,"");
        strcpy((movie+aux)->genero,"");
        (movie+aux)->duracion=0;
        strcpy((movie+aux)->descripcion,"");
        (movie+aux)->puntaje=0;
        strcpy((movie+aux)->linkimagen,"");

        printf("Eliminacion exitosa \n");
        system("pause");
    }



}

int modificarPelicula(eMovie* movie, int tam)
{
    char opcion;
    int aux;
    char auxchar[100];

    printf("Seleccione pelicula a eliminar: \n");
    fflush(stdin);
    gets(auxchar);

    aux = buscarMovie(movie,auxchar,tam);
    printMovie(movie+aux);
    printf("Desea modificar esta pelicula? (S/N)\n");

    fflush(stdin);
    opcion=getchar();
    opcion = tolower(opcion);
    if(opcion == 's'){

            switch(menuModifica())
            {
            case 1:
            {
                printf("Ingrese nuevo titulo: ");
                fflush(stdin);
                gets((movie+aux)->titulo);
            }
            break;
            case 2:
            {
                printf("Ingrese nuevo genero: ");
                fflush(stdin);
                gets((movie+aux)->genero);
            }
            break;
            case 3:
                    printf("Ingrese nueva duracion: ");
                    fflush(stdin);
                    scanf("%d", &(movie+aux)->duracion);

            break;
            case 4:
            {
                printf("\n\nIngrese nueva descripcion:\n ");
                fflush(stdin);
                gets((movie+aux)->descripcion);
            }
            break;
            case 5:

                    printf("Ingrese puntaje: ");
                    fflush(stdin);
                    scanf("%d", &(movie+aux)->puntaje);

            break;
            case 6:
            {
                printf("Ingrese nuevo link de la imagen: ");
                fflush(stdin);
                gets((movie+aux)->linkimagen);
            }
            break;
            case 7:
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
            }

    }
}

int menuModifica()
{
    int opcion;

    printf("MENU MODIFICAR\n");
    printf("1. Titulo\n");
    printf("2. Genero\n");
    printf("3. Duracion\n");
    printf("4. Descripcion\n");
    printf("5. Puntaje\n");
    printf("6. Link de imagen\n");
    printf("7. Cancelar\n");


    scanf("%d",&opcion);

    return opcion;
}


int buscarLugarLibre(eMovie* movie, int tam)
{
    int lugarLibre=-1;
    int i;
    for( i=0; i < tam; i++)
    {
        if((movie+i)->duracion==0)
        {
            lugarLibre=i;
            break;
        }
    }

    return lugarLibre;
}

int printMovies(eMovie* movie,int tam)
{
    int i, ret=0;

    printf("Titulo\t *Genero\t *Duracion\t *Puntaje\n");

    for(i=0; i<tam; i++)
    {
        if((movie+i)->duracion > 0)
        {
            printf("\t%s\t%s\t%d\t%d\n",(movie+i)->titulo, (movie+i)->genero,(movie+i)->duracion,(movie+i)->puntaje);
        }
    }
    return ret;
}

void printMovie(eMovie* movie)
{

    printf("\t%s\t%s\t%d\t%d\n",movie->titulo, movie->genero, movie->duracion, movie->puntaje);

}


int guardarArchivo(eMovie* movie,int tam)
{
    int flag= 0;

    FILE *archivo;

    archivo=fopen("archivo.bin","wb");

    if(archivo == NULL)
    {
        flag=1;
    }
    else
    {
        fwrite(movie,sizeof(eMovie),tam,archivo);
        fclose(archivo);
        flag=0;
    }

    return flag;
}

void generarPagWeb(eMovie* movie,int tam)
{
    int i;

    FILE* archivo;

    archivo = fopen("Peliculas.html", "w");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        for(i=0; i<tam; i++)
        {
            fprintf(archivo,"<article class='col-md-4 article-intro'>\n<a href='#'>\n");

            fprintf(archivo,"<img class='img-responsive img-rounded' src='");

            if((movie+i)->duracion > 0)
            {
                fprintf(archivo,"%s'\nalt=''>\n </a>\n <h3>\n <a href='#'>", (movie+i)->linkimagen);
                fprintf(archivo,"%s</a>\n </h3>\n<ul>\n<li>", (movie+i)->titulo);
                fprintf(archivo,"Genero: %s</li>\n<li>", (movie+i)->genero);
                fprintf(archivo,"Puntaje: %d</li>\n<li>", (movie+i)->puntaje);
                fprintf(archivo,"Duracion: %d</li>\n</ul>\n <p>", (movie+i)->duracion);
                fprintf(archivo,"%s</p>\n</article>\n", (movie+i)->descripcion);
            }

        }
    }

    fclose(archivo);
    printf("HTML creado\n");
}

int lugarLibre(eMovie* movie,int tam)
{
    int i;
    int ret=-1;

    for(i=0; i<tam; i++)
    {
        if(((movie+i)->duracion)!=0)
        {
            ret=1;
            break;
        }
    }
    return ret;
}

int buscarMovie(eMovie* movie, char* titulo, int tam)
{
    int i;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(strcmp((movie+i)->titulo, titulo)==0)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}



