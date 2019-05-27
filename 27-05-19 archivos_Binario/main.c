#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE* miArchivo;
   int *x;

   x = (int*) malloc(sizeof(int));

//   /// No es necesario que tenga extension pero para
//   /// reconocerlo, podria ponerle .dat o .bin
//
//   miArchivo = fopen("Datos.dat","wb");
//
//   // EN ESTE CASO NECESITA UNA DIRECCION DE MEMORIA
//   //TIPO DE DATO QUE QUIERO ESCRIBIR (Pasandole el tamanio)
//   // CANTIDAD ELEMENTOS DEL TIPO ESPECIFICADO QUE QUIERO ESCRIBIR.
//   // DIRECCION DONDE LO GUARDA.
//   /// SIEMPRE DEPENDE DEL TIPO DE ARCHIVO QUE VOY A ESCRIBIR
//
//   fwrite(&x,sizeof(int), 1, miArchivo);
//
//   fclose(miArchivo);

    if(miArchivo!= NULL)
    {
        miArchivo = fopen("Datos.dat", "rb"); // 1ero APERTURA

    }

    /// DIR DONDE QUIERO GUARDAR EL DATO
    /// CANTIDAD SIZE OF
    /// CANTIDAD DE ELEMEMENTOS
    /// DIRECCION DE LECTURA

    fread(x,sizeof(int),1,miArchivo); //2do ACCION

    fclose(miArchivo); //3er Cierre

    printf("%d",*x);
    system("pause");

    return 0;
}
