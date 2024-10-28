#include <stdio.h>
#include "db.h"

void cadastrarPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[])
{
    int validar = 0;
    char op;
    Pessoa pessoa;
    pessoa.matricula = *quantidade + 1;
    pessoa.ativa = 1;
    pessoa.qtdMaterias = 0;

    while (!validar && op != 'n')
    {
        limparTela();
        op = 'a'; // Essa atribuição existe somente para o caso de existir lixo em tipos CHARS. (Evitar erro no while)

        printf("\tCADASTRO DE %s", tipo);
        printf("\n--------------------------------------\n");
        printf("Informe o nome: ");
        fgets(pessoa.nome, tam, stdin);
        printf("Informe o cpf (somente numeros): ");
        fgets(pessoa.cpf, TAM_CPF, stdin);
        printf("Informe a data de nascimento: ");
        pessoa.data = inserirData();
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &pessoa.sexo);
        printf("\n--------------------------------------\n");

        toUpper(pessoa.nome);
        tratarStr(pessoa.nome);
        charToUpper(&pessoa.sexo);

        setbuf(stdin, NULL);

        int cpfCadastrado = buscarPessoaPorCPF(lstPessoa, *quantidade, pessoa.cpf);
        
        
        if (validarCPF(pessoa.cpf) && validarData(pessoa.data) && validarSexo(pessoa.sexo) && cpfCadastrado == -1)
        {
            validar = 1;
            limparTela();
            printf("NOVO %s CADASTRADO", tipo);
            mostrarPessoa(pessoa);
            esperarEnter();
        }
        else
        {
            if(cpfCadastrado != -1) 
            {
                printf("\nJá existe um cadastro com esse CPF.\n");
            }
            else 
            {
                printf("\nAlguma informacao incorreta.\n");
                mostrarPessoa(pessoa);
            }

            printf("Deseja tentar realizar o cadastro novamente? (s/n)\n");

            while (op != 's' && op != 'n')
            {
                scanf(" %c", &op);
            }
            limparBuffer();
        }
    }

    if (op != 'n')
    {
        lstPessoa[*quantidade] = pessoa;
        *quantidade += 1;
    }

    return;
}

void atualizarPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[])
{
    int validar = 0;
    char op = 'a';
    char cpf[TAM_CPF];
    limparTela();
    printf("Informe o CPF do cadastrado que deseja alterar: ");
    fgets(cpf, TAM_CPF, stdin);
    int posicao;
    posicao = buscarPessoaPorCPF(lstPessoa, *quantidade, cpf);

    if(posicao < 0)
    {
        printf("\nEsse usuario nao foi encontrado.\n");
        esperarEnter();
    }
    else
    {
        limparTela();
        mostrarPessoa(lstPessoa[posicao]);
        printf("\n Deseja mesmo atualizar esse cadastro? (s/n)\n");
        while (op != 's' && op != 'n')
            op = getchar();
    }

    if (posicao >= 0 && op == 's')
    {
        Pessoa pessoa = lstPessoa[posicao];

        while (!validar && op != 'n')
        {
            limparTela();
            limparBuffer();

            mostrarPessoa(pessoa);

            printf("ATUALIZAR %s", tipo);
            printf("Informe o nome: ");
            fgets(pessoa.nome, tam, stdin);
            printf("Informe a data de nascimento: ");
            pessoa.data = inserirData();
            printf("Informe o sexo (M/F): ");
            scanf(" %c", &pessoa.sexo);
            pessoa.qtdMaterias = 0;

            if (validarData(pessoa.data) && validarSexo(pessoa.sexo))
            {
                validar = 1;
            }
            else
            {
                limparBuffer();
                printf("Alguma informacao incorreta.\n");
                printf("Deseja tentar atualizar o cadastrado novamente? (s/n)\n");
                while (op != 's' && op != 'n')
                    op = getchar();
            }
            limparBuffer();
        }

        if (op != 'n')
            lstPessoa[*quantidade] = pessoa;
    }
}

void excluirPessoa(Pessoa lstPessoa[], int *quantidade, char tipo[]) 
{
    
    int posicao;
    char cpf[TAM_CPF];
    char op = '0';
    limparTela();
    printf("Informe o CPF do cadastro que deseja desativar: ");
    fgets(cpf, TAM_CPF, stdin);

    posicao = buscarPessoaPorCPF(lstPessoa, *quantidade, cpf);
    if(posicao < 0)
    {
        printf("\nEsse usuario nao foi encontrado.");
    }
    else
    {
        limparTela();
        printf("EXCLUIR %s", tipo);
        mostrarPessoa(lstPessoa[posicao]);
        printf("\nDeseja mesmo excluir esse cadastro? (s/n)\n");
        while (op != 's' && op != 'n')
            scanf(" %c", &op);
    }

    limparBuffer();

    if(posicao >= 0 && op == 's')
    {
        limparTela();
        lstPessoa[posicao].ativa = 0;
        printf("Cadastro excluido.");
        ordenandoPessoasAtivas(lstPessoa, *quantidade);
        *quantidade -= 1;
    }

    esperarEnter();
}

void listarPessoasOrdenadasPorSexo(Pessoa lstPessoa[], int quantidade, char ordem) {
    Pessoa pessoas[quantidade];
    copiarArrayDePessoas(lstPessoa, pessoas, quantidade);
    ordenandoPessoasPorSexo(pessoas, quantidade, ordem);
    mostrarPessoas(pessoas, quantidade);
}

void listarPessoasOrdenadasPorNome(Pessoa lstPessoa[], int quantidade) {
    Pessoa pessoas[quantidade];
    copiarArrayDePessoas(lstPessoa, pessoas, quantidade);
    ordenandoPessoasPorNome(pessoas, quantidade);
    mostrarPessoas(pessoas, quantidade);
}
void listarPessoasOrdenadasPorData(Pessoa lstPessoa[], int quantidade, char ordem);