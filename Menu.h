#include <Siv3D.hpp>
#include <hamFramework.hpp>
#include "Main.h"

class GlowText{
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
		, m_offset(blur + 4, blur + 4)
	{
		const Size region = font(text).region().stretched(blur + 4).size;
		
		Image image(region, Color(0, 0));

		font(text).write(image, m_offset, Palette::White);

		image.gaussianBlur(blur, blur).gammaCorrect(gamma);

		for (auto& pixel : image)
		{
			pixel.a = pixel.r;

			pixel.r = pixel.g = pixel.b = 255;
		}

		m_texture = Texture(image);
	}

	const Texture& getGlowTexture() const
	{
		return m_texture;
	}

	RectF draw(const Vec2& pos, const Color& glow = Palette::White, const Color& text = Palette::White) const
	{
		m_texture.draw(pos, glow);

		return m_font(m_text).draw(pos + m_offset, text);
	}

	RectF drawCenter(double y, const Color& glow = Palette::White, const Color& text = Palette::White) const
	{
		return drawCenter(Vec2(Window::Width() / 2, y), glow, text);
	}

	RectF drawCenter(const Vec2& pos, const Color& glow = Palette::White, const Color& text = Palette::White) const
	{
		return draw(pos - m_texture.size / 2, glow, text);
	}

	RectF region(const Vec2& pos = Vec2(0, 0)) const
	{
		return RectF(pos, m_texture.size).stretched(-m_offset);
	}

	RectF regionCenter(double y) const
	{
		return regionCenter(Vec2(Window::Width() / 2, y));
	}

	RectF regionCenter(const Vec2& pos) const
	{
		return region(pos - m_texture.size / 2);
	}
};

class Menu :public MyApp::Scene{
Font menuFont=Font(20,Typeface::Medium);
const Array<GlowText> texts={
GlowText(menuFont,U"Creator",10);
GlowText(menuFont,U"Alphabetical order",10);
GlowText(menuFont,U"Randomly",10);
GlowText(menuFont,U"Settings",10);
GlowText(menuFont,U"EXIT",10);
}
}
