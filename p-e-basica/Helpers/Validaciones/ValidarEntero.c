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

void LeerArchivo(){
    FILE *Archivo;

    Archivo = fopen("archivo.dat","rb");
    if(Archivo==NULL){
        printf("Error al abrir el archivo \n");
        exit(1);
    }

    fread(&Temp, sizeof(struct TEMP), 1, Archivo);
    while(!feof(Archivo)){
        fread(&Temp, sizeof(struct TEMP), 1, Archivo);
    }
}


