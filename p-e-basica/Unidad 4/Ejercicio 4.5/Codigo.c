#include <stdio.h>
#include <stdlib.h>

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

    char  Minimo[30];
    float Promedio;
    int   CantPorEvento=0;
    int   CantPuerta=0;

    char CodAnt[10];
    int  PuertaAnt;

    Archivo = fopen("eventos.dat","rb");
    ArchivoProm = fopen("eventopromedio.dat","wb");
    if(Archivo == NULL || ArchivoProm == NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(&E, sizeof(struct EVENTO), 1, Archivo);
    while(!feof(Archivo)){
            strcpy(CodAnt,E.Cod);
            CantPorEvento=0;

            while(strcmpi(CodAnt,E.Cod)==0 && !feof(Archivo)){
                PuertaAnt = E.NumPuerta;
                CantPuerta=0;

                while(PuertaAnt == E.NumPuerta && strcmpi(CodAnt,E.Cod)==0 && !feof(Archivo)){

                    CantPuerta+=E.CantEsp;
                    fread(&E, sizeof(struct EVENTO), 1, Archivo);
                }
                CantPorEvento+=CantPuerta;

                EP.NumPuerta = PuertaAnt;
                EP.Prom = (float)(CantPorEvento)/(CantPuerta);

                fwrite(&EP,sizeof(struct EVENTOPROM),1,ArchivoProm);
            }
            printf("Al evento de codigo %s asistieron %d espectadores.\n", CodAnt, CantPorEvento);
    }

    fclose(Archivo);
    fclose(ArchivoProm);

    return 0;
}

