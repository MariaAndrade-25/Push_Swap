# push_swap

Versão consolidada e corrigida a partir das duas versões originais.

## Estrutura

## Compilar
```bash
make
```

## Executar
```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```
*This project has been created as part of the 42 curriculum by `malves-a`, `mtomanar`.*

# push_swap

## Description

`push_swap` receives distinct signed integers in stack `a` and prints a
sequence of Push_swap operations that sorts `a` in ascending order while
leaving stack `b` empty. Arguments may be passed individually or as quoted
strings. Invalid integers, overflow, duplicates, and unknown options print
`Error` on stderr.

## Instructions

```bash
make
./push_swap 2 1 3 6 5 8
./push_swap --complex "4 67 3 87 23"
./push_swap --adaptive --bench 5 1 4 2 3
make clean
make fclean
```

The default strategy is `--adaptive`. Available selectors are `--simple`,
`--medium`, `--complex`, and `--adaptive`. Normal operation output is sent
only to stdout, one operation per line. `--bench` sends disorder, selected
strategy, complexity, total operations, and all operation counters to stderr.

## Algorithms

Before any move, the program computes disorder as the number of inverted pairs
divided by the total number of pairs. Values are then coordinate-compressed to
their ranks, which supports negative and positive integers without changing
their order.

- **Simple, O(n^2):** repeatedly rotates the smallest remaining rank to the
	top, pushes it to `b`, then pushes all values back to `a`.
- **Medium, O(n sqrt(n)):** partitions ranks into `sqrt(n)` chunks, pushes each
	chunk to `b`, and returns values from largest to smallest.
- **Complex, O(n log(n)):** LSD binary radix sorting using `pb`, `pa`, and
	rotations. The number of passes is logarithmic in `n`.
- **Adaptive:** disorder `< 0.2` selects Simple, `0.2 <= disorder < 0.5`
	selects Medium, and disorder `>= 0.5` selects Complex. These thresholds
	match the required low, medium, and high-disorder regimes.

The stated bounds count generated Push_swap operations. Auxiliary coordinate
compression uses O(n) memory; stack storage and sorting helpers also use O(n)
auxiliary space. The simple method is intentionally a baseline and is not
intended to minimize operations on large random inputs.

## Contributions

- `malves-a`: argument validation, operation implementation, stack handling,
	benchmark reporting, and integration.
- `mtomanar`: sorting strategy implementations, rank/chunk helpers, and
	algorithm organization.

## Resources

- 42 school Push_swap subject and operation specification.
- Knuth, *The Art of Computer Programming*, Volume 3: sorting and searching.
- C standard library and POSIX `write(2)` documentation.

AI was used to review the existing implementation against the subject,
identify build and correctness issues, implement focused fixes, and run
compilation plus randomized operation simulations. The learners remain
responsible for understanding and defending every part of the code.
Em caso de entrada inválida, o programa escreve `Error` em stderr.
