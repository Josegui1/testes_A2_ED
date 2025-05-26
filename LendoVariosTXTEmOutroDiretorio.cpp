#include <iostream>
#include <string>
#include <fstream>

int main(){
    int count = 1;
    std::string archiveName;
    std::string word;
    std::string dir;

    std::cout << "Digite o caminho do diretorio (ex.: dados/ ou C:\\\\pasta\\\\): ";
    std::getline(std::cin, dir);

    // Garantir que o caminho termine com '/' ou '\\' dependendo do SO
    if (dir.back() != '/' && dir.back() != '\\') {
        dir += '/';  // No Linux/MacOS use '/'
    }

    while(true){
        archiveName = dir + std::to_string(count) + ".txt";
        std::ifstream archive(archiveName);

        if (!archive.is_open()){
            std::cout << "Nao foi possivel ler mais arquivos. Finalizando o programa ";
            break;
        }

        while (archive >> word){
            std::cout << word << " ";
        }
        std::cout << std::endl;

        archive.close();
        count++;
    }

    return 0;
}

// Acredito que esses topicos cobrem o basico do que sera implementado durante a avaliacao e nao havia ainda sido visto
