/**
 * TDA Lista.
 * @author Pablo Lencina, Adrian Flores
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define POS_NULA NULL
#define ELE_NULO NULL

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern �C�
{
#endif

/**
 Inicializa una lista vac�a.
 Una referencia a la lista creada es referenciada en *L.
**/
DLL_EXPORT extern void crear_lista(tLista * l);

/**
 Inserta el elemento E, en la posici�n P, en L.
 Con L = A,B,C,D y la posici�n P direccionando C, luego:
 L' = A,B,E,C,D
**/
DLL_EXPORT extern void l_insertar(tLista l, tPosicion p, tElemento e);

/**
 Elimina la celda P de L. El elemento almacenado en la posici�n P es eliminado mediante la funci�n fEliminar parametrizada.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
DLL_EXPORT extern void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento));

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la funci�n fEliminar parametrizada.
**/
DLL_EXPORT extern void l_destruir(tLista * l, void (*fEliminar)(tElemento));

 /**
 Recupera y retorna el elemento en la posici�n P.
 Si P es fin(L), finaliza indicando LST_POSICION_INVALIDA.
**/
DLL_EXPORT extern tElemento l_recuperar(tLista l, tPosicion p);

/**
 Recupera y retorna la primera posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
DLL_EXPORT extern tPosicion l_primera(tLista l);

/**
 Recupera y retorna la posici�n siguiente a P en L.
 Si P es fin(L), finaliza indicando LST_NO_EXISTE_SIGUIENTE.
**/
DLL_EXPORT extern tPosicion l_siguiente(tLista l, tPosicion p);

/**
 Recupera y retorna la posici�n anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
DLL_EXPORT extern tPosicion l_anterior(tLista l, tPosicion p);

 /**
 Recupera y retorna la �ltima posici�n de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
DLL_EXPORT extern tPosicion l_ultima(tLista l);

 /**
 Recupera y retorna la posici�n fin de L.
 Si L es vac�a, primera(L) = ultima(L) = fin(L).
**/
DLL_EXPORT extern tPosicion l_fin(tLista l);

/**
 Retorna la longitud actual de la lista.
**/
DLL_EXPORT extern int l_longitud(tLista l);

#ifdef __cplusplus
}
#endif
