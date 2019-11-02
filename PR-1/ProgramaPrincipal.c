#include <stdio.h>
#include <stdlib.h>

#include "partida.h"
#include "lista.h"
#include "arbol.h"
#include "ia.h"


#define POS_NULA NULL

int pruebaLista();
void limpiarConsola();
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
    char nombre1[50];
    char nombre2[50];

    printf("Ingrese nombre de Jugador 1 \n");
    int i=0;
    scanf("%c",&nombre1[i]);
    while(nombre1[i]!='\n'){
        i++;
        scanf("%c",&nombre1[i]);
    }
    printf("Ingrese nombre de Jugador 2 \n");
     i=0;
    scanf("%c",&nombre2[i]);
    while(nombre2[i]!='\n'){
        i++;
        scanf("%c",&nombre2[i]);
    }


    limpiarConsola();

    int modo;
    printf("Eliga modo de juego : \n");
    printf("(1)_USUARIO VS USUARIO \n");
    printf("(2)_USUARIO VS COMPUTADORA \n");
    printf("(3)_COMPUTADORA VS COMPUTADORA \n");
    scanf("%i",&modo);
    if(modo==1)
        modo=103;
    else
        if(modo==2)
            modo=104;
        else
            modo=105;
    limpiarConsola();

    int comienza;

    printf("Eliga quien empieza : \n");
    printf("(1)_JUGADOR 1 \n");
    printf("(2)_JUGADOR 2 \n");
    printf("(3)_AL AZAR \n");
    scanf("%i",&comienza);
    if(comienza==3)
      comienza=(rand()%(2-1+1))+1;
    if(comienza==1)
        comienza=100;
    else
        comienza=101;
    limpiarConsola();

    tPartida partida;
    nueva_partida(&partida,modo,comienza,nombre1,nombre2);
    printf("partida creada");
    int x,y;

    while(partida->estado==111){
       if(partida->turno_de==100)
            printf("Turno de Jugador 1: %s\n",partida->nombre_jugador_1);
        else
            printf("Turno de Jugador 2: %s\n",partida->nombre_jugador_2);
      if(partida->modo_partida==103){
        printf("Ingrese coordenadas para colocar: (fila columna) \n");
        scanf("%i",&x);
        scanf("%i",&y);
        nuevo_movimiento(partida,x,y);

      }

      system("pause");
      limpiarConsola();
    }


}
 void limpiarConsola(){
    system("cls");
}
