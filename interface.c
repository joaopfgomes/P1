// interface.c

#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"

int main() {
    Pedido* listaPedidos = NULL;
    Fila fila = {NULL, NULL}; // Inicializa a fila com ponteiros nulos
    int opcao, pratoEscolhido;
    
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
            case 1: {
                Pedido* pedido = criarPedido();
                printf("Pedido criado com ID: %d\n", pedido->id);

                while (1) {
                    printf("\nEscolha um prato do cardápio (Digite 0 para finalizar):\n");
                    printf("Entradas:\n");
                    printf("1. Sopa de Cebola\n");
                    printf("2. Salada Caesar\n");
                    printf("3. Bruschetta\n");
                    printf("4. Carpaccio de Carne\n");
                    printf("5. Camarão ao Alho\n");
                    printf("\nPratos Principais:\n");
                    printf("6. Lasanha à Bolonhesa\n");
                    printf("7. Filé Mignon com Fritas\n");
                    printf("8. Frango Grelhado com Legumes\n");
                    printf("9. Bacalhau à Gomes de Sá\n");
                    printf("10. Risoto de Cogumelos\n");
                    printf("\nSobremesas:\n");
                    printf("11. Tiramisu\n");
                    printf("12. Cheesecake de Frutas Vermelhas\n");
                    printf("13. Mousse de Chocolate\n");
                    printf("14. Pudim de Leite\n");
                    printf("15. Sorvete de Baunilha com Calda de Morango\n");
                    printf("Escolha o número do prato: ");
                    scanf("%d", &pratoEscolhido);

                    if (pratoEscolhido == 0) break;

                    switch (pratoEscolhido) {
                        case 1: adicionarPrato(pedido, "Sopa de Cebola"); break;
                        case 2: adicionarPrato(pedido, "Salada Caesar"); break;
                        case 3: adicionarPrato(pedido, "Bruschetta"); break;
                        case 4: adicionarPrato(pedido, "Carpaccio de Carne"); break;
                        case 5: adicionarPrato(pedido, "Camarão ao Alho"); break;
                        case 6: adicionarPrato(pedido, "Lasanha à Bolonhesa"); break;
                        case 7: adicionarPrato(pedido, "Filé Mignon com Fritas"); break;
                        case 8: adicionarPrato(pedido, "Frango Grelhado com Legumes"); break;
                        case 9: adicionarPrato(pedido, "Bacalhau à Gomes de Sá"); break;
                        case 10: adicionarPrato(pedido, "Risoto de Cogumelos"); break;
                        case 11: adicionarPrato(pedido, "Tiramisu"); break;
                        case 12: adicionarPrato(pedido, "Cheesecake de Frutas Vermelhas"); break;
                        case 13: adicionarPrato(pedido, "Mousse de Chocolate"); break;
                        case 14: adicionarPrato(pedido, "Pudim de Leite"); break;
                        case 15: adicionarPrato(pedido, "Sorvete de Baunilha com Calda de Morango"); break;
                        default: printf("Opção inválida!\n"); break;
                    }
                }
                adicionarPedidoLista(&listaPedidos, pedido);
                break;
            }

            case 2: {
                printf("Digite o ID do pedido: ");
                int id;
                scanf("%d", &id);
                printf("Digite o nome do prato a ser removido: ");
                char prato[MAX_NOME];
                scanf("%s", prato);
                removerPrato(listaPedidos, prato);
                break;
            }

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
                printf("Saindo...\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
