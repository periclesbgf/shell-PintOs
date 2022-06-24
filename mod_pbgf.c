#include "../devices/input.h"
#include "pbgf.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


void shell(){

    bool qq = 0;
    while(qq == 0){
        int contador = 0;
        int saida = 0;
        int aux;
        int BACKSPACE = 8;
        int ENTER = 13;
        printf("pbgf> ");
        char tecla[6];
        while (saida == 0){
            aux = input_getc();
            if (aux == ENTER) {
                saida = 1;
            } else if (aux == BACKSPACE){
                if (contador != 0){
                    printf("\b \b");
                    contador --;
                }
                continue;
            }
            tecla[contador] = aux;
            printf("%c", tecla[contador]);
            contador++;
        }
        saida = 0;
        tecla[contador - 1] = '\0';
        contador = 0;
        printf("\n");
        if (strcmp(tecla, "whoami") == 0) {
            printf("Paricles Buarque de Gusmao Filho\n");
        }
        else if (strcmp(tecla, "exit") == 0){
            qq = 1;

        } else {
            printf("invalid command\n");
        }
        
    }
}