#pragma once
#ifndef RENDER_H
#define RENDER_H

#include<functional>
#include <string>
#define WINDOW_W 1200
#define WINDOW_H 675
struct ExMessage;
struct button;
typedef std::function<void(int, int, const ExMessage&)> callback_t;
namespace GUI {
	void init();
	void add_button(int x, int y, int w, int h, std::string name, callback_t callback);
	void draw_button(const button& b);
}
#endif