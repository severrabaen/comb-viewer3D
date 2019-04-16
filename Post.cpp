#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Post.h"

//(๑•ૅㅁ•๑)o00(文化祭限定投稿機能(๑•ૅㅁ•๑)ヴァネ!?)

Post::Post(const InitData& init) :IScene(init) {
	postFont = Font(20);
	expRect = drawshape<Rect>((Window::Width()) / 2, (Window::Height()) / 2, 400, 100);
	inpRect = drawshape<Rect>((Window::Width()) / 2, (Window::Height()) / 2 + 500, 400, 800);
}

void Post::update() {

}

void Post::draw() const {
	for (auto i : buttonChars) { i.draw(); }
	inpRect.drawFrame();
	expRect.drawFrame();
}