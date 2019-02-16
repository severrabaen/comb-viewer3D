#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Works.h"

//(๑•ૅㅁ•๑)o00(ここはスライドショーメインパート)

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"works//Workslist.txt");
	String line, creatorName, title;
	BinaryReader ini;
	while (reader.readLine(line)) {
		works working;
		working.workModel = Model(U"works//" + line + U".obj");
		ini.open(U"works//" + line + U"exp.ini");
		if (!ini) {
			return;
		}
		creatorName = ini.read<String>(U"what.creator");
		title = ini.read<String>(U"what.title");
	}
	WorksFont = Font();//決める
	howToTexture = Texture(U"howToImg");
	TwitterImg = Texture(U"Twitter.png");
	TwitterRect = drawShape<Rect>(TwitterImg.width, TwitterImg.height);//座標決め
}

void Works::update() {
	//初回説明用画像(いらないかな？)
	while (getData().firstOpenFlag) {
		howToTexture.draw();
		if (KeyEnter.pressed()) {
			getData().firstOpenFlag = false;
		}
	}
	if (!getData().firstOpenFlag) {
		Graphics3D::FreeCamera();

		if ((KeyRight.pressed() || goToRight.LeftClicked()) || (getData().slideFlag&&)) {
			nextWorkNum = nowWorkNum;
			++nextWorkNum;
			nextWorkNum %= (int)works.size();
		}

		if ((KeyLeft.pressed() || goToLeft.LeftClicked()) || (getData().slideFlag&&)) {
			prevWorkNum = nowWorkNum;
			++prevWorkNum;
			prevWorkNum %= (int)works.size();
		}

		if (TwitterRect.mouseOver()) {
			WorksFont(U"Twitterに投稿する").draw();//座標決め(TwitterRectの少し下)
		}

		if (TwitterRect.leftClicked()) {
			Twitter::OpenTweetWindow(U"今、#Comb-Viewer3Dで、" + creatorName + "の作品の" + titleName + "を見ています!\nComb Viewer3Dのダウンロードはこちらから!\nhttps://github.com/severrabaen/Comb-Viewer3D\n@severrabaen");
		}

		//マウスオーバー時にカーソルを手の形にする
		const bool handCursorRight = goToRight.mouseOver();
		const bool handCursorLeft = goToLeft.mouseOver();
		const bool handCursorTwitter = TwitterRect.mouseOver();
		Cursor::SetStyle(handCursorRight ? CursorStyle::Hand : CursorStyle::Default);
		Cursor::SetStyle(handCursorLeft ? CursorStyle::Hand : CursorStyle::Default);
		Cursor::SetStyle(handCursorTwitter ? CursorStyle::Hand : CursorStyle::Default);
	}
}

//描画
void Works::draw() const {
	if (!disappFlag) {
		TwitterImg.draw();
	}
	if () {//いい感じの位置(x座標)にカーソルが来たら表示
		goToRight.draw();
		goToLeft.draw();
	}
	workModel.draw();
}
