// string_pattern.cpp : Defines the entry point for the console application.
//



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;



//
//	dump backup 
//

void dump_backup()
{
#if __back__up 
	int N;
	std::cin >> N;
	std::string str;
	for (int i = 0; i < N; ++i)
	{
		std::cout.width(N);
		str += "#";
		std::cout << str.c_str()
			<< std::endl;
	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	//	int N;
	std::cin >> N;

	int count_pos = 0;
	int count_neg = 0;
	int count_zero = 0;

	for (int i = 0; i < N; ++i)
	{
		int value = 0;
		cin >> value;

		if (value == 0)
			++count_zero;
		else if (value > 0)
			++count_pos;
		else if (value < 0)
			++count_neg;

	}
	std::cout.precision(3);
	float fra_pos = ((float)count_pos) / ((float)N);
	float fra_neg = ((float)count_neg) / ((float)N);
	float fra_zero = ((float)count_zero) / ((float)N);

	cout << fixed << setprecision(3);

	cout << fra_pos << endl;
	cout << fra_neg << endl;
	cout << fra_zero;

	return 0;
#endif 

}


/*

	compute table to have largest prefix  length of the substring which is also suffix of same substring 

	abab
	a		= 0
	ab		= 0
	aba		= 1
	abab	= 2

	abcabc

	a		= 0
	ab		= 0
	abc		= 0
	abca	= 1
	abcab   = 2
	abcabc  = 3


	abcaabc
	a		= 0
	ab		= 0
	abc		= 0
	abca    = 1
	abcaa   = 1
	abcaab  = 2
	abcabc  = 3


	ababdc

	a		= 0
	ab		= 0
	aba     = 1
	abab    = 2
	ababd   = 0
	ababdc  = 0

*/


static void compute_longest_suffix_prefix_table(std::vector<int>& table, const std::string& pattern)
{
	size_t length = pattern.length();
	table.resize(length);

	table[0] = 0;

	//size_t index = 0;

	for ( size_t k = 1; k < length; ++k)
	{
		size_t i = table[k - 1];
		
		while (1)
		{
			if (pattern[i] == pattern[k])
			{				
				table[k] = i+1;
				break;
			}
			
			if (i == 0)
			{
				table[k] = 0;
				break;
			}
				
			i = table[i];
		}
	}

	cout << "For pattern = " << pattern.c_str() << endl;
	size_t length_table = table.size();
	for (size_t x = 0; x < length_table; ++x)
	{
		cout << table[x] << endl;
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> table;

/*
	// [ Unit Test ] - 1
	abab
	a = 0
	ab = 0
	aba = 1
	abab = 2
*/
	//string pattern = "abab";

/*
// [ Unit Test ] - 2

	abcabc

		a = 0
		ab = 0
		abc = 0
		abca = 1
		abcab = 2
		abcabc = 3
	*/
	//string pattern = "abcabc";

/*
// [ Unit Test ] - 3
	abcaabc
		a = 0
		ab = 0
		abc = 0
		abca = 1
		abcaa = 1
		abcaab = 2
		abcabc = 3
*/
	string pattern = "abcaabc";
	compute_longest_suffix_prefix_table(table, pattern);
	return 0;
}

