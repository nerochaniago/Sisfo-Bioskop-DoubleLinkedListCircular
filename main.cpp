#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#define enter system("PAUSE")
using namespace std;

#include "Bioskop.h"
#include "Film.h"
#include "Relasi.h"
#include "Operasi.h"


void Konsumen(ListRel LR, objek beli){

    bool keluar = false;
    int pilih;
    //objek beli;
    address_R PR;
    string lokasi;

    while (!keluar){
        cout<<"=========================================================================="<<endl;
        cout<<"======================== *** Menu Konsumen *** ==========================="<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<endl;
        cout<<"         1. Lihat Film di teater"<<endl;
        cout<<"         2. masukkan uang"<<endl;
        cout<<"         3. beli"<<endl;
        cout<<"         0. exit"<<endl;
        cout<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<endl;
        cout<<"Pilih : ";
        cin>>pilih;
        system("CLS");
        switch (pilih){
            case 1 :
                    printInfoR(LR);
                    getch();
                    system("CLS");
                    break;
            case 2 :
                    cout<<"======================================================================"<<endl;
                    cout<<endl;
                    cout<<"Masukkan Uang : Rp";
                    cin>>beli.harga;
                    cout<<endl;
                    cout<<"======================================================================"<<endl;
                    getch();
                    system("CLS");
                    break;
            case 3 :
                    cout<<"======================================================================"<<endl;
                    cout<<endl;
                    cout<<"masukkan teater : ";
                    cin>>lokasi;
                    cout<<"masukkan nama film : ";
                    cin>>beli.nama;
                    cout<<"masukkan jumlah tiket : ";
                    cin>>beli.qty;
                    PR = findElmt_R(LR,lokasi,beli.nama);
                    if (PR != Nil){
                        if (infoChil(infoR(PR).down).qty > 0){
                            if (beli.harga >= infoChil(infoR(PR).down).harga * beli.qty){
                                infoChil(infoR(PR).down).qty = infoChil(infoR(PR).down).qty - beli.qty;
                                cout<<"Terima Kasih Anda Telah Membeli "<<beli.nama<<" Sebanyak "<<beli.qty<<endl;
                                beli.harga = beli.harga - infoChil(infoR(PR).down).harga * beli.qty;
                                cout<<"Sisa Uang Anda : Rp"<<beli.harga<<endl;
                            }
                        }else if(infoChil(infoR(PR).down).qty == 0){
                            cout<<"tiket Habis"<<endl;
                        }else if(beli.harga < infoChil(infoR(PR).down).harga * beli.qty){
                            cout<<"Maaf Uang Anda Tidak Mencukupi"<<endl;
                        }
                    }
                    cout<<endl;
                    cout<<"======================================================================"<<endl;
                    getch();
                    system("CLS");
                    break;
            default :
                    keluar = true;
                    break;
        }
    }
}

void Admin(ListPar &LP, ListChil &LC, ListRel &LR){
    bool keluar = false;
    bool kelar = false;
    int pilih;
    string teater,films;
    objek film;
    objek fil[5];
    string teat[12];
    infotypeR x;


    CreateListP(LP);
    CreateListC(LC);
    createlistR(LR);

    address_P cariTeater;
    address_C cariFilm;
    address_R cariRelasi;


    fil[0].nama = "Avenger";
    fil[0].qty = 1200;
    fil[0].harga = 50000;
    fil[1].nama = "TTM";
    fil[1].qty = 1200;
    fil[1].harga = 35000;
    fil[2].nama = "Jombi";
    fil[2].qty = 1000;
    fil[2].harga = 25000;
    fil[3].nama = "Hercules";
    fil[3].qty = 1200;
    fil[3].harga = 35000;
    fil[4].nama = "KungFu";
    fil[4].qty = 1000;
    fil[4].harga = 35000;
    for (int i = 0; i<=4;i++){
        iFirstC(LC,alokasiC(fil[i]));
    }

    teat[0] = "Teater.1";
    teat[1] = "Teater.2";
    teat[2] = "Teater.3";
    teat[3] = "Teater.4";
    teat[4] = "Teater.5";
    teat[5] = "Teater.6";
    teat[6] = "Teater.7";
    teat[7] = "Teater.8";
    teat[8] = "Teater.9";
    teat[9] = "Teater.10";
    teat[10] = "Teater.11";
    teat[11] = "Teater.12";
    for (int i = 0; i<=11; i++){
        iFirstP(LP,alokasiP(teat[i]));
    }

    /*for (int i = 0; i<=11;i++){
        for (int j = 0; j <= 4; j++){
            x.down = findElmC(LC,bar[j]);
            x.up = findElmP(LP,lok[i]);
            if((x.down != Nil) && (x.up != Nil)){
                address_R PR = alokasiR(x);
                insertFirstR(LR,PR);
            }
        }
    }*/


    while (!keluar){
        cout<<"======================================================================="<<endl;
        cout<<"======================== *** Admin Menu *** ==========================="<<endl;
        cout<<"======================================================================="<<endl;
        cout<<endl;
        cout<<"         1. Tambah Teater Bioskop"<<endl;
        cout<<"         2. Hapus Teater Bioskop"<<endl;
        cout<<"         3. Tambah Film"<<endl;
        cout<<"         4. Hapus Film"<<endl;
        cout<<"         5. Tambah Film ke Teater"<<endl;
        cout<<"         6. Hapus Film dari Teater"<<endl;
        cout<<"         7. Lihat Teater"<<endl;
        cout<<"         8. Lihat Film"<<endl;
        cout<<"         9. Lihat Film di Teater"<<endl;
        cout<<"         0. exit"<<endl;
        cout<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"                      Copyright Nero Chaniago And Prima Manggala Group "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Pilih : ";
        cin>>pilih;
        system("CLS");
        switch(pilih){
            case 1 :
                    plusTeater(LP);
                    getch();
                    system("CLS");
                    break;
            case 2 :
                    kelar = false;
                    cout<<"======================================================================"<<endl;
                    cout<<endl;
                    while(!kelar){
                        cout<<"Masukkan teater yang akan dihapus : ";
                        cin>>teater;
                        cariTeater = findElmP(LP,teater);
                        if(cariTeater != Nil){
                            kelar = true;
                        }else{
                            cout<<"Maaf teater tidak ditemukan"<<endl;
                            kelar = true;
                        }
                    }
                    cout<<endl;
                    cout<<"======================================================================"<<endl;
                    deleteTeater(LP,cariTeater);
                    getch();
                    system("CLS");
                    break;
            case 3 :
                    plusFilm(LC);
                    getch();
                    system("CLS");
                    break;
            case 4 :
                    kelar = false;
                    cout<<"======================================================================"<<endl;
                    cout<<endl;
                    while(!kelar){
                        cout<<"Masukkan film yang akan dihapus : ";
                        cin>>film.nama;
                        cariFilm = findElmC(LC,film);
                        if(cariFilm != Nil){
                            kelar = true;
                        }else{
                            cout<<"Maaf film tidak ditemukan"<<endl;
                            kelar = true;
                        }
                    }
                    cout<<endl;
                    cout<<"======================================================================"<<endl;
                    deleteFilm(LC,cariFilm);
                    getch();
                    system("CLS");
                    break;
            case 5 :
                    plusRelasi(LR,LP,LC);
                    getch();
                    system("CLS");
                    break;
            case 6 :
                    kelar = false;
                    cout<<"======================================================================"<<endl;
                    cout<<endl;
                    while(!kelar){
                        cout<<"Masukkan teater : ";
                        cin>>teater;
                        cout<<"Masukkan film : ";
                        cin>>films;
                        cariRelasi = findElmt_R(LR,teater,films);
                        if(cariRelasi != Nil){
                            kelar = true;
                        }
                    }
                    cout<<endl;
                    cout<<"======================================================================"<<endl;
                    deleteRelasi(LR,cariRelasi);
                    getch();
                    system("CLS");
                    break;
            case 7 :
                    printInfoP(LP);
                    getch();
                    system("CLS");
                    break;
            case 8 :
                    printInfoC(LC);
                    getch();
                    system("CLS");
                    break;
            case 9 :
                    printInfoR(LR);
                    getch();
                    system("CLS");
                    break;
                    default:
                    keluar = true;
            }
        }
}

void MainMenu(){
    bool exit = false;
    int pilih;
    ListChil LC;
    ListPar LP;
    ListRel LR;
    objek beli;


    while (!exit){
        cout<<"======================================================================"<<endl;
        cout<<"========================= *** Main Menu *** =========================="<<endl;
        cout<<"======================================================================"<<endl;
        cout<<endl;
        cout<<"         1. Admin"<<endl;
        cout<<"         2. Konsumen"<<endl;
        cout<<"         0. exit"<<endl;
        cout<<endl;
        cout<<"======================================================================"<<endl;
        cout<<"======================================================================"<<endl;
        cout<<"======================================================================"<<endl;
        cout<<endl;
        cout<<"Pilih : ";
        cin>>pilih;
        system("CLS");
        switch(pilih){
            case 1 :
                    Admin(LP,LC,LR);
                    break;
            case 2 :
                    Konsumen(LR,beli);
                    break;
            default :
                    exit = true;
                    break;
        }
    }
}


int main()
{
    //system("color 3F");
    MainMenu();


    return 0;
}

