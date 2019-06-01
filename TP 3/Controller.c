#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>


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

    if(pFile != NULL)
    {
        pFile = fopen("data.csv", "r");

    }

    else
    {
        printf("Error de apertura de archivo texto");
    }

    ///LLAMAR A LA FUNCION PARSEO TEXTO QUE SE ENCARGUE DE MOSTRAR.
    parser_EmployeeFromText(pFile,pArrayListEmployee);

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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee*auxiliar;
    Employee*auxiliar2;
    Employee* auxiliar3;

    auxiliar = employee_new();
    auxiliar2= employee_new();
    auxiliar3 = employee_new();



    auxiliar->horasTrabajadas=100;
    auxiliar->id = 1;
    strcpy(auxiliar->nombre,"PEDRO");

    employee_setId(auxiliar2,2);

    auxiliar2->horasTrabajadas = 10;
    strcpy(auxiliar2->nombre,"JUAN");
    auxiliar2->id = 2;

     auxiliar3->horasTrabajadas = 50;
    strcpy(auxiliar3->nombre,"MARIA");
    auxiliar3->id = 3;


    ll_add(pArrayListEmployee,auxiliar);
    ll_add(pArrayListEmployee,auxiliar2);
    ll_add(pArrayListEmployee,auxiliar3);


//    (auxiliar+0)->horasTrabajadas=100;
//    (auxiliar+0)->id = 1;
//    strcpy((auxiliar+0)->nombre,"PEDRO");
//
//    (auxiliar+1)->horasTrabajadas=10;
//    strcpy((auxiliar+1)->nombre,"JUAN");
//    (auxiliar+1)->id = 2;
//
//    int i;
//    for(i=0;i<2;i++)
//    {
//        ll_add(pArrayListEmployee,auxiliar+i);
//    }

    return 1;
}

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
    Employee *empleado;
//    Employee *empleado2;

//    int i;
//    char nombre[50];
//    int id;
//    int horas;



//    empleado = ll_get(pArrayListEmployee,0);
//    printf("%s %d %d\n",empleado->nombre,empleado->id,empleado->horasTrabajadas,&empleado);
//
//    empleado2 = ll_get(pArrayListEmployee,1);
//    printf("%s %d %d Dir: %d\n",empleado2->nombre,empleado2->id,empleado2->horasTrabajadas,&empleado2);
//





//    for(i=0; i<2; i++);
//
//    {
//        empleado = (Employee*) ll_get(pArrayListEmployee,i);
//
//        printf("%d %d\n",empleado[i].id,empleado[i].horasTrabajadas);
//
//
////              printf("Error.\n");
//
//    }
//
//
//


    system("pause");

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

