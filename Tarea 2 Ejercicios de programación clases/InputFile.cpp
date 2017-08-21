#include <iostream>
#include "InputFile.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

bool InputFile::Read(std::string fileName)
{
	char output[100];
	std::ifstream _contents;
	_contents.open(fileName);
	if (_contents.fail()) {
		return false;
	}
	else
		while (!_contents.eof()) {
			_contents >> output;
			cout << output;
		}
	_contents.close();
	return true;
}

std::string InputFile::GetContents()
{
	std::string c = _contents;
	return std::string(c);
}
