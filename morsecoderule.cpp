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
string wordToMorse::translate(string inword){
	nomalword = inword;
	string morse = "";
	for (int i=0; i < inword.length(); i++) {
		morse += T.CharToMorse(inword[i]);
		if (i != inword.length()- 1)
			morse += "000";
	};
	return morse;
};
string sentMorseTranslate::sentToMor(string insentense) {
	string temp = "", word = "";
	size_t letter = insentense.find_first_of(" "), nowletter;
	word.assign(insentense, 0, letter);//translate first word
	temp += W.translate(word);
	nowletter = letter;
	if (letter != std::string::npos) {
		temp += "0000000";
		do {
			word = "";
			letter = insentense.find_first_of(" ", letter + 1);
			word.assign(insentense, nowletter + 1, letter - nowletter - 1);
			temp += W.translate(word);
			if (letter != std::string::npos)
				temp += "0000000";
			nowletter = letter;
		} while (letter != std::string::npos);
	}
	return temp;
};
string MorseToWord::toWord(string inMorse) {
	string letterSpace,letter;
	string word = "";
	for (int i = 0; i < inMorse.length(); i++) {
		letter += inMorse[i];
		letterSpace += inMorse[i];
		
		if (letterSpace == "000") {
			for (int j = 0; j < 3; j++)
				letter.pop_back();
			word += T.MorseToChar(letter);
			letterSpace = "";
			letter = "";
		}
		else  if (inMorse[i] != '0')
			letterSpace ="";
		if (i+1 == inMorse.length())
			word += T.MorseToChar(letter);
		};
		
	return word;
};
string MorseToSent::ToSent(string inMorse) {
	string wordSpace, word;
	string sent = "";
	for (int i = 0; i < inMorse.length(); i++) {
		word += inMorse[i];
		wordSpace += inMorse[i];

		if (wordSpace == "0000000") {
			for (int j = 0; j < 7; j++)
				word.pop_back();
			sent+= W.toWord(word);
			wordSpace = "";
			word = "";
		}
		else  if (inMorse[i] != '0')
			wordSpace = "";
		if (i + 1 == inMorse.length())
			sent += " "+W.toWord(word);
	};

	return sent;
};