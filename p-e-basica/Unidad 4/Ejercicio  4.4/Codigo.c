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

int TARIFA
{
    int   Mes;
    int   CodigoTarifa;
    float Precio;
};

int main()
{
    return 0;
}

void CargaTarifas(float Tarifas[]){
    FILE* ArchivoTarifas;
    struct TARIFA Tarifa[8] = {0};
    int i=0;

    ArchivoTarifas = fopen("tarifas.dat","rb");
    if(ArchivoTarifas==NULL){}

    fread(&TARIFA[i], sizeof(struct TARIFA)1,ArchivoTarifa);

    while(!feof(ArchivoTarifa)){
        i++;
        fread(&Tarifa[i],sizeof(struct TARIFA),1,ArchivoTarifa);
    }

    fclose(ArchivoTarifa);
}
