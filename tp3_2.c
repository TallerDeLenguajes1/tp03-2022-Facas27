#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
     char *p1, *p2, *p3 , *p4 , *p5;
     p1= (char *) malloc(100*sizeof(char));
     p2= (char *) malloc(100*sizeof(char));
     p3= (char *) malloc(100*sizeof(char));
     p4= (char *) malloc(100*sizeof(char));
     p5= (char *) malloc(100*sizeof(char));
     printf("Ingrese el primer nombre \n");
     gets(p1);
     printf("Ingrese el segundo nombre \n");
     gets(p2);
     printf("Ingrese el tercero nombre \n");
     gets(p3);
     printf("Ingrese el cuarto nombre \n");
     gets(p4);
     printf("Ingrese el quinto nombre \n");
     gets(p5);
        char *V [5] = {p1, p2, p3, p4, p5};
        for (int i = 0; i < 5; i++)
        {
            puts(V[i]);
        }
        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);

        











    return 0;
}