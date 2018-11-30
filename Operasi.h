#ifndef OPERASI_H_INCLUDED
#define OPERASI_H_INCLUDED


#include "Bioskop.h"
#include "Film.h"
#include "Relasi.h"

#include <iostream>

using namespace std;

address_C alokasiBarang();
address_P alokasiLokasi();
address_R alokasiRelasi(ListPar LP, ListChil LC);
void plusTeater(ListPar &L);
void plusFilm(ListChil &L);
void plusRelasi(ListRel &LR, ListPar LP, ListChil LC);
void deleteTeater(ListPar &L, address_P P);
void deleteFilm(ListChil &L, address_C &P);
void deleteRelasi(ListRel &L, address_R &P);
#endif // OPERASI_H_INCLUDED
