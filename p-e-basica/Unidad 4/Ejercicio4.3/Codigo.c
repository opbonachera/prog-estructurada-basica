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
    FILE *ArchivoGastos;
    FILE *ArchivoSector;
    Archivo = fopen("LLAMADAS.dat", "rb");
    char SectorAnterior[15];
    char SectorMax[15];
    char NombreSectorArchivo[15];
    int i=0, ContadorPorTipo[3]={0};
    int AcumuladorPorSector, Maximo=0;
    float c[3], GastosPorSector=0.;
    struct LLAMADA L;
    struct LLAMADA Llamadas[20];
    struct GASTO G;
    struct LLAMADACOSTO LC;


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

    // Lectura de los costos por llamada
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
            NombreSectorArchivo = strcat(L.Sector,".dat");
            // Concatenar el nombre del sector con el string ".dat" y abrir el archivo.
            ArchivoSector = fopen(NombreSectorArchivo,"wb");

            while(!feof(Archivo) && strcmpi(SectorAnterior,L.Sector)==0){

                AcumuladorPorSector+=L.Duracion;
                ContadorPorTipo[L.Tipo-1]++;
                GastosPorSector+=L.Duracion * c[L.Tipo-1];

                LC.Duracion = L.Duracion;
                LC.Costo = L.Duracion * c[L.tipo-1];
                LC.Tipo = L.Tipo;

                fwrite(&LC,sizeof(struct LLAMADACOSTO),1,ArchivoSector);
                // Escribir estos datos en llamada costo y despues escribir en el archivo con el nombre que se creo arriba
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

