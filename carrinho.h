struct _carrinho{
    int codItem;
    char nomeBebida[30];
    double preco;
    int quant;
    struct _carrinho *next;
};
typedef struct _carrinho Carrinho;

typedef struct _listaCompra{
    Carrinho *first;
    Carrinho *last;
}ListaCompra;

Carrinho *buscaItem(ListaCompra *ListaCompra, Carrinho *item);
Carrinho *criaItem(ListaCompra *listaCompra, int codItem, char nomeBebida[], double preco, int quant);
void adicionaCarrinho(ListaCompra *listaCompra, Carrinho *item);
void notaFiscal(ListaCompra *listaCompra);
int listaVaziaCompra(ListaCompra *listaCompra);

