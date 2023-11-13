#include <stdio.h>

struct VENTA
{
    char Suc[15];
    int  Cod;
    int  Cant;
};

struct PRODUCTO{
    int   Cod;
    char  Desc[20];
    float Precio;
    int   Stock;
    int   PuntoPedido;
    int   CantPedido;
};

int main(){
    GenerarArchProd();
    GenerarArchVen();

    LeerVentas(6);
    LeerProductos(10);

    return 0;
}

int GenerarArchVen(){
    int i, CantVentas;

    FILE *ArchVentas;

    struct VENTA V[] = {
        {"SucursalUno",1,100},
        {"SucursalUno",1,100},
        {"SucursalUno",43,100},
        {"SucursalUno",67,100},
        {"SucursalDos",12,100},
        {"SucursalDos",23,100}
    };

    ArchVentas = fopen("ventas.dat","wb");
    if(ArchVentas==NULL){
        printf("Error.\n");
        exit(1);
    }

    CantVentas = sizeof(V) / sizeof(struct VENTA);

    for(i=0;i<CantVentas;i++){
        fwrite(&V[i], sizeof(struct VENTA),1,ArchVentas);
    }

    fclose(ArchVentas);
    return 0;
}

int GenerarArchProd(){
    int j, CantProd;

    FILE *ArchProd;

    struct PRODUCTO P[] = {
        {1, "Producto",23.45,23,2,32},
        {2, "Producto",23.45,23,2,32},
        {3, "Producto",23.45,23,2,32},
        {4, "Producto",23.45,23,2,32},
        {5, "Producto",23.45,23,2,32},
        {6, "Producto",23.45,23,2,32},
        {7, "Producto",23.45,23,2,32},
        {8, "Producto",23.45,23,2,32},
        {9, "Producto",23.45,23,2,32},
    };

    ArchProd = fopen("productos.dat","wb");
    if(ArchProd == NULL){
        printf("Error.\n");
        exit(1);
    }

    CantProd = sizeof(P) / sizeof(struct PRODUCTO);

    for(j=0;j<CantProd;j++){
        fwrite(&P[j], sizeof(struct PRODUCTO),1,ArchProd);
    }

    fclose(ArchProd);
}

void LeerProductos(){
    FILE *Archivo;
    int i=0;
    struct PRODUCTO P[100];

    Archivo = fopen("productos.dat","rb");

    if(Archivo==NULL){
        printf("Error.\n");
        exit(1);
    }

    fread(&P, sizeof(struct PRODUCTO),1,Archivo);
    while(!feof(Archivo)){
        printf("%d - %s",P[i].Cod, P[i].Desc);
        fread(&P, sizeof(struct PRODUCTO),1,Archivo);
    }

    fclose(Archivo);
}

void LeerVentas(int Cant){
    FILE *Archivo;
    int i=0;
    struct VENTA V[100];

    Archivo = fopen("ventas.dat","rb");

    if(Archivo==NULL){
        printf("Hubo un error al abrir el archivo. \n");
        exit(1);
    }

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&V[i],sizeof(struct VENTA),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&V[i],sizeof(struct VENTA),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("SUCURSAL: %s - CODIGO: %d - CANTIDAD: %d \n", V[i].Suc, V[i].Cod, V[i].Cant);
    }

    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
