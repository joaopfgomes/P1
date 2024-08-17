#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"

int main() {
    Pedido* listaPedidos = NULL;
    Fila fila = {NULL, NULL};
    int opcao, id;
    char prato[MAX_NOME];

    while (1) {
        printf("\nMenu de Opções:\n");
        printf("1. Adicionar Pedido\n");
        printf("2. Remover Prato de Pedido\n");
        printf("3. Processar Pedido\n");
        printf("4. Listar Pedidos Pendentes\n");
        printf("5. Listar Pedidos em Processamento\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID do pedido: ");
                scanf("%d", &id);
                Pedido* pedido = criarPedido(id);
                printf("Digite o nome do prato (digite 'fim' para encerrar): ");
                while (1) {
                    scanf("%s", prato);
                    if (strcmp(prato, "fim") == 0) break;
                    adicionarPrato(pedido, prato);
                }
                adicionarPedidoLista(&listaPedidos, pedido);
                break;

            case 2:
                printf("Digite o ID do pedido: ");
                scanf("%d", &id);
                printf("Digite o nome do prato a ser removido: ");
                scanf("%s", prato);
                removerPrato(listaPedidos, prato);
                break;

            case 3:
                transferirParaFila(&listaPedidos, &fila);
                break;

            case 4:
                listarPedidosPendentes(listaPedidos);
                break;

            case 5:
                listarFila(&fila);
                break;

            case 6:
                exit(0);

            default:
                printf("Opção inválida!\n");
                break;
        }
    }
    return 0;
}
