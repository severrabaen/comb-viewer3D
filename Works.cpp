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
		INIReader ini(U"data//" + line + U"exp.txt");
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

		}
		if ((KeyLeft.pressed() || goToLeft.LeftClicked()) || ()) {

		}

		//later
		if (TwitterRect.mouseOver()) {
			WorksFont(U"Twitterに投稿する").draw();//座標決め
		}

		if (TwitterRect.leftClicked()) {
			Twitter::OpenTweetWindow(U"今、#Comb-Viewer3Dで、" + authorName + "氏の3DCG作品の" + titleName + "を見ています!");
		}
	}
}

void Works::draw() {
	if (!disappFlag) {
		goToRight.draw();
		goToLeft.draw();
		TwitterImg.draw();
	}
	workModel.draw();

	//drawLeadLine(Window::Center(), Circular(100.0, 60_deg), 150.0, L"引き出し線", LeadLineTextHAlign::Right, LeadLineTextVAlign::Top, font);
	//drawLeadLine(Window::Center() + Circular(50.0, -45_deg), Circular(100.0, -45_deg), 150.0, L"左にも引ける", LeadLineTextHAlign::Left, LeadLineTextVAlign::Top, font);
}
