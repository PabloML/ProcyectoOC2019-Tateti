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
int hijos_cant(tLista l) {
    int i=0;
    tPosicion pos = l->siguiente;
    while(pos!=NULL) {
        i++;
        pos=pos->siguiente;
    }
    return i;
}
void eliminar_nodo(void* e) {   }
void destruirAux(tArbol a,tNodo n ,void (*fEliminar)(tElemento));
/**
Inicializa un �rbol vac�o.
Una referencia al �rbol creado es referenciado en *A.
**/
extern void crear_arbol(tArbol * a)
{

            (*a)=(struct arbol*)malloc(sizeof(struct arbol));
             if ((*a)==NULL)
                 exit(ARB_ERROR_MEMORIA);

            (*a)->raiz=NULL;


}

/**
Crea la ra�z de A.
Si A no es vac�o, finaliza indicando ARB_OPERACION_INVALIDA.
**/
 void crear_raiz(tArbol a, tElemento e)
{

     if (a->raiz!=NULL)
         {
             exit(ARB_OPERACION_INVALIDA);
         }
        tNodo futuraRaiz=(tNodo)malloc(sizeof(struct nodo));

                 if (futuraRaiz==NULL || futuraRaiz==0)
                        exit(ARB_ERROR_MEMORIA);
                 else
                    {
                     crear_lista(&(futuraRaiz->hijos));
                     futuraRaiz->padre=NULL;
                     futuraRaiz->elemento=e;
                      a->raiz=futuraRaiz;
                    }

}

/**
 Inserta y retorna un nuevo nodo en A.
 El nuevo nodo se agrega en A como hijo de NP, hermano izquierdo de NH, y cuyo r�tulo es E.
 Si NH es NULL, el nuevo nodo se agrega como primer hijo de NP.
 Si NH no corresponde a un nodo hijo de NP, finaliza indicando ARB_POSICION_INVALIDA.
 NP direcciona al nodo padre, mientras NH al nodo hermano derecho del nuevo nodo a insertar.
**/
 tNodo a_insertar(tArbol a, tNodo np, tNodo nh, tElemento e)
{

        if (np==NULL)
                exit(ARB_POSICION_INVALIDA);

        tLista hermanosNUEVO=np->hijos;
        tNodo nuevoHijo=(tNodo)malloc(sizeof(struct nodo));
        if(nuevoHijo==NULL || nuevoHijo==0)
                exit(ARB_ERROR_MEMORIA);
        crear_lista(&(nuevoHijo->hijos));
        nuevoHijo->elemento=e;
        nuevoHijo->padre=np;
        tPosicion posHermanosNUEVO=l_primera(hermanosNUEVO);
        tPosicion finHermanosNUEVO=l_fin(hermanosNUEVO);
        if(nh!=NULL){
                while(posHermanosNUEVO!=finHermanosNUEVO && l_recuperar(hermanosNUEVO,posHermanosNUEVO))
                        posHermanosNUEVO=l_siguiente(hermanosNUEVO,posHermanosNUEVO);
                if(posHermanosNUEVO==finHermanosNUEVO)
                           exit(ARB_POSICION_INVALIDA);
                }
                else{
                    posHermanosNUEVO=l_fin(hermanosNUEVO);

                }
                l_insertar(hermanosNUEVO,posHermanosNUEVO,nuevoHijo);
             return nuevoHijo;

}

/**
 Elimina el nodo N de A. El elemento almacenado en el �rbol es eliminado mediante la funci�n fEliminar parametrizada.
 Si N es la ra�z de A, y tiene un s�lo hijo, este pasa a ser la nueva ra�z del �rbol.
 Si N es la ra�z de A, y a su vez tiene m�s de un hijo, finaliza retornando ARB_OPERACION_INVALIDA.
 Si N no es la ra�z de A y tiene hijos, estos pasan a ser hijos del padre de N, en el mismo orden y a partir de la posici�n que ocupa N en la lista de hijos de su padre.
**/
 void a_eliminar(tArbol a, tNodo n, void (*fEliminar)(tElemento))
{
    tLista hijosN=n->hijos;
    if (a==NULL)
    {
        exit(ARB_ERROR_MEMORIA);
    }
    else if (a->raiz==n)
         {
            int cantDeN=hijos_cant(hijosN);
            if(cantDeN==1){
                a->raiz=(tNodo)l_recuperar(hijosN,l_primera(hijosN));
                a->raiz->padre=NULL;
            }
            else
                if(cantDeN>1)
                    exit(ARB_OPERACION_INVALIDA);
         }
         else
           {
                  tNodo padreN=n->padre;
                  tLista hermanosN=padreN->hijos;
                  tPosicion posHermanosN=l_primera(hermanosN);
                  tPosicion finHermanosN=l_fin(hermanosN);
                  tPosicion posHijosN=l_primera(hijosN);
                  tPosicion finHijosN=l_fin(hijosN);
                  while(posHermanosN!=finHermanosN && l_recuperar(hermanosN,posHermanosN)!=n)
                      posHermanosN=l_siguiente(hermanosN,posHermanosN);
                  if(posHermanosN == finHermanosN)
                      exit(ARB_POSICION_INVALIDA);
                   while(posHijosN!=finHijosN){
                      tNodo nuevoHijoN=l_recuperar(hijosN,posHijosN);
                      nuevoHijoN->padre=padreN;
                      l_insertar(hermanosN,posHermanosN,nuevoHijoN);
                      posHijosN=l_siguiente(hijosN,posHijosN);
                      posHermanosN=l_siguiente(hermanosN,posHermanosN);
                   }
                   l_eliminar(hermanosN,posHermanosN,eliminar_nodo);
            }
    fEliminar(n->elemento);
    l_destruir(&hijosN,eliminar_nodo);
    n->hijos=NULL;
    n->padre=NULL;
    n->elemento=NULL;
    free(n);
    n=NULL;
}

/**
 Destruye el �rbol A, elimininando cada uno de sus nodos.
 Los elementos almacenados en el �rbol son eliminados mediante la funci�n fEliminar parametrizada.
**/
 void a_destruir(tArbol * a, void (*fEliminar)(tElemento))
{

       destruirAux(*a,(*a)->raiz,fEliminar);
        (*a)->raiz=NULL;
        free(*a);
        (*a)=NULL;
}
/**
 Destruye arbol recursisavemente
*/
void destruirAux(tArbol a,tNodo n ,void (*fEliminar)(tElemento)){
    tPosicion pos=l_primera(n->hijos);
    while(pos !=l_fin(n->hijos)){
        destruirAux(a,l_recuperar(n->hijos,pos),fEliminar);
    }
    a_eliminar(a,n,fEliminar);
}


/**
Recupera y retorna el elemento del nodo N.
*/
 tElemento a_recuperar(tArbol a, tNodo n)
{
    if (n==NULL)
        exit(ARB_ERROR_MEMORIA);
     return n->elemento;
}

/**
Recupera y retorna el nodo correspondiente a la ra�z de A.
**/
extern tNodo a_raiz(tArbol a)
{
    return a->raiz;
}

/**
 Obtiene y retorna una lista con los nodos hijos de N en A.
**/
 tLista a_hijos(tArbol a, tNodo n)
{
        return n->hijos;
}

/**
 Inicializa un nuevo �rbol en *SA.
 El nuevo �rbol en *SA se compone de los nodos del sub�rbol de A a partir de N.
 El subarbol de A a partir de N debe ser eliminado de A.
**/
 void a_sub_arbol(tArbol a, tNodo n, tArbol * sa)
{
                    tLista listaDeHermanos ;
                    tPosicion pos,fin;

                    crear_arbol(sa);
                    crear_raiz(*sa,n->elemento);
                    (*sa)->raiz->hijos=n->hijos;

                    if(n!=a->raiz){
                      listaDeHermanos=n->padre->hijos;
                      pos=l_primera(listaDeHermanos);
                      fin=l_fin(listaDeHermanos);
                      while(pos!=fin && l_recuperar(listaDeHermanos,pos)!=n){
                          pos=l_siguiente(listaDeHermanos,pos);
                      }
                      if(pos!=fin){
                            exit(ARB_POSICION_INVALIDA);
                      }
                      else
                          l_eliminar(listaDeHermanos,pos,eliminar_nodo);
                          n->padre=NULL;


                   }

}
