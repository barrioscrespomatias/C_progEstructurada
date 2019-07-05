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
    Employee * auxiliar;
    char id[50], nombre[50], horas[50], sueldo[50], edad[50], empleo[50];


    ///DESDE EL PARSER SOLO LOS TENGO CONVERTIR A MI TIPO DE DATO Y CARGARLO EN EL ARRAY DE EMPLEADOS.
//    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,edad,empleo,sueldo);

//    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,]\n",id,nombre,empleo,edad,horas);


    while(!feof(pFile))
    {
//        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horas,sueldo);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horas,sueldo);

//        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,edad,empleo,sueldo);
        auxiliar = employee_newParametros(id,nombre,empleo,edad,horas,sueldo);
        ll_add(pArrayListEmployee,auxiliar);


//        printf("%d\n",auxiliar->id);
//        printf("\nLEIDOS: %d\n",ll_len(pArrayListEmployee));
    }
    printf("Archivo cargado correctamente\n");
    system("pause");

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
   int retorno = 0;
   Employee* unEmpleado;
   int cantidad;


   while(!feof(pFile))
   {
       unEmpleado = employee_new();
       cantidad = fread(unEmpleado,sizeof(Employee),1,pFile);

       if(cantidad == 1 && unEmpleado != NULL)
       {
           ll_add(pArrayListEmployee,unEmpleado);
       }

      retorno = 1;
   }



    return retorno;
}
