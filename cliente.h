struct _cliente{
    int codCliente;
    char nomeCliente[50];
    int cpf;
    int idade;
    int fiado;
    struct _cliente *next;
    struct _cliente *prev;
};
typedef struct _cliente Cliente;

typedef struct _listaCliente{
    Cliente *first;
    Cliente *last;
}ListaCliente; 

Cliente *cadastraCliente(ListaCliente *listaCliente);
Cliente *buscaCliente(ListaCliente *listaCliente, int key);
void adicionaCliente(ListaCliente *listaCliente, Cliente *new);
void mostrarClientes(ListaCliente *listaBebida);
int freeListaCliente(ListaCliente *lista);
int listaVaziaCliente(ListaCliente *listaCliente);
int verificaNome(const char nome[]);