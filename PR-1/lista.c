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
 Inicializa una lista vac�a.
 Una referencia a la lista creada es referenciada en *L.
**/
extern void crear_lista(tLista * l)
 {
     (*l)=(tLista)malloc(sizeof(struct celda));
     if ((*l)!=POS_NULA)
     {
        (*l)->elemento=ELE_NULO;
        (*l)->siguiente=POS_NULA;
     }
     else exit(LST_ERROR_MEMORIA);
 }

/**
 Inserta el elemento E, en la posici�n P, en L.
 Con L = A,B,C,D y la posici�n P direccionando C, luego:
 L' = A,B,E,C,D
**/
extern void l_insertar(tLista l, tPosicion p, tElemento e)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    else if (l->siguiente==POS_NULA)
         {
            l->siguiente=(tPosicion)malloc(sizeof(struct celda));
            if (l->siguiente!=POS_NULA)
            {
                l->siguiente->elemento=e;
                l->siguiente->siguiente=POS_NULA;
            }
            else exit(LST_ERROR_MEMORIA);
         }
         else if (p==POS_NULA)
              {
                 exit(LST_POSICION_INVALIDA);
              }
              else if (l==p)
                   {
                      tPosicion position= (tPosicion)malloc(sizeof(struct celda));
                      if (position!=POS_NULA)
                      {
                         position->elemento=e;
                         position->siguiente=((tPosicion)l)->siguiente;
                         l->siguiente=position;
                      }
                      else exit(LST_ERROR_MEMORIA);
                   }
                   else
                        {
                           tPosicion position= (tPosicion)malloc(sizeof(struct celda));
                           if (position!=POS_NULA)
                           {
                               position->elemento=e;
                               tPosicion pos=p->siguiente;
                               p->siguiente=position;
                               position->siguiente=pos;
                           }
                           else exit(LST_ERROR_MEMORIA);
                        }
}

 /**
 Elimina el nodo que se encuentra en la posici�n P de L.
 El elemento almacenado en la posici�n P es eliminado mediante la funci�n fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento))
 {
     if (l==POS_NULA)
     {
         exit(LST_ERROR_MEMORIA);
     }
     else if (p==POS_NULA)
           {
              exit(LST_POSICION_INVALIDA);
           }
     else if (p->siguiente==POS_NULA)
          {
             exit(LST_POSICION_INVALIDA);
          }
          else {
                  tPosicion pos=p->siguiente;
                  fEliminar(pos->elemento);
                  tPosicion posSiguiente=pos->siguiente;
                  p->siguiente=posSiguiente;
                  pos->siguiente=POS_NULA;
                  pos->elemento=ELE_NULO;
                  free(pos);
               }
 }

 /**
 Recupera y retorna la primera posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_primera(tLista l)
 {
     tPosicion pos=(struct celda*)l;
     return pos;
 }

 /**
 Recupera y retorna la �ltima posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_ultima(tLista l)
 {
     tPosicion pos=POS_NULA;
     if (l!=POS_NULA)
     {
        if (l->siguiente==POS_NULA)
        {
            pos=(struct celda*)l;
        }
        else {
                pos=(struct celda*)l;
                while (pos->siguiente->siguiente!=POS_NULA)
                {
                  pos=pos->siguiente;
                }
             }
     }
     return pos;
 }

 /**
 Recupera y retorna la posici�n anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
extern tPosicion l_anterior(tLista l, tPosicion p)
 {
     tPosicion pos=POS_NULA;
     if (p==POS_NULA)
     {
         exit(LST_POSICION_INVALIDA);
     }
     else if (l!=POS_NULA)
          {
             if (l->siguiente==POS_NULA)
             {
                 exit(LST_NO_EXISTE_ANTERIOR);
             }
             else {
                    pos=l;
                    while (pos->siguiente!=p)
                    {
                      pos=pos->siguiente;
                    }
                  }
          }
     return pos;
 }

  /**
 Recupera y retorna la posici�n siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
extern tPosicion l_siguiente(tLista l, tPosicion p)
 {
     tPosicion pos=POS_NULA;
     if (p==POS_NULA)
     {
         exit(LST_POSICION_INVALIDA);
     }
     if (l!=POS_NULA)
     {
         if (p->siguiente==POS_NULA)
         {
             exit(LST_NO_EXISTE_SIGUIENTE);
         }
         else pos=p->siguiente;
     }

    return pos;
 }

/**
 Recupera y retorna la posici�n fin de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
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
 Recupera y retorna el elemento en la posici�n P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern tElemento l_recuperar(tLista l, tPosicion p)
 {
     tElemento elem=ELE_NULO;
     if (l==POS_NULA)
     {
         exit(LST_ERROR_MEMORIA);
     }
     else if (p==POS_NULA)
          {
             exit(LST_POSICION_INVALIDA);
          }
          else if (p->siguiente==POS_NULA)
               {
                   exit(LST_POSICION_INVALIDA);
               }
               else elem=p->siguiente->elemento;
    if (elem==ELE_NULO)
        exit(LST_ELEMENTO_NULO);
    return elem;
 }

/**
 Destruye la lista L, elimininando cada una de sus posiciones. Los elementos almacenados en las posiciones son eliminados mediante la funci�n fEliminar parametrizada.
**/
extern void l_destruir(tLista * l, void (*fEliminar)(tElemento))
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
