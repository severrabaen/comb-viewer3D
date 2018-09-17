#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "Works.h"

//フルスクリーン化
namespace fullscreen {
	constexpr Size BaseSize(720, 720);
	void setupfullsc() {
		Window::SetBaseSize(BaseSize);
		const auto[displayIndex, displayMode] = OptimalScreen::Get(OptimalScreen::Preference::AspectMin, BaseSize);
		Graphics::SetFullScreen(true, displayMode.size, displayIndex, displayMode.refreshRateHz);
		Print << U"Display {} | size {} @ {} Hz"_fmt(displayIndex, displayMode.size, displayMode.refreshRateHz);
	}
}

void Main() {
	App::setupfullsc();
	Graphics::SetBackGround(Palette::Black);
	Window::Resize({ windowWidth, windowHeight }, true);
	Window::SetTitle(U"Comb Viewer 3D", verstr);

	MyApp SceneMgr;
	//メニュー
	SceneMgr.add<Menu>(U"Menu");
	//本編
	SceneMgr.add<U"Works">;
	//settings
	SceneMgr.add<U"Setting">;

	while (System::Update()) {
		SceneMgr.updateScene();
		SceneMgr.drawScene();
	}
}
