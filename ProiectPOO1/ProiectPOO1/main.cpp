#include <iostream>
#include <string>

using namespace std;

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
    Animal(string nume, int varsta, float greutate, float pret);
    Animal(string nume, char sex, bool eesteCumparat, int varsta, bool areProblemeSpeciale, float greutate, float pret);

    //copy constructor
    Animal(const Animal& other);

    // overload operator=
    Animal& operator=(const Animal& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, const Animal& a);

    //overload operator>>
    friend istream& operator>>(istream& in, Animal& a);

    // overload operator==
    bool operator==(const Animal& an);

    // overload operator<
    bool operator<(const Animal& an);

    //overload operator+
    friend Animal operator+(Animal, Animal);

    // destructor
    ~Animal();

    //function
    bool verificaObezitate();


};

int Animal::numarAnimale = 0;

// constructors
Animal::Animal() : idAnimal(numarAnimale)
{
    //cout << "\nConstructor de initializare pentru casa Animal: " << endl;
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
    //cout << "\nConstructor pentru clasa Animal cu 2 parametrii: " << endl;
    this->nume = nume;
    this->pret = pret;
    numarAnimale++;
}

Animal::Animal(string nume, int varsta, float greutate) : idAnimal(numarAnimale)
{
    //cout << "\nConstructor pentru clasa Animal cu 3 parametrii: " << endl;
    this->nume = nume;
    this->varsta = varsta;
    this->greutate = greutate;
    numarAnimale++;
}

Animal::Animal(string nume, int varsta, float greutate, float pret) : idAnimal(numarAnimale)
{
    //cout << "\nConstructor pentru clasa Animal cu 4 parametrii: " << endl;
    this->nume = nume;
    this->varsta = varsta;
    this->greutate = greutate;
    this->pret = pret;
    numarAnimale++;
}

Animal::Animal(string nume, char sex, bool esteCumparat, int varsta, bool areProblemeSpeciale, float greutate, float pret) : idAnimal(numarAnimale)
{
    //cout << "\nConstructor pentru clasa Animal cu 7 parametrii: " << endl;
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

// overload operator==
bool Animal::operator==(const Animal& an)
{
    if (this->nume == an.nume && this->sex == an.sex && this->esteCumparat == an.esteCumparat && this->varsta == an.varsta && this->areProblemeSpeciale == an.areProblemeSpeciale && this->greutate == an.greutate && this->pret == an.pret)
        return true;
    return false;
}

bool Animal::operator<(const Animal& an)
{
    if ( (this->varsta < an.varsta) && (this->greutate < an.greutate) )
        return true;
    return false;
}

// overoad operator+
Animal operator+(Animal ob1, Animal ob2)
{
    Animal rez;
    rez.nume = ob1.nume + ob2.nume;
    rez.varsta = ob1.varsta + ob2.varsta;
    rez.greutate = ob1.greutate + ob2.greutate;
    rez.pret = ob1.pret + ob2.pret;
    return rez;
}

// destructor
Animal::~Animal()
{
    cout << "\nDistruge animalul: ";
    cout << this->nume << endl;
}

//function :  verifica daca animalul este overweight in functie de varsta si greutate si daca este adevarat
           // se modifice arePrblemeSpeciale din False in True (daca e cazul) 
bool Animal::verificaObezitate()
{
    bool obezitate = false;
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
    {
        this->areProblemeSpeciale = true;
        obezitate = true;
    }

    return obezitate;       
}
class Client 
              
{
private:
    string nume;
    string prenume;
    int *varsta;
    char *sex;     // M sau F
    double rating; // intre 0 si 5
    int animaleDetinute;
    static int numarClienti;

public:
    //setters and getters
    void setNume(string nume) { this->nume = nume; }
    void setPrenume(string prenume) { this->prenume = prenume; }
    void setVarsta(int *varsta)
    { 
        if (this->varsta != NULL)
            delete this->varsta;
        this->varsta = new int(*varsta);
    }
    void setSex(char *sex) 
    { 
        if (this->sex != NULL)
            delete this->sex;
        this->sex = new char(*sex);
    }
    void setRating(double rating) { this->rating = rating; }
    void setAnimaleDetinute(int animaleDetinute) { this->animaleDetinute = animaleDetinute; }
    static void setNumarClienti(int numarClientiNou) { numarClienti = numarClientiNou; }

    string getNume() { return this->nume; }
    string getPrenume() { return this->prenume; }
    int* getVarsta() { return this->varsta; }
    char* getSex() { return this->sex; }
    double getRating() { return this->rating; }
    int getAnimaleDetinute() { return this->animaleDetinute; }
    static int getNumarClienti() { return numarClienti; }

    //constructors
    Client();
    Client(string nume, string prenume, int *varsta);
    Client(string nume, string prenume, double rating, int animaleDetinute);
    Client(string nume, string prenume, int *varsta, double rating, int animaleDetinute);
    Client(string nume, string prenume, int *varsta, char *sex, double rating, int animaleDetinute);

    // copy constructor
    Client(const Client& other);

    // overload operator=
    Client& operator=(const Client& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, const Client& c);
    
    // overload operator>>
    friend istream& operator>>(istream& in, Client& c);

    // overload operator==
    bool operator==(const Client& cl);

    //overload operator<
    bool operator<(const Client& cl);

    // overload oprator+
    friend Client operator+(Client, Client);
    
    //destructor
    ~Client();

    //function
    bool poateAdoptaAnimal(Animal a);
};

int Client::numarClienti = 0;

// constructors
Client::Client()
{
    // << "Constructor de initializare pentru clasa Client: " << endl;
    this->nume = "Anonim";
    this->prenume = "Anonim";
    this->varsta = new int(0);
    this->sex = new char('-');
    this->rating = 0;
    this->animaleDetinute = 0;
    numarClienti++;
    //cout << this->nume << " " << this->prenume << " cu varsta de " << *this->varsta << " ani si sexul " << *this->sex << ", are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

Client::Client(string nume, string prenume, int *varsta)
{
    //cout << "Constructor pentru clasa Client cu 3 parametrii: " << endl;
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = new int(*varsta); // creaza un pointer cu valoarea din v

    numarClienti++;
    //cout << this->nume << " " << this->prenume << " cu varsta de " << *this->varsta << " ani. " << endl;
}

Client::Client(string nume, string prenume, double rating, int animaleDetinute)
{
    //cout << "Constructor pentru clasa Client cu 4 parametrii: " << endl;

    this->nume = nume;
    this->prenume = prenume;
    this->rating = rating;
    this->animaleDetinute = animaleDetinute;
    numarClienti++;
    //cout << this->nume << " " << this->prenume << " are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

Client::Client(string nume, string prenume, int *varsta, double rating, int animaleDetinute)
{
    //cout << "Constructor pentru clasa Client cu 4 parametrii: " << endl;
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = new int(*varsta);
    this->rating = rating;
    this->animaleDetinute = animaleDetinute;
    numarClienti++;
    //cout << this->nume << " " << this->prenume << " cu varsta de " << *this->varsta << " ani, are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

Client::Client(string nume, string prenume, int *varsta, char *sex, double rating, int animaleDetinute)
{
    //cout << "Constructor pentru clasa Client cu 5 parametrii: " << endl;

    this->nume = nume;
    this->prenume = prenume;
    this->varsta = new int(*varsta);
    this->sex = new char(*sex);
    this->rating = rating;
    this->animaleDetinute = animaleDetinute;
    numarClienti++;
    //cout << this->nume << " " << this->prenume << " cu varsta de " << *this->varsta << " ani si sexul " << *this->sex << ", are ratingul de " << this->rating << " puncte si a detinut " << this->animaleDetinute << " animale. " << endl;
}

//copy constructor
Client::Client(const Client& other)
{
    this->nume = other.nume;
    this->prenume = other.prenume;

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

        this->nume = other.nume;
        this->prenume = other.prenume;
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
    out << "\nNume: " << c.nume;
    out << "\nPrenume: " << c.prenume;
    out << "\nVarsta: " << *c.varsta;
    out << "\nSex: " << *c.sex;
    out << "\nRating: " << c.rating;
    out<< "\nAnimale detinute: " << c.animaleDetinute << endl;
    return out;
}

// overload operator>>
istream& operator>>(istream& in, Client& c)
{
    cout << "\nNume: ";
    in >> c.nume;
    cout << "\nPrenume: ";
    in >> c.prenume;

    cout << "\nVarsta: ";
    int v;
    in >> v;
    if (c.varsta != NULL)
        delete c.varsta;
    c.varsta = new int(v);

    cout << "\nSex: ";
    char s;
    in >> s;
    if (c.sex != NULL)
        delete c.sex;
    c.sex = new char(s);
    
    cout << "\nRating: ";
    in >> c.rating;
    cout << "\nAnimale detinute: ";
    in >> c.animaleDetinute;
    return in;
}

//overload operator==
bool Client::operator==(const Client& cl)
{
    if ( (this->nume == cl.nume) && (this->prenume == cl.prenume) && (*this->varsta == *cl.varsta) && (*this->sex == *cl.sex) && (this->rating == cl.rating) && (this->animaleDetinute == animaleDetinute) )
        return true;
    return false;
}

bool Client::operator<(const Client& cl)
{
    if ( (this->rating < cl.rating) && (this->animaleDetinute < cl.animaleDetinute) )
        return true;
    return false;
}

//overload operator+
Client operator+(Client ob1, Client ob2)
{
    Client rez;
    rez.nume = ob1.nume + ob2.nume;
    rez.prenume = ob1.prenume + ob2.prenume;
    rez.varsta = new int(*ob1.varsta + *ob2.varsta);
    rez.rating = ob1.rating + ob2.rating;
    rez.animaleDetinute = ob1.animaleDetinute + ob2.animaleDetinute;
    return rez;
}

// destructor
Client::~Client()
{
    cout << "\nDistruge clientul: " ;
    cout << this->nume << " " << this->prenume << endl;
    
    if(this->varsta != NULL)
        delete this->varsta;

    if (this->sex != NULL)
        delete this->sex;
    
}

//function :  verifica daca se poate adopta un animal in functie de ratingul, varsta si experienta cu animalele 
          //  pe care le are clientul si in functie de problemele speciale ale animalului
        
bool Client::poateAdoptaAnimal(Animal a)
{
    bool poateAdopta = true;
    
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

    //overload operator==
    bool operator==(const Hrana& hr);

    // overload operator<
    bool operator<(const Hrana& hr);

    // overload operator+
    friend Hrana operator+(Hrana, Hrana);

    // destructor 
    ~Hrana();

    // function 
    int calculeazaGrameHrana(Animal a);
};

// constructors
Hrana::Hrana()
{
    //cout << "\nConstructor de initializare pentru clasa Hrana: " << endl;
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

// overload operator==
bool Hrana::operator==(const Hrana& hr)
{
    if (this->nume == hr.nume && this->pret == hr.pret && this->tipAnimal == hr.tipAnimal && this->esteUmeda == hr.esteUmeda && this->valNutritiva == hr.valNutritiva)
        return true;
    return false;
}

//overload operator<
bool Hrana::operator<(const Hrana& hr)
{
    if (this->pret < hr.pret)
        return true;
    return false;
}

// overload operator+
Hrana operator+(Hrana ob1, Hrana ob2)
{
    Hrana rez;
    rez.nume = ob1.nume + ob2.nume;
    rez.pret = ob1.pret + ob2.pret;
    return rez;

}

// destructor
Hrana::~Hrana()
{
    cout << "\nDistruge hrana: ";
    cout << this->nume << endl;
}



// function : calculeaza in functie de tipul animalului: pisica/caine care este cantitatea de hrana umeda 
           // si cantitatea de hrana uscata recomandata pentru animalut in functie de greutatea acestuia
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
    Hainuta(string denumire, string tipAnimal, double pret);
    Hainuta(string denumire, char marime, string tipAnimal, double pret, string culoare);

    // copy constructor
    Hainuta(const Hainuta& other);

    // overload operator=
    Hainuta& operator=(const Hainuta& other);

    // overload operator<<
    friend ostream& operator<<(ostream& out, Hainuta& h);

    //overload operator>>
    friend istream& operator>>(istream& in, Hainuta& h);

    //overload operator==
    bool operator==(const Hainuta& ha);

    // overload operator<
    bool operator<(const Hainuta& ha);

    // overload operator+
    friend Hainuta operator+(Hainuta, Hainuta);

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

Hainuta::Hainuta(string denumire, string tipAnimal, double pret)
{
    this->denumire = denumire;
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

// overload operator==
bool Hainuta::operator==(const Hainuta& ha)
{
    if (this->denumire == ha.denumire && this->marime == ha.marime && this->tipAnimal == ha.tipAnimal && this->pret == ha.pret && this->culoare == ha.culoare)
        return true;
    return false;
}

// overload operator<
bool Hainuta::operator<(const Hainuta& ha)
{
    if (this->pret < ha.pret)
        return true;
    return false;
}

// overload operator+
Hainuta operator+(Hainuta ob1, Hainuta ob2)
{
    Hainuta rez;
    rez.denumire = ob1.denumire + ob2.denumire;
    rez.tipAnimal = ob1.tipAnimal + ob2.tipAnimal;
    rez.pret = ob1.pret + ob2.pret;
    return rez;

}

// destructor 
Hainuta::~Hainuta()
{
    cout << "\nDistruge Hainuta : " ;
    cout << this->denumire << endl ;
}

// function : recomanda in functie de tipul animalului: pisica/caine care este marimea potrivita 
           // pentru animalut in functie de greutatea acestuia
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
    Animal a;
    Client c;
    Hrana hr;
    Hainuta h;

    int input = -1;
    while (input != 0)
    {   
        cout << "\nALEGETI OPTIUNEA: " << endl;
        cout << "  0. Exit!\n";
        cout << "  1. Creeaza animal\n";
        cout << "  2. Creeaza client\n";
        cout << "  3. Creeaza hrana\n";
        cout << "  4. Creeaza hainuta\n";
        cout << "  5. Afiseaza animal\n";
        cout << "  6. Afiseaza client\n";
        cout << "  7. Afiseaza hrana\n";
        cout << "  8. Afiseaza hainuta\n";
        cout << "  9. Editeaza animal\n";
        cout << " 10. Editeaza client\n";
        cout << " 11. Editeaza hrana\n";
        cout << " 12. Editeaza hainuta\n";
        cout << " 13. Verifica daca animalul creat are probleme cu obezitatea\n";
        cout << " 14. Verifica daca clientul poate adopta animalul creat\n";
        cout << " 15. Calculeaza cantitatea de hrana recomandata animalului creat\n";
        cout << " 16. Calculeaza marimea recomandata pentru hainuta animalului creat\n";
        cout << " Introduceti optiunea dorita: \n";
        
        cin >> input;

        switch (input)
        {
        case 0:
            cout << "Iesire din program! " << endl;
            break;

        case 1:
            cin >> a;
            break;

        case 2:
            cin >> c;
            break;

        case 3:
            cin >> hr;
            break;

        case 4:
            cin >> h;
            break;

        case 5:
            cout << a << endl;
            break;

        case 6:
            cout << c << endl;
            break;

        case 7:
            cout << hr << endl;
            break;

        case 8:
            cout << h << endl;
            break;

        case 9:
            cout << "Animalul are urmatoarele atribute:\n" << " 1. nume\n" << " 2. sex\n" 
                 << " 3. esteCumparat\n" << " 4. varsta\n" << " 5. areProblemeSpeciale\n" 
                 << " 6. greutate\n" << " 7. pret\n";
            cout << "Ce doriti sa editati? Scrieti numarul corespunzator atributului dorit: \n";
            int inputAnimal;
            cin >> inputAnimal;
            switch (inputAnimal)
            {
            case 1:
            {
                string n;
                cin >> n;
                a.setNume(n);
                break;
            }

            case 2:
            {
                char s;
                cin >> s;
                a.setSex(s);
                break;
            }

            case 3:
            {
                bool cump;
                cin >> cump;
                a.setEsteCumparat(cump);
                break;
            }

            case 4:
            {
                int v;
                cin >> v;
                a.setVarsta(v);
                break;
            }

            case 5:
            {
                bool ps;
                cin >> ps;
                a.setAreProblemeSpeciale(ps);
                break;
            }

            case 6:
            {
                float g;
                cin >> g;
                a.setGreutate(g);
                break;
            }

            case 7:
            {
                float p;
                cin >> p;
                a.setPret(p);
                break;
            }

            default:
                cout << "Nu corespunde niciunui atribut! \n";
                break;
            }
            break;

        case 10:
            cout << "Clientul are urmatoarele atribute:\n" << " 1. nume\n" << " 2. prenume\n" << " 3. varsta\n"
                 << " 4. sex\n" << " 5. rating\n" << " 6. animaleDetinute\n";
            cout << "Ce doriti sa editati? Scrieti numarul corespunzator atributului dorit: \n";
            int inputClient;
            cin >> inputClient;
            switch (inputClient)
            {
            case 1:
            {
                string n;
                cin >> n;
                c.setNume(n);
                break;
            }

            case 2:
            {
                string p;
                cin >> p;
                c.setPrenume(p);
                break;
            }

            case 3:
            {
                int v;
                int* varstaNoua;
                cin >> v;
                varstaNoua = new int(v);
                c.setVarsta(varstaNoua);
                delete varstaNoua;
                break;
            }

            case 4:
            {
                char s;
                char* sexNou;
                cin >> s;
                sexNou = new char(s);
                c.setSex(sexNou);
                delete sexNou;
                break;
            }

            case 5:
            {
                double r;
                cin >> r;
                c.setRating(r);
                break;
            }

            case 6:
            {
                int ad;
                cin >> ad;
                c.setAnimaleDetinute(ad);
                break;
            }

            default:
                cout << "Nu corespunde niciunui atribut! \n";
                break;
            }
            break;

        case 11:
            cout << "Hrana are urmatoarele atribute:\n" << " 1. nume\n" << " 2. pret\n" << " 3. tipAnimal\n"
                 << " 4. esteUmeda\n" << " 5. valNutritiva\n";
            cout << "Ce doriti sa editati? Scrieti numarul corespunzator atributului dorit: \n";
            int inputHrana;
            cin >> inputHrana;
            switch (inputHrana)
            {
            case 1:
            {
                string n;
                cin >> n;
                hr.setNume(n);
                break;
            }

            case 2:
            {
                float p;
                cin >> p;
                hr.setPret(p);
                break;
            }

            case 3:
            {
                string tipAn;
                cin >> tipAn;
                hr.setTipAnimal(tipAn);
                break;
            }

            case 4:
            {
                bool eUmeda;
                cin >> eUmeda;
                hr.setEsteUmeda(eUmeda);
                break;
            }

            case 5:
            {
                int valNut;
                cin >> valNut;
                hr.setValNutritiva(valNut);
                break;
            }

            default:
                cout << "Nu corespunde niciunui atribut! \n";
                break;
            }
            break;


        case 12:
            cout << "Hainuta are urmatoarele atribute:\n" << " 1. denumire\n" << " 2. marime\n" << " 3. tipAnimal\n"
                 << " 4. pret\n" << " 5. culoare\n";
            cout << "Ce doriti sa editati? Scrieti numarul corespunzator atributului dorit: \n";
            int inputHainuta;
            cin >> inputHainuta;
            switch (inputHainuta)
            {
            case 1:
            {
                string den;
                cin >> den;
                h.setDenumire(den);
                break;
            }

            case 2:
            {
                char mar;
                cin >> mar;
                h.setMarime(mar);
                break;
            }

            case 3:
            {
                string tipAn;
                cin >> tipAn;
                h.setTipAnimal(tipAn);
                break;
            }

            case 4:
            {
                double pr;
                cin >> pr;
                h.setPret(pr);
                break;
            }

            case 5:
            {
                string cul;
                cin >> cul;
                h.setCuloare(cul);
                break;
            }

            default:
                cout << "Nu corespunde niciunui atribut! \n";
                break;
            }
            break;

        case 13:
        {
            bool copieAreProblemeSpeciale = a.getAreProblemeSpeciale();
            
            if (copieAreProblemeSpeciale == false && a.verificaObezitate() == false)
                cout << " Animalul nu are nicio problema speciala\n";
            else
                if (copieAreProblemeSpeciale == true && a.verificaObezitate() == false)
                    cout << " Animalul nu are probleme cu obezitatea, dar are alte probleme speciale\n";
                else
                    cout << " Animalul are probleme cu obezitatea\n";
            break;       
        }

        case 14:
        
            if (c.poateAdoptaAnimal(a) == true)
                cout << " Clientul poate adopta animalul\n";
            else
                cout << " Clientul nu poate adopta acest animal\n";
            break;
        

        case 15:
        
            if (hr.getEsteUmeda() == true)
                cout << " Animalului" << " " << a.getNume() << " " << "i se recomada" << " " 
                     << hr.calculeazaGrameHrana(a) << " " << "grame de hrana umeda.\n";
            else
                cout << " Animalului" << " " << a.getNume() << " " << "i se recomada" << " "
                << hr.calculeazaGrameHrana(a) << " " << "grame de hrana uscata.\n";
            break;
        

        case 16:
        
            cout << "Marimea hainutei" << " " << h.getDenumire() << " " 
                 << "ce se recomanda pentru animalul creat este" << " " << h.aflaMarimeRecomandata(a)<<endl;
            break;
        
        default:
            cout << "Optiunea nu exista! " << endl;
            break;
        }
    }








    /*
    Client c1("balasa", "bianca", new int(20), 4.55, 1), 
    Client c2("Cioinica", "Petru", new int(22), 4, 4);
    Client c3;
    c3 = c1 + c2;
    cout << c3;
    */

    /*
    Hrana hr1("BrtCare", 34.5);
    Hrana hr2("Whiskas", 22.99);
    Hrana hr3;
    hr3 = hr1 + hr2;
    cout << hr3;
    */


    /*
    Animal a1("piscot", 1, 2.333, 3.444);
    Animal a2("pisicescu", 2, 3.444, 6.55);
    Animal a3;
    a3 = a1 + a2;
    cout << a3;
    */

    /*
    Hainuta h1("pelerina", "pisica", 22.33);
    Hainuta h2("salopeta", "Caine", 44.78);
    Hainuta h3;
    h3 = h1 + h2;
    cout << h3;
    */

    /*
    Animal a1("piscot", 'M', true, 1, false, 22.5, 233.3);
    Animal a2("piscot", 'M', true, 1, false, 22.4, 233.3);
   
    if (a1 == a2)
        cout << "DA";
    else
        cout << "NU";

    //cout<<a1.getNumarAnimale();
    */

   
    /*
    Client c1;
    cin >> c1;
    Client c2 = c1;
    cout << c2;
    */

    /*
    Hrana hr5("BritCare",25.9, "pisica",true,155 );
    Animal a
    */
    
    /*
    Hainuta h10("onesie","caine",20);
    Animal a10("Rex", 7, 10);
    cout << " Recomandam marimea " << h10.aflaMarimeRecomandata(a10) << endl;
    */


    /*
    Animal a7("Sophie",5,6);
    a7.setAreProblemeSpeciale(false);
    cout << "Are probleme speciale: " << a7.verificaObezitate();
    cout << endl;
    */

    
    /*
    Client c5("Balasa", "Bianca", new int(20), 3.55, 1);
    cout<<"Poate adopta: "<< c5.poateAdoptaAnimal(a1);
    cout << endl;
    */
    

    /*
    Animal a1;
    cin>>a1;
    cout << a1 << endl; 
    Client c1;
    cin >> c1;
    cout << c1 << endl;
    Hrana h1;
    cin >> h1;
    cout << h1 << endl;
    Hainuta ha1;
    cin >> ha1;
    cout << ha1 << endl;
    */
    
    return 0;
}