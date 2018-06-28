#include "password.h"

void password::setpasslong(int length) {
	passwordlength = length;//if the password is longer than new length ,then cut the extra size , shorter will add 0 at the end
	while (word.length() > length)
		word.pop_back();
	while (word.length() < length)
		word.push_back('0');
}
void password::passtotxt() {
	ofstream outfile ("newpassword.txt");
	outfile << "Password: "<<word<<endl;
	outfile.close();
};
string password::getword() {
	return word;
}
string charpass::gempassword(){
for (int i = 0; i<passwordlength; i++)
	if (rand() % 2 == 0)
		word += (char)(rand() % 26 + 65);
	else
		word += (char)(rand() % 26 + 97);
return word;
	  }
string numpass::gempassword() {
	for (int i = 0; i<passwordlength; i++)
		word += rand() % 10 + 48;
	return word;
};
string mixpass::gempassword() {
	int choice=0;
	for (int i = 0; i < passwordlength; i++)
	{
		choice = rand() % 3;
		switch (choice) {
		case(0):
			word += (char)(rand() % 26 + 65);
				break;
		case(1):
			word += (char)(rand() % 26 + 97);
			break;
		case(2):
			word += rand() % 10 + 48;
				break;
		};
	}
	return word;
};