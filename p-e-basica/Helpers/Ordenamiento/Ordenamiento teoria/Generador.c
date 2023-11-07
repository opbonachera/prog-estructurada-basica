#include <stdio.h>
#include <stdlib.h>

struct EMPLEADO{
    int legajo;
    char nombre[31];
    int categoria;
}
;

int main()
{
    int i, Cant;
    FILE *Archivo;

    struct EMPLEADO E[] = {
        {5,"Ornella",1},
        {8,"Paula",2},
        {1,"Florencia",3},
        {2,"Camila",4},
        {7,"Oriana",5},
        {9,"Sol",6},
        {10,"Lucas",7},
        {12,"Tiziana",7},
        {11,"Sofia",7},
    };

    Cant = sizeof(E) / sizeof(struct EMPLEADO);
    Archivo = fopen("empleados.dat","wb");

    if(Archivo==NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    for(i=0;i<Cant;i++){
        fwrite(&E[i],sizeof(struct EMPLEADO),1,Archivo);
    }

    fclose(Archivo);
    LeerArchivo(Cant);
    return 0;
}

void LeerArchivo(int Cant){
    FILE *Archivo;
    int i=0;
    struct EMPLEADO E[100];

    Archivo = fopen("empleados.dat","rb");

    printf("---CONTENIDO DEL ARCHIVO---\n");

    fread(&E[i],sizeof(struct EMPLEADO),1,Archivo);
    while(!feof(Archivo)){
        i++;
        fread(&E[i],sizeof(struct EMPLEADO),1,Archivo);
    }

    for(i=0;i<Cant;i++){
         printf("LEGAJO: %d --- NOMBRE: %s \n", E[i].legajo, E[i].nombre );
    }
    fclose(Archivo);
    printf("---FIN DE LECTURA DEL ARCHIVO--\n");
}
