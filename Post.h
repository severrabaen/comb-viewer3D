#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

//キーボードに使う文字
const String buttonChars = U"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!?-_";
//投稿者:本文
using posting = std::pair<String, String>;

class CharButton{
private:
	String m_text;
	Rect m_rect;
	bool m_pressed = false;
public:
	CharButton() = default;
	CharButton(const String& text, const Rect& rect)
		: m_text(text)
		, m_rect(rect) {}
	bool update(){
		if (m_rect.leftClicked()){
			m_pressed = true;
		}
		else if (m_pressed() && !m_rect.mouseOver()){
			m_pressed = false;
		}
		else if (m_pressed && m_rect.leftReleased){
			m_pressed = false;
			return true;
		}
		return false;
	}
}


class Post :public MyApp::Scene{
private:
	
public:
}
