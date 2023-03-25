#include "Fruit.h"

Fruit::Fruit()
{
	texture.loadFromFile("res/fruit.png");
	sprite.setTexture(texture);
}
sf::Sprite Fruit::GetSprite()
{
	 return this->sprite;
}
void Fruit::SetPosition(int x, int y)
{
	this->sprite.setPosition(x, y);
}