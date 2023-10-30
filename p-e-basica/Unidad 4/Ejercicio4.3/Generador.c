#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct llamada {char sector[16];
                int duracion;
                int tipollamada;
                };

struct gasto {char sector[16];
             float gastos;};

struct costo{float c1;float c2; float c3;};

struct nombresector{int duracion;
                    int tipo;
                    float costo;};

int main()

{   int i;
    struct llamada reg;
    struct costo regcosto;
    struct gasto g;
    FILE * Arch;
    Arch=fopen("llamadas.dat","wb");
    if (Arch==NULL)
    {
    printf("Error");
        exit(0);
    }

    for(i=0;i<7;i++)
    {
        printf("Sector:");
        fflush(stdin);
        gets(reg.sector);
        printf("Duracion");
        scanf("%d",&reg.duracion);
        printf("tipo:");
        scanf("%d",&reg.tipollamada);
        fwrite(&reg,sizeof(struct llamada),1,Arch);
    }

    fclose(Arch);

    Arch=fopen("costo.dat","wb");
    if (Arch==NULL)
    {
    printf("Error");
        exit(0);
    }
    regcosto.c1=20;
    regcosto.c2=10;
    regcosto.c3=15;

    fwrite(&regcosto,sizeof(struct costo),1,Arch);
       fclose(Arch);
}
