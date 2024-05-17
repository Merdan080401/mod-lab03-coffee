#include "Automata.h"
#include <cassert>

void testOnOff() {
    Automata machine;
    assert(machine.getState() == Automata::OFF);
    machine.on();
    assert(machine.getState() == Automata::WAIT);
    machine.off();
    assert(machine.getState() == Automata::OFF);
}

void testCoin() {
    Automata machine;
    machine.on();
    machine.coin(1.0);
    assert(machine.getState() == Automata::ACCEPT);
}

void testChoice() {
    Automata machine;
    const std::string menu[] = {"Coffee", "Tea", "Milk"};
    const double prices[] = {1.5, 1.0, 0.75};
    machine.getMenu(menu, prices, 3);
    machine.on();
    machine.coin(2.0);
    machine.choice(1);
    assert(machine.check());
}

void testCancel() {
    Automata machine;
    machine.on();
    machine.coin(1.0);
    machine.cancel();
    assert(machine.getState() == Automata::WAIT);
    assert(machine.cash == 0);
}

int main() {
    testOnOff();
    testCoin();
    testChoice();
    testCancel();

    return 0;
}
