#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int getInt(char mensaje[]);
int getValidInt(char mensaje[]); //DOXY
float getFloat(char mensaje[]);
int getValidFloat(char mensaje[]);//DOXY

char getChar(char mensaje[]);
char getValidCharFM(char mensaje[]);
char getValidCharSN(char mensaje[]);



int esNumericoInt(char str[]);
int esNumericoFloat(char str[]);

int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esSoloChar(char letra); // DOXY
void getString(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
void getValidStringLetras(char mensaje[], char mensajeError[], char nombre[]);

















#endif // UTN_H_INCLUDED
