#include <sstream>

#include "Paddle.h"
#include "Ball.h"
#include <cstdlib>
#include <SFML\Graphics.hpp>
#include <iostream>
Paddle player1(40, 1080 / 2);
Paddle player2(1920 - 40, 1080 / 2);
Ball ball(1920 / 2, 1080/2);
VideoMode vm(1920, 1080);
RenderWindow window(vm, "Pong", Style::Fullscreen);
void movementUp();
void movementDown();
void collision();
void scoringAndLives();
int scorep1,scorep2 = 0;
int livesp1 = 3,livesp2 = 3;

Font font;
int main()
{

	//HUD
	Text hudp1,hudp2;
	
	font.loadFromFile("fonts/DS-DIGI.ttf");
	
	hudp2.setFont(font);
	hudp2.setCharacterSize(50);
	hudp2.setFillColor(Color::White);
	hudp2.setPosition(1920/1.25-hudp2.getGlobalBounds().width, 20);
	hudp1.setFont(font);
	hudp1.setCharacterSize(50);
	hudp1.setFillColor(Color::White);
	hudp1.setPosition(20, 20);
	Clock clock;
	while (window.isOpen()) 
	{
		
		//GESTIONE 
		Time dt = clock.restart();
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game when the window is closed
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		movementUp();
		movementDown();
		
		collision();
		scoringAndLives();
		//collision(player1);
		//collision(player2);


		
		player1.update(dt);
		player2.update(dt);
		ball.update(dt);
		std::stringstream ssp1,ssp2;
		ssp1 << "Score: " << scorep1 << " Lives:" << livesp1;
		ssp2 << "Score: " << scorep2 << " Lives:" << livesp2;
		hudp1.setString(ssp1.str());
		hudp2.setString(ssp2.str());
		//UPDATE DEL GIOCO 
		window.clear();
		window.draw(player1.getShape());
		window.draw(player2.getShape());

		window.draw(ball.getShape());
		window.draw(hudp1);
		window.draw(hudp2);
		
		
		
		window.display();
		
		
	}
	
	return 0;
}
void movementUp( )
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player1.moveUp();

		if (player1.getShape().getPosition().y < 0)
		{
			player1.stopUp();
		}
	}
	else
	{
		player1.stopUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		player2.moveUp();

		if (player2.getShape().getPosition().y < 0)
		{
			player2.stopUp();
		}
	}
	else { player2.stopUp(); }
}
void movementDown() 
{
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player1.moveDown();
		if (player1.getShape().getPosition().y > 1080 - player1.getPosition().height)
		{
			player1.stopDown();
		}
	}
	else
	{
		player1.stopDown();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		player2.moveDown();
		if (player2.getShape().getPosition().y > 1080 - player2.getPosition().height)
		{
			player2.stopDown();
		}
	}
	else
	{
		player2.stopDown();
	}
}
void collision() 
{
	
	if (ball.getPosition().top > 1080 - ball.getShape().getSize().x || ball.getPosition().top < 0 + ball.getShape().getSize().x)
	{
		ball.reboundBotOrTop();
	}
	if (ball.getPosition().left > window.getSize().x - ball.getPosition().width||ball.getPosition().left<0+ball.getPosition().width)
	{
		ball.reboundSides();
		
	}
	if (ball.getPosition().intersects(player1.getPosition()) || ball.getPosition().intersects(player2.getPosition()))
	{
		ball.reboundPaddle();
	}
}
void scoringAndLives() 
{
	if (ball.getPosition().left > window.getSize().x - ball.getPosition().width) 
	{
		livesp2--;
		scorep1++;
	}
	if (ball.getPosition().left < 0 + ball.getPosition().width) 
	{
		livesp1--;
		scorep2++;
	}
	
	if (livesp1 == 0 || livesp2 == 0)
	{
		
		//livesp1 = 3; 
		//livesp2 = 3; 
		scorep1 = 0; 
		scorep2 = 0; 
		livesp1 = 3; 
		livesp2 = 3; 
	}
}






