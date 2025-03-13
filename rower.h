#ifndef ROWER_H
#define ROWER_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>

class Rower {
private:
    int kadencja;         // Liczba obrotów na minutę
    int przerzutka;       // Liczba zębów na przedniej zębatce
    int zebatka;          // Liczba zębów na tylnej zębatce
    double srednica_kola; // Średnica koła w metrach

public:
    // Konstruktor
    Rower(int k, int p, int z, double s);

    // Gettery
    int getKadencja() const;
    int getPrzerzutka() const;
    int getZebatka() const;
    double getSrednicaKola() const;

    // Settery
    void setKadencja(int k);
    void setPrzerzutka(int p);
    void setZebatka(int z);
    void setSrednicaKola(double s);

    // Metody obliczające
    double obliczPredkosc() const;
    double obliczPrzelozenie(double predkosc) const;

    // Metody operacyjne
    void wyswietlDane() const;         // Wyświetlanie obiektu
    void zwiekszKadencje(int increment); // Zwiększanie kadencji
    void porownajKadencje(const Rower& other) const; // Porównanie kadencji
    bool operator==(const Rower& other) const; // Porównanie obiektów
};

#endif // ROWER_H
