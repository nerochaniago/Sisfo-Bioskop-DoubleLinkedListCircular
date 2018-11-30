#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "Film.h"

void CreateListC(ListChil &L){
    firstChil(L) = Nil;
    lastChil(L) = Nil;
}
address_C alokasiC(objek x){
    address_C P;

    P = new Child;
    infoChil(P).nama = x.nama;
    infoChil(P).harga = x.harga;
    infoChil(P).qty = x.qty;
    nextChil(P) = Nil;
    prevChil(P) = Nil;

    return P;
}
void dealokasiC(address_C &P){
    delete P;
    P = Nil;
}

void iFirstC(ListChil &L, address_C P){
    if (firstChil(L) == Nil){
        firstChil(L) = P;
        lastChil(L) = P;
    }else if( firstChil(L) == lastChil(L) ){
        nextChil(P) = firstChil(L);
        prevChil(firstChil(L)) = P;
        nextChil(firstChil(L)) = P;
        prevChil(P) = firstChil(L);
        firstChil(L) = P;
    } else {
        nextChil(P) = firstChil(L) ;
        prevChil(firstChil(L)) = P ;
        nextChil(lastChil(L)) = P ;
        prevChil(P) = lastChil(L) ;
        firstChil(L) = P ;
    }
}
void iAfterC(ListChil &L, address_C P){
    if (firstChil(L) == Nil ) {
        firstChil(L) = P ;
        lastChil(L) = P ;
    }else if (firstChil(L) == lastChil(L)){
        nextChil(firstChil(L)) = P ;
        prevChil(P) = firstChil(L) ;
        nextChil(P) = firstChil(L) ;
        prevChil(firstChil(L)) = P ;
        lastChil(L) = P ;
    }else {
        nextChil(firstChil(L)) = P ;
        prevChil(P) = firstChil(L);
        prevChil(lastChil(L)) = P ;
        nextChil(P) = lastChil(L) ;
    }

}
void iLastC(ListChil &L, address_C P){
   if (firstChil(L) == Nil) {
        firstChil(L) = P ;
        lastChil(L) = P ;
   }else if (firstChil(L) == lastChil(L)){
        nextChil(P) = firstChil(L) ;
        prevChil(firstChil(L)) = P ;
        nextChil(firstChil(L)) = P ;
        prevChil(P) = firstChil(L) ;
        firstChil(L) = P ;
    }else {
        nextChil(P) = firstChil(L) ;
        prevChil(firstChil(L)) = P ;
        nextChil(lastChil(L)) = P ;
        prevChil(P) = lastChil(L) ;
        firstChil(L) = P ;
    }
}
void dFirstC(ListChil &L, address_C &P){
    if (firstChil(L) != Nil){
        if (P == lastChil(L)){
            nextChil(P) = Nil;
            prevChil(P) = Nil;
            firstChil(L) = Nil;
            lastChil(L) = Nil;
        }else if (nextChil(P) == lastChil(L)){
            nextChil(P) = firstChil(L);
            prevChil(P) = firstChil(L);
            prevChil(lastChil(L)) = Nil;
            nextChil(lastChil(L)) = Nil;
            lastChil(L) = P;
        }else{
            address_C Q = nextChil(P);
            nextChil(P) = nextChil(Q);
            prevChil(nextChil(Q)) = P;
            nextChil(Q) = Nil;
            prevChil(Q) = Nil;
        }
    }
}
void dAfterC(ListChil &L, address_C Prec, address_C &P){
    if (firstChil(L) != Nil){
        if (firstChil(L) == lastChil(L)){
            firstChil(L) = Nil;
            lastChil(L) = Nil;
        }else{
            P = nextChil(Prec);
            nextChil(Prec) = nextChil(P);
            prevChil(nextChil(P)) = Prec;
            nextChil(P) = Nil;
            prevChil(P) = Nil;
        }
    }
}
void dLastC(ListChil &L, address_C &P){
    if (firstChil(L) != Nil){
        P = lastChil(L);
        lastChil(L) = prevChil(P);
        nextChil(lastChil(L)) = Nil;
        prevChil(P) = Nil;
    }
}
address_C findElmC(ListChil L, objek x){
    address_C P;

    P = firstChil(L);
    while (P !=Nil && infoChil(P).nama!=x.nama){
        P = nextChil(P);
    }
    return P;
}
void printInfoC(ListChil L){
    address_C P;
    int i;

    i = 1;
    cout<<"======================================================================"<<endl;
    cout<<endl;
    if (firstChil(L) != Nil){
        if (firstChil(L) == lastChil(L)){
            cout<<i<<". "<<"Judul Film : "<<infoChil(P).nama<<endl;
            cout<<"   "<<"Jumlah Tersisa : "<<infoChil(P).qty<<endl;
            cout<<"   "<<"Harga : Rp"<<infoChil(P).harga<<endl;
            cout<<endl;
        }else{
            P = firstChil(L);
            while (nextChil(P) != firstChil(L)){
                cout<<i<<". "<<"Judul Film : "<<infoChil(P).nama<<endl;
                cout<<"   "<<"Jumlah Tersisa : "<<infoChil(P).qty<<endl;
                cout<<"   "<<"Harga : Rp"<<infoChil(P).harga<<endl;
                cout<<endl;
                i++;
                P = nextChil(P);
            }
        }
    if (nextChil(P) == firstChil(L)){
        cout<<i<<". "<<"Judul Film : "<<infoChil(P).nama<<endl;
        cout<<"   "<<"Jumlah Tersisa : "<<infoChil(P).qty<<endl;
        cout<<"   "<<"Harga : Rp"<<infoChil(P).harga<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"======================================================================"<<endl;
    }
}
