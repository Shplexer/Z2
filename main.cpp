#include "main.h"
#include <memory>
int main() {

	bool exitFlag;
	bool exitAllFlag;
	cout << "===================================================================================================================" << endl;
	cout << "Welcome!" << endl << "Made by Orekhov Daniil, group 423, task #2, variant #3" << endl;
	cout << "===================================================================================================================" << endl;
	cout << "Task: Develop a base and derived class for a given subject area and implement methods and attributes for these classes" << endl <<
		"Implement a way to access objects in a cotainer" << endl <<
		"Base class: mammals" << endl <<
		"Attributes: nutrition, weight, environment" << endl <<
		"Derived class: Carnivores" << endl;
	do {
		std::string fileName;
		std::vector<std::any> animals;
		do {
			cout << "===================================================================================================================" << endl;
			giveMainMenu();
			exitFlag = true;
			fileMenuChoice choice = static_cast<fileMenuChoice>(checkInt());
			switch (choice)
			{
			case fileMenuChoice::test:
				launchTest();
				exitFlag = false;
				break;
			case fileMenuChoice::file:
				tie(exitFlag, fileName) = openFile();
				if(exitFlag)
					setList(animals, fileName);
				break;
			case fileMenuChoice::empty:
				break;
			case fileMenuChoice::exit:
				cout << "Exiting the program...";
				std::exit(0);
			default:
				cout << "ERR. Wrong input, try again" << endl;
				exitFlag = false;
				break;
			}
		} while (!exitFlag);
		do {
			printAll(animals);
			giveEditMenu();
			exitFlag = false;
			exitAllFlag = false;
			//int tempCh = checkInt();
			editMenuChoice choice = static_cast<editMenuChoice>(checkInt());
			switch (choice)
			{
			case editMenuChoice::add:
				add(animals, false);
				break;
			case editMenuChoice::remove:
				if (animals.size() != 0) {
					remove(animals, false);
				}
				else{
					cout << "ERR. There are no mammals that can be deleted" << endl;
				}
				break;
			case editMenuChoice::save:
				fileName = saveFileCheck(fileName);
				saveToFile(animals, fileName);
				break;
			case editMenuChoice::goBack:
				exitFlag = true;
				break;
			case editMenuChoice::exit:
				cout << "Exiting the program...";
				exitAllFlag = true;
				exitFlag = true;
				break;
			default:
				cout << "ERR. Wrong input, try again" << endl;
				break;
			}
		} while (!exitFlag);
		animals.clear();
		//printAll(animals);
	} while (!exitAllFlag);

	return 0;
}
