#include <stdio.h>
#include <string.h>

// ############################################################################
// PARTE A: FICHARIO DE LEITORES (MODULO 1)
// ############################################################################

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

// Autor: Lucas Bozek - RGM
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

// ############################################################################
// PARTE B: ACERVO DE LIVROS (MODULO 2)
// ############################################################################

// ============================================================================
// MODULO: ACERVO DE LIVROS
// Autor: Integrante B Luccas
// ============================================================================

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

// ############################################################################
// PARTE C: CATALOGO DE AUTORES (MODULO 3)
// ############################################################################

// ----------------------------------------------------------------------------
// MODULO 3: CATALOGO DE AUTORES CLASSICOS
// Autor: Nicolas Henrique da Silva Honorio (RGM: ____________)
// ----------------------------------------------------------------------------

struct Autor {
    int idAutor;
    char nome[50];
    char nacionalidade[30];
    int anoNascimento;
    char obraMaisFamosa[60];
    int ativo;
};

struct Autor catalogoAutores[50];
int totalAutores = 0;

int buscarIndiceAutor(int id) {
    int i;
    for (i = 0; i < totalAutores; i++) {
        if (catalogoAutores[i].idAutor == id && catalogoAutores[i].ativo == 1) {
            return i;
        }
    }
    return -1;
}

void exibirAutor(int i) {
    printf("ID: %d\n", catalogoAutores[i].idAutor);
    printf("Nome: %s\n", catalogoAutores[i].nome);
    printf("Nacionalidade: %s\n", catalogoAutores[i].nacionalidade);
    printf("Ano de nascimento: %d\n", catalogoAutores[i].anoNascimento);
    printf("Obra mais famosa: %s\n", catalogoAutores[i].obraMaisFamosa);
    printf("------------------------------------\n");
}

void cadastrarAutor() {
    if (totalAutores >= 50) {
        printf("\n[ERRO] Catalogo cheio! Limite de 50 autores atingido.\n");
        return;
    }

    catalogoAutores[totalAutores].idAutor = totalAutores + 1;

    printf("\n--- CADASTRO DE AUTOR ---\n");
    printf("Nome: ");
    scanf(" %49[^\n]", catalogoAutores[totalAutores].nome);
    printf("Nacionalidade: ");
    scanf(" %29[^\n]", catalogoAutores[totalAutores].nacionalidade);
    printf("Ano de nascimento: ");
    scanf("%d", &catalogoAutores[totalAutores].anoNascimento);
    printf("Obra mais famosa: ");
    scanf(" %59[^\n]", catalogoAutores[totalAutores].obraMaisFamosa);

    catalogoAutores[totalAutores].ativo = 1;

    printf("\nAutor cadastrado com sucesso! ID gerado: %d\n",
           catalogoAutores[totalAutores].idAutor);
    totalAutores++;
}

void listarOuBuscarAutores() {
    int escolha, i, id, encontrou;

    printf("\n1. Listar todos os autores\n");
    printf("2. Buscar autor por ID\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        encontrou = 0;
        printf("\n--- AUTORES CADASTRADOS ---\n");
        for (i = 0; i < totalAutores; i++) {
            if (catalogoAutores[i].ativo == 1) {
                exibirAutor(i);
                encontrou = 1;
            }
        }
        if (encontrou == 0) {
            printf("Nenhum autor cadastrado.\n");
        }
    } else if (escolha == 2) {
        printf("Digite o ID do autor: ");
        scanf("%d", &id);
        i = buscarIndiceAutor(id);
        if (i == -1) {
            printf("\nAutor com ID %d nao encontrado.\n", id);
        } else {
            printf("\n");
            exibirAutor(i);
        }
    } else {
        printf("\n[ERRO] Opcao invalida!\n");
    }
}

void editarAutor() {
    int id, i, campo;

    printf("\nDigite o ID do autor que deseja editar: ");
    scanf("%d", &id);
    i = buscarIndiceAutor(id);

    if (i == -1) {
        printf("\nAutor com ID %d nao encontrado.\n", id);
        return;
    }

    printf("\nDados atuais:\n");
    exibirAutor(i);

    printf("Qual campo deseja alterar?\n");
    printf("1. Nome\n");
    printf("2. Nacionalidade\n");
    printf("3. Ano de nascimento\n");
    printf("4. Obra mais famosa\n");
    printf("0. Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &campo);

    switch (campo) {
        case 1:
            printf("Novo nome: ");
            scanf(" %49[^\n]", catalogoAutores[i].nome);
            printf("\nNome atualizado!\n");
            break;
        case 2:
            printf("Nova nacionalidade: ");
            scanf(" %29[^\n]", catalogoAutores[i].nacionalidade);
            printf("\nNacionalidade atualizada!\n");
            break;
        case 3:
            printf("Novo ano de nascimento: ");
            scanf("%d", &catalogoAutores[i].anoNascimento);
            printf("\nAno atualizado!\n");
            break;
        case 4:
            printf("Nova obra mais famosa: ");
            scanf(" %59[^\n]", catalogoAutores[i].obraMaisFamosa);
            printf("\nObra atualizada!\n");
            break;
        case 0:
            printf("\nEdicao cancelada.\n");
            break;
        default:
            printf("\n[ERRO] Opcao invalida!\n");
    }
}

void removerAutor() {
    int id, i;
    char confirmacao;

    printf("\nDigite o ID do autor que deseja remover: ");
    scanf("%d", &id);
    i = buscarIndiceAutor(id);

    if (i == -1) {
        printf("\nAutor com ID %d nao encontrado.\n", id);
        return;
    }

    printf("\nVoce vai remover:\n");
    exibirAutor(i);
    printf("Confirma a remocao? (s/n): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 's' || confirmacao == 'S') {
        catalogoAutores[i].ativo = 0;
        printf("\nAutor removido com sucesso!\n");
    } else {
        printf("\nRemocao cancelada.\n");
    }
}

void moduloAutores() {
    int opcaoAutor;
    do {
        printf("\n--- [MODULO 3: CATALOGO DE AUTORES (Integrante C)] ---\n");
        printf("1. Cadastrar Novo Autor\n");
        printf("2. Listar / Buscar Autores\n");
        printf("3. Editar Dados de Autor\n");
        printf("4. Remover Autor\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoAutor);

        switch (opcaoAutor) {
            case 1:
                cadastrarAutor();
                break;
            case 2:
                listarOuBuscarAutores();
                break;
            case 3:
                editarAutor();
                break;
            case 4:
                removerAutor();
                break;
            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida no Modulo de Autores!\n");
        }
    } while (opcaoAutor != 0);
}

// ############################################################################
// PARTE D: EMPRESTIMOS E RELATORIOS (MODULO 4)
// ############################################################################

// ============================================================================
// parte D: EMPRESTIMOS E RELATORIOS
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

    // Confere se o livro existe e esta ativo no acervo (funcao do modulo B)
    if (buscarIndiceLivro(novo.idLivro) == -1) {
        printf("\n[ERRO] Livro com ID %d nao encontrado no acervo! Emprestimo nao registrado.\n", novo.idLivro);
        return;
    }

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

// ############################################################################
// PARTE FINAL: CABECALHO COMUM E FUNCAO PRINCIPAL (MAIN) - DESPACHANTE DE MENUS
// ############################################################################

// Funcao visual comum da equipe
// Autor: Equipe (todos os integrantes)
void exibirCabecalho() {
    printf("\n======================================================\n");
    printf("   BIBLIOTECA CLASSICA - SISTEMA DE GESTAO DE ACERVO   \n");
    printf("======================================================\n");
}

// Autor: Equipe (todos os integrantes)
int main() {
    int opcaoPrincipal;

    do {
        exibirCabecalho();
        printf("SELECIONE A PERSPECTIVA DO SISTEMA:\n");
        printf("1. Modulo de Leitores / Fichario (Integrante A)\n");
        printf("2. Modulo de Livros / Acervo (Integrante B)\n");
        printf("3. Modulo de Autores (Integrante C)\n");
        printf("4. Modulo de Emprestimos e Relatorios (Integrante D)\n");
        printf("0. Encerrar o Sistema\n");
        printf("------------------------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1:
                moduloLeitores();
                break;
            case 2:
                moduloAcervo();
                break;
            case 3:
                moduloAutores();
                break;
            case 4:
                moduloEmprestimosRelatorios();
                break;
            case 0:
                printf("\nEncerrando o sistema da Biblioteca Classica... Ate logo!\n");
                break;
            default:
                printf("\n[ALERTA] Opcao invalida! Digite um numero de 0 a 4.\n");
        }
    } while (opcaoPrincipal != 0);

    return 0;
}
