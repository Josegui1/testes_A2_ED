#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Estrutura do nó da BST
struct NodoBST {
    string palavra;
    vector<int> idsDocumentos;
    NodoBST* esquerda;
    NodoBST* direita;
};

bool jaExiste(const vector<int>& v, int valor) {
    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i] == valor) {
            return true;
        }
    }
    return false;
}

NodoBST* inserir(NodoBST* raiz, const string& palavra, int idDoc) {
    if (raiz == NULL) {
        NodoBST* novo = new NodoBST;
        novo->palavra = palavra;
        novo->idsDocumentos.push_back(idDoc);
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    if (palavra < raiz->palavra) {
        raiz->esquerda = inserir(raiz->esquerda, palavra, idDoc);
    } else if (palavra > raiz->palavra) {
        raiz->direita = inserir(raiz->direita, palavra, idDoc);
    } else {
        if (!jaExiste(raiz->idsDocumentos, idDoc)) {
            raiz->idsDocumentos.push_back(idDoc);
        }
    }
    return raiz;
}

void imprimirInOrder(NodoBST* raiz) {
    if (raiz != NULL) {
        imprimirInOrder(raiz->esquerda);
        cout << raiz->palavra << ": ";
        for (int i = 0; i < (int)raiz->idsDocumentos.size(); ++i) {
            cout << raiz->idsDocumentos[i] << " ";
        }
        cout << "\n";
        imprimirInOrder(raiz->direita);
    }
}

void liberarBST(NodoBST* raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->esquerda);
        liberarBST(raiz->direita);
        delete raiz;
    }
}

int main() {
    int count = 1;
    string archiveName;
    string word;
    string dir;

    cout << "Digite o caminho do diretorio (ex.: dados/ ou C:\\\\pasta\\\\): ";
    getline(cin, dir);

    if (dir.back() != '/' && dir.back() != '\\') {
        dir += '/';  // Adapta para sistemas baseados em '/' ou '\'
    }

    NodoBST* indiceInvertido = NULL;

    while (true) {
        archiveName = dir + to_string(count) + ".txt";
        ifstream archive(archiveName.c_str());

        if (!archive.is_open()) {
            cout << "Nao foi possivel ler mais arquivos. Finalizando o programa.\n";
            break;
        }

        while (archive >> word) {
            indiceInvertido = inserir(indiceInvertido, word, count);  //IdDoc = count
        }

        archive.close();
        count++;
    }

    cout << "\nIndice Invertido:\n";
    imprimirInOrder(indiceInvertido);

    liberarBST(indiceInvertido);

    return 0;
}

// Embora esse codigo sejan razoavelmente mais simples que a versao final, ele aprensenta as partes mais basicas e uma ideia de implementacao.