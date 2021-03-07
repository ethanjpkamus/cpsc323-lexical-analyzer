#include <vector>
#include <string>
#include <cctype>
#include <iostream>

#include "sig_item.cpp"

using std::vector;
using std::string;
using std::cout;
using std::endl;

enum states
{
	rej_ = 0,
	int_ = 1,
	ide_ = 2,
	sep_ = 3,
	opr_ = 4,
	com_ = 5,
	sps_ = 6
};

int statetable[][7] = {
	{rej_, int_, ide_, sep_, opr_, com_, sps_},
	{int_, int_, int_, rej_, rej_, rej_, rej_},
	{ide_, ide_, ide_, rej_, rej_, rej_, rej_},
	{sep_, rej_, rej_, rej_, rej_, rej_, rej_},
	{opr_, rej_, rej_, rej_, opr_, rej_, rej_},
	{com_, com_, com_, com_, com_, rej_, com_},
	{sps_, rej_, rej_, rej_, rej_, rej_, rej_}
};

//go through input file and sort everything out
vector<sig_item> lexer(string line)
{
	vector<sig_item> things;
	int endline = line.length();
	char current_char = ' ';
	int current_state = rej_;
	int transition = rej_;
	int previous_state = rej_;

	for(int i = 0; i < endline ; ++i)
	{
		current_char = line[i];
		transition = what_char(current_char);
		current_state = statetable[current_state][transition];

		if(current_state = rej_){
			//check if space and store into vector
		} else {
			//possibly increment here
		}
	}

	return things;
}

int what_char(char c)
{
	if(c == '!') 
	{ return com_; } 
	
	if(isalpha(c) || c == '_')
	{ return ide_; }
	
	if(is_sep(c))
	{ return sep_; }

	if(isdigit(c))
	{ return int_; }

	if(isspace(c))
	{ return sps_; }

	if(is_opr(c))
	{ return opr_; }

}

bool is_sep(char c)
{
	return (c == '{' || c == '}' || 
			c == '(' || c == ')' || 
			c == '[' || c == ']' ||
			c == ',' || c == '.' ||
			c == ':' || c == ';' );
}

bool is_opr(char c)
{
	return (c == '*' || c == '+' || 
			c == '-' || c == '=' || 
			c == '/' || c == '>' ||
			c == '<' || c == '%' );
}
