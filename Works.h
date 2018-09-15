#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>

//Time which decide when the visitor not control Comb-Viewer3D for a while.
const int disappMAndRec=10000;

struct works{
  //Viewed model and its data.
  Model workmodel;
  String titleName,authorName;
}

class Works :public MyApp::Scene{
  private:
  //To change the model.
  Triangle goToLeft, goToRight;
  //To disappMAndRec
  Stopwatch stopwatch;
  public:
}
