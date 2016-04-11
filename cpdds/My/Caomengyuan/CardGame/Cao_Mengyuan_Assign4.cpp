#include <iostream>
#include "Cao_Mengyuan_Assign4_card_game.h"
using namespace std;

int main (int argc, char * const argv[])
{
    int total_number_of_cards;
    Deck_of_Card x;
    x.initialize();
    sscanf (argv[1], "%d", &total_number_of_cards);
    cout << "Total numebr of cards = " << total_number_of_cards << endl;
    cout << "Value of the game = " << x.value(total_number_of_cards / 2, total_number_of_cards / 2) << endl;
    return 0;
}
