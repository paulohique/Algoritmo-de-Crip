#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_CONTENT_LEN 1000

void criptografarString1(wchar_t *str) {
    int len = wcslen(str);
    for (int i = 0; i < len; i++) {
        int valorAscii = (int)str[i];

        if (valorAscii >= 0 && valorAscii <= 255) {
            str[i] = (wchar_t)(valorAscii + 3);
        }
    }
}

void descriptografarString1(wchar_t *str) {
    int len = wcslen(str);
    for (int i = 0; i < len; i++) {
        int valorAscii = (int)str[i];

        if (valorAscii >= 0 && valorAscii <= 255) {
            str[i] = (wchar_t)(valorAscii - 3);
        }
    }
}

void criptografarString2(wchar_t *str) {
    int len = wcslen(str);
    for (int i = 0; i < len; i++) {
        int valorAscii = (int)str[i];

        if (valorAscii >= 0 && valorAscii <= 255) {
            str[i] = (wchar_t)(valorAscii + 3);
        }
    }
}

void descriptografarString2(wchar_t *str) {
    int len = wcslen(str);
    for (int i = 0; i < len; i++) {
        int valorAscii = (int)str[i];

        if (valorAscii >= 0 && valorAscii <= 255) {
            str[i] = (wchar_t)(valorAscii - 3);
        }
    }
}

void criptografia(wchar_t *str) {
    criptografarString2(str);
    criptografarString1(str);
}

void descriptografia(wchar_t *str) {
    descriptografarString1(str);
    descriptografarString2(str);
}

void criarArquivo(char *nomeArquivo, wchar_t *content) {
    FILE *file;
    file = fopen(nomeArquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        exit(1);
    }
    fwprintf(file, L"%ls", content);
    fclose(file);
    printf("Arquivo '%s' criado com sucesso!\n", nomeArquivo);
}

void editarArquivo(char *nomeArquivo) {
    wchar_t novoConteudo[MAX_CONTENT_LEN];
    FILE *file;

    printf("Digite o novo conteúdo do arquivo '%s':\n", nomeArquivo);
    fgetws(novoConteudo, MAX_CONTENT_LEN, stdin);
    novoConteudo[wcslen(novoConteudo) - 1] = L'\0';
    criptografia(novoConteudo);

    file = fopen(nomeArquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo '%s' para escrita!\n", nomeArquivo);
        exit(1);
    }

    fwprintf(file, L"%ls", novoConteudo);

    fclose(file);

    printf("Arquivo '%s' atualizado com sucesso!\n", nomeArquivo);
}

void lerDescriptografado(char *nomeArquivo) {
    FILE *file;
    wchar_t content[MAX_CONTENT_LEN];

    file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo '%s' para leitura!\n", nomeArquivo);
        exit(1);
    }

    fgetws(content, MAX_CONTENT_LEN, file);

    fclose(file);

    descriptografia(content);

    wprintf(L"Conteúdo do arquivo selecionado (descriptografado):\n");
    wprintf(L"%ls\n", content);
}

void nomeAleatorio(char *nomeArquivo, int comprimento) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < comprimento; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);
        nomeArquivo[i] = charset[randomIndex];
    }
    nomeArquivo[comprimento] = '\0';
    strcat(nomeArquivo, ".txt");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));
    char nomeArquivo[MAX_FILENAME_LEN];
    int option;
    char ch;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Criar arquivo\n");
        printf("2. Editar arquivo\n");
        printf("3. Descriptografar conte�do do arquivo '%s'\n", nomeArquivo);
        printf("4. Escolher outro arquivo para descriptografar\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &option);
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch (option) {
            case 1: {
                wchar_t content[MAX_CONTENT_LEN];
                nomeAleatorio(nomeArquivo, 10);
                printf("Nome do arquivo gerado: %s\n", nomeArquivo);
                printf("Digite o conteúdo do arquivo:\n");
                fgetws(content, MAX_CONTENT_LEN, stdin);
                content[wcslen(content) - 1] = L'\0';
                criptografia(content);
                criarArquivo(nomeArquivo, content);
                break;
            }
            case 2:
                editarArquivo(nomeArquivo);
                break;
            case 3:
                lerDescriptografado(nomeArquivo);
                break;
            case 4: {
                printf("Digite o nome do arquivo que deseja descriptografar (sem extensão .txt): ");
                fgets(nomeArquivo, MAX_FILENAME_LEN, stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
                strcat(nomeArquivo, ".txt");
                lerDescriptografado(nomeArquivo);
                break;
            }
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 5);

    return 0;
}
