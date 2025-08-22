#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-- Constantes GLOBAIS

#define MAX_STRINGS 50


//-- Criando STRUCT
struct territorio{
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//-- Funcao Principal Main
int main(){
    struct territorio biblioteca[MAX_STRINGS];
    int totalTerritorio = 0;

    // -- Laço principal do menu
    do{
         // Exibe o menu de cadastro
        printf("\n======================================\n");
        printf("  WAR ESTRUTURADO - CADASTRO INICIAL  ");
        printf("\n======================================\n");
        printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");
        for ( totalTerritorio = 0; totalTerritorio <= 4; totalTerritorio++ ){

            printf("--- Cadastrando territorio %d ---\n", totalTerritorio + 1);
            printf("Nome do territorio: ");
            fgets(biblioteca[totalTerritorio].nome, MAX_STRINGS, stdin);

            printf("Cor do exercito (ex: Azul, Verde): ");
            fgets(biblioteca[totalTerritorio].cor, MAX_STRINGS, stdin);

            biblioteca[totalTerritorio].nome[strcspn(biblioteca[totalTerritorio].nome, "\n")];
            biblioteca[totalTerritorio].cor[strcspn(biblioteca[totalTerritorio].cor, "\n")];

            printf("Numero de tropas: ");
            scanf("%d", &biblioteca[totalTerritorio].tropas);
            printf("\n");
            limparBufferEntrada(); // Limpa  o 'n' deixado pelo scanf.


        }; 

        //LISTAGEM DE TERRITORIOS:

         printf("\n========================================\n");
         printf("     MAPA DO MUNDO - ESTADO ATUAL");
         printf("\n========================================\n");

         for (totalTerritorio = 0; totalTerritorio <= 4; totalTerritorio++) {
            printf("\n");
            printf("TERRITORIO %d:\n", totalTerritorio + 1);
            printf("- Nome: %s", biblioteca[totalTerritorio].nome);
            printf("- Dominado por: Exercito %s", biblioteca[totalTerritorio].cor);
            printf("- Tropas: %d\n", biblioteca[totalTerritorio].tropas);
            printf("\n");
         }; 

        printf("\nCadastro inicial feito com sucesso!\n");
    
    } while (totalTerritorio<=4); // Condição pra o programa seja executado!

    return 0; // Fim do programa
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
