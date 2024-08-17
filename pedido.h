#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_PRATOS 10
#define MAX_NOME 50

// Estrutura para armazenar pratos do pedido
typedef struct {
    char nome[MAX_NOME];
} Prato;

// Nó da lista ligada
typedef struct Pedido {
    int id;
    Prato pratos[MAX_PRATOS];
    int qtdPratos;
    struct Pedido* proximo;
} Pedido;

// Estrutura da fila de processamento
typedef struct {
    Pedido* frente;
    Pedido* tras;
} Fila;

// Funções para manipular a lista ligada e a fila
Pedido* criarPedido(int id);
void adicionarPrato(Pedido* pedido, const char* nomePrato);
void removerPrato(Pedido* pedido, const char* nomePrato);
void adicionarPedidoLista(Pedido** lista, Pedido* novoPedido);
void removerPedidoLista(Pedido** lista, int id);
void listarPedidosPendentes(Pedido* lista);
void transferirParaFila(Pedido** lista, Fila* fila);
void listarFila(Fila* fila);
void processarFila(Fila* fila);

#endif
