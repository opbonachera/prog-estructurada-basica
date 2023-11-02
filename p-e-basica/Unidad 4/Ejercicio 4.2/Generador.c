#include <stdio.h>

struct SUCURSAL
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
    int i, CantSuc;
    int j, CantPed;
    FILE *ArchivoSuc;
    FILE *ArchivoP;

    struct PRODUCTO P[] = {
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
        {1, "Producto",23.45,23,2,32},
    };

    struct SUCURSAL S[] = {
        {"SucursalUno",1,100},
        {"SucursalUno",1,100},
        {"SucursalUno",43,100},
        {"SucursalUno",67,100},
        {"SucursalDos",12,100},
        {"SucursalDos",23,100}
    };

    CantPed = sizeof(P) / sizeof(struct PEDIDO);
    ArchivoP = fopen("pedidos.dat","wb");

    CantSuc = sizeof(S) / sizeof(struct SUCURSAL);
    ArchivoSuc = fopen("sucursales.dat","wb");

    if(ArchivoP == NULL || ArchivoSuc == NULL){
        printf("Error al escribir el archivo. \n");
        exit(1);
    }

    for(j=0;j<CantPed;j++){
        fwrite(&S[i],sizeof(struct SUCURSAL),1,ArchivoSuc);
    }

    for(i=0;i<CantSuc;i++){
        fwrite(&S[i],sizeof(struct SUCURSAL),1,ArchivoSuc);
    }

    fclose(ArchivoSuc);
    fclose(ArchivoP);

    LeerArchivo(CantSuc);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct SUCURSAL S[100];

    Archivo = fopen("sucursales.dat","rb");

    if(Archivo==NULL){
        printf("Hubo un error al abrir el archivo. \n");
        exit(1);
    }

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&S[i],sizeof(struct SUCURSAL),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&S[i],sizeof(struct SUCURSAL),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("SUCURSAL: %s - CODIGO: %d - CANTIDAD: %d \n", S[i].Suc, S[i].Cod, S[i].Cant);
    }

    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
