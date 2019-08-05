#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int primera;
    int segunda;
    int tercera;
    int cierre;
} eNotas;





int main()
{
    eNotas * listaNotasAlumnos;
    int i;
    int bandera = 0;
    int contador = 0;

    eNotas nuevaNota;


    listaNotasAlumnos = (eNotas*) malloc(sizeof(eNotas));

    listaNotasAlumnos = &nuevaNota;

    for( i= 0; i<3; i++)
    {
        if(contador>0 && bandera == 1)
        {
            listaNotasAlumnos = (eNotas*) realloc(listaNotasAlumnos,sizeof(eNotas)*5);

            bandera = 0;
        }


        printf("Ingrese primer nota: \n");
        scanf("%d",&nuevaNota.primera);

        printf("Ingrese segunda nota: \n");
        scanf("%d",&nuevaNota.segunda);

        printf("Ingrese tercer nota: \n");
        scanf("%d",&nuevaNota.tercera);

        nuevaNota.cierre = (nuevaNota.primera + nuevaNota.segunda + nuevaNota.tercera)/3;

        //*(listaNotasAlumnos+i) = nuevaNota;

        listaNotasAlumnos+1;

        contador++;
        if(contador == 1)
        {
            bandera = 1;
        }
        else
        {
            bandera= 0;
        }


    }
    printf("Notas Finales\n\n");
    for(i=0; i<3; i++)
    {

       /// OPERADOR PUNTEROS
        printf("%2d %2d %2d FINAL: %2d\n",*(listaNotasAlumnos+i));

        ///OPERADOR VECTOR
       // printf("%2d %2d %2d FINAL: %2d\n",listaNotasAlumnos[i].primera, listaNotasAlumnos[i].segunda,listaNotasAlumnos[i].tercera,listaNotasAlumnos[i].cierre);
//        printf("%2d %2d %2d FINAL: %2d\n",listaNotasAlumnos[i].primera, listaNotasAlumnos[i].segunda,listaNotasAlumnos[i].tercera,listaNotasAlumnos[i].cierre);
    }


//    printf("%2d %2d %2d FINAL: %2d\n",*listaNotasAlumnos);
//    printf("%2d %2d %2d FINAL: %2d\n",*(listaNotasAlumnos+1));






//    int numero;
//    int otroNumero;
//    int unNumeroMas;
//
//    numero = 10;
//    otroNumero = 20;
//    unNumeroMas = 99;
//
//
//    int *punteroNumero;
//    int ** punteroPunteroNumero;
//    int ***punteroPunteroPunteroNumero;
//
//
//    punteroNumero = &numero;
//    punteroPunteroNumero = &punteroNumero;
//
//    punteroPunteroPunteroNumero =  &punteroPunteroNumero;
//
//    punteroNumero = &otroNumero;
//
//    otroNumero = 100-unNumeroMas;
//
////    punteroNumero = &numero;
//
//
////    printf("%d\n",***punteroPunteroPunteroNumero);
//
//
//
//
//
////    eEmployee listaEmpleados[7];
////    eEmployee *p;
////    eEmployee ** pp;
//
//
////    harcodearEmpleados(listaEmpleados);
////
////    p =&listaEmpleados[0];
////    pp = &p;
//
//
////    printf("%d\n",listaEmpleados[1].id);
//
//    for(i=0; i<7;i++)
//    {
////        printf("%d %s %c %d\n",listaEmpleados[i].id,listaEmpleados[i].nombre,listaEmpleados[i].sexo, listaEmpleados[i].sueldo);
////        printf("%d %s %c %d\n",*(listaEmpleados+i).id,listaEmpleados[i].nombre,listaEmpleados[i].sexo, listaEmpleados[i].sueldo);
//
//
//        ///VALIDO aritmetica punteros
////        printf("%d \n",(listaEmpleados+i)->id);
//        /// VALIDo VECTOR
////        printf("%d \n",p[i].id);
//
////        printf("%d \n",  *(*(pp)))->id;
//
//
//    }
//
//
//
//
    return 0;
}
//
//
//void harcodearEmpleados(eEmployee x[])
//    {
//
//        eEmployee y[]=
//        {
//            {1111, "ana", 'f', 15000},
//            {3333, "luis", 'm', 25000},
//            {4444, "alberto", 'm', 10000},
//            {5555, "julia", 'f', 30000},
//            {1313, "julieta", 'f', 23000},
//            {4545, "andrea", 'f', 31000},
//            {3232, "mauro", 'm', 27000},
//        };
//
//        for(int i=0; i<7; i++)
//        {
//            x[i] = y[i];
//        }
//
//    }
