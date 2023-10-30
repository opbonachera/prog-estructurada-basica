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

int Busqueda();

int main()
{
    FILE *Archivo;
    FILE *ArchivoCostos;
    Archivo = fopen("LLAMADAS.dat", "rb");
    int LlamadaPorSector[3]=0, CostoPorTipo[3]=0;
    char SectorAnterior[15];
    struct LLAMADA L;


    ArchivoCostos=fopen("gastos.dat","rb");

    if(ArchivoCostos==NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    for(i=0;i<3;i++){
        fread(&CostoPorTipo[i],sizeof(float),1,ArchivoCostos);
    }

    if(Archivo==NULL){
        printf("ERROR");
        exit(1);
    }

    fread(&L,sizeof(struct LLAMADA),1,Archivo);

    while(!feof(Archivo)){
        LlamadaPorSector;
        strcpy(SectorAnterior,L.Sector);

        while(!feof(Archivo) && strcmpi(SectorAnterior,L.Sector==0)){
            Tipo = L.Tipo - 1;
            LlamadaPorSector[Tipo]++;
        }
    }

}
