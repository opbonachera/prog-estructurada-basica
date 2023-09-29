#include <stdio.h>
#include <string.h>

struct PRODUCTO{
    int  Codigo;
    int  Stock;
    char Descripcion[50];
};
int  ValidarEntero(int,int,int);
float ValidarReal(float,float,float);
void ValidarCadena(char[],int);
void GrabarArchivo(struct PRODUCTO[]);
void CargaInicial(struct PRODUCTO[]);
void  CargarVentas(struct PRODUCTO[]);
int  Busqueda(struct PRODUCTO[], int, int);

int main(){
    struct PRODUCTO P[3];

    CargaInicial(P);
    CargarVentas(P);
    GrabarArchivo(P);

    return 0;
}



void GrabarArchivo(struct PRODUCTO P[]){
    int i=0;
    FILE *archivo;

    archivo = fopen("stock.dat","wb");

    if(archivo!=NULL){
        for(i=0;i<3;i++){
            fwrite(&P[i],sizeof(struct PRODUCTO),1,archivo);
        }
    }else{
        printf("Hubo un error al abrir el archivo. \n");
    }
    fclose(archivo);
}

void CargarVentas(struct PRODUCTO P[]){
    int pos, Codigo, ArtSolicitados;
    FILE *archivo;

    archivo = fopen("faltantes.dat","wb");

    printf("---CARGA DE VENTAS---\n");
    printf("Ingrese el codigo de la venta o 0 para terminar...\n");
    Codigo = ValidarEntero(1,15,0);

    while(Codigo!=0){
        pos = Busqueda(P,Codigo,3);

        if(pos!=-1){
        printf("Ingrese la cantidad de articulos solicitados...\n");
        ArtSolicitados = ValidarEntero(1,1000000,1);

        if(ArtSolicitados>P[pos].Stock){
            printf("No hay suficientes articulos en stock. \n");
            fwrite(&P[pos].Codigo, sizeof(struct PRODUCTO),1,archivo);
        }else{
            P[pos].Stock-=ArtSolicitados;
        }

        printf("Venta cargada correctamente. \n");
    }else{
        printf("Articulo no encontrado. \n");
    }

        printf("Ingrese el codigo de la venta o 0 para terminar...\n");
        Codigo = ValidarEntero(1,15,0);
    }

    fclose(archivo);
    printf("---FIN DE CARGA DE VENTAS---\n");
}

int Busqueda(struct PRODUCTO P[], int Buscado, int Cant){
    int i=0, pos=-1;

    while(i<Cant && pos==-1){
        if(P[i].Codigo==Buscado){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
void CargaInicial(struct PRODUCTO P[]){
    int i=0;
    struct PRODUCTO ProdTemp;
    char Descripcion[5];

    printf("---CARGA DE ARTICULOS---\n");

    for(i=0;i<3;i++){
        printf("-Numero de articulo: %d -\n",i);

        printf("Ingrese el codigo del articulo...\n",i);
        ProdTemp.Codigo = ValidarEntero(1,15,1);

        printf("Ingrese la descripcion del articulo (5 caracteres)...\n");
        ValidarCadena(&ProdTemp.Descripcion,2);
        strcpy(&ProdTemp.Descripcion,Descripcion);

        printf("Ingrese el stock disponible...\n");
        ProdTemp.Stock = ValidarEntero(1,10000000,1);

        P[i] = ProdTemp;
    }


    for(i=0;i<3;i++){
        printf("  CODIGO %d   DESCRIPCION %s   STOCK %d \n", P[i].Codigo, P[i].Descripcion, P[i].Stock);
    }
    printf("---FIN DE CARGA DE ARTICULOS---\n");
}

int ValidarEntero(int Li,int Ls,int Cf){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);
    }while(!((Entero>=Li && Entero<=Ls)||(Entero==Cf)));
    return Entero;
}

float ValidarReal(float Li,float Ls,float Cf){
    float Real;
    do{
        printf("");
        scanf("%f",&Real);
    }while(!((Real>=Li && Real<=Ls)||(Real==Cf)));
    return Real;
}

void ValidarCadena(char Cadena[], int Largo){
    char CadenaTemp[100];
    do{
        printf("");
        fflush(stdin);
        fgets(CadenaTemp,100,stdin);

        if(CadenaTemp[strlen(CadenaTemp)-1] == '\n'){
            CadenaTemp[strlen(CadenaTemp)-1] = '\0';
        }
    }while(!(strlen(CadenaTemp)==Largo));
    strcpy(CadenaTemp,Cadena);
}
