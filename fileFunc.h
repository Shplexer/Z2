#pragma once

#include "classes.h"
#include <any>
#include <fstream>
#include <filesystem>

enum class fileNameChoice { change = 1, exit };
//enum class fileNameTakenChoice { change = 1, keep };
enum class errChoice { change = 1, keep };
std::tuple <bool, std::string> openFile();
std::string fileNameCheck(std::string inputName);
void setList(std::vector<std::any>& srcArr, std::string fileName);
void saveToFile(std::vector<std::any>& srcArr, std::string fileName);
std::string saveFileCheck(std::string fileName);