#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#define MAX_NOMBRE 20
#define MAX_HS 200
#define MAX_SUELDO 30000
#define MAX_ID 2000


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile=NULL;
    int retorno=-1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path, "r");
        if(pFile!=NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
            retorno=0;
            printf("\n Empleados cargados \n");
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile = NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);
            retorno=0;
            printf("\n Empleados cargados \n");
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char buffeNombre[MAX_NOMBRE];
    int bufferHorasTrabajadas;
    char bufferHorasTrabajadasStr[512];
    int bufferSueldo;
    char bufferSueldoStr[512];
    int id;
    char idStr[512];
    Employee* auxEmpleado;
    /*auxEmpleado = employee_new();*/
    int reintentos;
    reintentos=2;
    if(pArrayListEmployee!=NULL)
    {
        if( !utn_getName("\nIngrese nombre: ", "\nNombre invalido", 1,MAX_NOMBRE, reintentos, buffeNombre) &&
            !utn_getUnsignedInt("\nIngrese hs trabajadas: ", "\nDato invalido", 1, 4, 1, MAX_HS, 2, &bufferHorasTrabajadas) &&
            !utn_getUnsignedInt("\nIngrese sueldo: ", "\ndato invalido", 1, 6, 1, MAX_SUELDO, 2, &bufferSueldo) )
        {
            id = controller_IdMaximo(pArrayListEmployee)+1;
            sprintf(idStr, "%d", id);
            sprintf(bufferHorasTrabajadasStr, "%d", bufferHorasTrabajadas);
            sprintf(bufferSueldoStr, "%d", bufferSueldo);
            auxEmpleado = employee_newParametros(idStr, buffeNombre, bufferHorasTrabajadasStr, bufferSueldoStr);
            if( auxEmpleado!= NULL)
            {
                ll_add(pArrayListEmployee, auxEmpleado);
                printf("\n Empleado agregado \n");
            }
        }
        /*else
        {
            employee_delete(auxEmpleado);
        }*/
        retorno=0;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int idBuscado;
    int posicionEmpleado;
    int opcionModificar;
    char bufferNombre[512];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    Employee* auxEmpleado;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nIngrese id del empleado a modificar: ", "\n Dato invalido", 1, 5,1,MAX_ID, 2, &idBuscado);
        posicionEmpleado = controller_buscarId(pArrayListEmployee, idBuscado);
        if(posicionEmpleado != -1)
        {
            auxEmpleado = ll_get(pArrayListEmployee, posicionEmpleado);
            do
            {
                utn_getUnsignedInt("\n 1)Nombre\n 2)Horas Trabajadas\n 3)Sueldo\n 4)Salir\n Opcion a modificar: ", "\nopcion invalida", 1, sizeof(int), 1, 5, 2, &opcionModificar);
                switch(opcionModificar)
                {
                    case 1:
                        utn_getName("\n Nuevo nombre: ", "\nDato invalido", 1, MAX_NOMBRE, 2, bufferNombre);
                        employee_setNombre(auxEmpleado, bufferNombre);
                        break;
                    case 2:
                        utn_getUnsignedInt("\n cantidad hs trabajadas: ", "\nDato invalido", 1, sizeof(int), 1, MAX_HS, 2, &bufferHorasTrabajadas);
                        employee_setHorasTrabajadas(auxEmpleado, bufferHorasTrabajadas);
                        break;
                    case 3:
                        utn_getUnsignedInt("\n Nuevo sueldo: ", "\n dato invalido", 1, sizeof(int), 1, MAX_SUELDO, 2, &bufferSueldo);
                        employee_setSueldo(auxEmpleado, bufferSueldo);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\n Opcion invalida\n");
                }
            }while(opcionModificar!=4);
        }
        else
        {
            printf("\n No se encuentra id \n");
        }
    retorno=0;
    }



    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int idEliminar;
    int posicionId;
    Employee* auxEmpleado;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\n Ingrese id a eliminar:", "\nDato invalido", 1, 5, 1, MAX_ID, 2, &idEliminar);
        posicionId = controller_buscarId(pArrayListEmployee, idEliminar);
        if(posicionId!=-1)
        {
            auxEmpleado = ll_get(pArrayListEmployee, posicionId);
            employee_delete(auxEmpleado);
            ll_remove(pArrayListEmployee, posicionId);
            printf("\n Empleado eliminado \n");
        }
        else
        {
            printf("\n No se encuentra id \n");
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* auxEmpleado;
    int i;
    int lenArray;
    int bufferId;
    char bufferNombre[512];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    lenArray = ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        for(i=0; i<lenArray; i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if(!employee_getId(auxEmpleado, &bufferId) &&
               !employee_getNombre(auxEmpleado, bufferNombre) &&
               !employee_getHorasTrabajadas(auxEmpleado, &bufferHorasTrabajadas) &&
               !employee_getSueldo(auxEmpleado,&bufferSueldo))
            {
                printf("\n ID:%d - Nombre:%s - HorasTrabajadas:%d - Sueldo:%d", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ///ll_sort(pArrayListEmployee, )     aplicar ordenamiento por puntero funcion.-
        ll_sort(pArrayListEmployee, employee_compararPorNombre, 1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile=NULL;
    int retorno=-1;
    Employee* auxEmpleado;
    int i;
    int lenArray;
    char bufferNombre[512];
    int bufferId;
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        lenArray = ll_len(pArrayListEmployee);
        pFile = fopen(path, "w");
        if(pFile!=NULL)
        {
            for(i=0; i<lenArray; i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee, i);
                employee_getId(auxEmpleado, &bufferId);
                employee_getHorasTrabajadas(auxEmpleado, &bufferHorasTrabajadas);
                employee_getSueldo(auxEmpleado, &bufferSueldo);
                employee_getNombre(auxEmpleado, bufferNombre);
                fprintf(pFile , "%d, %s, %d, %d\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            }
            retorno=0;
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile=NULL;
    Employee* auxEmpleado;
    int i;
    int lenArray;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        lenArray = ll_len(pArrayListEmployee);
        pFile = fopen(path, "wb");
        if(pFile!=NULL)
        {
            for(i=0; i<lenArray; i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee, i);
                fwrite(auxEmpleado, sizeof(Employee),1, pFile);
                //printf("\n %s", auxEmpleado->nombre);
            }
            retorno=0;
            fclose(pFile);
        }
    }

    return retorno;
}

int controller_IdMaximo(LinkedList* pArrayListEmployee)
{
    //int retorno=-1;
    Employee* auxEmpleado;
    int idMaximo=-1;
    int i;
    int lenArray;
    int bufferId;
    lenArray = ll_len(pArrayListEmployee);
    for(i=0; i<lenArray; i++)
    {
        auxEmpleado=ll_get(pArrayListEmployee, i);
        if(!employee_getId(auxEmpleado, &bufferId) && bufferId>idMaximo)
        {
            idMaximo = bufferId;
        }
    }
    return idMaximo;
}

int controller_buscarId(LinkedList* pArrayListEmployee, int idBuscado)
{
    int retorno=-1;
    Employee* auxEmpleado;
    int idEmpleado;
    int lenArray;
    lenArray = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL && idBuscado>=0)
    {
        for(i=0; i<lenArray; i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if (!employee_getId(auxEmpleado, &idEmpleado) && idEmpleado == idBuscado)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}
