#include "functions.h"

std::string makeLineGood() {
	std::string input{ "==" };
	std::getline(cin >> std::ws, input);
	for (auto i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			input[i] = '_';
		}
	}
	return input;
}

std::string getGoodLine(std::string input) {
	std::string temp = input;
	for (auto i = 0; i < temp.size(); i++) {
		if (temp[i] == '_') {
			temp[i] = ' ';
		}
	}
	return temp;
}

int checkInt() {
	int input{ 0 };
	while (!(cin >> input)) {
		cin.clear();											//discard err flag
		cin.ignore(INT_MAX, '\n');								//clear buffer for INT_MAX characters or until '\n'
		cout << "ERR. Wrong input, try again" << endl;
	}
	cin.ignore(INT_MAX, '\n');
	return input;
}

void launchTest() {
	std::vector<std::any> controlVec;
	std::vector<std::any> testVec;
	createTestVec(controlVec, CONTROLSIZE);
	createTestVec(testVec, TESTSIZE);
	add(testVec, true);
	cout << "ADDING FUNCTION: ";
	compareArrays(testVec, controlVec);
	controlVec.clear();
	testVec.clear();
	createTestVec(testVec, CONTROLSIZE);
	createTestVec(controlVec, TESTSIZE);
	remove(testVec, true);
	cout << "DELETING FUNCTION: ";
	compareArrays(testVec, controlVec);	
}

void createTestVec(std::vector<std::any>& testVec, int size) {
	carnivores tempCarn;
	mammals tempHerb;
	mammals tempOmn;
	int i = 0;
	int j = 0;
	std::string str = std::to_string(i);

		tempCarn.setOrder("Carnivore");
		tempCarn.setName(str);
		tempCarn.setNutrition(str);
		tempCarn.setEnv(str);
		tempCarn.setWeight(i);
		tempCarn.setAttack(str);
		i++;
		str = std::to_string(i);
		tempHerb.setOrder("Herbivore");
		tempHerb.setName(str);
		tempHerb.setNutrition(str);
		tempHerb.setEnv(str);
		tempHerb.setWeight(i);
		i++;
		str = std::to_string(i);
		tempOmn.setOrder("Omnivore");
		tempOmn.setName(str);
		tempOmn.setNutrition(str);
		tempOmn.setEnv(str);
		tempOmn.setWeight(i);

		while(j < size){
			testVec.push_back(tempCarn);
			j++;
			if (j >= size)
				break;
			testVec.push_back(tempHerb);
			j++;
			if (j >= size)
				break;
			testVec.push_back(tempOmn);
			j++;
			if (j >= size)
				break;
		}

}

void compareArrays(std::vector<std::any>& testVec, std::vector<std::any>& controlVec) {
	if (controlVec.size() == testVec.size()) {
		for (auto i = 0; i < std::max(testVec.size(), controlVec.size()); i++) {
			std::string typeN = testVec[i].type().name();
			if (typeN == "class carnivores") {
				carnivores tempTest = std::any_cast<carnivores>(testVec[i]);
				carnivores tempControl = std::any_cast<carnivores>(controlVec[i]);
				if (tempTest.getName() == tempControl.getName() &&
					tempTest.getNutrition() == tempControl.getNutrition() &&
					tempTest.getEnv() == tempControl.getEnv() &&
					tempTest.getWeight() == tempControl.getWeight() &&
					tempTest.getAttack() == tempControl.getAttack()) {
					if (i == controlVec.size() - 1)
						std::cout << "\033[36m" << "GOOD" << "\033[0m" << std::endl;
				}
				else {
					std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
					std::cout << "Input array: " << std::endl;
					printAll(testVec);
					std::cout << "Control array: " << std::endl;
					printAll(controlVec);
					break;
				}
			}
			else {
				mammals tempTest = std::any_cast<mammals> (testVec[i]);
				mammals tempControl = std::any_cast<mammals>(controlVec[i]);
				if (tempTest.getName() == tempControl.getName() &&
					tempTest.getNutrition() == tempControl.getNutrition() &&
					tempTest.getEnv() == tempControl.getEnv() &&
					tempTest.getWeight() == tempControl.getWeight()) {
					if (i == std::max(testVec.size(), controlVec.size()) - 1)
						std::cout << "\033[36m" << "GOOD" << "\033[0m" << std::endl;
				}
				else {
					std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
					std::cout << "Input array: " << std::endl;
					printAll(testVec);
					std::cout << "Control array: " << std::endl;
					printAll(controlVec);
					break;
				}
			}
		}
	}
	else {
	std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
	std::cout << "Input array: " << std::endl;
	printAll(testVec);
	std::cout << "Control array: " << std::endl;
	printAll(controlVec);
	}

}

void add(std::vector<std::any>& srcArr, bool test) {
	//int tempCh = checkInt();
	bool exitFlag;
	mammalOrderChoice choice;
	if (!test) {
		cout << "What mammal needs to be added?" << endl
			<< "1. Carnivore" << endl
			<< "2. Herbivore" << endl
			<< "3. Omnivore" << endl;
		choice = static_cast<mammalOrderChoice>(checkInt());
	}
	else {
		choice = mammalOrderChoice::carnivore;
	}
	do {
		exitFlag = true;
		if (choice == mammalOrderChoice::carnivore) {
			carnivores temp;
			if (!test) {
			temp.setAll();
			}
			else {
				temp.setName("0");
				temp.setNutrition("0");
				temp.setEnv("0");
				temp.setWeight(0);
				temp.setAttack("0");
			}
			temp.setOrder("Carnivore");
			srcArr.push_back(temp);
		}
		else if (choice == mammalOrderChoice::herbivore) {
			mammals temp;
			temp.setAll();
			temp.setOrder("Herbivore");
			srcArr.push_back(temp);
		}
		else if (choice == mammalOrderChoice::omnivore) {
			mammals temp;
			temp.setAll();
			temp.setOrder("Omnivore");
			srcArr.push_back(temp);
		}
		else {
			cout << "ERR. WRONG INPUT" << endl;
			exitFlag = false;
		}
	} while (!exitFlag);
}

void remove(std::vector<std::any>& srcArr, bool test) {
	int inputNum = 0;
	if (test) {
		inputNum = TESTDELETE;
	}
	else
	{
		cout << "Enter the number of a mammal that needs to be deleted: ";
		do {
			inputNum = checkInt();
		} while (inputNum > srcArr.size() || inputNum < 1);
	}
	for (int i = 0; i < srcArr.size(); i++) {
		if (i == inputNum - 1) {
			for (i; i < srcArr.size() - 1; i++) {
				srcArr[i] = srcArr[i + 1];
			}
			srcArr.pop_back();
			break;
		}
	}
}