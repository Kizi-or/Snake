#pragma once
#include <SFML/Graphics.hpp>
class Fruit
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Fruit();
	~Fruit() = default;
	sf::Sprite GetSprite();
	void SetPosition(int x,int y);
};

