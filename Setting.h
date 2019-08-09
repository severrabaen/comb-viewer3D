#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

//(๑•ૅㅁ•๑)o00(設定のデータ)

class Setting :public MyApp::Scene {
private:
	Font settingFont;
	Rect menuBack;

public:
	Setting(const InitData& init);
	void update()override;
	void draw() const override;
};