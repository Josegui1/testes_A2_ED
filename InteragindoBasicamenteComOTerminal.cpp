// A ideia aqui eh implementar uma cli simples no terminal para depois usar no trabalho de A2 de ED
#include <iostream>
#include <string>

// Podemos fazer isso adicionando dois argumentos na main: int argc (argument count) e char* argv[] (argument vector), ou seja, o numero de argumentos passados
// e um vetor de strings representando os argumentos. Com base nesses dois parametros, podemos operar verificacoes que permitem decidir a decisao a ser tomada
int main(int argc, char* argv[]) {
    std::cout << "Numero de argumentos: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argumento " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}

// Para funcionar devemos escrever do lado do executavel .\executavel.exe argumentos. Eh com base nisso que podemos comecar a fazer interacoes cli no terminal.
// Vale ressaltar que o primeiro argumento sempre eh o nome do executavel, logo obrigatoriamente argc >= 1.
