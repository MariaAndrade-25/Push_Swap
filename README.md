# push_swap

Versão consolidada e corrigida a partir das duas versões originais.

## Estrutura
- Stack implementada com **array dinâmico**
- Parsing de múltiplos argumentos e strings com espaços
- Validação de inteiros e overflow
- Detecção de duplicados
- Operações completas: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Ordenação específica para até 5 números
- Radix sort com normalização por índices para conjuntos maiores

## Compilar
```bash
make
```

## Executar
```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

Em caso de entrada inválida, o programa escreve `Error` em stderr.
