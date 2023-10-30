#include <stdio.h>
#include <string.h>

struct PROPIETARIO{
    int  Dni;
    char NombreApellido[50];
    char Domicilio[50];
};
int LeerArchivo(struct PROPIETARIO P[]);

int main(){
    struct PROPIETARIO P[100];
    LeerArchivo(P);
    return 0;
}

int LeerArchivo(struct PROPIETARIO P[]){
    int i=0, j=0;
    struct PROPIETARIO PropietarioTemp;
    FILE *archivo;

    archivo = fopen("PROPIETARIOS.dat","rb");

    if(archivo==NULL){
        printf("Error al abrir el archivo. \n");
    }else{

        printf("---LEYENDO ARCHIVO...---\n");
        fread(&P[i],sizeof(struct PROPIETARIO),1,archivo);

        while(!(feof(archivo))){
            fread(&P[i],sizeof(struct PROPIETARIO),1,archivo);
            i++;
        }

    }
    fclose(archivo);
    printf("---ARCHIVO LEIDO. SE ENCONTRARON %d REGISTROS---\n",i);

    printf("  DNI          APELLIDO Y NOMBRE             DOMICILIO \n");
    for(j=0;j<i;j++){
        printf("   %d          %s         %s   \n",P[j].Dni,P[j].NombreApellido, P[j].Domicilio);
    }
}

