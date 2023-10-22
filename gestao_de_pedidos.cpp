#include <stdio.h>
#include <string.h>

typedef struct 
{
    int numero;
    char descricao[100];
    int concluido;
    float preco;
    int quantidade_vendida;
} Pedido;

// Função para adicionar um pedido
void adicionarPedido(Pedido pedidos[], int *totalPedidos) 
{
    if (*totalPedidos < 100) 
	{
        Pedido novoPedido;
        printf("Numero do Pedido: ");
        scanf("%d", &novoPedido.numero);
        getchar();  // Consumir a quebra de linha deixada pelo scanf
        printf("Descricao do Pedido: ");
        scanf(" %[^\n]", novoPedido.descricao);
        printf("Preco do Pedido: ");
        scanf("%f", &novoPedido.preco);
        novoPedido.concluido = 0;
        novoPedido.quantidade_vendida = 0;

        pedidos[(*totalPedidos)++] = novoPedido;
    } 
	
	else 
    
	{
        printf("A capacidade máxima de pedidos foi atingida.\n");
    }
}

// Função para listar todos os pedidos
void listarPedidos(Pedido pedidos[], int totalPedidos) 
{
    printf("Lista de Pedidos:\n");
    for (int i = 0; i < totalPedidos; i++) 
	{
        printf("Numero: %d\n", pedidos[i].numero);
        printf("Descricao: %s\n", pedidos[i].descricao);
        printf("Preco: %,2f\n", pedidos[i].preco);
        printf("Concluido: %s\n", pedidos[i].concluido ? "Sim" : "Nao");
        printf("Quantidade Vendida: %d\n", pedidos[i].quantidade_vendida);
        printf("------------------------------\n");
    }
}

// Função para marcar um pedido como concluído
void marcarConcluido(Pedido pedidos[], int totalPedidos, int numeroPedido) 
{
    for (int i = 0; i < totalPedidos; i++) 
	{
        if (pedidos[i].numero == numeroPedido) 
		{
            pedidos[i].concluido = 1;
            printf("Pedido marcado como concluido.\n");
            return;
        }
    }
    printf("Pedido nao encontrado.\n");
}

// Função para salvar os pedidos em um arquivo
void salvarPedidos(Pedido pedidos[], int totalPedidos) 
{
    FILE *arquivo;
    arquivo = fopen("pedidos.txt", "w");
    if (arquivo == NULL) 
	{
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < totalPedidos; i++) 
	{
        fprintf(arquivo, "%d,%s,%.2f,%d,%d\n", pedidos[i].numero, pedidos[i].descricao, pedidos[i].preco, pedidos[i].concluido, pedidos[i].quantidade_vendida);
    }

    fclose(arquivo);
    printf("Pedidos salvos com sucesso no arquivo 'pedidos.txt'.\n");
}

int main() 

{
    Pedido pedidos[100];
    int totalPedidos = 0;
    int escolha;

    while (1) 
    
	{
        printf("Escolha uma opcao:\n");
        printf("1. Adicionar Pedido\n");
        printf("2. Listar Pedidos\n");
        printf("3. Marcar Pedido como Concluido\n");
        printf("4. Salvar Pedidos em um Arquivo\n");
        printf("5. Sair\n");
        scanf("%d", &escolha);
        	
        switch (escolha)
		 
		{
            case 1:
                adicionarPedido(pedidos, &totalPedidos);
                break;
            case 2:
                listarPedidos(pedidos, totalPedidos);
                break;
            case 3:
                int numeroPedido;
                printf("Numero do Pedido a ser marcado como concluido: ");
                scanf("%d", &numeroPedido);
                marcarConcluido(pedidos, totalPedidos, numeroPedido);
                break;
            case 4:
                salvarPedidos(pedidos, totalPedidos);
                break;
            case 5:
                printf("Saindo do programa. Até mais!\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }        

    return 0;
}
