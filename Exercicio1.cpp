#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Passagem {
public:
    int assento;
    string data_hora;
    string cpf;
    string nome;
    int idade;

    Passagem(int a, string dh, string c, string n, int i) : assento(a), data_hora(dh), cpf(c), nome(n), idade(i) {}
};

class Viagem {
public:
    int numero;
    string partida;
    string chegada;
    vector<Passagem> passagens_vendidas;

    Viagem(int num, string part, string cheg) : numero(num), partida(part), chegada(cheg) {}

    void vender_passagem(int assento, string data_hora, string cpf, string nome, int idade) {
        passagens_vendidas.push_back(Passagem(assento, data_hora, cpf, nome, idade));
    }

    int total_arrecadado() {
        return passagens_vendidas.size() * 80;
    }

    string passageiro_por_assento(int assento) {
        for (const auto& passagem : passagens_vendidas) {
            if (passagem.assento == assento) {
                return passagem.nome;
            }
        }
        return "Assento não ocupado.";
    }
};

class EmpresaOnibus {
public:
    vector<Viagem> viagens;

    Viagem& nova_viagem(int numero, string partida, string chegada) {
        viagens.push_back(Viagem(numero, partida, chegada));
        return viagens.back();
    }

    int arrecadado_mes(int mes) {
        int total = 0;
        for (const auto& viagem : viagens) {
            for (const auto& passagem : viagem.passagens_vendidas) {
                if (stoi(passagem.data_hora.substr(5, 2)) == mes) {
                    total += 80;
                }
            }
        }
        return total;
    }

    Viagem& horario_mais_rentavel() {
        int max_arrecadado = -1;
        Viagem* viagem_rentavel = nullptr;

        for (auto& viagem : viagens) {
            int arrecadado = viagem.total_arrecadado();
            if (arrecadado > max_arrecadado) {
                max_arrecadado = arrecadado;
                viagem_rentavel = &viagem;
            }
        }

        return *viagem_rentavel;
    }

    double media_idade_passageiros() {
        int total_idade = 0;
        int total_passageiros = 0;

        for (const auto& viagem : viagens) {
            for (const auto& passagem : viagem.passagens_vendidas) {
                total_idade += passagem.idade;
                total_passageiros++;
            }
        }

        return static_cast<double>(total_idade) / total_passageiros;
    }
};

int main() {
    EmpresaOnibus empresa;

    Viagem& viagem1 = empresa.nova_viagem(1, "Rio de Janeiro", "São Paulo");
    Viagem& viagem2 = empresa.nova_viagem(2, "São Paulo", "Rio de Janeiro");

    viagem1.vender_passagem(1, "2023-10-07 08:00", "123456789", "João", 30);
    viagem1.vender_passagem(2, "2023-10-07 08:00", "987654321", "Maria", 25);
    viagem2.vender_passagem(1, "2023-10-07 10:00", "111111111", "Pedro", 40);

    cout << "Total arrecadado para viagem 1: " << viagem1.total_arrecadado() << " reais\n";
    cout << "Total arrecadado em outubro: " << empresa.arrecadado_mes(10) << " reais\n";
    cout << "Nome do passageiro do assento 2 na viagem 1: " << viagem1.passageiro_por_assento(2) << "\n";
    cout << "Horário mais rentável: Viagem " << empresa.horario_mais_rentavel().numero << "\n";
    cout << "Média de idade dos passageiros: " << fixed << setprecision(2) << empresa.media_idade_passageiros() << " anos\n";

    return 0;
}
