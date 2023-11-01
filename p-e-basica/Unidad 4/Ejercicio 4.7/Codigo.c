#include <stdio.h>

struct BARRERA
{
    int Dia;
    int Hora;
    int NumBarrera;
};

int main(){
    FILE *ArchBarreras;
    struct BARRERA B;
    int DiaAnt, HoraAnt, BarAnt, ContDia=0, ContHora=0;

    ArchBarreras = fopen("barreras.dat","rb");
    if(ArchBarreras==NULL){
        exit(1);
    }

    fread(&B, sizeof(struct BARRERA),1,ArchBarreras);
    // Bucle inicio de archivo
    while(!feof(ArchBarreras)){
        DiaAnt = B.Dia;
        ContDia=0;
        //Bucle por dia
        do{
            HoraAnt = B.Hora;
            ContHora=0;
            // Bucle por hora
            do{
                ContHora++;
                fread(&B, sizeof(struct BARRERA),1,ArchBarreras);
            // Fin bucle por hora
            }while(!feof(ArchBarreras) && DiaAnt==B.Dia && HoraAnt==B.Hora);
            ContDia+=ContHora;
            printf("En la hora %d ingresaron %d vehiculos. \n", HoraAnt, ContHora);
        //Fin Bucle por dia
        }while(!feof(ArchBarreras) && DiaAnt==B.Dia);
        printf("En el dia %d ingresaron %d vehiculos. \n", DiaAnt, ContDia);
    // Bucle fin de archivo
    }

}
