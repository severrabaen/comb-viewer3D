
#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "Setting.h"

//(๑•ૅㅁ•๑)o00(アプリの諸々の設定。現時点では背景とスライドショーの設定)

Setting::Setting(const InitData& init) : IScene(init) {
	settingFont = Font(10);
}

void Setting::update() {
	//change the background
	SimpleGUI::CheckBoxAt(getData().darkTheme, U"Theme", Vec2(Scene::Width() - 100, 320), 170);
	//dark theme
	if (getData().darkTheme) {
		Scene::SetBackground(HSV(0, 0, 100));
	}
	//light theme
	else {
		Scene::SetBackground(HSV(165, 55, 26));
	}

	//if slideshow or not
	SimpleGUI::CheckBoxAt(getData().slideFlag, U"slideshow", Vec2(Scene::Width() - 100, 420), 170);

}

void Setting::draw() const {
	menuBack.drawFrame();
	settingFont(U"メニューに戻る", menuBack.center());
}