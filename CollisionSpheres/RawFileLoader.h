#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <sstream>

class RawFile
{
private:
	std::ifstream stream;
	std::string data;
	const std::string& path;

public:
	RawFile(const std::string& file);

	const std::string& getContent() const { return data; }
};