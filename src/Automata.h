#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>

class Automata {
public:
    enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

    Automata();
    void on();
    void off();
    void coin(double money);
    void getMenu(const std::string menu[], const double prices[], int size);
    STATES getState() const;
    void choice(int drink);
    bool check();
    void cancel();
    void cook();
    void finish();

private:
    double cash;
    std::string menu[10];
    double prices[10];
    STATES state;
    int chosenDrink;
};

#endif // AUTOMATA_H
