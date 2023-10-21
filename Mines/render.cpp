#include "render.h"
#include <graphics.h>
IMAGE nums[9], bomb, flag, red_bomb, undiscovered;
char filename[6] = "$.png";
void init_GUI()
{
	initgraph(WINDOW_W, WINDOW_H);
	for (int i = 0; i <= 8; i++)
	{
		filename[0] = i + '0';
		loadimage(&nums[i], (LPCTSTR)filename);
	}
	loadimage(&bomb, _T("b.png"));
	loadimage(&flag, _T("f.png"));
	loadimage(&red_bomb, _T("r.png"));
	loadimage(&undiscovered, _T("u.png"));
}