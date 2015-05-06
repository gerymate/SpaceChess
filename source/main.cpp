#include "app.h"
#include <iostream>
#include <string>

void showUsage(std::string);

int main(int argc, char** argv)
{
	std::vector<std::string> params;
	for (int i = 0; i != argc; ++i)
	{
		params.push_back(std::string{ argv[i] });
	}

	if (argc == 1)
	{
		App app;
		return app.run();
	}
	else if (argc == 2) 
	{
		if (params[1] == "-s")
		{
		    std::cout << "Networked game - we are the server\n";
		} else if (params[1] == "-r") {
		    App app {"playback"};
		    return app.run();
		} else {
			showUsage(params[0]);
		}
	}
	else if (argc == 3) 
	{
		if (params[1] == "-r")
		{
			std::cout << "Opening " << params[2] << " for replay...\n";
		}
		else if (params[1] == "-c")
		{
			std::cout << "Connecting to " << params[2] << " ...\n";
		}
		else
		{
			showUsage(params[0]);
		}
	}
	else
	{
		showUsage(params[0]);
	}

	return 0;
}

void showUsage(std::string executable)
{
	std::cout << "Usage:\n\n SpaceChess [mode] [argument]\n\n";
	std::cout << "Run without parameters for a local game.\n\n";
	std::cout << "Run with '-r FILENAME' to watch a previously saved game.\n\n";
	std::cout << "Run with '-s' to play a networked game accepting a remote connection\n\n";
	std::cout << "Run with '-c IP_ADDRESS' to connect to a remote game.\n\n";
}