#include <Siv3D.hpp>
#include <HamFramework.hpp>
#define SIV3D_WINDOWS_HIGH_DPI
#include "Main.h"
#include "Menu.h"
#include "Works.h"
#include "Setting.h"
#include "Credit.h"

//(๑•ૅㅁ•๑)o00(フルスクリーン、SceneMgr)

void Main() {
	Window::SetTitle(U"Comb Viewer 3D" + verstr);
	MyApp SceneMgr;

	//fullscreen
	const Array<Size> resolutions = Graphics::GetFullscreenResolutions();
	size_t index = resolutions.size() - 1;
	Window::SetFullscreen(true, resolutions[index]);

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
