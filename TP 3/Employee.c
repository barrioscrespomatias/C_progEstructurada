#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    return nuevoEmpleado;
}
//Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas)
//{
//
//}
//void employee_delete();


/// DEVUELVE 0 si hubo un error (this = NULL o idAux >1) o 1 si pudo setearlo.

int employee_setId(Employee* this,int id)
{
    int setOk = 0;

    if(this!= NULL && id>0)
    {
        this->id = id;
        setOk = 1;
    }

    return setOk;
}

/// DEVUELVE 0 en caso de que hay un error. sino el ID obtenido
int employee_getId(Employee* this,int* id)
{
    *id = 0;

    if(this!= NULL && this->id >0)
    {
        *id = this->id;
    }

    return *id;
}
//
//int employee_setNombre(Employee* this,char* nombre);
//int employee_getNombre(Employee* this,char* nombre);
//
//int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
//int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
//
//int employee_setSueldo(Employee* this,int sueldo);
//int employee_getSueldo(Employee* this,int* sueldo);
//

