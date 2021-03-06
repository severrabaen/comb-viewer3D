﻿#pragma once
#include <Siv3D.hpp>
#include <hamFramework.hpp>
#include "Main.h"

//(๑•ૅㅁ•๑)o00(メニューに必要なデータ。GlowTextを追加するかは検討中)

class GlowText {
private:
	Font m_font;
	String m_text;
	Texture m_texture;
	Point m_offset = { 0,0 };
public:
	GlowText() = default;
	GlowText(const Font& font, const String& text, int32 blur, double gamma = 2.0)
		: m_font(font)
		, m_text(text)
		, m_offset(blur + 4, blur + 4) {
		const Size region = font(text).region().stretched(blur + 4).size;

		Image image(region, Color(0, 0));

		font(text).overwrite(image, m_offset, Palette::White);

		image.gaussianBlur(blur, blur).gammaCorrect(gamma);

		for (auto& pixel : image) {
			pixel.a = pixel.r;

			pixel.r = pixel.g = pixel.b = 255;
		}

		m_texture = Texture(image);
	}

	const Texture& getGlowTexture() const {
		return m_texture;
	}

	RectF draw(const Vec2& pos, const Color& glow = Palette::White, const Color& text = Palette::White) const {
		m_texture.draw(pos, glow);
		return m_font(m_text).draw(pos + m_offset, text);
	}

	RectF drawCenter(double y, const Color& glow = Palette::White, const Color& text = Palette::White) const {
		return drawCenter(Vec2(Scene::Width() / 2, y), glow, text);
	}

	RectF drawCenter(const Vec2& pos, const Color& glow = Palette::White, const Color& text = Palette::White) const {
		return draw(pos - m_texture.size() / 2, glow, text);
	}

	RectF region(const Vec2& pos = Vec2(0, 0)) const {
		return RectF(pos, m_texture.size()).stretched(-m_offset);
	}

	RectF regionCenter(double y) const {
		return regionCenter(Vec2(Scene::Width() / 2, y));
	}

	RectF regionCenter(const Vec2& pos) const {
		return region(pos - m_texture.size() / 2);
	}
};

class Menu :public MyApp::Scene {
private:
	Font menuFont;
	Rect exitRect, randomRect, creditRect, settingRect;
	const Array<GlowText> texts = {
	GlowText(menuFont,U"RANDOM",10),
	GlowText(menuFont,U"SETTING",10),
	GlowText(menuFont,U"CREDIT",10),
	GlowText(menuFont,U"QUIT",10),
	};

public:
	Menu(const InitData& init);
	void update()override;
	void draw() const override;
};