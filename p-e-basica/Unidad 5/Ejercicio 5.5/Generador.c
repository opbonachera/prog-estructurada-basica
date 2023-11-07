#include <stdio.h>

struct CONTACTO
{
    char Nombre[20];
    int  Numero;
};

void LeerArchivo(int);

int main()
{
    int i, Cant;
    FILE *Archivo;

    struct CONTACTO C[] = {
        {"ORNELLA",3244234},
        {"PAULA",32443423},
        {"BONACHERA",432342},
        {"SOLANGE",1212213},
        {"LILY",23223},
        {"TANIA",4324343},
        {"CAROLINA",232123}
    };

    Cant = sizeof(C) / sizeof(struct CONTACTO);
    Archivo = fopen("agenda.dat","wb");

    if(Archivo==NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    for(i=0;i<Cant;i++){
        fwrite(&C[i],sizeof(struct CONTACTO),1,Archivo);
    }

    fclose(Archivo);
    LeerArchivo(Cant);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct CONTACTO C[100];

    Archivo = fopen("agenda.dat","rb");

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&C[i],sizeof(struct CONTACTO),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&C[i],sizeof(struct CONTACTO),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("NOMBRE: %s            --- NUMERO: %d        \n",C[i].Nombre, C[i].Numero);
    }

    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}

