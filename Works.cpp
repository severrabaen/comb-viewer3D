#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <Works.h>

Works::Works(const InitData& init) :IScene(init) {
	TextReader reader(U"Works//Workslist.txt");
	String line;
	while (reader.readLine(line)) {
		workModel = Model(U"" + U".obj");
	}
	WorksFont = Font()//unknown;
}

void Works::update() {
	Graphics3D::FreeCamera();
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
