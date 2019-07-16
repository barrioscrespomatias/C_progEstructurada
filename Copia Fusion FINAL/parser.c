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
int parser_PeliculaFromText(FILE* pFile, LinkedList* pArrayListPelicula)
{
    ePelicula * auxiliar;
    char id[50], nombre[50], anio[50], genero[50];//, edad[50], empleo[50];


    ///DESDE EL PARSER SOLO LOS TENGO CONVERTIR A MI TIPO DE DATO Y CARGARLO EN EL ARRAY DE EMPLEADOS.
//    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,edad,empleo,sueldo);

//    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,]\n",id,nombre,empleo,edad,horas);
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,anio,genero);


    while(!feof(pFile))
    {
//        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horas,sueldo);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,anio,genero);

//        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,edad,empleo,sueldo);
        auxiliar = pelicula_newParametros(id,nombre,anio,genero);
        ll_add(pArrayListPelicula,auxiliar);


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
int parser_PeliculaFromBinary(FILE* pFile, LinkedList* pArrayListPelicula)
{
   int retorno = 0;
   ePelicula* unaPelicula;
   int cantidad;


   while(!feof(pFile))
   {
       unaPelicula = pelicula_new();
       cantidad = fread(unaPelicula,sizeof(ePelicula),1,pFile);

       if(cantidad == 1 && unaPelicula != NULL)
       {
           ll_add(pArrayListPelicula,unaPelicula);
       }

      retorno = 1;
   }



    return retorno;
}
