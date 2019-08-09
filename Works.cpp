#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Works.h"

//(๑•ૅㅁ•๑)o00(メインパート。未実装の機能はアップデートを待つ)

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"works//Workslist.txt");

	//エラーが生じた際にログをtxtファイルにも残す
	TextWriter writer(U"works//logger.txt");

	/*while (reader.readLine(line)) {
		worksinfo working;
		//waiting for update...

		//working.workModel = Model(U"works//" + line + U".obj");
		//ini.open(U"works//" + line + U"exp.ini");
		if (!ini) {
			Print << U"Error has occured! : The named file doesn't exist!\n";
			writer << U"Error!(lol)  When:" << DateTime::Now() << U"Cause: ini file doesn't exist!";
			return;
		}
		working.creatorName = ini[U"what.name"];
	}*/

	for (const FilePath& viewDirectory : FileSystem::DirectoryContents(FileSystem::CurrentDirectory() + U"Works", false)) {
		if (!FileSystem::IsDirectory(viewDirectory)) {
			writer.writeln(U"FE!");
			continue;
		}
		const INIData ini(U"works//" + viewDirectory + U"exp.ini");
		if (ini.isEmpty()) {
			writer.writeln(U"IE!");
			continue;
		}
		worksinfo working;

		working.titleName = ini[U"what.title"];
		working.creatorName = ini[U"what.name"];
		working.path = viewDirectory + ini[U"what.dir"];
		//push
		wo << working;
	}

	WorksFont = Font(20, Typeface::Medium);//暫定
	TwitterImg = Texture(U"Twitter.png");
	TwitterRect = drawshape<Rect>(1, 2, 3, 4);//暫定(後で絶対変える)
	menuBack = drawshape<Rect>(1, 2, 3, 4);//(暫定)
	goToLeft = Triangle(Vec2(50, Scene::Height() / 2 + 25), Vec2(25, Scene::Height() / 2), Vec2(50, Scene::Height() / 2 - 25));
	goToRight = Triangle(Vec2(Scene::Width() - 25, Scene::Height() / 2), Vec2(Scene::Width() - 50, Scene::Height() / 2 + 25), Vec2(Scene::Width() - 50, Scene::Height() / 2 - 25));
	stopwatch.start();
}

void Works::update() {

	//waiting for update...
	//Graphics3D::FreeCamera();

	worksinfo working;
	if (KeyRight.pressed() || goToRight.leftClicked()) {
		nextWorkNum = nowWorkNum;
		++nextWorkNum;
		nextWorkNum %= wo.size();
	}

	if (KeyLeft.pressed() || goToLeft.leftClicked()) {
		prevWorkNum = nowWorkNum;
		++prevWorkNum;
		prevWorkNum %= wo.size();
	}

	if (handCursorTwitter) {
		WorksFont(U"Twitterに投稿する").draw();//座標決め(TwitterRectの少し下にする)
	}

	if (TwitterRect.leftClicked()) {
		Twitter::OpenTweetWindow(U"#Comb-Viewer3Dで、" + working.creatorName + U"の3DCG作品の" + working.titleName + U"を見ています!\nComb Viewer3Dのダウンロードはこちらから!\nhttps://github.com/severrabaen/Comb-Viewer3D via @severrabaen");
	}

	//slideshow
	if (getData().slideFlag && stopwatch.ms() == disappMillisec) {
		nextWorkNum = nowWorkNum;
		++nextWorkNum;
		nextWorkNum %= wo.size();
		stopwatch.restart();
	}

	if (goToRight.mouseOver()) {
		cursorhand = true;
	}

	if (goToLeft.mouseOver()) {
		cursorhand = true;
	}

	if (TwitterRect.mouseOver()) {
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
	if ((double)Cursor::Pos().x <= (double)Scene::Width() / 5 || (double)Cursor::Pos().x >= (double)(Scene::Width() / 5) * 4) {
		goToRight.drawFrame();
		goToLeft.drawFrame();
		menuBack.drawFrame();
		WorksFont(U"メニューに戻る", menuBack.center());
	}

	//work.workModel.draw();
}