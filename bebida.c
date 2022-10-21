#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carrinho.h"
#include "cliente.h"
#include "bebida.h"


Bebida *cadastrarBebida(ListaBebida *listaBebida){
    Bebida *new = malloc(sizeof(Bebida));
    printf("Código da Bebida: ");
    scanf("%d", &new->codBebida);
    while(new->codBebida < 1){
        printf("O código deve ser número positivo: ");
        scanf("%d", &new->codBebida);
    }
    while(buscaBebida(listaBebida, new->codBebida) != NULL){
        printf("Código já cadastrado, insira um novo: ");
        scanf("%d", &new->codBebida);
    }
    printf("Nome da Bebida: ");
    scanf("%s", new->nomeBebida);
    printf("Quantidade da bebida em ml: ");
    scanf("%d", &new->quantMl);
    while(new->quantMl <= 0){
        printf("A quantidade não pode ser negativa.\n");
        printf("Digite novamente: ");
        scanf("%d", &new->quantMl);
    }
    printf("Quantidade em estoque: ");
    scanf("%d", &new->estoque);
    while(new->estoque < 0){
        printf("O estoque não pode ser negativo.\n");
        printf("Digite novamente: ");
        scanf("%d", &new->estoque);
    }
    printf("Bebida alcoolica (SIM[1]  NÃO[0]): ");
    scanf("%d", &new->alcoolica);
    while (new->alcoolica != 1 && new->alcoolica != 0){
        printf("Escolha a opção válida (SIM[1]  NÃO[0]): ");
        scanf("%d", &new->alcoolica);
    }
    printf("Preço da Bebida: ");
    scanf("%lf", &new->preco);
    while(new->preco < 0.1){
        printf("O estoque não pode ser negativo.\n");
        printf("Digite novamente: ");
        scanf("%lf", &new->preco);
    }
    printf("\n");
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int listaVaziaBebida(ListaBebida *listaBebida){
    return(listaBebida->first == NULL);
}

void adicionaBebida(ListaBebida *listaBebida, Bebida *new){
    if(listaVaziaBebida(listaBebida)){
        listaBebida->first = new;
        listaBebida->last = new;
    }
    else{
        new->prev = listaBebida->last;
        new->prev->next = new;
        listaBebida->last = new; 
    }
    return;
}

void mostrarBebidas(ListaBebida *listaBebida){
    Bebida *aux;
    if(listaVaziaBebida(listaBebida)){
        printf("Não existe bebidas cadastradas\n\n");
        return;
    }
    printf("-----------------------------------------------\n");
    printf("\n");
    for(aux = listaBebida->first; aux != NULL; aux=aux->next){
        printf("Código: %d\n", aux->codBebida);
        printf("Bebida: %s\n", aux->nomeBebida);
        printf("Quantidade: %dml\n", aux->quantMl);
        if(aux->alcoolica == 1)
            printf("Alcoólica: SIM\n");
        else
            printf("Alcoólica: NÃO\n");
        printf("Preço: R$ %.2lf\n", aux->preco);
        printf("Estoque disponível: %d\n", aux->estoque);
        printf("\n");
    }
    printf("-----------------------------------------------\n");
    printf("\n");
}

Bebida *buscaBebida(ListaBebida *listaBebida, int cod){
    Bebida *aux;
    for(aux = listaBebida->first; aux != NULL; aux = aux->next){
        if(aux->codBebida == cod){
            return aux;
        }
    }
    return NULL;
}

void compraBebida(ListaBebida *listaBebida){
    int quantBebida, cod;
    Bebida *bebida;
    if(listaVaziaBebida(listaBebida)){
        printf("Não existe bebidas cadastradas\n\n");
        return;
    }
    printf("Código da Bebida: ");
    scanf("%d", &cod);
    bebida = buscaBebida(listaBebida, cod);
    if (bebida == NULL){
        printf("Bebida não encontrada\n");
    }
    else{
        printf("Bebida: %s\n", bebida->nomeBebida); 
        printf("Quantidade em estoque: %d\n", bebida->estoque);
        printf("Adicionar em estoque: ");
        scanf("%d", &quantBebida);
        bebida->estoque += quantBebida;
        printf("Estoque atualizado: %d\n\n", bebida->estoque);
    }
}

int verificaVenda(ListaBebida *listaBebida, ListaCliente *listaCliente){
    if(listaVaziaBebida(listaBebida)){
        printf("Não existe bebidas cadastradas\n\n");
        return 0;
    }
    if(listaVaziaCliente(listaCliente)){
        printf("Não existe clientes cadastrados\n\n");
        return 0;
    }
    return 1;
}

void vendeBebida(ListaBebida *listaBebida, ListaCliente *listaCliente){
    ListaCompra *listaCompra = malloc(sizeof(ListaCompra));
    listaCompra->first = NULL;
    listaCompra->last = NULL;
    Carrinho *item, *itemAux;
    int quantBebida, cod, cpf;
    Bebida *bebida;
    Cliente *cliente;
    if(!verificaVenda(listaBebida, listaCliente))
        return; 
    printf("CPF do Cliente: ");
    scanf("%d", &cpf);
    cliente = buscaCliente(listaCliente, cpf);
    if(cliente == NULL){
        printf("Cliente não encontrado\n\n");
        return;
    }
    printf("Cliente: %s\n", cliente->nomeCliente);
    while(1){
        printf("\nPara encerrar a compra digite -1 como codigo.\n\n");
        printf("Codigo da bebida: ");
        scanf("%d", &cod);
        if(cod == -1){
            notaFiscal(listaCompra);
            return;
        }
        bebida = buscaBebida(listaBebida, cod);
        if(!bebida)
            printf("Codigo inválido.\n");
        while(bebida){
            printf("Bebida: %s\n", bebida->nomeBebida);
            if(!bebida->estoque){
                printf("Sem estoque!\n");
                break;
            }
            if(bebida->alcoolica){
                if(cliente->idade < 18){
                    printf("Venda não autorizada, escolha outra bebida.\n");
                    break;
                }
            }
            printf("Quantidade: ");
            scanf("%d", &quantBebida);
            while(quantBebida > bebida->estoque || quantBebida <= 0){
                printf("Quantidade inválida!\n");
                printf("Estoque atual: %d\n", bebida->estoque);
                printf("Quantidade: ");
                scanf("%d", &quantBebida);
            }
            bebida->estoque -= quantBebida;
            item = criaItem(listaCompra, bebida->codBebida, bebida->nomeBebida, bebida->preco, quantBebida);
            itemAux = buscaItem(listaCompra, item);
            if(!itemAux)
                adicionaCarrinho(listaCompra, item);
            else{
                itemAux->quant += quantBebida;
            }
            break;
        }
    }
}

int freeListaBebida(ListaBebida *lista){
    Bebida *aux;
    aux = lista->first;
    int i = 0;
    while(aux != NULL){
        lista->first = lista->first->next;
        free(aux);
        aux = lista->first;
        i++;
    }
    return i;
}