#include <stdio.h>
#include <string.h>

int main(){
    char CFin[3]="FIN", Cadena[20];

    ValidarCadena(Cadena, CFin, 3);

    printf("La cadena ingresada es %s \n", Cadena);

    return 0;
}

void ValidarCadena(char Cadena[], char CFin[], int Largo){
    char CadenaTemp[20];
    do{
        printf("");
        fgets(CadenaTemp, 20, stdin);

        if(CadenaTemp[strlen(CadenaTemp)-1] == '\n'){
            CadenaTemp[strlen(CadenaTemp)-1] = '\0';
        }

    }while( !((strlen(CadenaTemp)==Largo) || strcmpi(CadenaTemp, CFin)==0) );
    strcpy(Cadena, CadenaTemp);
}
