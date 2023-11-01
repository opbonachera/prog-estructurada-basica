
#include <stdio.h>

struct FECHA
{
    int Dia;
    int Mes;
    int Anio;
};
struct VISITANTE
{
    char   NomAp[35];
    int    DNI;
    char   Localidad[40];
    char   Email[20];
    struct FECHA Fecha;
};

int  IngresarVisitantes(struct VISITANTE[],int);
int  ValidarEntero(int,int,int);
void ValidarCadena(char[],int);
void OrdenarVisitantes(struct VISITANTE[],int);
void GrabarArchivo(struct VISITANTE[],int);

int main()
{
    FILE *ArchVisitantes;
    FILE *ArchVisitantesLocalidad;
    int    VPorLocalidad=0, CantV;
    char   LocAnterior[40];
    char   NomVisitantesLocalidad;
    struct VISITANTE V;
    struct VISITANTE VecVis[500];

    CantV = IngresarVisitantes(VecVis,500);
    OrdenarVisitantes(VecVis,CantV);
    GrabarArchivo(VecVis,CantV);

    ArchVisitantes = fopen("visitantes.dat","rb");
    fread(&V, sizeof(struct VISITANTE),1,ArchVisitantes);

    while(!feof(ArchVisitantes)){
    // Bucle inicio de archivo
        strcpy(LocAnterior,V.Localidad);
        strcpy(NomVisitantesLocalidad,V.Localidad);
        strcat(NomVisitantesLocalidad,".dat");

        VPorLocalidad=0;

        ArchVisitantesLocalidad =fopen(NomVisitantesLocalidad,"wb");
        if(ArchVisitantesLocalidad==NULL){
            printf("Error al abrir el archivo. \n");
            exit(1);
        }
        // Bucle por localidad
        do{
            VPorLocalidad++;
            fwrite(&V,sizeof(struct VISITANTE),1,ArchVisitantesLocalidad);
        }while(!feof(ArchVisitantes) && strcmpi(V.Localidad, LocAnterior)==0);

        fclose(ArchVisitantesLocalidad);
        printf("Asistieron %d visitantes a la localidad %d\n", VPorLocalidad,LocAnterior);
        // Fin de bucle por localidad
    }
    //Fin de archivo
}

void OrdenarVisitantes(struct VISITANTE V[], int Cant){
    char CadenaTemp[20];
    int i, j, aux;

    printf("---ORDENANDO VISITANTES---\n");
    for(i=0;i<Cant;i++){
        for(j=0;j<Cant-i-1;j++){
            if(strcmpi(v[j].Localidad,v[j+1].Localidad)>0){
                strcpy(aux,v[j]);
                strcpy(v[j],v[j+1]);
                strcpy(v[j+1], aux);
            }
        }
    }
    printf("---FIN DEL ORDENAMIENTO---\n");
}

void GrabarArchivo(struct VISITANTE V[], int Cant){
    FILE*Archivo;
    int i=0;

    Archivo = fopen("visitantes.dat","wb");
    for(i=0;i<Cant;i++){
        fwrite(&V[i], sizeof(struct VISITANTE), 1, Archivo);
    }
    fclose(Archivo);
}

int IngresarVisitantes(struct VISITANTE V[], int Max){
    int    i=0;
    struct VISITANTE V;

    printf("Ingrese el DNI del visitantre o FIN para terminar. \n");
    fgets(V.NomAp,35,stdin);

    while(strcmpi(V.NomAp, "FIN")!=0 && i < Max){
        printf("Ingrese el dni del visitante...\n");
        V.DNI = ValidarEntero(1000000,1000000000,1000000);

        printf("Ingrese la localidad del visitante...\n");
        fgets(V.Localidad,40,stdin);

        printf("Ingrese el email del visitante...\n");
        fgets(V.Email,20,stdin);

        printf("Ingrese la fecha del dia de hoy... \n");
        printf("Dia \n");
        V.Fecha.Dia = ValidarEntero(1,31,1);
        printf("Mes \n");
        V.Fecha.Mes = ValidarEntero(1,12,1);
        printf("Anio \n");
        V.Fecha.Anio = ValidarEntero(2000,2023,2000);

        i++;

        printf("Ingrese el DNI del visitantre o FIN para terminar. \n");
        fgets(V.NomAp,35,stdin);
    }

    printf("---FIN DE CARGA DE VISITANTES---\n");
    return i;
}

int ValidarEntero(int Li,int Ls,int Cf){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);
    }while(!((Entero>=Li && Entero<=Ls)||(Entero==Cf)));
    return Entero;
}
