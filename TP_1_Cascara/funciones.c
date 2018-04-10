 /** \brief esta funcion realiza la suma de dos numeros
*
* \param n1 es un numero
* \param n2 es un numero
* \return devuelve la suma de los valores de n1 y n2
*/
int suma(int n1, int n2){
    int resultado;

    resultado= n1 + n2;
  return resultado;
}
 /** \brief esta funcion realiza la multiplicacion de dos numeros
*
* \param n1 es un numero
* \param n2 es un numero
* \return devuelve la multiplicacion de los valores de n1 y n2
*/
int multiplicacion(int n1,int n2){
int resultado;
resultado=n1*n2;
return resultado;
}
 /** \brief esta funcion realiza la resta de dos numeros
*
* \param n1 es un numero
* \param n2 es un numero
* \return devuelve la resta de los valores de n1 y n2
*/

int resta(int n1, int n2){
   int resultado;
   resultado=n1-n2;
   return resultado;
}
 /** \brief esta funcion realiza la division de dos numeros
*
* \param n1 es un numero
* \param n2 es un numero
* \return devuelve el cociente de los valores de n1 y n2
*/
float division(float n1, float n2){
    float resultado;
     while(n2==0){
                    printf("ERROR, no es posible la division por cero \n");
                    printf("Ingrese el segundo operando\n ");

                    scanf("%f",&n2);
                }
    resultado=n1/n2;
    return resultado;
}
 /** \brief esta funcion realiza el factorial de un numero entero
*
* \param n1 es un numero entero
* \return devuelve el factorial del valor numerico de n1
*/
int factorial(int valor){
int resultado=1 ,i;
     if(valor<0){
                    printf("Error, el factorial de un numero negativo no existe \n");
                    system("pause");
                }


for(i=valor; i>0; i--){
        resultado = resultado * i;
        }
 return resultado;
}

