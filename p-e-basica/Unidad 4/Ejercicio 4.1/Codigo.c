#include <stdio.h>

typedef struct{
    char  Programa[35];
    float Rating;
    int   NumeroCanal;
}CANAL;

typedef struct{
    int NumCanal;
    int Promedio;
}PROMEDIOCANAL;

void GrabarArchivo(PROMEDIOCANAL[], int);

int main(){
    FILE *Archivo;
    int NumeroAnterior, RatingMenor, Mayor=0, i=0;
    CANAL C;
    PROMEDIOCANAL VCanal[];

    Archivo = fopen("Rating.dat","rb");
    if(Archivo==NULL){
        printf("Hubo un error. \n");
    }else{

        fread(&C, sizeof(CANAL),1,Archivo);

        while(!feof(Archivo)){
            RatingMenor = 0;
            NumeroAnterior = CANAL.NumeroCanal;

            printf("---CANALES CON MENOS PUNTOS DE RATING---\n");

            do{

                if(CANAL.Rating <= 15) RatingMenor++;
                if(CANAL.Rating > Mayor){
                    Mayor = CANAL.NumeroCanal;
                }
 
                PROMEDIOCANAL[i].NumCanal = CANAL.NumeroCanal;
                PROMEDIOCANAL[i].Promedio = CANAL.Rating;

                fread(&C,sizeof(CANAL),1,Archivo);
                
                i++;
            } while(CANAL.NumeroCanal == NumeroAnterior);
            

            printf("Canal %d\n", CANAL.NumeroCanal);
        }

        printf("El canal con mayor numero de rating es el %d\n",Mayor);
        fclose(Archivo);
    }

    GrabarArchivo(VCanal,i);
}

void GrabarArchivo(PROMEDIOCANAL VCanal[], int N){
    int i=0;
    FILE *Archivo;
    
    Archivo = fopen("promedio.dat","wb");

    if(Archivo!=NULL){
        for(i=0, i<N; i++){
            fwrite(&VCanal[i], sizeof(CANAL),1,Archivo);
        }
    }else{
        printf("Hubo un error al abrir el archivo. \n");
    }
    fclose(Archivo);
    printf("---ARCHIVO GRABADO CORRECTAMENTE---\n");
}