#include <iostream>
using namespace std;

int main() {
    const int SEGREDO = 42;
    const int MAX_TENTATIVAS = 5;
    int contador = 0;
    int chute = 0;
    bool acertou = false;
    double pontos = 1000.0;

    cout << "*************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinhação! *" << endl;
    cout << "*************************************" << endl;

    while (!acertou && contador < MAX_TENTATIVAS)
    {
        cout << "Digite o seu chute: ";
        cin >> chute;

        acertou = (chute == SEGREDO);

        if (chute > SEGREDO) {
        contador++;
        pontos -= abs(chute - SEGREDO)/2.0;
        cout << "Que pena! " << chute << " é maior que o número secreto!" << endl;
        } else {
        contador++;
        pontos -= abs(chute - SEGREDO)/2.0;
        cout << "Que pena! " << chute << " é menor que o número secreto!" << endl;
        }
    }
    
    if (acertou) {
        contador = 0;
        cout.precision(2);
        cout << fixed;
        cout << "Parabéns! Você acertou o número secreto! Sua pontuação foi: " << pontos << " pontos." << endl;
    } else {
        cout << "Que pena! Você perdeu! O número secreto era " << SEGREDO << "." << endl;
    }

    return 0;
}