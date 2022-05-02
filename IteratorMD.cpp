#include "IteratorMD.h"
#include "MD.h"
#include <iostream>

using namespace std;

IteratorMD::IteratorMD(const MD& _md): md(_md) {
    ind = md.prim;
}

TElem IteratorMD::element() const{
    if(ind == -1)
        throw runtime_error("");
    TElem ee{md.e[ind].first, md.e[ind].second};
    return ee;
}

bool IteratorMD::valid() const {
    return ind != -1;
}

void IteratorMD::urmator() {
    if(ind == -1)
        throw runtime_error("");
    ind = md.urm[ind];
}

void IteratorMD::prim() {
    ind = md.prim;
}
