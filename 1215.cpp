#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 10000
#define MAX_CHARS 200
#define MAX_WORDS 5000

// Fun��o auxiliar para comparar strings
int compare_strings(const void* a, const void* b) {
    const char** str_a = (const char**)a;
    const char** str_b = (const char**)b;
    return strcmp(*str_a, *str_b);
}

int main() {
    char lines[MAX_LINES][MAX_CHARS];
    char words[MAX_WORDS][MAX_CHARS];
    int word_count = 0;
    int i, j;

    // Ler linhas de texto at� o fim de entrada (EOF)
    while (fgets(lines[word_count], MAX_CHARS, stdin) != NULL) {
        // Remover o caractere de nova linha (se existir)
        lines[word_count][strcspn(lines[word_count], "\n")] = '\0';

        // Converter todas as letras para min�sculas
        for (i = 0; lines[word_count][i]; i++) {
            lines[word_count][i] = tolower(lines[word_count][i]);
        }

        // Separar palavras e armazen�-las em 'words'
        char* token = strtok(lines[word_count], " ");
        while (token != NULL) {
            strcpy(words[word_count], token);
            word_count++;

            // Verificar se atingimos o limite m�ximo de palavras
            if (word_count >= MAX_WORDS) {
                printf("Limite m�ximo de palavras atingido.\n");
                return 0;
            }

            token = strtok(NULL, " ");
        }
    }

    // Ordenar as palavras em ordem alfab�tica
    qsort(words, word_count, sizeof(words[0]), compare_strings);

    // Imprimir as palavras distintas
    if (word_count > 0) {
        printf("%s\n", words[0]);
        for (i = 1; i < word_count; i++) {
            // Verificar se a palavra atual � diferente da anterior
            if (strcmp(words[i], words[i - 1]) != 0) {
                printf("%s\n", words[i]);
            }
        }
    }

    return 0;
}
