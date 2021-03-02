#include <fstream>
#include <iostream>
#include <vector>
// #include "lexer.cpp"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

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
	vector<string> stuff;

	//open input file and add it to ifstream object
	inputfile.open(filename);
	if(!inputfile.is_open())
	{
		cout << "not swag" << endl;
		return EXIT_FAILURE;
	}
	while (inputfile.get(t))
	{
		if (t == ' ' || t == '\n' || t == '\t')
		{
			stuff.push_back(s); //call lexer at this point in the code?
			s = ""; //this step should some how be done when the state is reset to the starting state.
		} else {
			s += t;
		}	
	}

	int temp = stuff.size();
	for(int i = 0; i < temp; ++i)
	{
		cout << *(stuff.begin() + i) << endl;
	}

	inputfile.close();


	//function call to lexer() and pass it an ifstream
	//receive output from lexer() and store in main
	//store output in a new txt file via ofstream

	return 0;
}