 #include <stdio.h>
 #include <string.h>

 struct VUELOS{
    char CodAerolinea;
    float Precio;
    int Dia;
    int NumeroVuelo;
    int CantPasajeros;
 };

 struct PASAJEROS{
    int Dni;
    int NumeroVuelo;
 };

 float ValidarReal(float,float,float);
 int   ValidarEntero(int,int,int);
 int   LeerVuelosActualizados(struct VUELOS[]);
 int   LeerVuelos(struct VUELOS[]);
 int   LeerPasajeros(struct PASAJEROS[]);
 int   Busqueda(struct PASAJEROS[]);
 void  ActualizarDatos(struct PASAJEROS[], struct VUELOS[], int, int);
 void  GrabarArchivo(struct VUELOS[],int);
 void  ValidarCadena(char[], int);

 int main(){
    struct VUELOS V[100];
    struct PASAJEROS P[100];
    int CantVuelos, CantPasajeros;

    CantVuelos = LeerVuelos(V);
    CantPasajeros = LeerPasajeros(P);
    ActualizarDatos(P,V,CantVuelos,CantPasajeros);
    GrabarArchivo(V,CantVuelos);
    LeerVuelosActualizados(V);

    return 0;
}

void GrabarArchivo(struct VUELOS V[], int CantVuelos){
    int i=0;
    FILE *archivo;

    archivo = fopen("Aero1.dat","wb");

    if(archivo==NULL){
        printf("Error al leer el archivo. \n");
    }else{
        printf("---GRABANDO ARCHIVO...---\n");
        for(i=0;i<CantVuelos;i++){
            fwrite(&V[i],sizeof(struct VUELOS), 1, archivo);
        }
        printf("---ARCHIVO GRABADO---\n");
    }

    fclose(archivo);
}

void ActualizarDatos(struct PASAJEROS P[], struct VUELOS V[], int CantVuelos, int CantPasajeros){
    int i=0, j=0;

    printf("---ACTUALIZANDO DATOS...---\n");
    for(i=0;i<CantVuelos;i++){
        for(j=0;j<CantPasajeros; j++){
            if(P[j].NumeroVuelo == V[i].NumeroVuelo){
                V[i].CantPasajeros++;
            }
        }
    }
    printf("---DATOS ACTUALIZADOS CORRECTAMENTE---\n");
}

int LeerPasajeros(struct PASAJEROS P[]){
    int i=0,    j=0;
    FILE *archivo;

    archivo = fopen("Pasajeros.dat", "rb");

    if(archivo==NULL){
        printf("Error al abrir el archivo Pasajeros.dat \n");
    }else{
        printf("---LEYENDO ARCHIVO---\n");
        fread(&P[i],sizeof(struct PASAJEROS),1,archivo);

        while(!feof(archivo)){
            fread(&P[i],sizeof(struct PASAJEROS),1,archivo);
            i++;
        }
    }

    fclose(archivo);

    printf("---ARCHIVO LEIDO---\n");
    printf("---CONTENIDO---\n");

    for(j=0;j<i;j++){
        printf("   %d       %d    ", P[j].Dni, P[j].NumeroVuelo);
    }
}

int LeerVuelosActualizados(struct VUELOS V[]){
    int i=0, j=0;
    struct VUELOS Vuelo;
    FILE *archivo;

    archivo=fopen("Aero1.dat","rb");

    if(archivo==NULL){
        printf("Error al abrir el archivo. \n");
    }else{
        printf("---LEYENDO ARCHIVO---\n");

        fread(&Vuelo, sizeof(struct VUELOS), 1, archivo);
        while(!feof(archivo)){
           V[i] = Vuelo;
           fread(&Vuelo, sizeof(struct VUELOS), 1, archivo);
           i++;
        }
    }

    fclose(archivo);

    printf("---ARCHIVO LEIDO---\n");
    printf("---CONTENIDO---\n");

    for(j=0;j<i;j++){
        printf("  %s    %d    %d    %f     %d   ", V[j].CodAerolinea, V[j].Dia, V[j].NumeroVuelo, V[j].Precio, V[j].CantPasajeros);
    }
    return i;
}

int LeerVuelos(struct VUELOS V[]) {
    int i = 0;
    FILE *archivo;

    archivo = fopen("Vuelos.dat", "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo. \n");
        return -1; // Devolver un valor de error.
    } else {
        printf("---LEYENDO ARCHIVO---\n");

        while (fread(&V[i], sizeof(struct VUELOS), 1, archivo) == 1) {
            i++;
        }
    }

    fclose(archivo);

    printf("---ARCHIVO LEIDO---\n");
    printf("---CONTENIDO---\n");

    for (int j = 0; j < i; j++) {
        printf("CodAerolinea: %s, Dia: %d, NumeroVuelo: %d, Precio: %.2f, CantPasajeros: %d\n",
               V[j].CodAerolinea, V[j].Dia, V[j].NumeroVuelo, V[j].Precio, V[j].CantPasajeros);
    }
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

float ValidarReal(float Li,float Ls,float Cf){
    float Real;
    do{
        printf("");
        scanf("%f",&Real);
    }while(!((Real>=Li && Real<=Ls)||(Real==Cf)));
    return Real;
}

void ValidarCadena(char Cadena[], int Largo){
    char CadenaTemp[100];
    do{
        printf("");
        fflush(stdin);
        fgets(CadenaTemp,100,stdin);

        if(CadenaTemp[strlen(CadenaTemp)-1] == '\n'){
            CadenaTemp[strlen(CadenaTemp)-1] = '\0';
        }
    }while(!(strlen(CadenaTemp)==Largo));
    strcpy(CadenaTemp,Cadena);
}
