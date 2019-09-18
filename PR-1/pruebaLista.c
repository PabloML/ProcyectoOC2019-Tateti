#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define POS_NULA NULL
int pruebaLista();
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
    pruebaLista();
    /**
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
    return 0;*/
}
int pruebaLista(){
       
            tLista l;
            crear_lista(&l);
        
        printf("Ingrese los numeros que quiera : \n");

        tEntero e=(tEntero)malloc(sizeof(struct entero));
        tPosicion p1=l_primera(l);
        int valor;
        scanf("%i",&valor);
        while(valor!=0){
            e->entero=valor;
            l_insertar(l,p1,e);
            printf("el ingresado : %i\n",((tEntero)l_recuperar(l,p1))->entero);
            p1=l_siguiente(l,p1);
            scanf("%i",&valor);
             e=(tEntero)malloc(sizeof(struct entero));
        }
    
        tPosicion pr=l_primera(l);
    
        while(pr!=l_fin(l)){
            printf("Elem : %i\n",((tEntero)l_recuperar(l,pr))->entero);
            pr=l_siguiente(l,pr);
            if(pr==l_ultima(l))
                pr=l_fin(l);

        }
        return 1;
    }
