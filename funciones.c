#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "inc/input.h"

void inicializar(EPersona per[], int cantidad){
    int i;

    for(i=0; i<cantidad; i++){
        per[i].estado = 0;
    }
}

void alta(EPersona per[], int cantidad){
    int i;
    int validaEdad, validaNombre;

    for(i=0; i<cantidad; i++){
        if(per[i].estado == 0){
            printf("DNI: ");
            scanf("%ld", &per[i].dni);

            do{
                validaNombre = getString(per[i].nombre,"Nombre: ","El largo debe ser entre 2 y 50",2,50);
            }
            while(validaNombre == -1);

            do{
                validaEdad = getInt(&per[i].edad,"Edad: ","Rango valido [0 - 100]",1,100);
            }
            while(validaEdad == -1);

            per[i].estado = 1;

            break;
        }
    }
    printf("\n");
}

void listar(EPersona per[], int cantidad){
    int i, j, k;
    EPersona aux;
    system("cls");

    for (j=0; j<cantidad-1; j++)
        {
            for(k=j+1; k<cantidad; k++)
                {
                    if (strcmp(per[j].nombre, per[k].nombre) > 0){
                        {
                            aux = per[j];
                            per[j] = per[k];
                            per[k] = aux;
                        }
                    }
                }
        }

    printf("Listado de Personas:\n\nDNI\t\tNombre\t\t\tEdad\t\n");

    for(i=0; i<cantidad; i++){
        if(per[i].estado == 1){
            printf("%ld\t%s\t\t\t%d\t\n", per[i].dni, per[i].nombre, per[i].edad);
        }
    }
    printf("\n");
}

int buscarPersona(EPersona per[], int cantidad, long dni)
{
    int indice = -1;
    int i;

    for(i=0; i < cantidad; i++)
    {
        if(per[i].estado == 1 && per[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPersona(EPersona per)
{
    printf("\nDNI: %ld   Nombre: %s   Edad: %d \n", per.dni, per.nombre, per.edad);
}

void baja(EPersona per[], int cantidad){
long dni;
int esta;
char confirma;

system("cls");
printf("Baja Persona\n\n");

   printf("Ingrese DNI: ");
        scanf("%ld", &dni);

        esta = buscarPersona(per, cantidad, dni);

        if(esta == -1)
        {
            printf("\nEl DNI %ld no se encuentra en el sistema\n\n", dni);

        }
        else{

                mostrarPersona(per[esta]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            per[esta].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
        }

        }
}

void listarGrafico(EPersona per[], int cantidad){
   int i, j;
   for (i = 0; i < cantidad; i++){
        if(per[i].estado == 1){
                if(per[i].edad <= 18){
                    printf(" *\n");
                }
                else if(per[i].edad >= 19 && per[i].edad <= 35){
                    printf("\t  *\n");
                }
                else if(per[i].edad > 35){
                    printf("\t\t *\n");
                }
        }
   }
   printf("<18\t19-35\t>35\t\n");
}

void hardCode(EPersona per[]){
    per[0].dni = 13566346;
    strcpy(per[0].nombre, "Simon");
    per[0].edad = 53;
    per[0].estado = 1;

    per[1].dni = 63452741;
    strcpy(per[1].nombre, "Raul");
    per[1].edad = 28;
    per[1].estado = 1;

    per[2].dni = 42342324;
    strcpy(per[2].nombre, "Jose");
    per[2].edad = 16;
    per[2].estado = 1;

    per[3].dni = 12312312;
    strcpy(per[3].nombre, "Alfredo");
    per[3].edad = 32;
    per[3].estado = 1;
}









