#include <iostream>
#include <string.h>

using namespace std;

class Client
{
private:
    string numePrenume;
    int *varsta;
    char *sex;     // M sau F
    double rating; // intre 0 si 5
    int animaleDetinute;
    static int numarClienti;

public:
    //setters and getters
    void setNumePrenume(string numePrenumeNou) { numePrenume = numePrenumeNou; }
    void setVarsta(int *varstaNoua) { varsta = varstaNoua; }
    void setSex(char *sexNou) { sex = sexNou; }
    void setRating(double ratingNou) { rating = ratingNou; }
    void setAnimaleDetinute(int animaleDetinuteNou) { animaleDetinute = animaleDetinuteNou; }
    static void setNumarClienti(int numarClientiNou) { numarClienti = numarClientiNou; }

    string getNumePrenume() { return numePrenume; }
    int *getVarsta() { return varsta; }
    char *getSex() { return sex; }
    double getRating() { return rating; }
    int getAnimaleDetinute() { return animaleDetinute; }
    static int getNumarClienti() { return numarClienti; }

    //constructors
    Client();
    Client(string nP, int v);
    Client(string nP, double r, int aD);
    Client(string nP, int v, double r, int aD);
    Client(string nP, int v, char s, double r, int aD);

    //destructor
    ~Client();
};

int Client::numarClienti = 0;

// constructors
Client::Client()
{
    cout << "Constructor de initializare: " << endl;
    numePrenume = "Anonim";
    varsta = new int(0);
    sex = new char('-');
    rating = 0;
    animaleDetinute = 0;
    numarClienti++;
    cout << numePrenume << " cu varsta de " << *varsta << " ani si sexul " << *sex << ", are ratingul de " << rating << " puncte si a detinut " << animaleDetinute << " animale. " << endl;
}

Client::Client(string nP, int v)
{
    cout << "Constructor pentru clasa Client cu 2 parametrii: " << endl;
    numePrenume = nP;
    varsta = new int(v); // creaza un pointer cu valoarea din v
    numarClienti++;
    cout << numePrenume << " cu varsta de " << *varsta << " ani. " << endl;
}

Client::Client(string nP, double r, int aD)
{
    cout << "Constructor pentru clasa Client cu 3 parametrii: " << endl;
    numePrenume = nP;
    rating = r;
    animaleDetinute = aD;
    numarClienti++;
    cout << numePrenume << " are ratingul de " << rating << " puncte si a detinut " << animaleDetinute << " animale. " << endl;
}

Client::Client(string nP, int v, double r, int aD)
{
    cout << "Constructor pentru clasa Client cu 4 parametrii: " << endl;
    numePrenume = nP;
    varsta = new int(v);
    rating = r;
    animaleDetinute = aD;
    numarClienti++;
    cout << numePrenume << " cu varsta de " << *varsta << " ani, are ratingul de " << rating << " puncte si a detinut " << animaleDetinute << " animale. " << endl;
}

Client::Client(string nP, int v, char s, double r, int aD)
{
    cout << "Constructor pentru clasa Client cu 5 parametrii: " << endl;
    numePrenume = nP;
    varsta = new int(v);
    sex = new char(s);
    rating = r;
    animaleDetinute = aD;
    numarClienti++;
    cout << numePrenume << " cu varsta de " << *varsta << " ani si sexul " << *sex << ", are ratingul de " << rating << " puncte si a detinut " << animaleDetinute << " animale. " << endl;
}

// destructor
Client::~Client()
{
    cout << "Distruge: " << endl;
    cout << numePrenume << " " << *varsta << " " << *sex << " " << rating << " " << animaleDetinute << endl;
    delete varsta;
    delete sex;
}

class Animal
{
private:
    string nume;
    char sex; // M sau F
    bool esteCumparat;
    int varsta;
    bool areProblemeSpeciale; // 0: nu are probleme; 1: are probleme
    float greutate;
    float pret;
    static int numarAnimale;

public:
    // setters
    void setNume(string numeNou) { nume = numeNou; }
    void setSex(char sexNou) { sex = sexNou; }
    void setEsteCumparat(bool esteCumparatNou) { esteCumparat = esteCumparatNou; }
    void setVarsta(int varstaNou) { varsta = varstaNou; }
    void setAreProblemeSpeciale(bool areProblemeSpecialeNou) { areProblemeSpeciale = areProblemeSpecialeNou; }
    void setGreutate(float greutateNoua) { greutate = greutateNoua; }
    void setPret(float pretNou) { pret = pretNou; }
    static void setNumarAnimale(int numarAnimaleNou) { numarAnimale = numarAnimaleNou; }

    // getters
    string getNume() { return nume; }
    char getSex() { return sex; }
    bool getEsteCumparat() { return esteCumparat; }
    int getVarsta() { return varsta; }
    bool getAreProblemeSpeciale() { return areProblemeSpeciale; }
    float getGreutate() { return greutate; }
    float getPret() { return pret; }
    static int getNumarAnimale() { return numarAnimale; }

    // constructors
    Animal();
    Animal(string n, float p);
    Animal(string n, int v, float g);
    Animal(string n, bool eCump, bool aPS, float p);
    Animal(string n, char s, bool eCump, int v, bool aPS, float g, float p);

    // destructors
    ~Animal();
};

int Animal::numarAnimale = 0;

// constructors
Animal::Animal()
{
    cout << "Constructor de initializare: " << endl;
    nume = "Anonim";
    sex = '-';
    esteCumparat = 0;
    varsta = 0;
    areProblemeSpeciale = 0;
    greutate = 0;
    pret = 0;
    numarAnimale++;
}

Animal::Animal(string n, float p)
{
    cout << "Constructor pentru clasa Animal cu 2 parametrii: " << endl;
    nume = n;
    pret = p;
    numarAnimale++;
}

Animal::Animal(string n, int v, float g)
{
    cout << "Constructor pentru clasa Animal cu 3 parametrii: " << endl;
    nume = n;
    varsta = v;
    greutate = g;
    numarAnimale++;
}

Animal::Animal(string n, bool eCump, bool aPS, float p)
{
    cout << "Constructor pentru clasa Animal cu 4 parametrii: " << endl;
    nume = n;
    esteCumparat = eCump;
    areProblemeSpeciale = aPS;
    pret = p;
    numarAnimale++;
}

Animal::Animal(string n, char s, bool eCump, int v, bool aPS, float g, float p)
{
    cout << "Constructor pentru clasa Animal cu 7 parametrii: " << endl;
    nume = n;
    sex = s;
    esteCumparat = eCump;
    varsta = v;
    areProblemeSpeciale = aPS;
    greutate = g;
    pret = p;
    numarAnimale++;
}

// destructor
Animal::~Animal()
{
    cout << "Distruge: " << endl;
    cout << nume << endl;
}

class Eveniment
{
private:
    Client client;
    Animal animal;
    string data;
    char tipEveniment; // A : de adoptat; L : lasat spre adoptie

public:
    //setters
    void setClient(Client clientNou) { client = clientNou; }
    void setAnimal(Animal animalNou) { animal = animalNou; }
    void setData(string dataNoua) { data = dataNoua; }
    void setTipEveniment(char tipEvenimentNou) { tipEveniment = tipEvenimentNou; }

    // getters
    Client getClient() { return client; }
    Animal getAnimal() { return animal; }
    string getData() { return data; }
    char getTipEveniment() { return tipEveniment; }

    //constructors
    Eveniment();
    Eveniment(Client c, char tE);
    Eveniment(Client c, string d, char tE);
    Eveniment(Client c, Animal a, string d, char tE);

    //destructors
    ~Eveniment();
};

//constructors
Eveniment::Eveniment()
{
    //TO DO overload = for Client and Animal
}

Eveniment::Eveniment(Client c, char tE)
{
    client = c;
    tipEveniment = tE;
}

Eveniment::Eveniment(Client c, string d, char tE)
{
    client = c;
    data = d;
    tipEveniment = tE;
}

Eveniment::Eveniment(Client c, Animal a, string d, char tE)
{
    client = c;
    animal = a;
    data = d;
    tipEveniment = tE;
}

// destructor
Eveniment::~Eveniment()
{
    cout << "Distruge: " << endl;
    cout << client.getNumePrenume() << endl;
}

class Registru
{
private:
    const string numeMagazin = "NumeMagazin";
    Eveniment eveniment; //TO DO: schimba in lista de evenimente dupa ce rezolvam cu []
    int an;
    double bilant;

public:
    // setters
    void setEveniment(Eveniment evenimentNou) { eveniment = evenimentNou; }

    // getters
    Eveniment getEveniment() { return eveniment; }
    string getNumeMagazin() { return numeMagazin; }

    //cpnstructors
    Registru();
    Registru(Eveniment e);
    Registru(Eveniment e, int anNou);
    Registru(Eveniment e, int anNou, double b);

    // destructor
    ~Registru();
};

// constructors
Registru::Registru()
{ // overload la =
    an = 0;
    bilant = 0;
}

Registru::Registru(Eveniment e)
{
    eveniment = e;
}

Registru::Registru(Eveniment e, int anNou)
{
    eveniment = e;
    an = anNou;
}

Registru::Registru(Eveniment e, int anNou, double b)
{
    eveniment = e;
    an = anNou;
    bilant = b;
}

// destructor
Registru::~Registru()
{
    cout << "Distruge: " << endl;
    cout << eveniment.getClient().getNumePrenume() << endl;
}

int main()
{
    Client c1("popescu", 7), c2("ionescu", 5, 3);
    Eveniment e1(c1, "12.09.2021", 'A'), e2(c2, "222", 'N');
    Registru r1(e1);
    //Registru::setNumarClienti(2);
    //cout << Registru::getNumarClienti();
    return 0;
}