/**
 * @file main.c
*/
#include "producto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void productos_to_csv(Producto p[]);
void generar_proveedor(char buffer[6]);
void limpiar_buffer(void);
float pedir_precio(char* nombre_producto);

int main()
{
	int i;
	srand(time(NULL));

	char* nombres[5]={"Teclado Mecanico","Mouse Gamer","Monitor 24 Pulgadas","Memoria RAM 16GB","Disco SSD 1TB"};
	char proveedor[6];
	float precio;

	Producto Productos[5];
	printf("INGRESO DE PRECIOS PARA EL INVENTARIO\n\n");

	for (i=0;i<5;i++)
	{
		int cantidad=(rand()%100)+1; 
		generar_proveedor(proveedor);      

		precio=pedir_precio(nombres[i]);

		Productos[i]=crear_producto(nombres[i],cantidad,proveedor,precio);
	}
	printf("\n");

	printf("RESUMEN DEL INVENTARIO GENERADO\n");
	for (i=0;i<5;i++)
	{
		print_producto(Productos[i]);
		printf("\n");
	}

	productos_to_csv(Productos);
	printf("\nArchivo guardado en build/inventario.csv\n");

	for (i=0;i<5;i++) eliminar_producto(Productos[i]);

	return 0;
}

/**
 * @brief Limpia el buffer del teclado leyendo hasta el salto de linea
*/
void limpiar_buffer(void)
{
	char c=getchar();
	while (c!='\n')
	{
		c=getchar();
	}
}

/**
 * @brief Pide el precio por teclado y repite la pregunta si la entrada no es valida
*/
float pedir_precio(char* nombre_producto)
{
	float precio;
	int leidos;

	while (1)
	{
		printf("Ingrese el precio para '%s': ",nombre_producto);
		leidos=scanf("%f",&precio);
		if (leidos!=1)
		{
			printf("Error: Entrada invalida. Intente de nuevo.\n");
			limpiar_buffer();
		}
		else if (precio<0.0f)
		{
			printf("Error: El precio no puede ser negativo. Intente de nuevo.\n");
			limpiar_buffer();
		}
		else if (precio>100000000.0f)
		{
			printf("Error: Precio fuera de rango. Intente de nuevo.\n");
			limpiar_buffer();
		}
		else
		{
			limpiar_buffer();
			return precio;
		}
	}
}

/**
 * @brief Funcion que crea un CSV a partir de un arreglo de Productos
*/
void productos_to_csv(Producto p[])
{
	int i;
	FILE* archivo;
	archivo=fopen("build/inventario.csv", "w");
	if (archivo==NULL)
	{
		printf("Error: No se pudo abrir el archivo\n");
		exit(1);
	}
	fprintf(archivo, "Nombre,Cantidad,Proveedor,Precio\n");
	for (i=0; i<5; i++)
	{
		fprintf(archivo, "%s,%d,%s,%.2f\n",p[i].nombre,p[i].cantidad,p[i].proveedor,p[i].precio);
	}
	fclose(archivo);
}

/**
 * @brief Genera una cadena aleatoria de 5 caracteres
*/
void generar_proveedor(char buffer[6])
{
	int j;
	const char chars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (j=0;j<5;j++)
	{
		buffer[j]=chars[rand()%(sizeof(chars)-1)];
	}
	buffer[5]='\0';
}