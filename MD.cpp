#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;


MD::MD() {
    prim = -1;
    ultim = -1;
    cp = 1000;
    dd = 0;
    e = new TElem[1000];
    urm = new int[1000];
    ant = new int[1000];
    for(int i = 0; i < cp; i++){
        urm[i] = i + 1;
        ant[i] = i - 1;
    }
    urm[cp-1] = -1;
    ant[0] = -1;
    primLiber =0;
    ultim = -1;
}


void MD::adauga(TCheie c, TValoare v) {
    TElem ee;
    ee.first=c;ee.second=v;
    redim();
    int i = creeazaNod(ee);
    urm[i] = prim;
    ant[prim] = i;
    prim = i;
    dd++;
}


bool MD::sterge(TCheie c, TValoare v) {
    ///daca e primul
    if(prim == -1)return false;
    if(e[prim].first == c && e[prim].second == v){
        ant[urm[prim]] = ant[prim];
        int a = prim;
        prim = urm[prim];
        dd--;
        dealoca(a);
        return true;
    }
    int p = prim;
    while(urm[p] != -1){
        if(e[urm[p]].first == c && e[urm[p]].second == v) {
            int q = p;
            p = urm[p];
            ///q precede p
            urm[q] = urm[p];
            ant[urm[p]] = q;
            dealoca(p);
            dd--;
            return true;
        }
        p=urm[p];
    }
    return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
    vector<TValoare> v;
    int p = prim;
    while (p != -1){
        if(e[p].first == c){
            v.push_back(e[p].second);
        }
        p = urm[p];
    }
    return v;
}


int MD::dim() const {
    return dd;
}


bool MD::vid() const {
    return dd == 0;
}

IteratorMD MD::iterator() const {
    return IteratorMD(*this);
}


MD::~MD() = default;

int MD::creeazaNod(TElem ee) {
    int i=aloca();
    this->e[i] = ee;
    urm[i] = -1;
    ant[i] = -1;
    return i;
}

void MD::dealoca(int i) {
    urm[i]=primLiber;
    primLiber=i;
}

int MD::aloca() {
    int i=primLiber;
    primLiber=urm[primLiber];
    return i;
}

void MD::redim() {
    if( dd+1 >= cp){
        TElem* ne = new TElem [cp*2];
        int* nurm =  new int[cp*2];
        int* nant = new int[cp*2];
        for(int i = 0; i < cp; i++){
            ne[i] = e[i];
            nurm[i] = urm[i];
            nant[i] = nant[i];
        }
        for(int i = cp; i < (cp*2); i++){
            nurm[i] = i+1;
            nant[i] = i-1;
        }
        nurm[cp*2] = -1;
        int p = primLiber;
        while(nurm[p] != -1)p = nurm[p];
        nurm[p] = cp;
        nant[cp] = p;
        urm=nurm;
        ant = nant;
        e= ne;
        cp*=2;
    }
}

