#include <stdio.h>
#include <string.h>

struct LLAMADA
{
    char Sector[15];
    int  Duracion;
    int  Tipo;
};

struct LLAMADACOSTO
{
    int   Duracion;
    int   Tipo;
    float Costo;
};

struct GASTO
{
    char Sector[15];
    float Total;
};

void LeerCostos(float[]);

int main(){
    FILE *ArchivoLlamadas;
    FILE *ArchivoGastos;
    FILE *ArchivoValorizado;
    FILE *Sector;

    char    NombreSector[20];
    char    SecAnterior[20];
    int     TipoAnterior, AcumuladorPorSector, Contador;
    float   CostoPorSector[3] = {0};
    struct  GASTO G;
    struct  LLAMADA L;
    struct  LLAMADACOSTO LC;

    LeerCostos(CostoPorSector);

    ArchivoLlamadas = fopen("llamadas.dat","rb");
    if(ArchivoLlamadas==NULL){
        printf("Error al abrir el archivo. \n");
    }

    ArchivoGastos = fopen("gasto.dat","wb");
    if(ArchivoGastos == NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    // Lectura del archivo que contiene las llamadas
    fread(&L, sizeof(struct LLAMADA),1,ArchivoLlamadas);

    while(!feof(ArchivoLlamadas)){
        // Copia del codigo de sector
        strcpy(SecAnterior, L.Sector);
        strcat(L.Sector,".dat");
        AcumuladorPorSector = 0;
        G.Total=0;

        // Bucle por sector
        while(!feof(ArchivoLlamadas) && strcmpi(SecAnterior,L.Sector)==0){

            TipoAnterior = L.Tipo;
            AcumuladorPorSector+= L.Duracion;
            Contador=0;
            ArchivoValorizado = fopen(NombreSector, "wb");
            // Bucle por tipo de llamada
            while(!feof(ArchivoLlamadas) && strcmpi(SecAnterior,L.Sector)==0 && TipoAnterior==L.Tipo){
                Contador++;

                LC.Tipo = L.Tipo;
                LC.Duracion = L.Duracion;
                LC.Costo = L.Duracion * CostoPorSector[L.Tipo-1];

                fread(&L, sizeof(struct LLAMADA),1,ArchivoLlamadas);
            }
            fwrite(&LC,sizeof(struct LLAMADACOSTO),1,ArchivoValorizado);
            printf("Se realizaron %d llamadas del tipo %d.\n", Contador, TipoAnterior);

            strcpy(G.Sector,SecAnterior);
            G.Total+=L.Duracion * CostoPorSector[L.Tipo-1];
        }

        printf("El sector %s hablo durante %d minutos. \n", SecAnterior, AcumuladorPorSector);
        fclose(ArchivoValorizado);
        fwrite(&G, sizeof(struct GASTO),1,ArchivoGastos);
        fread(&L, sizeof(struct LLAMADA),1,ArchivoLlamadas);
    }

    ImprimirGastos();
    fclose(ArchivoLlamadas);
    fclose(ArchivoGastos);
}

void LeerCostos(float Costos[])
{
    FILE *ArchivoCostos;

    ArchivoCostos = fopen("costo.dat","rb");
    if(ArchivoCostos==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }


    for(int i=0;i<3;i++){
        fread(&Costos[i], sizeof(float),1, ArchivoCostos);
    }

    fclose(ArchivoCostos);
}

void ImprimirGastos(){
    FILE *ArchivoGastos;
    ArchivoGastos = fopen("gasto.dat","rb");
    struct GASTO G;
    if(ArchivoGastos==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    printf("   SECTOR     TOTAL    \n");
    while(!feof(ArchivoGastos)){
        fread(&G,sizeof(struct GASTO),1,ArchivoGastos);
        printf("   %s     %.2f    \n", G.Sector, G.Total);
    }

    fclose(ArchivoGastos);
}
