#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"

Menu::Menu(const InitData& init) :IScene(init) {
	glyphFont = Font(25);
	const String text = U"Comb-Viewer3D";
	const auto g2 = glyphFont.getGlyph(U'2');
	const RectF region = glyphFont(text).regionAt(Window::center());
}

void Menu::update() {
	if (getData().glyphFlag) {
		const double t = Min(1.0, System::FrameCount() / 50.0);
		Vec2 pos(region.tl());
		for (const auto& glyph : glyphFont(text)) {
			if (g.codePoint == U'C') {
				g.texture.draw(pos + g.offset - Vec2{ 0, 1000 * EaseIn(Easing::Cubic, 1.0 - t) }, Color(48));
			}
			else if (g.codePoint == U'3'&&t < 1.0) {
				g2.texture.draw(pos + g2.offset, Color(48, 255 * ((System::FrameCount() / 3) % 2)));
				pos.x += g2.xAdvance;
				continue;
			}
			else if (g.codePoint == U'D'){
				const double ratio = cos(Math::TwoPi * t * 4);
				g.texture.scaled(ratio, 1.0).draw(pos + g.offset + Vec2(g.xAdvance * (1 - ratio) / 2, 0), Color(48));
			}
			else {
				g.texture.draw(pos + g.offset, Color(48));
			}
		}
		getData().glyphFlag = false;
	}
	else {
		for(auto i :step(5)){
		if(text[i].leftClicked()){
		  if(text[i]=="EXIT") System::exit();
		  if(text[i]=="Randomly") startNum=Random(1,worksNum);
			if(text[i]=="")
		}
		}
	}
}

void Menu::draw(){
	if(!getdata().glyphFlag){
        int32 i = 0;
        for (const auto&text : texts) {
	        const bool mouseOver = text.regionCenter(260 + i * 50).mouseOver;
		text.drawCenter(260 + i * 50, AlphaF(mouseOver ? 1.0 : 0.0), AlphaF(mouseOver ? 1.0 : 0.9));
		++i;
	}
    }
}
