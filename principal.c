#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int inicializar(Pilha * pino1, int * discos);  
void terminar(Pilha * pino1, Pilha * pino2, Pilha * pino3);
int movimentar(Pilha * pino1, Pilha * pino2, Pilha * pino3);
int mover(Pilha * origem, Pilha * destino);
void mostrarPinos(Pilha * pino1, Pilha * pino2, Pilha * pino3);
void mostrarPossibilidades(Pilha * pino1, Pilha * pino2, Pilha * pino3);

int main() {
    int estado = 1;    
    unsigned int discos = 0; 
    Pilha * A = criar();
    Pilha * B = criar();
    Pilha * C = criar();
    while(estado != 1000){
        switch(estado){
            case 1 :
                system("cls");
                estado = inicializar(A, &discos);     
                break;
            case 2 :
                system("cls");
                mostrarPinos(A,B,C); 
            case 3 :
                mostrarPossibilidades(A,B,C);
            case 4 :                
                estado = movimentar(A, B, C);                
                break;            
            case 5 :
                if(tamanho(C) == discos){
                    estado = 6;
                }
                else{
                    estado = 2;   
                }
                break;  
            case 6 :
                terminar(A, B, C);
                estado = 1000;
                break;            
        }
        
    }
    printf("Jogo finalizado!!");
}



int inicializar(Pilha * pino1, int * discos){    
    printf("\nTorre de Hanoi, desenvolvido em C por Ryan Sampaio Filho.\n");
    printf("Voce quer jogar com quantos discos?\n");
    fflush(stdin);
    scanf("%d", discos);
    if(*discos < 0){
        return 1;
    }
    int aux = *discos;
    while(aux > 0){
        empilhar(pino1, aux);    
        aux = aux - 1;    
    }
    return 2;
}
void terminar(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    destruir(pino1);
    destruir(pino2);
    destruir(pino3);
}

int movimentar(Pilha * pino1, Pilha * pino2, Pilha * pino3){    
    char movimento[3] = {0,0,'\0'};
    printf("Digite o proximo movimento: \n");
    fflush(stdin);
    scanf("%c%c", movimento, movimento + 1);
    switch(movimento[0]){
        case 'A':
            switch(movimento[1]){
                case 'B':
                    if(mover(pino1, pino2) == 0)
                        return 4;
                    break;
                case 'C':
                    if(mover(pino1, pino3) == 0)
                        return 4;
                    break;
                default:
                    printf("Movimento invalido!\n");
                        return 4;
            }
            break;
        case 'B':
            switch(movimento[1]){
                case 'A':
                    if(mover(pino2, pino1) == 0)
                        return 4;
                    break;
                case 'C':
                    if(mover(pino2, pino3) == 0)
                        return 4;
                    break;
                default:
                    printf("Movimento invalido!\n");
                    return 4;
            }
            break;
        case 'C':
            switch(movimento[1]){
                case 'A':
                    if(mover(pino3, pino1) == 0)
                        return 4;
                    break;
                case 'B':
                    if(mover(pino3, pino2) == 0)
                        return 4;
                    break;
                default:
                    printf("Movimento invalido!\n");
                    return 4;
                }
                break;
        default:
            printf("Movimento invalido!\n");
            return 4;
            break;         
    }
    return 5;
}

int mover(Pilha * origem, Pilha * destino){    
    if(tamanho(origem) > 0 && (tamanho(destino) <= 0 || topo(origem) < topo(destino))){
        empilhar(destino,desempilhar(origem));
        return 1;
    }
    else {
        printf("Nao e possivel fazer este movimento.\n");
        return 0;
    }
}

void mostrarPinos(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    printf("A: ");
    imprimir(pino1);
    printf("B: ");
    imprimir(pino2);
    printf("C: ");
    imprimir(pino3);
}

void mostrarPossibilidades(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    printf("Voce pode fazer esses movimentos: ");
    if((topo(pino1) < topo(pino2) || tamanho(pino2) == 0) && tamanho(pino1) > 0){
            printf(" AB ");
    }
    if((topo(pino1) < topo(pino3) || tamanho(pino3) == 0) && tamanho(pino1) > 0){
            printf(" AC ");
    }
    if((topo(pino2) < topo(pino1) || tamanho(pino1) == 0) && tamanho(pino2) > 0){
            printf(" BA ");
    }
    if((topo(pino2) < topo(pino3) || tamanho(pino3) == 0) && tamanho(pino2) > 0){
            printf(" BC ");        
    }
    if((topo(pino3) < topo(pino1) || tamanho(pino1) == 0) && tamanho(pino3) > 0){
            printf(" CA ");
    }
    if((topo(pino3) < topo(pino2) || tamanho(pino2) == 0) && tamanho(pino3) > 0){
            printf(" CB ");
    }
    printf("\n");
}

