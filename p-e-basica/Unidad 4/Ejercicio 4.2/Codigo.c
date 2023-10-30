#include <stdio.h>
#include <string.h>

struct VENTAS
{
    char Sucursal[15];
    int  Codigo;
    int  Cantidad;
};

struct PRODUCTO
{
    int Codigo;
    char Desc[20];
    float Precio;
    int Stock;
    int PuntoPedido;
    int CantPedido;
};

struct PEDIDO
{
    int Codigo;
    int Cantidad;
};

int Busqueda(struct PRODUCTO[], int, int);

int main(){

    FILE *Archivo;
    FILE *Archivo2;

    int i=0, Posicion;
    struct VENTAS V;
    struct PRODUCTO Productos[200], auxProducto;
    char sucAnterior[30];
    float TotalPorSucursal=0, CantTotal=0;
    Archivo = fopen("productos.dat","rb");

    if(Archivo==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    fread(&auxProducto, sizeof(struct PRODUCTO),1,Archivo);

    while(!feof(Archivo)){
        Productos[i] = auxProducto;
        i++;
        fread(&auxProducto,sizeof(struct PRODUCTO),1,Archivo);
    }

    fclose(Archivo);

    Archivo2 = fopen("ventas.dat","rb");

    if(Archivo2 == NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    fread(&V,sizeof(struct VENTAS),1,Archivo2);

    while(feof(Archivo)))
}
