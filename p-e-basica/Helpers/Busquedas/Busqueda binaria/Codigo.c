#include <stdio.h>
#include <stdlib.h>

struct PRODUCTO
{
    int Cod;
    int Cant;
};

struct PRODUCTO Busqueda(int);

int main()
{
    int    CodBusq;
    struct PRODUCTO Prod;

    printf("---BUSQUEDA BINARIA---\n");
    printf("Ingrese un codigo entero del 1 al 12 para obtener un producto o 0 para finalizar la busqueda\n");
    scanf("%d",&CodBusq);

    while(CodBusq!=0){
        Prod = Busqueda(CodBusq);
        if(Prod.Cod==-1){
            printf("Producto no encontrado. \n");
        }else{
            printf("CODIGO %d ---- CANTIDAD %d \n", Prod.Cod, Prod.Cant);
        }


        printf("---BUSQUEDA BINARIA---\nIngrese un codigo entero del 1 al 12 para obtener un producto o 0 para finalizar la busqueda\n");
        scanf("%d",&CodBusq);
    }
}

struct PRODUCTO Busqueda(int CodBusq){
    // Se reduce el conjunto de busqueda a la mitad por cada lectura
    FILE *Archivo;
    struct PRODUCTO Prod;
    int Inicio, Fin, Mitad;
    int Encontrado;

    Archivo = fopen("productos.dat","r+b");
    if(Archivo==NULL){
        printf("Hubo un error al abrir el archivo.\n");
        exit(1);
    }

    Inicio = 0;
    fseek(Archivo,0,SEEK_END);
    Fin = ftell(Archivo) / sizeof(struct PRODUCTO);
    Mitad = (Fin+Inicio) / 2;

    // Se posiciona en el registro del medio del archivo y se lee
    fseek(Archivo, Mitad*sizeof(struct PRODUCTO), SEEK_SET);
    fread(&Prod, sizeof(struct PRODUCTO),1,Archivo);

    while(Inicio<=Fin && Prod.Cod!=CodBusq){
        // Si el codigo buscado es mayor que el codigo de la mitad de los registros, partimos el archivo a partir de la "segunda" mitad
        if(CodBusq > Prod.Cod){
            Inicio = Mitad+1;
        }else{
        // Si el codigo buscado no es mayor al codigo del medio, entonces partimos el archivo y nos quedamos con la primera mitad
            Fin = Mitad-1;
        }
        // Volvemos a partir la mitad en funcion de los puntos de inicio y fin calculados anteriormente
        Mitad = (Fin+Inicio) / 2;
        if(Inicio <= Fin && Prod.Cod!=CodBusq){
            // Se desplaza desde el comienzo del archivo hasta la mitad calculada
            fseek(Archivo, Mitad*sizeof(struct PRODUCTO),SEEK_SET);
            fread(&Prod,sizeof(struct PRODUCTO),1,Archivo);
        }
    }

    if(Prod.Cod!=CodBusq){
        Prod.Cod=-1;
    }
    fclose(Archivo);
    return Prod;
}
