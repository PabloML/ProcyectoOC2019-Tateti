
#include "lista.h"
#include "arbol.h"
#include "partida.h"
#include "ia.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void partidaUsuarioUsuario(tPartida p){
    int x;
    int y;
    ;
    while(p->estado==PART_EN_JUEGO){
        printf("Turno de " );
        if(p->turno_de==PART_JUGADOR_1)
            printf("%s \n",p->nombre_jugador_1);
        else
            if(p->turno_de==PART_JUGADOR_2)
                printf("%s \n",p->nombre_jugador_2);

        printf("INGRESE LAS COORDENADAS  [ ej 1 3] : ");
        scanf("%i",&x);
        scanf("%i",&y);

        while(x<1 || x>3 || y<1 || y>3) {
                printf("ERROR : INGRESE CORRECTAMENTE LAS COORDENADAS : ");
            scanf("%i",&x);
             scanf("%i",&y);
        }

        while(nuevo_movimiento(p, (x-1), (y-1))==PART_MOVIMIENTO_ERROR){
            printf("\n ERROR : POSICION OCUPADA . \n INGRESE DE NUEVO : ");
            scanf("%i",&x);
             scanf("%i",&y);
        }

        dibujarTabla(p);
    }

     if(p->estado!=PART_EN_JUEGO){
            if(p->estado==PART_EMPATE)
                printf("Empataron");
            else{
                printf("Gano ");
                if(p->estado==PART_GANA_JUGADOR_1)
                    printf("%s \n",p->nombre_jugador_1);
                else
                    printf("%s \n",p->nombre_jugador_2);
            }
        finalizar_partida(&p);
        printf("\nGRACIAS POR JUGAR");
    }
}
void  partidaUsuarioComputadora(tPartida p){
    int x;
    int y;

    limpiarConsola();

    while(p->estado==PART_EN_JUEGO){
        if(p->turno_de==PART_JUGADOR_1){
            printf("Turno de %s\n",p->nombre_jugador_1);
            printf("INGRESE LAS COORDENADAS  [ ej 1 3] : ");
             scanf("%i",&x);
             scanf("%i",&y);

            while(x<1 || x>3 || y<1 || y>3) {
                printf("ERROR : INGRESE CORRECTAMENTE LAS COORDENADAS : ");
                scanf("%i",&x);
                scanf("%i",&y);
            }
            while(nuevo_movimiento(p, (x-1), (y-1))==PART_MOVIMIENTO_ERROR){
                printf("\n ERROR : POSICION OCUPADA . \n INGRESE DE NUEVO : ");
                scanf("%i",&x);
                scanf("%i",&y);
            }
        }
        else{
            if(p->turno_de==PART_JUGADOR_2){
                printf("Turno de Computadora \n");
                tBusquedaAdversaria ia=NULL;
                crear_busqueda_adversaria(&ia, p);
                proximo_movimiento(ia,&x,&y);
                nuevo_movimiento(p,x,y);
                destruir_busqueda_adversaria(&ia);
            }
        }
        dibujarTabla(p);
    }
    if(p->estado!=PART_EN_JUEGO){
        if(p->estado==PART_EMPATE)
            printf("Empataron");
        else{
            printf("Gano ");
            if(p->estado==PART_GANA_JUGADOR_1)
                printf("%s \n",p->nombre_jugador_1);
            else
                printf("%s \n",p->nombre_jugador_2);
        }
        finalizar_partida(&p);
        printf("\nGRACIAS POR JUGAR");
    }
}

int main(){
    tPartida p;
    int modoPartida;
    int comienza;
    char nombreJ1[50];
    char nombreJ2[50];


        //printf("Como quiere jugar la partida? \n1= Usuario vs Usuario o 2= Usuario vs Computadora: ");
        printf("ELIGA EL MODO DE JUEGO : \n");
        printf("1) USUARIO VS USUARIO  \n");
        printf("2) USUARIO VS COMPUTADORA \n");

        scanf("%i", &modoPartida);
        if(modoPartida==1)
            modoPartida=PART_MODO_USUARIO_VS_USUARIO;
        else
            if(modoPartida==2)
                modoPartida=PART_MODO_USUARIO_VS_AGENTE_IA;

        while(modoPartida!= PART_MODO_USUARIO_VS_USUARIO && modoPartida!= PART_MODO_USUARIO_VS_AGENTE_IA){
            printf("ERROR : Elija alguno de los mencionados anteriormente: ");
            scanf("%i", &modoPartida);
            if(modoPartida==1)
                modoPartida=PART_MODO_USUARIO_VS_USUARIO;
            else
                if(modoPartida==2)
                    modoPartida=PART_MODO_USUARIO_VS_AGENTE_IA;
        }

         limpiarConsola();

        // Si el modo a jugar es Usuario vs Usuario
        if(modoPartida==PART_MODO_USUARIO_VS_USUARIO){
            //printf("Quien va a iniciar jugando la partida? \n1= Jugador1, 2= Jugador2 o 3=Al azar: ");
            printf("ELIGA QUIEN COMENZARA A JUGAR : \n");
            printf("1)_ JUGADOR_1");
            printf("2)_ JUGADOR_2");
            printf("3)_ AL_AZAR");

            scanf("%i", &comienza);
            if(comienza==1)
                   comienza=PART_JUGADOR_1;
            else
                if(comienza==2)
                        comienza=PART_JUGADOR_2;
                else
                    if(comienza==3)
                        comienza=PART_JUGADOR_RANDOM;

            while(comienza!=PART_JUGADOR_1 && comienza!=PART_JUGADOR_2 && comienza!= PART_JUGADOR_RANDOM){
                printf("ERROR : Elija alguno de los mencionados anteriormente: ");
                scanf("%i", &comienza);
                 if(comienza==1)
                   comienza=PART_JUGADOR_1;
                else
                    if(comienza==2)
                        comienza=PART_JUGADOR_2;
                    else
                        if(comienza==3)
                            comienza=PART_JUGADOR_RANDOM;
            }

            limpiarConsola();

            printf("\nNombre del Jugador 1: ");
            scanf("%s",nombreJ1);
            printf("\nNombre del Jugador 2: ");
            scanf("%s",nombreJ2);

            limpiarConsola();

            nueva_partida(&p,modoPartida,comienza,nombreJ1,nombreJ2);
            partidaUsuarioUsuario(p);

        }
        else{
            // Si el modo a jugar es Usuario vs Inteligencia Artificial
            if(modoPartida==PART_MODO_USUARIO_VS_AGENTE_IA){
                printf("ELIGA QUIEN VA A COMENZAR LA PARTIDA : \n");
                printf("1)_JUGADOR_1 \n");
                printf("2)_JUGADOR_2 \n" );
                printf("3)_AL_AZAR \n");

                scanf("%i", &comienza);
                if(comienza==1)
                   comienza=PART_JUGADOR_1;
                else
                    if(comienza==2)
                        comienza=PART_JUGADOR_2;
                    else
                        if(comienza==3)
                            comienza=PART_JUGADOR_RANDOM;
                while(comienza!=PART_JUGADOR_1 && comienza!=PART_JUGADOR_2 && comienza!= PART_JUGADOR_RANDOM){
                    printf("Eleccion incorrecta. \nElija alguno de los mencionados anteriormente: ");
                    scanf("%i", &comienza);
                    if(comienza==1)
                        comienza=PART_JUGADOR_1;
                    else
                        if(comienza==2)
                            comienza=PART_JUGADOR_2;
                        else
                            if(comienza==3)
                                comienza=PART_JUGADOR_RANDOM;
                }

                limpiarConsola();

                printf("\nNombre del Jugador 1: ");
                scanf("%s",nombreJ1);
                strcpy(nombreJ2, "Computadora");
                nueva_partida(&p,modoPartida,comienza,nombreJ1,nombreJ2);
                partidaUsuarioComputadora(p);
            }
        }
    return 0;
}

    void limpiarConsola(){
        system("cls");
    }
/**
 Dibuja la tabla
**/
void dibujarTabla(tPartida p) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(p->tablero->grilla[i][j]==PART_SIN_MOVIMIENTO){
                printf("    _");
            }
            else
                if(p->tablero->grilla[i][j]==PART_JUGADOR_1)
                    printf("    O");
                else
                    if(p->tablero->grilla[i][j]==PART_JUGADOR_2)
                        printf("    X");

        }
        printf("\n\n");
    }
}
