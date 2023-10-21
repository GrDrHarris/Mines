#include "render.h"
#include "args.h"
#include "logger.h"

#include <conio.h>
int main(int argc, char** argv)
{
	logger::init();
	phrase_args(argc, argv);
	init_GUI();
	_getch();
	return 0;
}