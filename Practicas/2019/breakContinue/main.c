#include <stdio.h>
#include <stdlib.h>


int sumar(int * primero, int * segundo);

int main()
{
//    int nro1 = 11;
//    int nro2=1;
//    int resultado;
//    int i;
//    int contadorPares = 0;
//    int numeros[10] =
//    {
//        1,2,3,4,5,6,7,8,9,0
//    };
//
//    resultado = sumar(&nro1, &nro2);
//
//    printf("%d",resultado);
//
//

    int contador = 0;
    int vector[10];
    int x = 1;
    for(x=1; x<=10; x++)
        {
            vector[x] = 23;
            printf("Posicion = %d    Numero: %d\n",contador, vector[x]);

            contador++;

           // Error es que un elemento del vector, no va a ser cargado ya
           //los elementos son consecutivos empezando en la posicion 0.
           // x comienza a cargar a partir de la posicion 1.

        }




//    for (i=0; i<10;i++)
//    {
//        if(numeros[i]%2 == 0 && numeros[i]!= 0)
//        {
////            contadorPares++;
//            contadorPares = numeros[i];
//            printf("El primer numero par es: %d\n",contadorPares);
//            break;
//        }
//    }

//    printf("Los numeros pares son : %d\n",contadorPares);



    return 0;


}


int sumar(int * primero, int * segundo)
{
    int total;


    total = *(primero)+*(segundo);

    return total;
}
