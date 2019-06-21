#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Works.h"

//(๑•ૅㅁ•๑)o00(ここがスライドショーメインパート)

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"works//Workslist.txt");
	String line, authorName, title;
	BinaryReader ini;

	while (reader.readLine(line)) {
		works working;
		//実装されたら
		//working.workModel = Model(U"works//" + line + U".obj");
		ini.open(U"works//" + line + U"exp.ini");
		if (!ini) {
			Console << U"The ini file doesn't exist!\n";
			return;
		}
		//authorName = ini.read(U"what.name");
	}
	WorksFont = Font(20, Typeface::Medium);//暫定
	TwitterImg = Texture(U"Twitter.png");
	TwitterRect = drawshape<Rect>(1, 2, 3, 4);//暫定(後で絶対変える)
	goToRight = Triangle(Vec2(25, Window::Height() / 2), Vec2(50, Window::Height() / 2 + 25), Vec2(50, Window::Height() / 2 - 25));
	goToLeft = Triangle(Vec2(Window::Width() - 25, Window::Height() / 2), Vec2(Window::Width() - 50, Window::Height() / 2 + 25), Vec2(Window::Width(), Window::Height() / 2 + 25));

	//マウスオーバー時にカーソルを手の形にする
	handCursorRight = goToRight.mouseOver();
	handCursorLeft = goToLeft.mouseOver();
	handCursorTwitter = TwitterRect.mouseOver();
}

void Works::update() {
	//実装されたら
	//Graphics3D::FreeCamera();

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

	if (handCursorTwitter) {
		WorksFont(U"Twitterに投稿する").draw();//座標決め(TwitterRectの少し下にする)
	}

	if (TwitterRect.leftClicked()) {
		Twitter::OpenTweetWindow(U"#Comb-Viewer3Dで、" + work.creatorName + U"の3DCG作品の" + work.titleName + U"を見ています!\nComb Viewer3Dのダウンロードはこちらから!\nhttps://github.com/severrabaen/Comb-Viewer3D via @severrabaen");
	}

	//スライドショー
	if (getData().slideFlag || stopwatch.ms() == disappMillisec) {
		nextWorkNum = nowWorkNum;
		++nextWorkNum;
		nextWorkNum %= sizeof(work);
	}

	if (handCursorRight) {
		cursorhand = true;
	}

	if (handCursorLeft) {
		cursorhand = true;
	}

	if (handCursorTwitter) {
		cursorhand = true;
	}


	if (!cursorhand) {
		CursorStyle::Default;
	}

	else {
		CursorStyle::Hand;
	}
}

//描画
void Works::draw() const {
	works work;

	if (!disappFlag) {
		TwitterImg.draw();
	}

	//マウスのx座標がいい感じのところに来たら移動用の矢印を表示
	if ((double)Cursor::Pos().x <= (double)Window::Width() / 5 || (double)Cursor::Pos().x >= (double)(Window::Width() / 5) * 4) {
		goToRight.drawFrame();
		goToLeft.drawFrame();
	}
	//work.workModel.draw();
}