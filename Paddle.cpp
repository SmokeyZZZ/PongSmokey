#include "Paddle.h"
Paddle::Paddle(float startX, float startY) 
{
	m_Position.x = startX;
	m_Position.y = startY;
	m_Shape.setSize(sf::Vector2f(5,100));
	m_Shape.setPosition(m_Position);
	
}
FloatRect Paddle::getPosition() 
{
	return m_Shape.getGlobalBounds();
}
RectangleShape Paddle::getShape() 
{
	return m_Shape;
}
void Paddle::moveUp()
{
	m_MovingUp = true;
	
}
void Paddle::moveDown()
{
	m_MovingDown = true;
}
void Paddle::stopUp()
{
	m_MovingUp = false;
}
void Paddle::stopDown() 
{
	m_MovingDown = false;
}
void Paddle::update(Time dt)
{
	if (m_MovingUp)
	{
		m_Position.y -= m_speed * dt.asSeconds();
	}
	if (m_MovingDown)
	{
		m_Position.y += m_speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}

