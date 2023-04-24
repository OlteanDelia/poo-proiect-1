#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;
class Punct2D
{
    int x , y;
public:
    Punct2D(); //constructor fara parametrii;
    Punct2D(int x);
    Punct2D(int x, int y);
    Punct2D( const Punct2D&); // constructor de copiere;
    ~Punct2D(); //destructor;
    friend Punct2D& operator+( Punct2D&, Punct2D &);
    Punct2D& operator=(const Punct2D&);//operator de atribuire;
    friend istream& operator>>(istream&, Punct2D&);//citire;
    friend ostream& operator<<(ostream&, Punct2D&);//afisare;

    int get_x()//getter de parametru(din private)
    {
        return x;
    }

    int get_y()//getter de parametru(din private)
    {
        return y;
    }

    void set_x(int x)//modifica valoarea unui parametru din private
    {
        this->x = x;
    }

    void set_y(int y)//modifica valoarea unui parametru din private
    {
        this->y = y;
    }
};

Punct2D :: Punct2D()//constructor fara parametrii;
{
    x = 0;
    y = 0;
}

Punct2D :: Punct2D(int x)//constructor cu un parametru din cei 2
{
    this->x = x;
}

Punct2D :: Punct2D(int x, int y)//constructor cu 2/toti parametrii
{
    this->x = x;
    this->y = y;
}

Punct2D :: Punct2D(const Punct2D &p)//constructor de copiere
{
    this->x = p.x;
    this->y = p.y;
}

Punct2D :: ~Punct2D(){}//destructor

Punct2D &Punct2D :: operator = (const Punct2D &p)//operator de atribuire
{
    if(this != &p)
    {
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

Punct2D& operator+(Punct2D& p1, Punct2D&  p2)
{
    Punct2D p3;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;


}


istream& operator>>(istream &in, Punct2D &punct)//citire punct
{
    in >> punct.x >> punct.y;
    return in;
}

ostream& operator<<(ostream &out, Punct2D &punct)//afisare punct
{
    out << punct.x << " " << punct.y;
    return out;
}


class Figura
{
    char *denumire;
    int nrPuncte;
    vector <Punct2D> P;
public:
    Figura(); //constructor fara parametri;
    Figura(char *denumire, int nrPuncte);//constructor cu 2 parametrii
    Figura(char *denumire, int nrPuncte, vector<Punct2D> P);//constructor cu toti parametrii
    Figura( const Figura&); // constructor de copiere;
    ~Figura(); //destructor;
    Figura& operator=(const Figura&);//operator de atribuire;
    friend istream& operator>>(istream&, Figura&);//citire;
    friend ostream& operator<<(ostream&, Figura&);//afisare
    Figura& operator +=(Punct2D pct);//operator de adaugare punct si schimbare denumire figura
    bool operator != (const Figura &fig); //operator de comparare(verifica daca s la fel sau diferite)

    char* get_den()//getter de parametru(din private)
    {
        return denumire;
    }

    int get_nrPuncte()//getter de parametru(din private)
    {
        return nrPuncte;
    }

    char *getDenumire() const//getter de parametru(din private)
    {
        return denumire;
    }

    void setDenumire(char *denumire)//modifica valoarea unui parametru din private
    {
        this->denumire=new char[strlen(denumire)+1];
        strcpy( this->denumire, denumire);
    }

    void setNrPuncte(int nrPuncte) //modifica valoarea unui parametru din private
    {
        this->nrPuncte = nrPuncte;
    }

    vector<Punct2D> get_P()//getter de parametru(din private)
    {
        return P;
    }

    void setPuncte(vector<Punct2D> vector1) //modifica valoarea unui parametru din private
    {
        for (int i=0; i<vector1.size(); i++)
        {
            this->P[i] = vector1[i];
        }
    }

};

bool Figura :: operator != (const Figura &fig)
{
    if(this->denumire != fig.denumire || this->nrPuncte != fig.nrPuncte)
        return true;
    return false;
}

Figura :: Figura()//constructor fara parametrii;
{
    denumire = NULL;
    nrPuncte = 0;
    P = {};
}

Figura :: Figura(char *denumire, int nrPuncte) //constructor cu 2 parametrii
{
    this->denumire=new char[strlen(denumire)+1];
    strcpy( this->denumire, denumire);
    this->nrPuncte = nrPuncte;

}

Figura :: Figura(char *denumire, int nrPuncte, vector <Punct2D> P) //constructor cu toti parametrii
{
    this->denumire=new char[strlen(denumire)+1];
    strcpy( this->denumire, denumire);

    this->nrPuncte = nrPuncte;
    this->P = P;
}

Figura :: Figura(const Figura &f) //copyconstructor
{
    this->denumire=new char[strlen(f.denumire)+1];
    strcpy( this->denumire, f.denumire);
    this->nrPuncte = f.nrPuncte;
    this->P = f.P;
}

Figura :: ~Figura()
{
    if(this->denumire != NULL)
        delete[] this->denumire;
}

Figura &Figura :: operator = (const Figura &f)
{
    if(this != &f)
    {
        this->denumire = f.denumire;
        this->nrPuncte = f.nrPuncte;
        this->P = f.P;
    }
    return *this;

}

Figura  &Figura :: operator += (Punct2D pct)
{
    this->P.push_back(pct);
    int nr = this->get_nrPuncte();
    nr = nr + 1;
    this->setNrPuncte(nr);
    if(nr == 2)
    {
        char aux[100];
        strcpy(aux, "segment");
        this->setDenumire(aux);
    }
    if(nr == 3)
    {
        char aux[100];
        strcpy(aux, "triunghi");
        this->setDenumire(aux);
    }
    if(nr == 4)
    {
        char aux[100];
        strcpy(aux, "patrulater");
        this->setDenumire(aux);
    }
    if(nr == 5)
    {
        char aux[100];
        strcpy(aux, "pentagon");
        this->setDenumire(aux);
    }
    if(nr == 6)
    {
        char aux[100];
        strcpy(aux, "hexagon");
        this->setDenumire(aux);
    }
    if(nr == 7)
    {
        char aux[100];
        strcpy(aux, "heptagon");
        this->setDenumire(aux);
    }
    if(nr == 8)
    {
        char aux[100];
        strcpy(aux, "octagon");
        this->setDenumire(aux);
    }


}

istream& operator >> (istream &in, Figura &fig)//citire figura
{
    char aux[255];
    in >> aux;
    fig.denumire = new char[strlen(aux)+1];
    strcpy(fig.denumire , aux);

    in >> fig.nrPuncte;

    for(int i = 0; i < fig.nrPuncte; i++)
    {
        int x,y;
        in>>x>>y;
        Punct2D aux(x,y);
        fig.P.push_back(aux);
    }
    return in;
}
ostream& operator << (ostream &out, Figura &fig)//afisare figura
{
    out << fig.denumire<<endl;
    out << fig.nrPuncte<<endl;

    vector<Punct2D>::iterator i;
    for(i = fig.P.begin(); i != fig.P.end(); i++)
        out << *i <<endl;

    return out;
}



class Geometrie
{
    int nrFiguri;
    vector <Figura> fig;
public:
    Geometrie(); //constructor fara parametrii;
    Geometrie(int nrFiguri, vector <Figura> fig); ///constructor cu toti parametrii
    //Geometrie(int nrFiguri, char *denumire, int nrPuncte, vector <Punct2D> P);
    Geometrie( const Geometrie&); // constructor de copiere;
    ~Geometrie(); //destructor;
    Geometrie& operator=(const Geometrie&);//operator de atribuire;
    friend istream& operator>>(istream&, Geometrie&);//citire;
    friend ostream& operator<<(ostream&, Geometrie&);//afisare;
    Geometrie& operator -=(int pct); //

    vector<Figura> get_fig()
    {
        return this->fig;
    }

};


Geometrie :: Geometrie()//constructor fara parametrii;
{
    nrFiguri = 0;
    fig = {};
}

Geometrie :: Geometrie(int nrFiguri, vector <Figura> fig)//constructor cu parametrii;
{
    this->nrFiguri = nrFiguri;
    this->fig = fig;
}
/*
Geometrie::Geometrie(int nrFiguri, char *denumire, int nrPuncte, vector<Punct2D> P) {
    this->nrFiguri = nrFiguri;
    this->fig[0].setDenumire(denumire);
    this->fig[0].setNrPuncte(nrPuncte);
    this->fig[0].setPuncte(P);
}
*/

Geometrie::Geometrie(const Geometrie &g)
{
    this->fig = g.fig;
    this->nrFiguri = g.nrFiguri;
}

Geometrie :: ~Geometrie(){}

Geometrie &Geometrie :: operator=(const Geometrie &g)
{
    if(this != &g)
    {
        this->nrFiguri = g.nrFiguri;
        this->fig = g.fig;
    }

    return *this;
}

Geometrie &Geometrie ::operator-=(int pct)
{
    vector<Figura>f;
    f = this->get_fig();
    int nr = f[0].get_nrPuncte();
    nr = nr - 1;


    vector<Punct2D>p,auxx;
    p = f[0].get_P();
    int nrp = 0;
    vector<Punct2D>::iterator i;
    for(i = p.begin(); i != p.end(); i++)
    {
        nrp++;
        if(nrp != pct)
            auxx.push_back(*i);
    }
    f[0].setPuncte(auxx);
    f[0].setNrPuncte(nr);
    if(nr == 1)
    {
        char aux[100];
        strcpy(aux, "punct");
        f[0].setDenumire(aux);
    }
    if(nr == 2)
    {
        char aux[100];
        strcpy(aux, "segment");
        f[0].setDenumire(aux);
    }
    if(nr == 3)
    {
        char aux[100];
        strcpy(aux, "triunghi");
        f[0].setDenumire(aux);
    }
    if(nr == 4)
    {
        char aux[100];
        strcpy(aux, "patrulater");
        f[0].setDenumire(aux);
    }
    if(nr == 5)
    {
        char aux[100];
        strcpy(aux, "pentagon");
        f[0].setDenumire(aux);
    }
    if(nr == 6)
    {
        char aux[100];
        strcpy(aux, "hexagon");
        f[0].setDenumire(aux);
    }
    if(nr == 7)
    {
        char aux[100];
        strcpy(aux, "heptagon");
        f[0].setDenumire(aux);
    }
    if(nr == 8)
    {
        char aux[100];
        strcpy(aux, "octagon");
        f[0].setDenumire(aux);
    }
}

istream& operator>>(istream &in, Geometrie &geom)//citire geometrie
{
    in >> geom.nrFiguri;
    for(int i = 0; i < geom.nrFiguri; i++)
    {
        Figura f;
        in>>f;
        geom.fig.push_back(f);
    }
    return in;
}

ostream& operator<<(ostream &out, Geometrie &geom)
{
    out<<"Nr. fig. geom este de: "<<geom.nrFiguri<<endl;
    vector<Figura>::iterator i;
    for(i = geom.fig.begin(); i != geom.fig.end(); i++)
        out << *i <<endl;

    return out;
}

int main()
{/*
    Punct2D p1(1,-1), p2(2), p3[4];
    for( int x=0;x<4;x++)
    {
        cout <<" introdu coordonate punct"<<endl;
        cin >> p3[x];
    }
    */
    Punct2D v[4];
    cin>>v[1];
    cout<<v[1]<<endl;
    v[2]=v[3]= v[1]+v[1];

    cout<<v[2]<<endl;
    cout<<v[3];
/*
    vector <Punct2D> p4;
    p4.push_back(p1);
    p4.push_back(p2);
    Figura f1("triunghi dreptunghic", 3);
    cout<<f1<<endl;
    Figura f2("Segment", 2, p4);
    Figura f3[2];
    cout << "Da exemplu de figura"<<endl;
    cin>>f3[0];
    f3[1] = f3[0];
    f3[1] += p1;//Adauga un punct unei figuri si schimba denumirea acesteia
    if (f1 != f3[1])
        cout<<"figura f1 diferita de figura f3[1]"<<endl;
    else cout<<"figurile sunt identice"<<endl;

    vector <Figura> ff3;
    ff3.push_back(f3[0]);
    ff3.push_back(f3[1]);
    Geometrie g1, g2(2, ff3);
    Punct2D p51(0,0),p52(0,1),p53(1,1),p54(1,0);
    vector <Punct2D> p5(4);
    p5[0]=(p51);
    p5.push_back(p52);
    p5.push_back(p53);
    p5.push_back(p54);
    Figura f5("patrat", 4, p5);

    vector <Figura> vf5;
    vf5.push_back(f5);
    Geometrie g3(1, vf5), g4;
    g4 = g3;
    cout<<"Citim o geometrie:"<<endl;
    cin>>g1;
    g3 -= 1; //sterge primul punct, decrementeaza nr de puncte si schimba denumirea in “triunghi”
    cout<<g3<<g4;
*/
    return 0;
}

