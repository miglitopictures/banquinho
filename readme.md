# Sistema de Contas Bancárias em C

Mini sistema de manutenção de contas com arquivo binário.

## Como compilar e rodar

```bash
clang -o sistema_banco sistema_banco.c
./sistema_banco
```

## Menu

1. Cadastrar cliente 
2. Consultar cliente 
3. Atualizar saldo
4. Encerrar conta
5. Listar clientes
7. Sair


## Funções utilizadas

- `fseek()` — acessa posições específicas do arquivo
- `fread()` / `fwrite()` — lê e grava registros binários
- `rewind()` — reinicia a leitura do arquivo do início