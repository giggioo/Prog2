#include <iostream>
#include <fstream>
#include "liste.h"
#include "grafo.h"

using namespace std;

int carica(lista& pi){
    ifstream is;
    is.open("PI.txt");
    int quantiPI = 0;
    tipo_inf luogo;
    elem* e;
    while(!is.eof()){
        char buffer[256];
        is.getline(buffer,256,'\n');
        luogo.id=atoi(buffer);
        is.getline(luogo.nome, 21, '\n');
        is.get(luogo.tipo);
        is.ignore();
        e = new_elem(luogo);
        pi = ord_insert_elem(pi, e);
        quantiPI++;
    }
    return quantiPI;
}

tipo_inf search_pi(lista pi, int id){
    int n_elem = head(pi).id;
    for(int i=n_elem-id;i>0;i--){
        pi=tail(pi);
    }
    return head(pi);
}

void stampa(lista l){
    cout<<endl;
    while(tail(l)!=NULL){
        print(head(l));
        l=tail(l);
    }
}

graph mappa(int n){
    graph g = new_graph(n);
    ifstream is;
    is.open("G.txt");
    char buffer[512];
    char token[256];
    int u,v;
    while(!is.eof()){
        is.getline(buffer, 512, '\n');
        strcpy(token,strtok(buffer," "));
        u = atoi(token);
        strcpy(token,strtok(NULL,"\n"));
        v = atoi(token);
        add_edge(g,u,v,1);
    }
    return g;
}

void stampa_mappa(graph g, lista pi){
    
    /*
    while(g.nodes!=NULL){
        tipo_inf pi_in_graph = search_pi(pi,(*g.nodes)->node);
        cout<<pi_in_graph.nome<<" connesso a: ";
        while((*g.nodes)->next!=NULL){
            cout<<search_pi(pi,(*g.nodes)->node).nome<<" ";
            *(g.nodes) = (*g.nodes)->next;
        }
        cout<<endl;
        g.nodes = get_nextadj(g.nodes);
    }
    */

   

}

int main(int argc, char const *argv[]){
    
    lista pi = new elem;
    int dim=carica(pi);
    //cin>>quale;
    //print(search_pi(pi,quale));
    mappa(dim);

    return 0;
}
