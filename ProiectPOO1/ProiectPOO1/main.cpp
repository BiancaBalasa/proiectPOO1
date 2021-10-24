#include <iostream>
#include <string.h>

using namespace std;

//TO DO:
//Overload de [] la toate clase
//Modificat fieldu eveniment de tip Eveniment din registru sa fie numit evenimente si sa fie de tip Eveniment[]
//implicit modificat tot ce trebuie din Registru ca sa fie corect
//overload de +, de == de ++ 

class Client
{
private:
    string numePrenume;
    int* varsta;
    char* sex;     // M sau F
    double rating; // intre 0 si 5
    int animaleDetinute;
    static int numarClienti;

public:
    //setters and getters
    void setNumePrenume(string numePrenume) { this->numePrenume = numePrenume; }
    void setVarsta(int* varsta) { this->varsta = varsta; }
    void setSex(char* sex) { this->sex = sex; }
    void setRating(double rating) { this->rating = rating; }
    void setAnimaleDetinute(int animaleDetinute) { this->animaleDetinute = animaleDetinute; }
    static void setNumarClienti(int numarClientiNou) { numarClienti = numarClientiNou; }

    string getNumePrenume() { return this->numePrenume; }
    int* getVarsta() { return this->varsta; }
    char* getSex() { return this->sex; }
    double getRating() { return this->rating; }
    int getAnimaleDetinute() { return this->animaleDetinute; }
    static int getNumarClienti() { return numarClienti; }

    //constructors
    Client();
    Client(string numePrenume, int varsta);
    Client(string numePrenume, double rating, int animaleDetinute);
    Client(string numePrenume, int varsta, double rating, int animaleDetinute);
    Client(string numePrenume, int varsta, char sex, double rating, int animaleDetinute);

    // copy constructor
    Client(const Client& other);

    // overload operator=
    Client& operator=(const Client& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, const Client& c);
    
    // overload operator>>
    friend istream& operator>>(istream& in, Client& c);
    
    //destructor
    ~Client();
};

int Client::numarClienti = 0;

// constructors
Client::Client()
{
    cout << "Constructor de initializare: " << endl;
    this->numePrenume = "Anonim";
    this->varsta = new int(0);
    this->sex = new char('-');
    this->rating = 0;
    this->animaleDetinute = 0;
    numarClienti++;
    cout << this->numePrenume << " cu varsta de " << *this->varsta << " ani si sexul " << *this->sex << ", are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

Client::Client(string numePrenume, int varsta)
{
    cout << "Constructor pentru clasa Client cu 2 parametrii: " << endl;
    this->numePrenume = numePrenume;
    this->varsta = new int(varsta); // creaza un pointer cu valoarea din v
    numarClienti++;
    cout << this->numePrenume << " cu varsta de " << *this->varsta << " ani. " << endl;
}

Client::Client(string numePrenume, double rating, int animaleDetinute)
{
    cout << "Constructor pentru clasa Client cu 3 parametrii: " << endl;
    this->numePrenume = numePrenume;
    this->rating = rating;
    this->animaleDetinute = animaleDetinute;
    numarClienti++;
    cout << this->numePrenume << " are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

Client::Client(string numePrenume, int varsta, double rating, int animaleDetinute)
{
    cout << "Constructor pentru clasa Client cu 4 parametrii: " << endl;
    this->numePrenume = numePrenume;
    this->varsta = new int(varsta);
    this->rating = rating;
    this->animaleDetinute = animaleDetinute;
    numarClienti++;
    cout << this->numePrenume << " cu varsta de " << *this->varsta << " ani, are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

Client::Client(string numePrenume, int varsta, char sex, double rating, int animaleDetinute)
{
    cout << "Constructor pentru clasa Client cu 5 parametrii: " << endl;
    this->numePrenume = numePrenume;
    this->varsta = new int(varsta);
    this->sex = new char(sex);
    this->rating = rating;
    this->animaleDetinute = animaleDetinute;
    numarClienti++;
    cout << this->numePrenume << " cu varsta de " << *this->varsta << " ani si sexul " << *this->sex << ", are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

//copy constructor
Client::Client(const Client& other)
{
    this->numePrenume = other.numePrenume;
    if (other.varsta != NULL)
        this->varsta = new int(*other.varsta);
    else
        this->varsta = new int();
    if (other.sex != NULL)
        this->sex = new char(*other.sex);
    else
        this->sex = new char();

    this->rating = other.rating;
    this->animaleDetinute = other.animaleDetinute;
}

// overload operator=
Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        if (this->varsta != NULL)
            delete this->varsta;
        if (this->sex != NULL)
            delete this->sex;

        this->numePrenume = other.numePrenume;
        this->varsta = new int(*other.varsta);
        this->sex = new char(*other.sex);
        this->rating = other.rating;
        this->animaleDetinute = other.animaleDetinute;
    }
    return *this;

}

// overload operator<<
ostream& operator<<(ostream& out, const Client& c)
{
    out << c.numePrenume << " " << *c.varsta << " " << *c.sex << " " << c.rating << " " << c.animaleDetinute << endl;
    return out;
}

// overload operator>>
istream& operator>>(istream& in, Client& c)
{
    cout << "Nume Prenume: " << endl;
    in >> c.numePrenume;
    cout << "Varsta: " << endl;
    in >> *c.varsta;
    cout << "Sex: " << endl;
    in >> *c.sex;
    cout << "Rating: " << endl;
    in >> c.rating;
    cout << "Animale detinute: " << endl;
    in >> c.animaleDetinute;
    return in;
}

// destructor
Client::~Client()
{
    cout << "Distruge clientul: " << endl;
    cout << this->numePrenume << endl;
    delete this->varsta;
    delete this->sex;
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
    void setNume(string nume) { this->nume = nume; }
    void setSex(char sex) { this->sex = sex; }
    void setEsteCumparat(bool esteCumparat) { this->esteCumparat = esteCumparat; }
    void setVarsta(int varsta) { this->varsta = varsta; }
    void setAreProblemeSpeciale(bool areProblemeSpeciale) { this->areProblemeSpeciale = areProblemeSpeciale; }
    void setGreutate(float greutate) { this->greutate = greutate; }
    void setPret(float pret) { this->pret = pret; }
    static void setNumarAnimale(int numarAnimaleNou) { numarAnimale = numarAnimaleNou; }

    // getters
    string getNume() { return this->nume; }
    char getSex() { return this->sex; }
    bool getEsteCumparat() { return this->esteCumparat; }
    int getVarsta() { return this->varsta; }
    bool getAreProblemeSpeciale() { return this->areProblemeSpeciale; }
    float getGreutate() { return this->greutate; }
    float getPret() { return this->pret; }
    static int getNumarAnimale() { return numarAnimale; }

    // constructors
    Animal();
    Animal(string nume, float pret);
    Animal(string nume, int varsta, float greutate);
    Animal(string nume, bool esteCumparat, bool areProblemeSpeciale, float pret);
    Animal(string nume, char sex, bool eesteCumparat, int varsta, bool areProblemeSpeciale, float greutate, float pret);

    //copy constructor
    Animal(const Animal& other);

    // overload operator=
    Animal& operator=(const Animal& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, const Animal& a);

    //overload operator>>
    friend istream& operator>>(istream& in, Animal& a);


    // destructor
    ~Animal();

    
};

int Animal::numarAnimale = 0;

// constructors
Animal::Animal()
{
    cout << "Constructor de initializare: " << endl;
    this->nume = "Anonim";
    this->sex = '-';
    this->esteCumparat = false;
    this->varsta = 0;
    this->areProblemeSpeciale = false;
    this->greutate = 0;
    this->pret = 0;
    numarAnimale++;
}

Animal::Animal(string nume, float pret)
{
    cout << "Constructor pentru clasa Animal cu 2 parametrii: " << endl;
    this->nume = nume;
    this->pret = pret;
    numarAnimale++;
}

Animal::Animal(string nume, int varsta, float greutate)
{
    cout << "Constructor pentru clasa Animal cu 3 parametrii: " << endl;
    this->nume = nume;
    this->varsta = varsta;
    this->greutate = greutate;
    numarAnimale++;
}

Animal::Animal(string nume, bool esteCumparat, bool areProblemeSpeciale, float pret)
{
    cout << "Constructor pentru clasa Animal cu 4 parametrii: " << endl;
    this->nume = nume;
    this->esteCumparat = esteCumparat;
    this->areProblemeSpeciale = areProblemeSpeciale;
    this->pret = pret;
    numarAnimale++;
}

Animal::Animal(string nume, char sex, bool esteCumparat, int varsta, bool areProblemeSpeciale, float greutate, float pret)
{
    cout << "Constructor pentru clasa Animal cu 7 parametrii: " << endl;
    this->nume = nume;
    this->sex = sex;
    this->esteCumparat = esteCumparat;
    this->varsta = varsta;
    this->areProblemeSpeciale = areProblemeSpeciale;
    this->greutate = greutate;
    this->pret = pret;
    numarAnimale++;
}

// copy constructor
Animal::Animal(const Animal& other)
{
    this->nume = other.nume;
    this->sex = other.sex;
    this->esteCumparat = other.esteCumparat;
    this->varsta = other.varsta;
    this->areProblemeSpeciale = other.areProblemeSpeciale;
    this->greutate = other.greutate;
    this->pret = other.pret;
}

// overload operator=
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->nume = other.nume;
        this->sex = other.sex;
        this->esteCumparat = other.esteCumparat;
        this->varsta = other.varsta;
        this->areProblemeSpeciale = other.areProblemeSpeciale;
        this->greutate = other.greutate;
        this->pret = other.pret;
    }
    return *this;
}

// overload operator<<
ostream& operator<<(ostream& out, const Animal& a)
{
    out << a.nume << " " << a.sex << " " << a.esteCumparat << " " << a.varsta << " " << a.areProblemeSpeciale << " " << a.greutate << " " << a.pret << endl;
    return out;
}

// overload operator>>
istream& operator>>(istream& in,  Animal& a)
{
    cout << "Nume: "<<endl;
    in >> a.nume;
    cout << "Sex: " << endl;
    in >> a.sex;
    cout << "Este cumparat: " << endl;
    in >> a.esteCumparat;
    cout << "Varsta: " << endl;
    in >> a.varsta;
    cout << "Are probleme speciale: " << endl;
    in >> a.areProblemeSpeciale;
    cout << "Greutate: " << endl;
    in >> a.greutate;
    cout << "Pret: " << endl;
    in >> a.pret;
    return in;
}

// destructor
Animal::~Animal()
{
    cout << "Distruge animalul: " << endl;
    cout << this->nume << endl;
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
    void setClient(Client client) { this->client = client; }
    void setAnimal(Animal animal) { this->animal = animal; }
    void setData(string data) { this->data = data; }
    void setTipEveniment(char tipEveniment) { this->tipEveniment = tipEveniment; }

    // getters
    Client getClient() { return this->client; }
    Animal getAnimal() { return this->animal; }
    string getData() { return this->data; }
    char getTipEveniment() { return this->tipEveniment; }

    //constructors
    Eveniment();
    Eveniment(Client client, char tipEveniment);
    Eveniment(Client client, string data, char tipEveniment);
    Eveniment(Client client, Animal animal, string data, char tipEveniment);

    // copy constructor
    Eveniment(const Eveniment& other);

    // overload operator=
    Eveniment& operator=(const Eveniment& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, const Eveniment& e);

    // overload operator>>
    friend istream& operator>>(istream& in, Eveniment& e);

    //destructors
    ~Eveniment();
};

//constructors
Eveniment::Eveniment()
{
    this->data = "DD/MM/YYYY";
    this->tipEveniment = 'X';
}

Eveniment::Eveniment(Client client, char tipEveniment)
{
    this->client = client;
    this->tipEveniment = tipEveniment;
}

Eveniment::Eveniment(Client client, string data, char tipEveniment)
{
    this->client = client;
    this->data = data;
    this->tipEveniment = tipEveniment;
}

Eveniment::Eveniment(Client client, Animal animal, string data, char tipEveniment)
{
    this->client = client;
    this->animal = animal;
    this->data = data;
    this->tipEveniment = tipEveniment;
}

// copy constructor
Eveniment::Eveniment(const Eveniment& other)
{
    this->client = other.client;
    this->animal = other.animal;
    this->data = other.data;
    this->tipEveniment = other.tipEveniment;
}

// overload operator=
Eveniment& Eveniment::operator=(const Eveniment& other)
{
    if (this != &other)
    {
        this->client = other.client;
        this->animal = other.animal;
        this->data = other.data;
        this->tipEveniment = other.tipEveniment;
    }
    return *this;
}

// overload operator<<
ostream& operator<<(ostream& out, const Eveniment& e)
{
    out << e.client << " " << e.animal << " " << e.data << " " << e.tipEveniment << endl;
    return out;
}

// overload operator>>
istream& operator>>(istream& in, Eveniment& e)
{
    cout << "Client: " << endl;
    in >> e.client;
    cout << "Animal: " << endl;
    in >> e.animal;
    cout << "Data: " << endl;
    in >> e.data;
    cout << "Tip eveniment: " << endl;
    in >> e.tipEveniment;
    return in;
}

// destructor
Eveniment::~Eveniment()
{
    cout << "Distruge evenimentul pentru clientul: " << endl;
    cout << this->client.getNumePrenume() << endl;
}

class Registru
{
private:
    const string numeMagazin = "Lumea Animalelor";
    Eveniment eveniment; //TO DO: schimba in lista de evenimente dupa ce rezolvam cu []
    int nrEvenimente;
    int an;
    double bilant;

public:
    // setters
    void setEveniment(Eveniment eveniment) { this->eveniment = eveniment; }
    void setNrEveniment(int nrEveniment) { this->nrEvenimente = nrEvenimente; }
    void setAn(int an) { this->an = an; }
    void setBilant(double bilant) { this->bilant = bilant; }

    // getters
    Eveniment getEveniment() { return this->eveniment; }
    int getNrEvenimente() { return this->nrEvenimente; }
    int getAn() { return this->an; }
    double getBilant() { return this->bilant; }
    string getNumeMagazin() { return this->numeMagazin; }

    //constructors
    Registru();
    Registru(Eveniment eveniment);
    Registru(Eveniment eveniment, int an);
    Registru(Eveniment eveniment,int nrEvenimente, int an, double bilant);

    // copy constructor
    Registru(const Registru& other);

    // overload operator=
    Registru& operator=(const Registru& other);

    //overload operator<<
    friend ostream& operator<<(ostream& out, const Registru& r);

    //overload operator>>
    friend istream& operator>>(istream& in, Registru& r);

    // destructor
    ~Registru();
};

// constructors
Registru::Registru()
{ // overload la =
    this->nrEvenimente = 0;
    this->an = 0;
    this->bilant = 0;
}

Registru::Registru(Eveniment eveniment)
{
    this->nrEvenimente = 0;
    this->eveniment = eveniment;
}

Registru::Registru(Eveniment eveniment, int an)
{
    this->nrEvenimente = 0;
    this->eveniment = eveniment;
    this->an = an;
}

Registru::Registru(Eveniment eveniment,int nrEvenimente, int an, double bilant)
{
    this->nrEvenimente = nrEvenimente;
    this->eveniment = eveniment;
    this->an = an;
    this->bilant = bilant;
}

// copy constructor
Registru::Registru(const Registru& other)
{
    this->eveniment = other.eveniment;
    this->an = other.an;
    this->bilant = other.bilant;
}

// overload operator<<
ostream& operator<<(ostream& out, const Registru& r)
{
    out << r.numeMagazin << " " << r.eveniment << " " << r.an << " " << r.bilant << endl;
    return out;
}

//overload operator>>
istream& operator>>(istream& in, Registru& r)
{
    cout << "Eveniment: " << endl;
    in >> r.eveniment;
    cout << "An: " << endl;
    in >> r.an;
    cout << "Bilant: " << endl;
    in >> r.bilant;
    return in;

}

//overload operator=
Registru& Registru::operator=(const Registru& other)
{
    if (this != &other)
    {
        this->eveniment = other.eveniment;
        this->an = other.an;
        this->bilant = other.bilant;
    }
    return *this;
}

// destructor
Registru::~Registru()
{
    cout << "Distruge din registru evenimentul pentru clientul: " << endl;
    cout << this->eveniment.getClient().getNumePrenume() << endl;
}

int main()
{
    // Client c1("popescu", 7), c2("ionescu", 5, 3);
    // Eveniment e1(c1, "12.09.2021", 'A'), e2(c2, "222", 'N'), e3;
    // Registru r1(e1);
    // e3 = e1;

    /*Client c1("popescu", 7);
    Client c2 = c1;
    c2.setVarsta(new int(8));
    cout << *c1.getVarsta() << endl;
    cout << *c2.getVarsta() << endl;*/



    //Registru::setNumarClienti(2);
    //cout << Registru::getNumarClienti();
    //Animal a1("pisica", 5, 5.239),a;
    //Animal a2 = a1;
    //a1.setVarsta(6);
    //cout << a1.getVarsta() << endl;
    //cout << a2.getVarsta() << endl;
    //cin >> a;
    //cout << a;
    /*Client c;
    cin >> c;
    cout << c;*/
    

 /*   Eveniment e;
    cin >> e;
    cout << e;
    cout << "Animalul este "<< e.getAnimal().getNume()<<endl;*/
    Registru r;
    cin >> r;
    cout << r;

    return 0;
}