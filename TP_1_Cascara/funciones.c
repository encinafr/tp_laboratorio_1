//esta funcion suma dos numeros
int suma(int n1, int n2){
    int resultado;

    resultado= n1 + n2;
  return resultado;
}
//esta funcion realiza la multiplicacion de dos numeros
int multiplicacion(int n1,int n2){
int resultado;
resultado=n1*n2;
return resultado;
}
//esta funcion realiza la resta de dos numeros
int resta(int n1, int n2){
   int resultado;
   resultado=n1-n2;
   return resultado;
}
//esta funcion realizala division de dos numeros
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
//esta funcion calcula el factorial de un numero
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

