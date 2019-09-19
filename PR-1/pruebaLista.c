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
    tLista l;
    crear_lista(&l);
    printf("Ingrese los numeros que quiera terminando la serie con 0 : \n");
    tEntero e=(tEntero)malloc(sizeof(struct entero));
    tPosicion p1=l_primera(l);
    int valor;
    scanf("%i",&valor);
    while(valor!=0){
      e->entero=valor;
      l_insertar(l,p1,e);
      printf("el ingresado : %i\n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
      p1=l_siguiente(l,l_primera(l));
      scanf("%i",&valor);
      e=(tEntero)malloc(sizeof(struct entero));
     }
    printf("\nEn lo siguiente se describi posicion como la tPosicion que se conoce en el lista.h que como sabemos se maneja indirectamente.\n");
    e=(tEntero)malloc(sizeof(struct entero));
    tPosicion p=l_primera(l);
    e->entero=1;
    printf("\nInserto el numero 1 en la primera posicion.\n");
    l_insertar(l,p,e);
    e=(tEntero)malloc(sizeof(struct entero));
    e->entero=2;
    p=l_siguiente(l,l_primera(l));
    printf("\nInserto el numero 2 en la posicion siguiente a la primera posicion.\n");
    l_insertar(l,p,e);
    e=(tEntero)malloc(sizeof(struct entero));
    e->entero=3;
    printf("\nInserto el numero 3 en la ultima posicion.\n");
    p=l_anterior(l,l_ultima(l));
    l_insertar(l,p,e);
    e=(tEntero)malloc(sizeof(struct entero));
    e->entero=4;
    p=l_anterior(l,l_fin(l));
    printf("\nInserto el numero 4 en la posicion anterior a la posicion fin de la lista.\n");
    l_insertar(l,p,e);
    printf("\nLa primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
    printf("La siguiente a la primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_siguiente(l,l_primera(l))))->entero);
    printf("La ultima de la lista es: %i \n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
    printf("La anterior a la ultima de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_ultima(l))))->entero);
    p=l_primera(l);
    printf("\nElimino el elemento de la primera posicion.\n");
    l_eliminar(l,p,&eliminarElemento);
    printf("\nLa primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
    printf("La ultima de la lista es: %i \n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
    printf("La anterior a la ultima de la lista es: %i\n",((tEntero)l_recuperar(l,l_anterior(l,l_ultima(l))))->entero);
    p=l_siguiente(l,l_primera(l));
    printf("\nElimino el elemento de la posicio siguiente a la primera posicion.\n");
    l_eliminar(l,p,&eliminarElemento);
    printf("\nLa primera de la lista es: %i \n",((tEntero)l_recuperar(l,l_primera(l)))->entero);
    printf("La ultima de la lista es: %i \n",((tEntero)l_recuperar(l,l_ultima(l)))->entero);
    printf("\nDestruyo la lista.\n");
    l_destruir(&l,&eliminarElemento);
    if (l==POS_NULA)
        printf("\nLa lista fue destruida.\n");
    return 0;
}

int pruebaLista(){
            tLista l;
            int opcion;


        printf("Elija una opcion : \n");
        printf("(1)Crear Lista: \n");
        printf("(2)Ingrese los numeros (Termine con un 0 la secuencia): \n");
        printf("(3)Mostrar La lista : \n");
        printf("(4)Salir : \n");

        scanf("%i",&opcion);

        if(opcion==1){
            crear_lista(&l);
        }

        printf("------------------------\n");
        printf("Elija una opcion : \n");
        printf("(1)Crear Lista: (hecho)\n");
        printf("(2)Ingrese los numeros (Termine con un 0 la secuencia: \n");
        printf("(3)Mostrar La lista : \n");
        printf("(4)Salir : \n");
        scanf("%i",&opcion);
        if(opcion==2){

        tEntero e=(tEntero)malloc(sizeof(struct entero));
        tPosicion p1=l_primera(l);
        printf("Ingrese los numeros que quiera : \n");
        int valor;
        scanf("%i",&valor);
        while(valor!=0){
            e->entero=valor;
            l_insertar(l,p1,e);
            p1=l_siguiente(l,l_primera(l));
            scanf("%i",&valor);
             e=(tEntero)malloc(sizeof(struct entero));
        }
        }
        printf("------------------------\n");
        printf("Elija una opcion : \n");
        printf("(1)Crear Lista: (hecho)\n");
        printf("(2)Ingrese los numeros (Termine con un 0 la secuencia): (hecho)\n");
        printf("(3)Mostrar La lista : \n");
        printf("(4)Salir : \n");
        scanf("%i",&opcion);
        if(opcion==3){
            printf("nnnnnnnnnnnnnnnnnnnnnnnnnnn \n");
            tPosicion pr=l_primera(l);
            printf("nnnnnnnnnnnnnnnnnnnnnnnnnnn \n");
            while(pr!=l_fin(l)){
                printf("Elem : %i\n",((tEntero)l_recuperar(l,pr))->entero);
                pr=pr->siguiente;
                if(pr==l_ultima(l)){
                    pr=l_fin(l);}
                    printf("Elem : %i\n",((tEntero)l_recuperar(l,pr))->entero);

        }
        }

        printf("------------------------\n");
        printf("Elija una opcion : \n");
        printf("(1)Crear Lista: (hecho)\n");
        printf("(2)Ingrese los numeros (Termine con un 0 la secuencia): (hecho)\n");
        printf("(3)Mostrar La lista : (hecho)\n");
        printf("(4)Salir : \n");
        scanf("%i",&opcion);
        if(opcion==4){
           l_destruir(&l,&eliminarElemento);
        if (l==POS_NULA)
            printf("\nLa lista fue destruida.\n");
        }
        return 1;
    }
