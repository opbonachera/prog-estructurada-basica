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
    struct PRODUCTO P;
    struct VENTAS V;
    int i=0,j, SucAnterior;
    float VentasPorSuc=0, VentasTotales=0;

    Archivo=fopen("productos.dat","rb");

    if(Archivo==NULL){
        printf("Hubo un error.\n");
        exit(1);
    }

    fread(&V, sizeof(struct PRODUCTO),1, Archivo);

    while(!feof(Archivo)){
        VentasPorSuc = 0;
        strcpy(SucAnterior, V.Sucursal);

        while(!feof(Archivo) && strcmpi(SucAnterior,V.Sucursal) == 0){
            Posicion = Busqueda(Productos, V.Codigo);

            VentasPorSuc+=Productos[p].Precio * V.Cantidad;
            VentasVec[p]+=Productos[p].Precio * V.Cantidad;
            fread(&P, sizeof(struct PRODUCTO),1, Archivo);
        }

        VentasTotales+=VentasPorSuc;
    }


    return 0;
}

int Busqueda(struct PRODUCTO[], int CodigoABuscar){
    int Pos=-1, int i=0;

    while(Pos==-1){
        if(Producto[i].Codigo==CodigoABuscar){
            Pos=i;
        }else{
            i++;
        }
    }

    return Pos;
}
