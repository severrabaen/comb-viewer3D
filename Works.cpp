#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Works.h"

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"Works//Workslist.txt");
	String line;
	while (reader.readLine(line)) {
		workModel = Model(line + U".obj");
		authorName = line;
		titleName = line;
	}
	WorksFont = Font()//unknown;
		howToTexture = Texture(U"");
}

void Works::update() {
	while (getData().firstOpenFlag) {
		howToTexture.draw();
		if (KeyEnter.pressed()) {
			getData().firstOpenFlag = false;
		}

	}

	Graphics3D::FreeCamera();

	if ((KeyRight.pressed() || goToRight.LeftClicked()) || ()) {

	}
	if ((KeyLeft.pressed() || goToLeft.LeftClicked()) || ()) {

	}
}

void Works::draw() {
	if (!disappFlag) {
		goToRight.draw();
		goToLeft.draw();

	}
	workModel.draw();

	//drawLeadLine(Window::Center(), Circular(100.0, 60_deg), 150.0, L"引き出し線", LeadLineTextHAlign::Right, LeadLineTextVAlign::Top, font);
	//drawLeadLine(Window::Center() + Circular(50.0, -45_deg), Circular(100.0, -45_deg), 150.0, L"左にも引ける", LeadLineTextHAlign::Left, LeadLineTextVAlign::Top, font);
}
