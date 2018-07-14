#ifndef MORSECODERULE_H
#define MORSECODERULE_H
#include <string>
#include <iostream>
using namespace std;
class morsestream {//translate a letter to morce code or morce code to letter
private:
	char letter;
	string morse;
public: 
	morsestream() :letter(' '), morse(" ") {};
	morsestream(char _letter, string _morse) :letter(_letter),morse(_morse){};
	char outchar(){
		return letter;
	};
	string outmorse() {
		return morse;
	};
	morsestream & operator= (const morsestream & other) {
		letter = other.letter;
		morse = other.morse;
	};
};
class morsetable {//morce code table
private:
	morsestream table[36];
public:
	morsetable() :table{ {'A',"10111"},{'B',"111010101"},{'C',"111010111010"},
	{'D',"11101010"},{'E',"1"},{'F',"101011101"},{'G',"111011101"},
	{'H',"1010101"},{'I',"101"},{'J',"1011101110111"},{'K',"111010111"},
	{'L',"101110101"},{'M',"1110111"},{'N',"11101"},{'O',"11101110111"},
	{'P',"10111011101"},{'Q',"1110111010111"},{'R',"1011101"},{'S',"10101"},
	{'T',"111"},{'U',"1010111"},{'V',"101010111"},{'W',"101110111"},
	{'X',"11101010111"},{'Y',"1110101110111"},{'Z',"11101110101"},
	{'1',"10111011101110111"},{'2',"101011101110111"},{'3',"10101010111"},
	{'4',"10101010111"},{'5',"101010101"},{'6',"11101010101"},
	{'7',"1110111010101"},{'8',"111011101110101"},{'9',"11101110111011101"},
	{'0',"1110111011101110111"} } {};
	string CharToMorse(char tran);
	char MorseToChar(string tran);
};
class wordToMorse{//word
private:
	string nomalword, morsecode;
	morsetable T;
public:
	wordToMorse():nomalword(""),morsecode("") {};
	string  translate(string inword);
};
class sentMorseTranslate {//sentence translate
  private:
	  wordToMorse W;
  public:
	  string sentToMor(string insentense);
};


class MorseToWord {
private:
	string nomalword;
	morsetable T;
public:
	string toWord(string inMorse);
};
class MorseToSent {
private:
	MorseToWord W;
public:
	string ToSent(string inMorse);
};
#endif 
