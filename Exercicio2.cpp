#include <iostream>
#include <string>

using namespace std;


struct Empregado {
    string nome;
    string sobrenome;
    int ano_nascimento;
    string RG;
    int ano_admissao;
    double salario;
};


void Reajusta_dez_porcento(Empregado* empregados, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        empregados[i].salario *= 1.10;
    }
}

int main() {
   
    Empregado empregados[50] = {
        {"João", "Silva", 1985, "1234567", 2010, 5000.0},
        {"Maria", "Santos", 1990, "7654321", 2015, 6000.0},
        
    };

    
    Reajusta_dez_porcento(empregados, 2); 

    
    for (int i = 0; i < 2; i++) {
        cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << ", Salário: " << empregados[i].salario << " reais\n";
    }

    return 0;
}
