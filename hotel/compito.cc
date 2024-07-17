#include <iostream>
#include "bst.h"
#include <fstream>


using namespace std;

bst init(){
    bst tree = NULL;
    ifstream is;

    is.open("hotel.txt");
    
    char* numeroHotelChar = new char;
    is.get(numeroHotelChar,'\n');
    is.get();
    //is.getline(numeroHotelChar,1,'\n');
    int numeroHotel = atoi(numeroHotelChar);

    for(int i=0;i<numeroHotel;i++){
        tipo_inf h = new hotel;
        char* numeroStelle = new char;
        is.getline(numeroStelle,2,'\n');
        h->numeroStelle = atoi(numeroStelle);
        is.getline(h->nome,21,'\n');
        is.getline(h->luogo,21,'\n');

        bnode* elem = bst_newNode(atoi(numeroStelle),h);
        bst_insert(tree, elem);
    }

    return tree;

}

void stampa(bst tree){
    if(get_right(tree)!=NULL)
        stampa(get_right(tree));
    print(get_value(tree));
    if(get_left(tree)!=NULL)
        stampa(get_left(tree));
    
}


int main(int argc, char* argv[]){
    
    if(argc<=1){
        cout<<"Usage: "<<argv[0]<<" file.txt"<<endl;
        exit(0);
    }

    bst tree = init();
    stampa(tree);
    
    return 0;
}