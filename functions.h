#pragma once

#include "classes.h"
#include "main.h"
#include<any>

#define CONTROLSIZE 4
#define TESTSIZE 3
#define TESTDELETE 4

enum class mammalOrderChoice{carnivore = 1, herbivore, omnivore};
//inline int globalNum;

std::string makeLineGood();
std::string getGoodLine(std::string input);
void createTestVec(std::vector<std::any>& testVec, int size);
void compareArrays(std::vector<std::any>& testVec, std::vector<std::any>& contolVec);
int checkInt();
void launchTest();
void add(std::vector<std::any>& srcArr, bool test);
void remove(std::vector<std::any>& srcArr, bool test);