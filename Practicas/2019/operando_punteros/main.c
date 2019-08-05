#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[50];
    int numero;
}ePersonas;



int main()
{
    int i;
    ePersonas lista[2];

    ePersonas unaPersona = {"Matute",1};
    ePersonas dosPersona = {"Juliana",2};

    for(i=0 ; i<2; i++)
    {
        lista[i] = unaPersona;

    }

    printf("%s %d\n",lista[1].nombre, lista[1].numero);


//    {
//        {"Matute",1}
////        {"Juliana",2},
////        {"Tomas",3},
//    };

    int numeros[10] = {0,-2,2,3,99,5,6,7,8,22};
    int *p;

    p=numeros;
    p++;
    p++;



//    printf("%d\n",*(numeros+4) );

//    printf("%d\n",p[0] );


    return 0;
}
