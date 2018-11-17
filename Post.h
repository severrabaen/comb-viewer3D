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
