#include "XsAsciiRenderEngine.hpp"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); // for fast rendering
	cin.tie(NULL); // for fast rendering
	XsWindow window(75, 25 /* window scale */);
	window.name("yarra");
	window.pos(150);
	window.scale(75, 25);
	window.background('#'); /* background char */
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

	XsTexture tex;
	const char* _tex =
		"###0###"
		"#/-|-\\#"
		"/##|##\\"
		"##/#\\##"
		"##|#|##";
	byte bgcolor = calcolor(XS_WHITE, XS_DARKGREY);
	byte whiteblue = calcolor(XS_WHITE, XS_BLUE);
	byte _colortex[]{
		bgcolor,	bgcolor,	bgcolor,	whiteblue,	bgcolor,	bgcolor,	bgcolor,
		bgcolor,	whiteblue,	whiteblue,	whiteblue,	whiteblue,	whiteblue,	bgcolor,
		whiteblue,	bgcolor,	bgcolor,	whiteblue,	bgcolor,	bgcolor,	whiteblue,
		bgcolor,	bgcolor,	whiteblue,	bgcolor,	whiteblue,	bgcolor,	bgcolor,
		bgcolor,	bgcolor,	whiteblue,	bgcolor,	whiteblue,	bgcolor,	bgcolor,
	};
	tex.load(vex2(7, 5), _tex);
	tex.loadColor(vex2(7, 5), _colortex);
	XsMesh mesh;
	mesh.pos = vex2(30, 7);
	mesh.tex = tex;

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
		'/','|','\\',
		'/','\\',
		'|','|'
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
	XsBody body;
	for (size_t i = 0; i < 13; i++) {
		tpoint.pos = _tpos[i];
		tpoint.lett(_tch[i]);
		tpoint.color(_tcolor[i]);
		body << tpoint;
	};
	body.pos(45, 8);
	while (true) {
		// exit button
		if (XsKeyPressed(XS_KEY_ESC))
			break;
		// << for drawing
		window << point;
		window << rect2;
		window << mesh;
		window << body;
		window.draw(1.f/* fps */);
	};
	return 0;
}
