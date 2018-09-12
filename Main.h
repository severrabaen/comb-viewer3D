#include <Siv3D.hpp>
#include <HamFramework.hpp>

//フルスクリーン化
namespace fullscreen{
constexpr Size BaseSize(720, 720);
 void setupfullsc(){
   Window::SetBaseSize(BaseSize);
   const auto[displayIndex, displayMode] = OptimalScreen::Get(OptimalScreen::Preference::AspectMin, BaseSize);
 		Graphics::SetFullScreen(true, displayMode.size, displayIndex, displayMode.refreshRateHz);
 		Print << U"Display {} | size {} @ {} Hz"_fmt(displayIndex, displayMode.size, displayMode.refreshRateHz);
 }
 
 void main(){
 App::setupfullsc();
 Graphics::SetBackGround(Palette::Black);
}
