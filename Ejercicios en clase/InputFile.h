#pragma once
#include <string>

class InputFile
{
public:
	bool Read(std::string fileName);
	std::string GetContents();


private:
	std::string _contents;


};
