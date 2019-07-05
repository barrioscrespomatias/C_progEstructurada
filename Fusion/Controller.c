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
        printf("Error de apertura de archivo texto\n");
        system("pause");
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
    FILE*pFile;

    pFile = fopen(path,"rb");

    if(pFile != NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }
    else
    {
        printf("Error.\n");
        system("pause");
    }

    fclose(pFile);

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
    int idModificar;
    int existe;
    char confirma;
    int indice;
    int opcion;
    Employee *empleado;
    empleado = employee_new();

    ///SUBMENU MODIFICAR
    int idAuxModificado;
    char nombreAux[100];
    int horasAux;
    int sueldoAux;

    char nombreAnterior[100];
    int horasAnterior;
    int sueldoAnterior;

    idModificar = getValidInt("Ingrese Id del empleado a modificar: \n");
    existe = findEmployee(pArrayListEmployee,&idModificar,&indice);


    if(existe!=1)
    {
        printf("No existe un empleado con el Id cargado\n");
    }
    else
    {

        confirma = getValidCharSN("Realmente desea modificar el empleado? (s/n): ");
        if(confirma == 'S' || confirma == 's')
        {
            do
            {
                system("cls");
                printf("Menu modificar: \n");
                printf("1. Id\n");
                printf("2. Nombre\n");
                printf("3. Horas\n");
                printf("4. Sueldo\n");
                printf("5. Salir\n\n");

                opcion = getValidInt("Ingrese una opcion: ");
                empleado = ll_get(pArrayListEmployee,indice);

                switch(opcion)
                {
                case 1:
                    ///ID
                    idAuxModificado = getValidInt("Ingrese nuevo id: ");
//                    empleado = ll_get(pArrayListEmployee,indice);
                    //TENDRIA QUE TOMAR ID AUX DESDE EL IDGET
                    employee_setId(empleado,idAuxModificado);
                    printf("El empleado %s se ha modificado exitosamente!! Su nuevo ID es %d\n",empleado->nombre,empleado->id);
                    system("pause");
                    break;
                case 2:
                    ///NOMBRE
                    getValidStringLetras("Ingrese nuevo nombre: ","Error. Solo puede ingresar letras.",nombreAux);
                    employee_getNombre(empleado,nombreAnterior);
                    employee_setNombre(empleado,nombreAux);
                    printf("El nombre del empleado se ha sustituido exitosamente!!\n\n%s->%s\n",nombreAnterior,empleado->nombre);
                    system("pause");
                    break;
                case 3:
                    ///HORAS
                    horasAux=getValidInt("Ingrese nuevas horas trabajadas: ");
                    employee_getHorasTrabajadas(empleado,&horasAnterior);
                    employee_setHorasTrabajadas(empleado,horasAux);
                    printf("\n\nLas horas del empleado pasaron de un total de %d a un total de %d.\n\n",horasAnterior,empleado->horasTrabajadas);
                    system("pause");
                    break;
                case 4:
                    sueldoAux=getValidInt("Ingrese nuevo sueldo: ");
                    employee_getSueldo(empleado,&sueldoAnterior);
                    employee_setSueldo(empleado,sueldoAux);
                    printf("\n\nEl sueldo del empleado paso de un total de $%d a un monto de $%d.\n\n",sueldoAnterior,empleado->sueldo);
                    system("pause");
                    break;
                }

            }

            while(opcion != 5);


        }
        else
        {
            printf("Se ha cancelado la modificacion\n\n");
        }

    }

    system("pause");

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
    //indice = &indice;


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
            printf("El empleado con el ID %d ha sido borrado existosamente\n",idDelete);

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
        ll_sort(pArrayListEmployee,employeeSortByName,1);

        printf(" Id  |Nombre       |Empleo       |Edad|Horas     |Sueldo  \n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleados = ll_get(pArrayListEmployee,i);
            if(i%250==0 && i!=0)
            {
                system("pause");
            }

            printf("%5d|%13s|%13s|%4d|%10d|%8d\n",empleados->id, empleados->nombre, empleados->empleo, empleados->edad, empleados->horasTrabajadas, empleados->sueldo);


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
    FILE*pFile;
    Employee* unEmpleado;
    int cantidad, i;


    pFile=fopen(path,"w");
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        cantidad = ll_len(pArrayListEmployee);
        rewind(pFile);
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<cantidad; i++)
        {
            unEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
            fprintf(pFile, "%d, %s, %d, %d\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->horasTrabajadas,unEmpleado->sueldo);

        }

        printf("Los datos se han guardado correctamente!!\n");
        system("pause");
    }
    else
    {
        printf("No se pudo guardar el archivo");
        system("pause");
    }

    fclose(pFile);

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
    FILE* miArchivoBinario;
    Employee *unEmpleado;
    int i = 0;
    int cantidad;


    miArchivoBinario = fopen(path,"wb");
    cantidad = ll_len(pArrayListEmployee);



    if(pArrayListEmployee!= NULL&& miArchivoBinario != NULL)
    {
        for(i=0; i<cantidad; i++)
        {
            unEmpleado = ll_get(pArrayListEmployee,i);
            fwrite(unEmpleado,sizeof(Employee),1,miArchivoBinario);
        }
    }




    fclose(miArchivoBinario);






    return 1;
}



