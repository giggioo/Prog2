#include "hotel.h"
#include <iostream>
#include <cstring>

using namespace std;

void copy(tipo_inf& to, tipo_inf from){
    to = new hotel;
    to->numeroStelle = from->numeroStelle;
    strcpy(to->nome, from->nome);
    strcpy(to->luogo, from->luogo);
}

void print(tipo_inf h){
    cout<<"Hotel "<<h->nome<<", "<<h->luogo<<", "<<h->numeroStelle<<"stelle"<<endl;
}