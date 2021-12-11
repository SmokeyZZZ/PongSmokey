#pragma once //previene il fatto che il file venga preprocessato piu di una volta
#include <SFML\Graphics.hpp>
using namespace sf;
class Paddle
{
private:
	Vector2f m_Position;
	RectangleShape m_Shape;
	float m_speed = 1000.0f;
	bool m_MovingUp = true;
	bool m_MovingDown = false;
public:
	Paddle(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();
	void update(Time dt);
};
