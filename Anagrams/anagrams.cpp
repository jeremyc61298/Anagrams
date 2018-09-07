#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

void countLetters(string line, vector<int> &counts)
{
	for (auto letter : line)
	{
		if (isalpha(letter))
		{
			char upper = toupper(letter);
			counts[upper - 'A']++;
		}
	}
}

bool anagram(string line1, string line2)
{
	vector<int> counts1(26, 0);
	vector<int> counts2(26, 0);

	countLetters(line1, counts1);
	countLetters(line2, counts2);

	return (counts1 == counts2) ? true : false;
}

int main()
{
	ifstream fin("anagrams.in");
	if (!fin)
	{
		cout << "Error opening input file. " << endl;
		return -1;
	}

	ofstream fout("anagrams.out");
	const string endOfFile = "<end>";

	// Read in 2 lines
	string line1, line2;
	getline(fin, line1);
	getline(fin, line2);
	while (line1 != endOfFile && line2 != endOfFile)
	{
		bool result = anagram(line1, line2);
		fout << ((result) ? "YES" : "NO");

		getline(fin, line1);
		getline(fin, line2);

		if (line1 != endOfFile && line2 != endOfFile)
		{
			fout << endl;
		}
	}
	return 0;
}