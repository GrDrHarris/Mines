#include "args.h"
#include "logger.h"

#include<string>
#include<functional>

static bool deal_debug(std::string s)
{
	//TODO
	return false;
}
static bool deal_setw(std::string s)
{
	//TODO
	return false;
}
static bool deal_seth(std::string s)
{
	//TODO
	return false;
}
static bool deal_seed(std::string s)
{
	//TODO
	return false;
}
static bool deal_replay(std::string s)
{
	//TODO
	return false;
}

struct command {
	std::string name;
	std::function<bool(std::string)> handler;
}known_commands[] = {
	{"--debug", deal_debug},
	{"-w=", deal_setw},
	{"-h=", deal_seth},
	{"--seed=", deal_seed},
	{"--replay=", deal_replay}
};

static bool begin_with(std::string a, std::string b)
{
	//TODO
	return false;
}
void phrase_args(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string cmd = std::string(argv[i]);
		for (int j = 0; j < sizeof(known_commands) / sizeof(command); j++)
		{
			if (begin_with(cmd, known_commands[j].name))
			{
				if (known_commands[j].handler)
					logger::log("command \"" + cmd + "\" dealed successfully\n");
				else
					logger::Log("command \"" + cmd + "\" matched but failed to invoke\n");
				goto deal_success;
			}
		}
		logger::Log("command \"" + cmd + "\" failed to match\n");
		deal_success: 
	}
}