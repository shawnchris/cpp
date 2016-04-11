#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class stable_marriage_instance {
	// Private
	int no_of_couples;
	vector<vector<int> > Preference_of_men;
	vector<vector<int> > Preference_of_women;
	vector<int> match_for_men;
	vector<int> match_for_women;

	// private member function: checks if anybody is free in boolean "my_array"
	// returns the index of the first-person who is free in "my_array"
	// if no one is free it returns a -1.
	int anybody_free(vector<bool> my_array) {
		// fill the necessary code for this function
		for (int i = 0; i < no_of_couples; i++)
			if (my_array[i] == true)
				return i;

		return -1;
	}

	// private member function: if index1 is ranked higher than index2
	// in a preference array called "my_array" it returns "true"; otherwise
	// it returns "false"
	bool rank_check(vector<int> my_array, int index1, int index2) {
		// fill the necessary code for this function
		int rank1, rank2;
		for (int i = 0; i < no_of_couples; i++) {
			if (my_array[i] == index1)
				rank1 = i;
			if (my_array[i] == index2)
				rank2 = i;
		}

		// smaller is higher
		return rank1 < rank2 ? true : false;
	}

	// private member function: implements the Gale-Shapley algorithm
	void Gale_Shapley() {
		vector<bool> is_man_free;
		vector<bool> is_woman_free;
		vector<vector<bool> > has_this_man_proposed_to_this_woman;

		int man_index, woman_index;

		// initializing everything
		is_man_free.resize(no_of_couples);
		is_woman_free.resize(no_of_couples);
		has_this_man_proposed_to_this_woman.resize(no_of_couples);
		match_for_men.resize(no_of_couples);
		match_for_women.resize(no_of_couples);
		for (int i = 0; i < no_of_couples; i++) {
			// do the necessary initialization here
			has_this_man_proposed_to_this_woman[i].resize(no_of_couples);
			is_man_free[i] = true;
			is_woman_free[i] = true;
			for (int j = 0; j < no_of_couples; j++)
				has_this_man_proposed_to_this_woman[i][j] = false;
			match_for_men[i] = -1;
			match_for_women[i] = -1;
		}

		// Gale-Shapley Algorithm
		while ((man_index = anybody_free(is_man_free)) >= 0) {
			// fill the necessary code here
			// Let w be the first woman on M's preference-list to whom M has not yet proposed.
			for (int i = 0; i < no_of_couples; i++) {
				woman_index = Preference_of_men[man_index][i];
				if (!has_this_man_proposed_to_this_woman[man_index][woman_index])
					break;
			}

			// if w is un-engaged then
			// Assign M and w to be engaged to each other.
			if (match_for_women[woman_index] == -1) {
				match_for_women[woman_index] = man_index;
				match_for_men[man_index] = woman_index;
				has_this_man_proposed_to_this_woman[man_index][woman_index] =
						true;
				is_man_free[man_index] = false;
				is_woman_free[woman_index] = false;
			}
			// else
			// if w prefers M to her fiance M' then
			// Assign M and w to be engaged to each other. Declere M' to be un-engaged.
			else if (rank_check(Preference_of_women[woman_index], man_index,
					match_for_women[woman_index])) {
				match_for_men[match_for_women[woman_index]] = -1;
				is_man_free[match_for_women[woman_index]] = true;
				match_for_women[woman_index] = man_index;
				match_for_men[man_index] = woman_index;
				has_this_man_proposed_to_this_woman[man_index][woman_index] =
						true;
				is_man_free[man_index] = false;
				is_woman_free[woman_index] = false;
			}
			// else
			// w rejects M (and M remains un-engaged).
			else {
				has_this_man_proposed_to_this_woman[man_index][woman_index] =
						true;
			}
		}
	}

	// private member function: reads data
	bool read_data(int argc, const char * argv[]) {
		// fill the necessary code here.  The first entry in the input
		// file is the #couples, followed by the preferences of the men
		// and preferences of the women.  Keep in mind all indices start
		// from 0.
		cout << "Input file name: " << argv[1] << endl;
		ifstream f(argv[1], ios_base::in);
		if (f.good()) {
			f >> no_of_couples;
			cout << "Number of couples = " << no_of_couples << endl;

			Preference_of_men.resize(no_of_couples);
			Preference_of_women.resize(no_of_couples);
			for (int i = 0; i < no_of_couples; i++) {
				Preference_of_men[i].resize(no_of_couples);
				for (int j = 0; j < no_of_couples; j++)
					f >> Preference_of_men[i][j];
			}
			for (int i = 0; i < no_of_couples; i++) {
				Preference_of_women[i].resize(no_of_couples);
				for (int j = 0; j < no_of_couples; j++)
					f >> Preference_of_women[i][j];
			}

			cout << endl << "Preferences of Men" << endl;
			cout << "--------------------" << endl;
			for (int i = 0; i < no_of_couples; i++) {
				cout << "(" << i << "): ";
				for (int j = 0; j < no_of_couples; j++)
					cout << Preference_of_men[i][j] << " ";
				cout << endl;
			}
			cout << endl << "Preferences of Women" << endl;
			cout << "--------------------" << endl;
			for (int i = 0; i < no_of_couples; i++) {
				cout << "(" << i << "): ";
				for (int j = 0; j < no_of_couples; j++)
					cout << Preference_of_women[i][j] << " ";
				cout << endl;
			}

			return true;
		} else {
			cout << "Input file does not exist!" << endl;
			return false;
		}
	}

	// private member function: print solution
	void print_soln() {
		// write the appropriate code here
		cout << endl << "Matching of Men" << endl;
		for (int i = 0; i < no_of_couples; i++)
			cout << "Man:" << i << " -> Woman: " << match_for_men[i] << endl;
		cout << endl << "Matching of Women" << endl;
		for (int i = 0; i < no_of_couples; i++)
			cout << "Woman:" << i << " -> Man: " << match_for_women[i] << endl;
	}

public:
	void solve_it(int argc, const char * argv[]) {
		cout << "Gale-Shapley Algorithm" << endl;
		if (read_data(argc, argv)) {
			Gale_Shapley();
			print_soln();
		}
	}
};

int main(int argc, const char * argv[]) {
	stable_marriage_instance x;
	x.solve_it(argc, argv);
}
