// pedido.h

#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_NOME 100

// Estrutura para armazenar um prato
typedef struct Prato {
    char nome[MAX_NOME];
    struct Prato* next;
} Prato;

// Estrutura para armazenar um pedido
typedef struct Pedido {
    int id;
    Prato* pratos; // Ponteiro para a lista ligada de pratos
    struct Pedido* next; // Ponteiro para o próximo pedido
} Pedido;

// Estrutura para a fila de pedidos
typedef struct Fila {
    Pedido* inicio;
    Pedido* final;
} Fila;

// Protótipos das funções
Pedido* criarPedido(void);
void adicionarPrato(Pedido* pedido, const char* nomePrato);
void removerPrato(Pedido* listaPedidos, const char* nomePrato);
void adicionarPedidoLista(Pedido** listaPedidos, Pedido* pedido);
void transferirParaFila(Pedido** listaPedidos, Fila* fila);
void listarPedidosPendentes(Pedido* listaPedidos);
void listarFila(Fila* fila);

#endif // PEDIDO_H
