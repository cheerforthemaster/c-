#pragma once
#include <vector>
using namespace std;

__declspec(dllexport) void setModelArray(vector<vector<double>> &vec1, vector<double> &vec2, int X, int Y, int Z);
__declspec(dllexport) void setSectionArray(vector<vector<double>> &parray);

__declspec(dllexport) void reshape_func(int w, int h);
__declspec(dllexport) void display_func();
__declspec(dllexport) void mouse_click_func(int button, int state, int x, int y);
__declspec(dllexport) void mouse_move_func(int x, int y);
__declspec(dllexport) void keyboard_func(unsigned char key, int x, int y);
__declspec(dllexport) void specialkey_func(int key, int x, int y);
__declspec(dllexport) void initPaint();