#include <iostream>
#include "rower.h"

int main() {
    try {
        // Tworzymy rowery
        Rower rower1(80, 50, 15, 0.7);
        Rower rower2(90, 60, 18, 0.75);

        // Wyświetlanie danych roweru
        std::cout << "Rower 1:\n";
        rower1.wyswietlDane();

        std::cout << "\nRower 2:\n";
        rower2.wyswietlDane();

        // Porównanie rowerów
        if (rower1 == rower2) {
            std::cout << "\nRower 1 jest taki jak rower 2.\n";
        } else {
            std::cout << "\nRower 1 nie jest taki jak rower 2.\n";
        }

        // Zwiększanie kadencji
        rower1.zwiekszKadencje(10);
        std::cout << "\nPo zwiększeniu kadencji roweru 1:\n";
        rower1.wyswietlDane();

        // Porównanie kadencji
        std::cout << "\nPorównanie kadencji rowerów:\n";
        rower1.porownajKadencje(rower2);

    } catch (const std::invalid_argument& e) {
        std::cout << "Błąd: " << e.what() << std::endl;
    }

    return 0;
}
