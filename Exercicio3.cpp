#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Produto {
public:
    string codigo;
    string nome;
    double preco;
};

void cadastrarProduto(vector<Produto>& produtos, string codigo, string nome, double preco) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo || produto.nome == nome) {
            cout << "Produto já cadastrado com o mesmo código ou nome." << endl;
            return;
        }
    }

    Produto novoProduto = {codigo, nome, preco};
    produtos.push_back(novoProduto);
    cout << "Produto '" << nome << "' cadastrado com sucesso!" << endl;
}

void excluirProduto(vector<Produto>& produtos, string codigo) {
    auto it = remove_if(produtos.begin(), produtos.end(), [codigo](const Produto& produto) {
        return produto.codigo == codigo;
    });

    if (it != produtos.end()) {
        produtos.erase(it, produtos.end());
        cout << "Produto removido com sucesso!" << endl;
    } else {
        cout << "Produto não encontrado." << endl;
    }
}

void listarProdutos(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }

    cout << left << setw(15) << "Código" << setw(25) << "Nome" << "Preço" << endl;
    for (const Produto& produto : produtos) {
        cout << left << setw(15) << produto.codigo << setw(25) << produto.nome << fixed << setprecision(2) << produto.preco << endl;
    }
}

void consultarPreco(const vector<Produto>& produtos, string codigo) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo) {
            cout << "O preço do produto '" << produto.nome << "' é R$" << fixed << setprecision(2) << produto.preco << "." << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    vector<Produto> produtos;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Inserir novo produto" << endl;
        cout << "2. Excluir produto" << endl;
        cout << "3. Listar produtos" << endl;
        cout << "4. Consultar preço" << endl;
        cout << "0. Sair" << endl;

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            string codigo, nome;
            double preco;
            cout << "Digite o código do produto (13 caracteres): ";
            cin >> codigo;
            cout << "Digite o nome do produto (máximo 20 caracteres): ";
            cin >> nome;
            cout << "Digite o preço do produto (duas casas decimais): ";
            cin >> preco;
            cadastrarProduto(produtos, codigo, nome, preco);
        } else if (opcao == 2) {
            string codigo;
            cout << "Digite o código do produto a ser excluído: ";
            cin >> codigo;
            excluirProduto(produtos, codigo);
        } else if (opcao == 3) {
            listarProdutos(produtos);
        } else if (opcao == 4) {
            string codigo;
            cout << "Digite o código do produto para consultar o preço: ";
            cin >> codigo;
            consultarPreco(produtos, codigo);
        } else if (opcao == 0) {
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
