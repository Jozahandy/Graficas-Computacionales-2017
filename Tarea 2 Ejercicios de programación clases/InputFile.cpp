#include <iostream>
#include "InputFile.h"
#include <sstream>
#include <fstream>

using namespace std;

bool InputFile::Read(std::string fileName)
{
	char output[100];
	std::ifstream _archivo;
	std::string a, b;
	_archivo.open(fileName);
	if (_archivo.fail()) {
		return false;
	}
	else{
		while (std::getline(_archivo, a)) {
			b += a;
			b += "\n";
		}

			_archivo >> output;
			_contents = b;
		}

	return true;
}

std::string InputFile::GetContents()
{
	return _contents;
}
