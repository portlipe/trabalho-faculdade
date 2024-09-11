//trabalho-faculdade
//Escreva um programa que simula o funcionamento de uma máquina de refrigerantes. O programa deve utilizar uma estrutura para armazenar dados sobre cada refrigerante 

#include <iostream>
#include <string>
using namespace std;

struct Refrigerante {
    string nome;
    double preco;
    int quantidade;
};

void cadastrarRefrigerantes(Refrigerante refrigerantes[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o nome do refrigerante: ";
        cin >> refrigerantes[i].nome;
        do {
            cout << "Digite o preço do refrigerante: ";
            cin >> refrigerantes[i].preco;
        } while (refrigerantes[i].preco < 0);

        do {
            cout << "Digite a quantidade disponível: ";
            cin >> refrigerantes[i].quantidade;
        } while (refrigerantes[i].quantidade < 0);
    }
}

void exibirRefrigerantes(Refrigerante refrigerantes[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (refrigerantes[i].quantidade > 0) {
            cout << i + 1 << ". " << refrigerantes[i].nome << " - R$ " << refrigerantes[i].preco << " (" << refrigerantes[i].quantidade << " disponíveis)\n";
        }
    }
}

int selecionarRefrigerante(Refrigerante refrigerantes[], int tamanho) {
    int escolha;
    do {
        cout << "Escolha um refrigerante (1 a " << tamanho << "): ";
        cin >> escolha;
    } while (escolha < 1 || escolha > tamanho || refrigerantes[escolha - 1].quantidade == 0);
    return escolha - 1;
}

double inserirDinheiro() {
    double valor;
    do {
        cout << "Insira o valor (máximo R$10,00): ";
        cin >> valor;
    } while (valor < 0 || valor > 10);
    return valor;
}

int main() {
    const int tamanho = 5;
    Refrigerante refrigerantes[tamanho];
    double totalArrecadado = 0;
    bool continuar = true;

    cadastrarRefrigerantes(refrigerantes, tamanho);

    while (continuar) {
        exibirRefrigerantes(refrigerantes, tamanho);
        int escolha = selecionarRefrigerante(refrigerantes, tamanho);
        double dinheiro = inserirDinheiro();

        if (dinheiro >= refrigerantes[escolha].preco) {
            double troco = dinheiro - refrigerantes[escolha].preco;
            cout << "Troco: R$ " << troco << endl;
            refrigerantes[escolha].quantidade--;
            totalArrecadado += refrigerantes[escolha].preco;
            if (refrigerantes[escolha].quantidade == 0) {
                cout << "O refrigerante " << refrigerantes[escolha].nome << " está esgotado.\n";
            }
        } else {
            cout << "Dinheiro insuficiente.\n";
        }

        char resposta;
        cout << "Deseja continuar? (s/n): ";
        cin >> resposta;
        if (resposta == 'n' || resposta == 'N') {
            continuar = false;
        }
    }

    cout << "Total arrecadado: R$ " << totalArrecadado << endl;

    return 0;
}

