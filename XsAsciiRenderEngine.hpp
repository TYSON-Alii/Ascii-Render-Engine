#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
const enum XsKey {
	XS_KEY_A = 65,
	XS_KEY_B = 66,
	XS_KEY_C = 67,
	XS_KEY_D = 68,
	XS_KEY_E = 69,
	XS_KEY_F = 70,
	XS_KEY_G = 71,
	XS_KEY_H = 72,
	XS_KEY_I = 73,
	XS_KEY_J = 74,
	XS_KEY_K = 75,
	XS_KEY_L = 76,
	XS_KEY_M = 77,
	XS_KEY_N = 78,
	XS_KEY_O = 79,
	XS_KEY_P = 80,
	XS_KEY_Q = 81,
	XS_KEY_R = 82,
	XS_KEY_S = 83,
	XS_KEY_T = 84,
	XS_KEY_U = 85,
	XS_KEY_V = 86,
	XS_KEY_W = 87,
	XS_KEY_X = 88,
	XS_KEY_Y = 89,
	XS_KEY_Z = 90,
	XS_KEY_0 = 48,
	XS_KEY_1 = 49,
	XS_KEY_2 = 50,
	XS_KEY_3 = 51,
	XS_KEY_4 = 52,
	XS_KEY_5 = 53,
	XS_KEY_6 = 54,
	XS_KEY_7 = 55,
	XS_KEY_8 = 56,
	XS_KEY_9 = 57,
	XS_KEY_SPACE = 32,
	XS_KEY_ESC = 27,
	XS_KEY_DELETE = 8,
	XS_KEY_TAB = 9,
	XS_KEY_UP = 38,
	XS_KEY_DOWN = 40,
	XS_KEY_RIGHT = 39,
	XS_KEY_LEFT = 37,
	XS_KEY_SHIFT = 14,
	XS_KEY_ENTER = 13,
	XS_MOUSE_LEFT = 1,
	XS_MOUSE_RIGHT = 2,
	XS_MOUSE_MIDDLE = 16
};
const enum XsColor {
	XS_BLACK = 0,
	XS_DARKBLUE = 1,
	XS_DARKGREEN = 2,
	XS_DARKCYAN = 3,
	XS_DARKRED = 4,
	XS_DARKMAGENTA = 5,
	XS_DARKYELLOW = 6,
	XS_GREY = 7,
	XS_DARKGREY = 8,
	XS_BLUE = 9,
	XS_GREEN = 10,
	XS_CYAN = 11,
	XS_RED = 12,
	XS_PURPLE = 13,
	XS_YELLOW = 14,
	XS_WHITE = 15
};
bool XsKeyPressed(byte __KEY_CODE) { return (GetKeyState(__KEY_CODE) & 0x800); };
struct vex2 {
	int x = 0, y = 0;
	vex2() {};
	vex2(float v1, float v2) { x = v1; y = v2; };
	vex2(float v1) { x = v1; y = v1; };
	vex2 operator+(float v) { return vex2(x + v, y + v); };
	vex2 operator+(vex2 v) { return vex2(x + v.x, y + v.y); };
	vex2 operator-(float v) { return vex2(x - v, y - v); };
	vex2 operator-(vex2 v) { return vex2(x - v.x, y - v.y); };
	vex2 operator*(float v) { return vex2(x * v, y * v); };
	vex2 operator*(vex2 v) { return vex2(x * v.x, y * v.y); };
	vex2 operator/(float v) { return vex2(x / v, y / v); };
	vex2 operator/(vex2 v) { return vex2(x / v.x, y / v.y); };
	void operator+=(float v) { x += v; y += v; };
	void operator+=(vex2 v) { x += v.x; y += v.y; };
	void operator-=(float v) { x -= v; y -= v; };
	void operator-=(vex2 v) { x -= v.x; y -= v.y; };
	void operator*=(float v) { x *= v; y *= v; };
	void operator*=(vex2 v) { x *= v.x; y *= v.y; };
	void operator/=(float v) { x /= v; y /= v; };
	void operator/=(vex2 v) { x /= v.x; y /= v.y; };
};
void swap(vex2& v1, vex2& v2) {
	const vex2 tv = v1;
	v1 = v2;
	v2 = tv;
};
void swap(float& v1, float& v2) {
	const float tv = v1;
	v1 = v2;
	v2 = tv;
};
byte calcolor(byte bg, byte fg) { return bg * 16 + fg; };

class XsChrono {
private:
	std::chrono::time_point<std::chrono::system_clock> _qwe = std::chrono::system_clock::now();
	std::chrono::time_point<std::chrono::system_clock> ___start = std::chrono::system_clock::now(), ___end = std::chrono::system_clock::now();
public:
	const std::chrono::time_point<std::chrono::system_clock> getStartTime() { return _qwe; };
	float timeAfterCreation() { return (float)std::chrono::duration_cast<std::chrono::milliseconds>(_qwe - std::chrono::system_clock::now()).count() / 1000.f; };
	void restart() {
		___start = std::chrono::system_clock::now();
	};
	void reset() {
		_qwe = std::chrono::system_clock::now();
		___start = std::chrono::system_clock::now();
	};
	bool froze = false;
	int getSeconds() {
		if (!froze)
			___end = std::chrono::system_clock::now();
		return (int)std::chrono::duration_cast<std::chrono::seconds>(___end - ___start).count();
	};
	float getMilliSeconds() {
		if (!froze)
			___end = std::chrono::system_clock::now();
		return (float)std::chrono::duration_cast<std::chrono::milliseconds>(___end - ___start).count() / 1000.f;
	};
	double getMicroSeconds() {
		if (!froze)
			___end = std::chrono::system_clock::now();
		return (double)std::chrono::duration_cast<std::chrono::microseconds>(___end - ___start).count() / 1000000.0;
	};
	long double getNanoSeconds() {
		if (!froze)
			___end = std::chrono::system_clock::now();
		return (long double)std::chrono::duration_cast<std::chrono::nanoseconds>(___end - ___start).count() / 1000000000.0;
	};
};
bool XsLimiter(XsChrono& __vev, float __vev2) {
	if (__vev2 < __vev.getMilliSeconds()) {
		__vev.restart();
		return true;
	}
	return false;
};

class texel {
private:
public:
	texel() {};
	texel(char v1, byte v2) { lett = v1; color = v2; };
	char lett = ' ';
	byte color = 0x0f;
};

class XsPoint {
private:
	texel _t;
public:
	vex2 pos = 0;
	void color(byte bg, byte fg) { _t.color = bg * 16 + fg; };
	void color(byte v) { _t.color = v; };
	byte& color() { return _t.color; };
	void lett(char v) { _t.lett = v; };
	char& lett() { return _t.lett; };
};
class XsRectangle {
private:
	texel _t;
public:
	vex2 pos = 0;
	vex2 scale = 1;
	void color(byte bg, byte fg) { _t.color = bg * 16 + fg; };
	void color(byte v) { _t.color = v; };
	byte& color() { return _t.color; };
	void lett(char v) { _t.lett = v; };
	char& lett() { return _t.lett; };
};
class XsTexture {
private:
	std::vector<std::vector<texel>> _ct;
	vex2 _scl = 1;
public:
	XsTexture(vex2 scale) {
		_ct.resize(scale.y);
		for (size_t i = 0; i < _ct.size(); i++)
			_ct[i].resize(scale.x);
	};
	XsTexture() { };
	XsTexture(float scalex, float scaley) {
		_ct.resize(scaley);
		for (size_t i = 0; i < _ct.size(); i++)
			_ct[i].resize(scalex);
	};
	void load(vex2 scl, const char* v) {
		_scl = scl;
		_ct.resize(scl.y);
		for (size_t i = 0; i < scl.y; i++)
			_ct[i].resize(scl.x);
		for (size_t j = 0; j < scl.y; j++)
			for (size_t i = 0; i < scl.x; i++)
				_ct[j][i].lett = v[j * scl.x + i];
	};
	void loadColor(vex2 scl, byte v[]) {
		_scl = scl;
		_ct.resize(scl.y);
		for (size_t i = 0; i < scl.y; i++)
			_ct[i].resize(scl.x);
		for (size_t j = 0; j < scl.y; j++)
			for (size_t i = 0; i < scl.x; i++)
				_ct[j][i].color = v[j * scl.x + i];
	};
	vex2 scale() { return _scl; };
	void load(vex2 scl, char v[]);
	void load(vex2 scl, std::string v);
	void load(vex2 scl, std::vector<char> v);
	void set(char v);
	void set(vex2 pos, char v);
	std::vector<std::vector<texel>>& operator()() { return _ct; };
};
class XsMesh {
private:
public:
	vex2 pos = 0;
	XsTexture tex;
	void color(byte bg, byte fg) {
		for (int i = 1; i < tex.scale().x; i++)
			for (int j = 0; j < tex.scale().y; j++)
				tex()[j][i].color = bg * 16 + fg;
	};
	void color(byte v) {
		for (int i = 1; i < tex.scale().x; i++)
			for (int j = 0; j < tex.scale().y; j++)
				tex()[j][i].color = v;
	};
};

class XsBody {
private:
	std::vector<XsPoint> _vs;
	vex2 _p = 0;
public:
	void add(XsPoint v) { _vs.push_back(v); };
	void operator<<(XsPoint v) { _vs.push_back(v); };
	void pos(vex2 v) { _p = v; };
	void pos(int v1, int v2) { _p.x = v1; _p.y = v2; };
	vex2& pos() { return _p; };
	std::vector<XsPoint>& data() { return _vs; };
};

class XsWindow {
private:
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	bool _r = false;
	std::string _name;
	vex2 _scale;
	vex2 _pos;
	vex2 _cs = vex2(GetConsoleFontSize(hand, NULL).X, GetConsoleFontSize(hand, NULL).Y);
	XsChrono _clk;
	byte _color = 0xf0;
	char _background = ' ';
public:
	XsWindow(float v1, float v2) {
		renderList.resize(v2);
		for (size_t i = 0; i < renderList.size(); i++) {
			renderList[i].resize(v1, texel(_background, _color));
			std::fill(renderList[i].begin(), renderList[i].end(), texel(_background, _color));
		};
	};
	XsWindow(vex2 v) {
		renderList.resize(v.y);
		for (size_t i = 0; i < renderList.size(); i++) {
			renderList[i].resize(v.x, texel(_background, _color));
			std::fill(renderList[i].begin(), renderList[i].end(), texel(_background, _color));
		};
	};
	std::vector<std::vector<texel>> renderList;
	void name(std::string v) { _name = v; _r = true; };
	void scale(vex2 v) { _scale = v; _r = true; };
	void pos(vex2 v) { _pos = v;  _r = true; };
	void scale(float v1, float v2) { _scale = vex2(v1, v2); _r = true; };
	void pos(float v1, float v2) { _pos = vex2(v1, v2);  _r = true; };
	std::string name() { return _name; };
	vex2 scale() { return _scale; };
	vex2 pos() { return _pos; };
	void operator<<(XsPoint v) {
		if (v.pos.x - 1>= 0 && v.pos.y - 1 >= 0 && v.pos.x - 1 < _scale.x && v.pos.y - 1 < _scale.y)
			renderList[v.pos.y - 1][v.pos.x - 1] = texel(v.lett(), v.color());
	};
	void operator<<(XsRectangle v) {
		for (int i = 0; i < v.scale.x - 1; i++)
			for (int j = 0; j < v.scale.y - 1; j++)
				if (v.pos.x + j >= 0 && v.pos.y + i >= 0 && v.pos.x + j < _scale.x && v.pos.y + i < _scale.y)
					renderList[v.pos.y + j][v.pos.x + i] = texel(v.lett(), v.color());
	};
	void operator<<(XsMesh v) {
		for (int i = 0; i < v.tex.scale().x; i++)
			for (int j = 0; j < v.tex.scale().y; j++)
				if (v.pos.x + j >= 0 && v.pos.y + i >= 0 && v.pos.x + j < _scale.x && v.pos.y + i < _scale.y)
					renderList[v.pos.y + j][v.pos.x + i] = texel(v.tex()[j][i].lett, v.tex()[j][i].color);
	};
	void operator<<(XsBody v) {
		for (auto _v : v.data()) {
			_v.pos += v.pos();
			*this << _v;
		};
	};
	void color(byte bg, byte fg) { _color = bg * 16 + fg; };
	byte color() { return _color; };
	void background(char v) { _background = v; };
	char background() { return _background; };
	void draw(float fps) {
		if (_r) {
			const std::wstring _ws = std::wstring(_name.begin(), _name.end());
			SetWindowText(GetConsoleWindow(), _ws.c_str());
			renderList.resize(_scale.y);
			for (volatile size_t i = 0; i < renderList.size(); i++) {
				renderList[i].resize(_scale.x);
				std::fill(renderList[i].begin(), renderList[i].end(), texel(_background, _color));
			};
		};
		if (XsLimiter(_clk, fps)) {
			system("cls");
			SetWindowPos(GetConsoleWindow(), 0, _pos.x, _pos.y, (_scale.x) * _cs.x + (_cs.x * 5), (_scale.y) * _cs.y + (_cs.x * 5), SWP_SHOWWINDOW);
			SetConsoleTextAttribute(hand, renderList[0][0].color);
			for (volatile size_t j = 0; j < renderList.size(); j++) {
				for (volatile size_t i = 0; i < renderList[j].size(); i++) {
					if (i > 0 && renderList[j][i].color != renderList[j][i - 1].color)
						SetConsoleTextAttribute(hand, renderList[j][i].color);
					putchar(renderList[j][i].lett);
				};
				if (j != renderList.size() - 1)
					putchar('\n');
			};
		};
		_r = false;
	};
	void draw() {
		if (_r) {
			const std::wstring _ws = std::wstring(_name.begin(), _name.end());
			SetWindowText(GetConsoleWindow(), _ws.c_str());
			renderList.resize(_scale.y);
			for (volatile size_t i = 0; i < renderList.size(); i++) {
				renderList[i].resize(_scale.x);
				std::fill(renderList[i].begin(), renderList[i].end(), texel(_background, _color));
			};
		};
		system("cls");
		SetWindowPos(GetConsoleWindow(), 0, _pos.x, _pos.y, (_scale.x) * _cs.x + (_cs.x * 5), (_scale.y) * _cs.y + (_cs.x * 5), SWP_SHOWWINDOW);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), renderList[0][0].color);
		for (volatile size_t j = 0; j < renderList.size(); j++) {
			for (volatile size_t i = 0; i < renderList[j].size(); i++) {
				if (i > 0 && renderList[j][i].color != renderList[j][i - 1].color)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), renderList[j][i].color);
				putchar(renderList[j][i].lett);
			};
			if (j != renderList.size() - 1)
				putchar('\n');
		};
		_r = false;
	};
	void clear() {
		for (volatile size_t i = 0; i < renderList.size(); i++) {
			renderList[i].resize(_scale.x);
			std::fill(renderList[i].begin(), renderList[i].end(), texel(_background, _color));
		};
	}
};
