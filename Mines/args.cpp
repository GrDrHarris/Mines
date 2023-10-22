#include "args.h"
#include "logger.h"
#include "engine.h"

#include<string>
#include<functional>

static bool deal_debug(std::string s)
{
	if (s != "")
		logger::Log("--debug with additional suffix:\"" + s + "\". Though debug mode is still enabled.");
	engine::enable_debug();
	return true;
}
static bool deal_setw(std::string s)
{
	//TODO
	logger::Log("deal_setw is TBD");
	return false;
}
static bool deal_seth(std::string s)
{
	//TODO
	logger::Log("deal_seth is TBD");
	return false;
}
static bool deal_mine(std::string s)
{
	//TODO
	logger::Log("deal_mine is TBD");
	return false;
}
static bool deal_seed(std::string s)
{
	//TODO
	logger::Log("deal_seed is TBD");
	return false;
}
static bool deal_replay(std::string s)
{
	//TODO
	logger::Log("deal_replay is TBD");
	return false;
}

struct command {
	std::string name;
	std::function<bool(std::string)> handler;
}known_commands[] = {
	{"--debug", deal_debug},
	{"-w=", deal_setw},
	{"-h=", deal_seth},
	{"-m=", deal_mine},
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
		bool suc = false;
		for (int j = 0; j < sizeof(known_commands) / sizeof(command); j++)
		{
			if (begin_with(cmd, known_commands[j].name))
			{
				if (known_commands[j].handler(cmd.substr(known_commands[j].name.length())))
					logger::log("command \"" + cmd + "\" dealed successfully\n", logger::OTHER);
				else
					logger::Log("command \"" + cmd + "\" matched but failed to invoke\n");
				suc = true;
				break;
			}
		}
		if(!suc)
			logger::Log("command \"" + cmd + "\" failed to match\n");
	}
}