// Vamos agora tentar ler mais de um arquvo .txt
#include <iostream>
#include <string>
#include <fstream>

int main(){
    int count = 1;
    std::string archiveName;
    std::string word;

    while(true){

        archiveName = std::to_string(count) + ".txt";
        std::ifstream archive(archiveName);

        if (!archive.is_open()){
            std::cout << "Nao foi possivel ler mais arquivos." << std::endl;
            break;
        }

        std::cout << "Arquivo: " << archiveName << std::endl;
        while (archive >> word){
            std::cout << word << " ";
        }

        archive.close();
        count++;
        std::cout << std::endl;

    }
    std::cout << "Fim." << std::endl;

    return 0;
}