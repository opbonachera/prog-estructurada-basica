#include <stdio.h>
#include <string.h>

struct PRODUCTO
{
    char Codigo[5];
    char Descripcion[30];
    float Precio;
    float ImporteTotal;
    int UnidadesVendidas;
};

float ValidarReal(float,float,float);
int   ValidarEntero(int,int,int);
int   CargarProductos(int, struct PRODUCTO[]);
int   Busqueda(char Buscado[], int, struct PRODUCTO[]);
void  CargarVentas(int, struct PRODUCTO[]);
void  MostrarListado(int, struct PRODUCTO[]);
void  ValidarCadena(char[], char[],int);

int main(){
    struct PRODUCTO P[50];
    int CantProductos;

    CantProductos=CargarProductos(50,P);
    CargarVentas(CantProductos,P);
    MostrarListado(CantProductos,P);

    return 0;
}

float ValidarReal(float Li, float Ls, float CFin){
    float Real;
    do{
        printf("");
        scanf("%f",&Real);
    }while(!( (Real>=Li && Real<=Ls)||( Real == CFin) ));
    return Real;
}

int ValidarEntero(int Li, int Ls, int CFin){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);
    }while(!( (Entero>=Li && Entero<=Ls)||( Entero == CFin) ));
    return Entero;
}

void ValidarCadena(char Cadena[], char CFin[], int Largo){
    char CadenaTemp[20];
    do{
        printf("");
        fgets(CadenaTemp, 20, stdin);

        if(CadenaTemp[strlen(CadenaTemp)-1] == '\n'){
            CadenaTemp[strlen(CadenaTemp)-1] = '\0';
        }

    }while( !((strlen(CadenaTemp)==Largo) || strcmpi(CadenaTemp, CFin)==0) );
    strcpy(Cadena, CadenaTemp);
}

int CargarProductos(int Cantidad, struct PRODUCTO P[]){
    char Codigo[20], CFin[3] = "FIN", Descripcion[20];
    int i=0;
    float Precio;

    printf("---CARGA DE PRODUCTOS---\n");
    printf("Ingrese el codigo del producto (2 caracteres)... \n");
    ValidarCadena(Codigo, CFin, 3);

    while(strcmpi(Codigo,"FIN")!=0 && i<Cantidad){
        printf("Ingrese el precio del producto...");
        P[i].Precio = ValidarReal(1.,100000.,1.);

        printf("Ingrese la descripcion del producto...\n");
        ValidarCadena(Descripcion,CFin,2); // Esto esta mal porque si se introduce un fin el programa terminaría.
        strcpy(Descripcion,P[i].Descripcion);

        printf("Ingrese la cantidad de unidades vendidas al mes anterior...\n");
        P[i].UnidadesVendidas=ValidarEntero(1,10000000,1);

        printf("Ingrese el importe total vendido al mes anterior...\n");
        P[i].ImporteTotal = ValidarReal(1.,10000000.,1.);

        i++;

        printf("Ingrese el codigo del producto (2 caracteres) o FIN para terminar... \n");
        ValidarCadena(Codigo, CFin, 3);
    }
    printf("---FIN DE CARGA DE PRODUCTOS---\n");
    printf("--- %d Producto(s) cargados---\n", i);
    return i;
}

int Busqueda(char Buscado[], int Cant, struct PRODUCTO P[]){
    int pos=-1, i=0;

    while(i<Cant && pos==-1){
        if(strcmpi(P[i].Codigo,Buscado)==0){
            pos=i;
        }else{
            i++;
        }
    }

    return pos;
}

void CargarVentas(int Cant, struct PRODUCTO P[]){
    char Codigo[2];
    int i=0, UnidadesVendidas, pos;

    printf("Ingrese la cantidad de unidades vendidas...\n");
    UnidadesVendidas = ValidarEntero(1,50,1);

    while(UnidadesVendidas!=0){
        printf("Ingrese el codigo del producto...\n");
        ValidarCadena(Codigo,"FIN",2);

        pos = Busqueda(Codigo,Cant,P);

        if(pos!=-1){
           P[pos].UnidadesVendidas+=UnidadesVendidas;
           P[pos].ImporteTotal+=P[pos].Precio*UnidadesVendidas;
        }else{
             printf("Producto no encontrado.\n");
        }

        i++;

        printf("Ingrese la cantidad de unidades vendidas o 0 para terminar...\n");
        UnidadesVendidas = ValidarEntero(1,50,1);
    }

    printf("---FIN DE LA CARGA DE VENTAS---\n");
    printf("---Se actualizaron %d productos.\n", i);
}

void MostrarListado(int Cant, struct PRODUCTO P[]){
    int i=0;

    printf("--- LISTADO DE PRODUCTOS ---\n");
    printf("  DESCRIPCION     CANT VENDIDA    IMPORTE VENDIDO   \n");
    for(i=0;i<Cant;i++){
        printf("  %s       %d      %f    \n",P[i].Descripcion, P[i].UnidadesVendidas, P[i].ImporteTotal);
    }
}
