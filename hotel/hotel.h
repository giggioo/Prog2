struct hotel{
    int numeroStelle;
    char nome[20];
    char luogo[20];
};

typedef hotel* tipo_inf;

void copy(tipo_inf&, tipo_inf);
void print(tipo_inf);