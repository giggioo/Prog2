#include <iostream>
#include <cstring>
#include "tipo.h"

int compare(tipo_inf p1,tipo_inf p2){
    if(p1.id == p2.id)
        return 0;
    if(p1.id < p2.id)
        return 1;
    else return -1;
}

void copy(tipo_inf& to,tipo_inf from){
    to.id = from.id;
    strcpy(to.nome, from.nome);
    to.tipo = from.tipo;
}

void print(tipo_inf p){
    std::cout<<p.id<<": "<<p.nome<<" ("<<p.tipo<<")"<<std::endl;
}
