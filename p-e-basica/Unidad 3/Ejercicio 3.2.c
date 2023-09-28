#include <stdio.h>
#include <string.h>

int LeerArchivo(struct ALUMNO[]);
void GrabarPromocionados(struct ALUMNO[]);
void GrabarCursados(struct ALUMNO[]);
void GrabarReprobados(struct ALUMNO[]);

int main(){
    struct ALUMNO A[];

    LeerArchivo(A);
    GrabarPromocionados(A);
    GrabarCursados(A);
    GrabarReprobados(A);

    return 0;
}

int LeerArchivo(struct ALUMNO A[]){
    int i=0;
    FILE *arch;

    fopen("alumnos.dat","rb");
    if(arch==NULL){
        printf("Error al leer el archivo. \n");
    }else{
        for(i=0;i<2;i++){
            fread(&A[i], sizeof(struct ALUMNO),1,arch);
        }
    }
    return i;
}

void GrabarPromocionados(struct ALUMNO A[]){
    int i=0;
    FILE *archivo;

    printf("---GRABANDO ARCHIVO promocionados.dat---\n");
    archivo = fopen("promocionados.dat","wb");

    if(!(archivo==NULL){
        for(i=0;i<10;i++){
            if(A[i].Nota1 >= 7  && A[i].Nota2 >=7){
                fwrite(&A[i], sizeof(struct ALUMNO),1,archivo);
            }
        }

        printf("---ARCHIVO promocionados.dat GRABADO---\n");
    }else{
        printf("Hubo un error. \n");
    }


    fclose(archivo);
}

void GrabarCursados(struct ALUMNO A[]){
    int i=0;
    FILE *archivo;

    printf("---GRABANDO ARCHIVO cursados.dat---\n");
    archivo = fopen("cursados.dat","wb");

    if(!(archivo==NULL){
        for(i=0;i<10;i++){
            if( (A.Nota1 >= 4 && A.Nota1 <= 7) && (A.Nota2 >= 4 && A.Nota2 <= 7) ){
                fwrite(&A[i], sizeof(struct ALUMNO),1,archivo);
            }
        }

        printf("---ARCHIVO cursados.dat GRABADO---\n");
    }else{
        printf("Hubo un error. \n");
    }


    fclose(archivo);
}

void GrabarReprobados(struct ALUMNO A[]){
    int i=0;
    FILE *archivo;

    printf("---GRABANDO ARCHIVO reprobados.dat---\n");
    archivo = fopen("reprobados.dat","wb");

    if(!(archivo==NULL){
        for(i=0;i<10;i++){
            if( A.Nota1 < 4 || A.Nota2 <4 ){
                fwrite(&A[i], sizeof(struct ALUMNO),1,archivo));
            }
        }

        printf("---ARCHIVO reprobados.dat GRABADO---\n");
    }else{
        printf("Hubo un error. \n");
    }


    fclose(archivo);
}
