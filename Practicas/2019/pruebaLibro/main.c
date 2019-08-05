#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    char dia[50];
    char mes[50];
    char anio[50];
    char clase[50];
    char comprobante[50];
    char razonSocial[200];
    char cuit[50];
    char netoGravado[50];
    char iva[50];
    char exento[50];
    char percepcion[50];
    char total[50];
} eObjeto;


int main()
{
    FILE *pFile;
    eObjeto *listaObjetos;
    int parserOk;


    pFile = fopen("libro.csv", "r");

    if(pFile != NULL)
    {
        printf("Apertura correcta\n");
    }

    else
    {
        printf("Error al abrir\n");
    }

    parserOk = parserObjetos(listaObjetos,pFile);
//    printf("%d\n",parserOk);

    if(parserOk)
    {
  //      fwrite(&listaObjetos,sizeof(eObjeto),1,pFile);

    }

    fclose(pFile);

    return 0;
}

int parserObjetos(eObjeto* listaObjetos, FILE* pFile)
{
    int leido = 0;
    char buffer [2048];
    int returnAux = 0;
    char diaStr[50], mesStr[50], anioStr[50], claseStr[10], comprobanteStr[50], razonSocialStr[150], cuitStr[50], netoGravadoStr[50];
    char ivaStr[50], exentoStr[50], percepcionStr[50], totalStr[50], fechaStr[50];

    eObjeto auxiliar;


    fscanf(pFile,"%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^\n]\n",fechaStr,claseStr, comprobanteStr, razonSocialStr,cuitStr,netoGravadoStr,ivaStr,exentoStr,percepcionStr,totalStr);


    while(!feof(pFile))
    {



//       leido = fread(buffer,sizeof(char),2048,pFile);
//       printf("%s\n",buffer);

        fscanf(pFile,"%[^/],%[^/],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^;],%[^\n]\n", diaStr, mesStr, anioStr, claseStr, comprobanteStr, razonSocialStr,cuitStr,netoGravadoStr, ivaStr, exentoStr, percepcionStr, totalStr);


        strcpy(auxiliar.dia,diaStr);
        printf("%s\n",diaStr);
        strcpy(auxiliar.mes,mesStr);
        printf("%s\n",mesStr);

//        strcpy(auxiliar.anio,anioStr);
//        printf("%s\n",anioStr);
//
//        strcpy(auxiliar.clase,claseStr);
//        printf("%s\n",claseStr);
//
//        strcpy(auxiliar.comprobante,comprobanteStr);
//                printf("%s\n",comprobanteStr);
//
//        strcpy(auxiliar.razonSocial,razonSocialStr);
//                printf("%s\n",razonSocialStr);
//
//        strcpy(auxiliar.cuit,cuitStr);
//                printf("%s\n",cuitStr);
//
//        strcpy(auxiliar.netoGravado,netoGravadoStr);
//                printf("%s\n",netoGravadoStr);
//
//        strcpy(auxiliar.iva,ivaStr);
//                printf("%s\n",ivaStr);
//
//        strcpy(auxiliar.exento,exentoStr);
//                printf("%s\n",exentoStr);
//
//        strcpy(auxiliar.percepcion,percepcionStr);
//                printf("%s\n",percepcionStr);
//
//        strcpy(auxiliar.total,totalStr);
//                printf("%s\n",totalStr);
//
//


//        printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",auxiliar.dia,auxiliar.mes, auxiliar.anio, auxiliar.clase, auxiliar.comprobante,auxiliar.razonSocial, auxiliar.cuit, auxiliar.netoGravado, auxiliar.iva, auxiliar.exento, auxiliar.percepcion, auxiliar.total);

        returnAux = 1;

        break;
    }


    printf("Cargado correctamente\n");
    system("pause");


    return returnAux;
}

