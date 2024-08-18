#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_NOME 100

typedef struct Pedido {
    int id;
    char pratos[MAX_NOME];
    struct Pedido* next;
} Pedido;

typedef struct Fila {
    Pedido* inicio;
    Pedido* fim;
} Fila;

// Funções de pedido
Pedido* criarPedido(int id);
void adicionarPrato(Pedido* pedido, const char* prato);
void removerPrato(Pedido* pedido, const char* prato);
void adicionarPedidoLista(Pedido** listaPedidos, Pedido* pedido);
void listarPedidosPendentes(Pedido* listaPedidos);

// Funções de fila
void transferirParaFila(Pedido** listaPedidos, Fila* fila);
void listarFila(Fila* fila);

#endif // PEDIDO_H
