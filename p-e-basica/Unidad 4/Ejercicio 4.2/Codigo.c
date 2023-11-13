#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    int   PPedido;
    int   CPedido;
};

struct PRODUCTO Busqueda(struct PRODUCTO[], int, int);
int  CargarProductos(struct PRODUCTO[]);

int main(){
    FILE *ArchVentas;

    struct VENTA V;
    struct PRODUCTO P;
    struct PRODUCTO Productos[200];

    char SucAnt[20];
    int  CantProd;

    float TotalSuc=0, TotalEmp=0;
    char SucMax[15];

    CantProd = CargarProductos(Productos);

    ArchVentas = fopen("ventas.dat","rb");
    if(ArchVentas == NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(&V, sizeof(struct VENTA),1,ArchVentas);
    while(!feof(ArchVentas)){
        strcpy(SucAnt,V.Suc);
        TotalSuc=0;

        while(strcmpi(V.Suc,SucAnt)==0 && !feof(ArchVentas)){
            P = Busqueda(Productos, V.Cod, CantProd);

            if(P.Precio!=-1){
                printf("Entro\n");
                TotalSuc+= V.Cant * P.Precio;
            }

            fread(&V, sizeof(struct VENTA),1,ArchVentas);
        }
        printf("La sucursal %s ha recaudado un total de %.2f\n", SucAnt, TotalSuc);
        TotalEmp+=TotalSuc;
    }
}

struct PRODUCTO Busqueda(struct PRODUCTO P[], int CodBusq, int Cant){
    int     i=0, Ban=-1;
    struct  PRODUCTO ProdEncontrado;

    while(Ban==-1 && i<Cant){
        if(P[i].Cod == CodBusq){
            ProdEncontrado = P[i];
            Ban=1;
            printf("Encontrado\n");
            printf("CodBusq %d P[i] %d\n", CodBusq, P[i].Cod);
        }else{
            i++;
            printf("No encontrado\n");
        }
    }

    if(Ban==-1){
        ProdEncontrado.Precio = -1;
    }

    return ProdEncontrado;
}

int CargarProductos(struct PRODUCTO P[]){
    FILE *ArchProd;

    struct PRODUCTO Prod;
    ArchProd = fopen("productos.dat","rb");

    int i=0;

    if(ArchProd == NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(&P[i], sizeof(struct PRODUCTO), 1, ArchProd);
    while(!feof(ArchProd)){
        i++;
        fread(&P[i], sizeof(struct PRODUCTO), 1, ArchProd);
    }

    fclose(ArchProd);
    printf("Cant cargados: %d", i);
    return i;
}
