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
    void setNumePrenume(string numePrenume) { this->numePrenume = numePrenume; }
    void setVarsta(int *varsta) { this->varsta = varsta; }
    void setSex(char *sex) { this->sex = sex; }
    void setRating(double rating) { this->rating = rating; }
    void setAnimaleDetinute(int animaleDetinute) { this->animaleDetinute = animaleDetinute; }
    static void setNumarClienti(int numarClientiNou) { numarClienti = numarClientiNou; }

    string getNumePrenume() { return this->numePrenume; }
    int *getVarsta() { return this->varsta; }
    char *getSex() { return this->sex; }
    double getRating() { return this->rating; }
    int getAnimaleDetinute() { return this->animaleDetinute; }
    static int getNumarClienti() { return numarClienti; }

    //constructors
    Client();
    Client(string numePrenume, int varsta);
    Client(string numePrenume, double rating, int animaleDetinute);
    Client(string numePrenume, int varsta, double rating, int animaleDetinute);
    Client(string numePrenume, int varsta, char sex, double rating, int animaleDetinute);

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

    // destructors
    ~Animal();
};

int Animal::numarAnimale = 0;

// constructors
Animal::Animal()
{
    cout << "Constructor de initializare: " << endl;
    this->nume = "Anonim";
    this->sex = '-';
    this->esteCumparat = 0;
    this->varsta = 0;
    this->areProblemeSpeciale = 0;
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

    //destructors
    ~Eveniment();
};

//constructors
Eveniment::Eveniment()
{
    //TO DO overload = for Client and Animal
    // this->client
    // this->animal
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
    int an;
    double bilant;

public:
    // setters
    void setEveniment(Eveniment eveniment) { this->eveniment = eveniment; }
    void setAn(int an) { this->an = an; }
    void setBilant(double bilant) { this->bilant = bilant; }

    // getters
    Eveniment getEveniment() { return this->eveniment; }
    int getAn() { return this->an; }
    double getBilant() { return this->bilant; }
    string getNumeMagazin() { return this->numeMagazin; }

    //cpnstructors
    Registru();
    Registru(Eveniment eveniment);
    Registru(Eveniment eveniment, int an);
    Registru(Eveniment eveniment, int an, double bilant);

    // destructor
    ~Registru();
};

// constructors
Registru::Registru()
{ // overload la =
    this->an = 0;
    this->bilant = 0;
}

Registru::Registru(Eveniment eveniment)
{
    this->eveniment = eveniment;
}

Registru::Registru(Eveniment eveniment, int an)
{
    this->eveniment = eveniment;
    this->an = an;
}

Registru::Registru(Eveniment eveniment, int an, double bilant)
{
    this->eveniment = eveniment;
    this->an = an;
    this->bilant = bilant;
}

// destructor
Registru::~Registru()
{
    cout << "Distruge din registru evenimentul pentru clientul: " << endl;
    cout << this->eveniment.getClient().getNumePrenume() << endl;
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