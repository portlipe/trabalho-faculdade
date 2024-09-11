/*Escreva um programa que utiliza uma estrutura para armazenar informações sobre uma conta de cliente
O programa deve utilizar um array contendo, no mínimo, 10 estruturas de contas de clientes e oferecer uma interface de usuário baseada em menus que permita ao usuário: 
(a) Adicionar uma nova conta de cliente. 
(b) Remover uma conta existente. 
(c) Listar todas as contas cadastradas. 
(d) Imprimir todos os dados de um cliente específico. 
(e) Atualizar os dados de uma conta de cliente.*/

#include <iostream>
#include <string>
using namespace std;

struct Endereco {
    string cidade;
    string estado;
    string cep;
};

struct ContaCliente {
    string nome;
    string cpf;
    Endereco endereco;
    string telefone;
    double saldo;
};

void adicionarConta(ContaCliente contas[], int &total) {
    if (total >= 10) {
        cout << "Limite de contas atingido.\n";
        return;
    }
    
    ContaCliente novaConta;
    cin.ignore();  
    cout << "Digite o nome do cliente: ";
    getline(cin, novaConta.nome);
    
    cout << "Digite o CPF do cliente: ";
    cin >> novaConta.cpf;
    
    cin.ignore();  
    cout << "Digite a cidade: ";
    getline(cin, novaConta.endereco.cidade);
    
    cout << "Digite o estado: ";
    getline(cin, novaConta.endereco.estado);
    
    cout << "Digite o CEP: ";
    cin >> novaConta.endereco.cep;
    
    cout << "Digite o telefone de contato: ";
    cin >> novaConta.telefone;
    
    do {
        cout << "Digite o saldo inicial (não pode ser negativo): ";
        cin >> novaConta.saldo;
    } while (novaConta.saldo < 0);

    contas[total] = novaConta;
    total++;
}

void removerConta(ContaCliente contas[], int &total, string cpf) {
    for (int i = 0; i < total; i++) {
        if (contas[i].cpf == cpf) {
            for (int j = i; j < total - 1; j++) {
                contas[j] = contas[j + 1];
            }
            total--;
            cout << "Conta removida.\n";
            return;
        }
    }
    cout << "Conta não encontrada.\n";
}

void listarContas(ContaCliente contas[], int total) {
    if (total == 0) {
        cout << "Nenhuma conta cadastrada.\n";
        return;
    }
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << contas[i].nome << " - CPF: " << contas[i].cpf << "\n";
    }
}

void imprimirDados(ContaCliente contas[], int total, string cpf) {
    for (int i = 0; i < total; i++) {
        if (contas[i].cpf == cpf) {
            cout << "Nome: " << contas[i].nome << "\n";
            cout << "CPF: " << contas[i].cpf << "\n";
            cout << "Cidade: " << contas[i].endereco.cidade << "\n";
            cout << "Estado: " << contas[i].endereco.estado << "\n";
            cout << "CEP: " << contas[i].endereco.cep << "\n";
            cout << "Telefone: " << contas[i].telefone << "\n";
            cout << "Saldo: R$ " << contas[i].saldo << "\n";
            return;
        }
    }
    cout << "Conta não encontrada.\n";
}

void atualizarConta(ContaCliente contas[], int total, string cpf) {
    for (int i = 0; i < total; i++) {
        if (contas[i].cpf == cpf) {
            cin.ignore();
            cout << "Digite o novo nome: ";
            getline(cin, contas[i].nome);
            
            cout << "Digite a nova cidade: ";
            getline(cin, contas[i].endereco.cidade);
            
            cout << "Digite o novo estado: ";
            getline(cin, contas[i].endereco.estado);
            
            cout << "Digite o novo CEP: ";
            cin >> contas[i].endereco.cep;
            
            cout << "Digite o novo telefone: ";
            cin >> contas[i].telefone;
            
            do {
                cout << "Digite o novo saldo (não pode ser negativo): ";
                cin >> contas[i].saldo;
            } while (contas[i].saldo < 0);
            return;
        }
    }
    cout << "Conta não encontrada.\n";
}

int main() {
    ContaCliente contas[10];
    int totalContas = 0;
    int opcao;
    string cpf;

    do {
        cout << "\n1. Adicionar conta\n2. Remover conta\n3. Listar contas\n4. Imprimir dados de um cliente\n5. Atualizar conta\n0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarConta(contas, totalContas);
                break;
            case 2:
                cout << "Digite o CPF da conta a ser removida: ";
                cin >> cpf;
                removerConta(contas, totalContas, cpf);
                break;
            case 3:
                listarContas(contas, totalContas);
                break;
            case 4:
                cout << "Digite o CPF do cliente: ";
                cin >> cpf;
                imprimirDados(contas, totalContas, cpf);
                break;
            case 5:
                cout << "Digite o CPF da conta a ser atualizada: ";
                cin >> cpf;
                atualizarConta(contas, totalContas, cpf);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
