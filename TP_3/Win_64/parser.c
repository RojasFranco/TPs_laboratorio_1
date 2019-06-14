#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int cantidadDatosLeidos;
    char auxPrimerLinea[512];
    char bufferId[512];
    char bufferNombre[512];
    char bufferHorasTrabajadas[512];
    char bufferSueldo[512];
    Employee* auxEmpleado;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        retorno = 0;
        fscanf(pFile, "%[^\n]\n", auxPrimerLinea);
        do
        {
            cantidadDatosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            if( cantidadDatosLeidos==4 )
            {
                auxEmpleado = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
                if(auxEmpleado!=NULL)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                }
                //printf("\n%s", bufferNombre);
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee auxEmpleado;
    Employee* pEmpleado;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            fread(&auxEmpleado, sizeof(Employee), 1, pFile);
            //printf("\n %s", auxEmpleado.nombre);
            pEmpleado = employee_newParametrosBin(auxEmpleado.id, auxEmpleado.nombre, auxEmpleado.horasTrabajadas, auxEmpleado.sueldo);
            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
            }

        }
        retorno=0;
    }
    return retorno;
}
