// Talvez esse daqui seja mais complexo, mas agora devemos aprender a ler um .txt em c++ automaticamente
#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::ifstream archive("1.txt");
    std::string word;

    if (archive.is_open()){
        while(archive >> word){
            std::cout << word << " ";
        }
        archive.close();
    }
    else{
        std::cout << "Nao foi possivel abrir o arquivo. Por favor tente novamente" << std::endl;
    }
    return 0;
}

// Isso permite a leitura de um arquivo basico, mas devemos ler n arquivos.txt. Vamos tentar fazer isso agora