#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Cria um novo pedido
Pedido* criarPedido(int id) {
    Pedido* novo = (Pedido*)malloc(sizeof(Pedido));
    novo->id = id;
    novo->qtdPratos = 0;
    novo->proximo = NULL;
    return novo;
}

// Adiciona um prato ao pedido
void adicionarPrato(Pedido* pedido, const char* nomePrato) {
    if (pedido->qtdPratos < MAX_PRATOS) {
        strcpy(pedido->pratos[pedido->qtdPratos].nome, nomePrato);
        pedido->qtdPratos++;
    } else {
        printf("Número máximo de pratos atingido!\n");
    }
}

// Remove um prato do pedido
void removerPrato(Pedido* pedido, const char* nomePrato) {
    int i;
    for (i = 0; i < pedido->qtdPratos; i++) {
        if (strcmp(pedido->pratos[i].nome, nomePrato) == 0) {
            // Remover o prato deslocando os outros
            for (int j = i; j < pedido->qtdPratos - 1; j++) {
                strcpy(pedido->pratos[j].nome, pedido->pratos[j + 1].nome);
            }
            pedido->qtdPratos--;
            printf("Prato removido com sucesso!\n");
            return;
        }
    }
    printf("Prato não encontrado!\n");
}

// Adiciona um pedido à lista ligada
void adicionarPedidoLista(Pedido** lista, Pedido* novoPedido) {
    novoPedido->proximo = *lista;
    *lista = novoPedido;
}

// Remove um pedido da lista ligada pelo ID
void removerPedidoLista(Pedido** lista, int id) {
    Pedido* atual = *lista;
    Pedido* anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Pedido não encontrado!\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Pedido removido com sucesso!\n");
}

// Lista todos os pedidos pendentes
void listarPedidosPendentes(Pedido* lista) {
    Pedido* atual = lista;
    while (atual != NULL) {
        printf("Pedido ID: %d\n", atual->id);
        for (int i = 0; i < atual->qtdPratos; i++) {
            printf("  Prato: %s\n", atual->pratos[i].nome);
        }
        atual = atual->proximo;
    }
}

// Transfere um pedido da lista para a fila
void transferirParaFila(Pedido** lista, Fila* fila) {
    if (*lista == NULL) {
        printf("Nenhum pedido para transferir!\n");
        return;
    }

    Pedido* pedido = *lista;
    *lista = (*lista)->proximo;
    pedido->proximo = NULL;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = pedido;
    } else {
        fila->tras->proximo = pedido;
        fila->tras = pedido;
    }

    printf("Pedido %d transferido para a fila de processamento.\n", pedido->id);
}

// Lista os pedidos na fila
void listarFila(Fila* fila) {
    Pedido* atual = fila->frente;
    while (atual != NULL) {
        printf("Pedido ID: %d em processamento.\n", atual->id);
        atual = atual->proximo;
    }
}

// Processa o próximo pedido na fila
void processarFila(Fila* fila) {
    if (fila->frente == NULL) {
        printf("Nenhum pedido para processar!\n");
        return;
    }

    Pedido* pedido = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    printf("Processando pedido %d.\n", pedido->id);
    free(pedido);
}
