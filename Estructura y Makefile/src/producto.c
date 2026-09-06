/**
 * @file producto.c
 * @brief Funciones relacionadas con la estructura Producto
*/
#include "producto.h"

/**
 * @brief Función que crea una estructura Producto
 * 
 * @param nombre Cadena de caracteres con el nombre del producto
 * @param cantidad Cantidad del producto
 * @param proveedor Cadena de caracteres con el proveedor del producto
 * @param precio Precio del producto
 * @return Producto Estructura Producto
 */
Producto crear_producto(char* nombre, int cantidad, char* proveedor, float precio)
{
	Producto p;
	p.nombre=(char*)malloc(strlen(nombre)+1);
	if (p.nombre==NULL)
	{
		printf("Error: No se pudo asignar memoria para el nombre\n");
		exit(1);
	}
	strcpy(p.nombre,nombre);

	p.proveedor=(char*)malloc(strlen(proveedor)+1);
	if (p.proveedor==NULL)
	{
		printf("Error: No se pudo asignar memoria para el proveedor\n");
		exit(1);
	}
	strcpy(p.proveedor,proveedor);

	if (cantidad<0) cantidad=0;
	p.cantidad=cantidad;

	if (precio<0) precio=0;
	p.precio=precio;

	return p;
}

/**
 * @brief Imprime información de una estructura Producto
 * 
 * @param p Estructura Producto a imprimir
*/
void print_producto(Producto p)
{
	printf("Nombre:    %s\n",p.nombre);
	printf("Cantidad:  %d\n",p.cantidad);
	printf("Proveedor: %s\n",p.proveedor);
	printf("Precio:    %.2f\n",p.precio);
}

/**
 * @brief Elimina la memoria asignada a una estructura Producto
 * 
 * @param p Estructura Producto a eliminar
*/
void eliminar_producto(Producto p)
{
	free(p.nombre);
	free(p.proveedor);
}