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

/**
Inicializa un �rbol vac�o.
Una referencia al �rbol creado es referenciado en *A.
**/
extern void crear_arbol(tArbol * a)
{
    (*a)=(tArbol)malloc(sezeof(struct arbol));
    (*a)->raiz=POS_NULA;
}

/**
Crea la ra�z de A.
Si A no es vac�o, finaliza indicando ARB_OPERACION_INVALIDA.
**/
extern void crear_raiz(tArbol a, tElemento e)
{
    a->raiz=(tNodo)malloc(sizeof(struct nodo));
    a->raiz->elemento=e;
    tLista* l;
    a->raiz->hijos=crear_lista(l);
    a->raiz->padre=POS_NULA;
}
int perteneceAlArbol(tArbol a, tNodo n)
{
    int res=0;
    while (n!=a->raiz || n->padre!=a->raiz || n!=POS_NULA)
    {
        n=n->padre;
    }
    if (n==POS_NULA)
    {
       res=1;
    }
}
/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo r�tulo es E.
 Si NH es NULL, el nuevo nodo se agrega como primer hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, mientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/
extern tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e)
{
    tNodo=POS_NULA;
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else {
             if (perteneceAlArbol(a,np)==1)
             {
                exit(ARB_POSICION_INVALIDA);
             }
             else if (np==POS_NULA)
                  {
                     exit(ARB_POSICION_INVALIDA);
                  }
                  else if (nh->padre!=np)
                       {
                          exit(ARB_POSICION_INVALIDA);
                       }
                       else if (nh==POS_NULA)
                            {
                               nodo=(tnodo)malloc(sizeof(struct nodo));
                               nodo->elemento=e;
                               tLista* l;
                               nodo->hijos=crear_lista(l);
                               nodo->padre=np;
                               l_insertar(np->hijos,l_primera(np->hijos),nodo);
                            }
                            else {
                                   nodo=(tnodo)malloc(sizeof(struct nodo));
                                   nodo->elemento=e;
                                   tLista* l;
                                   nodo->hijos=crear_lista(l);
                                   nodo->padre=np;
                                   l_insertar(np->hijos,nh,nodo);
                                 }
         }
    return nodo;
}

/**
 Elimina el nodo N de A. El elemento almacenado en el �rbol es eliminado mediante la funci�n fEliminar parametrizada.
 Si N es la ra�z de A, y tiene un s�lo hijo, este pasa a ser la nueva ra�z del �rbol.
 Si N es la ra�z de A, y a su vez tiene m�s de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la ra�z de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posici�n que ocupa N en la lista de hijos de su padre.
**/
extern void a_eliminar(tArbol a, tNodo pa, void (*fEliminar)(tElemento))
{
    if (a==POS_NULA)
    {
        exit(ARB_POSICION_INVALIDA);
    }
    else if (a->raiz==pa)
         {
           if (l_primera(pa->hijos)==l_ultima(pa->hijos))
           {
               tNodo raizVieja=pa;
               tNodo raizNueva=l_recuperar(pa->hijos,l_primera(pa->hijos));
               raizNueva->padre=POS_NULA;
               a->raiz=raizNueva;
               fEliminar(raizVieja->elemento);
               l_destruir(raizVieja->hijos);
               free(raizVieja);
           }
         }
}

/**
 Destruye el �rbol A, elimininando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
extern void a_destruir(tArbol * a, void (*fEliminar)(tElemento));

/**
Recupera y retorna el elemento del nodo N.
*/
extern tElemento a_recuperar(tArbol a, tNodo n);

/**
Recupera y retorna el nodo correspondiente a la ra�z de A.
**/
extern tNodo a_raiz(tArbol a);

/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
extern tLista a_hijos(tArbol a, tNodo n);

/**
 Inicializa un nuevo �rbol en *SA.
 El nuevo �rbol en *SA se compone de los nodos del sub�rbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
extern void a_sub_arbol(tArbol a, tNodo n, tArbol * sa);