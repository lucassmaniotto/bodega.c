#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carrinho.h"
#include "cliente.h"
#include "bebida.h"
#include "empresa.h"



void printMenu(){
    printf("1 - Cadastrar bebida\n");
    printf("2 - Mostrar bebidas\n");
    printf("3 - Comprar bebida\n");
    printf("4 - Vender Bebida\n");
    printf("5 - Cadastrar Cliente\n");
    printf("6 - Mostrar Clientes\n");
    printf("7 - Sair\n");
}

int main(){
    ListaBebida *listaBebida = malloc(sizeof(ListaBebida));
    listaBebida->first = NULL;  
    listaBebida->last = NULL;
    ListaCliente *listaCliente = malloc(sizeof(ListaCliente));
    listaCliente->first = NULL; 
    listaCliente->last = NULL;

    while (1){
        int opcao, quantFree;
        printMenu();
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        printf("\n");
        if(opcao == 1){
            adicionaBebida(listaBebida, cadastrarBebida(listaBebida));
        }
        else if(opcao == 2){
            mostrarBebidas(listaBebida);
        }
        else if(opcao == 3){
            compraBebida(listaBebida);
        }
        else if(opcao == 4){
            vendeBebida(listaBebida, listaCliente);
        }
        else if(opcao == 5){
            adicionaCliente(listaCliente, cadastraCliente((listaCliente)));
        }
        else if(opcao == 6){
            mostrarClientes(listaCliente);
        }
        else if(opcao == 7){
            quantFree = freeListaBebida(listaBebida) + freeListaCliente(listaCliente);
            printf("Memoria liberada: %d\n", quantFree);
            printf("Sistema finalizado\n");
            break;
        }
        else if(opcao > 7 || opcao < 1){
            printf("Opção invalida!\n\n");
        }
    } 
    return 0;
}