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
extern void crear_lista(tLista * l)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    (*l)=(tLista)malloc(sizeof(struct celda));
    tPosicion pos=(struct celda*)(*l);
    if (pos!=POS_NULA)
    {
        pos->elemento=POS_NULA;
        pos->siguiente=POS_NULA;
    }
    else {
            exit(LST_ERROR_MEMORIA);
         }

}

/**
 Inserta el elemento E, en la posición P, en L.
 Con L = A,B,C,D y la posición P direccionando C, luego:
 L' = A,B,E,C,D
**/
extern void l_insertar(tLista l, tPosicion p, tElemento e)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    else if (p==POS_NULA)
         {
             exit(LST_POSICION_INVALIDA);
         }
         else if (l->siguiente==POS_NULA && p==l)
              {
                  l->siguiente=(tPosicion)malloc(sizeof(struct celda));
                  if (l->siguiente!=POS_NULA)
                  {
                      l->siguiente->elemento=e;
                      l->siguiente->siguiente=POS_NULA;
                  }
                  else {
                          exit(LST_ERROR_MEMORIA);
                       }
              }
              else if (l->siguiente!=POS_NULA)
                   {
                      tPosicion pos=(tPosicion)malloc(sizeof(struct celda));
                      if (pos!=POS_NULA)
                      {
                          pos->elemento=e;
                          pos->siguiente=p->siguiente;
                          p->siguiente=pos;
                      }
                      else {
                              exit(LST_ERROR_MEMORIA);
                           }
                   }
                   else {
                           exit(LST_POSICION_INVALIDA);
                        }
}

/**
 Elimina la celda P de L. El elemento almacenado en la posición P es eliminado mediante la función fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento))
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    else if (p==POS_NULA || p->siguiente==POS_NULA || l->siguiente==POS_NULA)
         {
             exit(LST_POSICION_INVALIDA);
         }
         else {
                 tPosicion pos= p->siguiente;
                 fEliminar(pos->elemento);
                 p->siguiente=pos->siguiente;
                 pos->siguiente=POS_NULA;
                 free(pos);
              }
}

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la función fEliminar parametrizada.
**/
extern void l_destruir(tLista * l, void (*fEliminar)(tElemento))
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    tPosicion p=(struct celda*)(*l);
    while (p!=POS_NULA && p->siguiente!=POS_NULA)
    {
        tPosicion pos= p->siguiente;
        fEliminar(pos->elemento);
        p->siguiente=pos->siguiente;
        pos->siguiente=POS_NULA;
        free(pos);
    }
    if (p!=POS_NULA)
    {
       free(p);
    }
}

 /**
 Recupera y retorna el elemento en la posición P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
extern tElemento l_recuperar(tLista l, tPosicion p)
{
    tElemento e=ELE_NULO;
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    else if (p==POS_NULA || p->siguiente==POS_NULA || l->siguiente==POS_NULA)
         {
             exit(LST_POSICION_INVALIDA);
         }
         else {
                 e=p->siguiente->elemento;
              }
    if (e==ELE_NULO)
       exit(LST_ELEMENTO_NULO);
    return e;
}

/**
 Recupera y retorna la primera posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_primera(tLista l)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    return l;
}

/**
 Recupera y retorna la posición siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
extern tPosicion l_siguiente(tLista l, tPosicion p)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    else if (p==POS_NULA || (p!=l && l->siguiente==POS_NULA))
         {
             exit(LST_POSICION_INVALIDA);
         }
         else if (p->siguiente==POS_NULA)
              {
                  exit(LST_NO_EXISTE_SIGUIENTE);
              }
    return p->siguiente;
}

/**
 Recupera y retorna la posición anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
extern tPosicion l_anterior(tLista l, tPosicion p)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    else if (p==POS_NULA)
         {
             exit(LST_POSICION_INVALIDA);
         }
         else if (p==l)
              {
                 exit(LST_NO_EXISTE_ANTERIOR);
              }
    tPosicion pos=l;
    while (pos!=POS_NULA && pos->siguiente!=p)
    {
       pos=pos->siguiente;
    }
    if (pos==POS_NULA)
    {
       exit(LST_POSICION_INVALIDA);
    }
    return pos;
}

 /**
 Recupera y retorna la última posición de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_ultima(tLista l)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    tPosicion p=l;
    while (p->siguiente!=POS_NULA && p->siguiente->siguiente!=POS_NULA)
    {
      p=p->siguiente;
    }
    return p;
}

 /**
 Recupera y retorna la posición fin de L.
 Si L es vacía, primera(L) = ultima(L) = fin(L).
**/
extern tPosicion l_fin(tLista l)
{
    if (l==POS_NULA)
    {
        exit(LST_ERROR_MEMORIA);
    }
    tPosicion p=l;
    while (p->siguiente!=POS_NULA)
    {
      p=p->siguiente;
    }
    return p;
}
