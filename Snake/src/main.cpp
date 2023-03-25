#include "Snake.h"
#include <time.h>
#include <windows.h>
Direction DirectionChange(Direction& dir,sf::Event event)
{
	if (event.key.code == sf::Keyboard::Down && dir != Direction::UP)
	{
		return dir = Direction::DOWN;
	}
	if (event.key.code == sf::Keyboard::Up && dir != Direction::DOWN)
	{
		return dir = Direction::UP;
	}
	if (event.key.code == sf::Keyboard::Left && dir != Direction::RIGHT)
	{
		return dir = Direction::LEFT;
	}
	if (event.key.code == sf::Keyboard::Right && dir != Direction::LEFT)
	{
		return dir = Direction::RIGHT;
	}
	return dir;
}
sf::Vector2f RandomValues() {
	int x = rand() % 30;
	int y = rand() % 30;
	sf::Vector2f randomValues(x*15,y*15);
	return randomValues;
}
sf::Vector2f FreeValues(Fruit fruit, Snake snakeList[], sf::Vector2f newPos, int numb)
{
		for (int i = 0; i < numb; i++)
		{
			if (newPos == snakeList[i].GetPosition())
			{
				i = 0;
				newPos.x = (rand() % 30) * 15;
				newPos.y = (rand() % 30) * 15;
			}
		}
		 return newPos;
}
int main()
{
	bool notOver = true;
	while (notOver) {
		srand(time(NULL));
		sf::RenderWindow window(sf::VideoMode(450, 450), "Snake");
		int numb = 4;
		bool collision = false;
		sf::Texture textureFloor;
		textureFloor.loadFromFile("res/floor.png");
		sf::Sprite sprite(textureFloor);
		Snake* snakeList = new Snake[900];
		Fruit fruit;
		sf::Vector2f startValues = RandomValues();
		fruit.SetPosition(startValues.x,startValues.y);
		Direction direction = Direction::RIGHT;
		sf::Clock clock;
		float timer = 0;
		float delay = 0.08;

		while (window.isOpen())
		{
			sf::Event event;
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;
			int randomX = (rand() % 30) * 15;
			int randomY = (rand() % 30) * 15;
			sf::Vector2f randomValues(randomX, randomY);
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					notOver = false;
				}
				if (event.key.code == sf::Keyboard::M)
				{
					window.close();
				}
			}
			if (timer > delay)
			{
				DirectionChange(direction, event);
				timer = 0;
				//Fruit&SnakeHead collision
				if (snakeList[0].GetPosition() == fruit.GetSprite().getPosition())
				{
					sf::Vector2f freeValues = FreeValues(fruit, snakeList, randomValues, numb);
					fruit.SetPosition(freeValues.x, freeValues.y);
					numb++;
				}
				//SnakeHead and body move
				snakeList[0].Move(direction, snakeList, numb);
				//Collision detection
				collision = snakeList[0].Collision(snakeList, numb);
			}
			window.clear();
			//Floor drawing
			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					sprite.setPosition(i * 15, j * 15);
					window.draw(sprite);
				}
			}
			//Fruit drawing
			window.draw(fruit.GetSprite());

			//Snake drawing
			for (int i = 0; i < numb; i++)
			{
				window.draw(snakeList[i].GetSprite());
			}
			if (collision)
			{
				window.close();

			}
			window.display();
		}
		delete[] snakeList;
	}
	return 0;
}
