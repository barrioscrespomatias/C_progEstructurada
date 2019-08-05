#include <stdio.h>
#include <stdlib.h>

struct S_datos
{
    int dato0;
    int dato1;
    int dato2;
};



int main()
{

    struct S_datos datos= {1,2,3};
    int* p= (int*)&datos;

    p = datos;
    *(p)->dato1 = 100;






    return 0;
}
