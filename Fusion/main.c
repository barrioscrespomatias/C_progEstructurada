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



//    Employee *punteroEmpleados;
//    Employee listaEmpleados[5];
//
//    int idAux;
//    char nombre[100];
//    int error = 0;
//
//    punteroEmpleados = listaEmpleados;
//
//    strcpy(punteroEmpleados[0].nombre,"Pedro");
//    punteroEmpleados[0].id = 1000;
//    punteroEmpleados[0].horasTrabajadas = 50;
//    punteroEmpleados[0].sueldo = 10000;
//
//
//    strcpy(punteroEmpleados[1].nombre,"Jose");
//    punteroEmpleados[1].id = 3;
//    punteroEmpleados[1].horasTrabajadas = 10;
//    punteroEmpleados[1].sueldo = 100;
//
//
//    strcpy(punteroEmpleados[2].nombre,"Maria");
//    punteroEmpleados[2].id = 50;
//    punteroEmpleados[2].horasTrabajadas = 1;
//    punteroEmpleados[2].sueldo = 10000;
//
//    int sueldoAux;
//    int getOk=0;
//    int setOk=0;
//    int sueldoSeteado = 5;




//    getOk = employee_getSueldo(punteroEmpleados+0,&sueldoAux);
//
//    printf("Sueldo obtenido de la estructura es: %d\n\n",sueldoAux);
//
//    printf("Seteo la estructura con un nuevo sueldo de 5\n\n");
//    setOk = employee_setSueldo(punteroEmpleados+0,sueldoSeteado);
//    printf("Imprimo la nueva estrcutura: \n");
//    printf("%d",punteroEmpleados->sueldo);

///PRUEBA NOMBRE GET/SET
//
//char name[30] = " ";
//char name2[30] = "Jamaica";
//int getOK;
//int setOk = 0;


/////Guardo el string de la estrcutura en el auxiliar name (Que se encuentra vacio)
/////Lo tomo del tercer elemento (+2) del puntero a estrcutura
//
//getOK = employee_getNombre(punteroEmpleados+2, name);
///// SI DEVUELVE 1, se pudo setear.
//if(getOK ==1)
//{
//    /// IMPRIMO LA NUEVA VARIABLE NAME
//    printf("El nombre obtenido de la estructura es: %s\n\n",name);
//
//}
//
//printf("\n\n");
//printf("Prueba del SET ingresando Jamaica\n\n");
//
/////PRUEBA DEL SET
///// SETEANDO LA VARIABLE NAME2
//setOk = employee_setNombre(punteroEmpleados+2,name2);
/////IMPRIMO PARA MOSTRAR EL SETEO CON NAME2
//printf("Imprimo la nueva variable dentro de la estructura: %s",punteroEmpleados[2].nombre);


//    int guardoId;

///// PRUEBA ID GET / SET
//    idAux = employee_getId(punteroEmpleados+0,&guardoId);
//    printf("Obtengo ID estrcutura: %d\n\n",guardoId);
//    int id = 50;
//    printf("Seteo en %d: \n",id);
//
//    employee_setId(punteroEmpleados+0,id);
//    printf("Imprimo nuevamente ID estructura: \n\n");
//
//    printf("%d",punteroEmpleados->id);




//    int id;
//    char nombre[128];
//    int horasTrabajadas;
//    int sueldo;






    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
//            printf("\tMENU PRINCIPAL\n\n");
//            printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
//            printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
//            printf("3. Alta de empleado\n");
//            printf("4. Modificar datos de empleado\n");
//            printf("5. Baja de empleado\n");
//            printf("6. Listar empleados\n");
//            printf("7. Ordenar empleados\n");
//            printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
//            printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
//            printf("10. Salir\n");

        printf("\tMENU PRINCIPAL\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
        // printf("3. Alta de empleado\n");

        printf("2.  Agregar empleado\n");
        printf("3.  Listar empleados\n");
        printf("4.  Borrar empleado\n");
        printf("5.  Ordenar empleados\n");
        printf("6.  Modificar empleados\n");
        printf("7.  Guardar Binario\n");
        printf("8.  Cagar Binario\n");
        printf("9.  Guardar NUEVO TEXTO\n");
        printf("10. Cargar NUEVO TEXTO\n");


        printf("15. Salir\n");




        printf("\n\nIngrese una opcion: ");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            controller_loadFromText("archivo.csv",listaEmpleados);
            break;
//        case 2:
//            controller_addEmployee(listaEmpleados);
//            break;
        case 3:
            controller_ListEmployee(listaEmpleados);
            break;
//        case 4:
//            controller_removeEmployee(listaEmpleados);
//            break;
//        case 5:
//            controller_sortEmployee(listaEmpleados);
//            break;
//        case 6:
//            controller_editEmployee(listaEmpleados);
//            break;
//        case 7:
//            controller_saveAsBinary("data.bin",listaEmpleados);
//            break;
//        case 8:
//            controller_loadFromBinary("data.bin",listaEmpleados);
//            break;
//        case 9:
//            controller_saveAsText("nuevaData.csv",listaEmpleados);
//            break;
//
//        case 10:
//            controller_loadFromText("nuevaData.csv",listaEmpleados);
//            break;
//
        case 11:
            ll_map(listaEmpleados,laQueMapea);
            break;
        }
    }
    while(option != 15);
    return 0;
}

