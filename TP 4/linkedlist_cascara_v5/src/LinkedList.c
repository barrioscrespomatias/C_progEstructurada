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

    if(this!= NULL)
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


    int i;



    if(this!= NULL)
    {
        if(nodeIndex>=0 && nodeIndex <ll_len(this))
        {
            pNode = this->pFirstNode;

            for(i=0; i<ll_len(this); i++)
            {
                if(i == nodeIndex)
                {

                    break;
                }

                else

                {
                    pNode = pNode->pNextNode;

                }

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
    int returnAux = -1;
    Node *pNodeAnterior = NULL;
    Node *pNodeNuevo = NULL;

    ///Asigno memoria para dos nodos
    pNodeNuevo =(Node*) malloc(sizeof(Node));
    pNodeAnterior = (Node*) malloc(sizeof(Node));

    ///Condiciones de ingreso
    if(this!= NULL && nodeIndex>=0 && nodeIndex <=ll_len(this))
    {
        ///OBTENGO EL NODO ANTERIOR
        /// GET NODE YA TIENE UN FOR. ME DEYVUELVE EL NODO
//        pNodeAnterior = getNode(this,nodeIndex-1);

        /// INICIO DE LA LISTA
        if(nodeIndex == 0)
        {

            pNodeNuevo->pNextNode = this->pFirstNode;
            this->pFirstNode = pNodeNuevo;
            this->size++;
            returnAux = 0;
        }
        /// CUALQUIER PARTE DE LA LISTA QUE NO SEA EL INICIO
        else
        {
            pNodeAnterior = getNode(this,nodeIndex-1);
            pNodeNuevo->pNextNode = pNodeAnterior->pNextNode;
            pNodeAnterior->pNextNode = pNodeNuevo;
            this->size ++;
            returnAux = 0;


        }
        ///PASO EL ELEMENTO AL NUEVO NODO
        pNodeNuevo->pElement = pElement;

    }





    return returnAux;
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
    int indiceUltimo = ll_len(this);

//    printf("%d\n",indiceUltimo-1);
//    system("pause");

//    Node *pNodeAnterior = NULL;

    if(this!= NULL)
    {
        addNode(this,indiceUltimo,pElement);
        returnAux = 0;
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



/// Retorna un puntero al elemento que se encuentra en el índice especificado.
/// Verificando que el puntero this sea distinto de NULL y que index sea positivo e inferior
/// al tamaño del array. Si la verificación falla la función retorna (NULL)
/// y si tiene éxito retorna el elemento.


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxiliar = NULL;
    auxiliar = (Node*)malloc(sizeof(Node));

    if(this!= NULL && index>=0 && index < ll_len(this))
    {
        auxiliar = getNode(this,index);
        returnAux  = auxiliar->pElement;
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
    Node* nodoAuxiliar = (Node*)malloc(sizeof(Node));

    if(this!=NULL && index>= 0 && index < ll_len(this))
    {
//        nodoAuxiliar = getNode(this,index);
//        nodoAuxiliar->pElement = pElement;

        nodoAuxiliar = getNode(this,index);
        nodoAuxiliar->pElement = pElement;
        returnAux = 0;


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
    Node* pNodeAeliminar = NULL;
    Node* pNodeAnterior = NULL;

    pNodeAeliminar = (Node*) malloc(sizeof(Node));
    pNodeAnterior = (Node*) malloc(sizeof(Node));



    if(this!= NULL && index>= 0 && index<ll_len(this))
    {
        pNodeAeliminar = getNode(this,index);

        if(index == 0)
        {
            this->pFirstNode = pNodeAeliminar->pNextNode;
            this->size--;

            returnAux = 0;

        }

        else
        {
            pNodeAnterior = getNode(this,index-1);
            pNodeAnterior->pNextNode = pNodeAeliminar->pNextNode;
            this->size--;
            returnAux = 0;

        }
        returnAux = 0;
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

    if(this!=NULL)
    {
        this->pFirstNode = NULL;
        this->size= 0;

        returnAux = 0;
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

    if(this!= NULL)
    {
        ll_clear(this);
        this = NULL;

        returnAux = 0;
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
    Node*pNodeAuxiliar = NULL;
    pNodeAuxiliar = (Node*)malloc(sizeof(Node));

    int i;
    if(this!= NULL)


    {

        for(i=0; i<ll_len(this); i++)
        {
            pNodeAuxiliar = getNode(this,i);
            if(pElement == pNodeAuxiliar->pElement)
            {
                returnAux = i;
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
    Node*pNodeAuxiliar = NULL;
    pNodeAuxiliar = (Node*)malloc(sizeof(Node));

    if(this!= NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
//    Node* nodoAnterior = NULL;
//    Node*nodoNuevo = NULL;
//
//    nodoAnterior = (Node*) malloc(sizeof(Node));
//    nodoNuevo = (Node*) malloc(sizeof(Node));
//
//
//    if(this!= NULL && index>=0 && index < ll_len(this))
//    {
//        if(this->size == 0)
//        {
//            nodoNuevo->pNextNode = this->pFirstNode;
//            this->pFirstNode = nodoNuevo;
//            this->size ++;
//            returnAux = 0;
//
//        }
//
//        else
//        {
//            nodoAnterior = getNode(this,index-1);
//
//            nodoNuevo->pNextNode=nodoAnterior->pNextNode;
//            nodoAnterior->pNextNode = nodoNuevo;
//            this->size++;
//            returnAux=0;
//        }
//
//        nodoNuevo->pElement = pElement;
//
//

//    }

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
void* ll_pop(LinkedList* this, int indice)
{
    void* returnAux = NULL;
    Node *nodoAEliminar = NULL;

    if(this!= NULL && indice >= 0 && indice <ll_len(this))
    {
        nodoAEliminar = getNode(this,indice);
        returnAux = nodoAEliminar->pElement;
        ll_remove(this,indice);
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
    int existe;


    if(this!= NULL)
    {
        existe = ll_indexOf(this,pElement);

        if(existe == -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
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
    int i, j, existe;

    Node* aComparar = NULL;
    aComparar = (Node*)malloc(sizeof(Node));


    if(this!= NULL && this2 != NULL)//||
    {
        for(i= 0; i<ll_len(this2); i++)
        {
            aComparar = getNode(this2,i);
            existe = ll_contains(this,aComparar->pElement);
            if(existe != 1)
            {
                ///No puedo poner un return.
                ///PROBAR CON WHILE
                return returnAux = 0;
            }
        }
        returnAux = 1;
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
    Node*pNode;


    int i;

    if(this!= NULL && from>=0 && from<ll_len(this) && to<=ll_len(this) && to>= from)
    {
        cloneArray = ll_newLinkedList();

            for(i=from; i<to; i++)
            {
                pNode = getNode(this,i);
                ll_add(cloneArray,pNode->pElement);
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
    int cantidad = ll_len(this);

    if(this!= NULL)
    {
        cloneArray = ll_subList(this,0,cantidad);

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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;

    Node* pNodeA = NULL;
    Node* pNodeB = NULL;
    Node* pNodeAuxiliar = NULL;

    int i, j;

    if(this!= NULL)
    {
        for(i=0; i<ll_len(this)-1;i++)
        {
            for(j=i+1; j<ll_len(this); j++)
            {

                ///La funcion debe recibir los paratros de punteros.
                /// tengo que hacer un get de la funcion.
               //if(*pFunc)
                {
                    pNodeA = pNodeB;
                    pNodeB = pNodeAuxiliar;
                    pNodeAuxiliar = pNodeA;
                    returnAux = 0;
                }
                else
                {

                }
            }
        }

    }

    return returnAux;

}

