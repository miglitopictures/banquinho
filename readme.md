# Sistema de Contas Bancárias em C

Sistema de manutenção de contas com arquivo binário.

## Como compilar e rodar

```bash
clang -o sistema_banco sistema_banco.c
./sistema_banco
```

## Menu

1. Cadastrar cliente em uma posição específica
2. Consultar cliente pelo número da conta
3. Atualizar saldo
4. Encerrar conta
5. Listar clientes
6. Listar com rewind
7. Sair

## Funções utilizadas

- `fseek()` — acessa posições específicas do arquivo
- `fread()` / `fwrite()` — lê e grava registros binários
- `rewind()` — reinicia a leitura do arquivo do início