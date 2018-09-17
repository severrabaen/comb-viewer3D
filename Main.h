#include <Siv3D.hpp>
#include <HamFramework.hpp>

using MyApp = SceneManager<String>;

struct ViewerData {
	bool firstOpenFlag = true;
};

//MessageBox(escape or not)
class Main :public MyApp::Scene {
private:
	Font mFont = Font(18);
	Point center = Window::Center();
	Rect messageBox = Rect(300, 150).setCenter(center);
	Rect yesButton = Rect(120, 40).setcenter(center.movedBy(-70, 30));
	Rect noButton = Rect(120, 40).setcenter(center.movedBy(70, 30));
	EasingController<double> easing(0.0, 1.0, Easing::Quart, 500.0);
	EscapeRect=drawshape<Rect>(;

	void update() {
		Graphics2D::SetTransform(Mat3x2::Identity());
		const double e = easing.easeout();

		if (e != 0) {
			Graphics2D::SetTransform(Mat3x2::Translate(-center).scale(e).translate(center));
			const ColorF uiColor = AlphaF(e);
			RoundRect(messageBox, 20).draw(ColorF(0.2, 0.6, 0.4, e));
			mFont(U"終了してよろしいですか？").drawCenter(center.movedBy(0, -30), uiColor);

			yesButton.drawFrame(2, 0, uiColor);
			mFont(U"はい").drawCenter(yesButton.center, uiColor);

			noButton.drawFrame(2, 0, uiColor);
			mFont(U"いいえ").drawCenter(noButton.center, uiColor);
		}
	}
	if (!easing.isActive()){
		if (e == 1.0){
			if (yesButton.mouseOver())
				yesButton.draw(AlphaF(0.3));

			if (noButton.mouseOver())
				noButton.draw(AlphaF(0.3));

			if (yesButton.leftClicked())
				System::Exit();

			if (noButton.leftClicked())
				easing.start();
		}
		else if (EscapeRect.leftClicked()){
			easing.start();
		}
	}
public:

}

//いつもの
template <class ShapeType>
class drawshape :public ShapeType {
public:
	Transition m_transition = Transition(0.2s, 0.1s);

public:
	drawShape() = default;

	explicit drawShape(const ShapeType& shape)
		: ShapeType(shape) {}

	template <class ...Args>
	explicit drawShape(Args&&... args)
		: ShapeType(std::forward<Args>(args)...) {}

	void update()
	{
		m_transition.update(ShapeType::mouseOver());
	}

	void drawShape(Color color = Color(255, 255, 255)) const
	{
		ShapeType::drawFrame(0, 2, color);
		ShapeType::draw(Color(color, (uint32)(m_transition.value() * 64)));
	}

	const Transition& getTransition() const
	{
		return m_transition;
	}
};
