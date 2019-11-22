/**
 * TDA Arbol.
 * @author Pablo Lencina, Adrian Flores
 */

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "lista.h"

#define ARB_OPERACION_INVALIDA      10
#define ARB_POSICION_INVALIDA       11
#define ARB_ERROR_MEMORIA           12
#define POS_NULA NULL
#define ELE_NULO NULL

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern “C”
{
#endif

/**
Inicializa un árbol vacío.
Una referencia al árbol creado es referenciado en *A.
**/
DLL_EXPORT extern void crear_arbol(tArbol * a);

/**
Crea la raíz de A.
Si A no es vacío, finaliza indicando ARB_OPERACION_INVALIDA.
**/
DLL_EXPORT extern void crear_raiz(tArbol a, tElemento e);

/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo rótulo es E.
 Si NH es NULL, el nuevo nodo se agrega como último hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, mientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/
DLL_EXPORT extern tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e);

/**
 Elimina el nodo N de A.
 El elemento almacenado en el árbol es eliminado mediante la función fEliminar parametrizada.
 Si N es la raíz de A, y tiene un sólo hijo, este pasa a ser la nueva raíz del árbol.
 Si N es la raíz de A, y a su vez tiene más de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la raíz de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posición que ocupa N en la lista de hijos de su padre.
**/
DLL_EXPORT extern void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento));

/**
 Destruye el árbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el árbol son eliminados mediante la función fEliminar parametrizada.
**/
DLL_EXPORT extern void a_destruir(tArbol * a, void (*fEliminar)(tElemento));

/**
Recupera y retorna el elemento del nodo N.
*/
DLL_EXPORT extern tElemento a_recuperar(tArbol a, tNodo n);

/**
Recupera y retorna el nodo correspondiente a la raíz de A.
**/
DLL_EXPORT extern tNodo a_raiz(tArbol a);

/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
DLL_EXPORT extern tLista a_hijos(tArbol a, tNodo n);

/**
 Inicializa un nuevo árbol en *SA.
 El nuevo árbol en *SA se compone de los nodos del subárbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
DLL_EXPORT extern void a_sub_arbol(tArbol a, tNodo n, tArbol * sa);

#ifdef __cplusplus
}
#endif
