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

Employee* employee_new();
Employee* employee_newParametros(char* id,char* nombre, char* emploeo, char* edad, char* horasTrabajadas, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setEdad(Employee* this,int edad);
int employee_getEdad(Employee* this,int* edad);

int employee_setEmpleo(Employee* this,char* empleo);
int employee_getEmpleo(Employee* this,char* empleo);




//MIS FUNCIONES
int findEmployee(LinkedList* pArrayList, int *id, int*indice);

int employeeSortById(void * empleadoA, void * empleadoB);
int employeeSortByName(void * empleadoA, void * empleadoB);
int employeeSortByHorasTrabajadas(void * empleadoA, void * empleadoB);
int employeeSortBySueldo(void * empleadoA, void * empleadoB);





#endif // employee_H_INCLUDED
