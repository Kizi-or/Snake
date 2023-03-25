#pragma once
#include <iostream>
#include "Fruit.h"
#include <vector>
#include <list>
enum class Direction { UP, DOWN, RIGHT, LEFT };

class Snake
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	
	
public:
	Snake();
	~Snake();
	sf::Sprite GetSprite();
	sf::Vector2f GetPosition();
	void Move(Direction direction,Snake snake[],int numb);
	void SetPosition(int x, int y);
	bool Collision(Snake snake[],int numb);
	bool WallCollision();
	bool TailCollision(Snake snake[], int numb);
};

