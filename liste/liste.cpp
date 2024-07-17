#include <iostream>
using namespace std;

struct elem{
    int val;
    elem* next;
};

typedef elem* lista;

int head(lista l){return l->val;}
lista tail(lista l){return l->next;}

void stampalista(lista l){
    while(l!=NULL){
        cout<<head(l)<<" ";
        l=tail(l);
    }
    cout<<endl;
}

lista insert_elem(lista l, elem* e){
    e->next = l;
    return e;
}

lista crea_lista(int n){
    lista l=NULL;
    for(;n>0;n--){
        elem *e = new elem;
        cout<<"Valore: ";
        cin>>e->val;
        l=insert_elem(l,e);
    }
    return l;
}

lista delete_elem(lista l, elem* e){
    if(l==e){
        l=tail(l);
    }
    else{
        lista l_appoggio=l;
        while(tail(l_appoggio)!=e){
            l_appoggio=tail(l_appoggio);
        }
        l_appoggio->next=tail(tail(l_appoggio));
    }
    delete e;
    return l;
}

void eliminalista(lista &l){
    while(l!=NULL){l=delete_elem(l,l);}
}

elem* search(lista l, int val){
    while(l!=NULL){
        if(head(l)==val)
            return l;
        else
            l=tail(l);
    }
    return NULL;
}

int conta(lista l, int v){
    int occorrenze = 0;
    while((l=search(l,v))!=NULL){
        occorrenze++;
        l=tail(l);
    }
    return occorrenze;
}

lista cancella(lista l, int v){
    for(int i=conta(l,v);i>0;i--){
        l=delete_elem(l,search(l,v));
    }
    return l;
}

lista copy(lista l){
    lista new_lista = NULL;
    elem* new_elem;
    elem* last_in = NULL;
    
    while(l!=NULL){
        new_elem = new elem;
        new_elem->val = head(l);
        new_elem->next=NULL;
        if(last_in==NULL){
            // esegue solo una volta, sto inserendo la testa della lista.
            new_lista=new_elem;
        }else{
            last_in->next=new_elem;
        }
        last_in = new_elem;
        l=tail(l);
    }
    return new_lista;
}

int main(int argc, char const *argv[])
{

    lista l = crea_lista(3);
    elem* e1 = new elem;
    e1->val=1;
    elem* e2 = new elem;
    e2->val=2;
    l = insert_elem(l,e1);
    l = insert_elem(l,e2);
    stampalista(l);
    l=cancella(l,1);
    stampalista(l);
    lista l2 = copy(l);
    stampalista(l2);
    return 0;
}
