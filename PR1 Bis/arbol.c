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

/**
Inicializa un árbol vacío.
Una referencia al árbol creado es referenciado en *A.
**/
extern void crear_arbol(tArbol * a)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    (*a)=(tArbol) malloc(sizeof(struct arbol));
    tArbol arbol=(struct arbol*) (*a);
    if (arbol!=POS_NULA)
    {
        arbol->raiz=POS_NULA;
    }
    else {
            exit(ARB_ERROR_MEMORIA);
         }
}

/**
Crea la raíz de A.
Si A no es vacío, finaliza indicando ARB_OPERACION_INVALIDA.
**/
extern void crear_raiz(tArbol a, tElemento e)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (a->raiz!=POS_NULA)
         {
             exit(ARB_OPERACION_INVALIDA);
         }
    a->raiz=(tNodo)malloc(sizeof(struct nodo));
    if (a->raiz!=POS_NULA)
    {
        a->raiz->elemento=e;
        a->raiz->padre=POS_NULA;
        tLista l;
        crear_lista(&l);
        a->raiz->hijos=l;
    }
    else {
            exit(ARB_ERROR_MEMORIA);
         }
}

/**
 * Devuelve 1 si n pertenece al arbol 0en caso contrario
 * @param a Es el arbol al quiero comprobar si pertenece n.
 * @param n Es el nodo que quiero saber si pertenece al arbol a.
 * @return 1 si n pertenece al arbol a y 0 en caso contrario.
 */
int perteneceAlArbol(tArbol a, tNodo n)
{
    int res=1;
    while (n!=(a->raiz) && (n->padre)!=a->raiz && n->padre!=POS_NULA && n!=POS_NULA)
    {
       n=n->padre;
    }
    if (n!=(a->raiz) && (n->padre)!=a->raiz && (n==POS_NULA || n->padre==POS_NULA))
    {
       res=0;
    }
    return res;
}

/**
 * Obtiene la posición en la lista l del nodo n.
 * @param l Es la lista donde quiero buscar al nodo n.
 * @param n Es el nodo que busco en la lista l.
 * @return La posición de la lista l donde se halla el nodo n.
 */
tPosicion recuperarPosicion(tLista l,tNodo n)
{
    tPosicion p=l_primera(l);
    while (p!=l_fin(l) && l_recuperar(l,p)!=n)
    {
        p=l_siguiente(l,p);
    }
    return p;
}

/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo rótulo es E.
 Si NH es NULL, el nuevo nodo se agrega como último hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, mientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/
extern tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e)
{
    tNodo n=POS_NULA;
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (nh==POS_NULA && perteneceAlArbol(a,np)==1)
         {
             n=(tNodo)malloc(sizeof(struct nodo));
             if (n!=POS_NULA)
             {
                 n->elemento=e;
                 n->padre=np;
                 tLista l;
                 crear_lista(&l);
                 n->hijos=l;
                 l_insertar(np->hijos,l_ultima(np->hijos),n);
             }
             else {
                     exit(ARB_ERROR_MEMORIA);
                  }
         }
         else if (np==POS_NULA || nh==POS_NULA || nh->padre!=np || perteneceAlArbol(a,np)==0)
              {
                  exit(ARB_POSICION_INVALIDA);
              }
              else {
                      n=(tNodo)malloc(sizeof(struct nodo));
                      if (n!=POS_NULA)
                      {
                          n->elemento=e;
                          n->padre=np;
                          tLista l;
                          crear_lista(&l);
                          n->hijos=l;
                          l_insertar(np->hijos,recuperarPosicion(np->hijos,nh),n);
                      }
                      else {
                             exit(ARB_ERROR_MEMORIA);
                           }
                   }
         return n;
}

/**
 * Falso eliminar del elemento para sacar los nodos de la listas de hijos del arbol sin que se elimine el elemento.
 * @param e Elemento que no quiero eliminar.
 */
void falsoEliminar(tElemento e)
{
}

/**
 Elimina el nodo N de A.
 El elemento almacenado en el árbol es eliminado mediante la función fEliminar parametrizada.
 Si N es la raíz de A, y tiene un sólo hijo, este pasa a ser la nueva raíz del árbol.
 Si N es la raíz de A, y a su vez tiene más de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la raíz de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posición que ocupa N en la lista de hijos de su padre.
**/
extern void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento))
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (n==POS_NULA || perteneceAlArbol(a,n)==0)
         {
             exit(ARB_POSICION_INVALIDA);
         }
         else if (n==a->raiz && l_primera(n->hijos)!=l_fin(n->hijos) && l_primera(n->hijos)==l_ultima(n->hijos))
              {
                  tNodo nodo=l_recuperar(n->hijos,l_primera(n->hijos));
                  nodo->padre=POS_NULA;
                  a->raiz=nodo;
                  l_destruir(&(n->hijos),&falsoEliminar);
              }
              else if (n==a->raiz && l_primera(n->hijos)==l_fin(n->hijos))
                   {
                       a->raiz=POS_NULA;
                   }
                   else{
                           tPosicion p=recuperarPosicion(n->padre->hijos,n);
                           l_ultima(n->hijos);
                           if (n==a->raiz && l_primera(n->hijos)!=l_ultima(n->hijos))
                           {
                               exit(ARB_OPERACION_INVALIDA);
                           }
                           else if (l_primera(n->hijos)!=l_ultima(n->hijos))
                                {
                                    tNodo nodo=l_recuperar(n->hijos,l_primera(n->hijos));
                                    nodo->padre=n->padre;
                                    l_eliminar(n->hijos,l_primera(n->hijos),falsoEliminar);
                                    tPosicion pos=l_primera(n->hijos);
                                    while (pos!=l_fin(n->hijos))
                                    {
                                        tNodo primera=l_recuperar(n->hijos,l_primera(n->hijos));
                                        primera->padre=nodo;
                                        l_insertar(nodo->hijos,l_primera(nodo->hijos),primera);
                                        l_eliminar(n->hijos,l_primera(n->hijos),&falsoEliminar);
                                    }
                                    l_insertar(nodo->padre->hijos,p,nodo);
                                }
                                else if (l_primera(n->hijos)!=l_fin(n->hijos))
                                     {
                                        tNodo nodo=l_recuperar(n->hijos,l_primera(n->hijos));
                                        nodo->padre=n->padre;
                                        n->padre->hijos=nodo->hijos;
                                     }
                          l_eliminar(n->padre->hijos,p,&falsoEliminar);
                          n->padre=POS_NULA;
                       }

    fEliminar(n->elemento);
    l_destruir(&(n->hijos),&falsoEliminar);
    free(n);
}

/**
 * Destruye arbol recursisavemente
 * @param a El arbol que deseo destruir.
 * @param n al cual ingreso recursivamente.
*/
void destruirAux(tArbol a,tNodo n ,void (*fEliminar)(tElemento))
{
    tPosicion pos=l_primera(n->hijos);
    while(pos !=l_fin(n->hijos)){
        destruirAux(a,l_recuperar(n->hijos,pos),fEliminar);
    }
    a_eliminar(a,n,fEliminar);
}

/**
 Destruye el árbol A, eliminando cada uno de sus nodos.
 Los elementos almacenados en el árbol son eliminados mediante la función fEliminar parametrizada.
**/
extern void a_destruir(tArbol * a, void (*fEliminar)(tElemento))
{
    tArbol arbol=(*a);
    if (a!=POS_NULA)
    {
       destruirAux(arbol,arbol->raiz,fEliminar);
       free(arbol->raiz);
       free(arbol);
    }
}

/**
Recupera y retorna el elemento del nodo N.
*/
extern tElemento a_recuperar(tArbol a, tNodo n)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (n==POS_NULA || perteneceAlArbol(a,n)==0)
         {
             exit(ARB_POSICION_INVALIDA);
         }
    return n->elemento;
}

/**
Recupera y retorna el nodo correspondiente a la raíz de A.
**/
extern tNodo a_raiz(tArbol a)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    return a->raiz;
}

/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
extern tLista a_hijos(tArbol a, tNodo n)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (n==POS_NULA || perteneceAlArbol(a,n)==0)
         {
             exit(ARB_POSICION_INVALIDA);
         }
    return n->hijos;
}

/**
 Inicializa un nuevo árbol en *SA.
 El nuevo árbol en *SA se compone de los nodos del subárbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
extern void a_sub_arbol(tArbol a, tNodo n, tArbol * sa)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (n==POS_NULA || perteneceAlArbol(a,n)==0)
         {

             exit(ARB_POSICION_INVALIDA);
         }
    tLista listaDeHermanos ;
    tPosicion pos,fin;
    crear_arbol(sa);
    crear_raiz(*sa,n->elemento);
    (*sa)->raiz->hijos=n->hijos;
     if(n!=a->raiz)
     {
       listaDeHermanos=n->padre->hijos;
       pos=l_primera(listaDeHermanos);
       fin=l_fin(listaDeHermanos);
       while(pos!=fin && l_recuperar(listaDeHermanos,pos)!=n)
       {
           pos=l_siguiente(listaDeHermanos,pos);
       }
       l_eliminar(listaDeHermanos,pos,falsoEliminar);
       n->padre=POS_NULA;
    }
}
