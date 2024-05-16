#include "Automata.h"

int main() {
    Automata machine;
    const std::string menu[] = {"Coffee", "Tea", "Milk"};
    const double prices[] = {1.5, 1.0, 0.75};
    machine.getMenu(menu, prices, 3);

    machine.on();
    machine.coin(2.0);
    machine.choice(0);
    if (machine.check()) {
        machine.cook();
    }
    machine.finish();
    return 0;
}
