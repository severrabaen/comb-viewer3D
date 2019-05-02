#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

//(๑•ૅㅁ•๑)o00(Works.hを作っている)

//フェード切り替えの時間(10sec.)
const int disappMillisec = 10000;

struct works {
	//Viewed model and its data.
	//Model workModel;
	String titleName, creatorName;
	int32 x, y;
};

/*↓LeadLine
enum class LeadLineTextHA {
	Left,
	Right,
};

enum class LeadLineTextVA {
	Top,
	Middle,
	Bottom,
};

void drawLeadLine(const Vec2& from, const Circular& lead1, const double lead2, const String text, const LeadLineTextHA ha, const LeadLineTextVA va, const Font& WorksFont) {
	const Vec2 p1 = from;
	const Vec2 p2 = p1 + lead1;
	const Vec2 p3 = p2 + Circular(lead2, ha == LeadLineTextHA::Left ? 270_deg : 90_deg);
	const Rect region = WorksFont(text).region();

	Vec2 pText;
	pText.x = ha == LeadLineTextHA::Left ? p3.x : p3.x - region.w;

	switch (valign) {
	case LeadLineTextVA::Top: pText.y = p3.y - region.h; break;
	case LeadLineTextVA::Middle: pText.y = p3.y - region.h / 2; break;
	case LeadLineTextVA::Bottom: pText.y = p3.y; break;
	}

	Line(p1, p2).draw(Palette::White);
	Line(p2, p3).draw(Palette::White);
	WorksFont(text).draw(pText, Palette::White);
}
↑LeadLine*/

class Works :public MyApp::Scene {
private:
	Texture TwitterImg;
	Rect TwitterRect;
	int nowWorkNum, nextWorkNum, prevWorkNum;
	double zoom = 0;
	bool handCursorRight, handCursorLeft, handCursorTwitter;
	String title, authorName;
	//表示しているモデルの切り替え用の矢印
	Triangle goToLeft, goToRight;
	int nowdis, nextdis, prevdis;
	//自動フェード機能用
	Stopwatch stopwatch;
	bool disappFlag = false, cursorhand;
	Font WorksFont;

public:
	Works(const InitData& init);
	void update() override;
	void draw() const override;
};