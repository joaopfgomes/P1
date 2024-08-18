#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Função para criar um novo pedido
Pedido* criarPedido(int id) {
    Pedido* novoPedido = (Pedido*)malloc(sizeof(Pedido));
    if (novoPedido == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novoPedido->id = id;
    novoPedido->pratos[0] = '\0'; // Inicializa a string de pratos como vazia
    novoPedido->next = NULL;
    return novoPedido;
}

// Adiciona um prato ao pedido
void adicionarPrato(Pedido* pedido, const char* prato) {
    strcat(pedido->pratos, prato);
    strcat(pedido->pratos, "; "); // Adiciona um separador entre os pratos
}

// Remove um prato do pedido
void removerPrato(Pedido* pedido, const char* prato) {
    // Implementação simplificada para remoção; pode precisar de mais ajustes
    char* pos = strstr(pedido->pratos, prato);
    if (pos != NULL) {
        memmove(pos, pos + strlen(prato) + 2, strlen(pos + strlen(prato) + 2) + 1);
    }
}

// Adiciona um pedido à lista de pedidos pendentes
void adicionarPedidoLista(Pedido** listaPedidos, Pedido* pedido) {
    if (*listaPedidos == NULL) {
        *listaPedidos = pedido;
    } else {
        Pedido* temp = *listaPedidos;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pedido;
    }
}

// Lista todos os pedidos pendentes
void listarPedidosPendentes(Pedido* listaPedidos) {
    if (listaPedidos == NULL) {
        printf("Nenhum pedido pendente.\n");
        return;
    }
    while (listaPedidos != NULL) {
        printf("Pedido ID: %d, Pratos: %s\n", listaPedidos->id, listaPedidos->pratos);
        listaPedidos = listaPedidos->next;
    }
}

// Transfere o pedido mais antigo da lista para a fila
void transferirParaFila(Pedido** listaPedidos, Fila* fila) {
    if (*listaPedidos == NULL) {
        printf("Nenhum pedido pendente para transferir.\n");
        return;
    }

    Pedido* pedido = *listaPedidos;
    *listaPedidos = pedido->next;  // Remove o pedido da lista pendente

    // Adiciona o pedido à fila de processamento
    if (fila->inicio == NULL) {
        fila->inicio = pedido;
        fila->fim = pedido;
        pedido->next = NULL;
    } else {
        fila->fim->next = pedido;
        fila->fim = pedido;
        pedido->next = NULL;
    }

    printf("Pedido com ID %d transferido para a fila de processamento.\n", pedido->id);
}

// Lista todos os pedidos na fila de processamento
void listarFila(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }
    Pedido* temp = fila->inicio;
    while (temp != NULL) {
        printf("Pedido ID: %d, Pratos: %s\n", temp->id, temp->pratos);
        temp = temp->next;
    }
}
