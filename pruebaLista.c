#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "arbol.h"
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
    free((tEntero)e);
}

int main()
{
    /*tLista l;
    crear_lista(&l);
    printf("El elemento del primer elemento de la lista es %p\n", l->elemento);
    printf("El segundo elemento de la lista es %p\n", l->siguiente);
    printf("La ultima posicion es: %p\n",l_ultima(l));
    printf("La posicion fin es: %p\n\n",l_fin(l));
    tEntero e=(tEntero) malloc(sizeof(struct entero));
    if (e!=POS_NULA)
    {
        e->entero=1;
        l_insertar(l,l,e);
        printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l))->entero);
        printf("El ultimo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
        printf("El ultimo elemento es: %i\n\n",((tEntero)l_recuperar(l,l_anterior(l,l_fin(l))))->entero);
        tEntero en=(tEntero) malloc(sizeof(struct entero));
        if (en!=POS_NULA)
        {
           en->entero=2;
           l_insertar(l,l,en);
           printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
           printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_primera(l)))))->entero);
           printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_primera(l))))->entero);
           printf("El ultimo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
           printf("El ultimo elemento es: %i\n\n",((tEntero)l_recuperar(l,l_anterior(l,l_fin(l))))->entero);
           tEntero ent=(tEntero) malloc(sizeof(struct entero));
            if (ent!=POS_NULA)
            {
                ent->entero=3;
                l_insertar(l,l->siguiente,ent);
                printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
                printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_primera(l)))))->entero);
                printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_primera(l))))->entero);
                printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_siguiente(l,l_primera(l))))))->entero);
                printf("El tercer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_siguiente(l,l_primera(l)))))->entero);
                printf("El ultimo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
                printf("El ultimo elemento es: %i\n\n",((tEntero)l_recuperar(l,l_anterior(l,l_fin(l))))->entero);
                tEntero ente=(tEntero) malloc(sizeof(struct entero));
                if (ente!=POS_NULA)
                {
                    ente->entero=4;
                    l_insertar(l,l->siguiente->siguiente->siguiente,ente);
                    printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
                    printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_primera(l)))))->entero);
                    printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_primera(l))))->entero);
                    printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_siguiente(l,l_primera(l))))))->entero);
                    printf("El tercer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_siguiente(l,l_primera(l)))))->entero);
                    printf("El tercer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_siguiente(l,l_siguiente(l,l_primera(l)))))))->entero);
                    printf("El cuarto elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_siguiente(l,l_siguiente(l,l_primera(l))))))->entero);
                    printf("El ultimo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
                    printf("El ultimo elemento es: %i\n\n",((tEntero)l_recuperar(l,l_anterior(l,l_fin(l))))->entero);
                    l_eliminar(l,l->siguiente->siguiente,&eliminarElemento);
                    printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
                    printf("El primer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_primera(l)))))->entero);
                    printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_primera(l))))->entero);
                    printf("El segundo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_siguiente(l,l_siguiente(l,l_primera(l))))))->entero);
                    printf("El tercer elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_siguiente(l,l_siguiente(l,l_primera(l)))))->entero);
                    printf("El ultimo elemento de la lista es: %i\n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
                    printf("El ultimo elemento es: %i\n\n",((tEntero)l_recuperar(l,l_anterior(l,l_fin(l))))->entero);
                    l_destruir(&l,&eliminarElemento);
                }
                else exit(LST_ERROR_MEMORIA);
            }
            else exit(LST_ERROR_MEMORIA);
        }
        else exit(LST_ERROR_MEMORIA);
    }
    else exit(LST_ERROR_MEMORIA);*/
    tArbol a;
    crear_arbol(&a);
    printf("la raíz del arbol es %p\n\n", a->raiz);
    tEntero e=(tEntero) malloc(sizeof(struct entero));
    if (e!=POS_NULA)
    {
        e->entero=1;
        crear_raiz(a,e);
        printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
        printf("El padre de la raiz es %p\n", a->raiz->padre);
        printf("La primera posicion de la lista de hijos de la raiz es %p\n\n", l_primera(a->raiz->hijos));
        tEntero en=(tEntero) malloc(sizeof(struct entero));
        if (en!=POS_NULA)
        {
            en->entero=2;
            a_insertar(a, a->raiz, POS_NULA, en);
            printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
            tNodo n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
            printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
            printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
            tEntero ent=(tEntero) malloc(sizeof(struct entero));
            if (ent!=POS_NULA)
            {
                ent->entero=3;
                a_insertar(a, a->raiz, POS_NULA, ent);
                printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
                printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
                printf("El padre del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
                tNodo no=l_recuperar(a->raiz->hijos,l_siguiente(a->raiz->hijos,l_primera(a->raiz->hijos)));
                printf("El segundo hijo de la raiz es %i\n",((tEntero)no->elemento)->entero);
                printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)no->elemento)->entero,((tEntero)no->padre->elemento)->entero );
                tEntero ente=(tEntero) malloc(sizeof(struct entero));
                if (ente!=POS_NULA)
                {
                    ente->entero=4;
                    a_insertar(a,n,l_primera(n->hijos)->elemento,ente);
                    printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                    n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
                    printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
                    printf("El padre del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
                    no=l_recuperar(a->raiz->hijos,l_siguiente(a->raiz->hijos,l_primera(a->raiz->hijos)));
                    printf("El segundo hijo de la raiz es %i\n",((tEntero)no->elemento)->entero);
                    printf("El padre del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)no->padre->elemento)->entero );
                    tNodo nod=l_recuperar(n->hijos,l_primera(n->hijos));
                    printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nod->elemento)->entero);
                    printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)nod->elemento)->entero,((tEntero)nod->padre->elemento)->entero );
                    tEntero enter=(tEntero) malloc(sizeof(struct entero));
                    if (enter!=POS_NULA)
                    {
                        enter->entero=5;
                        a_insertar(a,n,l_fin(n->hijos)->elemento,enter);
                        printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                        n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
                        printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
                        printf("El padre del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
                        no=l_recuperar(a->raiz->hijos,l_siguiente(a->raiz->hijos,l_primera(a->raiz->hijos)));
                        printf("El segundo hijo de la raiz es %i\n",((tEntero)no->elemento)->entero);
                        printf("El padre del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)no->padre->elemento)->entero );
                        nod=l_recuperar(n->hijos,l_primera(n->hijos));
                        printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nod->elemento)->entero);
                        printf("El padre del nodo con elemento %i es %i\n",((tEntero)nod->elemento)->entero,((tEntero)nod->padre->elemento)->entero );
                        tNodo nodo=l_recuperar(n->hijos,l_ultima(n->hijos));
                        printf("El segundo hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nodo->elemento)->entero);
                        printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)nodo->elemento)->entero,((tEntero)nodo->padre->elemento)->entero );
                        a_eliminar(a,nod,&eliminarElemento);
                        printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                        tNodo nodo1=l_recuperar(n->hijos,l_primera(n->hijos));
                        printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nodo1->elemento)->entero);
                        printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)nodo1->elemento)->entero,((tEntero)nodo1->padre->elemento)->entero );
                        tEntero entero=(tEntero) malloc(sizeof(struct entero));
                        if (entero!=POS_NULA)
                        {
                            entero->entero=6;
                            a_insertar(a,no,POS_NULA,entero);
                            printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                            n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
                            printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
                            printf("El padre del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
                            no=l_recuperar(a->raiz->hijos,l_siguiente(a->raiz->hijos,l_primera(a->raiz->hijos)));
                            printf("El segundo hijo de la raiz es %i\n",((tEntero)no->elemento)->entero);
                            printf("El padre del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)no->padre->elemento)->entero );
                            nod=l_recuperar(n->hijos,l_primera(n->hijos));
                            printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nod->elemento)->entero);
                            printf("El padre del nodo con elemento %i es %i\n",((tEntero)nod->elemento)->entero,((tEntero)nod->padre->elemento)->entero );
                            nodo=l_recuperar(n->hijos,l_ultima(n->hijos));
                            printf("El segundo hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nodo->elemento)->entero);
                            printf("El padre del nodo con elemento %i es %i\n",((tEntero)nodo->elemento)->entero,((tEntero)nodo->padre->elemento)->entero );
                            tNodo nodo1=l_recuperar(no->hijos,l_ultima(no->hijos));
                            printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)nodo1->elemento)->entero);
                            printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)nodo1->elemento)->entero,((tEntero)nodo1->padre->elemento)->entero );
                            tEntero entero1=(tEntero) malloc(sizeof(struct entero));
                            if (entero1!=POS_NULA)
                            {
                                entero1->entero=7;
                                a_insertar(a,no,l_ultima(no->hijos)->elemento,entero1);
                                printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                                n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
                                printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
                                no=l_recuperar(a->raiz->hijos,l_siguiente(a->raiz->hijos,l_primera(a->raiz->hijos)));
                                printf("El segundo hijo de la raiz es %i\n",((tEntero)no->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)no->padre->elemento)->entero );
                                tNodo nod=l_recuperar(n->hijos,l_primera(n->hijos));
                                printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nod->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n",((tEntero)nod->elemento)->entero,((tEntero)nod->padre->elemento)->entero );
                                nodo=l_recuperar(n->hijos,l_ultima(n->hijos));
                                printf("El segundo hijo del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)nodo->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n",((tEntero)nodo->elemento)->entero,((tEntero)nodo->padre->elemento)->entero );
                                nodo1=l_recuperar(no->hijos,l_primera(no->hijos));
                                printf("El primer hijo del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)nodo1->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n",((tEntero)nodo1->elemento)->entero,((tEntero)nodo1->padre->elemento)->entero );
                                tNodo nodo2=l_recuperar(no->hijos,l_ultima(no->hijos));
                                printf("El segundo hijo del nodo con elemento %i es %i\n",((tEntero)no->elemento)->entero,((tEntero)nodo2->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n\n",((tEntero)nodo1->elemento)->entero,((tEntero)nodo2->padre->elemento)->entero );
                                //a_destruir(&a,&eliminarElemento);
                                //printf("la raiz del arbol es %p\n\n", a->raiz);
                                tArbol arbol;
                                a_sub_arbol(a,n,&arbol);
                                printf("El elemento de la raiz es %i\n", ((tEntero) a->raiz->elemento)->entero);
                                n=l_recuperar(a->raiz->hijos,l_primera(a->raiz->hijos));
                                printf("El primer hijo de la raiz es %i\n",((tEntero)n->elemento)->entero);
                                printf("El padre del nodo con elemento %i es %i\n",((tEntero)n->elemento)->entero,((tEntero)n->padre->elemento)->entero );
                                printf("El elemento de la raiz del nuevo arbol es %i\n", ((tEntero) arbol->raiz->elemento)->entero);
                            }
                            else exit(ARB_ERROR_MEMORIA);
                        }
                else exit(ARB_ERROR_MEMORIA);
                    }
                else exit(ARB_ERROR_MEMORIA);
                }
                else exit(ARB_ERROR_MEMORIA);
            }
            else exit(ARB_ERROR_MEMORIA);
        }
        else exit(ARB_ERROR_MEMORIA);
    }
    else exit(ARB_ERROR_MEMORIA);
    return 0;
}

