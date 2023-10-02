#include <stdio.h>
#include <string.h>

int   ValidarEntero(int,int,int);
int   LeerArchivo(struct PASAJERO[],struct VUELO[]);
float ValidarReal(float,float,float);
void  ValidarCadena(char[],int);

struct VUELO{
    char CodigoAerolinea[10];
    int  Dia;
    int  NumeroVuelo;
    float CostoPasaje;
    int Pasajeros;
};

struct PASAJERO{
    int DNI;
    int NumeroVuelo;
};

int main(){
    return 0;
}

void LeerArchivo(struct PASAJERO[], struct VUELO[]){
    int i=0;
    FILE *archivo;

    archivo = fopen("Vuelos.dat","rb");

    if(archivo==NULL){
        printf("Se produjo un error al abrir el archivo. \n");
    }else{
        while(!feof(archivo)){
            fread(&Vuelo[i],sizeof(struct VUELO),1,archivo);
            i++;
        }
    }
    fclose(archivo);
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
