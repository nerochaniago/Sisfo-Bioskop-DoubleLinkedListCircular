#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include<iostream>


#define Nil NULL
#define infoChil(P) P->infoChil
#define nextChil(P) P->nextChil
#define prevChil(P) P->prevChil
#define firstChil(L) L.firstChil
#define lastChil(L) L.lastChil

using namespace std;

struct objek{
    string nama;
    int qty,harga;
};

typedef struct Child *address_C;

struct Child{
    objek infoChil;
    address_C nextChil;
    address_C prevChil;
};

struct ListChil{
    address_C firstChil;
    address_C lastChil;
};

void CreateListC(ListChil &L);
address_C alokasiC(objek x);
void dealokasiC(address_C &P);
void iFirstC(ListChil &L, address_C P);
void iAfterC(ListChil &L, address_C P);
void iLastC(ListChil &L, address_C P);
void dFirstC(ListChil &L, address_C &P);
void dAfterC(ListChil &L, address_C Prec, address_C &P);
void dLastC(ListChil &L, address_C &P);
address_C findElmC(ListChil L, objek x);
void printInfoC(ListChil L);

#endif // FILM_H_INCLUDED
