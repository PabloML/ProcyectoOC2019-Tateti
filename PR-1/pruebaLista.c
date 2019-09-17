#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define POS_NULA NULL

typedef struct entero
{
    int entero;
}*tEntero;

/**
 *Elimina el elemento pasado por parametro.
 * @param e Elemento a eliminar.
 */
void eliminarElemento (tElemento e)
{
    ((tEntero)e)->entero=0;
    free(e);
}

int main()
{
    tLista l;
    crear_lista(&l);
    tEntero e=(tEntero)malloc(sizeof(struct entero));
    tPosicion p=l_primera(l);
    e->entero=1;
    l_insertar(l,p,e);
    e=(tEntero)malloc(sizeof(struct entero));
    e->entero=2;
    p=l_siguiente(l,l_primera(l));
    l_insertar(l,p,e);
    e=(tEntero)malloc(sizeof(struct entero));
    e->entero=3;
    p=l_anterior(l,l_ultima(l));
    l_insertar(l,p,e);
    e=(tEntero)malloc(sizeof(struct entero));
    e->entero=4;
    p=l_anterior(l,l_fin(l));
    l_insertar(l,p,e);
    printf("La primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
    printf("La siguiente a la primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_siguiente(l,l_primera(l))))->entero);
    printf("La ultima de la lista es: %i \n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
    printf("La anterior a la ultima de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_ultima(l))))->entero);
    p=l_primera(l);
    l_eliminar(l,p,&eliminarElemento);
    printf("\nElimino la primera de la lista.");
    printf("\nLa primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
    printf("La ultima de la lista es: %i \n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
    printf("La anterior a la ultima de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_ultima(l))))->entero);
    p=l_siguiente(l,l_primera(l));
    l_eliminar(l,p,&eliminarElemento);
    printf("\nElimino la segunda de la lista.");
    printf("\nLa primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
    printf("La ultima de la lista es: %i \n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
    l_destruir(&l,&eliminarElemento);
    printf("\nDestruyo la lista.");
    if (l==POS_NULA)
        printf("\nLa lista fue destruida.\n");
    return 0;
}
