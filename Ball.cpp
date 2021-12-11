#include "Ball.h"
Ball::Ball(float startX,float startY)
{
	m_position.x = startX;
	m_position.y = startY;
	m_shape.setSize(sf::Vector2f(10, 10));
	m_shape.setPosition(m_position);
}
FloatRect Ball::getPosition() 
{
	return m_shape.getGlobalBounds();

}
RectangleShape Ball::getShape()
{
	return m_shape;
}
float Ball::getXVelocity() 
{
	return m_directionX;
}
void Ball::reboundSides()
{
	m_position.x = 1920/2;
	m_position.y = 1080 / 2;
	m_directionY = -m_directionY;
	
}
void Ball::reboundBotOrTop()
{
	
	m_directionY = -m_directionY;
}
void Ball::reboundPaddle() 
{
	m_directionX = -m_directionX;
}


void Ball::update(Time dt)
{
	m_position.x += m_directionX * m_speed * dt.asSeconds();
	m_position.y += m_directionY * m_speed * dt.asSeconds();

	m_shape.setPosition(m_position);
}


