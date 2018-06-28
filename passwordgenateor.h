#ifndef PASSWORDGENERATEOR_H
#define PASSWORDGENERATEOR_H
#include "password.h"
void passwordgenateor() {
	password* in=nullptr;
	char type;
	int plong=0;
	cout << "Welcome to password generateeor" << endl;
	cout << "please chooce the password type(A:letter only,B:number only,C:letter and number):";
	cin >> type;
	switch (type) {
	case'A':
	case'a': {
		cout << "How long of the password?";
		cin >> plong;
		charpass cp(plong);
		//cp.setpasslong(plong);
		in = &cp;
		cout << "Password created." << endl << "the password is " << cp.gempassword() << endl;
		break;
	}
	case'B':
	case'b':
	{cout << "How long of the password?";
	cin >> plong;
	numpass np(plong);
	//np.setpasslong(plong);
	in = &np;
	cout << "Password created." << endl << "the password is " << np.gempassword() << endl;
	break;
	}
	case'C':
	case'c': {
		cout << "How long of the password?";
		cin >> plong;
		mixpass mp(plong);
		//mp.setpasslong(plong);
		in = &mp;
		cout << "Password created." << endl << "the password is " << mp.gempassword() << endl;
		break;
	}
	}
};
#endif