#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

class Credit :public MyApp::Scene {
private:
	Rect BackToMenuRect,creditRect;
	Texture BackToMenuThumb;
	Font BTMFont,CreditFont, chimpanzeeFont;
	Audio chinpan,selectedSound;

public:
	Credit(const InitData& init);
	void update() override;
	void draw() const override;
};
