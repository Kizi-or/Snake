#include "Snake.h"

Snake::Snake()
{
	texture.loadFromFile("res/snake.png");
	sprite.setTexture(texture);
}
Snake::~Snake()
{

}
void Snake::Move(Direction direction,Snake snake[],int numb)
{
	sf::Vector2f pos = sprite.getPosition();
	int horizontalDir = 0;
	int verticalDir = 0;
	if (direction == Direction::DOWN)
	{
		horizontalDir = 0;
		verticalDir = 15;
	}
	if (direction == Direction::UP)
	{
		horizontalDir = 0;
		verticalDir = -15;
	}
	if (direction == Direction::LEFT)
	{
		horizontalDir = -15;
		verticalDir = 0;
	}
	if (direction == Direction::RIGHT)
	{
		horizontalDir = 15;
		verticalDir = 0;
	}
	this->sprite.setPosition(this ->sprite.getPosition().x + horizontalDir, this->sprite.getPosition().y + verticalDir);
	for (int i = 1; i < numb; i++)
	{
		sf::Vector2f container = snake[i].sprite.getPosition();
		snake[i].sprite.setPosition(pos);
		pos = container;
	}
}
sf::Vector2f Snake::GetPosition() 
{
	sf::Vector2f copy = this->sprite.getPosition();
	return copy;
}
sf::Sprite Snake::GetSprite() 
{
	sf::Sprite copy = this->sprite;
	return copy;
}
void Snake::SetPosition(int x, int y)
{
	this->sprite.setPosition(x, y);
}
bool Snake::Collision(Snake snake[],int numb)
{
	if(Snake::TailCollision(snake,numb))
	{
		return true;
	}
	if (Snake::WallCollision())
	{
		return true;
	}
	return false;
}
bool Snake::WallCollision()
{
	if (sprite.getPosition().x >= 450 ||
		sprite.getPosition().y >= 450 ||
		sprite.getPosition().x < 0 ||
		sprite.getPosition().y < 0)
	{
		return true;
	}
	return false;
}
bool Snake::TailCollision(Snake snake[],int numb)
{
	for (int i = 1; i < numb; i++)
	{
		if (snake[i].GetPosition() == snake[0].GetPosition())
		{
			return true;
		}
	}
	return false;
}

