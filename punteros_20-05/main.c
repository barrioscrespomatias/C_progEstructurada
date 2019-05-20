#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;

} eDato;


void mostrarNumeros(eDato *info, int tamanio);
int ordenarPorLetras(eDato *info, int tamanio);



int main()
{
    eDato muchosDatos[3] = {{1,'X'},{2,'A'},{3,'C'}};
    int estado;

    estado = ordenarPorLetras(muchosDatos,3);
    if(estado == 0)
    {
        mostrarNumeros(muchosDatos,3);
    }
    else

    {
        printf("Algo fallo");
    }



//    eDato *pDato  = NULL;
//
//    pDato = muchosDatos;




//    if(pDato!=NULL)
//        mostrarNumeros(pDato, 3);






//    int i;
//    for(i=0; i<3; i++)
//    {
//        printf("%d--%c\n", (*(pDato+i)).numero,(*(pDato+i)).letra);
//
//        printf("%d--%c\n", (pDato+i)->numero, (pDato+i)->letra);
//        printf("%d--%c\n", pDato[i].numero, pDato[i].letra);
//
//    }
//
//    printf("%d",(*pDato).numero);
//    printf("%d--%c", pDato->numero, pDato->letra); // Igual anterior.
//    //Flecha ingresa a la estructura y me permite no utilizar punto ni *. Mas limpio utilizar el operador flecha.




    return 0;
}

void mostrarNumeros(eDato *info, int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        printf("%d--%c\n", (info+i)->numero, (info+i)->letra);
    }
}

int ordenarPorLetras(eDato *info, int tamanio)
{
    int i;
    int r;
    int esNull = 1;
    eDato auxiliar;

    if(info!= NULL)
    {
        for(i=0; i<tamanio; i++)
        {
            for(r=i+1; r<tamanio; r++)
            {
                if((info+i)->letra > (info+r)->letra)
                {
                    auxiliar = *(info+i);
                    *(info+i) = *(info+r);
                    *(info+r) = auxiliar;


//                    (info+i)->letra = (info+r)->letra;
//                    (info+r)->letra = (auxiliar+i)->letra;
//                    (auxiliar+i)->letra = (info+i)->letra;
                }


            }
        }

        esNull = 0;

    }

    return esNull;


}
