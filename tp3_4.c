#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int cantidad;
    char **V;
    printf("Ingrese la cantidad de nombres a ingresar: ");
    scanf("%d",&cantidad);
    fflush(stdin);
    V = (char **) malloc(cantidad * sizeof(char *));
    for(int i=0;i<cantidad;i++){
        fflush(stdin);
        V[i]=(char *) malloc(100);
        printf("Ingrese el nombre %d: ",i+1);
        gets(V[i]); 
    }
    printf("Nombres: ");
    for(int i=0;i<cantidad;i++){
        puts(V[i]);
    }
     for(int i=0;i<cantidad;i++){
        free(V[i]);
    }
    free(V);

    return 0;
}