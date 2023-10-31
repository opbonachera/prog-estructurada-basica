#include <stdio.h>

struct EMPLEADOINFOMES
{
    char Sector[10];
    int  DNI;
    int  HorasTrabajadas;
};

struct EMPLEADO
{
    char  NombreApellido[30];
    float ValorHora;
    int   DNI;
};

struct EMPLEADOSECTOR
{
    int   DNI;
    char  NombreApellido[30];
    int   HorasTrabajadas;
    float Sueldo;
};

void CargaEmpleados(struct EMPLEADO[]);
int  Busqueda(struct EMPLEADO[], int DNI);

int main(){
    FILE *ArchivoHoras;
    FILE *ArchivoSector;

    char   NombreSector[10];
    char   SectorAnterior[10];
    int    Posicion;
    struct EMPLEADOINFOMES EIM;
    struct EMPLEADO VEmpleados[100];
    struct EMPLEADOSECTOR ES;

    CargaEmpleados(VEmpleados);

    ArchivoHoras = fopen("horasTrabajadas.dat","rb");
    if(ArchivoHoras==NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(&EIM, sizeof(struct EMPLEADOINFOMES),1,ArchivoHoras);
    while(!feof(ArchivoHoras)){
        strcpy(SectorAnterior,EIM.Sector);

        strcpy(NombreSector, EIM.Sector);
        strcat(NombreSector,".dat");
        // Abrimos el archivo para escribir por sector
        ArchivoSector = fopen(NombreSector,"wb");
            if(ArchivoSector==NULL){
                exit(1);
                printf("Error al abrir el archivo. \n");
            }

        while(!feof(ArchivoHoras) && strcmpi(SectorAnterior,EIM.Sector) == 0){
                Posicion = Busqueda(VEmpleados, EIM.DNI);

                ES.DNI = EIM.DNI;
                ES.HorasTrabajadas = EIM.HorasTrabajadas;
                ES.Sueldo = EIM.HorasTrabajadas * VEmpleados[Posicion].ValorHora;
                strcpy(ES.NombreApellido, VEmpleados[Posicion].NombreApellido);
                fwrite(&ES, sizeof(struct EMPLEADOSECTOR),1,ArchivoSector);
                // Por cada empleado escribimos un registro en el archivo correspondiente al sector

                fread(&EIM, sizeof(struct EMPLEADOINFOMES),1,ArchivoHoras);
                // Leemos el archivo principal en el bucle mas interno
        }

        fclose(ArchivoSector);
    }
    fclose(ArchivoHoras);
    return 0;
}

void CargaEmpleados(struct EMPLEADO E[]){
    // Abre el archivo empleados.dat y guarda los datos en memoria.
    FILE *Archivo;
    int i=0;

    Archivo = fopen("empleados.dat","rb");
    if(Archivo==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    fread(&E[i], sizeof(struct EMPLEADO),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&E[i], sizeof(struct EMPLEADO),1,Archivo);
    }
    fclose(Archivo);
}

int  Busqueda(struct EMPLEADO Empleado[], int DNI){
    // Busca el DNI que recibe por parametro en el vector de empleados y devuelve su posicion.
    int Pos, i=0;

    while(Pos==-1){
        if(Empleado[i].DNI==DNI){
            Pos = i;
        }else{
            i++;
        }
    }

    return Pos;
}
