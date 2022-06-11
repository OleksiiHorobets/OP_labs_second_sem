#include <iostream>
#include <vector>
#include "TIntNumber.h"
#include "TRealNumber.h"
#include <ctime>


using namespace std;


vector<TIntNumber*> generate_TIntNumber_vec(int m){
	const int LOWER_BOUND = -1000;
	const int UPPER_BOUND = 1000;

	vector<TIntNumber*> vec;
	for (int i = 0; i < m; i++)
	{
		vec.push_back(new TIntNumber(LOWER_BOUND + rand()%(2*UPPER_BOUND)));
	}
	return vec;
}

vector<TRealNumber*> generate_TRealNumber_vec(int n) {
	const int LOWER_BOUND = -1000;
	const int UPPER_BOUND = 1000;

	vector<TRealNumber*> vec;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(new TRealNumber(LOWER_BOUND + rand() % (2 * UPPER_BOUND), rand() % UPPER_BOUND));
	}
	return vec;
}


int get_first_dgts_sum(vector<TIntNumber*>& vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i]->getFirstDgt();
	}
	return sum;
}

int get_last_dgts_sum(vector<TRealNumber*>& vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i]->getLastDgt();
	}
	return sum;
}

int main()
{
	srand(time(NULL));
	int m;
	cout << "Enter m: ";
	cin >> m;

	int n;
	cout << "Enter n: ";
	cin >> n;

	vector<TIntNumber*> int_numbers_vec = generate_TIntNumber_vec(m);
	vector<TRealNumber*> real_numbers_vec = generate_TRealNumber_vec(n);

	int first_dgts_sum = get_first_dgts_sum(int_numbers_vec);
	int last_dgts_sum = get_last_dgts_sum(real_numbers_vec);
	

	cout << "First digits sum of integer numbers: " << first_dgts_sum << endl;
	cout << "Last digits sum of real numbers: " << last_dgts_sum << endl;

}
