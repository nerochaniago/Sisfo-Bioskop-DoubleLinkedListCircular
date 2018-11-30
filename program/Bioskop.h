#ifndef BIOSKOP_H_INCLUDED
#define BIOSKOP_H_INCLUDED

#include<iostream>
#define Nil NULL
#define infoPar(P) P->infoPar
#define nextPar(P) P->nextPar
#define prevPar(P) P->prevPar
#define firstPar(L) L.firstPar
#define lastPar(L) L.lastPar

using namespace std;

typedef struct Parent *address_P;

struct Parent{
    string infoPar;
    address_P nextPar;
    address_P prevPar;
};

struct ListPar{
    address_P firstPar;
    address_P lastPar;
};

void CreateListP(ListPar &L);
address_P alokasiP(string x);
void dealokasiP(address_P &P);
void iFirstP(ListPar &L, address_P P);
void iAfterP(ListPar &L, address_P P);
void iLastP(ListPar &L, address_P P);
void dFirstP(ListPar &L, address_P &P);
void dAfterP(ListPar &L, address_P Prec, address_P &P);
void dLastP(ListPar &L, address_P &P);
address_P findElmP(ListPar L, string x);
void printInfoP(ListPar L);

#endif //BIOSKOP_H_INCLUDED
