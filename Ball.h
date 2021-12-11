#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Ball
{
	
private:
	Vector2f m_position;
	RectangleShape m_shape;
	float m_speed =2000.0f;
	float m_directionX = .2f;
	float m_directionY = .2f;
public:
	Ball(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBotOrTop();
	void reboundBottom();
	void reboundPaddle();
	void update(Time dt);
	
	
};

