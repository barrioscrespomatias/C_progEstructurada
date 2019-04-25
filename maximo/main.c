#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numeros[6] = {10,-2000,-20,50,100,-1000};

    int maximo;

    int i;
    int flag = 0;


    for(i=0; i<6;i++)
    {
        if(flag == 0 || numeros[i]>maximo)
        {
            maximo = numeros[i];
            flag = 1;
        }
    }

     printf("%d\n",maximo);
    system("pause");



    return 0;
}
