#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Main.h"

//�L�[�{�[�h�Ɏg������
const String buttonChars = U"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!?-_";
//���e��:�{��
using posting = std::pair<String, String>;

class CharButton {
private:
	String m_text;
	Rect m_rect;
	bool m_pressed = false;
public:
	CharButton() = default;
	CharButton(const String& text, const Rect& rect)
		: m_text(text)
		, m_rect(rect) {}
	bool update() {
		if (m_rect.leftClicked()) {
			m_pressed = true;
		}
		else if (m_pressed && !m_rect.mouseOver()) {
			m_pressed = false;
		}
		else if (m_pressed && m_rect.leftReleased) {
			m_pressed = false;
			return true;
		}
		return false;
	}
};


class Post :public MyApp::Scene {
private:
	Font postFont;
	Rect inpRect;

public:
	void update() override;
	void draw() const override;
};