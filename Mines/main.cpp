#include "render.h"
#include "args.h"
#include "logger.h"

#include <conio.h>

void draw_buttons()
{
	const int Y = 30;
	const int dis = 25;
	const int H = 60;
	const int W = 180;
	const int n = 4;
	int x0 = (WINDOW_W - W * n - dis * (n - 1)) / 2;
	callback_t dumbCallback = [](int x, int y, const ExMessage& msg) -> void {};
	GUI::add_button(x0, Y, W, H, "easy", dumbCallback);
	x0 += W + dis;
	GUI::add_button(x0, Y, W, H, "mideum", dumbCallback);
	x0 += W + dis;
	GUI::add_button(x0, Y, W, H, "hard", dumbCallback);
	x0 += W + dis;
	GUI::add_button(x0, Y, W, H, "hell", dumbCallback);
}
int main(int argc, char** argv)
{
	logger::init();
	phrase_args(argc, argv);
	
	GUI::init();
	draw_buttons();
	_getch();
	return 0;
}