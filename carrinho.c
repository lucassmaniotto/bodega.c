#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "bebida.h"
#include "carrinho.h"

Carrinho *criaItem(ListaCompra *ListaCompra, int codItem, char nomeBebida[], double preco, int quant){
    Carrinho *item = malloc(sizeof(Carrinho));
    snprintf(item->nomeBebida, sizeof(item->nomeBebida), "%s", nomeBebida);
    item->codItem = codItem;
    item->preco = preco;
    item->quant = quant;
    item->next = NULL;
    item->next = NULL;
    return item;
}

int listaVaziaCompra(ListaCompra *listaCompra){
    return(listaCompra->first == NULL);
}


void adicionaCarrinho(ListaCompra *listaCompra, Carrinho *item){
    if(listaVaziaCompra(listaCompra)){
        listaCompra->first =  item;
        listaCompra->last = item;
    }
    else{
        listaCompra->last->next = item;
        listaCompra->last = item;
    }
    return;
}

Carrinho *buscaItem(ListaCompra *listaCompra, Carrinho *item){
    Carrinho *aux;
    for(aux = listaCompra->first; aux != NULL; aux= aux->next){
        if(aux->codItem == item->codItem){
            return aux;
        }
    }
    return NULL;
}

void notaFiscal(ListaCompra *listaCompra){
    Carrinho *prox, *atual;
    atual = listaCompra->first;
    int i = 1;
    printf("|------------------------------------------------------|\n");
    printf("| Item | Descrição | Quant. | Preço Uni. | Preco Total |\n");
    printf("|------------------------------------------------------|\n");
    while(atual != NULL){
        printf("|%-6d|%-11s|%-8d|%-12.2lf|%-13.2lf|\n", i, atual->nomeBebida, atual->quant, atual->preco , (atual->preco*atual->quant));
        prox = atual->next;
        free(atual);
        atual = prox;
        i++;
    }
    printf("|------------------------------------------------------|\n");
}

    

        