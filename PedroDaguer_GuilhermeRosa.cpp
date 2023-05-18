#include <iostream>
#include <locale.h>
#include "TrabalhoHeaders.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Lista tabela[TAM];
    ListaRev tabelarev[TAM];
    menu(tabela, tabelarev);
    return 0;
}
