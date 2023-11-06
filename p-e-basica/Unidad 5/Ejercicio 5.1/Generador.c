#include <stdio.h>

struct PRODUCTO
{
    char  Desc[15];
    float Precio;
    int   CodProducto;
};

int main(){
    int i, Cant;
    FILE *Archivo;

    struct PRODUCTO P[] = {
        {"AURICULARES",3456.76,1},
        {"MICROFONO",5445.65,2},
        {"CABLE USB",56767.5,3},
        {"MONITOR HD",299999,4}
    };

    Cant = sizeof(P) / sizeof(struct PRODUCTO);
    Archivo = fopen("productos.dat","wb");

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
         printf("CODIGO: %d          - DESCRIPCION %s                   - PRECIO %f         \n", P[i].CodProducto, P[i].Desc, P[i].Precio);
    }
    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
