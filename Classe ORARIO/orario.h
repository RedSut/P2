class orario{
    private:
    int sec;
    public:
    orario(int=0,int=0,int=0);
    operator int();
    int Ore()const;
    int Minuti()const;
    int Secondi()const;
    orario UnOraPiuTardi()const;
    void AvanzaUnOra();
};