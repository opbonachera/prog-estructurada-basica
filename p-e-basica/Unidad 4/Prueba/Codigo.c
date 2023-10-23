#include <stdio.h>

struct PERSONA{
    char NomAp;
    int  NumLegajo;
    float Sueldo;
    int NumSector;
    int NumAño;
}

int main(){
    // Ejercicio con un solo nivel de corte de control. 
    struct PERSONA P;
    int AntSector, ContadorTotal, ContadorSector;
    FILE *archEmpleados;

    ArchEmpleados = fopen("empleado.dat","rb");

    if(ArchEmpleados == NULL){
        printf("Hubo un error.\n");
    }else{
        contTotal = 0;

        fread(&P, sizeof(struct PERSONA),1, ArchEmpleados);
        while(!feof(ArchEmpleados)){
            // Lee los registros hasta el final del archivo
            AntSector = P.NumSector;
            ContadorSector = 0;
            // Se lee el dato de control, en este caso el numero de sector
            do{
                ContadorSector++;
                fread(&P, sizeof(struct PERSONA),1, ArchEmpleados);
            }while(P.NumSector == AntSector && !feof(ArchEmpleados));
            // En el do while se leen los datos hasta que cambia el dato de corte y cuando cambia, se imprime la informacion
            contTotal += ContadorSector;
            printf("La cantidad de empleados del sector %d es de %d", AntSector, ContadorSector);

        }
        fclose(ArchEmpleados);
        printf("La cantidad total de empleados de la empresa es de %d");

        return 0;
    }

}