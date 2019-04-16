#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Credit.h"

//(๑•ૅㅁ•๑)o00(クレジット作成)

Credit::Credit(const InitData& init) :IScene(init) {
	creditFont = Font(20);
}

void Credit::update() {

}
void Credit::draw() const {
	creditFont.draw(sentence);
}