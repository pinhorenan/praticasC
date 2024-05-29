#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int SEGREDO = rand() % 100;
    
    int max_tentativas;
    int chute;
    char dificuldade;

    int tentativas = 0;
    bool acertou = false;
    double pontos = 1000.0;

    cout << "*************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinhação! *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha o nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D): ";

    cin >> dificuldade;

    switch (dificuldade) {
        case 'F':
            cout << "Você escolheu o nível fácil!" << endl;
            cout << "Você terá 15 tentativas para acertar o número secreto." << endl;
            cout << "Boa sorte!" << endl;
            break;
        case 'M':
            cout << "Você escolheu o nível médio!" << endl;
            cout << "Você terá 10 tentativas para acertar o número secreto." << endl;
            cout << "Boa sorte!" << endl;
            break;
        case 'D':
            cout << "Você escolheu o nível difícil!" << endl;
            cout << "Você terá 5 tentativas para acertar o número secreto." << endl;
            cout << "Boa sorte!" << endl;
            break;
        default:
            cout << "Opção inválida! O nível de dificuldade foi definido como médio." << endl;
            cout << "Você terá 10 tentativas para acertar o número secreto." << endl;
            cout << "Boa sorte!" << endl;
            break;
    }

    while (!acertou && tentativas < max_tentativas)
    {
        cout << "Digite o seu chute: ";
        cin >> chute;

        acertou = (chute == SEGREDO);

        if (chute > SEGREDO) {
        tentativas++;
        pontos -= abs(chute - SEGREDO)/2.0;
        cout << "Que pena! " << chute << " é maior que o número secreto!" << endl;
        } else {
        tentativas++;
        pontos -= abs(chute - SEGREDO)/2.0;
        cout << "Que pena! " << chute << " é menor que o número secreto!" << endl;
        }
    }
    
    if (acertou) {
        cout << "Parabéns! Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi: " << pontos << " pontos." << endl;
    } else {
        cout << "Que pena! Você perdeu! O número secreto era " << SEGREDO << "." << endl;
    }

    return 0;
}