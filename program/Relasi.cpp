#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "Relasi.h"


void createlistR(ListRel &L){
    firstR(L) = Nil;
    lastR(L) = Nil;
}

address_R alokasiR(infotypeR x){
    address_R P = new Relasi;
    infoR(P) = x;
    nextR(P) = Nil;
    prevR(P) = Nil;
    return P;
}

void dealokasiR(address_R &P){
    delete P;
    P = Nil;
}

void insertFirstR(ListRel &L, address_R P){
    if (firstR(L) == Nil){
        firstR(L) = P;
        lastR(L) = P;
    }
    else{
        nextR(P) = firstR(L);
        prevR(firstR(L)) = P;
        firstR(L) = P;
    }
}

void insertLastR(ListRel &L, address_R P){
       if(firstR(L)== NULL)
    {
        firstR(L) = P;
        lastR(L) = P;
    }
    else
    {
        nextR(lastR(L)) = P;
        prevR(P) = lastR(L);
        lastR(L) = P;
    }
}

void insertAfterR(ListRel &L, address_R Prec, address_R P){
    nextR(P) = nextR(Prec);
    prevR(P) = Prec;
    prevR(nextR(P)) = P;
    nextR(Prec) = P;
}

void deleteFirstR(ListRel &L, address_R P){
    if(firstR(L)== NULL)
       cout<<"list kosong "<<endl;
    else if(firstR(L) == lastR(L))
    {
        P = firstR(L);
        firstR(L)= NULL;
        lastR(L)= NULL;
    }
    else
    {
        P = firstR(L);
        firstR(L) = nextR(P);
        nextR(P) = NULL;
        prevR(firstR(L)) = NULL;
    }
}
void deleteLastR(ListRel &L, address_R P){
    if(firstR(L)== NULL)
       cout<<"list kosong "<<endl;
    else if(nextR(firstR(L))==NULL)
    {
        deleteFirstR(L,P);
    }
    else
    {
        P = lastR(L);
        lastR(L) = prevR(P);
        nextR(lastR(L)) = NULL;
        prevR(P) = NULL;
    }
}

void deleteAfterR(ListRel &L, address_R Prec, address_R P){
    P = nextR(Prec);
    nextR(Prec) = nextR(P);
    prevR(nextR(P)) = Prec;
    nextR(P)= NULL;
    prevR(P)= NULL;
}
address_R findElmt_R(ListRel L, string lokasi,string barang){
    address_R Q;

    Q = firstR(L);
    while(Q != NULL){
        if((infoPar(infoR(Q).up) == lokasi) && (infoChil(infoR(Q).down).nama == barang)){
            return Q;
        Q = nextR(Q);
        }
    }
    return NULL;
}

void printInfoR(ListRel L){
    address_R P;
    address_C PC;
    int i;

    i = 1;
    P = firstR(L);
    cout<<"======================================================================"<<endl;
    cout<<endl;
    if (firstR(L) != Nil){
        if (firstR(L) == lastR(L)){
            cout<<"Teater : "<<infoPar(infoR(P).up)<<endl;
            cout<<"Daftar Film : "<<"Nama Film : "<<infoChil(infoR(P).down).nama<<endl;
            cout<<"                "<<"Jumlah Tiket Tersisa : "<<infoChil(infoR(P).down).qty<<endl;
            cout<<"                "<<"Harga : Rp"<<infoChil(infoR(P).down).harga<<endl;
        }else{
            P = firstR(L);
            while (nextR(P) != Nil){
                cout<<"Teater : "<<infoPar(infoR(P).up)<<endl;
                cout<<"Daftar Film : "<<"Nama Film : "<<infoChil(infoR(P).down).nama<<endl;
                cout<<"                "<<"Jumlah Tiket Tersisa : "<<infoChil(infoR(P).down).qty<<endl;
                cout<<"                "<<"Harga : Rp"<<infoChil(infoR(P).down).harga<<endl;
                i++;
                P = nextR(P);
            }
        }
    }
}



