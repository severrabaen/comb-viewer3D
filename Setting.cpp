#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Setting.h"

Setting::Setting(const InitData& init) : IScene(init) {
	settingFont = Font(10);
	GUI gui(GUIStyle::Default);
	gui.setTitle(U"Setting");
	//テーマ色(デフォルトはダークテーマ)
	gui.add(U"Theme", GUIToggleSwitch::Create(U"DARK", U"LIGHT", false));
}

void Setting::update() {
	//ダークテーマ
	if (gui.toggleSwitch(U"Theme").isLeft()) { Graphics::SetBackground(HSV(0, 0, 100)); }
	//ライトテーマ
	else { Graphics::SetBackground(HSV(165, 55, 26)); }
}

void Setting::draw() {

}
