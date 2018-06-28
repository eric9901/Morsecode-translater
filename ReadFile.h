#ifndef READFILE_H
#define READFILE_H
#include <iostream>
#include <fstream>
#include "morsecoderule.h"
using namespace std;
class readfile {
private:
	ofstream openfile;
	string filename;
public: 
	void read(string _FileName);
	void close();
};
class outfile {
private: 
	string filename;
public:
	outfile(string filename){
		ofstream morcefile("Morce.txt");
		morcefile << "HI" << endl;
		morcefile.close();
	};
};
#endif