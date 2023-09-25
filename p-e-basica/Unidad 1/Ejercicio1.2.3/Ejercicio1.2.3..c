#include <stdio.h>
#include <string.h>

int CargarAlumnos(char[][100], int[]);
int Busqueda(char[][100], char[], int);
int ValidarDni();
void OrdenarAlumnos(char[][100], int);

int main(){
    char NombreApellido[50][100], Nombre[100];
    int Dni[50], pos, CantAlumnos;


    CantAlumnos = CargarAlumnos(NombreApellido, Dni);
    printf("Carga Finalizada \n");

    printf("Ingrese el nombre a buscar...\n");
    fgets(Nombre, 100, stdin);

    Nombre[strlen(Nombre)-1] = '\0';

    while(strcmpi(Nombre, "nobuscarmas")!=0){
        pos = Busqueda(NombreApellido, Nombre, CantAlumnos);

        if(pos!=-1){
            printf("El DNI del alumno es %d. \n", Dni[pos]);
        }else{
            printf("El alumno no fue registrado. \n");
        }

        printf("Ingrese el nombre a buscar...\n");
        fgets(Nombre, 100, stdin);
        Nombre[strlen(Nombre)-1] = '\0';
    }

    OrdenarAlumnos(NombreApellido,CantAlumnos);
    return 0;
}

int CargarAlumnos(char Nombres[][100], int Dni[]){
    char Nombre[100];
    int i=0, cant=0, DniTemp;

    printf("Ingrese el nombre del alumno...\n");
    fflush(stdin);
    gets(Nombre);

    while(strcmpi(Nombre,"FIN")!=0 && i<50){

        DniTemp=ValidarDni();
        Dni[i] = DniTemp;

        // Nombre[strlen(Nombre)-1] = '\0';

        strcpy(Nombres[i], Nombre);
        i++;
        cant++;

        printf("Ingrese el nombre del alumno...\n");
        fflush(stdin);
        gets(Nombre);
    }

    return cant;
}

int Busqueda(char Nombres[][100], char Nombre[], int Cant){
    int i=0, pos=-1;

    while(i<Cant && pos==-1){
        if(strcmpi(Nombres[i], Nombre)==0){
            pos=i;
        }else{
            i++;
        }
    }

    return pos;
}

int ValidarDni(){
    int Dni;
    do{
        printf("Ingrese el DNI del alumno...\n");
        scanf("%d",&Dni);
    }while(!(Dni>0 && Dni<100000000));
    return Dni;
}

void OrdenarAlumnos(char Nombres[][100], int cant){
    int aux[100], i, j;

    for(i=0;i<cant;i++){
        for(j=0;j<cant-1-i;j++){
            if(strcmpi(Nombres[j],Nombres[j+1])>0){
                strcpy(aux, Nombres[j]);
                strcpy(Nombres[j], Nombres[j+1]);
                strcpy(Nombres[j+1], aux);
            }

        }
    }

    printf("---LISTADO DE ALUMNOS EN ORDEN ALFABETICO---\n");
    for(i=0;i<cant;i++){
        puts(Nombres[i]);
        printf("\n");
    }
}
