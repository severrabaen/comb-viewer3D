#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"
#include "Menu.h"

Menu::Menu(const InitData& init) :IScene(init){

}

void Menu::update(){
int32 i=0;

for(const auto&text : texts){
  const bool mouseOver=text.regionCenter(260+i*50).mouseOver;

text.drawCenter(260 + i * 50, AlphaF(mouseOver ? 1.0 : 0.0),AlphaF(mouseOver ? 1.0 : 0.9));
++i;
}
}
