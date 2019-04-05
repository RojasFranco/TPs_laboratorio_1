#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

/**
* \brief recibe 2 numeros y guarda la suma en el puntero suma
* \param primerNumero es el primer numero recibido, segundoNumero es el segundo
y *suma es el puntero donde se guarda la suma
* \return 0 si salio todo bien, -1 en caso contrario
*
*/
int calcularSuma(int primerNumero, int segundoNumero, int* suma)
{
    int retorno=-1;
    if(suma!=NULL)
    {
        *suma=primerNumero+segundoNumero;
        retorno=0;
    }
    return retorno;
}

/**
* \brief recibe 2 numeros y guarda la resta en el puntero resta
* \param primerNumero es el primer numero recibido, segundoNumero es el segundo
y *resta es el puntero donde se guarda la resta
* \return 0 si salio todo bien, -1 en caso contrario
*
*/
int calcularResta(int primerNumero, int segundoNumero, int *resta)
{
    int retorno=-1;
    if (resta!=NULL)
    {
        *resta=primerNumero-segundoNumero;
        retorno=0;
    }
    return retorno;
}

/**
* \brief recibe 2 numeros y guarda la division en el puntero division
* \param primerNumero es el primer numero recibido, segundoNumero es el segundo
y *division es el puntero donde se guarda la division
* \return 0 si salio todo bien, -1 si su divisor es 0, o  -2 si la posicion del puntero es invalida
*
*/
int calcularDivision(int primerNumero, int segundoNumero, float *division)
{

    if(division!=NULL)
    {
        if(segundoNumero==0)
        {
            return -1;
        }
        else
        {
            *division=(float)primerNumero/segundoNumero;
            return 0;
        }
    }
    return -2;
}

/**
* \brief recibe 2 numeros y guarda la multiplicacion en el puntero multiplicacion
* \param primerNumero es el primer numero recibido, segundoNumero es el segundo
y *multiplicacion es el puntero donde se guarda la multiplicacion
* \return 0 si salio todo bien, -1 en caso contrario
*
*/
int calcularMultiplicacion(int primerNumero, int segundoNumero, int *multiplicacion)
{
    int retorno=-1;
    if (multiplicacion!=NULL)
    {
        *multiplicacion = primerNumero*segundoNumero;
        retorno=0;
    }
    return retorno;
}

/**
* \brief recibe 1 numer y guarda su factorial en el puntero factorial
* \param numero es el numero recibido, y *factorial numero el puntero donde se guarda
el resultado
* \return 0 si salio todo bien, -1 si se quiere calcular factorial de un negativo
-2 si la posicion del puntero es invalida
*
*/
int calcularFactorial(int numero, int *factorialNumero)
{
    int i;
    int factorial=1;
    if (numero<0)
    {
        return -1;
    }
    if (factorialNumero!=NULL)
    {
        for (i=1; i<= numero; i+=1)
        {
            factorial*=i;
        }
        *factorialNumero = factorial;
        return 0;
    }
    return -2;
}
