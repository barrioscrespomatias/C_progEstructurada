#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "utn.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    return nuevoEmpleado;
}
Employee* employee_newParametros(char* id,char* nombre, char* empleo, char* edad, char* horasTrabajadas, char* sueldo)
{
    Employee * auxiliar;
    auxiliar = employee_new();

    auxiliar->id = atoi(id);
    strcpy(auxiliar->nombre,nombre);
    strcpy(auxiliar->empleo,empleo);
    auxiliar->edad = atoi(edad);
    auxiliar->horasTrabajadas = atoi(horasTrabajadas);
    auxiliar->sueldo = atoi(sueldo);

    return auxiliar;
}


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
    int getIdOk = 0;

    if(this!= NULL && this->id >0)
    {
        *id = this->id;
        getIdOk = 1;
    }

    return getIdOk;
}


///EDAD

int employee_setEdad(Employee* this,int edad)
{
    int setOk = 0;

    if(this!= NULL && edad>0)
    {
        this->edad = edad;
        setOk = 1;
    }

    return setOk;
}

int employee_getEdad(Employee* this,int* edad)
{
    int getEdadOk = 0;

    if(this!= NULL && this->edad >0)
    {
        *edad = this->edad;
        getEdadOk = 1;
    }

    return getEdadOk;
}



/// SET NOMBRE

int employee_setNombre(Employee* this,char* nombre)
{
    int setOk = 0;
    int size = strlen(nombre);

    if(this!= NULL && size>0)
    {

        strcpy(this->nombre, nombre);
        setOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el nombre ingresado no contiene caracteres.");
    }

    return setOk;

}

///GET NOMBRE

int employee_getNombre(Employee* this,char* nombre)
{
    int getOk = 0;
    int size = 0;

    size = strlen(this->nombre);

    if(this!= NULL && size >0)
    {
        /// SIEMPRE ME VOY ACORDAR DEL STRCPY
        strcpy(nombre,this->nombre);
        getOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el nombre no tiene caracteres.\n");
    }

    return getOk;

}


///EMPLEO

int employee_setEmpleo(Employee* this,char* empleo)
{
    int setOk = 0;
    int size = strlen(empleo);

    if(this!= NULL && size>0)
    {

        strcpy(this->empleo, empleo);
        setOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el empleo ingresado no contiene caracteres.");
    }

    return setOk;

}

///GET NOMBRE

int employee_getEmpleo(Employee* this,char* empleo)
{
    int getOk = 0;
    int size = 0;

    size = strlen(this->empleo);

    if(this!= NULL && size >0)
    {
        /// SIEMPRE ME VOY ACORDAR DEL STRCPY
        strcpy(empleo,this->empleo);
        getOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el empleo no tiene caracteres.\n");
    }

    return getOk;

}





int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setOk = 0;

    if(this!= NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        setOk = 1;
    }

    return setOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getIdOk = 0;

    if(this!= NULL && this->horasTrabajadas>0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        getIdOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o las horas trabajadas son menor a 1");

    }

    return getIdOk;

}



int employee_setSueldo(Employee* this,int sueldo)
{
    int setOk = 0;

    if(this!= NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        setOk = 1;
    }

    return setOk;


}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int getSueldoOk = 0;
    if(this!= NULL && this->sueldo >0)
    {

        *sueldo = this->sueldo;
        getSueldoOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el sueldo es menor a 1");
    }

    return getSueldoOk;

}

///MIS FUNCIONES

int findEmployee(LinkedList* pArrayList, int *id, int*indice)
{

    ///NECESITO EL INDICE PARA ELIMINAR
    Employee* empleado;

    int i;
    int encontrado = 0;
    int largo = ll_len(pArrayList);

    for(i=0; i<largo;i++)
    {
        empleado = ll_get(pArrayList,i);

        if(empleado->id == *id)
        {
            printf("Se ha encontrado una coincidencia!!\n\nId :%d Nombre: %s \n",empleado->id, empleado->nombre);
            encontrado = 1;
            *indice = i;
            break;
            system("pause");
        }
    }

return encontrado;
}






int employeeSortById(void * empleadoA, void * empleadoB)
{
    int retorno = 0;

    if(  ((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id  )
    {
        retorno = 1;
    }

    return retorno;
}


int employeeSortByName(void * empleadoA, void * empleadoB)

{

    int retorno = 0;

    if(strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre)>0)
    {
        retorno = 1;
    }

    return retorno;
}


int employeeSortByHorasTrabajadas(void * empleadoA, void * empleadoB)
{
    int retorno = 0;

    if(  ((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas  )
    {
        retorno = 1;
    }

    return retorno;
}


int employeeSortBySueldo(void * empleadoA, void * empleadoB)
{
    int retorno = 0;

    if(  ((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo  )
    {
        retorno = 1;
    }

    return retorno;
}


///FUNCION QUE MAPEA
int laQueMapea (void* empleado)
{
    int returnAux = 0;

    if(empleado!= NULL)
    {
        ((Employee*)empleado)->sueldo = ((Employee*)empleado)->horasTrabajadas * 300;
        returnAux = 1;
    }


    return returnAux;
}


///FUNCION QUE FILTRA

int laQuefiltra(void* empleado)
{
    int returnAux = 0;

    if(empleado != NULL)
    {

         if( ((Employee*)empleado)->edad > 20 && strcmp( ((Employee*)empleado)->empleo,"programador") == 0)
         {
             returnAux = 1;
         }
    }


    return returnAux;
}

