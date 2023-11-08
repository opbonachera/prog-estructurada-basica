#include <stdio.h>
#include <stdlib.h>

struct CONTACTO
{
    char Nombre[20];
    int  Numero;
};

int     Menu();
struct  CONTACTO Busqueda();
void    Listar();
void    AgregarContacto();
void    ModificarContacto();
void    EliminarContacto();

int ValidarEntero(int,int,int);

int main(){
    int Opcion;

    Opcion = Menu();

    while(!(Opcion==0)){

        switch(Opcion){
        case 1: // Mostrar contactos
            Listar();
            break;
        case 2: // Agregar contacto
            AgregarContacto();
            break;
        case 3: // Buscar contacto
            Busqueda();
            break;
        case 4: // Modificar contacto
            ModificarContacto();
            break;
        case 5: // Eliminar contacto
            EliminarContacto();
            break;
        }
    Opcion = Menu();
}
}

void Listar(){
    FILE *Archivo;
    struct CONTACTO C;

    Archivo = fopen("agenda.dat","rb");

    if(Archivo==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    printf("    NOMBRE        NUMERO    \n");
    fread(&C, sizeof(struct CONTACTO), 1, Archivo);
    while(!feof(Archivo)){
        printf(" -> %s       \t%d   \n", C.Nombre, C.Numero);
        fread(&C, sizeof(struct CONTACTO), 1, Archivo);
    }

    fclose(Archivo);
}

void AgregarContacto(){
    printf("---AGREGAR CONTACTO---\n");

    FILE *Archivo;
    struct CONTACTO C;
    char Nombre[15];
    Archivo = fopen("agenda.dat","a+b");
    if(Archivo==NULL){
        printf("Error al abrir la agenda. Saliendo...\n");
        exit(1);
    }

    printf("Ingrese el nombre del nuevo contacto...\n");
    fflush(stdin);
    fgets(Nombre,15,stdin);

    if(Nombre[strlen(Nombre)-1] == '\n'){
            Nombre[strlen(Nombre)-1] = '\0';
    }

    strcpy(C.Nombre,Nombre);

    printf("Ingrese el numero del contacto...\n");
    scanf("%d",&C.Numero);

    fwrite(&C, sizeof(struct CONTACTO),1,Archivo);

    rewind(Archivo);
    fclose(Archivo);
}


struct CONTACTO Busqueda(){
    struct CONTACTO C, CEncontrado;
    int  Encontrado=0;
    char Nombre[15];
    FILE *Archivo;

    printf("---BUSQUEDA---\n");

    printf("Ingrese el nombre del contacto a buscar...\n");
    fflush(stdin);
    fgets(Nombre,15,stdin);

    if(Nombre[strlen(Nombre)-1] == '\n'){
            Nombre[strlen(Nombre)-1] = '\0';
    }

    Archivo = fopen("agenda.dat","rb");
    if(Archivo==NULL){
        printf("Error al abrir la agenda.\n");
        exit(1);
    }

    fread(&C, sizeof(struct CONTACTO),1,Archivo);
    while(!feof(Archivo) && Encontrado==0){

        if(strcmpi(Nombre, C.Nombre)==0){
            Encontrado=1;
            CEncontrado = C;
        }else{
            fread(&C, sizeof(struct CONTACTO),1,Archivo);
        }
    }

    if(Encontrado==0){
        printf("No se encontro el contacto. \n");
        CEncontrado.Numero=-1;
    }else{
        printf("NOMBRE: %s    ---- NUMERO: %d   \n", CEncontrado.Nombre, CEncontrado.Numero);
    }

    fclose(Archivo);
    return CEncontrado;
}

void ModificarContacto(){
    printf("---MODIFICACION---\n");
    struct CONTACTO C, CEnc;
    char   Opcion;
    char   Nombre[15];
    int    Ban=0;
    FILE   *Archivo;


    Archivo = fopen("agenda.dat","r+b");
    if(Archivo==NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    CEnc = Busqueda();

    if(CEnc.Numero!=-1){
        printf("Entro al if");
        fread(&C, sizeof(struct CONTACTO),1,Archivo);
        Ban=0;
        while(!feof(Archivo) && Ban==0){
                printf("Entro al while");
                if(strcmpi(C.Nombre, CEnc.Nombre) == 0){
                        Ban=1;
                        printf("¿Desea modificar el nombre del contacto? S/N\n");
                        fflush(stdin);
                        scanf("%c",&Opcion);

                        if(toupper(Opcion)=='S'){
                            printf("Ingrese el nuevo nombre del contacto...\n");
                            fflush(stdin);
                            fgets(Nombre,15,stdin);

                            if(Nombre[strlen(Nombre)-1] == '\n'){
                                Nombre[strlen(Nombre)-1] = '\0';
                            }

                            strcpy(CEnc.Nombre,Nombre);
                        }else{
                            printf("No modifica\n");
                        }

                        printf("¿Desea modificar el numero del contacto? S/N\n");
                        fflush(stdin);
                        scanf("%c",&Opcion);

                        if(toupper(Opcion)=='S'){
                            printf("Ingrese el nuevo numero del contacto...\n");
                            scanf("%d",&CEnc.Numero);
                        }else{
                            printf("No modifica...\n");
                        }

                        fseek(Archivo, sizeof(struct CONTACTO)*-1,SEEK_CUR);
                        fwrite(&CEnc, sizeof(struct CONTACTO),1,Archivo);
                        fflush(Archivo);
                }else{
                    fread(&C, sizeof(struct CONTACTO),1,Archivo);
                }
        }

    }
}

void EliminarContacto(){
    printf("---ELIMINAR CONTACTO---\n");

    FILE *Archivo, *Temp;
    struct CONTACTO C;
    char Nombre[15];

    Archivo = fopen("agenda.dat","r+b");
    Temp = fopen("agendatemp.dat","w+b");

    if(Archivo==NULL || Temp==NULL){
        printf("Error al abrir el archivo. Saliendo...\n");
        exit(1);
    }

    printf("Ingrese el nombre del contacto que desea eliminar...\n");
    fflush(stdin);
    fgets(Nombre,15,stdin);

    if(Nombre[strlen(Nombre)-1]=='\n'){
        Nombre[strlen(Nombre)-1] = '\0';
    }

    fread(&C, sizeof(struct CONTACTO),1,Archivo);
    while(!feof(Archivo)){
        printf("Entro al while\n");
        if(strcmpi(Nombre,C.Nombre)!=0){
            printf("Entro al if\n");
            fwrite(&C, sizeof(struct CONTACTO),1,Temp);
        }
        fread(&C, sizeof(struct CONTACTO),1,Archivo);
    }

    printf("Contacto eliminado\n");

    fclose(Archivo);
    fclose(Temp);

    remove("agenda.dat");
    rename("agendatemp.dat","agenda.dat");
}

int Menu()
{
    int Opcion;
    printf("---AGENDA---\n");
    printf("ELIJA UNA OPCION \n0.Salir \n1.Mostrar contactos\n2.Agregar contacto\n3.Buscar contactos\n4.Modificar contacto\n5.Borrar contacto\n");

    Opcion = ValidarEntero(1,5,0);

    return Opcion;
}

int ValidarEntero(int Li,int Ls,int Cf){
    int Entero;
    do{
        printf("");
        scanf("%d",&Entero);

        if(!((Entero>=Li && Entero<=Ls)||(Entero==Cf))){
            printf("Vuelva a ingresar...\n");
        }

    }while(!((Entero>=Li && Entero<=Ls)||(Entero==Cf)));
    return Entero;
}
