#include "interface.h"

void printAll(std::vector<std::any>& srcArr) {
	cout << "===================================================================================================================" << endl;
	cout << "Mammals: " << endl;
	cout << "===================================================================================================================" << endl;
	cout
		<< std::left
		<< std::setw(SSHRT) << "#"
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << "Mammal order"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Name"
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << "Nutrition"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Weight"
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << "Environment"
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << "Attack type"
		<< std::setw(SHRT) << "||"
		<< std::right << endl;
	cout << "===================================================================================================================" << endl;
	for (int i = 0; i < srcArr.size(); i++) {
		std::string typeN = srcArr[i].type().name();
		if (typeN == "class carnivores") {
			carnivores temp;
			temp = std::any_cast<carnivores>(srcArr[i]);
			temp.setNumber(i + 1);
			srcArr[i] = temp;
			std::any_cast<carnivores>(srcArr[i]).printAllElement();
		}
		else {
			mammals temp = std::any_cast<mammals>(srcArr[i]);
			temp.setNumber(i + 1);
			srcArr[i] = temp;
			std::any_cast<mammals>(srcArr[i]).printAllElement();
		}
	}
	cout << "===================================================================================================================" << endl;
}

void giveMainMenu() {
	cout
		<< "1. Test" << endl
		<< "2. Load a file" << endl
		<< "3. Manual input" << endl
		<< "4. Exit" << endl;
	cout << "===================================================================================================================" << endl;
}

void giveEditMenu() {
	cout << "Edit options:" << endl <<
		"1.Add a mammal to the list" << endl <<
		"2.Delete a mammal from the list" << endl <<
		"3.Save info to your file" << endl <<
		"4.Return to main menu" << endl <<
		"5.Exit the program." << endl;
	cout << "===================================================================================================================" << endl;
}