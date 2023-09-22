#include <stdio.h>
#include <string.h>

struct PRODUCTO
{
    char Codigo[5];
    float Precio;
    char Descripcion[30];
    int CantVendida;
    float ImporteTotal;
};

int   ValidarEntero(int, int, int);
int   CargarProductos(struct PRODUCTO[]);
int   Busqueda(struct PRODUCTO P[], char[], int);
float ValidarReal(float, float, float);
void  ValidarCadena(int, char[], char[]);
void  CargarVentas(struct PRODUCTO[]);
void  Listado(struct PRODUCTO[], int);

int main(){
    struct PRODUCTO P[50];
    int CantProductos;

    CantProductos = CargarProductos(P);
    CargarVentas(P);
    Listado(P, CantProductos);

    return 0;
}

int CargarProductos(struct PRODUCTO P[]){
    int i=0;
    char Descripcion[3], Codigo[5], CFin[3] = "FIN";

    printf("Ingrese la descripcion del producto o FIN para terminar...\n");
    ValidarCadena(3,Descripcion,CFin);

    while(!(strcmpi(Descripcion,"FIN")==0)){
            strcpy(P[i].Descripcion, Descripcion);

            printf("Ingrese el codigo del producto (5 caracteres)...\n");
            ValidarCadena(5, Codigo, "");
            strcpy(P[i].Codigo, Codigo);

            printf("Ingrese el precio del producto...\n");
            P[i].Precio = ValidarReal(1.,10000000.,1.);

            printf("Ingrese la cantidad de unidades vendidas...\n");
            P[i].CantVendida = ValidarEntero(1,10000000,1);

            printf("Ingrese el importe total vendido al mes anterior...");
            P[i].ImporteTotal = ValidarReal(1.,10000000.,1.);

            i++;

            printf("Ingrese la descripcion del producto o FIN para terminar...\n");
            ValidarCadena(3,Descripcion,CFin);
    }

    return i;
}


int ValidarEntero(int Li, int Ls, int CFin){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);
    }while(!((Entero>=Li&&Entero<=Ls)||(Entero==CFin)));
    return Entero;
}

void ValidarCadena(int Largo, char Cadena[], char CFin[]){
    char CadenaTemp[50];

    do{
        printf("");
        fflush(stdin);
        fgets(CadenaTemp, 50, stdin);

        if(CadenaTemp[strlen(CadenaTemp)-1] == '\n'){
            CadenaTemp[strlen(CadenaTemp)-1] = '\0';
        }

        if(strlen(CadenaTemp)!=Largo){
            printf("La cadena debe tener exactamente %d caracteres.\n", Largo);
        }
        if(strcmpi(CadenaTemp,CFin)==0)
            printf("Finalizando...\n");


    }while(!( (strlen(CadenaTemp)==Largo) || strcmpi(CadenaTemp,CFin)==0));

    strcpy(Cadena,CadenaTemp);
}

float ValidarReal(float Li, float Ls, float CFin){
    float Flotante;
    do{
        printf("");
        scanf("%f",&Flotante);
    }while(!((Flotante>=Li && Flotante<=Ls)||(Flotante==CFin)));
    return Flotante;
}

void Listado(struct PRODUCTO P[], int t){
    int i;

    printf(" DESCRIPCION    CANTIDAD UNIDADES VENDIDAS    IMPORTE TOTAL VENDIDO  ");
    for(i=0;i<t;i++){
        printf("   %s                %d            %d        \n", P[i].Descripcion, P[i].CantVendida, P[i].ImporteTotal);
    }
}

void CargarVentas(struct PRODUCTO P[]){
    int i=0, Cantidad, pos;
    char Codigo[5];

    printf("Ingrese la cantidad de unidades pedidas o 0 para terminar...\n");
    Cantidad=ValidarEntero(1,10000000,0);

    while(!(Cantidad==0)){
        printf("Ingrese el codigo del producto...\n");
        ValidarCadena(5,Codigo,"FIN");

        printf("%s\n",Codigo);
        pos = Busqueda(P,Codigo,5);
        printf("%d",pos);
        if(pos!=-1){
            P[pos].CantVendida+=Cantidad;
        }else{
            printf("Producto no encontrado. \n");
        }

        i++;

        printf("Ingrese la cantidad de unidades pedidas o 0 para terminar...\n");
        Cantidad=ValidarEntero(1,10000000,0);
    }

}

int Busqueda(struct PRODUCTO P[], char Buscado[], int c){
    int i=0, pos=-1;

    while(i<c || pos==-1){
        if(strcmpi(P[i].Codigo, Buscado)==0){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
