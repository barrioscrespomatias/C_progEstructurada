#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "utn.h"

ePelicula* pelicula_new()
{
    ePelicula* nuevaPelicula;
    nuevaPelicula = (ePelicula*)malloc(sizeof(ePelicula));
    return nuevaPelicula;
}
ePelicula* pelicula_newParametros(char* id,char* nombre, char* anio, char* genero)
{
    ePelicula * auxiliar;
    auxiliar = pelicula_new();

    auxiliar->id = atoi(id);
    strcpy(auxiliar->nombre,nombre);
    auxiliar->anio = atoi(anio);
    strcpy(auxiliar->genero,genero);

    return auxiliar;
}


//void employee_delete();


/// DEVUELVE 0 si hubo un error (this = NULL o idAux >1) o 1 si pudo setearlo.

int pelicula_setId(ePelicula* this,int id)
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
int pelicula_getId(ePelicula* this,int* id)
{
    int getIdOk = 0;

    if(this!= NULL && this->id >0)
    {
        *id = this->id;
        getIdOk = 1;
    }

    return getIdOk;
}


///Anio

int pelicula_setAnio(ePelicula* this,int anio)
{
    int setOk = 0;

    if(this!= NULL && anio>0)
    {
        this->anio = anio;
        setOk = 1;
    }

    return setOk;
}

int pelicula_getAnio(ePelicula* this,int* anio)
{
    int getEdadOk = 0;

    if(this!= NULL && this->anio >0)
    {
        *anio = this->anio;
        getEdadOk = 1;
    }

    return getEdadOk;
}



/// SET NOMBRE

int pelicula_setNombre(ePelicula* this,char* nombre)
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

int pelicula_getNombre(ePelicula* this,char* nombre)
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


///genero

int pelicula_setGenero(ePelicula* this,char* genero)
{
    int setOk = 0;
    int size = strlen(genero);

    if(this!= NULL && size>0)
    {

        strcpy(this->genero, genero);
        setOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el genero ingresado no contiene caracteres.");
    }

    return setOk;

}

///GET NOMBRE

int pelicula_getGenero(ePelicula* this,char* genero)
{
    int getOk = 0;
    int size = 0;

    size = strlen(this->genero);

    if(this!= NULL && size >0)
    {
        /// SIEMPRE ME VOY ACORDAR DEL STRCPY
        strcpy(genero,this->genero);
        getOk = 1;
    }
    else
    {
        printf("Error. El puntero es NULL o el genero no tiene caracteres.\n");
    }

    return getOk;

}





//int pelicula_setHorasTrabajadas(ePelicula* this,int horasTrabajadas)
//{
//    int setOk = 0;
//
//    if(this!= NULL && horasTrabajadas>0)
//    {
//        this->horasTrabajadas = horasTrabajadas;
//        setOk = 1;
//    }
//
//    return setOk;
//
//}
//
//int pelicula_getHorasTrabajadas(ePelicula* this,int* horasTrabajadas)
//{
//    int getIdOk = 0;
//
//    if(this!= NULL && this->horasTrabajadas>0)
//    {
//        *horasTrabajadas = this->horasTrabajadas;
//        getIdOk = 1;
//    }
//    else
//    {
//        printf("Error. El puntero es NULL o las horas trabajadas son menor a 1");
//
//    }
//
//    return getIdOk;
//
//}



//int pelicula_setSueldo(ePelicula* this,int sueldo)
//{
//    int setOk = 0;
//
//    if(this!= NULL && sueldo>0)
//    {
//        this->sueldo = sueldo;
//        setOk = 1;
//    }
//
//    return setOk;
//
//
//}
//int pelicula_getSueldo(ePelicula* this,int* sueldo)
//{
//    int getSueldoOk = 0;
//    if(this!= NULL && this->sueldo >0)
//    {
//
//        *sueldo = this->sueldo;
//        getSueldoOk = 1;
//    }
//    else
//    {
//        printf("Error. El puntero es NULL o el sueldo es menor a 1");
//    }
//
//    return getSueldoOk;
//
//}

///MIS FUNCIONES

int findPelicula(LinkedList* pArrayList, int *id, int*indice)
{

    ///NECESITO EL INDICE PARA ELIMINAR
    ePelicula* pelicula;

    int i;
    int encontrado = 0;
    int largo = ll_len(pArrayList);

    for(i=0; i<largo; i++)
    {
        pelicula = ll_get(pArrayList,i);

        if(pelicula->id == *id)
        {
            printf("Se ha encontrado una coincidencia!!\n\nId :%d Nombre: %s \n",pelicula->id, pelicula->nombre);
            encontrado = 1;
            *indice = i;
            break;
            system("pause");
        }
    }

    return encontrado;
}






int peliculaSortById(void * peliculaA, void * peliculaB)
{
    int retorno = 0;

    if(  ((ePelicula*)peliculaA)->id > ((ePelicula*)peliculaB)->id  )
    {
        retorno = 1;
    }

    return retorno;
}


int peliculaSortByName(void * peliculaA, void * peliculaB)

{

    int retorno = 0;

    if(strcmp(((ePelicula*)peliculaA)->nombre, ((ePelicula*)peliculaB)->nombre)>0)
    {
        retorno = 1;
    }

    return retorno;
}


int peliculaSortByAnio(void * peliculaA, void * peliculaB)
{
    int retorno = 0;

    if(  ((ePelicula*)peliculaA)->anio > ((ePelicula*)peliculaB)->anio  )
    {
        retorno = 1;
    }

    return retorno;
}



///GENERO

int peliculaSortByGenero(void * peliculaA, void * peliculaB)

{

    int retorno = 0;

    if(strcmp(((ePelicula*)peliculaA)->genero, ((ePelicula*)peliculaB)->genero)>0)
    {
        retorno = 1;
    }

    return retorno;
}




///FUNCION QUE MAPEA
//int laQueMapea (void* pelicula)
//{
//    int returnAux = 0;
//
//    if(pelicula!= NULL)
//    {
//        ((ePelicula*)pelicula)->sueldo = ((ePelicula*)pelicula)->horasTrabajadas * 300;
//        returnAux = 1;
//    }
//
//
//    return returnAux;
//}


///FUNCION QUE FILTRA

//int laQuefiltra(void* pelicula)
//{
//    int returnAux = 0;
//
//    if(pelicula != NULL)
//    {
//
//        if( ((ePelicula*)pelicula)->anio > 20 && strcmp( ((ePelicula*)pelicula)->genero,"programador") == 0)
//        {
//            returnAux = 1;
//        }
//    }
//
//
//    return returnAux;
//}


/// DEPURAR PELICULAS
//int laQuefiltra(void* pelicula)
//{
//    int returnAux = 0;
//    int contador = 0;
//
//    if(pelicula != NULL)
//    {
//
//        if( ((ePelicula*)pelicula)->id == contador)
//        {
//            returnAux = 1;
//        }
//        else
//        {
//            contador++;
//            returnAux = 0;
//        }
//    }
//
//
//    return returnAux;
//}

ePelicula constructorPeliculas()
{
    ePelicula* auxilar = (ePelicula*) malloc(sizeof(ePelicula));
}

int cantidadID(LinkedList* pArrayList)
{
    LinkedList *nuevo = ll_newLinkedList();

    ePelicula * unaPelicula;
    ePelicula * dosPelicula;
    ePelicula * tresPelicula;

    int i;
    int contador = 0;
    int cantidadPeliculas;
    char genero[50];
    char genero2[50];

    cantidadPeliculas = ll_len(pArrayList);

    ll_sort(pArrayList,peliculaSortById,1);

    for(i = 0; i<cantidadPeliculas; i++)
    {
        unaPelicula = (ePelicula*) ll_get(pArrayList,i);

        if(unaPelicula->id != contador)
        {
            contador++;
        }

    }
    printf("La cantidad de peliculas son: %d\n",contador);
    system("pause");

    contador = 0;


    for(i= 0; i<cantidadPeliculas; i++)
    {

        unaPelicula = (ePelicula*) ll_get(pArrayList,i);

        if(unaPelicula->id == 0)
        {
            contador++;

            dosPelicula = ll_get(pArrayList, i+1);


            if(printf("%d %s %d %s|",unaPelicula->id, unaPelicula->nombre, unaPelicula->anio, unaPelicula->genero))
            {

                if(printf("%s|",dosPelicula->genero))
                {
                    tresPelicula = ll_get(pArrayList,i+2);
                    printf("%s\n",tresPelicula->genero);
                }
                break;
            }
        }

    }


    printf("Cantidad de pelicuas con ID 0 %d\n",contador);
    system("pause");



    return 1;

}
