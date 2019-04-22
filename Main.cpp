#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"
#include "Works.h"
#include "Setting.h"
#include "Credit.h"

//(๑•ૅㅁ•๑)o00(全部の基礎)

//フルスクリーン化
namespace fullscreen {
	constexpr Size BaseSize(720, 720);
	void setupfullsc() {
		Window::SetBaseSize(BaseSize);
		const auto [displayIndex, displayMode] = OptimalScreen::Get(OptimalScreen::Preference::AspectMin, BaseSize);
		Graphics::SetFullScreen(true, displayMode.size, displayIndex, displayMode.refreshRateHz);
		Print << U"Display {} | size {} @ {} Hz"_fmt(displayIndex, displayMode.size, displayMode.refreshRateHz);
	}
}

void Main() {
	fullscreen::setupfullsc;
	Window::Resize((int32)Window::Width, (int32)Window::Height, true);
	Window::SetTitle(U"Comb Viewer 3D" + verstr);
	MyApp SceneMgr;
	//メニュー
	SceneMgr.add<Menu>(U"Menu");
	//本編
	SceneMgr.add<Menu>(U"Works");
	//設定画面
	SceneMgr.add<Menu>(U"Setting");
	//post(文化祭版限定機能)
	SceneMgr.add<Menu>(U"Post");
	//クレジット
	SceneMgr.add<Menu>(U"Credit");

	while (System::Update()) {
		SceneMgr.updateScene();
		SceneMgr.drawScene();
	}
}
