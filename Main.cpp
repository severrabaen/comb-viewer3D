#include <Siv3D.hpp>
#include <HamFramework.hpp>
#define SIV3D_WINDOWS_HIGH_DPI
#include "Main.h"
#include "Menu.h"
#include "Works.h"
#include "Setting.h"
#include "Credit.h"

//(๑•ૅㅁ•๑)o00(フルスクリーン、SceneMgr)

//フルスクリーン化
/*namespace fullscreen {
	constexpr Size BaseSize(720, 720);
	void setupfullsc() {
		Window::SetBaseSize(BaseSize);
		const auto [displayIndex, displayMode] = OptimalScreen::Get(OptimalScreen::Preference::AspectMin, BaseSize);
		Graphics::SetFullScreen(true, displayMode.size, displayIndex, displayMode.refreshRateHz);
		Print << U"Display {} | size {} @ {} Hz"_fmt(displayIndex, displayMode.size, displayMode.refreshRateHz);
	}
}*/

//using namespace fullscreen;

void Main() {
	//setupfullsc();
	Window::SetTitle(U"Comb Viewer 3D" + verstr);
	MyApp SceneMgr;

	//メニュー
	SceneMgr.add<Menu>(U"Menu");
	//本編
	SceneMgr.add<Works>(U"Works");
	//設定画面
	SceneMgr.add<Setting>(U"Setting");
	//クレジット
	SceneMgr.add<Credit>(U"Credit");

	while (System::Update()) {
		SceneMgr.updateScene();
		SceneMgr.drawScene();
	}
}