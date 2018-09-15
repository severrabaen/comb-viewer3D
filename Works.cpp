#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <Works.h>

Works::Works(const InitData& init) :IScene(init){
  TextReader reader(U"Works//Workslist.txt");
  String line;
  while(reader.readLine(line)){
  
  }
}

void Works::update(){

}

void Works::draw(){
  if(!disappFlag){
    goToRight.draw();
    goToLeft.draw();
  }
}
