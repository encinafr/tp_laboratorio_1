#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float n1;
    float n2;
    float resultado;


    while(seguir=='s')

    {
        system("cls");

        printf("1- Ingresar 1er numero (A=%.f)\n",n1);
        printf("2- Ingresar 2do numero (B=%.f)\n",n2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                printf("Ingrese el primer operando \n");
                scanf("%f",&n1);

                break;

            case 2:
                printf("Ingrese el segundo operando\n ");
                scanf("%f",&n2);
                break;
            case 3:
                resultado=suma(n1,n2);
                printf("La suma es: %.0f \n",resultado);
                system("pause");

                break;
            case 4:
                resultado=resta(n1,n2);
                printf("La resta es: %.0f \n", resultado);
                system("pause");
                break;
            case 5:
                while(n2==0){
                    printf("ERROR, no es posible la division por cero \n");
                    printf(" Ingrese el segundo operando\n ");
                    scanf("%f",&n2);
                }
                resultado= division(n1,n2);
                printf("El resultado de la division es %.2f \n ",resultado);
                system("pause");
                break;
            case 6:
                resultado=multiplicacion(n1,n2);
                printf("El resultado de la multiplicacion es: %.0f \n " , resultado);
                system("pause");
                break;
            case 7:
                if(n1>=0){
                resultado= factorial(n1);
                printf("El factorial del numero ingresado es: %.0f \n",resultado);
                system("pause");
                 }else{
                     resultado= factorial(n1);
                 }
                break;
            case 8:
                resultado=suma(n1,n2);
                printf("La suma es: %.0f \n",resultado);

                resultado=resta(n1,n2);
                printf("La resta es: %.0f \n", resultado);

                resultado= division(n1,n2);
                printf("El resultado de la division es: %.2f\n ",resultado);

                resultado=multiplicacion(n1,n2);
                printf("El resultado de la multiplicacion es: %.0f\n " , resultado);

                if(n1>=0){
                resultado= factorial(n1);
                printf("El factorial del numero ingresado es: %.0f\n",resultado);
                system("pause");
                 }else{
                     resultado= factorial(n1);
                 }

                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("A ingresado una opcion incorrecta \n");
                system("pause");
        }

    }


    return 0;
}
