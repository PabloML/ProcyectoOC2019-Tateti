/**
 * TDA Lista.
 * @author Pablo Lencina, Adrian Flores
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define POS_NULA NULL
#define ELE_NULO NULL

/**
 Inicializa una lista vacía.
 Una referencia a la lista creada es referenciada en *L.
**/
 void crear_lista(tLista * l)
 {
     (*l)=malloc(sizeof(struct celda));
     if ((*l)==NULL)
           exit(LST_ERROR_MEMORIA);

        (*l)->elemento=NULL;
        (*l)->siguiente=NULL;


 }

/**
 Inserta el elemento E, en la posición P, en L.
 Con L = A,B,C,D y la posición P direccionando C, luego:
 L' = A,B,E,C,D
**/
 void l_insertar(tLista l, tPosicion p, tElemento e)
{
   struct celda *aInsertar=(struct celda*)malloc(sizeof(struct celda));

   if(aInsertar==NULL)
        exit(LST_ERROR_MEMORIA);

   aInsertar->elemento=e;
   aInsertar->siguiente =p->siguiente;
   p->siguiente=aInsertar;
}

 /**
 Elimina el nodo que se encuentra en la posición P de L.
 El elemento almacenado en la posición P es eliminado mediante la función fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
 void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento))
 {
      if (p->siguiente==NULL)
          {
             exit(LST_POSICION_INVALIDA);
          }

                  tPosicion pos=p->siguiente;//va a ser eliminado
                  fEliminar(pos->elemento);


                  p->siguiente=p->siguiente->siguiente;
                  pos->siguiente=NULL;
                  pos->elemento=NULL;
                  free(pos);
 }

 /**
 Recupera y retorna la primera posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
 tPosicion l_primera(tLista l)
 {
     return l;
 }

 /**
 Recupera y retorna la última posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
 tPosicion l_ultima(tLista l)
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
 tPosicion l_anterior(tLista l, tPosicion p)
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
 tPosicion l_siguiente(tLista l, tPosicion p)
 {
         if (p->siguiente==NULL)
             exit(LST_NO_EXISTE_SIGUIENTE);

             return p->siguiente;
 }

/**
 Recupera y retorna la posición fin de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
 tPosicion l_fin(tLista l)
{
   tPosicion pos=l;
   while (pos->siguiente!=NULL)
   {
      pos=pos->siguiente;
   }
   return pos;
}

/**
 Recupera y retorna el elemento en la posición P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
 tElemento l_recuperar(tLista l, tPosicion p)
 {
        if (p->siguiente==NULL)
              exit(LST_POSICION_INVALIDA);

             return p->siguiente->elemento;

 }

/**
 Destruye la lista L, elimininando cada una de sus posiciones. Los elementos almacenados en las posiciones son eliminados mediante la función fEliminar parametrizada.
**/
 void l_destruir(tLista * l, void (*fEliminar)(tElemento))
{
    tPosicion pos=(*l);
    tPosicion posSiguiente=pos->siguiente;
    while (pos!=POS_NULA && posSiguiente!=POS_NULA)
    {
       if (pos->elemento!=ELE_NULO)
       {
          fEliminar(pos->elemento);
       }
       posSiguiente=pos->siguiente;
       pos->siguiente=POS_NULA;
       pos->elemento=ELE_NULO;
       free(pos);
       pos=posSiguiente;
       posSiguiente=pos->siguiente;
    }
    if (pos!=POS_NULA)
       free(pos);
}
