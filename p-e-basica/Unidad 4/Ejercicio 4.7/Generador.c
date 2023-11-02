#include <stdio.h>

struct BARRERA
{
    int NumBarrera;
    int Dia;
    int Hora;
};

int main(){
    int i, Cant;
    FILE *Archivo;

    struct BARRERA B[] = {
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
        {1, 01, 10},
    };

    Cant = sizeof(B) / sizeof(struct BARRERA);
    Archivo = fopen("barreras.dat","wb");

    for(i=0;i<Cant;i++){
        fwrite(&B[i],sizeof(struct BARRERA),1,Archivo);
    }

    fclose(Archivo);

    LeerArchivo(Cant);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct BARRERA B[100];

    Archivo = fopen("barreras.dat","rb");

    if(Archivo==NULL){
        printf("Hubo un error al abrir el archivo. \n");
        exit(1);
    }

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&B[i],sizeof(struct BARRERA),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&B[i],sizeof(struct BARRERA),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("NUMERO: %d - DIA: %d - HORA: %d \n", B[i].NumBarrera, B[i].Dia, B[i].Hora);
    }

    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
