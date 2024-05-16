#include "Automata.h"
#include <iostream>

Automata::Automata() : cash(0), state(OFF), chosenDrink(-1) {}

void Automata::on() {
    state = WAIT;
    std::cout << "Automata is on.\n";
}

void Automata::off() {
    state = OFF;
    std::cout << "Automata is off.\n";
}

void Automata::coin(double money) {
    if (state == WAIT || state == ACCEPT || state == CHECK) {
        cash += money;
        state = ACCEPT;
        std::cout << "Money accepted: " << money << "\n";
    } else {
        std::cout << "Cannot accept money in current state.\n";
    }
}

void Automata::getMenu(const std::string menu[], const double prices[], int size) {
    for (int i = 0; i < size; ++i) {
        this->menu[i] = menu[i];
        this->prices[i] = prices[i];
    }
}

Automata::STATES Automata::getState() const {
    return state;
}

void Automata::choice(int drink) {
    if (state == ACCEPT) {
        if (drink >= 0 && drink < 10) {
            chosenDrink = drink;
            state = CHECK;
            std::cout << "You chose: " << menu[drink] << ".\n";
        } else {
            std::cout << "Invalid drink choice.\n";
        }
    } else {
        std::cout << "Cannot choose drink in current state.\n";
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[chosenDrink]) {
            state = COOK;
            return true;
        } else {
            std::cout << "Insufficient funds.\n";
            state = ACCEPT;
            return false;
        }
    } else {
        std::cout << "Cannot check in current state.\n";
        return false;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "Transaction cancelled.\n";
    } else {
        std::cout << "Cannot cancel in current state.\n";
    }
}

void Automata::cook() {
    if (state == COOK) {
        std::cout << "Cooking " << menu[chosenDrink] << ".\n";
        cash -= prices[chosenDrink];
        state = WAIT;
    } else {
        std::cout << "Cannot cook in current state.\n";
    }
}

void Automata::finish() {
    if (state == WAIT) {
        std::cout << "Thank you for using the automata.\n";
    } else {
        std::cout << "Cannot finish in current state.\n";
    }
}
