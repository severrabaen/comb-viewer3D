#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "Setting.h"

Setting::Setting(const InitData& init) : IScene(init) {
	settingFont = Font(10);
}

void Setting::update() {
	//背景変更
	//ダークテーマ
	if (SimpleGUI::Button(U"Background", Vec2(100, 100), 200, true)) { Graphics::SetBackground(HSV(0, 0, 100)); }
	//ライトテーマ
	else { Graphics::SetBackground(HSV(165, 55, 26)); }
}

void Setting::draw() const {

}