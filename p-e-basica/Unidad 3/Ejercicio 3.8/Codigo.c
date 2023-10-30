#include <stdio.h>
#include <string.h>

struct INSCRIPTO{
    char ApellidoNombre;
    int  DNI;
    int  Pagado;
};

struct INTERESADO{
    int DNI;
    int NumTelefono;
};

int  ValidarEntero(int,int,int);
int LeerArchivo(struct INSCRIPTO[]);
int ActualizarDatos(struct INSCRIPTO[], struct INTERESADO[], int);
void ValidarCadena(char[],int);
void GrabarActualizado(struct INSCRIPTO[],int);
void GrabarInteresados(struct INTERESADO[],int);

int main(){
    struct INSCRIPTO Insc[50];
    struct INTERESADO Inte[50];
    int CantInscriptos, CantInteresados;

    CantInscriptos=LeerArchivo(Insc);
    CantInteresados=ActualizarDatos(Insc,Inte,CantInscriptos);
    GrabarActualizado(Insc,CantInscriptos);
    GrabarInteresados(Inte, CantInteresados);

    return 0;
}

void GrabarInteresados(struct INTERESADO I[], int CantInteresados){
    int i=0;
    FILE *archivo;

    archivo = fopen("INTERESADOS.dat","wb");

    if(archivo == NULL){
        printf("Error al abrir el archivo. \n");
    }else{
        printf("---GRABANDO ARCHIVO INTERESADOS.DAT---\n");
        for(i=0;i<CantInteresados;i++){
            fwrite(&I[i],sizeof(struct INTERESADO),1,archivo);
        }
        printf("---ARCHIVO GRABADO---\n");
    }
}

void GrabarActualizado(struct INSCRIPTO I[], int CantInscriptos){
    int i=0;
    FILE *archivo;

    archivo = fopen("INSCRIPTOS.dat", "wb");

    if(archivo==NULL){
        printf("Error al abrir el archivo. \n");
    }else{
        printf("---GRABANDO ARCHIVO---\n");
        for(i=0;i<CantInscriptos;i++){
            fwrite(&I[i],sizeof(struct INSCRIPTO),1,archivo);
        }
    }

    fclose(archivo);
    printf("---ARCHIVO GRABADO---\n");
}

int Busqueda(struct INSCRIPTO I[], int Buscado, int CantElementos){
    int i=0, pos=-1;

    while(pos==-1 && i<CantElementos){
        if(I[i].DNI == Buscado){
            pos = i;
        }else{
            i++;
        }
    }

    return pos;
}

int ActualizarDatos(struct INSCRIPTO Inscripto[], struct INTERESADO Interesados[], int CantInscriptos){
    int i=0, Dni=0, pos, Opcion;

    printf("Ingrese el DNI del alumno...\n");
    Dni=ValidarEntero(100000,100000000,0);

    while(!(Dni==0)){
        pos = Busqueda(Inscripto,Dni,CantInscriptos);

        if(pos!=-1){
            // Si encuentra el alumno
            if(Inscripto[pos].Pagado!=1){
                printf("¿Desea registrar el pago? 1 SI / 0 NO \n");
                scanf("%d", &Opcion);
                if(Opcion){
                    Inscripto[pos].Pagado = 1;
                }
            }else{
                // Si no encuentra el alumno
                printf("Alumno no inscripto. ¿Desea inscribirlo? \n");
                scanf("%d",&Opcion);

                if(Opcion){
                    if(CantInscriptos<60){
                        printf("Alumno inscripto en el curso. \n");
                    }else{
                        printf("El curso no cuenta con mas cupos. ¿Desea que lo anotemos en lista de espera? 1 SI / 0 NO");
                        scanf("%d", &Opcion);

                        if(Opcion){
                            printf("Ingrese el numero telefonico del alumno. \n");
                            scanf("%d",&Interesados[i].NumTelefono);
                            Interesados[i].DNI = Dni;
                            i++;
                            printf("Alumno anotado en lista de espera. \n");
                        }
                    }
                }
            }
        }
    }
    return i;
}


int LeerArchivo(struct INSCRIPTO I[]) {
    int i = 0, j = 0;
    struct INSCRIPTO InscriptoTemp;
    FILE *archivo;

    archivo = fopen("INSCRIPTOS.dat", "rb");

    if (archivo == NULL) {
        printf("Hubo un error al abrir el archivo. \n");
    } else {
        printf("---LEYENDO ARCHIVO---\n");

        fread(&InscriptoTemp, sizeof(struct INSCRIPTO), 1, archivo);

        while (!feof(archivo)) {
            I[i] = InscriptoTemp;
            i++;
            fread(&InscriptoTemp, sizeof(struct INSCRIPTO), 1, archivo);
        }

    }

    fclose(archivo);
    printf("---ARCHIVO LEIDO---\n");
    printf("---SE LEYERON %d REGISTROS---\n", i); // Corrected this line

    printf("   DNI    APELLIDO Y NOMBRE    PAGADO   \n");
    for (j = 0; j < i; j++) {
        printf("%8d %s %8d\n", I[j].DNI, I[j].ApellidoNombre, I[j].Pagado);
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
