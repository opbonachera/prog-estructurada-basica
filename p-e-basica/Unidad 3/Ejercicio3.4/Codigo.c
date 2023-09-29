#include <stdio.h>
#include <string.h>

void  ValidarCadena(char[],int);
float ValidarReal(float,float,float);
int   ValidarEntero(int,int,int);
int   LeerArchivo(struct PRODUCTO[]);
int   Busqueda(struct PRODUCTO[], int, int);
void  GrabarArchivo(struct PRODUCTO[]);
void  ActualizarDatos(struct PRODUCTO[]);

int main(){
    return 0;
}

void ActualizarDatos(struct PRODUCTO P[], int Cant){
    int i=0, pos;

    printf("Ingrese el porcentaje de incremento de precios...\n");
    scanf("%d",&Incremento);
    for(i=0;i<Cant;i++){
        P[i].Precio = (float) (P[i].Precio) * (Incremento/10);
    }
}

int Busqueda(struct PRODUCTO P[], int Buscado, int Cant){
    int pos=-1, i=0;

    while(i!=-1 && i<Cant){
        if(P[i].Codigo==Buscado){
            pos=1;
        }
    }
    return pos;
}

int Busqueda(struct PRODUCTO P[]){}
void LeerArchivo(struct PRODUCTO P[]){
    int i=0;
    FILE *archivo;

    fopen("alumnos.dat","rb");
    if(arch==NULL){
        printf("Error al leer el archivo. \n");
    }else{
        fread(&P[i],sizeof(PRODUCTO),1,archivo);

        while(!feof(archivo)){
            fread(&P[i],sizeof(PRODUCTO),1,archivo);
            i++;
        }
    }

    fclose(arch);

    return i;
}

void GrabarArchivo(struct PRODUCTO A[], int Cant){
    int i=0;
    FILE * arch;

    printf("---GRABANDO ARCHIVO...\n");
    arch = fopen("precios_actualizados.dat","wb");

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
    }while(!(strlen(CadenaTemp)==Largo));
    strcpy(CadenaTemp,Cadena);
}




