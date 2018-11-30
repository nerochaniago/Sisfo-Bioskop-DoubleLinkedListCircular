#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "Bioskop.h"
#include "Film.h"

#include<iostream>
#define Nil NULL
#define up(P) P->up
#define down(P) P->down
#define nextR(P) P->nextR
#define prevR(P) P->prevR
#define firstR(L) L.firstR
#define lastR(L) L.lastR
#define infoR(P) P->infoR
//#define infoUR(P) P->infoUR
//#define infoDR(P) P->infoDR

using namespace std;

struct infotypeR{
    address_P up;
    address_C down;
};

typedef struct Relasi *address_R;

struct Relasi{
    infotypeR infoR;
    address_R nextR;
    address_R prevR;
    address_C nextChil;
    address_P nextPar;

};

struct ListRel{
    address_R firstR;
    address_R lastR;
};

void createlistR(ListRel &L);
address_R alokasiR(infotypeR x);
void dealokasiR(address_R &P);
void insertFirstR(ListRel &L, address_R P);
void insertLastR(ListRel &L, address_R P);
void insertAfterR(ListRel &L, address_R Prec, address_R P);
void deleteFirstR(ListRel &L, address_R P);
void deleteLastR(ListRel &L, address_R P);
void deleteAfterR(ListRel &L, address_R Prec, address_R P);
address_R findElmt_R(ListRel L, string lokasi,string barang);
void printInfoR(ListRel L);

#endif // RELASI_H_INCLUDED
