#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};
struct Cliente {
        int ClienteID; // Numerado en el ciclo iterativo
        char *NombreCliente; // Ingresado por usuario
        int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
        Producto *Productos //El tamaño de este arreglo depende de la variable
        // “CantidadProductosAPedir”
};
int CalcularPF(struct Producto *p);



int main(){
    int cant, totalFN= 0;
    srand(time(NULL));

    printf("Introduzca la cantidad de clientes \n");
    scanf("%i",&cant);
   struct Cliente * clientes = malloc(cant * sizeof(struct Cliente));
    for (int  i = 0; i < cant; i++)
    {
        clientes[i]->ClienteID = i;
        clientes[i]->NombreCliente = (char *) malloc(100*sizeof(char));
        printf("Ingrese el nombre del cliente \n");
        gets(clientes[i]->NombreCliente);
        clientes[i]->CantidadProductuosAPedir = rand() % 4 + 1;
        clientes[i]->Productos =  malloc (clientes[i]->CantidadProductuosAPedir * sizeof(struct Producto));
        for (int z = 0; z < clientes[i]->CantidadProductuosAPedir; z++)
        {
           Productos[z]->ProductoID = z;
           Productos[z]->Cantidad = rand() % 9 + 1 ;
           int ran = rand()%6;
           char *pro[100];
           strcpy(pro, TiposProductos[ran]);
           Productos[z]->TipoProducto =  malloc(strlen(pro) * sizeof * Productos[z]->TipoProducto );
           strcpy(Productos[z]->TipoProducto , pro);
           Productos[z]->PrecioUnitario = rand() % 90 + 10;
           int total;
           total = CalcularPF(Productos[z])
           printf("El total a pagar por el producto %i es %i: \n"z+1 , total));
           totalFN  += total;


        }
        



    }
    













    return  0;
}
int CalcularPF(struct Producto *p){
    int total;
    total = (*p->Cantidad) * (*p->PrecioUnitario) ;
    return total;





}