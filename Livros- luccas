// ============================================================================
// Arquivo: livros.h | MODULO: ACERVO DE LIVROS
// Autor: Integrante B Luccas
// ============================================================================
#ifndef LIVROS_H
#define LIVROS_H

#include <stdio.h>
#include <string.h>

// Struct no escopo global (7 campos: int, char[], float)
struct Livro {
    int id;
    char titulo[60];
    char autor[50];
    int ano;
    float valor;
    int exemplares;
    int ativo; // 1 = Ativo, 0 = Removido
};

struct Livro acervo[50];
int totalLivros = 0;

// Grava (ou regrava) todo o vetor no arquivo livros.csv
// Autor: Integrante B Luccas
void salvarLivrosCSV() {
    int i;
    FILE *arq = fopen("livros.csv", "w"); // modo "w" zera o arquivo e regrava tudo
    if (arq == NULL) {
        printf("[ERRO] Nao foi possivel gravar livros.csv!\n");
        return;
    }
    for (i = 0; i < totalLivros; i++) {
        fprintf(arq, "%d;%s;%s;%d;%.2f;%d;%d\n",
                acervo[i].id, acervo[i].titulo, acervo[i].autor,
                acervo[i].ano, acervo[i].valor, acervo[i].exemplares,
                acervo[i].ativo);
    }
    fclose(arq);
}

// Carrega os livros do arquivo livros.csv ao abrir o programa
// Autor: Integrante B Luccas
void carregarLivrosCSV() {
    FILE *arq = fopen("livros.csv", "r");
    if (arq == NULL) return; // se o arquivo ainda nao existe, comeca com 0 registros

    totalLivros = 0;
    while (totalLivros < 50 &&
           fscanf(arq, "%d;%59[^;];%49[^;];%d;%f;%d;%d\n",
                  &acervo[totalLivros].id,
                  acervo[totalLivros].titulo,
                  acervo[totalLivros].autor,
                  &acervo[totalLivros].ano,
                  &acervo[totalLivros].valor,
                  &acervo[totalLivros].exemplares,
                  &acervo[totalLivros].ativo) == 7) {
        totalLivros++;
    }
    fclose(arq);
}

// Procura um livro ATIVO pelo id. Retorna a posicao no vetor ou -1 se nao achar.
// Autor: Integrante B Luccas
int buscarIndiceLivro(int idProcurado) {
    int i;
    for (i = 0; i < totalLivros; i++) {
        if (acervo[i].id == idProcurado && acervo[i].ativo == 1) {
            return i;
        }
    }
    return -1;
}

// Autor: Integrante B Luccas
void cadastrarLivro() {
    if (totalLivros >= 50) {
        printf("\n[ERRO] Acervo cheio (maximo de 50 livros)!\n");
        return;
    }

    acervo[totalLivros].id = totalLivros + 1; // ID automatico

    printf("\n--- CADASTRAR LIVRO (ID %d) ---\n", acervo[totalLivros].id);
    printf("Titulo: ");
    scanf(" %59[^\n]", acervo[totalLivros].titulo);
    printf("Autor: ");
    scanf(" %49[^\n]", acervo[totalLivros].autor);
    printf("Ano de publicacao: ");
    scanf("%d", &acervo[totalLivros].ano);
    printf("Valor (R$): ");
    scanf("%f", &acervo[totalLivros].valor);
    printf("Numero de exemplares: ");
    scanf("%d", &acervo[totalLivros].exemplares);
    acervo[totalLivros].ativo = 1;

    totalLivros++;
    salvarLivrosCSV();
    printf("\nLivro cadastrado com sucesso!\n");
}

// Autor: Integrante B Luccas
void listarLivros() {
    int i, encontrou = 0;

    printf("\n--- ACERVO DE LIVROS ---\n");
    printf("%-4s %-30s %-20s %-6s %-9s %-5s\n",
           "ID", "Titulo", "Autor", "Ano", "Valor", "Exem.");
    for (i = 0; i < totalLivros; i++) {
        if (acervo[i].ativo == 1) {
            printf("%-4d %-30s %-20s %-6d R$%-7.2f %-5d\n",
                   acervo[i].id, acervo[i].titulo, acervo[i].autor,
                   acervo[i].ano, acervo[i].valor, acervo[i].exemplares);
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhum livro cadastrado.\n");
    }
}

// Autor: Integrante B Luccas
void buscarLivroPorTitulo() {
    char termo[60];
    int i, encontrou = 0;

    printf("\nDigite parte do titulo: ");
    scanf(" %59[^\n]", termo);

    printf("\n--- RESULTADO DA BUSCA ---\n");
    for (i = 0; i < totalLivros; i++) {
        if (acervo[i].ativo == 1 && strstr(acervo[i].titulo, termo) != NULL) {
            printf("ID %d | %s | %s | %d | R$%.2f | %d exemplar(es)\n",
                   acervo[i].id, acervo[i].titulo, acervo[i].autor,
                   acervo[i].ano, acervo[i].valor, acervo[i].exemplares);
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhum livro encontrado com esse titulo.\n");
    }
}

// Autor: Integrante B Luccas
void editarLivro() {
    int idEdicao, pos;

    printf("\nDigite o ID do livro a editar: ");
    scanf("%d", &idEdicao);

    pos = buscarIndiceLivro(idEdicao);
    if (pos == -1) {
        printf("\n[ERRO] Livro nao encontrado!\n");
        return;
    }

    printf("\nEditando: %s\n", acervo[pos].titulo);
    printf("Novo titulo: ");
    scanf(" %59[^\n]", acervo[pos].titulo);
    printf("Novo autor: ");
    scanf(" %49[^\n]", acervo[pos].autor);
    printf("Novo ano: ");
    scanf("%d", &acervo[pos].ano);
    printf("Novo valor (R$): ");
    scanf("%f", &acervo[pos].valor);
    printf("Novo numero de exemplares: ");
    scanf("%d", &acervo[pos].exemplares);

    salvarLivrosCSV();
    printf("\nLivro atualizado com sucesso!\n");
}

// Autor: Integrante B Luccas
void removerLivro() {
    int idRemocao, pos;

    printf("\nDigite o ID do livro a remover: ");
    scanf("%d", &idRemocao);

    pos = buscarIndiceLivro(idRemocao);
    if (pos == -1) {
        printf("\n[ERRO] Livro nao encontrado!\n");
        return;
    }

    acervo[pos].ativo = 0; // remocao logica (o registro continua no vetor)
    salvarLivrosCSV();
    printf("\nLivro \"%s\" removido do acervo.\n", acervo[pos].titulo);
}

// Submenu do modulo (chamado pelo menu principal)
// Autor: Integrante B (Nome Completo e RGM)
void moduloAcervo() {
    int opcaoLivro;
    do {
        printf("\n--- [MODULO 2: ACERVO DE LIVROS (Integrante B)] ---\n");
        printf("1. Cadastrar Novo Livro\n");
        printf("2. Listar Acervo\n");
        printf("3. Buscar Livro por Titulo\n");
        printf("4. Editar Livro\n");
        printf("5. Remover Livro\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoLivro);

        switch (opcaoLivro) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                listarLivros();
                break;
            case 3:
                buscarLivroPorTitulo();
                break;
            case 4:
                editarLivro();
                break;
            case 5:
                removerLivro();
                break;
            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida no Modulo de Acervo!\n");
        }
    } while (opcaoLivro != 0);
}

#endif
