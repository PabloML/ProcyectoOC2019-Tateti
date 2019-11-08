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
Inicializa un �rbol vac�o.
Una referencia al �rbol creado es referenciado en *A.
**/
extern void crear_arbol(tArbol * a)
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else {
            (*a)=(tArbol)malloc(sizeof(struct arbol));
             if ((*a)!=POS_NULA)
             {
                (*a)->raiz=POS_NULA;
             }
             else exit(ARB_ERROR_MEMORIA);
         }
}

/**
Crea la ra�z de A.
Si A no es vac�o, finaliza indicando ARB_OPERACION_INVALIDA.
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
         else {
                 a->raiz=(tNodo)malloc(sizeof(struct nodo));
                 if (a->raiz!=POS_NULA)
                 {
                     a->raiz->elemento=e;
                     tLista l;
                     crear_lista(&l);
                     a->raiz->hijos=l;
                     a->raiz->padre=POS_NULA;
                 }
                 else exit(ARB_ERROR_MEMORIA);
              }
}
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
tPosicion recuperarPosicion(tLista l,tNodo n)
{
    tPosicion p=l_primera(l);
    while (p!=l_ultima(l) && l_recuperar(l,p)!=n)
    {
        p=l_siguiente(l,p);
    }
    return p;
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
    tNodo nodo=POS_NULA;
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (perteneceAlArbol(a,np)==0)
            {
               exit(ARB_POSICION_INVALIDA);
            }
         else if (np==POS_NULA)
              {
                 exit(ARB_POSICION_INVALIDA);
              }
              else if (nh==POS_NULA)
                   {
                       nodo=(tNodo)malloc(sizeof(struct nodo));
                       if (nodo!=POS_NULA)
                       {
                           nodo->elemento=e;
                           tLista l;
                           crear_lista(&l);
                           nodo->hijos=l;
                           nodo->padre=np;
                           l_insertar(np->hijos,l_primera(np->hijos),nodo);
                        }
                        else exit(ARB_ERROR_MEMORIA);
                   }
                   else if (nh->padre!=np)
                        {
                            exit(ARB_POSICION_INVALIDA);
                        }
                        else {
                                nodo=(tNodo)malloc(sizeof(struct nodo));
                                if (nodo!=POS_NULA)
                                {
                                    nodo->elemento=e;
                                    tLista l;
                                    crear_lista(&l);
                                    nodo->hijos=l;
                                    nodo->padre=np;
                                    l_insertar(np->hijos,recuperarPosicion(np->hijos,nh),nodo);
                                }
                                else exit(ARB_ERROR_MEMORIA);
                              }
    return nodo;
}

/**
 Elimina el nodo N de A. El elemento almacenado en el �rbol es eliminado mediante la funci�n fEliminar parametrizada.
 Si N es la ra�z de A, y tiene un s�lo hijo, este pasa a ser la nueva ra�z del �rbol.
 Si N es la ra�z de A, y a su vez tiene m�s de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la ra�z de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posici�n que ocupa N en la lista de hijos de su padre.
**/
extern void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento))
{
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (a->raiz==n)
         {
           tPosicion p=l_primera(n->hijos);
           if (p->siguiente!=POS_NULA)
           {
               if (l_primera(n->hijos)==l_ultima(n->hijos))
               {
                   tNodo raizVieja=n;
                   tNodo raizNueva=l_recuperar(n->hijos,l_primera(raizVieja->hijos));
                   raizNueva->padre=POS_NULA;
                   a->raiz=raizNueva;
                   fEliminar(raizVieja->elemento);
                   l_destruir(&(raizVieja->hijos),fEliminar);
                   free(raizVieja);
               }
               else exit(ARB_OPERACION_INVALIDA);
           }
           else {
                   tNodo raizVieja=n;
                   a->raiz=POS_NULA;
                   fEliminar(&(raizVieja->elemento));
                   l_destruir(&(raizVieja->hijos),fEliminar);
                   free(raizVieja);
                }
         }
         else  if (perteneceAlArbol(a,n)==0)
               {
                 exit(ARB_POSICION_INVALIDA);
               }
               else {
                      tNodo nodoViejo=n;
                      if (l_primera(nodoViejo->hijos)!=l_fin(nodoViejo->hijos))
                      {
                          tNodo nodoNuevo=l_recuperar(nodoViejo->hijos,l_primera(nodoViejo->hijos));
                          nodoNuevo->padre=nodoViejo->padre;
                          tPosicion pos=recuperarPosicion(nodoViejo->padre->hijos,n);
                          l_insertar(nodoViejo->padre->hijos,pos,nodoNuevo);
                          fEliminar(nodoViejo->elemento);
                          l_eliminar(nodoViejo->hijos,l_primera(nodoViejo->hijos),fEliminar);
                          tPosicion p=l_primera(nodoViejo->hijos);
                          while (p!=l_fin(nodoViejo->hijos))
                          {
                             l_insertar(nodoNuevo->hijos,l_primera(nodoViejo->hijos),l_recuperar(nodoViejo->hijos,l_primera(nodoViejo->hijos)));
                             l_eliminar(nodoViejo->hijos,l_primera(nodoViejo->hijos),fEliminar);
                             p=l_primera(nodoViejo->hijos);
                          }
                      }
                      l_destruir(&(nodoViejo->hijos),fEliminar);
                      tPosicion position=recuperarPosicion(nodoViejo->padre->hijos,nodoViejo);
                      nodoViejo->padre=POS_NULA;
                      l_eliminar(nodoViejo->padre->hijos,position,fEliminar);
                      free(nodoViejo);
                   }
}

/**
 Destruye el �rbol A, elimininando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
extern void a_destruir(tArbol * a, void (*fEliminar)(tElemento))
{
    if (a!=POS_NULA)
    {
        tArbol arbol=(*a);
        tPosicion p=l_primera(arbol->raiz->hijos);
        while (p->siguiente!=POS_NULA)
        {
           a_eliminar(arbol,l_recuperar(arbol->raiz->hijos,p),fEliminar);
           p=l_primera(arbol->raiz->hijos);
        }
        fEliminar(arbol->raiz->elemento);
        l_destruir(&(arbol->raiz->hijos),fEliminar);
        free(arbol->raiz);
        free(arbol);
    }
}

/**
Recupera y retorna el elemento del nodo N.
*/
extern tElemento a_recuperar(tArbol a, tNodo n)
{
    tElemento e=n->elemento;
    if (a==POS_NULA)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (perteneceAlArbol(a,n)==0)
         {
            exit(ARB_POSICION_INVALIDA);
         }
    return e;
}

/**
Recupera y retorna el nodo correspondiente a la ra�z de A.
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
    tLista l=n->hijos;
    if (a==POS_NULA)
    {
       exit(ARB_ERROR_MEMORIA);
    }
    else if (perteneceAlArbol(a,n)==0)
         {
            exit(ARB_POSICION_INVALIDA);
         }
    return l;
}

/**
 Inicializa un nuevo �rbol en *SA.
 El nuevo �rbol en *SA se compone de los nodos del sub�rbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
extern void a_sub_arbol(tArbol a, tNodo n, tArbol * sa)
{
  if (a==POS_NULA)
   {
       exit(ARB_ERROR_MEMORIA);
   }
   else if (n==POS_NULA)
        {
            exit(ARB_POSICION_INVALIDA);
        }
        else if (perteneceAlArbol(a,n)==0)
             {
                 exit(ARB_POSICION_INVALIDA);
             }
             else
                 {
                    tArbol arbol=(*sa);
                    if (arbol==POS_NULA)
                    {
                        crear_arbol(sa);
                    }
                    tPosicion p=recuperarPosicion(n->padre->hijos,n);
                    n->padre=POS_NULA;
                    arbol->raiz=n;
                    tPosicion siguiente=p->siguiente;
                    p->siguiente=siguiente->siguiente;
                    siguiente->siguiente=POS_NULA;
                    siguiente->elemento=POS_NULA;
                    free(siguiente);
                 }
}
