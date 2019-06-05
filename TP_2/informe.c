#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"
#include "informe.h"

#define QTY_ARRAY_TIPO 1000
#define SORT_UP 1
#define SORT_DOWN 0

int informe_ordenarEmpleados(Empleado arrayEmpleado[], int len)
{
    int retorno=-1;
    if(arrayEmpleado!=NULL && len>=0)
    {
        retorno=0;
        if(!empleado_cantidadEmpleados(arrayEmpleado, len))
        {
            empleado_ordenarPorDobleCriterio(arrayEmpleado, len, SORT_DOWN, SORT_DOWN);
            empleado_listar(arrayEmpleado, len);
            printf("ASDASDSA");
        }
        else
        {
            printf("\n No hay empleados \n");
        }
    }
    return retorno;
}

int informe_promedioSalarios(Empleado arrayEmpleado[], int len)
{
    int retorno=-1;
    int i;
    float salarioTotal=0;
    int cantidadEmpleados=0;
    float promedio;
    int cantidadEmpleadosSuperanPromedio=0;
    if (arrayEmpleado!=NULL && len>=0)
    {
        retorno=0;
        for(i=0; i<len; i++)
        {
            if(arrayEmpleado[i].isEmpty==1)
            {
                continue;
            }

            salarioTotal+=arrayEmpleado[i].salario;
            cantidadEmpleados+=1;
        }
        if(cantidadEmpleados>=1)
        {
            promedio = salarioTotal/cantidadEmpleados;
            printf("\nEl salario total es: %.2f\n", salarioTotal);
            printf("El promedio de los salarios es: %.2f\n", promedio);

            for(i=0; i<len; i++)
            {
                if(arrayEmpleado[i].salario> promedio && arrayEmpleado[i].isEmpty==0)
                {
                    cantidadEmpleadosSuperanPromedio+=1;
                }
            }
            printf("La cantidad de empleados que superan el promedio son: %d", cantidadEmpleadosSuperanPromedio);
        }
        else
        {
            printf("\n No hay empleados \n");
        }
    }
    return retorno;
}
