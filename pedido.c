// pedido.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Contador global para IDs de pedidos
static int nextID = 1;

// Função para criar um novo pedido com um ID sequencial
Pedido* criarPedido(void) {
    Pedido* pedido = malloc(sizeof(Pedido));
    if (pedido == NULL) {
        perror("Erro ao alocar memória para o pedido");
        exit(EXIT_FAILURE);
    }
    pedido->id = nextID++;
    pedido->pratos = NULL;
    pedido->next = NULL;
    return pedido;
}

// Função para adicionar um prato ao pedido
void adicionarPrato(Pedido* pedido, const char* nomePrato) {
    Prato* prato = malloc(sizeof(Prato));
    if (prato == NULL) {
        perror("Erro ao alocar memória para o prato");
        exit(EXIT_FAILURE);
    }
    strncpy(prato->nome, nomePrato, MAX_NOME);
    prato->nome[MAX_NOME - 1] = '\0';
    prato->next = pedido->pratos;
    pedido->pratos = prato;
}

// Função para remover um prato do pedido
void removerPrato(Pedido* listaPedidos, const char* nomePrato) {
    Pedido* pedido = listaPedidos;
    while (pedido != NULL) {
        Prato* anterior = NULL;
        Prato* atual = pedido->pratos;
        while (atual != NULL) {
            if (strcmp(atual->nome, nomePrato) == 0) {
                if (anterior == NULL) {
                    pedido->pratos = atual->next;
                } else {
                    anterior->next = atual->next;
                }
                free(atual);
                printf("Prato '%s' removido do pedido ID %d\n", nomePrato, pedido->id);
                return;
            }
            anterior = atual;
            atual = atual->next;
        }
        pedido = pedido->next;
    }
    printf("Prato '%s' não encontrado\n", nomePrato);
}

// Função para adicionar um pedido à lista de pedidos
void adicionarPedidoLista(Pedido** listaPedidos, Pedido* pedido) {
    pedido->next = *listaPedidos;
    *listaPedidos = pedido;
}

// Função para transferir pedidos da lista para a fila
void transferirParaFila(Pedido** listaPedidos, Fila* fila) {
    if (*listaPedidos == NULL) {
        printf("Nenhum pedido pendente para processar\n");
        return;
    }
    Pedido* pedido = *listaPedidos;
    *listaPedidos = pedido->next;
    pedido->next = NULL;
    
    if (fila->final == NULL) {
        fila->inicio = fila->final = pedido;
    } else {
        fila->final->next = pedido;
        fila->final = pedido;
    }
    printf("Pedido ID %d transferido para a fila\n", pedido->id);
}

// Função para listar pedidos pendentes
void listarPedidosPendentes(Pedido* listaPedidos) {
    while (listaPedidos != NULL) {
        printf("Pedido ID %d:\n", listaPedidos->id);
        Prato* prato = listaPedidos->pratos;
        while (prato != NULL) {
            printf("  Prato: %s\n", prato->nome);
            prato = prato->next;
        }
        listaPedidos = listaPedidos->next;
    }
}

// Função para listar pedidos na fila
void listarFila(Fila* fila) {
    Pedido* pedido = fila->inicio;
    while (pedido != NULL) {
        printf("Pedido ID %d:\n", pedido->id);
        Prato* prato = pedido->pratos;
        while (prato != NULL) {
            printf("  Prato: %s\n", prato->nome);
            prato = prato->next;
        }
        pedido = pedido->next;
    }
}
