#include <stdio.h>
#include <string.h>

void ValidarPatente();
int ValidarDias();
float ValidarPrecio();
int IngresarAlquileres(char[][30]);
void MostrarPorcentaje(char[][30], int);

int main(){
    return 0;
}

int IngresarAlquileres(char Patentes[][30]){
    int Cant, i=0;
    float PrecioDolar, Recaudacion;
    char Patente[1][30];

    do{
        printf("Ingrese la patente del auto...\n");
        strcpy(Patentes[0], Patente);
    }while(!(strlen(Patente)==7));

    while(strcmpi(Patentes[i],"fin")==0){

    }
}

int ValidarDias(){
    int Dias;
    do{
        printf("Ingrese la cantidad de dias de alquiler...\n");
        scanf("%d",%Dias);
    }while(!(Dia>0));
    return Dias;
}

float ValidarPrecio(){
    float Precio;
    do{
        printf("Ingrese el precio del alquiler...\n");
        scanf("%f",&Precio);
    }while(!(Precio>0));
    return Precio;
}
