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
}typedef Producto;
struct Cliente {
        int ClienteID; // Numerado en el ciclo iterativo
        char *NombreCliente; // Ingresado por usuario
        int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
        struct Producto *Productos //El tamaño de este arreglo depende de la variable
        // “CantidadProductosAPedir”
}typedef Cliente;
float CalcularPF(Producto p);



int main(){
    int cant;
    float totalFN = 0;
    srand(time(NULL));

    printf("Introduzca la cantidad de clientes \n");
    scanf("%i",&cant);
    Cliente *clientes;
    clientes = (Cliente *) malloc(cant * sizeof(Cliente));
    for (int  i = 0; i < cant; i++)
    {
        clientes[i].ClienteID = i;
        fflush(stdin);
        clientes[i].NombreCliente = (char *) malloc(100*sizeof(char));
        printf("Ingrese el nombre del cliente \n");
        gets(clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 4 + 1;
        clientes[i].Productos = (Producto *) malloc (clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int z = 0; z < clientes[i].CantidadProductosAPedir; z++)
        {
            float total = 0;
            char pro;
            pro =(char *)malloc(100);
           clientes[i].Productos[z].ProductoID = z;
           clientes[i].Productos[z].Cantidad = rand() % 9 + 1 ;
           int ran = rand()%6;
           strcpy(pro, TiposProductos[ran]);
           clientes[i].Productos[z].TipoProducto =  (char * )malloc(strlen(pro)+1 );
           strcpy(clientes[i].Productos[z].TipoProducto , pro);
           clientes[i].Productos[z].PrecioUnitario = rand() % 90 + 10;
           total = CalcularPF(clientes[i].Productos[z]);
           printf("El total a pagar por el producto %i es %i: \n", z+1 , total);
           totalFN  += total;


        }
        
        
    }
        printf("Mostrando los datos: \n");
        for (int i = 0; i < cant; i++)
        {
              printf("Cliente %d\n", i + 1);
              printf("ID del cliente : %d /n", clientes[i].ClienteID);
              puts(clientes[i].NombreCliente);
              printf("\nCantidad de Productos: %d\n",clientes[i].CantidadProductosAPedir);
              printf("\nProductos solicitados: \n");
              for (int z = 0; z < clientes[i].CantidadProductosAPedir; z++)
              {
                  puts(clientes[i].Productos[z].TipoProducto);
                  printf("Precio Unitario : %2f /n", clientes[i].Productos[z].PrecioUnitario);
                  printf("Cantidad : %d /n", clientes[i].Productos[z].Cantidad);
                  printf("Subtotal : %2f /n", CalcularPF(clientes[i].Productos[z]));

              }
              printf("Precio a pagar en total por el cliente: %2f /n", totalFN);
        }

        for(int i=0;i<cant;i++){
        for(int z=0;z<clientes[i].CantidadProductosAPedir;z++){
            free(clientes[i].Productos[z].TipoProducto);
            }
            free(clientes[i].Productos);
            free(clientes[i].NombreCliente);
        }
       free(clientes);
    













    return  0;
}
float CalcularPF( Producto p){
    float total;
    total = (p.Cantidad) * (p.PrecioUnitario) ;
    return total;





}