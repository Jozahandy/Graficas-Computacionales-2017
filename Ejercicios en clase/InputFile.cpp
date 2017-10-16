#include <iostream>
#include "InputFile.h"
#include <sstream>
#include <fstream>

#include "InputFile.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool InputFile::Read(std::string filename)
{
	char output[100];
	std::ifstream _archivo;
	std::string a, b;
	_archivo.open(filename);
	if (_archivo.fail()) {
		return false;
	}
	else
	{
		while (std::getline(_archivo, a)) {
			b += a;
			b += "\n";
		}
		_archivo.close();
		_contents = b;
	}

	return true;
}

std::string InputFile::GetContents()
{
	return _contents;
}