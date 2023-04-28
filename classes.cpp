#include "classes.h"

void mammals::setNumber(int input) {
	number = input;
}

void mammals::setName(std::string input) {
	name = input;
}
void mammals::setWeight(int input) {
	weight = input;
}
void mammals::setNutrition(std::string input) {
	nutritionType = input;
}
void mammals::setEnv(std::string input) {
	environment = input;
}
void mammals::setOrder(std::string input) {
	mammalOrder = input;
}
void carnivores::setAttack(std::string input) {
	attack = input;
}

std::string mammals::getName() {
	return name;
}
int mammals::getNumber() {
	return number;
}

int mammals::getWeight() {
	return weight;
}

std::string mammals::getNutrition() {
	return nutritionType;
}

std::string mammals::getEnv() {
	return environment;
}

std::string mammals::getOrder() {
	return mammalOrder;
}

void mammals::showName() {
	cout << name;
}

void mammals::showWeight() {
	cout << weight;
}
void mammals::showNutrition() {
	cout << getGoodLine(nutritionType);
}
void mammals::showEnv() {
	cout << getGoodLine(environment);
}
void mammals::showOrder() {
	cout << getGoodLine(mammalOrder);
}

void mammals::printAllElement() {
	cout
		<< std::left
		<< std::setw(SSHRT) << number
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(mammalOrder)
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << name
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(nutritionType)
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << weight
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(environment)
		<< std::setw(LNG + SHRT) << "||" << "||"
		<< std::right << endl;
}
void carnivores::printAllElement() {
	cout
		<< std::left
		<< std::setw(SSHRT) << number
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(mammalOrder)
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << name
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(nutritionType)
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << weight
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(environment)
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(attack)
		<< std::setw(SHRT) << "||"
		<< std::right << endl;
}

void carnivores::setAll() {
	std::string tempStr;
	int tempInt;
	carnivores temp;
	cout << "=============================" << endl;
	cout << "Enter name: ";			tempStr = makeLineGood();							name = tempStr;
	cout << "Enter nutrition: ";	tempStr = makeLineGood();							nutritionType = tempStr;
	cout << "Enter weight: ";		do { tempInt = checkInt(); } while (tempInt < 0);	weight = tempInt;
	cout << "Enter environment: ";	tempStr = makeLineGood();							environment = tempStr;
	cout << "Enter an attack: ";	tempStr = makeLineGood();							attack = tempStr;
}
void mammals::setAll(){
	std::string tempStr;
	int tempInt;
	carnivores temp;
	cout << "=============================" << endl;
	cout << "Enter name: ";	tempStr = makeLineGood();									name = tempStr;
	cout << "Enter nutrition: ";	tempStr = makeLineGood();							nutritionType = tempStr;
	cout << "Enter weight: ";		do { tempInt = checkInt(); } while (tempInt < 0);	weight = tempInt;
	cout << "Enter environment: ";	tempStr = makeLineGood();							environment = tempStr;
}

std::string carnivores::getAttack() {
	return attack;
}
