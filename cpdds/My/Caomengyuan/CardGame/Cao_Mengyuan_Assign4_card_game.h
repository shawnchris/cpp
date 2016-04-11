#ifndef card_game_h
#define card_game_h
#include <algorithm>

const int SIZE = 200;

class Deck_of_Card {

public:
	double Cardboard[SIZE][SIZE];

	void initialize() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				Cardboard[i][j] = -1;
	}

	double value(int r, int b) {
		if (Cardboard[r][b] != -1)
			return Cardboard[r][b];

		double term1 = ((double) r / (r + b)) * value(r - 1, b);

		double term2 = ((double) b / (r + b)) * value(r, b - 1);

		Cardboard[r][b] = std::max((term1 + term2), (double) (b - r));

		return Cardboard[r][b];
	}

};

#endif
