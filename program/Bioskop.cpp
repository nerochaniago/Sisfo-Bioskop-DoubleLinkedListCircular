#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "Bioskop.h"

void CreateListP(ListPar &L){
    firstPar(L) = Nil;
    lastPar(L) = Nil;
}
address_P alokasiP(string x){
    address_P P;

    P = new Parent;
    infoPar(P) = x;
    nextPar(P) = Nil;
    prevPar(P) = Nil;

    return P;
}
void dealokasiP(address_P &P){
    delete P;
    P = Nil;
}

void iFirstP(ListPar &L, address_P P){
    if (firstPar(L) == Nil){
        firstPar(L) = P;
        lastPar(L) = P;
    }else if( firstPar(L) == lastPar(L) ){
        nextPar(P) = firstPar(L);
        prevPar(firstPar(L)) = P;
        nextPar(firstPar(L)) = P;
        prevPar(P) = firstPar(L);
        firstPar(L) = P;
    } else {
        nextPar(P) = firstPar(L) ;
        prevPar(firstPar(L)) = P ;
        nextPar(lastPar(L)) = P ;
        prevPar(P) = lastPar(L) ;
        firstPar(L) = P ;
    }
}
void iAfterP(ListPar &L, address_P P){
    if (firstPar(L) == Nil ) {
        firstPar(L) = P ;
        lastPar(L) = P ;
    }else if (firstPar(L) == lastPar(L)){
        nextPar(firstPar(L)) = P ;
        prevPar(P) = firstPar(L) ;
        nextPar(P) = firstPar(L) ;
        prevPar(firstPar(L)) = P ;
        lastPar(L) = P ;
    }else {
        nextPar(firstPar(L)) = P ;
        prevPar(P) = firstPar(L);
        prevPar(lastPar(L)) = P ;
        nextPar(P) = lastPar(L) ;
    }
}
void iLastP(ListPar &L, address_P P){
    if (firstPar(L) == Nil) {
        firstPar(L) = P ;
        lastPar(L) = P ;
   }else if (firstPar(L) == lastPar(L)){
        nextPar(P) = firstPar(L) ;
        prevPar(firstPar(L)) = P ;
        nextPar(firstPar(L)) = P ;
        prevPar(P) = firstPar(L) ;
        firstPar(L) = P ;
    }else {
        nextPar(P) = firstPar(L) ;
        prevPar(firstPar(L)) = P ;
        nextPar(lastPar(L)) = P ;
        prevPar(P) = lastPar(L) ;
        firstPar(L) = P ;
    }
}
void dFirstP(ListPar &L, address_P &P){
    if (firstPar(L) != Nil){
        if (P == lastPar(L)){
            nextPar(P) = Nil;
            prevPar(P) = Nil;
            firstPar(L) = Nil;
            lastPar(L) = Nil;
        }else if (nextPar(P) == lastPar(L)){
            nextPar(P) = firstPar(L);
            prevPar(P) = firstPar(L);
            prevPar(lastPar(L)) = Nil;
            nextPar(lastPar(L)) = Nil;
            lastPar(L) = P;
        }else{
            address_P Q = nextPar(P);
            nextPar(P) = nextPar(Q);
            prevPar(nextPar(Q)) = P;
            nextPar(Q) = Nil;
            prevPar(Q) = Nil;
        }
    }
}
void dAfterP(ListPar &L, address_P Prec, address_P &P){
    if (firstPar(L) != Nil){
        if (firstPar(L) == lastPar(L)){
            dFirstP(L,P);
        }else if(firstPar(L) == lastPar(L)){
            P = nextPar(Prec);
            nextPar(Prec) = nextPar(P);
            prevPar(nextPar(P)) = Prec;
            nextPar(P) = Nil;
            prevPar(P) = Nil;
        }
    }
}
void dLastP(ListPar &L, address_P &P){
    if (firstPar(L) != Nil){
        P = lastPar(L);
        lastPar(L) = prevPar(P);
        nextPar(lastPar(L)) = Nil;
        prevPar(P) = Nil;
    }
}
address_P findElmP(ListPar L, string x){
    address_P P;
    P = firstPar(L);
    while(P != Nil && infoPar(P) != x){
        P = nextPar(P);
    }
    return P;
}
void printInfoP(ListPar L){
    address_P P;
    int i;

    i = 1;
    cout<<"======================================================================"<<endl;
    cout<<endl;
    if (firstPar(L) != Nil){
        if (firstPar(L) == lastPar(L)){
            cout<<i<<". "<<infoPar(P)<<endl;
        }else{
            P = firstPar(L);
            while (nextPar(P) != firstPar(L)){
                cout<<i<<". "<<infoPar(P)<<endl;
                i++;
                P = nextPar(P);
            }
        }
    if (nextPar(P) == firstPar(L)){
        cout<<i<<". "<<infoPar(P)<<endl;
    }
    cout<<endl;
    cout<<"======================================================================"<<endl;
    }
}

