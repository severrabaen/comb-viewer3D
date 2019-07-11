#pragma once
#include <Siv3D.hpp>
#include <HamFrameWork.hpp>
#include "Main.h"

//(๑•ૅㅁ•๑)o00(Credit.hのデータ)

class Credit :public MyApp::Scene {
private:
	Font creditFont;
	String sentence = { U"Program: severrabaen\nArtists: RianDigital" };
	Texture creditImg;
	Rect menuBack;

public:
	Credit(const InitData& init);
	void update();
	void draw() const override;
};
