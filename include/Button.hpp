#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Button : public sf::Drawable {
	sf::Font* font = nullptr;
	sf::SoundBuffer* buffer = nullptr;
	sf::Text text;
	sf::Color default_color;

	bool is_pressed = false;

	bool is_button_pressed = false;

	void hover();
	void unhover();
	void checkForPress(sf::Vector2f mouse_position);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void initBody(std::string text, sf::Vector2f position);
	void initSound();
public:
	explicit Button(sf::Font* font = nullptr, const std::string& text = "", sf::Vector2f position = sf::Vector2f(), sf::Color color = sf::Color(255, 255, 255, 255), sf::SoundBuffer* buffer = nullptr);
	~Button();

	void update(sf::Vector2f mouse_position);

    bool isPressed();
};
#endif