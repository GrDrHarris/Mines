#include "render.h"
#include <graphics.h>
#include <vector>
#include "resource.h"
IMAGE nums[9], bomb, flag, red_bomb, undiscovered;
char filename[] = "IDB_PNG_NUM$";
void GUI::init()
{
	initgraph(WINDOW_W, WINDOW_H);
	loadimage(&nums[0],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM0));
	loadimage(&nums[1],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM1));
	loadimage(&nums[2],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM2));
	loadimage(&nums[3],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM3));
	loadimage(&nums[4],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM4));
	loadimage(&nums[5],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM5));
	loadimage(&nums[6],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM6));
	loadimage(&nums[7],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM7));
	loadimage(&nums[8],  _T("PNG"), MAKEINTRESOURCE(IDB_PNG_NUM8));
	loadimage(&bomb,     _T("PNG"), MAKEINTRESOURCE(IDB_PNG_MINE));
	loadimage(&flag,     _T("PNG"), MAKEINTRESOURCE(IDB_PNG_FLAG));
	loadimage(&red_bomb, _T("PNG"), MAKEINTRESOURCE(IDB_PNG_MINE_RED));
	loadimage(&undiscovered, _T("PNG"), MAKEINTRESOURCE(IDB_PNG_COVERED));
	putimage(0, 0, &nums[5]);
}
struct button {
	int x, y, w, h;
	std::string name;
	callback_t callback;
	button(){}
	button(int _x, int _y, int _w, int _h, std::string _name, callback_t _callback)
		:x(_x), y(_y), w(_w), h(_h), name(_name), callback(_callback) {}
};
void GUI::draw_button(const button& b)
{
	if (b.name == "")
		return;
	rectangle(b.x, b.y, b.x + b.w, b.y + b.h);
	LPCTSTR str = (LPCTSTR)b.name.c_str();
	int tw = textwidth(str);
	int th = textheight(str);
	int tx = b.x + (b.w - tw) / 2;
	int ty = b.y + (b.h - th) / 2;
	outtextxy(tx, ty, str);
}
std::vector<button> buttons;
void GUI::add_button(int x, int y, int w, int h, std::string name, callback_t callback)
{
	button b = button(x, y, w, h, name, callback);
	buttons.push_back(b);
	GUI::draw_button(b);
}