#include <stdio.h>
#include <string.h>

void ValidarCodigo(char[]);
int ValidarCantidad();
float ValidarPrecio();
int RecaudacionTotal();
void OrdernarMostrar();
int CargarProductos(char[],float[]);
void RegistrarVentas(char[][],int[], float[]);
int Busqueda(char[][], char[]);

int main(){}

void ValidarCodigo(char Codigo[]){
    char C[];
    do{
        printf("Ingrese el codigo del producto...\n");
        fflush(stdin);
        fgets(C,4,stdin);
    }while(!(strlen(C)==4 || strcmpi(C,"fin")));
    strcpy(Codigo,C);
}

int ValidarCantidad(){
    int Cantidad;
    do{
        printf("Ingrese la cantidad de productos vendidos...\n");
        scanf("%d",&Cantidad);
    }while(!(Cantidad>0));
    return Cantidad;
}

float ValidarPrecio(){
    float Precio;
    do{
        printf("Ingrese el precio del producto...\n");
        scanf("%f",&Precio);
    }while(!(Precio>0));
    return Precio;
}

int CargarProductos(char Codigos[][4], float Precios[]){
    char Codigo[4], Cod[4];
    float Precio;
    int Cant=0, i=0;

    strcmpi(Cod,ValidarCodigo(Codigo));
    while(strcmpi(Cod,"fin")!=0){
        Cant++;
        Precio=ValidarPrecio();

        strcpy(Codigos[i],Codigo);
        Precios[i] = Precio;

        i++;
        strcmpi(Cod,ValidarCodigo(Codigo));
    }

    printf("--- FIN DE CARGA DE PRODUCTOS ---\n");
    return Cant;
}

int Busqueda(char Codigos[][4], char Buscado[]){
    int i, pos=-1;
    for(i=0;i<50;i++){
        if(strcmpi(Codigos[i], Buscado)==0){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}

void RegistrarVentas(int Codigos[][4], int Ventas[], float Precios[]){
    char Codigo[];
    int Ventas=0, Cantidad, VentaPorProducto[50], i=0, Posicion;
    float Recaudacion = 0.0;

    ValidarCodigo(Codigo);
    Cantidad = ValidarCantidad();

    while(Cantidad>0 && i<50){
        Posicion=Busqueda(Codigos, Codigo);

        if(Posicion!=-1){
            Recaudacion=(float)Precios[i]*Cantidad;
        }else{
            printf("Codigo no encontrado. \n");
        }
        i++;
    }
}
