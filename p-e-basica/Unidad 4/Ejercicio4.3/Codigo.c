#include <stdio.h>

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

struct NOMBRESECTOR
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

void LeerGastos();

int main()
{
    FILE *Archivo;
    FILE *ArchivoCostos;
    Archivo = fopen("LLAMADAS.dat", "rb");
    char SectorAnterior[15];
    struct LLAMADA L;
    struct LLAMADA Llamadas[20];
    int i=0;
    int AcumuladorPorSector, Maximo=0;
    char SectorMax[15];
    float c[3], GastosPorSector=0.;
    struct GASTO G;

    Archivo=fopen("llamadas.dat","rb");
    ArchivoCostos=fopen("costo.dat","rb");
    ArchivoGastos=fopen("gasto.dat","wb");

    if(Archivo==NULL)
    {
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    if(ArchivoCostos==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    if(ArchivoGastos==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    for(int i=0; i<3;i++){
        fread(&c[i],sizeof(float),1,ArchivoCostos);
    }

    fclose(ArchivoCostos);

    fread(&L, sizeof(struct LLAMADA),1,Archivo);
    while(!feof(Archivo))
    {
            strcpy(SectorAnterior,L.Sector);
            AcumuladorPorSector=0;
            G.Total=0;
            while(!feof(Archivo) && strcmpi(SectorAnterior,L.Sector)==0){

                AcumuladorPorSector+=L.Duracion;
                GastosPorSector+=L.Duracion * c[L.Tipo-1];

                fwrite(GastosPorSector,sizeof(struct GASTO),1,ArchivoGastos);
                fread(&L, sizeof(struct LLAMADA),1,Archivo);
            }

            printf("El sector %s acumulo %d minutos. El gasto total fue de %.2f \n",SectorAnterior, AcumuladorPorSector, GastosPorSector);

            if(AcumuladorPorSector>Maximo){
                strcpy(SectorMax,SectorAnterior);
            }

            fread(&L, sizeof(struct LLAMADA),1,Archivo);
    }

    printf("El sector que acumulo mas minutos de llamada fue el %s \n",SectorMax);

    fclose(Archivo);
    return 0;
}

void LeerGastos()
{
    FILE *ArchivoGastos;

    ArchivoGastos = fopen("gastos.dat","rb");

    while(!feof(ArchivoGastos))
    {
        printf("SECTOR: %s - GASTO: %f");
        printf("SECTOR: %s - GASTO: %f");
    }
}
