#include <stdio.h>
#include <stdlib.h>

struct PRODUCTO
{
    int Cod;
    int Cant;
};

struct PRODUCTO Busqueda(int);

int main()
{
    int i, Cant;
    FILE *Archivo;

    struct PRODUCTO P[] = {
        {1,34},
        {2,56},
        {3,4},
        {4,10},
        {5,34},
        {6,56},
        {7,4},
        {8,10},
        {9,34},
        {10,56},
        {11,4},
        {12,10},
    };

    Cant = sizeof(P) / sizeof(struct PRODUCTO);
    Archivo = fopen("productos.dat","wb");

    if(Archivo==NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    for(i=0;i<Cant;i++){
        fwrite(&P[i],sizeof(struct PRODUCTO),1,Archivo);
    }

    fclose(Archivo);
    LeerArchivo(Cant);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct PRODUCTO P[100];

    Archivo = fopen("productos.dat","rb");

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&P[i],sizeof(struct PRODUCTO),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&P[i],sizeof(struct PRODUCTO),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("CODIGO: %d - CANTIDAD: %d\n", P[i].Cod, P[i].Cant);
    }
    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}

