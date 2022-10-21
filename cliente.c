#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

int verificaNome(const char nome[]){
    int i;
    for(i = 0; i<strlen(nome); i++){
        if(nome[i] >= 48 && nome[i] <= 57 ){
            return 0;
        }       
    }
    return 1;
}

Cliente *cadastraCliente(ListaCliente *listaCliente){
    Cliente *new = malloc(sizeof(Cliente));
    printf("Código do Cliente: ");
    scanf("%d", &new->codCliente);
    while(new->codCliente < 0){
        printf("O código deve ser número positivo: ");
        scanf("%d", &new->codCliente);
    }
    while(buscaCliente(listaCliente, new->codCliente)){
        printf("Código já cadastrado, insira um novo: ");
        scanf("%d", &new->codCliente);
    }
    printf("Nome do Cliente: ");
    scanf("%s", new->nomeCliente);
    while(!verificaNome(new->nomeCliente)){
        printf("Nome invalido, insira novamente: ");
        scanf("%s", new->nomeCliente);
    }
    printf("CPF do Cliente: ");
    scanf("%d", &new->cpf);
    while(buscaCliente(listaCliente, new->cpf)){
        printf("CPF já cadastrado, insira um novo: ");
        scanf("%d", &new->cpf);
    }
    printf("Idade do Cliente: ");
    scanf("%d", &new->idade);
    printf("Pode vender fiado (SIM[1] NÃO[0]): ");
    scanf("%d", &new->fiado);
        while(new->fiado != 1 && new->fiado != 0){
        printf("Escolha a opção válida (SIM[1]  NÃO[0]): ");
        scanf("%d", &new->fiado);
    }
    printf("\n");
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int listaVaziaCliente(ListaCliente *listaCliente){
    return(listaCliente->first == NULL);
}

void adicionaCliente(ListaCliente *listaCliente, Cliente *new){
    Cliente *aux;
    if(listaVaziaCliente(listaCliente)){
        listaCliente->first = new; 
        listaCliente->last = new;  
        return;
    }
    if(new->idade <= listaCliente->first->idade){
        new->next = listaCliente->first;
        new->next->prev = new;
        listaCliente->first= new;
    }
    else if(new->idade >= listaCliente->last->idade){
        listaCliente->last->next=new;
        new->prev=listaCliente->last;
        listaCliente->last=new;
    }
    else{
        for(aux = listaCliente->first; aux != NULL; aux = aux->next){
            if(new->idade <= aux->idade){
                new->next = aux;
                aux->prev->next = new;
                new->prev = aux->prev;
                aux->prev = new;
                return;
            }
        }   
    }
}
 

void mostrarClientes(ListaCliente *listaCliente){
    Cliente *aux;
    if(listaVaziaCliente(listaCliente)){
        printf("Não existe clientes cadastrados\n\n");
        return;
    }
    printf("-----------------------------------------------\n");
    printf("\n");
    for(aux = listaCliente->first; aux != NULL; aux=aux->next){
        printf("Código: %d\n", aux->codCliente);
        printf("Nome: %s\n", aux->nomeCliente);
        printf("CPF: %d\n", aux->cpf);
        printf("Idade: %d\n", aux->idade);
        if(aux->fiado == 1)
            printf("Vende fiado: SIM\n");
        else
            printf("Vende fiado: NÃO\n");
        printf("\n");
    }
    printf("-----------------------------------------------\n");
    printf("\n");
}

Cliente *buscaCliente(ListaCliente *listaCliente, int key){
    Cliente *aux;
    for(aux = listaCliente->first; aux != NULL; aux = aux->next){
        if(aux->cpf == key || aux->codCliente == key){
            return aux;
        }
    }
    return NULL;
}

int freeListaCliente(ListaCliente *lista){
    Cliente *aux;
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