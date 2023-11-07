#include <stdio.h>
#include <stdlib.h>

struct empleado{
    int legajo;
    char nombre[31];
    int categoria;
};

void Ordenar();
void Listar();

int main()
{
    printf("---ARCHIVO SIN ORDENAR---\n");
    Listar();

    printf("---ARCHIVO ORDENADO---\n");
    Ordenar();
    Listar();

    return 0;
}

void Ordenar()
{
    // Se realizan dos lecturas guardando en dos variables los registros leidos
    struct empleado empactual, empanterior;
    // Se detecta cuando el archivo esta ordenado y se ordenan solo las partes que estan desordenadas
    int primerRecorrido=1, ultimoIntercambio, cont, ordenado,Intercambio;

    FILE *Arch;
    Arch=fopen("empleados.dat", "r+b");

    if (Arch==NULL)
        { printf(" ERROR apertura de archivo EMPLEADO");
          exit(1);
        }

    do{
        ordenado=1; // Bandera que indica si esta ordenado o no. Si al volver al entrar al while la bandera es igual a 0 significa que todavia esta desordenado
        fread(&empanterior,sizeof(struct empleado),1, Arch );
        cont=1;
        // Se inicia el contador
        while((primerRecorrido==1 && !feof(Arch))||(primerRecorrido!=1	&& cont<=ultimoIntercambio))
        {
            fread(&empactual, sizeof(struct empleado),1,Arch);
            cont++;
            if (!feof(Arch))
            {
                if (empanterior.legajo>	empactual.legajo)
                {
                    fseek(Arch,sizeof(struct empleado)*(-2),SEEK_CUR);
                    fflush(Arch);
                    fwrite(&empactual,sizeof(struct empleado),1,Arch );
                    fwrite(&empanterior,sizeof(struct empleado),1,Arch );
                    fflush(Arch);
                    ordenado=0;
                    Intercambio=cont; // Contador de intercambios
                }
                else
                empanterior=empactual;

            }
        }

        ultimoIntercambio=Intercambio;
        rewind(Arch);
        primerRecorrido=0;
        }while(!ordenado);
        fclose(Arch);
}

void Listar()
{
    FILE *Arch;struct empleado empactual;
    Arch=fopen("empleados.dat", "rb");
    if (Arch==NULL)
        { printf(" ERROR apertura de archivo EMPLEADO");
        exit(1);
        }
       fread(&empactual, sizeof(struct empleado),1,Arch);
       while (!feof(Arch))
       {
            printf ("LEG: %d -- NOMBRE %s -- CAT %d \n",empactual.legajo,empactual.nombre, empactual.categoria);
            fread(&empactual, sizeof(struct empleado),1,Arch);
       }
         fclose(Arch);
}
