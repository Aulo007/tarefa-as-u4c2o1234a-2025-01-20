#include "menu.h"

bool menu_is_valid_option(const MenuOption* options, int num_options, char input) {
    for (int i = 0; i < num_options; i++) {
        if (options[i].key == input) {
            return true;
        }
    }
    return false;
}
