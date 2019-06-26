#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int posicionNodoRecorrido;
    int lenLinkedList;
    if(this!=NULL && nodeIndex>=0 && this->pFirstNode!=NULL && nodeIndex<this->size)
    {
        lenLinkedList = this->size;
        pNode = this->pFirstNode;

        for(posicionNodoRecorrido=0; posicionNodoRecorrido<lenLinkedList; posicionNodoRecorrido++)
        {
            if(posicionNodoRecorrido == nodeIndex)
            {
                break;
            }
            else
            {
                pNode = pNode->pNextNode;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    //OBS: no hay que verificar que pElement sea o no null

    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoNuevo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNodoNuevo = (Node*) malloc(sizeof(Node));
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            if(nodeIndex == 0)
            {
                if(this->pFirstNode == NULL) pNodoNuevo->pNextNode = NULL;
                if(this->pFirstNode != NULL)  pNodoNuevo->pNextNode = this->pFirstNode;
                this->pFirstNode = pNodoNuevo;
            }
            else
            {
                pNodoAnterior = getNode(this,nodeIndex-1);
                pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;
                pNodoAnterior->pNextNode = pNodoNuevo;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;


/******************* EN CLASE ************************************
    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoProximo;
    Node* pNodoNuevo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(nodeIndex == 0)
        {
            pNodoAnterior = this->pFirstNode;
        }
        else
        {
            pNodoAnterior = getNode(this,nodeIndex - 1);
        }

        if(pNodoAnterior != NULL) pNodoProximo = pNodoAnterior; ///
        if(pNodoAnterior == NULL) pNodoProximo = NULL;

        pNodoNuevo = (Node*)malloc(sizeof(Node));
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            pNodoNuevo->pNextNode = pNodoProximo;

            if(nodeIndex == 0)
            {

                this->pFirstNode = pNodoNuevo;

            }
            else
                pNodoAnterior->pNextNode = pNodoNuevo;

            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
***************************************/

///////////////////////////////////////////////////////////////////////////////////////////

/*********** Lo que hice yo **************

    int returnAux = -1;
    int posicionNodoRecorrido;
    Node* pNodeAuxiliar = (Node*) malloc(sizeof(Node));
    Node* pNodeActual;
    Node* pNodeSiguiente;
    int lenLinkedList;

    if(this!=NULL && nodeIndex>=0 && pElement!=NULL && nodeIndex<=(this->size) && pNodeAuxiliar!=NULL)
    {
        if(this->size==0)
        {
            pNodeSiguiente = this->pFirstNode;
            pNodeAuxiliar->pElement = pElement;
            pNodeAuxiliar->pNextNode = pNodeSiguiente;
            this->pFirstNode = pNodeAuxiliar;
            this->size=1;
            returnAux=0;
        }
        else
        {
            lenLinkedList = this->size;
            pNodeActual = this->pFirstNode;
            for(posicionNodoRecorrido=1; posicionNodoRecorrido<=lenLinkedList;posicionNodoRecorrido++)
            {
                //pNodeNext = pNode->pNextNode;
                if(posicionNodoRecorrido == nodeIndex)
                {
                    pNodeSiguiente = pNodeActual->pNextNode; ///guardo el siguiente
                    pNodeAuxiliar->pElement = pElement;
                    pNodeAuxiliar->pNextNode = pNodeSiguiente;
                    pNodeActual->pNextNode = pNodeAuxiliar;
                    pNodeAuxiliar->pNextNode = pNodeSiguiente;
                    returnAux=0;
                    this->size+=1;
                    break;
                }
                else
                {
                    pNodeActual = pNodeActual->pNextNode;
                }
            }
        }
    }
    return returnAux;
*************************/
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenArray;
    if(this!=NULL)
    {
        lenArray=ll_len(this);
        addNode(this, lenArray, pElement);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAuxiliar;
    if(this!=NULL && index<ll_len(this) && index>=0)
    {
        nodoAuxiliar = getNode(this, index);
        returnAux = nodoAuxiliar->pElement;

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAuxiliar;
    if(this!=NULL && index<ll_len(this) && index>=0)
    {
        nodoAuxiliar = getNode(this, index);
        nodoAuxiliar->pElement = pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAuxiliar;
    Node* nodoAnterior;
    Node* nodoProximo;
    if(this!=NULL && ll_len(this)>0 && index>=0 && index<ll_len(this))
    {
        nodoAuxiliar = getNode(this, index);
        nodoProximo = getNode(this, index+1);
        if(index==0)
        {
            this->pFirstNode = nodoProximo;
        }
        else
        {
            nodoAnterior = getNode(this, index-1);
            nodoAnterior->pNextNode = nodoProximo;
        }
        free(nodoAuxiliar);
        returnAux=0;
        this->size-=1;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    //Node* nodoAuxiliarLiberar;
    if(this!=NULL)
    {
        /************
        lenArray = ll_len(this);

        no se debe utilizar
        for(i=0; i<lenArray; i++)
        {
            ll_remove(this, i);
        }
        *****/

        do
        {
            //nodoAuxiliarLiberar = getNode(this, 0);
            ll_remove(this, 0);
        } while(ll_len(this)>0); ///nodoAuxiliarLiberar!=NULL no valido

        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* pElementAuxiliar;
    if(this!=NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            pElementAuxiliar = ll_get(this, i);
            if(pElementAuxiliar == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_len(this))
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        addNode(this, index, pElement);
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index<ll_len(this) && index>=0)
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if (ll_indexOf(this, pElement) != -1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElementBuscado;
    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0; i<ll_len(this2); i++)
        {
            pElementBuscado = ll_get(this2, i);
            if(ll_contains(this, pElementBuscado)!=1)
            {
                returnAux=0;
                break;
            }
        }
        //returnAux=1;
    }
    return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
//    cloneArray = ll_newLinkedList();
    void* pElementoAuxiliar;
    int i;
    if(this!=NULL && from>=0  && from<to && to<=ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for(i=from; i<to; i++)
        {
            pElementoAuxiliar = ll_get(this, i);
            ll_add(cloneArray, pElementoAuxiliar);
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flag;
    int i;
    int lenArray;
    void* primerElemento;
    void* segundoElemento;
    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        lenArray = ll_len(this);
        do
        {
            flag=0;
            returnAux=0;
            for(i=0; i<lenArray-1; i++)
            {
                primerElemento=ll_get(this, i);
                segundoElemento=ll_get(this,i+1);
                if(pFunc(primerElemento, segundoElemento)<0 && order==0 ||
                   pFunc(primerElemento, segundoElemento)>0 && order==1 )
                {
                    ll_set(this, i, segundoElemento);
                    ll_set(this, i+1, primerElemento);
                    flag=1;
                }
            }
        }while(flag);

    }
    return returnAux;

}


/**
se modifican elementos de this segun criterio de la funcion pFunc
*/
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    //LinkedList* retorno = NULL;
    int retorno=-1;
    int i;
    int lenArray;
    void* pElementoAuxiliar;
    if(this!=NULL && pFunc!=NULL)
    {
        //retorno = ll_newLinkedList();
        retorno=0;
        lenArray = ll_len(this);
        for(i=0; i<lenArray; i++)
        {
            pElementoAuxiliar = ll_get(this, i);
            pFunc(pElementoAuxiliar);
            /*if(pFunc(pElementoAuxiliar)) //si no da error
            {
                ll_add(retorno, pElementoAuxiliar);
            }*/
        }
    }
    return retorno;
}


/****
recorre this y crea sublista con los elementos que cumplen la funcion pFunc
****/
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* retorno=NULL;
    int i;
    int lenArray;
    void* pElementoAuxiliar;
    if(this!=NULL && pFunc!=NULL)
    {
        retorno = ll_newLinkedList();
        lenArray = ll_len(this);
        for(i=0; i<lenArray; i++)
        {
            pElementoAuxiliar = ll_get(this, i);
            if(pFunc(pElementoAuxiliar))
            {
                ll_add(retorno, pElementoAuxiliar);
            }
        }
    }
    return retorno; //Obs: en caso de no agregar ningun elemento devuelvo puntero a la lista vacia(no la elimino).-
}


/****
recorre la lista y elimina los elementos que cumplen la funcion pFunc devolviendo la misma lista modificada
****/
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
    int retorno=-1;
    void* pElementoAuxiliar;
    int i;
    if(this!=NULL && pFunc!=NULL)
    {
        retorno=0;
        for(i=0; i<ll_len(this); i++)
        {
            pElementoAuxiliar = ll_get(this, i);
            if(pFunc(pElementoAuxiliar))
            {
                ll_remove(this, i);
                i-=1;
            }
        }
    }
    return retorno;
}
