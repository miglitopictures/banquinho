#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#define PATH "./clientes.dat"

typedef struct {
    char name[50];
    int numConta;
    float saldo;
    int ativo;
} Cliente;

FILE *arquivo;

void cadastrarCliente(){
    Cliente client;
    int posicao;

    arquivo = fopen(PATH, "ab+");

    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }

    printf("posicao para cadastro: ");
    scanf("%d", &posicao);
    printf("numero da conta: ");
    scanf("%d", &client.numConta);
    printf("nome: ");
    scanf(" %[^\n]", client.name);
    printf("saldo: ");
    scanf("%f", &client.saldo);
    client.ativo = 1;

    fseek(arquivo, posicao * sizeof(Cliente), SEEK_SET);
    fwrite(&client, sizeof(Cliente), 1, arquivo);
    fclose(arquivo);
    printf("cliente cadastrado!\n");
}

void consultarCliente() {
    Cliente client;
    int numBusca;
 
    arquivo = fopen(PATH, "rb");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }
 
    printf("numero da conta: ");
    scanf("%d", &numBusca);
 
    while (fread(&client, sizeof(Cliente), 1, arquivo) == 1) {
        if (client.ativo && client.numConta == numBusca) {
            printf("\nconta: %d\nnome: %s\nsaldo: R$%.2f\n", client.numConta, client.name, client.saldo);
            fclose(arquivo);
            return;
        }
    }
 
    printf("conta nao encontrada\n");
    fclose(arquivo);
}

void atualizarSaldo() {
    Cliente client;
    int numBusca;
    long pos;
 
    arquivo = fopen(PATH, "r+b");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }
 
    printf("numero da conta: ");
    scanf("%d", &numBusca);
 
    while (fread(&client, sizeof(Cliente), 1, arquivo) == 1) {
        if (client.ativo && client.numConta == numBusca) {
            printf("saldo atual: R$%.2f\nnovo saldo: ", client.saldo);
            scanf("%f", &client.saldo);
            pos = ftell(arquivo) - sizeof(Cliente);
            fseek(arquivo, pos, SEEK_SET);
            fwrite(&client, sizeof(Cliente), 1, arquivo);
            printf("saldo atualizado!\n");
            fclose(arquivo);
            return;
        }
    }
 
    printf("conta nao encontrada\n");
    fclose(arquivo);
}

void encerrarConta() {
    Cliente client;
    int numBusca;
    long pos;
 
    arquivo = fopen(PATH, "r+b");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }
 
    printf("numero da conta: ");
    scanf("%d", &numBusca);
 
    while (fread(&client, sizeof(Cliente), 1, arquivo) == 1) {
        if (client.ativo && client.numConta == numBusca) {
            client.ativo = 0;
            pos = ftell(arquivo) - sizeof(Cliente);
            fseek(arquivo, pos, SEEK_SET);
            fwrite(&client, sizeof(Cliente), 1, arquivo);
            printf("conta encerrada\n");
            fclose(arquivo);
            return;
        }
    }
 
    printf("conta nao encontrada\n");
    fclose(arquivo);
}

void listarClientes() {
    Cliente client;
 
    arquivo = fopen(PATH, "rb");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }
 
    rewind(arquivo);
 
    printf("\n_____________clientes cadastrados_____________\n\n");
    printf("  N da Conta  |  Nome Completo  |  Saldo\n");
    while (fread(&client, sizeof(Cliente), 1, arquivo) == 1) {
        if (client.ativo) {
            printf("  %-11d  |  %-13s  |  R$%.2f  \n", client.numConta, client.name, client.saldo);
        }
    }
    printf("\n______________________________________________\n\n");
    fclose(arquivo);
}


int main(void) {
    int opcao;
 
    do {
        printf("\n1. cadastrar cliente\n");
        printf("2. consultar cliente\n");
        printf("3. atualizar saldo\n");
        printf("4. encerrar conta\n");
        printf("5. listar clientes\n");
        printf("6. sair\n");
        printf("selecione: ");
        scanf("%d", &opcao);
 
        if (opcao == 1) cadastrarCliente();
        if (opcao == 2) consultarCliente();
        if (opcao == 3) atualizarSaldo();
        if (opcao == 4) encerrarConta();
        if (opcao == 5) listarClientes();
 
    } while (opcao != 6);
 
    printf("encerrando\n");
    return 0;
}