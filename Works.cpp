#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Works.h"

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"Works//Workslist.txt");
	String line;
	while (reader.readLine(line)) {
		works working;
		working.workModel = Model(U"works//" + line + U".obj");
		INIReader ini(U"works//" + line + U"exp.ini");
		if (!ini) {
			return;
		}
		authorName = ini.get<String>(U"what.author");
		title = ini.get<String>(U"what.title");
	}
	WorksFont = Font();//unknown
	howToTexture = Texture(U"howToImg");
	TwitterImg = Texture(U"Twitter.png");
	TwitterRect = drawshape<Rect>(TwitterImg.width, TwitterImg.height);//座標決め
	switch (getData().menuNum){
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}

void Works::update() {
	while (getData().firstOpenFlag) {
		howToTexture.draw();
		if (KeyEnter.pressed()) {
			getData().firstOpenFlag = false;
		}
	}
	if (!getData().firstOpenFlag) {
		Graphics3D::FreeCamera();
		if ((KeyRight.pressed() || goToRight.LeftClicked()) || ()) {
			nextWorkNum = nowWorkNum;
			++nextWorkNum;
			nextWorkNum %= works.size();
		}
		if ((KeyLeft.pressed() || goToLeft.LeftClicked()) || ()) {
			prevWorkNum = nowWorkNum;
			++prevWorkNum;
			prevWorkNum %= works.size();
		}

		//later
		if (TwitterRect.mouseOver()) {
			WorksFont(U"Twitterに投稿する").draw();//座標決め
		}

		if (TwitterRect.leftClicked()) {
			Twitter::OpenTweetWindow(U"今、#Comb-Viewer3Dで、" + authorName + "の作品の" + titleName + "を見ています!\nComb Viewer3Dのダウンロードはこちら:");
		}
		//shape of cursor
		const bool handCursor = goToRight.mouseOver;
		const bool handCursor = goToLert.mouseOver;
	}
}

//描画
void Works::draw() {
	if (!disappFlag) {
	  TwitterImg.draw();
	}
	if(){//dec
	  goToRight.draw();
	  goToLeft.draw();
	}
	workModel.draw();

	//drawLeadLine(Window::Center(), Circular(100.0, 60_deg), 150.0, L"引き出し線", LeadLineTextHAlign::Right, LeadLineTextVAlign::Top, font);
	//drawLeadLine(Window::Center() + Circular(50.0, -45_deg), Circular(100.0, -45_deg), 150.0, L"左にも引ける", LeadLineTextHAlign::Left, LeadLineTextVAlign::Top, font);
}
