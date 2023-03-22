#include <iostream>
#include <stdexcept>

using namespace std;
typedef int dado;

struct Dado {
    dado chave;
    [dados a serem inseridos]
    (analisar enunciado)

};

class noh {
    friend class abb;

    private: 
        Dado mDado;
        noh* esquerda;
        noh* direita;
    public:
        noh (const Dado& umDado):
            mDado(umDado), esquerda(NULL), direita(NULL) {}
        ~noh() {}
};

class abb{
    private: 
        noh* raiz;
        void percorreEmOrdemAUX(noh* atual, int nivel);
        noh* insereAUX(noh* umNoh, const Dado& umDado);
        noh* buscaAUX(noh* umNoh, dado chave);
        void destruirRecursivo(noh* umNoh);
    public:
        abb() {raiz = NULL;}
        ~abb();
        void imprimir();
        void inserir(const Dado& umDado);
        Dado busca(dado chave);
        void destruirRecursivo(noh* umNoh); //PERCORRIMENTO PÓS ORDEM

};
abb::~abb(){
    destruirRecursivo(raiz);
}

void abb::destruirRecursivo(noh* umNoh) {
    if (umNoh) {
        destruirRecursivo(umNoh -> esquerda);
        destruirRecursivo(umNoh -> direita);
        delete umNoh;

    }
}

void abb::inserir(const Dado& umDado) {
    raiz = insereAUX(raiz, umDado);
}

noh* abb::insereAUX(noh* umNoh, const Dado& umDado){
    if (umNoh == NULL) {
        noh* novoNoh = new noh (umDado);
        return novoNoh;

    } else if (umDado.chave < umNoh->mDado.chave) {
       umNoh->esquerda = insereAUX(umNoh-> esquerda, umDado);
       return umNoh;

    } else if (umDado.chave > umNoh->mDado.chave) {
       umNoh->direita= insereAUX(umNoh-> direita, umDado);
       return umNoh;

    }
    else {
        cout << "chave repetida na insercao\n";
    }

}

void abb::imprimir(){
    percorreEmOrdemAUX(raiz, 0);
    cout << endl;
}

void abb::percorreEmOrdemAUX(noh* atual, int nivel) {
    if (atual) { //VERIFICA SE É NULO, SE FOR DA FALHA DE SEGMENTAÇÃO
        percorreEmOrdemAUX(atual->esquerda); 
        cout << atual->#warning (OLHAR O QUE O ENUNCIADO QUER QUE IMPRIMA) << nivel;
        percorreEmOrdemAUX(atual->esquerda, nivel+1);
    }
}
Dado abb::busca(dado chave){
    noh* nohComDados = buscaAUX (raiz, chave);

    if (nohComDados == NULL)
        cout << "valor nao encontrado\n";
    else 
        return nohComDados->mDado; //

}
noh* abb::buscaAUX(noh* umNoh, dado chave) {
    if (umNoh == NULL) {
        return NULL;

    } else if (chave < umNoh->mDado.chave) {
       return buscaAUX(umNoh->esquerda, chave);

    } else if (chave > umNoh->mDado.chave) {
       return buscaAUX(umNoh-> direita, chave);
    }
    else {
       return umNoh;
    }
}

int main () {

    return 0;
}