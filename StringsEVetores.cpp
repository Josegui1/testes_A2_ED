#include <iostream>
#include <string>
#include <vector>

int main(){
    // Podemos declarar uma variavel do tipo string assim
    std::string word = "Jose";
    
    // Podemos declarar um vetor de um tipo assim
    std::vector<int> vector = {1, 3, 5, 7};
    
    // Temos diversos metodos para cada um desses tipos, inclusive podemos combinar eles se for possivel
    std::vector<std::string> words = {"Amo", "minha", "namoradinha", "gostosa", "e", "lindinha", "Isabela"};

    for (int i = 0; i < words.size(); i++){
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

// Esses dois tipos serao importantes no trabalho que sera feito, mas o basico pode ser visto na hora.