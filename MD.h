#pragma once
#include<vector>
#include<utility>

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMD;

class MD
{
    friend class IteratorMD;

private:
    int cp;
    TElem* e;
    int dd;
    int* urm;
    int* ant;

    int prim;
    int ultim;
    int primLiber;

    int aloca();
    void dealoca(int i);
    void redim();

    int creeazaNod(TElem e);
public:
    // constructorul implicit al MultiDictionarului
    MD();

    // adauga o pereche (cheie, valoare) in MD
    void adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza vectorul de valori asociate
    vector<TValoare> cauta(TCheie c) const;

    //sterge o cheie si o valoare
    //returneaza adevarat daca s-a gasit cheia si valoarea de sters
    bool sterge(TCheie c, TValoare v);

    //returneaza numarul de perechi (cheie, valoare) din MD
    int dim() const;

    //verifica daca MultiDictionarul e vid
    bool vid() const;

    // se returneaza iterator pe MD
    IteratorMD iterator() const;

    // destructorul MultiDictionarului
    ~MD();



};

