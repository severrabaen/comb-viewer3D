#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

class Setting :public MyApp::Scene {
private:
	Font settingFont;
public:
	Setting(const InitData& init);
	void update();
	void draw() const;
};