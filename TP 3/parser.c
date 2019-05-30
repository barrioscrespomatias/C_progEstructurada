#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[50], nombre[50], horas[50], sueldo[50];


    ///DESDE EL PARSER SOLO LOS TENGO CONVERTIR A MI TIPO DE DATO Y CARGARLO EN EL ARRAY DE EMPLEADOS.

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
    printf("%-4s| %-15s| %-15s| %-13s\n",id,nombre,horas,sueldo);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
        printf("%-4s| %-15s| %-15s| %-13s\n",id,nombre,horas,sueldo);
    }


    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
