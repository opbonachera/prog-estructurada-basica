#include <stdio.h>

struct INSCRIPCIONES
{
    char Departamento[15];
    int  CodigoMateria;
    int  DNI;
};

int main()
{
    FILE *ArchivoInscriptos;

    char   DeptAnterior;
    int    CodAnterior;
    int    ContMateria, ContDepto, ContTotal, ContDeptoMat;
    struct INSCRIPCIONES I;

    ArchivoInscriptos = fopen("inscriptos.dat","rb");

    if(ArchivoInscriptos==NULL){
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

    fread(&I,sizeof(struct INSCRIPCIONES),1,ArchivoInscriptos);

    while(!feof(ArchivoInscriptos)){
        strcpy(DeptAnterior, I.CodigoMateria);

        ContDepto=0;
        ContMateria=0;

        // Bucle por departamento
        while(!feof(ArchivoInscriptos) && strcmpi(DeptAnterior, I.CodigoMateria)==0){
                CodAnterior = I.CodigoMateria;
                ContMateria=0;
                // Bucle por materia
                while(!feof(ArchivoInscriptos) && strcmpi(DeptAnterior, I.CodigoMateria)==0 && DeptAnterior == I.Departamento){
                    ContMateria++;
                    fread(&I,sizeof(struct INSCRIPCIONES),1,ArchivoInscriptos);
                }
                printf("Materia %d - Inscriptos: %d \n", CodAnterior, ContMateria);
                ContDepto+=ContMateria;
                ContDeptoMat++;
        }
        printf("Total de inscriptos en el departamento: %d\n", ContDepto);
        printf("Cant de materias del depto: %d, \n", ContDeptoMat);
    }
    fclose(ArchivoInscriptos);
    return 0;
}
