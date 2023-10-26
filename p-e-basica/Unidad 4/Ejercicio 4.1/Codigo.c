#include <stdio.h>
#include <string.h>

typedef struct{
    char Zona[20];
    int CodigoLocalidad;
    int Dia;
    int Mes;
    float MMCaidos;
}MEDICION;

int main(){
    FILE* Archivo;
    int i=0, LocalidadAnterior=0;
    MEDICION M;
    char ZonaAnterior[20];
    float PrecPorZona=0,DiasPorLocalidad=0;

    Archivo = fopen("mediciones.dat","rb");

    if(Archivo==NULL){
        printf("Hubo un error al abrir el archivo. \n");
        exit(1);
    }

    fread(&M,sizeof(MEDICION),1,Archivo);

    while(!feof(Archivo)){

        PrecPorZona=0;
        strcpy(ZonaAnterior,M.Zona);

        while( !feof(Archivo) && strcmpi(ZonaAnterior,M.Zona)==0 ){
            LocalidadAnterior = M.CodigoLocalidad;
            DiasPorLocalidad=0;
            while(!feof(archivo) && strcmpi(ZonaAnterior,M.Zona)==0 && LocalidadAnterior==M.CodigoLocalidad){
                    PrecPorZona+=M.MMCaidos;
                    DiasPorLocalidad++:
                    fread(&M,sizeof(MEDICION),1,Archivo);
            }
            printf("Cantidad de dias en los que llovio en la localidad %d de la zona %s \n", DiasPorLocalidad, ZonaAnterior);
        }
        printf("El total de precipitaciones de la zona %s fue de %.2f", ZonaAnterior, PrecPorZona);

    }

    fclose(Archivo);
    return 0;
}
