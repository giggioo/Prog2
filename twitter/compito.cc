#include <iostream>
#include <fstream>
#include "grafi.h"
#include "node.h"

using namespace std;

graph initGraph(){
    ifstream is;
    is.open("graph");
    int nNodi;
    is>>nNodi;
    graph g = new_graph(nNodi);
    int nodo_s, nodo_d;
    while(is>>nodo_s>>nodo_d)
        add_arc(g,nodo_s,nodo_d,1);
    return g;
}

void stampa(graph g, node* n){
    adj_list elem;
    for(int i=1;i<=get_dim(g);i++){
        elem = get_adjlist(g,i);
        while(elem!=NULL){
            cout<<n[i].cont<<"-->"<<n[get_adjnode(elem)].cont<<endl;
            elem = get_nextadj(elem);
        }
    }
    cout<<endl;
}

void initNodi(node* n){
    ifstream is;
    is.open("node");
    char content[81];
    int pos = 1;
    while(is.getline(content,81,'\n')){
        strcpy(n[pos].cont, content);
        is.ignore();
        is.get(n[pos].tipo);
        pos++;
    }
}

int main(int argc, char const *argv[]){
    
    graph g = initGraph();
    node nodi[get_dim(g)+1];
    initNodi(nodi);
    stampa(g,nodi);



    return 0;
}
