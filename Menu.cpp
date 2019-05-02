#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "Works.h"

//(๑•ૅㅁ•๑)o00(メインメニューを作っている)

Menu::Menu(const InitData& init) :IScene(init) {
	const String text = U"Comb-Viewer3D";
	randomRect = drawshape<Rect>(296, 90, 175, 170);
	creditRect = drawshape<Rect>(531, 90, 175, 170);
	settingRect = drawshape<Rect>(61, 300, 175, 170);
	exitRect = drawshape<Rect>(531, 300, 175, 170);
}

void Menu::update() {
	if (exitRect.leftClicked()) { System::Exit(); }
	if (randomRect.leftClicked()) {
		getData().startNum = Random<int>(1,sizeof(works)) % sizeof(works) + 1;
		getData().slideFlag = true;
		changeScene(U"Works");
	}
	if (creditRect.leftClicked()) { changeScene(U"Credit"); }
	if (settingRect.leftClicked()) { changeScene(U"Setting"); }
}

void Menu::draw() const {
	int32 i = 0;
	for (const auto& text : texts) {
		const bool mouseOver = text.regionCenter(260 + i * 50).mouseOver();
		text.drawCenter(260 + i * 50, AlphaF(mouseOver ? 1.0 : 0.0), AlphaF(mouseOver ? 1.0 : 0.9));
		++i;
	}
	randomRect.drawFrame();
	creditRect.drawFrame();
	settingRect.drawFrame();
	exitRect.drawFrame();

	
}