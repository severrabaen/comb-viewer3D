#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

class Setting :public MyApp::Scene {
private:
	Font settingFont;
public:
	void update() const override;
	void draw() const;
}
