#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EVENTO{
    char Cod[10];
    int  NumPuerta;
    int  CantEsp;
};

struct EVENTOPROM{
    int   NumPuerta;
    float Prom;
};

int main(){
    FILE *Archivo;
    FILE *ArchivoProm;

    struct EVENTO E;
    struct EVENTOPROM EP;

    char  Minimo[10];
    float Promedio;
    int   CantPorEvento=0;
    int   CantPuerta=0;

    int Spuerta[15] = {0};
    int Cpuerta[15] = {0};

    char CodAnt[10];
    int  PuertaAnt;

    int Ban=0;
    int Min;

    Archivo = fopen("eventos.dat","rb");
    ArchivoProm = fopen("eventopromedio.dat","wb");
    if(Archivo == NULL || ArchivoProm == NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    printf("---LEYENDO ARCHIVO---");
    fread(&E, sizeof(struct EVENTO), 1, Archivo);
    while(!feof(Archivo)){
            strcpy(CodAnt,E.Cod);
            CantPorEvento=0;

            while(strcmpi(CodAnt,E.Cod)==0 && !feof(Archivo)){
                CantPorEvento+=E.CantEsp;

                Spuerta[E.NumPuerta-1]+=E.CantEsp;
                Cpuerta[E.NumPuerta-1]++;

                fread(&E, sizeof(struct EVENTO), 1, Archivo);
            }

            if(Ban==0 && CantPorEvento < Min){
                Ban=1;
                Min = CantPorEvento;
                strcpy(Minimo, E.Cod);
            }
            printf("Al evento de codigo %s asistieron %d espectadores.\n", CodAnt, CantPorEvento);
    }

    printf("El evento %s obtuvo menor cantidad de espectadores.\n", Minimo);

    fclose(Archivo);

    // Calculo del promedio

    for(int i=0;i<15;i++){
        if(Cpuerta[i]!=0){
            EP.NumPuerta = i+1;
            EP.Prom = (Spuerta[i] / Cpuerta[i])*(1.5);
        }else{
            EP.NumPuerta = i+1;
            EP.Prom = 0;
        }
        fwrite(&EP,sizeof(struct EVENTOPROM),1,ArchivoProm);
    }

    fclose(ArchivoProm);

    return 0;
}

