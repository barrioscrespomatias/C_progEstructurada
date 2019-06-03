#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include <string.h>
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{


    FILE* pFile;

    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }

    else
    {
        printf("Error de apertura de archivo texto");
    }



    ///LLAMAR A LA FUNCION PARSEO TEXTO QUE SE ENCARGUE DE MOSTRAR.

    fclose(pFile);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
//int controller_addEmployee(LinkedList* pArrayListEmployee)
//{
//    Employee *empleado;
//    empleado = employee_new();
//
//
//    int id;
//    int existe;
////    char nombre[50];
////    int sueldo;
////    int horas;
////    int existe;
//
//    id = getValidInt("Ingrese Id: ");
////    printf("%d",id);
//    existe = findEmployee(empleado,pArrayListEmployee,id);
//
//    if(existe == 1)
//    {
//
//        printf("Ya existe un empleado con ese id!!\n");
//    }
//
//    else
//    {
//        employee_setId()
//    }
//
//    system("pause");
//
//
//
//


    //HARDCODEO

//    Employee*auxiliar;
//    Employee*auxiliar2;
//    Employee* auxiliar3;
//
//    auxiliar = employee_new();
//    auxiliar2= employee_new();
//    auxiliar3 = employee_new();
//
//
//
//    auxiliar->horasTrabajadas=50;
//    auxiliar->id = 13;
//    strcpy(auxiliar->nombre,"PEPE");
//
//
//    auxiliar2->horasTrabajadas = 10;
//    strcpy(auxiliar2->nombre,"JUAN");
//    auxiliar2->id = 2;
//
//    auxiliar3->horasTrabajadas = 50;
//    strcpy(auxiliar3->nombre,"MARIA");
//    auxiliar3->id = 3;
//
//
//    ll_add(pArrayListEmployee,auxiliar);
//    ll_add(pArrayListEmployee,auxiliar2);
//    ll_add(pArrayListEmployee,auxiliar3);






//    return 1;
//}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

//int controller_mostrarUnEmpleado(LinkedList*pArrayListEmployee)
//{
//    Employee empleado;
//
//    empleado = ll_get(pArrayListEmployee,0);
//}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    Employee *empleados;
    int i;

    if(ll_len(pArrayListEmployee)== 0)
    {
        printf("No hay empleados para mostrar\n");
        system("pause");

    }

    else
    {
        printf(" Id  |Nombre       |Horas|Sueldo    \n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleados = ll_get(pArrayListEmployee,i);
            if(i%250==0 && i!=0)
            {
                system("pause");
            }

            printf("%5d|%13s|%5d|%10d\n",empleados->id, empleados->nombre, empleados->horasTrabajadas, empleados->sueldo);


        }

         system("pause");

    }


    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}



