#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia, mes, anio;
}eFecha;

typedef struct
{
    int id;
//    int cantEmpleadosSector;
    char descripcion[20];
    float valorHora;
}eSector;


typedef struct
{
    int idSector;

    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int cantidadHoras;
    int isEmpty;
} eEmpleado;

void inicializarEmpleados(eEmpleado listaEmpleados[], int tam);
int buscarLibre(eEmpleado[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado,eSector sectores[], int tamSector);
void cargarEmpleados(eEmpleado lista[], eSector sectores[], int tamSector);
void mostrarListaEmpleados(eEmpleado listaEmpleados[],int tamEmpleados, eSector listaSectores[], int tamSectores);
int buscarEmpleado(eEmpleado listaEmpleados[], int tam, int nLegajo, eSector listaSectores[], int tamSectores);
void modificarEmpleado(eEmpleado listaEmpleados[], int tam, eSector listaSectores[], int tamSectores);
void borrarEmpleado(eEmpleado listaEmpleados[], int tam, eSector listaSectores[],int tamSectores);

void mostrarSectores (eSector listaSectores[], int tamSector);
int calcularHora (eSector listaSectores[], int tamSector, int idSector);
void empleadosPorSector(eSector listaSectores[], eEmpleado listaEmpleados[], int tamSectores, int tamEmpleados);
void menuInformes(eSector listaSectores[], eEmpleado listaEmpleados[], int tamSec, int tamEmp);
void sueldosPorSector(eSector listaSectores[], eEmpleado listaEmpleados[], int tamSectores, int tamEmpleados);


void obtenerDescrpcionSector(eSector listaSectores[],int tamSec, int sectorId);
int contadorEmpleadosPorSector(eSector listaSectores[], eEmpleado listaEmpleados[], int tamSec, int tamEmp, int idSector);
void sectorConMasEmpleados(eSector listaSectores[],eEmpleado listaEmpleados[], int tamSec, int tamEmp);







#endif // EMPLEADO_H_INCLUDED
