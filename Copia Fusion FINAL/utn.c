#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief  pide ingresar un numero entero
 *
 * \param mensaje: a mostrar al usuario
 * \param
 * \return retorna el numero entero ingresado
 *
 */

int getInt(char mensaje[])
{
    int aux = 0;
    printf("%s", mensaje);
    scanf("%d",&aux);

    return aux;
}

/** \brief Analiza si un numero ingresado es un numero entero
 *
 * \param mensaje a ser moestrado
 * \param
 * \return 1 si es numero entero, 0 sino lo es.
 *
 */


int getValidInt(char mensaje[])
{
//    char auxiliar[100];
    char ingresado[100];
    int auxInt;

    printf("%s",mensaje);
    fflush(stdin);

    scanf("%s",ingresado);

    while(!esNumericoInt(ingresado))
    {
        printf("Error, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%s",ingresado);
    }


    auxInt = atoi(ingresado);

    return auxInt;

}



/** \brief Pide el ingreso de un numero flotante
 *
 * \param mensaje: a ser mostrado al usuario
 * \param
 * \return el numero flotante
 *
 */

float getFloat(char mensaje[])
{
    float aux = 0;
    printf("%s", mensaje);
    scanf("%f",&aux);

    return aux;
}

/** \brief Analiza si un numero ingresado es un numero flotante
 *
 * \param mensaje a ser moestrado
 * \param
 * \return 1 si es numero flotante, 0 sino lo es.
 *
 */


int getValidFloat(char mensaje[])
{
//    char auxiliar[100];
    char ingresado[100];
    float auxInt;

    printf("%s",mensaje);
    fflush(stdin);

    scanf("%s",ingresado);

    while(!esNumericoFloat(ingresado))
    {
        printf("Error, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%s",ingresado);
    }


    auxInt = atof(ingresado);

    return auxInt;

}


/** \brief Pide un caracter
 *
 * \param mensaje: A ser mostrado
 * \param
 * \return el caracter pedido
 *
 */


char getChar(char mensaje[])
{
    char aux;
    printf("%s", mensaje);
    scanf("%c", &aux);

    return aux;
}


/** \brief Analiza el char si es m o f
 *
 * \param mensaje a ser mostrado
 * \param
 * \return el char ingresado
 *
 */

char getValidCharFM(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    while(auxiliar!='f' && auxiliar!='m' && auxiliar !='F' && auxiliar!='M'){
        printf("Error. Reingrese f/m : \n");
//        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",&auxiliar);

    }
    return auxiliar;
}

//char getvalidString()
//{
//
//}


char getValidCharSN(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    while(auxiliar!='s' && auxiliar!='n' && auxiliar !='S' && auxiliar!='N'){
        printf("Error. Reingrese s/n : \n");
//        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",&auxiliar);

    }
    return auxiliar;
}





/** \brief confirma si el dato ingreado es un numero entero
 *
 * \param str cadena del dato ingresado
 * \param
 * \return retorna 1 en caso de que sea un numero entero o sino 0.
 *
 */

int esNumericoInt(char str[])
{
//    int esNumero;
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i]<'0'||str[i]>'9')
        {
            return 0;
        }

        i++;
    }

//    esNumero =1;

    return 1;

}

/** \brief confirma si el dato ingreado es un numero flotante
 *
 * \param str cadena del dato ingresado
 * \param
 * \return retorna 1 en caso de que sea un numero flotante o sino 0.
 *
 */


int esNumericoFloat(char str[])
{
//    int esNumero;
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i]<'0'||str[i]>'9')&&(str[i]!='.'))
        {
            return 0;
        }

        i++;
    }

//    esNumero =1;

    return 1;

}


/** \brief toma una cadena la analiza y define si es alfanumerico.
 *
 * \param cadena ingresada por el usuario
 * \param
 * \return 1 si es alfanumerico sino retorna 0
 *
 */

int esAlfaNumerico(char str[])
{
//    int esAlfaNumerico;
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i]!=' ')&&(str[i]<'0'||str[i]>'9') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
        {
            return 0;
        }

        i++;
    }

//    esAlfaNumerico =1;

    return 1;

}

/** \brief Toma un string y analiza si contiene solo letras
 *
 * \param string ingresado por el usuario
 * \param
 * \return 1 si es solo letras sino 0.
 *
 */

int esSoloLetras(char str[])
{
//    int soloLetras;
    int i = 0;
    while(str[i]!= '\0')
    {
        if((str[i] !=' ') && (str[i]<'a' || str[i]> 'z')&& (str[i]<'A' || str[i]> 'Z'))
        {
            return 0;
        }
        i++;
    }

//    soloLetras = 1;
    return 1;
}

/////** \brief
// *
// * \param
// * \param
// * \return
// *
// */

// NOFUNCIONA
//int esSoloChar(char letra)
//{
//    while(letra != '\0')
//    {
//        if((letra!=' ') && (letra<'a' || letra> 'z')&& (letra<'A' || letra> 'Z') && letra != '.')
//        {
//            printf("0");
//            system("pause");
//            return 0;
//        }
//
//    }
//
//    printf("1");
//    system("pause");
//    return 1;
//}

/** \brief Pide un string
 *
 * \param mensaje: a ser guardado
 * \param input:
 * \return
 *
 */

void getString(char mensaje[], char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

/** \brief Analiza si el string ingresado son solo letras y lo guarda en una cadena.
 *
 * \param mensaje a ser mostrado
 * \param input cadena donde ser guardan los datos en caso de ser correctos.
 * \return devuelve 1 en caso de ser una cadena de letras. 0 sino lo  es.
 *
 */


int getStringLetras(char mensaje[], char input[])
{
    char buffer[256];
    getString(mensaje,buffer);

    if(esSoloLetras(buffer))
    {
        strcpy(input, buffer);
        return 1;
    }

    return 0;
}

/** \brief Analiza si el string ingresado son solo numeros y lo guarda en una cadena.
 *
 * \param mensaje a ser mostrado
 * \param input cadena donde ser guardan los datos en caso de ser correctos.
 * \return devuelve 1 en caso de ser una cadena de numeros. 0 sino lo  es.
 *
 */


int getSringNumeros(char mensaje[], char input[])
{
    char buffer[256];
    getString(mensaje,buffer);
    if(esNumericoInt(buffer))
    {
        strcpy(input,buffer);
        return 1;
    }

    return 0;

}

/** \brief Pide el ingreso de una cadena de solo letras.
 *
 * \param Mensaje: a ser mostrado
 * \param Mensaje error: a ser mostrado
 * \return void
 *
 */

void getValidStringLetras(char mensaje[], char mensajeError[], char nombre[])
{
    char nombreAux[100];

    getStringLetras(mensaje,nombreAux);

    while(!esSoloLetras(nombreAux))
    {
        getStringLetras(mensajeError, nombreAux);
    }

    strcpy(nombre,nombreAux);
}



