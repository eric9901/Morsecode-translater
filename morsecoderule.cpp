#include "morsecoderule.h"
string morsetable::CharToMorse(char tran) {
	bool find = false;
	int i = 0;
	while (i<36) {
		if (table[i].outchar() == tran)
			return table[i].outmorse();
		i++;
	};
	return "error ";
}
char morsetable::MorseToChar(string tran) {
	bool find = false;
	int i = 0;
	while (i<36) {
		if (table[i].outmorse() == tran)
			return table[i].outchar();
		i++;
	};
	return '@';
};
string wordMorEncry::encrypt(string inword){
	nomalword = inword;
	string morse = "";
	for (int i=0; i < inword.length(); i++) {
		morse += T.CharToMorse(inword[i]);
		if (i != inword.length()- 1)
			morse += "000";
	};
	return morse;
};
string sentMorseEncry::sentMor(string insentense) {
	string temp = "", word = "";
	size_t letter = insentense.find_first_of(" "), nowletter;
	word.assign(insentense, 0, letter);//translate first word
	temp += W.encrypt(word);
	nowletter = letter;
	temp += "0000000";
	do {
		word = "";
		letter = insentense.find_first_of(" ", letter + 1);
		word.assign(insentense, nowletter + 1, letter - nowletter - 1);
		temp += W.encrypt(word);
		if(letter != std::string::npos)
		temp += "0000000";
		nowletter = letter;
	} while (letter != std::string::npos);
	return temp;
};