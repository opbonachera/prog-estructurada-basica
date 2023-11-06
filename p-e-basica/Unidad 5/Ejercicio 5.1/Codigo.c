// FLUJO DEL PROGRAMA

// Permitir el ingreso de un codigo
// Buscar el codigo del producto en el archivo
// Si no existe, mostrar un mensaje. Si existe, modificar el precio y/o la descripcion.

#include <stdio.h>
#include <stdlib.h>

struct PRODUCTO
{
    char  Desc[15];
    float Precio;
    int   CodProducto;
};


int   ValidarEntero(int,int,int);
float ValidarFlotante();
void  LeerArchivo();
struct PRODUCTO Busqueda(int);

int main(){
    FILE    *Archivo;
    int     CodBusq;
    int     RegActual;
    int     Ban=0;
    char    Opcion[2];
    char    DescTemp[15];
    float   Precio;
    struct  PRODUCTO P;
    LeerArchivo();

    Archivo = fopen("productos.dat","r+b");
    if(Archivo==NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    printf("Ingrese el codigo a buscar o 0 para terminar. \n");
    CodBusq = ValidarEntero(1,10,0);

    while(!(CodBusq==0)){
        P = Busqueda(CodBusq);

        if(P.CodProducto!=-1){
            printf("Se encontro el registro\n");

                fread(&P,sizeof(struct PRODUCTO),1,Archivo);
                Ban=0;
                while(!feof(Archivo) && Ban==0){


                        if(P.CodProducto==CodBusq){
                            printf("¿Desea modificar el precio del producto?  S/N...\n");
                            fflush(stdin);
                            gets(Opcion);

                            if(strcmpi("SI",Opcion)==0){
                                printf("Ingrese el nuevo precio del producto...\n");
                                Precio = ValidarFlotante();
                                Ban=1;

                                printf("%f", P.Precio);
                                P.Precio = Precio;

                            }

                            printf("¿Desea modificar la descripcion del producto?  S/N...\n");
                            fflush(stdin);
                            gets(Opcion);

                            if(strcmpi("SI",Opcion)==0){
                                printf("Ingrese la nueva descripcion del producto...\n");
                                fflush(stdin);
                                gets(DescTemp);
                                Ban=1;

                                strcpy(P.Desc, DescTemp);
                            }


                            fseek(Archivo,sizeof(struct PRODUCTO)*-1,SEEK_CUR);
                            fwrite(&P,sizeof(struct PRODUCTO),1,Archivo);
                            fflush(Archivo);
                        }else{
                            fread(&P,sizeof(struct PRODUCTO),1,Archivo);
                        }
            }
        }else{
            printf("Producto no encontrado.\n");
        }

        printf("Ingrese el codigo a buscar o 0 para terminar. \n");
        CodBusq = ValidarEntero(1,10,0);

        fseek(Archivo,sizeof(struct PRODUCTO),SEEK_SET);
    }
    LeerArchivo();
    fclose(Archivo);

}


struct PRODUCTO Busqueda(int CodBusq){
    FILE *Archivo;

    struct PRODUCTO Prod;
    int Encontrado=0;
    // Se abre el archivo en modo lectura
    Archivo = fopen("productos.dat","rb");

    if(Archivo==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }
    // Se lee el primer registro
    fread(&Prod,sizeof(struct PRODUCTO),1,Archivo);

    while(!feof(Archivo) && !Encontrado){
    // Se lee registro a registro mientras el producto no haya sido encontrado y mientras no sea fin de archivo
        if(Prod.CodProducto == CodBusq){
        // Si se lee un registro cuyo codigo es igual al codigo que se busca, se coloca el valor 1 en la bandera
            Encontrado=1;
        }else{
            fread(&Prod,sizeof(struct PRODUCTO),1,Archivo);
        // Si no fue encontrado, se siguen leyendo los registros
        }
    }
    // Si el registro no fue encontrado, se coloca un -1 en alguno de los campos
    if(!Encontrado){
        Prod.CodProducto=-1;
    }

    fclose(Archivo);
    return Prod;
}

void LeerArchivo(){
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

    for(i=0;i<4;i++){
         printf("CODIGO: %d          - DESCRIPCION %s                   - PRECIO %f         \n", P[i].CodProducto, P[i].Desc, P[i].Precio);
    }
    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}

int ValidarEntero(int Li,int Ls,int Cf){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);

        if(!((Entero>=Li && Entero<=Ls)||(Entero==Cf))){
            printf("Vuelva a ingresar. \n");
        }
    }while(!((Entero>=Li && Entero<=Ls)||(Entero==Cf)));
    return Entero;
}

float ValidarFlotante(){
    float Real;
    do{
        printf("");
        scanf("%f",&Real);

        if(!(Real>0)){
            printf("Ingrese nuevamente\n");
        }
    }while(!(Real>0));
    return Real;
}
