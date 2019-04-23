#include "empleado.h"
#include<string.h>
#include "../biblioteca_UTN/utn.h"

void inicializarEmpleados(eEmpleado listaEmpleados[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaEmpleados[i].isEmpty = LIBRE;
    }

}

int buscarLibre(eEmpleado listaEmpleados[], int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<TAM; i++)
    {
        if(listaEmpleados[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



void mostrarEmpleado(eEmpleado unEmpleado,eSector sectores[], int tamSector)
{
    char descripcionSector[20];
    int i;

    for(i=0; i<tamSector; i++)
    {
        if(unEmpleado.idSector == sectores[i].id)
        {
            strcpy(descripcionSector,sectores[i].descripcion);
            break;
        }
    }


    printf("%5d - %15s - %5c - %10.2f - %10.2f - %-10s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto, descripcionSector);

}

void cargarEmpleados(eEmpleado lista[], eSector sectores[], int tamSector)
{
//    int i;
//
//
//    for(i=0; i<TAM; i++)
//    {

//    int j, indiceLibre;

    int indice;
    int valorHora;


    indice = buscarLibre(lista,TAM);

    if(indice != -1)
    {
        //UTILIZO FUNCION QUE MUESTRA LOS SECTORES.
        mostrarSectores(sectores,tamSector);
        lista[indice].idSector = getValidInt("Ingrese sector: ");

        lista[indice].legajo = getValidInt("Ingrese un legajo: ");

        //CADENAS NO NECESITAN AMPERSAND
        // CHAR CON AMPERSAND
        getValidStringLetras("Ingrese su nombre: ","Error. Reingrese: ",lista[indice].nombre);
        lista[indice].sexo = getValidCharFM("Ingrese sexo f/m: ");
        lista[indice].cantidadHoras = getValidInt("Ingrese cantidad horas trabajadas: ");

        //UTILIZO FUNCION QUE DEVUELVE EL VALOR DE LAS HORAS SEGUN SECTOR
        valorHora = calcularHora(sectores,tamSector,lista[indice].idSector);
        lista[indice].sueldoBruto = lista[indice].cantidadHoras * valorHora;
        lista[indice].sueldoNeto = lista[indice].sueldoBruto*0.85;
        lista[indice].isEmpty = OCUPADO;


        printf("\n");
        printf("\nEmpleado cargado correctamente\n");
        system("pause");


    }

    else
    {
        printf("\nNo se han cargado los datos.\n");
        system("pause");
    }


}

void mostrarListaEmpleados(eEmpleado listaEmpleados[],int tamEmpleados, eSector listaSectores[], int tamSectores)
{
    int i;
    for (i=0; i<tamEmpleados; i++)
    {
        if(listaEmpleados[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(listaEmpleados[i],listaSectores,tamSectores);
            printf("\n");
        }

    }
}


int buscarEmpleado(eEmpleado listaEmpleados[], int tam, int nLegajo, eSector listaSectores[], int tamSectores)
{
    int i;
    int legajo = -1;
//    printf("Ingrese el numero de legajo: ");
//    scanf("%d",&legajo);

    legajo = getValidInt("Ingrese el numero de legajo: ");

    for (i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[i].legajo == legajo)
        {
            printf("El empleado es: \n");
            mostrarEmpleado(listaEmpleados[i],listaSectores,tamSectores);
//            system("pause");
//            printf("\n");
            legajo = i;
            break;
        }

    }

    return legajo;
}

void modificarEmpleado(eEmpleado listaEmpleados[], int tam, eSector listaSectores[], int tamSectores)
{
    int empleado;
    int opcion = 0;
    char confirma;


    empleado = buscarEmpleado(listaEmpleados,tam,3,listaSectores,tamSectores);
    do
    {
        opcion = getValidInt("\n\tMenu modificar:\n1.Nombre\n2.Sexo\n3.Sueldo Bruto\n4.Salir\n");

        switch(opcion)
        {
        //NOMBRE
        case 1:
            confirma = getValidCharSN("Confirma que quiere modificar este empleado? s/n: ");
            if((confirma == 's')||(confirma=='S'))
            {
                getValidStringLetras("Ingrese nuevo nombre: ", "Error. Reingrese: ",listaEmpleados[empleado].nombre);
                printf("Nombre modificado exitosamente!!\n");
            }

            break;
        //SEXO
        case 2:
            confirma = getValidCharSN("Confirma que quiere modificar este empleado? s/n: ");
            if((confirma == 's')||(confirma=='S'))
            {
                listaEmpleados[empleado].sexo = getValidCharFM("Ingrese nuevo sexo f/m: ");
                printf("Nombre modificado exitosamente!!\n");
            }

            break;
        //SUELDO BRUTO
        case 3:
            confirma = getValidCharSN("Confirma que quiere modificar el sueldo neto?\nACLARACION: Se modificara el sueldo bruto\n\nIngrese s/n: ");
            if((confirma == 's')||(confirma=='S'))
            {
                listaEmpleados[empleado].sueldoBruto = getValidFloat("Ingrese nuevo sueldo bruto: ");
                listaEmpleados[empleado].sueldoNeto = listaEmpleados[empleado].sueldoBruto * 0.85;
                printf("Sueldo bruto y neto modificados exitosamente!!\n");
            }

            break;
        //SALIR
        case 4:
            break;
        }

    }
    while(opcion!=4);

//    printf("Ingrese nuevo legajo: \n");
//    scanf("%d",&listaEmpleados[empleado].legajo);
//
//    printf("El legajo ha sido modificado con exito!!\n");
//    system("pause");
}


void borrarEmpleado(eEmpleado listaEmpleados[], int tam, eSector listaSectores[],int tamSectores)
{
    int legajo;
    char confirma;

    legajo = buscarEmpleado(listaEmpleados,tam,3,listaSectores,tamSectores);

    confirma = getValidCharSN("Confirma que quiere BORRAR este empleado?\nIngrese s/n: ");
    if((confirma == 's')||(confirma=='S'))
    {
        listaEmpleados[legajo].isEmpty = LIBRE;
        printf("Empleado BORRADO exitosamente!!\n");
    }

    else
    {
        printf("El empleado no ha sido borrado.\n");
    }

    system("pause");

}


void mostrarSectores (eSector listaSectores[], int tamSector)
{
    int i;
//    eSector sectorAuxiliar[];
//    int idSectorBuscar = 0;

    printf("\tLista de sectores: \n\n");
    for(i=0; i<tamSector; i++)
    {
        printf("%d %s\n",listaSectores[i].id,listaSectores[i].descripcion);
//       if(listaSectores[i].id == idSectorBuscar)
    }
}


int calcularHora (eSector listaSectores[], int tamSector, int idSector)
{
    int i;
    int valorHora;
//    eSector sectorAuxiliar[];
//    int idSectorBuscar = 0;

    for(i=0; i<tamSector; i++)
    {
        if(listaSectores[i].id == idSector)
        {
            valorHora= listaSectores[i].valorHora;
            break;
        }

//       if(listaSectores[i].id == idSectorBuscar)
    }

    return valorHora;
}





