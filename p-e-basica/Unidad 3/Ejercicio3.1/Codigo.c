#include <stdio.h>
#include <string.h>

struct ALUMNO{
    char NombreApellido[3];
    float NotaProm;
    int Dni;
    int Nota1;
    int Nota2;
};

int   ValidarEntero(int,int,int);
int   CargarAlumnos(struct ALUMNO[], int);
float ValidarReal(float,float,float);
void  ValidarCadena(char[],int);
void  GrabarArchivo(struct ALUMNO[],int);
void  LeerArchivo(struct ALUMNO[],int);

int main(){
    struct ALUMNO A[80];
    int CantCargada;

    CantCargada=CargarAlumnos(A,80);
    GrabarArchivo(A,CantCargada);
    LeerArchivo(A, CantCargada);

    return 0;
}

void LeerArchivo(struct ALUMNO A[], int Cant){
    int i=0;
    FILE *arch;

    fopen("alumnos.dat","rb");
    if(arch==NULL){
        printf("Error al leer el archivo. \n");
    }else{
        for(i=0;i<Cant;i++){
            fread(&A[i], sizeof(struct ALUMNO),1,arch);
        }
    }

    fclose(arch);

    printf("   DNI     Nombre      Notas      Promedio \n");
    for(i=0;i<Cant;i++){
    printf("   %d        %s        %d %d        %f     \n", A[i].Dni, A[i].NombreApellido, A[i].Nota1, A[i].Nota2, A[i].NotaProm);

    }
}

int CargarAlumnos(struct ALUMNO A[], int CantMax){
    int i=0, Dni;
    struct ALUMNO a;

    printf("---CARGA DE ALUMNOS---\n");

    printf("Ingrese el DNI del alumno o 0 para terminar la carga...\n");
    Dni = ValidarEntero(1,10,0);

    while(!(Dni==0)){
        a.Dni=Dni;
        printf("Ingrese el nombre y apellido del alumno...\n");
        ValidarCadena(a.NombreApellido,3);

        printf("Ingrese la primer nota del alumno...\n");
        a.Nota1 = ValidarEntero(1,10,1);

        printf("Ingrese la segunda nota del alumno...\n");
        a.Nota2 = ValidarEntero(1,10,1);

        a.NotaProm = (float) (a.Nota1+a.Nota2) / 2;

        A[i] = a;
        i++;

        printf("Ingrese el DNI del alumno o 0 para terminar la carga...\n");
        Dni = ValidarEntero(1,10,0);
    }

    printf("---FIN DE CARGA DE ALUMNOS---\n");
    printf("Se cargaron %d alumnos\n",i);

    return i;
}

void GrabarArchivo(struct ALUMNO A[], int Cant){
    int i=0;
    FILE * arch;

    printf("---GRABANDO ARCHIVO...\n");
    arch = fopen("alumnos.dat","wb");

    if(arch==NULL){
        printf("Hubo un error.\n");
    }else{
        for(i=0;i<Cant;i++){
            fwrite(&A[i],sizeof(struct ALUMNO),1,arch);
        }
    }
    fclose(arch);

    printf("---ARCHIVO GRABADO---\n");
}

int ValidarEntero(int Li,int Ls,int Cf){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);
    }while(!((Entero>=Li && Entero<=Ls)||(Entero==Cf)));
    return Entero;
}

float ValidarReal(float Li,float Ls,float Cf){
    float Real;
    do{
        printf("");
        scanf("%f",&Real);
    }while(!((Real>=Li && Real<=Ls)||(Real==Cf)));
    return Real;
}


void ValidarCadena(char Cadena[], int Largo){
    char CadenaTemp[100];
    do{
        printf("");
        fflush(stdin);
        fgets(CadenaTemp,100,stdin);

        if(CadenaTemp[strlen(CadenaTemp)-1] == '\n'){
            CadenaTemp[strlen(CadenaTemp)-1] = '\0';
        }

        if(strlen(CadenaTemp)!=Largo){
            printf("La cadena debe tener exactamente %d caracteres. \n",Largo);
        }
    }while(!(strlen(CadenaTemp)==Largo));
    strcpy(Cadena, CadenaTemp);
}
