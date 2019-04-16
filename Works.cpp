#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Works.h"

//(๑•ૅㅁ•๑)o00(ここがスライドショーメインパート)

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"works//Workslist.txt");
	String line, creatorName, title;
	BinaryReader ini;
	while (reader.readLine(line)) {
		works working;
		working.workModel = Model(U"works//" + line + U".obj");
		ini.open(U"works//" + line + U"exp.ini");
		if (!ini) { return; }
		creatorName = ini.read<String>(U"what.creator");
		title = ini.read<String>(U"what.title");
	}
	WorksFont = Font();//決める
	TwitterImg = Texture(U"Twitter.png");
	TwitterRect = drawshape<Rect>(1, 2, 3, 4);//座標決め
	goToRight = Triangle(Vec2(), Vec2(), Vec2());
	goToLeft = Triangle(Vec2(), Vec2(), Vec2());

	//マウスオーバー時にカーソルを手の形にする
	handCursorRight = goToRight.mouseOver();
	handCursorLeft = goToLeft.mouseOver();
	handCursorTwitter = TwitterRect.mouseOver();
}

void Works::update() {
	Graphics3D::FreeCamera();
	works work;
	if (KeyRight.pressed() || goToRight.leftClicked()) {
		nextWorkNum = nowWorkNum;
		++nextWorkNum;
		nextWorkNum %= sizeof(work);
	}

	if (KeyLeft.pressed() || goToLeft.leftClicked()) {
		prevWorkNum = nowWorkNum;
		++prevWorkNum;
		prevWorkNum %= sizeof(work);
	}

	if (TwitterRect.mouseOver()) {
		WorksFont(U"Twitterに投稿する").draw();//座標決め(TwitterRectの少し下)
	}

	if (TwitterRect.leftClicked()) {
		Twitter::OpenTweetWindow(U"今、#Comb-Viewer3Dで、" + work.creatorName + "の作品の" + work.titleName + "を見ています!\nComb Viewer3Dのダウンロードはこちらから!\nhttps://github.com/severrabaen/Comb-Viewer3D via @severrabaen");
	}

	//スライドショー
	if (getData().slideFlag || stopwatch.ms() == disappMAndRecMillisec) {
		nextWorkNum = nowWorkNum;
		++nextWorkNum;
		nextWorkNum %= sizeof(work);
	}

	if (handCursorRight) { CursorStyle::Hand; }
	else { CursorStyle::Default; }

	if (handCursorLeft) { CursorStyle::Hand; }
	else { CursorStyle::Default; }

	if (handCursorTwitter) { CursorStyle::Hand; }
	else { CursorStyle::Default; }
}

//描画
void Works::draw() const {
	if (!disappFlag) {
		TwitterImg.draw();
	}
	//x座標のいい感じのところにカーソルが来たら矢印を表示
	if ((double)Cursor::Pos().x <= (double)Window::Width() / 5 || (double)Cursor::Pos().x >= (double)(Window::Width() / 5) * 4) {
		goToRight.drawFrame();
		goToLeft.drawFrame();
	}
	working.workModel.draw();
}