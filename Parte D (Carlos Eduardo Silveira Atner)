#include <stdio.h>
#include <string.h>
 
// ============================================================================
// parte D: EMPRESTIMOS E RELATORIOS
// (colar no main.c da equipe)
// ============================================================================
struct Emprestimo {
    int idEmprestimo;
    int idLeitor;
    int idLivro;
    int dias;                // dias que o livro ficou emprestado
    float multa;             // valor da multa em reais
    int devolvido;           // 1 = Devolvido, 0 = Em aberto
    char dataEmprestimo[11]; // formato dd/mm/aaaa
};
struct Emprestimo historicoEmprestimos[50];
int totalEmprestimos = 0;
int proximoIdEmprestimo = 1; // gera IDs que nunca se repetem, mesmo apos remocoes
 
// ----------------------------------------------------------------------------
// Funcao auxiliar: procura um emprestimo pelo ID.
// Retorna a posicao no vetor, ou -1 se nao encontrar.
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
int buscarEmprestimo(int id) {
    int i;
    for (i = 0; i < totalEmprestimos; i++) {
        if (historicoEmprestimos[i].idEmprestimo == id) {
            return i;
        }
    }
    return -1;
}
 
// ----------------------------------------------------------------------------
// 1. CADASTRAR: registra um novo emprestimo
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void cadastrarEmprestimo() {
    if (totalEmprestimos >= 50) {
        printf("\n[ERRO] Limite de 50 emprestimos atingido!\n");
        return;
    }
 
    struct Emprestimo novo;
 
    novo.idEmprestimo = proximoIdEmprestimo;
 
    printf("\nID do leitor: ");
    scanf("%d", &novo.idLeitor);
    printf("ID do livro: ");
    scanf("%d", &novo.idLivro);
    printf("Data do emprestimo (dd/mm/aaaa): ");
    scanf("%10s", novo.dataEmprestimo);
 
    novo.dias = 0;
    novo.multa = 0.0;
    novo.devolvido = 0;
 
    historicoEmprestimos[totalEmprestimos] = novo;
    totalEmprestimos++;
    proximoIdEmprestimo++;
 
    printf("\nEmprestimo %d registrado com sucesso!\n", novo.idEmprestimo);
}
 
// ----------------------------------------------------------------------------
// 2. LISTAR: mostra todos os emprestimos
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void listarEmprestimos() {
    int i;
 
    if (totalEmprestimos == 0) {
        printf("\nNenhum emprestimo registrado.\n");
        return;
    }
 
    printf("\n%-4s %-7s %-7s %-12s %-5s %-8s %s\n",
           "ID", "Leitor", "Livro", "Data", "Dias", "Multa", "Situacao");
    for (i = 0; i < totalEmprestimos; i++) {
        printf("%-4d %-7d %-7d %-12s %-5d R$%-6.2f %s\n",
               historicoEmprestimos[i].idEmprestimo,
               historicoEmprestimos[i].idLeitor,
               historicoEmprestimos[i].idLivro,
               historicoEmprestimos[i].dataEmprestimo,
               historicoEmprestimos[i].dias,
               historicoEmprestimos[i].multa,
               historicoEmprestimos[i].devolvido ? "Devolvido" : "Em aberto");
    }
}
 
// ----------------------------------------------------------------------------
// 3. EDITAR: registra a devolucao e calcula a multa
// Regra assumida: prazo de 7 dias, multa de R$ 0,50 por dia de atraso
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void devolverEmprestimo() {
    int id, pos, dias;
 
    printf("\nID do emprestimo: ");
    scanf("%d", &id);
 
    pos = buscarEmprestimo(id);
    if (pos == -1) {
        printf("\n[ERRO] Emprestimo nao encontrado!\n");
        return;
    }
    if (historicoEmprestimos[pos].devolvido == 1) {
        printf("\n[AVISO] Este emprestimo ja foi devolvido.\n");
        return;
    }
 
    printf("Quantos dias o livro ficou emprestado? ");
    scanf("%d", &dias);
 
    historicoEmprestimos[pos].dias = dias;
    if (dias > 7) {
        historicoEmprestimos[pos].multa = (dias - 7) * 0.50;
    } else {
        historicoEmprestimos[pos].multa = 0.0;
    }
    historicoEmprestimos[pos].devolvido = 1;
 
    printf("\nDevolucao registrada! Multa: R$ %.2f\n", historicoEmprestimos[pos].multa);
}
 
// ----------------------------------------------------------------------------
// 4. REMOVER: cancela um emprestimo (puxa os proximos uma posicao para tras)
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void cancelarEmprestimo() {
    int id, pos, i;
 
    printf("\nID do emprestimo a cancelar: ");
    scanf("%d", &id);
 
    pos = buscarEmprestimo(id);
    if (pos == -1) {
        printf("\n[ERRO] Emprestimo nao encontrado!\n");
        return;
    }
 
    for (i = pos; i < totalEmprestimos - 1; i++) {
        historicoEmprestimos[i] = historicoEmprestimos[i + 1];
    }
    totalEmprestimos--;
 
    printf("\nEmprestimo %d cancelado.\n", id);
}
 
// ----------------------------------------------------------------------------
// RELATORIO 1: livro mais emprestado
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void relatorioLivroMaisEmprestado() {
    int i, j, contagem, maior = 0, idMaior = -1;
 
    if (totalEmprestimos == 0) {
        printf("\nNenhum emprestimo registrado.\n");
        return;
    }
 
    for (i = 0; i < totalEmprestimos; i++) {
        contagem = 0;
        for (j = 0; j < totalEmprestimos; j++) {
            if (historicoEmprestimos[j].idLivro == historicoEmprestimos[i].idLivro) {
                contagem++;
            }
        }
        if (contagem > maior) {
            maior = contagem;
            idMaior = historicoEmprestimos[i].idLivro;
        }
    }
 
    printf("\nLivro mais emprestado: ID %d (%d emprestimos)\n", idMaior, maior);
}
 
// ----------------------------------------------------------------------------
// RELATORIO 2: leitor com mais emprestimos
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void relatorioLeitorMaisEmprestimos() {
    int i, j, contagem, maior = 0, idMaior = -1;
 
    if (totalEmprestimos == 0) {
        printf("\nNenhum emprestimo registrado.\n");
        return;
    }
 
    for (i = 0; i < totalEmprestimos; i++) {
        contagem = 0;
        for (j = 0; j < totalEmprestimos; j++) {
            if (historicoEmprestimos[j].idLeitor == historicoEmprestimos[i].idLeitor) {
                contagem++;
            }
        }
        if (contagem > maior) {
            maior = contagem;
            idMaior = historicoEmprestimos[i].idLeitor;
        }
    }
 
    printf("\nLeitor com mais emprestimos: ID %d (%d emprestimos)\n", idMaior, maior);
}
 
// ----------------------------------------------------------------------------
// RELATORIO 3: emprestimos de um leitor especifico
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void relatorioEmprestimosDoLeitor() {
    int id, i, achou = 0;
 
    printf("\nID do leitor: ");
    scanf("%d", &id);
 
    printf("\n--- Emprestimos do leitor %d ---\n", id);
    for (i = 0; i < totalEmprestimos; i++) {
        if (historicoEmprestimos[i].idLeitor == id) {
            printf("Emprestimo %d | Livro %d | %s | %s\n",
                   historicoEmprestimos[i].idEmprestimo,
                   historicoEmprestimos[i].idLivro,
                   historicoEmprestimos[i].dataEmprestimo,
                   historicoEmprestimos[i].devolvido ? "Devolvido" : "Em aberto");
            achou = 1;
        }
    }
 
    if (achou == 0) {
        printf("Nenhum emprestimo encontrado para este leitor.\n");
    }
}
 
// ----------------------------------------------------------------------------
// RELATORIO 4: emprestimos em aberto e total de multas
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void relatorioEmAbertoEMultas() {
    int i, abertos = 0;
    float totalMultas = 0.0;
 
    printf("\n--- Emprestimos em aberto ---\n");
    for (i = 0; i < totalEmprestimos; i++) {
        if (historicoEmprestimos[i].devolvido == 0) {
            printf("Emprestimo %d | Leitor %d | Livro %d | %s\n",
                   historicoEmprestimos[i].idEmprestimo,
                   historicoEmprestimos[i].idLeitor,
                   historicoEmprestimos[i].idLivro,
                   historicoEmprestimos[i].dataEmprestimo);
            abertos++;
        }
        totalMultas = totalMultas + historicoEmprestimos[i].multa;
    }
 
    if (abertos == 0) {
        printf("Nenhum emprestimo em aberto.\n");
    }
    printf("\nTotal de multas cobradas: R$ %.2f\n", totalMultas);
}
 
// ----------------------------------------------------------------------------
// MODULO 4: SUBMENU DE EMPRESTIMOS E RELATORIOS
// Autor: Carlos Eduardo Silveira Atner 49572911
// ----------------------------------------------------------------------------
void moduloEmprestimosRelatorios() {
    int opcaoEmprestimo;
    do {
        printf("\n--- [MODULO 4: EMPRESTIMOS E RELATORIOS (Carlos Eduardo Silveira Atner)] ---\n");
        printf("1. Registrar Novo Emprestimo (Cruza Leitor + Livro)\n");
        printf("2. Listar / Buscar Emprestimos\n");
        printf("3. Registrar Devolucao / Editar Emprestimo\n");
        printf("4. Cancelar Emprestimo\n");
        printf("5. [RELATORIO] Livro Mais Emprestado\n");
        printf("6. [RELATORIO] Leitor com Mais Emprestimos\n");
        printf("7. [RELATORIO] Emprestimos de um Leitor Especifico\n");
        printf("8. [RELATORIO] Emprestimos em Aberto e Multas\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoEmprestimo);
 
        switch (opcaoEmprestimo) {
            case 1:
                cadastrarEmprestimo();
                break;
            case 2:
                listarEmprestimos();
                break;
            case 3:
                devolverEmprestimo();
                break;
            case 4:
                cancelarEmprestimo();
                break;
            case 5:
                relatorioLivroMaisEmprestado();
                break;
            case 6:
                relatorioLeitorMaisEmprestimos();
                break;
            case 7:
                relatorioEmprestimosDoLeitor();
                break;
            case 8:
                relatorioEmAbertoEMultas();
                break;
            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida no Modulo de Emprestimos!\n");
        }
    } while (opcaoEmprestimo != 0);
}
 
// ============================================================================
// MAIN DE TESTE - NAO copiar para o main.c do grupo.
// ============================================================================
int main() {
    moduloEmprestimosRelatorios();
    return 0;
}
