#include "ReadFile.h"
void readfile::read(string _filename) {
	openfile.open("example.txt");
	openfile << "Writing this to a file.\n";
};
void readfile::close() { openfile.close(); };

