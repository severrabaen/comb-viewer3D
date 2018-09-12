#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "3Dviewer.h"

void Main() {
	//Setting of window
	Window::Resize({ windowWidth, windowHeight }, true);
	Window::SetTitle(U"Run After the Chicken!!(RAC)v.1.0.0.");
	Graphics::SetBackground(Palette::Burlywood);

	MyApp SceneMgr;
	//メニュー
	SceneMgr.add<Menu>(U"Menu");
  //本編
	SceneMgr.add<U"3Dviewer">;

	while (System::Update()) {
		SceneMgr.updateScene();
		SceneMgr.drawScene();
	}
}
