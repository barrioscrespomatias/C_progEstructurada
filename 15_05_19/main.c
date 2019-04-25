#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 10
#define LIBRE 0
#define OCUPADO 1
#include "empleado.h"
#include "../biblioteca_UTN/utn.h"


//ABM


// FUNCIONES SE DECLARAN DEBAJO DE LAS ESTRUCTURAS.
void menuAbm(eEmpleado listaEmpleados[], eSector sectores[]);
void hardcodearDatosEmpleados(eEmpleado lista[], int tam);





int main()
{

    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM);
    hardcodearDatosEmpleados(lista,TAM);



    eSector sectores[3]=
    {
        {1,"Contable",100},
        {2,"Sistemas",200},
        {3,"RRHH",150},
    };





    menuAbm(lista,sectores);



    return 0;
}




void menuAbm(eEmpleado listaEmpleados[], eSector sectores[])
{

    int option = 0;
//    char seguir = 's';


    do
    {
        system("cls");
        printf("\r\t\tMenu principal\n\n");
        printf("1- Cargar un empleado\n");
        printf("2- Mostrar lista de empleados\n");
        printf("3- Buscar un indice libre\n");
        printf("4- Borrar un empleado\n");
        printf("5- Modificar un empleado\n");
        printf("6- Informes\n");
        printf("7- Salir\n");


        option=getValidInt("Ingrese una opcion: \n");

        switch(option)
        {
        case 1:
            cargarEmpleados(listaEmpleados,sectores,3);
            break;
        case 2:
            mostrarListaEmpleados(listaEmpleados, TAM,sectores,3);
            system("pause");

            break;
        case 3:
            buscarLibre(listaEmpleados,TAM);
            break;

        case 4:
            borrarEmpleado(listaEmpleados,TAM,sectores,3);

            break;
        case 5:
            modificarEmpleado(listaEmpleados,TAM,sectores,3);

            break;
        case 6:
            menuInformes(sectores,listaEmpleados,3,TAM);
            break;
        case 7:
            break;


        }

  }while(option != 7 );




}


void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]={1,8,9,7,2,4,10,22,99,100};
    char nombres[][50]={"Carlos","Maria","Carlos","Pedro","Carlos","Mateo","Matute","Pepe","Tano","Pipa"};
    char sexo[]={'M','F','M','M','M','M','M','M','M','M'};
    float sueldosBruto[]={22000,22000,15000,4000,21000,6000,15000,1500,30000,100};
    int sector[]={1,2,3,2,1,3,2,1,1,1};


    for(i=0; i<10; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].isEmpty = OCUPADO;
        lista[i].idSector = sector[i];

    }
}




