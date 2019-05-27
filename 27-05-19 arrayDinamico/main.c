#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* miArchivo;
    char buffer[20];

    ///APERTURA DESDE UN DIRECTORIO, FORMA DE ABRIRLO.
    miArchivo = fopen("misDatos.txt", "r"); ///1ºe paso

    ///PERMITE LEER DESDE ALGUN LUGAR Y TRAERLO  A LA CONSOLA
    /// DONDE LO GUARDO, CANTIDAD, ORIGEN
    while(!feof(miArchivo))
    {
        fgets(buffer, 30, miArchivo); ///2do paso
        printf("%s",buffer);
    }


//    fgets(buffer, 30, miArchivo); ///2do paso
//  printf("%s",buffer);

    ///CIERRO EL ARCHIVO
    fclose(miArchivo);






//    char nombre[] = "Matias";
//
//    //miArchivo = fopen("D:\\misDatos.txt", "w"); ///1er paso
//    /// ABRO ARCHIVO CON FOPEN(PATH; MODO)
//    miArchivo = fopen("misDatos.txt", "w"); ///1er paso
//
//
//
//    ///DIRECCIONA EL TEXTO HACIA OTRA PARTE (en este caso hacia mi archivo)
//    //fprintf(miArchivo,nombre); /// 2do paso
//   fprintf(miArchivo,"Su nombre es: \n %s",nombre); /// 2do paso
//
//
//
//    fclose(miArchivo); ///3er paso
//
//
//
//
    return 0;
}
