// (C) Máté Gergely - gerymate@gmail.com
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
	App app {params[1]};
	return app.run();
    }
    else if (argc == 3) 
    {
	App app {params[1], params[2]};
	return app.run();
    }
    else
    {
	App::showUsage(params[0]);
    }

    return 0;
}

