/**
 * TDA Lista.
 * @author Pablo Lencina, Adrian Flores
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define LST_ELEMENTO_NULO           1
#define LST_NO_EXISTE_SIGUIENTE     2
#define LST_NO_EXISTE_ANTERIOR      3
#define LST_POSICION_INVALIDA       4
#define LST_ERROR_MEMORIA           5
#define POS_NULA NULL
#define ELE_NULO NULL

/**
 Inicializa una lista vacía.
 Una referencia a la lista creada es referenciada en *L.
**/
extern void crear_lista(tLista * l)
 {
     (*l)=malloc(sizeof(struct celda));
     if ((*l)!=NULL)
     {
        (*l)->elemento=NULL;
        (*l)->siguiente=NULL;
     }
     else
      exit(LST_ERROR_MEMORIA);
 }

/**
 Inserta el elemento E, en la posición P, en L.
 Con L = A,B,C,D y la posición P direccionando C, luego:
 L' = A,B,E,C,D
**/
extern void l_insertar(tLista l, tPosicion p, tElemento e)
{  
   struct celda *aInsertar=(struct celda*)malloc(sizeof(struct celda));
   if(aInsertar==NULL)
      {
        exit(LST_ERROR_MEMORIA);
      }
   aInsertar->elemento=e;
 aInsertar->siguiente =p->siguiente;
 p->siguiente=nuevo;
}

 /**
 Elimina el nodo que se encuentra en la posición P de L.
 El elemento almacenado en la posición P es eliminado mediante la función fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento))
 {
      if (p->siguiente==POS_NULA)
          {
             exit(LST_POSICION_INVALIDA);
          }
      else {
                  tPosicion pos=p->siguiente;//va a ser eliminado
                  fEliminar(pos->elemento);
       
                  
                  p->siguiente=p->siguiente->siguiente;
                  pos->siguiente=NULL;
                  pos->elemento=NULL;
                  free(pos);
               }
 }

 /**
 Recupera y retorna la primera posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_primera(tLista l)
 {    
     return l;
 }

 /**
 Recupera y retorna la última posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_ultima(tLista l)
 {
     tPosicion pos=l;
     if(pos->siguiente!=NULL)
          while (pos->siguiente->siguiente!=NULL) {
               pos=pos->siguiente;
           }
     return pos;
 }

 /**
 Recupera y retorna la posición anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
extern tPosicion l_anterior(tLista l, tPosicion p)
 {
     tPosicion pos=l;
     if (p==l)
         exit(LST_NO_EXISTE_ANTERIOR);
    
     while (pos!= NULL && pos->siguiente!=p){
         pos=pos->siguiente;
     }
     return pos;
 }

  /**
 Recupera y retorna la posición siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
extern tPosicion l_siguiente(tLista l, tPosicion p)
 {    
         if (p->siguiente==POS_NULA)
             exit(LST_NO_EXISTE_SIGUIENTE);
         else 
             return p->siguiente;   
 }

/**
 Recupera y retorna la posición fin de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_fin(tLista l)
{
   tPosicion pos=l;
   while (pos->siguiente!=POS_NULA)
   {
      pos=pos->siguiente;
   }
   return pos;
}

/**
 Recupera y retorna el elemento en la posición P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern tElemento l_recuperar(tLista l, tPosicion p)
 { 
        if (p->siguiente==NULL)
              exit(LST_POSICION_INVALIDA);
        else
             return p->siguiente->elemento;
   
 }

/**
 Destruye la lista L, elimininando cada una de sus posiciones. Los elementos almacenados en las posiciones son eliminados mediante la función fEliminar parametrizada.
**/
extern void l_destruir(tLista * l, void (*fEliminar)(tElemento))
{
    tPosicion pos=(*l);
    tPosicion posSiguiente;
    while (pos->siguiente!=NULL)
    {
       posSiguiente=po->siguiente;
       fEliminar(posSiguiente->elemento);
       pos->elemento=NULL;
       pos->siguiente=posSiguiente->siguiente;
       posSiguiente->siguiente=NULL;
       free(posSiguiente);
    }
       free(l);
}
