/**
 * TDA Partida.
 * @author Pablo Lencina, Adrian Flores
 */

#include <stdio.h>
#include <stdlib.h>

#include "partida.h"

#define PART_JUGADOR_1                      100
#define PART_JUGADOR_2                      101
#define PART_JUGADOR_RANDOM                 102

#define PART_MODO_USUARIO_VS_USUARIO        103
#define PART_MODO_USUARIO_VS_AGENTE_IA      104
#define PART_MODO_AGENTE_IA_VS_AGENTE_IA    105

#define PART_MOVIMIENTO_OK                  106
#define PART_MOVIMIENTO_ERROR               107
#define PART_SIN_MOVIMIENTO                 108
#define PART_GANA_JUGADOR_1                 109
#define PART_GANA_JUGADOR_2                 110
#define PART_EN_JUEGO                       111
#define PART_EMPATE                         112

#define PART_ERROR_MEMORIA                  113

void controlGanador(tPartida p,int turno_De);

/**
Inicializa una nueva partida, indicando:
 - Modo de partida (Usuario vs. Usuario o Usuario vs. Agente IA).
 - Jugador que comienza la partida (Jugador 1, Jugador 2, o elección al azar).
 - Nombre que representa al Jugador 1.
 - Nombre que representa al Jugador 2.
**/
extern void nueva_partida(tPartida * p, int modo_partida, int comienza, char * j1_nombre, char * j2_nombre){
    (*p)=(tPartida)malloc(sizeof(struct partida));
    (*p)->modo_partida=modo_partida;
    (*p)->estado=111;
    (*p)->turno_de=comienza;
     (*p)->tablero=(tTablero)malloc(sizeof(struct tablero));
     for(int k=0;k<=2;k++)
        for(int h=0;h<=2;h++)
            (*p)->tablero->grilla[k][h]=0;
     for(int i=0;i<50;i++)
       (*p)->nombre_jugador_1[i]=*(j1_nombre+i);
     for(int j=0;j<50;j++)
       (*p)->nombre_jugador_2[j]=*(j2_nombre+j);
}
/**
Actualiza, si corresponde, el estado de la partida considerando que el jugador al que le corresponde jugar, decide hacerlo en la posición indicada (X,Y).
En caso de que el movimiento a dicha posición sea posible, retorna PART_MOVIMIENTO_OK; en caso contrario, retorna PART_MOVIMIENTO_ERROR.
Las posiciones (X,Y) deben corresponderse al rango [0-2]; X representa el número de fila, mientras Y el número de columna.
**/
extern int nuevo_movimiento(tPartida p, int mov_x, int mov_y){
    int valido=0;
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++)
                if(i==mov_x && j==mov_y && (p->tablero->grilla[i][j]==0)){
                    valido=1;
                    p->tablero->grilla[i][j]=p->turno_de;
                    if(p->turno_de == 100)
                        printf(" X |");
                    else
                        printf(" O |");
                }
                else{
                    if(p->tablero->grilla[i][j]==100)
                        printf(" X |");
                    else
                        if(p->tablero->grilla[i][j]==101)
                            printf(" O |");
                        else
                            printf("   |");
                }
           if(i!=2)
                printf("\n --------- \n");
        }
        printf("\n");


    if(valido==1){
        controlGanador(p,p->turno_de);
        if(p->turno_de==100)
            p->turno_de=101;
        else
            p->turno_de=100;

        return (PART_MOVIMIENTO_OK);
    }
    else
        return (PART_MOVIMIENTO_ERROR);

}
/**
Finaliza la partida referenciada por P, liberando toda la memoria utilizada.
**/
extern void finalizar_partida(tPartida * p){
   tPartida partida=(*p);
    free(partida->estado);
    free(partida->modo_partida);
    free(partida->nombre_jugador_1);
    free(partida->nombre_jugador_2);
    free(partida->tablero->grilla);
    free(partida->tablero);
    free(partida->turno_de);
    free(p);
}

void controlGanador(tPartida p,int turno_De){
 int hayGanador=0;
 if((p->tablero->grilla[0][0]==turno_De)&&(p->tablero->grilla[0][1]==turno_De)&&(turno_De==p->tablero->grilla[0][2]))
    hayGanador=1;
 else
    if((p->tablero->grilla[0][2]==turno_De)&&(turno_De==p->tablero->grilla[1][2])&&(turno_De==p->tablero->grilla[2][2]))
            hayGanador=1;
    else
        if((p->tablero->grilla[2][2]==turno_De)&&(p->tablero->grilla[2][1]==turno_De)&&(p->tablero->grilla[2][0]==turno_De))
            hayGanador=1;
        else
            if((p->tablero->grilla[2][0]==turno_De)&&(p->tablero->grilla[1][0]==turno_De)&&(p->tablero->grilla[0][0]==turno_De))
                hayGanador=1;
            else
                if((p->tablero->grilla[0][0]==turno_De)&&(p->tablero->grilla[1][1]==turno_De)&&(p->tablero->grilla[2][2]==turno_De))
                    hayGanador=1;
                else
                    if((p->tablero->grilla[0][2]==turno_De)&&(p->tablero->grilla[1][1]==turno_De)&&(turno_De==p->tablero->grilla[2][0]))
                        hayGanador=1;

 if(hayGanador==1)
    if(turno_De==100)
        p->estado=109;
     else
        p->estado=110;
}