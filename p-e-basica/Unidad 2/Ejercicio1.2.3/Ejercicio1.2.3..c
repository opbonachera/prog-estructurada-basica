#include <stdio.h>
#include <string.h>

int CargarAlumnos(char[][100], int[]);
int Busqueda(char[][100], char[]);
int ValidarDni();
void OrdenarAlumnos(char[][100], int);

int main(){
    int NombreApellido[50][100];
    int Dni[50], Nombre[100], i=0, pos, CantAlumnos;


    CantAlumnos = CargarAlumnos(NombreApellido, Dni);
    printf("Carga Finalizada \n");

    printf("Ingrese el nombre a buscar...\n");
    fgets(Nombre, 100, stdin);

    Nombre[strlen(Nombre)-1] = '\0';

    while(strcmpi(NombreApellido, 'nobuscarmas')==0){
        pos = Busqueda(NombreApellido, Nombre);

        if(pos!=-1){
            printf("El DNI del alumno es %d. \n", Dni[i]);
        }else{
            printf("El alumno no fue registrado. ");
        }
    }

    OrdenarAlumnos(NombreApellido, CantAlumnos);

    return 0;
}

int CargarAlumnos(char Nombres[][100], int Dni[]){
    char Nombre[100];
    int i=0, cant=0;

    printf("Ingrese el nombre del alumno...\n");
    fflush(stdin);
    fgets(Nombre,100,stdin);


    while(strcmpi(Nombre,"FIN")!=0 && i<50){

        printf("Ingrese el DNI del alumno...\n");
        scanf("%d",&Dni[i]);

        Nombre[strlen(Nombre)-1] = '\0';

        strcpy(Nombres[i], Nombre);
        i++;
        cant++;

        printf("Ingrese el nombre del alumno...\n");
        fflush(stdin);
        gets(Nombre);
    }

    return cant;
}

int Busqueda(char Nombres[][100], char Nombre[]){
    int i, pos=-1;

    while(i<50 && pos==-1){
        if(strcmpi(Nombres[i], Nombre)==0){
            pos=i;
        }else{
            i++;
        }
    }

    return pos;
}

void OrdenarAlumnos(char Nombres[][100], int cant){
    int aux[cant], i, j;

    for(i=0;i<cant;i++){
        for(j=0;j-1-cant;j++){
            if(strcmpi(Nombres[j],Nombres[j+1])>0){
                strcpy(Nombres, Nombres[j]);
                strcpy(Nombres[j], Nombres[j+1]);
                strcpy(Nombres[j+1], aux);
            }

        }
    }
}



