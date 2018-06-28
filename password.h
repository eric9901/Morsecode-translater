#ifndef PASSWORD_H
#define PASSWORD_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
class password {
protected:
	string word;
	int passwordlength;
public:
    password(){
		srand(time(NULL));
		word="";
		passwordlength = 4;
	};
	password(string inpass) :word(inpass) {
		srand(time(NULL));
		passwordlength = inpass.length();
	};
	password(int passlength) {
		srand(time(NULL));
		word = "";
		passwordlength = passlength;
	};
	void setpasslong(int length);
	string getword();
	void passtotxt();
	virtual string gempassword()=0;
};


class charpass : public password {
  public:
	  charpass() :password(){ };
	  charpass(int hi) :password(hi) { };
	  charpass(string hi) :password(hi) { };
	  string gempassword();
};


class numpass : public password {
public:
	numpass() :password() { };
	numpass(int hi) :password(hi) { };
	numpass(string hi) :password(hi) { };
	string gempassword();
};


class mixpass : public password {
public:
	mixpass() :password() { };
	mixpass(int hi) :password(hi) { };
	mixpass(string hi) :password(hi) { };
	string gempassword();
};
#endif 