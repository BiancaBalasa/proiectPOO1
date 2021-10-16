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
    void setNumePrenume(string numeNou) { numePrenume = numeNou; }
    string getNumePrenume() { return numePrenume; }
};

class Animal
{
private:
    string nume;
    char sex; // M sau F
    bool esteAdoptat;
    int varsta;
    bool areProblemeSpeciale; // 0: nu are probleme; 1: are probleme
    float greutate;
    float pret;
};

class Eveniment
{
private:
    Client client;
    Animal animal;
    string data;
    char tipEveniment; // A : de adoptat; L : lasat spre adoptie
};

class Registru
{
private:
    const string numeMagazin = "NumeMagazin";
    Eveniment evenimente; //TO DO: schimba in lista de evenimente dupa ce rezolvam cu []
    static int numarClienti;
    static int numarAnimale;
};
int Registru::numarClienti = 0;
int Registru::numarAnimale = 0;

int main()
{
    Client c1, c2;

    return 0;
}