#include <stdio.h>

struct VISITANTE
{
    char NomAp[10];
    char Localidad[20];
    char Email[20];
    int  DNI;
    int  Dia;
    int  Mes;
    int  Anio;
};

int main(){
    int i, Cant;
    FILE *Archivo;

    struct VISITANTE V[] = {
        {"ORNELLA","San Justo","obonachera@gmail.com",46119546,02,11,2023},
        {"ORNELLA","San Justo","obonachera@gmail.com",46119546,02,11,2023},
        {"ORNELLA","San Justo","obonachera@gmail.com",46119546,02,11,2023}
    };

    Cant = sizeof(V) / sizeof(struct VISITANTE);
    Archivo = fopen("visitantes.dat","wb");

    for(i=0;i<Cant;i++){
        fwrite(&V[i],sizeof(struct VISITANTE),1,Archivo);
    }

    fclose(Archivo);

    LeerArchivo(Cant);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct VISITANTE V[100];

    Archivo = fopen("visitantes.dat","rb");

    if(Archivo==NULL){
        printf("Hubo un error al abrir el archivo. \n");
        exit(1);
    }

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&V[i],sizeof(struct VISITANTE),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&V[i],sizeof(struct VISITANTE),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("NOMBRE: %s - EMAIL: %s - LOCALIDAD: %s \n", V[i].NomAp, V[i].Email, V[i].Localidad);
    }

    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
