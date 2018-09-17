#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>

//Time which decide when no one controls Comb-Viewer3D for a while.
const int disappMAndRecMillisec = 10000;

struct works {
	//Viewed model and its data.
	Model workModel;
	String titleName, authorName;
}

//↓LeadLine
enum class LeadLineTextHA {
	Left,
	Right,
};

enum class LeadLineTextVA {
	Top,
	Middle,
	Bottom,
};

void drawLeadLine(const Vec2& from, const Circular& lead1, const double lead2, const String text, const LeadLineTextHA ha, const LeadLineVA va, const Font& WorksFont) {
	const Vec2 p1 = from;
	const Vec2 p2 = p + lead1;
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
//↑LeadLine

class Works :public MyApp::Scene {
private:
	Texture howToTexture;
	//To change the model(2 things).
	Triangle goToLeft, goToRight;
	int nowdis, nextdis, prevdis;
	//To disappMAndRec(2 things)
	Stopwatch stopwatch;
	bool disappFlag = false;
public:
}
