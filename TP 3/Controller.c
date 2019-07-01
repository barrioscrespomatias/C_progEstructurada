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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{


    Employee *empleado;
    empleado = employee_new();


    int addOk = 0;
    int id;
    char buffer[100];
    int horas;
    int sueldo;
    int indice;

    int esta;

    id = getValidInt("Ingrese Id: ");
    esta = findEmployee(pArrayListEmployee,&id,&indice);
    if(esta == 1)
    {
        printf("Se ha encontrado un empleado con el id %d\nNo se pudo cargar el nuevo empleado\n",id);


    }
    else
    {

        getValidStringLetras("Ingrese nombre: ","Error. Solo puede ingresar letras.",buffer);
        horas=getValidInt("Ingrese horas trabajadas: ");
        sueldo=getValidInt("Ingrese sueldo: ");

        employee_setId(empleado,id);
        employee_setNombre(empleado,buffer);
        employee_setHorasTrabajadas(empleado,horas);
        employee_setSueldo(empleado,sueldo);

        ll_add(pArrayListEmployee,empleado);
        addOk = 1;
        printf("Empleado cargado correctamente\n");
    }

    system("pause");

    return addOk;
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

    ///NECESITO EL INDICE DE FINDEMPLOYEE PARA ELIMINAR
    int idDelete;
    int existe;
    char confirma;
    int indice;

    idDelete = getValidInt("Ingrese Id del empleado a eliminar: ");
    existe = findEmployee(pArrayListEmployee,&idDelete,&indice);
    indice = &indice;


    if(existe!=1)
    {
        printf("No existe un empleado con el Id cargado\n");
    }
    else
    {

        confirma = getValidCharSN("¿Realmente desea Borrar al empleado? ");
        if(confirma == 'S' || confirma == 's')
        {
            ll_remove(pArrayListEmployee,indice);
        }

    }

    system("pause");

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
    int opcion = 0;

    opcion = getValidInt("Menu ordenar empleados\n\n1. Id\n2. Nombre\n3. Horas trabajadas\n4. Sueldo\n\nSeleccione una opcion\n");

    switch(opcion)
    {
    case 1:
        ll_sort(pArrayListEmployee,employeeSortById,1);
        printf("Empleados ordenados por Id correctamente\n");
        system("pause");
        break;
    case 2:
        ll_sort(pArrayListEmployee,employeeSortByName,1);
        printf("Empleados ordenados por Nombre correctamente\n");
        system("pause");
        break;

    case 3:
        ll_sort(pArrayListEmployee,employeeSortByHorasTrabajadas,1);
        printf("Empleados ordenados por Horas correctamente\n");
        system("pause");
        break;
    case 4:
        ll_sort(pArrayListEmployee,employeeSortBySueldo,1);
        printf("Empleados ordenados por Sueldo correctamente\n");
        system("pause");
        break;
    }

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



