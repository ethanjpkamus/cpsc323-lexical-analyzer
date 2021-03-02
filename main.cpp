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

	if(argc != 2)
	{
		cout << "not swag" << endl;
		return EXIT_FAILURE;
	}
	string filename = argv[1];
	ifstream inputfile;

	//open input file and add it to ifstream object
	inputfile.open(filename);
	if(!inputfile.is_open())
	{
		cout << "not swag" << endl;
		return EXIT_FAILURE;
	}
	//function call to lexer() and pass it an ifstream
	//receive output from lexer() and store in main
	//store output in a new txt file via ofstream

	return 0;
}