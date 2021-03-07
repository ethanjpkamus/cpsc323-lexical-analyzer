#include <fstream>
#include <iomanip>
// #include <iostream>
// #include <vector>
#include "lexer.cpp"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::setw;

int main(int argc, char* argv[])
{
	//check if command line input is correct
	if(argc != 2)
	{
		cout << "not swag" << endl;
		return EXIT_FAILURE;
	}

	string filename = argv[1];
	string s = "";
	char t;
	ifstream inputfile;
	vector<sig_item> stuff;
	// vector<string> stuff;

	//open input file and add it to ifstream object
	inputfile.open(filename);
	
	if(!inputfile.is_open())
	{
		cout << "not swag" << endl;
		return EXIT_FAILURE;
	}
	while (getline(inputfile,s))
	{
		stuff = lexer(s);

		for(int i = 0; i < stuff.size(); ++i)
		{
			cout << setw(10) << stuff[i].token << " | " << stuff[i].lexeme << endl;
		}
	}

	// int temp = stuff.size();
	// for(int i = 0; i < temp; ++i)
	// {
	// 	cout << stuff[i] << endl;
	// }

	inputfile.close();


	//function call to lexer() and pass it an ifstream
	//receive output from lexer() and store in main
	//store output in a new txt file via ofstream

	return 0;
}