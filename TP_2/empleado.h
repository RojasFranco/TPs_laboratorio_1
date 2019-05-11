#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE]; ///nombre
    int sector; ///sector
    float salario; ///salario
    char apellido[TEXT_SIZE]; ///apellido

}Empleado;


#endif // EMPLEADO_H_INCLUDED

int empleado_Inicializar(Empleado array[], int size);                                    //cambiar empleado
int empleado_buscarEmpty(Empleado array[], int size, int* posicion);                    //cambiar empleado
int empleado_buscarID(Empleado array[], int size, int valorBuscado, int* posicion);                    //cambiar empleado
int empleado_buscarInt(Empleado array[], int size, int valorBuscado, int* posicion);                    //cambiar empleado
int empleado_buscarString(Empleado array[], int size, char* valorBuscado, int* indice);                    //cambiar empleado
int empleado_alta(Empleado array[], int size, int* contadorID);                          //cambiar empleado
int empleado_baja(Empleado array[], int sizeArray);                                      //cambiar empleado
int empleado_bajaValorRepetidoInt(Empleado array[], int sizeArray, int valorBuscado);
int empleado_modificar(Empleado array[], int sizeArray);                                //cambiar empleado
int empleado_ordenarPorDobleCriterio(Empleado array[],int size, int orderFirst, int orderSecond);                                  //cambiar empleado
int empleado_listar(Empleado array[], int size);                      //cambiar empleado


