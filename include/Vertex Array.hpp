#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class VertexArray : public sf::Drawable{
	std::vector<sf::Vertex> nodes;
	std::vector<sf::Vertex> grid;

    void addQuad(int index_X, int index_Y);
    void addStrip(int index_X, int index_Y, float max_strip_size, bool vertical);

	void initNodes();
	void initGrid();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	const sf::Color default_color = sf::Color(230, 230, 230);

	VertexArray();
	~VertexArray() override;
	
	void setNodeColor(const int index_X, const int index_Y, sf::Color color);
	void setNodeColor(size_t index, sf::Color color);
	void resetNodes();
};

#endif