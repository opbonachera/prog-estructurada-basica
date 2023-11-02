#include <stdio.h>

struct empleado{

int legajo;
char apellido[16];
char nombre[31];
int d,m,a;
int categoria;}
;

void ordenar();
void listar();

int main()
{
listar();
printf("Ordenado\n");
ordenar();
listar();
return 0;
}

void ordenar()
{
struct empleado empactual, empanterior;
int primerRecorrido=1, ultimoIntercambio, cont, ordenado,Intercambio;

FILE *Arch;
Arch=fopen("EMPLEADOS.DAT", "r+b");

if (Arch==NULL)
    { printf(" ERROR apertura de archivo EMPLEADO");
      exit(1);
    }
do{
    ordenado=1;
    fread(&empanterior,sizeof(struct empleado),1, Arch );
    cont=1;
    while((primerRecorrido==1 && !feof(Arch))||(primerRecorrido!=1	&& cont<=ultimoIntercambio))
    {
        fread(&empactual, sizeof(struct empleado),1,Arch);
        cont++;
        if (!feof(Arch))
        {
            if (empanterior.legajo>	empactual.legajo)
            { fseek(Arch,sizeof(struct empleado)*(-2),SEEK_CUR);
            fflush(Arch);
            fwrite(&empactual,sizeof(struct empleado),1,Arch );
            fwrite(&empanterior,sizeof(struct empleado),1,Arch );
            fflush(Arch);
            ordenado=0;
            Intercambio=cont;
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

void listar()

{FILE *Arch;struct empleado empactual;
Arch=fopen("EMPLEADOS.DAT", "rb");
if (Arch==NULL)
    { printf(" ERROR apertura de archivo EMPLEADO");
    exit(1);
    }
   fread(&empactual, sizeof(struct empleado),1,Arch);
   while (!feof(Arch))
   {printf ("%d %s %s %d-%d-%d %d \n ",empactual.legajo,empactual.apellido, empactual.nombre, empactual.d,empactual.m,empactual.a,empactual.categoria);
	fread(&empactual, sizeof(struct empleado),1,Arch);

	 }
	 fclose(Arch);
}
