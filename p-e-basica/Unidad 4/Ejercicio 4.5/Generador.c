#include <stdio.h>

struct EVENTO
{
    char Cod[10];
    int  NumPuerta;
    int  CantEsp;
};

int main(){
    int i, Cant;
    FILE *Archivo;

    struct EVENTO V[] = {
        {"PARTIDO",1,100},
        {"PARTIDO",1,100},
        {"PARTIDO",1,100},
        {"PARTIDO",2,100},
        {"PARTIDO",2,100},
        {"PARTIDO",2,100},
        {"PARTIDO",3,100},
        {"PARTIDO",3,100},
        {"FIESTA",5,100},
        {"FIESTA",5,100},
        {"FIESTA",6,100},
        {"FIESTA",6,100},
        {"RECITAL",6,100},
        {"RECITAL",6,100},
        {"RECITAL",6,100},
        {"RECITAL",11,100},
        {"RECITAL",11,100},
        {"RECITAL",12,100},
        {"RECITAL",12,100},
        {"RECITAL",13,100},
        {"RECITAL",13,100},
        {"RECITAL",13,100}
    };

    Cant = sizeof(V) / sizeof(struct EVENTO);
    Archivo = fopen("eventos.dat","wb");

    for(i=0;i<Cant;i++){
        fwrite(&V[i],sizeof(struct EVENTO),1,Archivo);
    }

    fclose(Archivo);

    LeerArchivo(Cant);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct EVENTO E[100];

    Archivo = fopen("eventos.dat","rb");

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&E[i],sizeof(struct EVENTO),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&E[i],sizeof(struct EVENTO),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("CODIGO: %s                 - PUERTA %d                   - CANTESP %d         \n", E[i].Cod, E[i].NumPuerta, E[i].CantEsp);
    }
    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}

