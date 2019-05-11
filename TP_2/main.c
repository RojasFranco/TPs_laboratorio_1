#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"


#define QTY_ARRAY_TIPO 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdempleado=0;                   //cambiar

    Empleado arrayEmpleado[QTY_ARRAY_TIPO];                   //cambiar
    empleado_Inicializar(arrayEmpleado,QTY_ARRAY_TIPO);                   //cambiar

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Empleado \n2) Modificar Empleado \n3) Baja Empleado\n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                empleado_alta(arrayEmpleado,QTY_ARRAY_TIPO,&contadorIdempleado);                   //cambiar
                break;

            case 2: //Modificar
                empleado_modificar(arrayEmpleado,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                empleado_baja(arrayEmpleado,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                empleado_listar(arrayEmpleado,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                empleado_ordenarPorDobleCriterio(arrayEmpleado,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
