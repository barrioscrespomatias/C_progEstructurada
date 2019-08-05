#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../../../primercuatri_2019/biblioteca_UTN/utn.h>

int main()
{

    char respuesta [10] = "si";
    int numero;



    while(strcmp(respuesta, "si") == 0)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",&numero);

        printf("Quiere ingresar otro?\n");
        scanf("%s",respuesta);

        if(strcmp(respuesta,"si")!=0)
        {
            printf("Esta seguro que no desea cargar mas datos?: \n");
            scanf("%s",respuesta);

            if(strcmp(respuesta,"si")== 0)
            {
                break;
            }
            else
            {
                strcpy(respuesta,"si");
            }
        }
    }



    return 0;
}
