#include "rower.h"

// Konstruktor z walidacją danych
Rower::Rower(int k, int p, int z, double s) {
    if (k <= 0) throw std::invalid_argument("Kadencja musi byc dodatnia.");
    if (p <= 0) throw std::invalid_argument("Przerzutki musza byc dodatnie.");
    if (z <= 0) throw std::invalid_argument("Ilosc zebatek musi byc dodatnia.");
    if (s <= 0) throw std::invalid_argument("Srednica kola musi byc dodatnia.");

    kadencja = k;
    przerzutka = p;
    zebatka = z;
    srednica_kola = s;
}

// Gettery
int Rower::getKadencja() const { return kadencja; }
int Rower::getPrzerzutka() const { return przerzutka; }
int Rower::getZebatka() const { return zebatka; }
double Rower::getSrednicaKola() const { return srednica_kola; }

// Settery
void Rower::setKadencja(int k) {
    if (k <= 0) throw std::invalid_argument("Kadencja musi byc dodatnia.");
    kadencja = k;
}

void Rower::setPrzerzutka(int p) {
    if (p <= 0) throw std::invalid_argument("Przerzutki musza byc dodatnie.");
    przerzutka = p;
}

void Rower::setZebatka(int z) {
    if (z <= 0) throw std::invalid_argument("Ilosc zebatek musi byc dodatnia.");
    zebatka = z;
}

void Rower::setSrednicaKola(double s) {
    if (s <= 0) throw std::invalid_argument("Srednica kola musi byc dodatnia.");
    srednica_kola = s;
}

// Metoda obliczająca prędkość
double Rower::obliczPredkosc() const {
    double przelozenie = double(przerzutka) / zebatka;
    return (kadencja * przelozenie * M_PI * srednica_kola) / 60.0;
}

// Metoda obliczająca przełożenie
double Rower::obliczPrzelozenie(double predkosc) const {
    return (predkosc * 60.0) / (kadencja * M_PI * srednica_kola);
}

// Metoda do wyświetlania danych
void Rower::wyswietlDane() const {
    std::cout << "Kadencja: " << kadencja << " obr/min\n";
    
    if (przerzutka == 1) {
        std::cout << "Przerzutka: " << przerzutka << " zab\n";
    } else if (przerzutka >= 2 && przerzutka <= 4) {
        std::cout << "Przerzutka: " << przerzutka << " zeby\n";
    } else {
        std::cout << "Przerzutka: " << przerzutka << " zebow\n";
    }

    if (zebatka == 1) {
        std::cout << "Zebatka: " << zebatka << " zab\n";
    } else if (zebatka >= 2 && zebatka <= 4) {
        std::cout << "Zebatka: " << zebatka << " zeby\n";
    } else {
        std::cout << "Zebatka: " << zebatka << " zebow\n";
    }
    std::cout << "Srednica kola: " << srednica_kola << " m\n";
    double predkosc = obliczPredkosc();
    std::cout << "Prędkość przy kadencji " << getKadencja() << " obr/min: " << predkosc << " m/s\n";
    double przelozenie = obliczPrzelozenie(10.0);
    std::cout << "Przełożenie dla prędkości 10 m/s: " << przelozenie << "\n";
}

// Zwiększanie kadencji
void Rower::zwiekszKadencje(int increment) {
    if (increment > 0) {
        kadencja += increment;
    } else {
        std::cout << "Wartość przyrostu kadencji musi być dodatnia.\n";
    }
}

// Porównanie kadencji
void Rower::porownajKadencje(const Rower& other) const {
    if (this->getKadencja() > other.getKadencja()) {
        std::cout << "Rower 1 ma wyższą kadencję niż Rower 2.\n";
    } else if (this->getKadencja() < other.getKadencja()) {
        std::cout << "Rower 2 ma wyższą kadencję niż Rower 1.\n";
    } else {
        std::cout << "Rowery mają równą kadencję.\n";
    }
}

// Porównanie rowerów
bool Rower::operator==(const Rower& other) const {
    return (this->getKadencja() == other.getKadencja() && this->getPrzerzutka() == other.getPrzerzutka() && 
            this->getZebatka() == other.getZebatka() && this->getSrednicaKola() == other.getSrednicaKola());
}
