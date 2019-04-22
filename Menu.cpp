#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"

//(๑•ૅㅁ•๑)o00(メインメニューを作っている)

Menu::Menu(const InitData& init) :IScene(init) {
	const String text = U"Comb-Viewer3D";
}

void Menu::update() {
	for (auto i : step(5)) {
		if (texts[i].leftClicked()) {
			if (texts[i] == "EXIT") { System::Exit(); }
			if (texts[i] == "RANDOM") { getData().startNum = srand() % works.size() + 1; }
			if (texts[i] == "") {}
		}
	}
}

void Menu::draw() const {
	int32 i = 0;
	for (const auto& text : texts) {
		const bool mouseOver = text.regionCenter(260 + i * 50).mouseOver;
		text.drawCenter(260 + i * 50, AlphaF(mouseOver ? 1.0 : 0.0), AlphaF(mouseOver ? 1.0 : 0.9));
		++i;
	}

	for (int i = 0; i < 5; ++i) {
		drawshape<Rect>.draw();
		texts[i].drawAt();
	}
}
