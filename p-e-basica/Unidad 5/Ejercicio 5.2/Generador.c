#include <stdio.h>
#include <stdlib.h>

struct FECHA
{
    int Dia;
    int Mes;
    int Anio;
};

struct EMPLEADO
{
    int     Legajo;
    int     Cat;
    char    Ap[15];
    char    Nom[30];
    struct  FECHA FechaIn;
};

int main(){
    int i=0, Cant;
    FILE *Archivo;

    struct EMPLEADO E[] = {
        {1,1,"Bonachera"}

    };
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct EMPLEADO E[100];

    Archivo = fopen("empleados.dat","rb");

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&E[i],sizeof(struct EMPLEADO),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&E[i],sizeof(struct EMPLEADO),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("NOMBRE: %s          - CATEGORIA %d            - APELLIDO %s     \n", E[i].Nom, E[i].Cat, P[i].Ap);
    }
    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
