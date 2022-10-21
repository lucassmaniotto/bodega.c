struct _bebida{
    int codBebida;
    char nomeBebida[30];
    int quantMl;
    int alcoolica;
    double preco;
    int estoque;
    struct _bebida *next;
    struct _bebida *prev;
};
typedef struct _bebida Bebida;

typedef struct _listaBebida{
    Bebida *first;
    Bebida *last;
}ListaBebida;


Bebida *cadastrarBebida(ListaBebida *listaBebida);
Bebida *buscaBebida(ListaBebida *listaBebida, int cod);
void adicionaBebida(ListaBebida *listaBebida, Bebida *new);
void compraBebida(ListaBebida *listaBebida);
void mostrarBebidas(ListaBebida *listaBebida);
void vendeBebida(ListaBebida *listaBebida, ListaCliente *listaCliente);
int verificaVenda(ListaBebida *listaBebida, ListaCliente *listaCliente);
int freeListaBebida(ListaBebida *lista);
int listaVaziaBebida(ListaBebida *listaBebida);
