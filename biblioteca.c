#include <stdio.h>
#include <string.h>

struct Leitor {
    int idLeitor;
    char nome[50];
    char telefone[20];
    int livrosEmprestados;
    float multaPendente;
    int ativo;
};

struct Leitor listaLeitores[50];
int totalLeitores = 0;

// Autor: Seu Nome Completo - RGM
void moduloLeitores() {
    int opcaoLeitor;

    do {
        printf("\n--- [MODULO 1: GESTAO DE LEITORES (Integrante A)] ---\n");
        printf("1. Cadastrar Novo Leitor\n");
        printf("2. Listar / Buscar Leitores\n");
        printf("3. Editar Dados do Leitor (telefone, multa)\n");
        printf("4. Remover Leitor\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoLeitor);

        switch (opcaoLeitor) {
            case 1:
                printf("\n[Em construcao] Rotina de Cadastro de Leitor...\n");
                printf("Campos previstos: ID, Nome, Telefone, Livros Emprestados e Multa.\n");
                break;
            case 2:
                printf("\n[Em construcao] Rotina de Busca e Listagem de Leitores...\n");
                break;
            case 3:
                printf("\n[Em construcao] Rotina de Edicao de Leitor por ID...\n");
                break;
            case 4:
                printf("\n[Em construcao] Rotina de Remocao de Leitor...\n");
                break;
            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida no Modulo de Leitores!\n");
        }
    } while (opcaoLeitor != 0);
}

int main() {
    int opcaoPrincipal;

    do {
        printf("\n======================================================\n");
        printf("          BIBLIOTECA CLASSICA - TESTE DO MODULO 1       \n");
        printf("======================================================\n");
        printf("1. Modulo de Leitores (Integrante A)\n");
        printf("0. Encerrar o Sistema\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1:
                moduloLeitores();
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\n[ALERTA] Opcao invalida!\n");
        }
    } while (opcaoPrincipal != 0);

    return 0;
}