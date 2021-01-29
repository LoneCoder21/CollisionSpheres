#include "RawFileLoader.h"

RawFile::RawFile(const std::string& path) : stream(path), path(path)
{
	std::string line;

	if (stream.is_open())
	{
		while (std::getline(stream, line))
		{
			data.append(line);
			data.push_back('\n');
		}
	}
	else
		std::cout << "bad stream\n";
}