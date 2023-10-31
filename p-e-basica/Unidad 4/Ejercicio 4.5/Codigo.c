#include <stdio.h>

struct EVENTO
{
    char Cod[10];
    int  NumPuerta;
    int  CantEsp;
};

struct PROMEDIOP
{
    int   NumPuerta;
    float Promedio;
};

int main(){
    FILE *ArchivoEventos;
    FILE *ArchivoPromedio;

    char   EvAnt[10];
    int    ContEvento, ContPuerta, ContTotal, EnAnt;
    struct EVENTO Ev;
    struct PROMEDIOP PP;

    ArchivoEventos = fopen("eventos.dat","rb");
    if(ArchivoEventos == NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(&Ev, sizeof(struct EVENTO),1,ArchivoEventos);
    while(!feof(ArchivoEventos)){
        strcpy(EvAnt, Ev.Cod);
        ContEvento=0;
        // Bucle por evento
        do{
            EnAnt = Ev.NumPuerta;
            ContPuerta=0;
            // Bucle por entrada
            ArchivoPuerta  = fopen("promediopuerta.dat","wb");

                do{
                    ContPuerta++;
                    fread(&Ev, sizeof(struct EVENTO),1,ArchivoEventos);
                }while(!feof(ArchivoEventos) && EvAnt == Ev.Cod && EnAnt == Ev.NumPuerta);

            ContEvento+=ContPuerta;
            PP.Puerta=Ev.NumPuerta;
            PP.Promedio=(float)ContEvento*ContPuerta/100;

            fwrite(&PP,sizeof(struct PROMEDIOP),1,ArchivoPuerta);
            // Fin bucle por entrada
            fclose(ArchivoPuerta);
        }while(!feof(ArchivoEventos) && EvAnt == Ev.Cod);
        // Fin bucle por evento
    }
    fclose(ArchivoEventos);
    // Fin de archivo
}
