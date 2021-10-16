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

public:
    void setNumePrenume(string numePrenumeNou) { numePrenume = numePrenumeNou; }
    void setVarsta(int *varstaNoua) { varsta = varstaNoua; }
    void setSex(char *sexNou) { sex = sexNou; }
    void setRating(double ratingNou) { rating = ratingNou; }
    void setAnimaleDetinute(int animaleDetinuteNou) { animaleDetinute = animaleDetinuteNou; }

    string getNumePrenume() { return numePrenume; }
    int *getVarsta() { return varsta; }
    char *getSex() { return sex; }
    double getRating() { return rating; }
    int getAnimaleDetinute() { return animaleDetinute; }
};

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

public:
    void setNume(string numeNou) { nume = numeNou; }
    void setSex(char sexNou) { sex = sexNou; }
    void setEsteCumparat(bool esteCumparatNou) { esteCumparat = esteCumparatNou; }
    void setVarsta(int varstaNou) { varsta = varstaNou; }
    void setAreProblemeSpeciale(bool areProblemeSpecialeNou) { areProblemeSpeciale = areProblemeSpecialeNou; }
    void setGreutate(float greutateNoua) { greutate = greutateNoua; }
    void setPret(float pretNou) { pret = pretNou; }

    string getNume() { return nume; }
    char getSex() { return sex; }
    bool getEsteCumparat() { return esteCumparat; }
    int getVarsta() { return varsta; }
    bool getAreProblemeSpeciale() { return areProblemeSpeciale; }
    float getGreutate() { return greutate; }
    float getPret() { return pret; }
};

class Eveniment
{
private:
    Client client;
    Animal animal;
    string data;
    char tipEveniment; // A : de adoptat; L : lasat spre adoptie

public:
    void setClient(Client clientNou) { client = clientNou; }
    void setAnimal(Animal animalNou) { animal = animalNou; }
    void setData(string dataNoua) { data = dataNoua; }
    void setTipEveniment(char tipEvenimentNou) { tipEveniment = tipEvenimentNou; }

    Client getClient() { return client; }
    Animal getAnimal() { return animal; }
    string getData() { return data; }
    char getTipEveniment() { return tipEveniment; }
};

class Registru
{
private:
    const string numeMagazin = "NumeMagazin";
    Eveniment eveniment; //TO DO: schimba in lista de evenimente dupa ce rezolvam cu []
    static int numarClienti;
    static int numarAnimale;

public:
    void setEveniment(Eveniment evenimentNou) { eveniment = evenimentNou; }
    static void setNumarClienti(int numarClientiNou) { numarClienti = numarClientiNou; }
    static void setNumarAnimale(int numarAnimaleNou) { numarAnimale = numarAnimaleNou; }

    Eveniment getEveniment() { return eveniment; }
    static int getNumarClienti() { return numarClienti; }
    static int getNumarAnimale() { return numarAnimale; }
    string getNumeMagazin() { return numeMagazin; }
};

int Registru::numarClienti = 0;
int Registru::numarAnimale = 0;

int main()
{
    Client c1, c2;
    Registru::setNumarClienti(2);
    cout << Registru::getNumarClienti();
    return 0;
}