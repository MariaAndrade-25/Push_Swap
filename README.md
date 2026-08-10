# Libft - @42SP

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success.svg" alt="Norminette" />
  <img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License" />
</p>

## 📝 Sobre o Projeto
O **Libft** é o primeiro projeto oficial da grade curricular da 42. O objetivo é recriar diversas funções da biblioteca padrão do C (`libc`), além de desenvolver funções utilitárias adicionais. Este projeto serve como a base de ferramentas que utilizarei ao longo de toda a minha jornada na linha de comando da 42.

> ⚠️ **Aviso:** Todo o código foi escrito seguindo piamente as regras estritas de formatação e boas práticas da **Norminette**.

---

## 🛠️ Funções Implementadas

### Funções da Libc (Replicadas)
* `ft_isalpha` - Verifica se o caractere é alfabético.
* `ft_isdigit` - Verifica se o caractere é um dígito numérico.
* `ft_isalnum` - Verifica se o caractere é alfanumérico.
* `ft_isascii` - Verifica se o caractere pertence à tabela ASCII.
* `ft_isprint` - Verifica se o caractere é imprimível.
* `ft_strlen` - Calcula o comprimento de uma string.
* `ft_memset` - Preenche a memória com um byte constante.
* `ft_bzero` - Zera uma estrutura de dados na memória.
* `ft_memcpy` - Copia uma área de memória.
* `ft_memmove` - Move uma área de memória (seguro contra sobreposição).
* `ft_strlcpy` - Copia uma string com limite de tamanho.
* `ft_strlcat` - Concatena uma string com limite de tamanho.
* `ft_toupper` - Converte um caractere para maiúsculo.
* `ft_tolower` - Converte um caractere para minúsculo.
* `ft_strchr` - Localiza a primeira ocorrência de um caractere em uma string.
* `ft_strrchr` - Localiza a última ocorrência de um caractere em uma string.
* `ft_strncmp` - Compara duas strings até um limite de caracteres.
* `ft_memchr` - Localiza um caractere em um bloco de memória.
* `ft_memcmp` - Compara dois blocos de memória.
* `ft_strnstr` - Localiza uma sub-string dentro de uma string com limite de tamanho.
* `ft_atoi` - Converte uma string de caracteres em um número inteiro (tratando espaços, sinais e dígitos).


## 🚀 Como Compilar e Usar

O projeto possui um **Makefile** que gerencia a compilação automatizada da biblioteca gerando o arquivo estático `libft.a`.

### Comandos Disponíveis:

| Comando | Descrição |
| :--- | :--- |
| `make` | Compila os arquivos `.c` e gera a biblioteca `libft.a`. |
| `make clean` | Remove todos os arquivos objeto (`.o`) gerados. |
| `make fclean` | Remove os arquivos objeto e o arquivo da biblioteca `libft.a`. |
| `make re` | Executa o `fclean` e o `make` novamente (reinicia a compilação). |

---

## 📦 Como Incluir no seu Projeto

Para usar esta biblioteca em qualquer outro projeto em C, basta incluir o cabeçalho no seu código:

```c
#include "libft.h"
