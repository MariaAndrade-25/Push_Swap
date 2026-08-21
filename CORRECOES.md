# Correções realizadas

## Cruzamento das versões
A versão `Push_Swap-main (1)` possuía a base mais completa para parsing,
alocação e validação. A versão `push_swap-main` possuía tentativas de
ordenação para casos pequenos e grandes. As duas versões tinham arquivos
incompletos e inconsistências de estrutura.

## Problemas corrigidos
- `main.c` estava incompleto.
- Não havia `Makefile` funcional.
- O header da segunda versão declarava `values` como `int` em vez de `int *`.
- Existiam referências a estruturas de lista encadeada apesar do projeto usar
  arrays.
- `push_swap.c` continha apenas declarações sem implementação útil.
- `utils.c` possuía funções incompletas e uma implementação inválida de
  comparação de strings.
- O parser de flags estava quebrado e não é necessário para o enunciado padrão.
- `rrr` executava rotação normal em vez de reverse rotate.
- A implementação original de `push` deslocava os elementos na direção errada.
- Os algoritmos de ordenação de 4 e 5 números tinham inconsistências.
- O `sort_simple.c` incluía um arquivo `.c` diretamente.
- Foram removidas dependências de estruturas inexistentes e arquivos
  incompatíveis entre as versões.

## Versão final
A versão consolidada usa:
- array dinâmico para as duas stacks;
- parsing de argumentos separados ou entre aspas;
- validação de `INT_MIN` e `INT_MAX`;
- tratamento de `+` e `-`;
- rejeição de duplicados;
- todas as 11 operações obrigatórias;
- algoritmo específico para 2 a 5 números;
- radix sort com normalização por posição para conjuntos maiores.

## Testes executados
- compilação com `-Wall -Wextra -Werror`;
- entradas inválidas e duplicadas;
- testes aleatórios de 2 a 50 números;
- teste aleatório de 100 números: ordenado corretamente;
- teste aleatório de 500 números: ordenado corretamente.
