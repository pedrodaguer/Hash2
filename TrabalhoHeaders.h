#include <iostream>
#include <string>
using namespace std;

#define TAM 31

struct Livro
{
    int matricula;
    string Titulo;
    string Editora;
    string Autor;
    Livro *proximo;
};

struct Lista
{
    Livro *inicio;
    int tam;
};

void inicializarLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirLista(Lista *l, int matricula, string titulo, string autor, string editora)
{
    Livro *novo = new Livro;

    if (novo)
    {
        novo->matricula = matricula;
        novo->Titulo = titulo;
        novo->Autor = autor;
        novo->Editora = editora;
        novo->proximo = NULL;

        if (l->inicio == NULL)
        {
            l->inicio = novo;
        }
        else
        {
            Livro *primeiro = l->inicio;
            novo->proximo = primeiro;
            l->inicio = novo;
        }

        l->tam++;
    }
    else
    {
        cout << "\n\tErro ao alocar memória!\n";
    }
}

Livro *buscarLista(Lista *l, int matricula)
{
    Livro *aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->matricula == matricula)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void imprimirLista(Lista *l)
{
    Livro *aux = l->inicio;
    cout << " Tam(" << l->tam << "): ";
    while (aux)
    {
        cout << aux->Titulo << " | ";
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int matricula)
{
    return matricula % TAM;
}

void inserir(Lista t[], int matricula, string titulo, string autor, string editora)
{
    int id = funcaoHash(matricula);
    inserirLista(&t[id], matricula, titulo, autor, editora);
}

Livro *buscar(Lista t[], int matricula)
{
    int id = funcaoHash(matricula);
    return buscarLista(&t[id], matricula);
}

void imprimir(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        cout << i << " = ";
        imprimirLista(&t[i]);
        cout << "\n";
    }
}

struct Revista
{
    int matricula;
    string Titulo;
    string Editora;
    string Autor;
    Revista *proximo;
};

struct ListaRev
{
    Revista *inicio;
    int tam;
};

void inicializarListaRev(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirListaRev(Lista *l, int matricula, string titulo, string autor, string editora)
{
    Revista *novo = new Revista;

    if (novo)
    {
        novo->matricula = matricula;
        novo->Titulo = titulo;
        novo->Autor = autor;
        novo->Editora = editora;
        novo->proximo = NULL;

        if (l->inicio == NULL)
        {
            l->inicio = novo;
        }
        else
        {
            Revista *primeiro = l->inicio;
            novo->proximo = primeiro;
            l->inicio = novo;
        }

        l->tam++;
    }
    else
    {
        cout << "\n\tErro ao alocar memória!\n";
    }
}

Revista *buscarListaRev(Lista *l, int matricula)
{
    Revista *aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->matricula == matricula)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void imprimirListaRev(Lista *l)
{
    Revista *aux = l->inicio;
    cout << " Tam(" << l->tam << "): ";
    while (aux)
    {
        cout << aux->Titulo << " | ";
        aux = aux->proximo;
    }
}

void inicializarTabelaRev(Lista t[])
{
    for (int i = 0; i < TAM; i++)
        inicializarListaRev(&t[i]);
}

int funcaoHashRev(int matricula)
{
    return matricula % TAM;
}

void inserirRev(Lista t[], int matricula, string titulo, string autor, string editora)
{
    int id = funcaoHashRev(matricula);
    inserirListaRev(&t[id], matricula, titulo, autor, editora);
}

Revista *buscarRev(Lista t[], int matricula)
{
    int id = funcaoHashRev(matricula);
    return buscarListaRev(&t[id], matricula);
}

void imprimirRev(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        cout << i << " = ";
        imprimirListaRev(&t[i]);
        cout << "\n";
    }
}

void menu(Lista tabela[], ListaRev tabelarev[])
{
    int opcao;
    Livro l1;
    Revista r1;
    int matricula;
    string titulo, editora, autor;
    inicializarTabela(tabela);
    inicializarTabelaRev(tabelarev);
    do
    {
        cout << "\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n\t4 - Sair\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\t1 - Livro\n\t2 - Revista\n";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                cout << "\tDigite a matrícula do livro que deseja inserir: ";
                cin >> matricula;
                cout << "\tDigite o título do livro que deseja inserir: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "\tDigite a editora do livro que deseja inserir: ";
                getline(cin, editora);
                cout << "\tDigite o autor do livro que deseja inserir: ";
                getline(cin, autor);
                inserir(tabela, matricula, titulo, autor, editora);
                break;

            case 2:
                cout << "\tDigite a matrícula da revista que deseja inserir: ";
                cin >> matricula;
                cout << "\tDigite o título da revista que deseja inserir: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "\tDigite a editora da revista que deseja inserir: ";
                getline(cin, editora);
                cout << "\tDigite o autor da revista que deseja inserir: ";
                getline(cin, autor);
                inserirRev(tabelarev, matricula, titulo, autor, editora);
                break;

            default:
                break;
            }

        case 2:
            cout << "\t1 - Livro\n\t2 - Revista\n";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                cout << "\tDigite a matrícula do livro que deseja buscar: ";
                cin >> matricula;
                if (Livro *livroEncontrado = buscar(tabela, matricula))
                {
                    cout << "\tLivro encontrado!\n";
                    cout << "\tTítulo do livro: " << livroEncontrado->Titulo << "\n";
                    cout << "\tMatrícula do livro: " << livroEncontrado->matricula << "\n";
                    cout << "\tAutor do livro: " << livroEncontrado->Autor << "\n";
                    cout << "\tEditora do livro: " << livroEncontrado->Editora << "\n";
                }
                else
                {
                    cout << "\tLivro não encontrado!\n";
                }
                break;

            case 2:
                cout << "\tDigite a matrícula da revista que deseja buscar: ";
                cin >> matricula;
                if (Revista *revistaEncontrada = buscarRev(tabelarev, matricula))
                {
                    cout << "\tRevista encontrada!\n";
                    cout << "\tTítulo: " << revistaEncontrada->Titulo << "\n";
                    cout << "\tMatrícula: " << revistaEncontrada->matricula << "\n";
                    cout << "\tAutor: " << revistaEncontrada->Autor << "\n";
                    cout << "\tEditora: " << revistaEncontrada->Editora << "\n";
                }
                else
                {
                    cout << "\tRevista não encontrada!\n";
                }
                break;

            default:
                break;
            }

        case 3:
            cout << "\t1 - Livro\n\t2 - Revista\n";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                imprimir(tabela);
                break;

            case 2:
                imprimirRev(tabelarev);
                break;

            default:
                cout << "Opção inválida!\n";
            }
        }
        while (opcao != 4)
            ;
    }
}
