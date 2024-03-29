/**
 * TDA Partida.
 * @author Pablo Lencina, Adrian Flores
 */

#include "partida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
Determina aleatoriamente que jugador iniciara la partida si se selecciona la opcion PART_JUGADOR_RANDOM
**/
int jugadorRamdom(){
    int jugador;
    int num= rand()%2;
    if(num==0)
        jugador=PART_JUGADOR_1;
    else
        jugador=PART_JUGADOR_2;

    return jugador;
}

/**
Inicializa una nueva partida, indicando:
 - Modo de partida (Usuario vs. Usuario o Usuario vs. Agente IA).
 - Jugador que comienza la partida (Jugador 1, Jugador 2, o elecci�n al azar).
 - Nombre que representa al Jugador 1.
 - Nombre que representa al Jugador 2.
**/
void nueva_partida(tPartida * p, int modo_partida, int comienza, char * j1_nombre, char * j2_nombre){

    (*p)=malloc(sizeof(struct partida));
    (*p)->modo_partida=modo_partida;

    if(comienza==PART_JUGADOR_RANDOM)
        comienza=jugadorRamdom();

    (*p)->turno_de=comienza;
    (*p)->tablero=malloc(sizeof(struct tablero));

    int i;
    int j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            ((*p)->tablero)->grilla[i][j]=PART_SIN_MOVIMIENTO;
        }
    }
    strcpy((*p)->nombre_jugador_1, j1_nombre);
    strcpy((*p)->nombre_jugador_2, j2_nombre);

    (*p)->estado=PART_EN_JUEGO;
}

int controlGanador(tTablero tablero){
    int ocupa = -1;

        if(tablero->grilla[0][0]==tablero->grilla[0][1] && tablero->grilla[0][0] == tablero->grilla[0][2])
                    ocupa= tablero->grilla[0][0];
        else
           if(tablero->grilla[0][0]==tablero->grilla[1][0] && tablero->grilla[0][0]==tablero->grilla[2][0])
                    ocupa= tablero->grilla [0][0];
            else
                if(tablero->grilla[1][1]==tablero->grilla[0][0] && tablero->grilla[2][2]==tablero->grilla[0][0])
                    ocupa= tablero->grilla[0][0];
                else
                    if(tablero->grilla[1][1]==tablero->grilla[0][1] && tablero->grilla[1][1]==tablero->grilla[2][1])
                        ocupa= tablero->grilla[1][1];
                    else
                        if(tablero->grilla[1][1]==tablero->grilla[1][0] && tablero->grilla[1][1]==tablero->grilla[1][2])
                            ocupa = tablero->grilla[1][1];
                        else
                            if(tablero->grilla[1][1]==tablero->grilla[0][2] && tablero->grilla[1][1]==tablero->grilla[2][0])
                                ocupa= tablero->grilla [1][1];
                            else
                                if(tablero->grilla[2][2]==tablero->grilla[2][1] && tablero->grilla[2][2]==tablero->grilla[2][0])
                                    ocupa= tablero->grilla[2][2];
                                else
                                    if(tablero->grilla[2][2]==tablero->grilla[1][2] && tablero->grilla[2][2]==tablero->grilla[0][2])
                                        ocupa= tablero->grilla[2][2];


    int i;
    int j;
    if(ocupa == -1) {
       for(i=0; i<3; i++)
                    for(j=0; j<3; j++)
                        if(tablero->grilla[i][j]==PART_SIN_MOVIMIENTO)
                            return PART_EN_JUEGO;
        return PART_EMPATE;
    }
    else
        return ocupa;
}

/**
Actualiza, si corresponde, el estado de la partida considerando que el jugador al que le corresponde jugar, decide hacerlo en la posici�n indicada (X,Y).
En caso de que el movimiento a dicha posici�n sea posible, retorna PART_MOVIMIENTO_OK; en caso contrario, retorna PART_MOVIMIENTO_ERROR.
Las posiciones (X,Y) deben corresponderse al rango [0-2]; X representa el n�mero de fila, mientras Y el n�mero de columna.
**/
int nuevo_movimiento(tPartida p, int mov_x, int mov_y){
    int salida;
    if((p->tablero)->grilla[mov_x][mov_y]!=PART_SIN_MOVIMIENTO)
        salida=PART_MOVIMIENTO_ERROR;
    else{
        (p->tablero)->grilla[mov_x][mov_y]=p->turno_de;
        salida=PART_MOVIMIENTO_OK;

        if(p->turno_de==PART_JUGADOR_1)
            p->turno_de=PART_JUGADOR_2;
        else
            if(p->turno_de==PART_JUGADOR_2)
                p->turno_de=PART_JUGADOR_1;


        if(controlGanador(p->tablero)==PART_EMPATE)
            p->estado=PART_EMPATE;
        else
            if(controlGanador(p->tablero)==PART_JUGADOR_1)
                p->estado=PART_GANA_JUGADOR_1;
            else
                if(controlGanador(p->tablero)==PART_JUGADOR_2)
                    p->estado=PART_GANA_JUGADOR_2;

    }
    return salida;
}

/**
Finaliza la partida referenciada por P, liberando toda la memoria utilizada.
**/
void finalizar_partida(tPartida * p){
    free((*p)->tablero);
    free(*p);
}
