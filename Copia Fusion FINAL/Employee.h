#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char empleo[128];
    int edad;
    int horasTrabajadas;
    int sueldo;
}Employee;

typedef struct
{
    int id;
    char nombre[150];
    int anio;
    char genero[50];
}ePelicula;

ePelicula* pelicula_new();
ePelicula* pelicula_newParametros(char* id,char* nombre, char* anio, char* genero);
void ePelicula_delete();

int pelicula_setId(ePelicula* this,int id);
int pelicula_getId(ePelicula* this,int* id);

int pelicula_setNombre(ePelicula* this,char* nombre);
int pelicula_getNombre(ePelicula* this,char* nombre);

int pelicula_setAnio(ePelicula* this,int anio);
int pelicula_getAnio(ePelicula* this,int* anio);

int pelicula_setGenero(ePelicula* this,char* genero);
int pelicula_getGenero(ePelicula* this,char* genero);


//int pelicula_setSueldo(ePelicula* this,int sueldo);
//int pelicula_setEmpleo(ePelicula* this,char* empleo);
//int pelicula_getEmpleo(ePelicula* this,char* empleo);




//MIS FUNCIONES
int findPelicula(LinkedList* pArrayList, int *id, int*indice);

int peliculaSortById(void * empleadoA, void * empleadoB);
int peliculaSortByName(void * empleadoA, void * empleadoB);
int peliculaSortByAnio(void * empleadoA, void * empleadoB);
int peliculaSortByGenero(void * empleadoA, void * empleadoB);

///Parcial
int laQueMapea (void* pelicula);
int laQuefiltra(void* pelicula);


int cantidadID(LinkedList* pArrayList);
ePelicula constructorPeliculas();







#endif // employee_H_INCLUDED
