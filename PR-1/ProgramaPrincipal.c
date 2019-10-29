#include <stdio.h>
#include <stdlib.h>

#include "partida.h"
#include "lista.h"
#include "arbol.h"
#include "ia.h"


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
    free((tEntero)e);
}

int main(){
    char *nombre1;
    char *nombre2;

    printf("Ingrese nombre de Jugador 1 \n");
    scanf("%s",&nombre1);
    printf("Ingrese nombre de Jugador 2 \n");
    scanf("%s",&nombre2);

    limpiarConsola();

    int modo;
    printf("Eliga modo de juego : \n");
    printf("(1)_USUARIO VS USUARIO \n");
    printf("(2)_USUARIO VS COMPUTADORA \n");
    scanf("%i",&modo);

    limpiarConsola();

    int comienza;

    printf("Eliga quien empieza : \n");
    printf("(1)_JUGADOR 1 \n");
    printf("(2)_JUGADOR 2 \n");
    printf("(3)_AL AZAR \n");
    scanf("%i",&comienza);
    if(comienza==3)
      comienza=(rand()%(2-1+1))+1;

    limpiarConsola();

    tPartida partida;
    nueva_partida(&partida,modo,comienza,nombre1,nombre2);

    nuevo_movimiento(partida,0,0);







}
void limpiarConsola(){
    system("cls");
}
