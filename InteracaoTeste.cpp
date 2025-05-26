// No trabalho, lidamos com interacoes na forma .\nome_arquivo_executavel.exe search||stats n_docs diretorio. Vamos tentar implementar isso entao
#include <iostream>
#include <string>

int main(int argc, char* argv[]){

    if (argc != 4){
        std::cerr << "Error: Invalid number of arguments\n";
        return 1;
    }

    std::string comando = argv[1];
    int n_docs = std::stoi(argv[2]);
    std::string diretorio = argv[3];

    if (comando == "search"){
        std::cout << "Aplica a opcao de search" << std::endl;
    }

    else if (comando == "stats"){
        std::cout << "Aplica a opcao de stats" << std::endl;
    }

    else{
        std::cerr << "Error: Invalid Command. Try again with search or stats as the first argument";
        return 1;
    }

    return 0;
}