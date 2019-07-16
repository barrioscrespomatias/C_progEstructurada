#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include <string.h>
#include "utn.h"



/** \brief Carga los datos de los peliculas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPelicula)
{


    FILE* pFile;


        pFile = fopen(path,"r");
        if(pFile != NULL)
        {

            parser_PeliculaFromText(pFile,pArrayListPelicula);
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

/** \brief Carga los datos de los peliculas desde el archivo data.csv (modo binario).
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
        parser_PeliculaFromBinary(pFile,pArrayListEmployee);
    }
    else
    {
        printf("Error.\n");
        system("pause");
    }

    fclose(pFile);

    return 1;
}

/** \brief Alta de peliculas
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
//int controller_addPelicula(LinkedList* pArrayListEmployee)
//{
//
//
//    ePelicula *pelicula;
//    pelicula = pelicula_new();
//
//
//    int addOk = 0;
//    int id;
//    char buffer[100];
////    int horas;
////    int sueldo;
//    int indice;
//
//    int esta;
//
//    id = getValidInt("Ingrese Id: ");
//    esta = findPelicula(pArrayListEmployee,&id,&indice);
//    if(esta == 1)
//    {
//        printf("Se ha encontrado un pelicula con el id %d\nNo se pudo cargar el nuevo pelicula\n",id);
//
//
//    }
//    else
//    {
//
//        getValidStringLetras("Ingrese nombre: ","Error. Solo puede ingresar letras.",buffer);
//        horas=getValidInt("Ingrese horas trabajadas: ");
//        sueldo=getValidInt("Ingrese sueldo: ");
//
//        pelicula_setId(pelicula,id);
//        pelicula_setNombre(pelicula,buffer);
//        pelicula_setHorasTrabajadas(pelicula,horas);
//        pelicula_setSueldo(pelicula,sueldo);
//
//        ll_add(pArrayListEmployee,pelicula);
//        addOk = 1;
//        printf("pelicula cargado correctamente\n");
//    }
//
//    system("pause");
//
//    return addOk;
//}
//
///** \brief Modificar datos de pelicula
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_editPelicula(LinkedList* pArrayListEmployee)
//{
//    int idModificar;
//    int existe;
//    char confirma;
//    int indice;
//    int opcion;
//    ePelicula *pelicula;
//    pelicula = pelicula_new();
//
//    ///SUBMENU MODIFICAR
//    int idAuxModificado;
//    char nombreAux[100];
////    int horasAux;
////    int sueldoAux;
//
//    char nombreAnterior[100];
////    int horasAnterior;
////    int sueldoAnterior;
//
//    idModificar = getValidInt("Ingrese Id del pelicula a modificar: \n");
//    existe = findEmployee(pArrayListEmployee,&idModificar,&indice);
//
//
//    if(existe!=1)
//    {
//        printf("No existe un pelicula con el Id cargado\n");
//    }
//    else
//    {
//
//        confirma = getValidCharSN("Realmente desea modificar el pelicula? (s/n): ");
//        if(confirma == 'S' || confirma == 's')
//        {
//            do
//            {
//                system("cls");
//                printf("Menu modificar: \n");
//                printf("1. Id\n");
//                printf("2. Nombre\n");
//                printf("3. Horas\n");
//                printf("4. Sueldo\n");
//                printf("5. Salir\n\n");
//
//                opcion = getValidInt("Ingrese una opcion: ");
//                pelicula = ll_get(pArrayListEmployee,indice);
//
//                switch(opcion)
//                {
//                case 1:
//                    ///ID
//                    idAuxModificado = getValidInt("Ingrese nuevo id: ");
////                    pelicula = ll_get(pArrayListEmployee,indice);
//                    //TENDRIA QUE TOMAR ID AUX DESDE EL IDGET
//                    pelicula_setId(pelicula,idAuxModificado);
//                    printf("El pelicula %s se ha modificado exitosamente!! Su nuevo ID es %d\n",pelicula->nombre,pelicula->id);
//                    system("pause");
//                    break;
//                case 2:
//                    ///NOMBRE
//                    getValidStringLetras("Ingrese nuevo nombre: ","Error. Solo puede ingresar letras.",nombreAux);
//                    pelicula_getNombre(pelicula,nombreAnterior);
//                    pelicula_setNombre(pelicula,nombreAux);
//                    printf("El nombre del pelicula se ha sustituido exitosamente!!\n\n%s->%s\n",nombreAnterior,pelicula->nombre);
//                    system("pause");
//                    break;
//                case 3:
//                    ///HORAS
//                    horasAux=getValidInt("Ingrese nuevas horas trabajadas: ");
//                    pelicula_getHorasTrabajadas(pelicula,&horasAnterior);
//                    pelicula_setHorasTrabajadas(pelicula,horasAux);
//                    printf("\n\nLas horas del pelicula pasaron de un total de %d a un total de %d.\n\n",horasAnterior,pelicula->horasTrabajadas);
//                    system("pause");
//                    break;
//                case 4:
//                    sueldoAux=getValidInt("Ingrese nuevo sueldo: ");
//                    pelicula_getSueldo(pelicula,&sueldoAnterior);
//                    pelicula_setSueldo(pelicula,sueldoAux);
//                    printf("\n\nEl sueldo del pelicula paso de un total de $%d a un monto de $%d.\n\n",sueldoAnterior,pelicula->sueldo);
//                    system("pause");
//                    break;
//                }
//
//            }
//
//            while(opcion != 5);
//
//
//        }
//        else
//        {
//            printf("Se ha cancelado la modificacion\n\n");
//        }
//
//    }
//
//    system("pause");
//
//    return 1;
//}
//
///** \brief Baja de pelicula
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int controller_removeEmployee(LinkedList* pArrayListEmployee)
//{
//
//    ///NECESITO EL INDICE DE FINDEMPLOYEE PARA ELIMINAR
//    int idDelete;
//    int existe;
//    char confirma;
//    int indice;
//
//    idDelete = getValidInt("Ingrese Id del pelicula a eliminar: ");
//    existe = findEmployee(pArrayListEmployee,&idDelete,&indice);
//    //indice = &indice;
//
//
//    if(existe!=1)
//    {
//        printf("No existe un pelicula con el Id cargado\n");
//    }
//    else
//    {
//
//        confirma = getValidCharSN("¿Realmente desea Borrar al pelicula? ");
//        if(confirma == 'S' || confirma == 's')
//        {
//            ll_remove(pArrayListEmployee,indice);
//            printf("El pelicula con el ID %d ha sido borrado existosamente\n",idDelete);
//
//        }
//
//    }
//
//    system("pause");
//
//    return 1;
//}
//
////int controller_mostrarUnEmpleado(LinkedList*pArrayListEmployee)
////{
////    pelicula pelicula;
////
////    pelicula = ll_get(pArrayListEmployee,0);
////}

/** \brief Listar peliculas
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListPelicula(LinkedList* pArrayListPelicula)
{

    ePelicula *peliculas;
    int i;

    if(ll_len(pArrayListPelicula)== 0)
    {
        printf("No hay peliculas para mostrar\n");
        system("pause");

    }

    else
    {
//        ll_sort(pArrayListPelicula,peliculaSortByName,1);

        printf(" Id  |Nombre                                                      |Anio       |Genero        \n");

        for(i=0; i<ll_len(pArrayListPelicula); i++)
        {
            peliculas = ll_get(pArrayListPelicula,i);
            if(i%250==0 && i!=0)
            {
                system("pause");
            }

            printf("%-5d|%-60s|%-11d|%-15s\n",peliculas->id, peliculas->nombre, peliculas->anio, peliculas->genero);


        }


        system("pause");

    }


    return 1;
}

/** \brief Ordenar peliculas
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortPelicula(LinkedList* pArrayListPelicula)
{
    int opcion = 0;

    opcion = getValidInt("Menu ordenar peliculas\n\n1. Id\n2. Nombre\n3. Anio\n4. Genero\n\nSeleccione una opcion\n");

    switch(opcion)
    {
    case 1:
        ll_sort(pArrayListPelicula,peliculaSortById,1);
        printf("peliculas ordenados por Id correctamente\n");
        system("pause");
        break;
    case 2:
        ll_sort(pArrayListPelicula,peliculaSortByName,1);
        printf("peliculas ordenados por Nombre correctamente\n");
        system("pause");
        break;

    case 3:
        ll_sort(pArrayListPelicula,peliculaSortByAnio,1);
        printf("peliculas ordenados por Horas correctamente\n");
        system("pause");
        break;
    case 4:
        ll_sort(pArrayListPelicula,peliculaSortByGenero,1);
        printf("peliculas ordenados por Sueldo correctamente\n");
        system("pause");
        break;
    }

    return 1;
}

/** \brief Guarda los datos de los peliculas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPelicula)
{
    FILE*pFile;
    ePelicula* unaPelicula;
    int cantidad, i;


    pFile=fopen(path,"w");
    if(pFile != NULL && pArrayListPelicula != NULL)
    {
        cantidad = ll_len(pArrayListPelicula);
        rewind(pFile);
        fprintf(pFile,"id,nombre,anio,genero\n");

        for(i=0; i<cantidad; i++)
        {
            unaPelicula = (ePelicula*) ll_get(pArrayListPelicula,i);
            fprintf(pFile, "%d, %s, %d, %s\n",unaPelicula->id,unaPelicula->nombre,unaPelicula->anio,unaPelicula->genero);

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

/** \brief Guarda los datos de los peliculas en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* miArchivoBinario;
    ePelicula *unEmpleado;
    int i = 0;
    int cantidad;


    miArchivoBinario = fopen(path,"wb");
    cantidad = ll_len(pArrayListEmployee);



    if(pArrayListEmployee!= NULL&& miArchivoBinario != NULL)
    {
        for(i=0; i<cantidad; i++)
        {
            unEmpleado = ll_get(pArrayListEmployee,i);
            fwrite(unEmpleado,sizeof(ePelicula),1,miArchivoBinario);
        }
    }




    fclose(miArchivoBinario);






    return 1;
}



