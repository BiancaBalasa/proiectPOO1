#include <iostream>
#include <string>

using namespace std;

class Animal // functionalitate: o functie care sa verifice daca animalul e overweight si daca e, sa se modifice areprblemespeciale din False in True daca e cazul 
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
    const int idAnimal;

public:
    // setters
    void setNume(string nume) { this->nume = nume; }
    void setSex(char sex) { this->sex = sex; }
    void setEsteCumparat(bool esteCumparat) { this->esteCumparat = esteCumparat; }
    void setVarsta(int varsta) { this->varsta = varsta; }
    void setAreProblemeSpeciale(bool areProblemeSpeciale) { this->areProblemeSpeciale = areProblemeSpeciale; }
    void setGreutate(float greutate) { this->greutate = greutate; }
    void setPret(float pret) { this->pret = pret; }
    //static void setNumarAnimale(int numarAnimaleNou) { numarAnimale = numarAnimaleNou; }

    // getters
    string getNume() { return this->nume; }
    char getSex() { return this->sex; }
    bool getEsteCumparat() { return this->esteCumparat; }
    int getVarsta() { return this->varsta; }
    bool getAreProblemeSpeciale() { return this->areProblemeSpeciale; }
    float getGreutate() { return this->greutate; }
    float getPret() { return this->pret; }
    static int getNumarAnimale() { return numarAnimale; }
    const int getIdAnimal() { return idAnimal; }

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

    //function
    void verificaObezitate();


};

int Animal::numarAnimale = 0;

// constructors
Animal::Animal() : idAnimal(numarAnimale)
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

Animal::Animal(string nume, float pret) : idAnimal(numarAnimale)
{
    cout << "Constructor pentru clasa Animal cu 2 parametrii: " << endl;
    this->nume = nume;
    this->pret = pret;
    numarAnimale++;
}

Animal::Animal(string nume, int varsta, float greutate) : idAnimal(numarAnimale)
{
    cout << "Constructor pentru clasa Animal cu 3 parametrii: " << endl;
    this->nume = nume;
    this->varsta = varsta;
    this->greutate = greutate;
    numarAnimale++;
}

Animal::Animal(string nume, bool esteCumparat, bool areProblemeSpeciale, float pret) : idAnimal(numarAnimale)
{
    cout << "Constructor pentru clasa Animal cu 4 parametrii: " << endl;
    this->nume = nume;
    this->esteCumparat = esteCumparat;
    this->areProblemeSpeciale = areProblemeSpeciale;
    this->pret = pret;
    numarAnimale++;
}

Animal::Animal(string nume, char sex, bool esteCumparat, int varsta, bool areProblemeSpeciale, float greutate, float pret) : idAnimal(numarAnimale)
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
Animal::Animal(const Animal& other) : idAnimal(other.idAnimal)
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
    out << "\nNume: " << a.nume;
    out << "\nSex: " << a.sex;
    out << "\nEste cumparat: " << a.esteCumparat;
    out << "\nVarsta: " << a.varsta;
    out << "\nAre probleme speciale: " << a.areProblemeSpeciale;
    out << "\nGreutate: " << a.greutate;
    out << "\nPret: " << a.pret << endl;
    return out;
}

// overload operator>>
istream& operator>>(istream& in, Animal& a)
{
    cout << "\nNume: ";
    in >> a.nume;
    cout << "\nSex: ";
    in >> a.sex;
    cout << "\nEste cumparat: ";
    in >> a.esteCumparat;
    cout << "\nVarsta: ";
    in >> a.varsta;
    cout << "\nAre probleme speciale: ";
    in >> a.areProblemeSpeciale;
    cout << "\nGreutate: ";
    in >> a.greutate;
    cout << "\nPret: ";
    in >> a.pret;
    return in;
}

// destructor
Animal::~Animal()
{
    cout << "\nDistruge animalul: ";
    cout << this->nume << endl;
}

//function 
void Animal::verificaObezitate()
{
    int criteriuObezitate;
    if (this->varsta < 2)
        criteriuObezitate = 7;
    else
    {
        if (this->varsta >= 2 && this->varsta <= 10)
            criteriuObezitate = 12;
        else
            criteriuObezitate = 10;
    }

    if (this->greutate >= criteriuObezitate)
        this->areProblemeSpeciale = true;
}
class Client //daca are rating mic varsta inaintata si experienta mica cu animale e o variabila in care zic nu (nu are voie sa adopte/cumpere)
             //in functie de niste factori(rating) sa avem discount pentru 
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

    //function
    bool poateAdoptaAnimal(Animal a);
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
    out << "\nNume Prenume: " << c.numePrenume;
    out << "\nVarsta: " << *c.varsta;
    out << "\nSex: " << *c.sex;
    out << "\nRating: " << c.rating;
    out<< "\nAnimale detinute: " << c.animaleDetinute << endl;
    return out;
}

// overload operator>>
istream& operator>>(istream& in, Client& c)
{
    cout << "\nNume Prenume: ";
    in >> c.numePrenume;
    cout << "\nVarsta: ";
    in >> *c.varsta;
    cout << "\nSex: ";
    in >> *c.sex;
    cout << "\nRating: ";
    in >> c.rating;
    cout << "\nAnimale detinute: ";
    in >> c.animaleDetinute;
    return in;
}

// destructor
Client::~Client()
{
    cout << "\nDistruge clientul: " ;
    cout << this->numePrenume<<endl ;
    delete this->varsta;
    delete this->sex;
}

//function
bool Client::poateAdoptaAnimal(Animal a)
{//daca are rating mic varsta inaintata si experienta mica cu animale e o variabila in care zic nu (nu are voie sa adopte/cumpere)
    bool poateAdopta = true;
    //daca are rating mic si numar mare de animale, nu are voie 
    if (this->rating <= 2.5 && this->animaleDetinute >= 5)
        poateAdopta = false;
    else
        if (*this->varsta >= 60 && a.getAreProblemeSpeciale())
            poateAdopta = false;

    return poateAdopta;

}


class Hrana
{
private:
    string nume;
    const string distribuitor;
    float pret;
    string tipAnimal;
    bool esteUmeda;
    int valNutritiva;

public:
    // setters
    void setNume(string nume) { this->nume = nume;  }
    void setPret(float pret) { this->pret = pret; }
    void setTipAnimal(string tipAnimal) { this->tipAnimal = tipAnimal; }
    void setEsteUmeda(bool esteUmeda) { this->esteUmeda = esteUmeda; }
    void setValNutritiva(int valNutritiva) { this->valNutritiva = valNutritiva; }

    // getters
    string getNume() { return this->nume; }
    float getPret() { return this->pret; }
    string getTipAnimal() { return this->tipAnimal; }
    bool getEsteUmeda() { return this->esteUmeda; }
    int getValNutritiva() { return this->valNutritiva; }

    // constructors
    Hrana();
    Hrana(string nume, float pret);
    Hrana(string nume, float pret, bool esteUmeda);
    Hrana(string nume, float pret, string tipAnimal, bool esteUmeda, int valNutritiva);

    //copy constructor 
    Hrana(const Hrana& other);

    // overload operator=
    Hrana& operator=(const Hrana& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, Hrana& h);

    // overload operator>>
    friend istream& operator>>(istream& in, Hrana& h);

    // destructor 
    ~Hrana();

    // function 
    int calculeazaGrameHrana(Animal a);
};

// constructors
Hrana::Hrana()
{
    this->nume = "Anonim";
    this->pret = 0;
    this->tipAnimal = "Anonim";
    this->esteUmeda = false;
    this->valNutritiva = 0;
}

Hrana::Hrana(string nume, float pret)
{
    this->nume = nume;
    this->pret = pret;
}

Hrana::Hrana(string nume, float pret, bool esteUmeda)
{
    this->nume = nume;
    this->pret = pret;
    this->esteUmeda = esteUmeda;
}

Hrana::Hrana(string nume, float pret, string tipAnimal, bool esteUmeda, int valNutritiva)
{
    this->nume = nume;
    this->pret = pret;
    this->tipAnimal = tipAnimal;
    this->esteUmeda = esteUmeda;
    this->valNutritiva = valNutritiva;
}

// copy constructor
Hrana::Hrana(const Hrana& other)
{
    this->nume = other.nume;
    this->pret = other.pret;
    this->tipAnimal = other.tipAnimal;
    this->esteUmeda = other.esteUmeda;
    this->valNutritiva = other.valNutritiva;
}

// overload operator=
Hrana& Hrana::operator=(const Hrana& other)
{
    if (this != &other)
    {
        this->nume = other.nume;
        this->pret = other.pret;
        this->tipAnimal = other.tipAnimal;
        this->esteUmeda = other.esteUmeda;
        this->valNutritiva = other.valNutritiva;
    }
    return *this;
}

// overload operator<<
ostream& operator<<(ostream& out, Hrana& h)
{
    out << "\nNume: " << h.nume;
    out << "\nPret: " << h.pret;
    out << "\nTip animal: " << h.tipAnimal;
    out << "\nEste umeda: " << h.esteUmeda;
    out << "\nValoare nutritiva: " << h.valNutritiva;
    return out;
}

// overload operator>>
istream& operator>>(istream& in, Hrana& h)
{
    cout << "\nNume: ";
    in >> h.nume;
    cout << "\nPret: ";
    in >> h.pret;
    cout << "\nTip animal: ";
    in >> h.tipAnimal;
    cout << "\nEste umeda: ";
    in >> h.esteUmeda;
    cout << "\nValoare nutritiva: ";
    in >> h.valNutritiva;
    return in;
}

// destructor
Hrana::~Hrana()
{
    cout << "\nDistruge hrana: ";
    cout << this->nume << endl;
}

// function
int Hrana::calculeazaGrameHrana(Animal a)
{
    int grameHranaUmedaPisica = 85;
    int grameHranaUmedaCaine = 100;
    int grameHranaUscataPisica = 1;
    int grameHranaUscataCaine = 1;

    if (this->esteUmeda == true)
    {
        if (this->tipAnimal == "pisica")
        {
            if (a.getGreutate() >= 2 && a.getGreutate() <= 3)
                grameHranaUmedaPisica = grameHranaUmedaPisica * 2;
            else
                if (a.getGreutate() == 4)
                    grameHranaUmedaPisica = grameHranaUmedaPisica * 3;
                else
                    if (a.getGreutate() >= 5)
                        grameHranaUmedaPisica = grameHranaUmedaPisica * 4;
        }
        else
            if (this->tipAnimal == "caine")
            {
                if (a.getGreutate() >= 3 && a.getGreutate() <= 6)
                    grameHranaUmedaCaine = grameHranaUmedaCaine * 4;
                else
                    if (a.getGreutate() >= 6 && a.getGreutate() <= 10)
                        grameHranaUmedaCaine = grameHranaUmedaCaine * 7;
                    else
                        if (a.getGreutate() >= 10 && a.getGreutate() <=20)
                            grameHranaUmedaCaine = grameHranaUmedaCaine * 11;
            }
    }
    else
        if (this->esteUmeda == false)
        {
            if (this->tipAnimal == "pisica")
            {
                if (a.getGreutate() >= 2 && a.getGreutate() <= 3)
                    grameHranaUscataPisica = grameHranaUscataPisica * 45;
                else
                    if (a.getGreutate() == 4)
                        grameHranaUscataPisica = grameHranaUscataPisica * 55;
                    else
                        if (a.getGreutate() >= 5)
                            grameHranaUscataPisica = grameHranaUscataPisica * 65;
            }
        }
        else
            if (this->tipAnimal == "caine")
            {
                if (a.getGreutate() >= 3 && a.getGreutate() <= 6)
                    grameHranaUscataCaine = grameHranaUscataCaine * 85;
                else
                    if (a.getGreutate() >= 6 && a.getGreutate() <= 10)
                        grameHranaUscataCaine = grameHranaUscataCaine * 140;
                    else
                        if (a.getGreutate() >= 10 && a.getGreutate() <= 20)
                            grameHranaUscataCaine = grameHranaUscataCaine * 240;
            }
    if (this->tipAnimal == "pisica")
    {
        if (this->esteUmeda == true)
            return grameHranaUmedaPisica;
        else
            return grameHranaUscataPisica;
    }
    else
        if (this->tipAnimal == "caine")
        {
            if (this->esteUmeda == true)
                return grameHranaUmedaCaine;
            else
                return grameHranaUscataCaine;
        }
    
}

class Hainuta
{
private:
    string denumire;
    char marime;
    string tipAnimal;
    double pret;
    string culoare;

public:
    // setters
    void setDenumire(string denumire) { this->denumire = denumire; }
    void setMarime(char marime) { this->marime = marime; }
    void setTipAnimal(string tipAnimal) { this->tipAnimal = tipAnimal; }
    void setPret(double pret) { this->pret = pret; }
    void setCuloare(string culoare) { this->culoare = culoare; }

    // getters
    string getDenumire() { return this->denumire; }
    char getMarime() { return this->marime; }
    string getTipAnimal() { return this->tipAnimal; }
    double getPret() { return this->pret; }
    string getCuloare() { return this->culoare; }

    // constructors 
    Hainuta();
    Hainuta(string denumire, char marime, string tipAnimal);
    Hainuta(string denumire, char marime, string tipAnimal, double pret);
    Hainuta(string denumire, char marime, string tipAnimal, double pret, string culoare);

    // copy constructor
    Hainuta(const Hainuta& other);

    // overload operator=
    Hainuta& operator=(const Hainuta& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, Hainuta& h);

    //overload operator>>
    friend istream& operator>>(istream& in, Hainuta& h);

    // destructor
    ~Hainuta();

    // function
    char aflaMarimeRecomandata(Animal a);

    
};

// constructors
Hainuta::Hainuta()
{
    this->denumire = "Anonim";
    this->marime = '-';
    this->tipAnimal = "Anonim";
    this->pret = 0;
    this->culoare = "Anonim";
}

Hainuta::Hainuta(string denumire, char marime, string tipAnimal)
{
    this->denumire = denumire;
    this->marime = marime;
    this->tipAnimal = tipAnimal;
}

Hainuta::Hainuta(string denumire, char marime, string tipAnimal, double pret)
{
    this->denumire = denumire;
    this->marime = marime;
    this->tipAnimal = tipAnimal;
    this->pret = pret;
}

Hainuta::Hainuta(string denumire, char marime, string tipAnimal, double pret, string culoare)
{
    this->denumire = denumire;
    this->marime = marime;
    this->tipAnimal = tipAnimal;
    this->pret = pret;
    this->culoare = culoare;
}

// copy constructor
Hainuta::Hainuta(const Hainuta& other)
{
    this->denumire = other.denumire;
    this->marime = other.marime;
    this->tipAnimal = other.tipAnimal;
    this->pret = other.pret;
    this->culoare = other.culoare;
}

// overload operator =
Hainuta& Hainuta:: operator=(const Hainuta& other)
{
    if (this != &other)
    {
        this->denumire = other.denumire;
        this->marime = other.marime;
        this->tipAnimal = other.tipAnimal;
        this->pret = other.pret;
        this->culoare = other.culoare;
    }
    return *this;
}

// overload operator<<
ostream& operator<<(ostream& out, Hainuta& h)
{
    out << "\nDenumire: " << h.denumire;
    out << "\nMarime: " << h.marime;
    out << "\nTip animal: " << h.tipAnimal;
    out << "\nPret: " << h.pret;
    out << "\nCuloare: " << h.culoare;
    return out;
}

istream& operator>>(istream& in, Hainuta& h)
{
    cout << "\nDenumire: ";
    in >> h.denumire;
    cout << "\nMarime: ";
    in >> h.marime;
    cout << "\nTip animal: ";
    in >> h.tipAnimal;
    cout << "\nPret: ";
    in >> h.pret;
    cout << "\nCuloare: ";
    in >> h.culoare;
    cout << endl;
    return in;
}

// destructor 
Hainuta::~Hainuta()
{
    cout << "\nDistruge Hainuta : " ;
    cout << this->denumire << " " << this->marime << endl ;
}

// function
char Hainuta::aflaMarimeRecomandata(Animal a)
{
    char marimeRecomandataPisica = '-';
    char marimeRecomandataCaine = '-';

    if (this->tipAnimal == "pisica")
    {
        if (a.getGreutate() >= 2 && a.getGreutate() <= 3)
            marimeRecomandataPisica = 'S';
        else
            if (a.getGreutate() == 4)
                marimeRecomandataPisica = 'M';
            else
                if (a.getGreutate() >= 5)
                    marimeRecomandataPisica = 'L';
    }
    else
        if (this->tipAnimal == "caine")
        {
            if (a.getGreutate() >= 3 && a.getGreutate() <= 6)
                marimeRecomandataCaine = 'S';
            else
                if (a.getGreutate() >= 6 && a.getGreutate() <= 10)
                    marimeRecomandataCaine = 'M';
                else
                    if (a.getGreutate() >= 10 && a.getGreutate() <= 20)
                        marimeRecomandataCaine = 'L';
        }
    if (this->tipAnimal == "pisica")
        return marimeRecomandataPisica;
    else
        return marimeRecomandataCaine;

}


int main()
{
    Animal a1("piscot",18,18);
    Client c1("Bianca",30,2.4,1);
    Hainuta h1("Onesie", 'M',"caine",20);
    cout << " Recomandam marimea " << h1.aflaMarimeRecomandata(a1) << endl;

    a1.setAreProblemeSpeciale(false);
    //a1.verificaObezitate();
    //cout << "Are probleme speciale: " << a1.getAreProblemeSpeciale();
    //cout << endl;
    cout<<"Poate adopta: "<< c1.poateAdoptaAnimal(a1);
    cout << endl;
    /*cin >> a1;
    cout << a1 << endl; 
    Client c1;
    cin >> c1;
    cout << c1 << endl;
    Hrana h1;
    cin >> h1;
    cout << h1 << endl;
    Hainuta ha1;
    cin >> ha1;
    cout << ha1 << endl;*/
    
    return 0;
}