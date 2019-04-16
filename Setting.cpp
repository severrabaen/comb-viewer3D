#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "Setting.h"

Setting::Setting(const InitData& init) : IScene(init) {
	settingFont = Font(10);
	//gui.setTitle(U"Setting");
	//�e�[�}�F(�f�t�H���g�̓_�[�N�e�[�})
	SimpleGUI::RadioButtons(U"DARK", U"LIGHT");
}

void Setting::update() {
	//�_�[�N�e�[�}
	if (gui.toggleSwitch(U"Theme").isLeft()) { Graphics::SetBackground(HSV(0, 0, 100)); }
	//���C�g�e�[�}
	else { Graphics::SetBackground(HSV(165, 55, 26)); }
}

void Setting::draw() const {

}
