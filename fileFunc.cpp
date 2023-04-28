#include "fileFunc.h"


std::tuple <bool, std::string> openFile() {
	std::ifstream fileIn;
	bool exitFlag = false;
	bool returnExit = false;
	fileNameChoice choice;
	std::error_code ec{};
	cout << "Enter the name of a source file: ";
	std::string fileName = makeLineGood();
	do {
		exitFlag = false;
		fileName = fileNameCheck(fileName);
		fileIn.open(fileName);
		if (!std::filesystem::is_regular_file(fileName, ec) || !fileIn.is_open()) {
			cout << endl << "The name of the file you have entered does not exist." << endl
				<< "1.Change the name of the file" << endl
				<< "2.Exit" << endl;
			choice = static_cast<fileNameChoice>(checkInt());
			switch (choice)
			{
			case fileNameChoice::change:
				cout << "Enter the name of a source file: ";
				fileName = fileNameCheck(makeLineGood());
				break;
			case fileNameChoice::exit:
				cout << "Exiting..." << endl;
				returnExit = false;
				exitFlag = true;
				break;
			default:
				cout << "ERR. Wrong input, try again" << endl;
				break;
			}
		}
		else{
			cout << "Your file is open!" << endl;
			//cout << fileName;
			exitFlag = true;
			returnExit = true;
		}
	} while (!exitFlag);
	fileIn.close();
	return std::tuple(returnExit, fileName);
}

std::string fileNameCheck(std::string inputName) {
	std::string temp;
	const std::string errName = "<>:\"/\\|?*";
	const std::vector<std::string> errName2{ "CON", "PRN", "AUX", "NUL",
  "COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9",
  "LPT1", "LPT2", "LPT3", "LPT4", "LPT5", "LPT6", "LPT7", "LPT8", "LPT9" };
	bool exitFlag = false;
	do {
		exitFlag = true;
		for (int i = 0; i < inputName.size(); i++) {
			for (int j = 0, k = 0; j < std::max(errName.size(), errName2.size()); j++, k++) {
				//cout << inputName[i] << " == " << errName[k] << " | " << inputName << " == " << errName2[j] << endl;
				if (inputName[i] == errName[k] || inputName == errName2[j]) {
					cout << "ERR. File name contains illegal characters. Try again." << endl;
					inputName = makeLineGood();
					exitFlag = false;
					break;
				}
				if (k >= errName.size() - 1)
					k = 0;
			}
			if (!exitFlag)
				break;
		}
	} while (!exitFlag);
	for (auto i = inputName.size() - 4; i < inputName.size(); i++) {
		temp = temp + inputName[i];
	}
	if (temp != ".txt") {
		inputName = inputName + ".txt";
	}

	return inputName;
}

void setList(std::vector<std::any>&srcArr, std::string fileName) {
	std::ifstream setFile;
	setFile.open(fileName);
	int i = 0;
	while(true){
		std::string tempOrd;
		std::string tempName;
		std::string tempNutr;
		std::string tempEnv;
		int num = 0;
		std::string tempAtt;
		setFile >> tempOrd >> std::ws;
		setFile >> tempName >> std::ws;
		setFile >> tempNutr >> std::ws;
		setFile >> num >> std::ws;

		//cout << "ord" << tempOrd;
		//cout << endl;
		//cout << "name" << tempName;
		//cout << endl;
		//cout << "nut" << tempNutr;
		//cout << endl;
		//cout << "env" << tempEnv;
		//cout << endl;
		//cout << "num" << num;
		//cout << endl;

		if (num < 0) {
			bool exitFlag = true;
			cout << endl << "ERR. Wrong input data for subject " << tempName << endl;
			cout << "Would you like to change the weight?" << endl;
			cout << "1. Yes" << endl << "2. No (Will put 0 as the weight value)" << endl;
			do
			{
				errChoice choice = static_cast<errChoice>(checkInt());
				switch (choice)
				{
				case errChoice::change:
					do {
						cout << "Enter valid weight: ";
						num = checkInt();
					} while (num < 0);
					break;
				case errChoice::keep:
					num = 0;
					break;
				default:
					cout << "ERR. Wrong input" << endl;
					exitFlag = false;
					break;
				}
			} while (!exitFlag);
		}  

		if (setFile.fail()) {
			bool exitFlag = true;
			cout << endl << "ERR. Wrong input data for subject " << tempName << endl;
			cout << "Would you like to change the weight?" << endl;
			cout << "1. Yes" << endl << "2. No (Will put 0 as the weight value)" << endl;
			do
			{
				errChoice choice = static_cast<errChoice>(checkInt());
				switch (choice)
				{
				case errChoice::change:
					do {
						cout << "Enter valid weight: ";
						num = checkInt();
					} while (num < 0);
					break;
				case errChoice::keep:
					num = 0;
					break;
				default:
					cout << "ERR. Wrong input" << endl;
					exitFlag = false;
					break;
				}
			setFile.ignore(INT_MAX, ' ');
			setFile.clear();
			} while (!exitFlag && !setFile.fail());
			setFile.ignore(INT_MAX, ' ');
		}
		setFile >> tempEnv >> std::ws;

		if (tempOrd != "Omnivore" && tempOrd != "Herbivore" && tempOrd != "omnivore" && tempOrd != "herbivore" && tempOrd != "Carnivore" && tempOrd != "carnivore") {
			bool exitFlag = true;
			cout << endl << "ERR. Wrong input data for subject " << tempName << endl;
			cout << "What mammal needs to be added?" << endl
				<< "1. Carnivore" << endl
				<< "2. Herbivore" << endl
				<< "3. Omnivore" << endl;
			do {
				mammalOrderChoice choice = static_cast<mammalOrderChoice>(checkInt());
				switch (choice)
				{
				case mammalOrderChoice::carnivore:
					tempOrd = "Carnivore";
					exitFlag = true;
					break;
				case mammalOrderChoice::herbivore:
					tempOrd = "Herbivore";
					exitFlag = true;
					break;
				case mammalOrderChoice::omnivore:
					tempOrd = "Omnivore";
					exitFlag = true;
					break;
				default:
					exitFlag = false;
					break;
				}
			} while (!exitFlag);
		}

		if (tempOrd == "Carnivore" || tempOrd == "carnivore") {
			carnivores tempVec;
			setFile >> tempAtt;
			tempVec.setOrder(tempOrd);
			tempVec.setName(tempName);
			tempVec.setNutrition(tempNutr);
			tempVec.setEnv(tempEnv);
			tempVec.setWeight(num);
			tempVec.setAttack(tempAtt);
			//std::getline(setFile, str, '\n');
			//str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
			tempVec.setNumber(i + 1);
			srcArr.push_back(tempVec);
			//cout << endl << "===st==" << endl;
			//cout << "ord" << tempOrd;
			//cout << endl;
			//cout << "name" << tempName;
			//cout << endl;
			//cout << "nut" << tempNutr;
			//cout << endl;
			//cout << "env" << tempEnv;
			//cout << endl;
			//cout << "num" << num;
			//cout << endl;
			//cout << "att" << tempAtt;
			//cout << endl << "====end====" << endl;
		}
		else{
			mammals tempVec;
			tempVec.setOrder(tempOrd);
			tempVec.setName(tempName);
			tempVec.setNutrition(tempNutr);
			tempVec.setEnv(tempEnv);
			tempVec.setWeight(num);
			//std::getline(setFile, str, '\n');
			//str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
			tempVec.setNumber(i + 1);
			srcArr.push_back(tempVec);

			//cout << endl << "====st====" << endl;
			//cout << "ord" << tempOrd;
			//cout << endl;
			//cout << "name" << tempName;
			//cout << endl;
			//cout << "nut" << tempNutr;
			//cout << endl;
			//cout << "env" << tempEnv;
			//cout << endl;
			//cout << "num" << num;
			//cout << endl << "====end====" << endl;
		}
		i++;
		if (setFile.eof())	
			break;
	}
	setFile.close();
}

std::string saveFileCheck(std::string saveFileName) {
	std::ifstream checkStream;
	bool exitFlag;
	bool exitAllFlag;
	do {
		exitAllFlag = false;
		checkStream.open(saveFileName);
		std::error_code ec{};
		if (!checkStream.is_open()) {
			cout << "No opened file found. Please enter a path to the file you wish to save your project to: ";
			saveFileName = fileNameCheck(makeLineGood());
			//if (!std::filesystem::is_regular_file(saveFileName, ec)) {
			//	cout << "Invalid data." << endl;
			//	continue;
			//}
		}
		else {
			cout << "The name of an open file: " << saveFileName << endl <<
				"Whould you like to make a new one or save into this one?" << endl <<
				"1. Save to another file" << endl <<
				"2. Save here" << endl;
			do {
				exitFlag = true;
				errChoice choice = static_cast<errChoice>(checkInt());
				switch (choice)
				{
				case errChoice::change:
					cout << "Enter a path to the file: ";
					//saveFileName = makeLineGood();
					saveFileName = fileNameCheck(makeLineGood());
					break;
				case errChoice::keep:
					exitAllFlag = true;
					break;
				default:
					exitFlag = false;
					break;
				}
			} while (!exitFlag);
		}
		checkStream.close();
		checkStream.open(saveFileName);
		if (!checkStream.is_open() || exitAllFlag)
			break;
		checkStream.close();
	} while (true);
	return saveFileName;
}

void saveToFile(std::vector<std::any>& srcArr, std::string saveFileName) {
	std::ofstream save;
	save.open(saveFileName, std::ios::out);
	for (int i = 0; i < srcArr.size(); i++) {
		std::string typeN = srcArr[i].type().name();
		if (typeN == "class carnivores") {
			carnivores tempVec = std::any_cast<carnivores>(srcArr[i]);
			save << tempVec.getOrder()	<< " " <<
				tempVec.getName()		<< " " <<
				tempVec.getNutrition()	<< " " <<
				tempVec.getWeight()		<< " " <<
				tempVec.getEnv()		<< " " <<
				tempVec.getAttack();	
		}
		else {
			mammals tempVec = std::any_cast<mammals>(srcArr[i]);
			save << tempVec.getOrder()	<< " " <<
				tempVec.getName()		<< " " <<
				tempVec.getNutrition()	<< " " <<
				tempVec.getWeight()		<< " " <<
				tempVec.getEnv();
		}
		cout << i << " " << srcArr.size() << endl;
		if(i != srcArr.size() - 1)
			save << endl;
	}
	save.close();
}