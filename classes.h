#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include"functions.h"

#define SHRT 5
#define SSHRT 3
#define MID 10
#define LNG 15

using std::cout;
using std::cin;
using std::endl;

class mammals{
protected:
	int weight = 0;
	int number = 0;
	std::string name = "MTY";
	std::string nutritionType = "MTY";
	std::string environment = "MTY";
	std::string mammalOrder = "MTY";
public:
	mammals(){ }

	void setNumber(int input);
	void setName(std::string input);
	void setWeight(int input);
	void setNutrition(std::string input);
	void setEnv(std::string input);
	void setOrder(std::string input);
	virtual void setAll();

	std::string getName();
	int getWeight();
	int getNumber();
	std::string getNutrition();
	std::string getEnv();
	std::string getOrder();

	void showName();
	void showWeight();
	void showNutrition();
	void showEnv();
	void showOrder();

	virtual void printAllElement();

	virtual ~mammals(){}

};

class carnivores : public mammals {
private:
	std::string attack = "MTY";
public:
	void setAttack(std::string input);
	std::string getAttack();
	void printAllElement() override;
	void setAll() override;
	//void showOrder();
};

