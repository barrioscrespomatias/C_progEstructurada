#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    Employee *punteroEmpleados;
    Employee listaEmpleados[5];
    int idAux;


    punteroEmpleados = listaEmpleados;

    strcpy(punteroEmpleados[0].nombre,"Pedro");
    punteroEmpleados[0].id = 1000;
    punteroEmpleados[0].horasTrabajadas = 50;
    punteroEmpleados[0].sueldo = 10000;


    strcpy(punteroEmpleados[1].nombre,"Jose");
    punteroEmpleados[1].id = 3;
    punteroEmpleados[1].horasTrabajadas = 10;
    punteroEmpleados[1].sueldo = 100;


    strcpy(punteroEmpleados[2].nombre,"Maria");
    punteroEmpleados[2].id = 50;
    punteroEmpleados[2].horasTrabajadas = 1;
    punteroEmpleados[2].sueldo = 10000;



    printf("%d\n\n",idAux = employee_getId(punteroEmpleados+0,&idAux));

    int id = 50;
    printf("Seteo en %d: \n",id);

    employee_setId(punteroEmpleados,id);
    printf("Imprimo: \n\n");
    printf("%d\n\n",idAux = employee_getId(punteroEmpleados+0,&idAux));


//    int id;
//    char nombre[128];
//    int horasTrabajadas;
//    int sueldo;




//    int option = 0;
//    LinkedList* listaEmpleados = ll_newLinkedList();
//    do{
//        switch(option)
//        {
//            case 1:
//                controller_loadFromText("data.csv",listaEmpleados);
//                break;
//        }
//    }while(option != 10);
    return 0;
}
