#include <Siv3D.hpp>
#include <HamFramework.hpp>

using MyApp = SceneManager<String, GameData>;

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
