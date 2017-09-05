#include <iostream>
#include "InputFile.h"
#include <sstream>
#include <fstream>

using namespace std;

bool InputFile::Read(std::string fileName)
{
	if (fileName.empty())
	{
		std::cout << "No filename provided" << std::endl;
		return false;
	}

	std::fstream inputFile(fileName, std::fstream::in);

	if (!inputFile.is_open())
	{
		std::cout << "Could not open file" << fileName << std::endl;
		return false;
	}

	std::stringstream ss;
	ss << inputFile.rdbuf();
	_contents = ss.str();
	return true;
}

std::string InputFile::GetContents()
{
	return _contents;
}