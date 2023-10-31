#include <stdio.h>
#include <string.h>

struct VIAJE
{
    int  NumInterno;
    int  NumTarjeta;
    int  Dia;
    int  Mes;
    char CodigoTarifa[10];
};

struct TARIFA
{
    int   Mes;
    int   CodigoTarifa;
    float Precio;
};

void CargaTarifas(float TARIFA[],int);

int main()
{
    FILE *ArchivoViajes;
    return 0;
}

void CargaTarifas(float Tarifas[], int Mes){
    FILE* ArchivoTarifas;
    struct TARIFA T;
    struct TARIFA Tarifa[8] = {0};
    int i=0;

    ArchivoTarifas = fopen("tarifas.dat","rb");
    if(ArchivoTarifas==NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(&T, sizeof(struct TARIFA),1,ArchivoTarifas);

    while(!feof(ArchivoTarifas)){
        if(T.Mes == Mes){
            Tarifas[i] = T.Precio;
        }
        i++;
        fread(&T,sizeof(struct TARIFA),1,ArchivoTarifas);
    }

    fclose(ArchivoTarifas);
}
