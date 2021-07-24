#include "XsAsciiRenderEngine.hpp"

using namespace std;

int main() {
	XsWindow window(75, 25);
	window.name("yarra");
	window.pos(150);
	window.scale(75, 25);
	window.background('#');
	window.color(XS_WHITE, XS_DARKGREY);

	XsPoint point;
	point.pos = vex2(10, 5);
	point.lett('+');
	point.color(XS_WHITE, XS_RED);

	XsRectangle rect;
	rect.color(XS_WHITE, XS_GREEN);
	rect.scale = vex2(3, 4);
	rect.lett('A');
	rect.pos = vex2(23, 15);

	XsRectangle rect2;
	rect2.color(XS_WHITE, XS_GREEN);
	rect2.scale = vex2(4, 5);
	rect2.lett('B');
	rect2.pos = vex2(15, 10);

	XsPoint tpoint;
	vex2 _tpos[]{
		vex2(0, -2),
		vex2(-2, -1), vex2(-1, -1), vex2(0, -1), vex2(1, -1), vex2(2, -1),
		vex2(-3, 0), vex2(0, 0), vex2(3, 0),
		vex2(-1, 1), vex2(1, 1),
		vex2(-1, 2), vex2(1, 2)
	};
	char _tch[]{
				  '0',
		'/', '-', '|', '-', '\\',
		'/',	  '|',		'\\',
			   '/',	  '\\',
			   '|',	  '|'
	};
	byte whiteblack = calcolor(XS_WHITE, XS_BLACK);
	byte whiteyellow = calcolor(XS_WHITE, XS_YELLOW);
	byte _tcolor[]{
		whiteblack,
		whiteyellow, whiteyellow, whiteyellow, whiteyellow, whiteyellow,
		whiteblack, whiteyellow, whiteblack,
		whiteyellow, whiteyellow,
		whiteblack, whiteblack
	};
	XsBody man;
	for (size_t i = 0; i < 13; i++) {
		tpoint.pos = _tpos[i];
		tpoint.lett(_tch[i]);
		tpoint.color(_tcolor[i]);
		man << tpoint;
	};
	man.pos(45, 8);

	while (true) {
		if (XsKeyPressed(XS_KEY_ESC))
			break;
		window.clear();
		window << point;
		window << rect2;
		if (XsKeyPressed(XS_KEY_A))
			man.pos().x -= 1;
		else if (XsKeyPressed(XS_KEY_D))
			man.pos().x += 1;
		if (XsKeyPressed(XS_KEY_W))
			man.pos().y -= 1;
		else if (XsKeyPressed(XS_KEY_S))
			man.pos().y += 1;
		window << man;
		window.draw(0.1f);
	};
	return 0;
}
