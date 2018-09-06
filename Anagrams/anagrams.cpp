#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

int main()
{
	ifstream fin("anagrams.in");
	if (!fin)
	{
		cout << "Error opening input file. " << endl;
		return -1;
	}

	ofstream fout("anagrams.out");


	return 0;
}