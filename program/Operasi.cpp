#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "Bioskop.h"
#include "Film.h"
#include "Relasi.h"

using namespace std;

address_C alokasiBarang(){
    objek x;

    cout<<"Masukkan nama film :";
    cin>>x.nama;
    cout<<"Masukkan banyaknya tiket :";
    cin>>x.qty;
    cout<<"Masukkan harga tiket :";
    cin>>x.harga;
    return alokasiC(x);
}

address_P alokasiLokasi(){
    string x;

    cout<<"Masukkan teater yang Ingin Ditambahkan :";
    cin>>x;
    return alokasiP(x);
}

address_R alokasiRelasi(ListPar LP, ListChil LC){
    infotypeR x;
    string lokasi;
    objek barang;

    cout<<"======================================================================"<<endl;
    cout<<endl;
    cout<<"masukkan nama film : ";
    cin>>barang.nama;
    x.down = findElmC(LC,barang);
    cout<<"masukkan teater : ";
    cin>>lokasi;
    x.up = findElmP(LP,lokasi);
    if((x.down != Nil) && (x.up != Nil)){
        return alokasiR(x);
    }
    else{
        cout<<"barag tidak ditemukan"<<endl;
        return Nil;
    }
    cout<<endl;
    cout<<"======================================================================"<<endl;
}

void plusTeater(ListPar &L){
    string teaters;
    int jumlah,i;

    cout<<"======================================================================"<<endl;
    cout<<endl;
    cout<<"masukkan jumlah teater yang ingin ditambahkan : ";
    cin>>jumlah;
    for (i = 1; i <= jumlah;i++){
        cout<<"masukkan nama teater (cth : Teater.1) : ";
        cin>>teaters;
        iFirstP(L,alokasiP(teaters));
    }
    cout<<endl;
    cout<<"======================================================================"<<endl;
}
void plusFilm(ListChil &L){
    objek film;
    int jumlah,i;

    cout<<"======================================================================"<<endl;
    cout<<endl;
    cout<<"masukkan jumlah film yang akan diinput : ";
    cin>>jumlah;
    for (i = 1; i <= jumlah;i++){
        cout<<"masukkan nama film : ";
        cin>>film.nama;
        cout<<"masukkan banyaknya tiket : ";
        cin>>film.qty;
        cout<<"masukkan harga tiket : Rp";
        cin>>film.harga;
        iLastC(L,alokasiC(film));
    }
    cout<<endl;
    cout<<"======================================================================"<<endl;
}

void plusRelasi(ListRel &LR, ListPar LP, ListChil LC){
    address_R PR;
    bool ulang = false;
    int pilih;
    address_R Prec;
    string teater,film;
    bool ulg = false;

    PR = alokasiRelasi(LP,LC);
    cout<<endl;
    cout<<"======================================================================"<<endl;
    cout<<endl;
      while(!ulang){
        cout<<"1. insert first"<<endl;
        cout<<"2. insert last"<<endl;
        cout<<"3. insert after"<<endl;
    cout<<endl;
    cout<<"======================================================================"<<endl;
    cout<<endl;
        cout<<"pilih : ";
        cin>>pilih;
        switch (pilih){
            case 1 :
                    insertFirstR(LR,PR);
                    ulang = true;
                    break;
            case 2 :
                    insertLastR(LR,PR);
                    ulang = true;
                    break;
            case 3 :

                    while (!ulg){
                        cout<<"input nama teater : ";
                        cin>>teater;
                        cout<<"input nama film : ";
                        cin>>film;
                        Prec = findElmt_R(LR,teater,film);
                        if(Prec != Nil){
                        insertAfterR(LR,Prec,PR);
                        ulg = true;
                        }
                        else{
                            cout<<"prec tidak ditemukan"<<endl;
                        }
                    }
                    ulang = true;
                    break;
            default :
                    cout<<"inputan salah"<<endl;
                    break;
        }
    }
}

void deleteTeater(ListPar &L, address_P P){
    if(firstPar(L) == Nil){
        cout<<"list kosong"<<endl;
    }
    else if (P == firstPar(L)){
        dFirstP(L,P);
    }
    else if (P == lastPar(L))
    {
        dLastP(L,P);
    }
    else{
        nextPar(prevPar(P)) = nextPar(P);
        prevPar(nextPar(P)) = prevPar(P);
        nextPar(P) = Nil;
        prevPar(P) = Nil;
    }
}

void deleteFilm(ListChil &L, address_C &P){
     if(firstChil(L) == Nil){
        cout<<"list kosong"<<endl;
    }
    else if (P == firstChil(L)){
        dFirstC(L,P);
    }
    else if (P == lastChil(L))
    {
        dLastC(L,P);
    }
    else{
        nextChil(prevChil(P)) = nextChil(P);
        prevChil(nextChil(P)) = prevChil(P);
        nextChil(P) = Nil;
        prevChil(P) = Nil;
    }
}

void deleteRelasi(ListRel &L, address_R &P){
     if(firstR(L) == Nil){
        cout<<"list kosong"<<endl;
    }
    else if (P == firstR(L)){
        deleteFirstR(L,P);
    }
    else if (P == lastR(L))
    {
        deleteLastR(L,P);
    }
    else{
        nextR(prevR(P)) = nextR(P);
        prevR(nextR(P)) = prevR(P);
        nextR(P) = Nil;
        prevR(P) = Nil;
    }
}
