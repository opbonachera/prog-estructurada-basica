#include <stdio.h>
#include <string.h>

struct PRODUCTO{
    int Codigo;
    float Precio;
    char Descripcion[50];
};

void  ValidarCadena(char[],int);
float ValidarReal(float,float,float);
int   ValidarEntero(int,int,int);
int   LeerArchivo(struct PRODUCTO[]);
int   Busqueda(struct PRODUCTO[], int, int);
int   LeerArchivoActualizado(struct PRODUCTO[]);
void  GrabarArchivo(struct PRODUCTO[],int);
void  ActualizarDatos(struct PRODUCTO[],int);

int main(){
    struct PRODUCTO P[100];
    int Cantidad;

    Cantidad = LeerArchivo(P);
    ActualizarDatos(P,Cantidad);
    GrabarArchivo(P, Cantidad);
    printf("---ARCHIVO ACTUALIZADO---\n");
    LeerArchivoActualizado(P);

    return 0;
}

void ActualizarDatos(struct PRODUCTO P[], int Cant){
    int i=0, pos, Incremento;

    printf("Ingrese el porcentaje de incremento de precios...\n");
    scanf("%d",&Incremento);
    for(i=0;i<Cant;i++){
        P[i].Precio = (float) ((P[i].Precio) * (Incremento/100.)) + P[i].Precio;
    }
}

int Busqueda(struct PRODUCTO P[], int Buscado, int Cant){
    int pos=-1, i=0;

    while(pos!=-1 && i<Cant){
        if(P[i].Codigo==Buscado){
            pos=i;
        }else{
            pos++;
        }
    }
    return pos;
}

int LeerArchivo(struct PRODUCTO P[]){
    int i=0, j;
    FILE *archivo;

    printf("---LEYENDO ARCHIVO---\n");
    archivo = fopen("PRECIOS.dat","rb");
    if(archivo==NULL){
        printf("Error al leer el archivo. \n");
    }else{
        fread(&P[i],sizeof(struct PRODUCTO),1,archivo);

        while(!feof(archivo)){
            fread(&P[i],sizeof(struct PRODUCTO),1,archivo);
            i++;
        }
    }

    printf("CONTENIDO DEL ARCHIVO");
    for(j=0;j<i;j++){
        printf("CODIGO    %d    PRECIO   %f     DESCRIPCION %s \n", P[j].Codigo, P[j].Precio, P[j].Descripcion);
    }

    fclose(archivo);

    printf("---FIN DE LECTURA---\n");
    return i;
}

int LeerArchivoActualizado(struct PRODUCTO P[]){
    int i=0, j;
    FILE *archivo;

    printf("---LEYENDO ARCHIVO---\n");
    archivo = fopen("precios_actualizados.dat","rb");
    if(archivo==NULL){
        printf("Error al leer el archivo. \n");
    }else{
        fread(&P[i],sizeof(struct PRODUCTO),1,archivo);

        while(!feof(archivo)){
            fread(&P[i],sizeof(struct PRODUCTO),1,archivo);
            i++;
        }
    }

    printf("---CONTENIDO DEL ARCHIVO---\n");
    for(j=0;j<i;j++){
        printf("CODIGO    %d    PRECIO   %f     DESCRIPCION %s \n", P[j].Codigo, P[j].Precio, P[j].Descripcion);
    }

    fclose(archivo);

    printf("---FIN DE LECTURA---\n");
    return i;
}

void GrabarArchivo(struct PRODUCTO P[], int Cant){
    int i=0;
    FILE * arch;

    printf("---GRABANDO ARCHIVO---\n");
    arch = fopen("precios_actualizados.dat","wb");

    if(arch==NULL){
        printf("Hubo un error.\n");
    }else{
        for(i=0;i<Cant;i++){
            fwrite(&P[i],sizeof(struct PRODUCTO),1,arch);
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
    strcpy(Cadena,CadenaTemp);
}




