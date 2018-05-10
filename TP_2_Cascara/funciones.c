
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Recorre el array colocando cero estado
 *
 * \param Array
 * \param Tamaño del array
 */

void inicializarLibre(ePersona vec[] , int tam)
{
    int i;
    for(i=0 ; i < tam ; i++)
    {
        vec[i].estado = 1;
    }
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int tam){

  int i;
    int espacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(lista[i].estado == 1)
        {
            espacio = i;
            break;
        }
    }
    return espacio;
}

/** \brief Recorre el vector e imprime los datos cargados
 *
 * \param vec Vector a recorrer
 */
void mostrarDato(ePersona vec)
{
    printf("Nombre:\tDni:\tEdad:\n");
    printf("%s\t%d\t%d\n" , vec.nombre ,vec.dni , vec.edad);

}


/** \brief Recorre el vector y pregunta por el estado para imprimir solo los datos que esten cargados sin basura
 * \param vec Vector a recorrer
 * \param tam tamaño del vactor
 */

void mostrarPersonas(ePersona vec[] , int tam)
{
    ordenarPorNombre(vec , tam);
    int i;
    printf("Nombre:\tDni:\tEdad:\n");
    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado == 0)
        {

            printf("%s\t%d\t%d\n" , vec[i].nombre ,vec[i].dni , vec[i].edad);
        }
    }
}
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona vec[],int tam, int dni)
{
      int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].estado ==0 && dni==vec[i].dni)
        {
            indice = i;
            break;
        }
    }
    return indice;


}
/** \brief  compara los nombres y los ordena en orden alfabetico
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vactor
 *
 */


void ordenarPorNombre(ePersona vec[] , int tam)
{
    int i;
    int j;
    ePersona aux;

    //printf("Dni:\tNombre:\tEdad:\n");
    for(i=0 ; i < tam-1 ; i++)
    {
        for(j=i+1 ; j < tam ; j++)
        {
            if((strcmp(vec[i].nombre,vec[j].nombre) > 0))
            {
                aux= vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }


}
/** \brief Pide los datos a ser cargados
 *
 * \param Vector donde guardo los datos
 * \param Tamaño del vactor
 * \return
 *
 */
void agregarPersona(ePersona vec[], int tam)
{

    ePersona nuevaPersona;
    int indice;
    int existe;
    long int dni;


    system("cls");
    printf("---Agregar persona---\n\n");

    indice = obtenerEspacioLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese DNI: ");
         fflush(stdin);
        scanf("%d", &dni);
        existe = buscarPorDni(vec, tam, dni);

        if(existe != -1)
        {
            printf("\nEl DNI %d ya esta dado de alta en el sistema\n", dni);
                   mostrarDato(vec[existe]);
                   system("pause");
        }
       else{
                   nuevaPersona.estado = 0;
                   nuevaPersona.dni = dni;

                   printf("Ingrese nombre: ");
                   fflush(stdin);
                   gets(nuevaPersona.nombre);

                   printf("Ingrese edad: ");
                   fflush(stdin);
                   scanf("%d", &nuevaPersona.edad);
                   while(nuevaPersona.edad <=0){
                    printf("ERROr,Reingrese edad: ");
                   fflush(stdin);
                   scanf("%d", &nuevaPersona.edad);
                   }
                   vec[indice] = nuevaPersona;

                   printf("\nAlta exitosa!!!\n\n");
                    system("\npause\n");

           }

  }

}

/** \brief Busca el DNI del usuario y cambia el estado para pisar sus datos
 *
 * \param vec vector que pasamos por parametro
 * \param tam tamaño del vector
 *
 */
void borrarPersona(ePersona vec[], int tam){
int dni;
int existe;
char confirma;
ePersona nuevapersona;

system("cls");
printf("---Borrar persona---\n\n");

   printf("Ingrese DNI: ");
        scanf("%d", &dni);

        existe = buscarPorDni(vec, tam, dni);

        if(existe == -1)
        {
            printf("\nEl DNI %d no se encuentra en el sistema\n\n", dni);
            system("pause");

        }
        else{

                mostrarDato(vec[existe]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){

            vec[existe]

            .estado = 1;
            printf("\nSe ha realizado la baja\n\n");
            system("pause");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
            system("pause");
        }

        }
}
/** \brief Imprime un * por cada rango de edad
 *
 * \param vec Vector a recorrer
 * \param tam Tamaño del vector
 *
 */

void mostrarGrafico(ePersona vec[],int tam){

  int i,r;
  int mayor;
  int flag=0;
  int  rango1=0;
  int  rango2=0;
  int  rango3=0;


  printf("\n***GRAFICO DE EDADES***\n");

  for(i=0 ; i < tam ; i++){

      if(vec[i].edad<18 && vec[i].estado==0){
        rango1++;
      }
      if(vec[i].edad >17 && vec[i].edad <= 35 && vec[i].estado==0){
        rango2++;
      }
      if(vec[i].edad >35 && vec[i].estado==0){
        rango3++;
      }
    }

     if(rango1 >= rango2 && rango1 >= rango3){
        mayor = rango1;
    }else{
        if(rango2 >= rango1 && rango2 >= rango3)
        {
            mayor = rango2;
        }
        else{
        mayor = rango3;
        }
    }
  for(i=mayor; i>0; i--){
        if(i<= rango1){
            printf("*");
        }
        if(i<= rango2){
            flag=1;
            printf("\t*");
        }
        if(i<= rango3){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }

    printf("<18\t19-35\t>35\n");

}



