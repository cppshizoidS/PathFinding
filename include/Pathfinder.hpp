#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include "Node.hpp"

#include <vector>


#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Pathfinder {
	struct List : private std::vector<Node*>
	{
	public:
		using vector::push_back;
		using vector::operator[];
		using vector::begin;
		using vector::end;
		using vector::size;

		List() = default;

		explicit List(Node* n) {
			push_back(n);
		};

		List(const std::vector<Node*>& n) {
			operator=(n);
		};
		virtual ~List() {};

		[[nodiscard]] bool contains(const Node& n) const {
			for (int i = 0; i < size(); i++)
				if (*operator[](i) == n)
					return true;
			return false;
		}

		void remove(size_t iterator) {
			erase(begin() + iterator);
		}
	private:
		typedef std::vector<Node*> vector;
	};

	static void reconstructPath(Node* finish_node, Node* start_node);
	std::vector<Node*> getNeighbourNodes(std::vector<Node>& nodes, Node* current_node, bool diagonal) const;

	static int calculateDistance(const Node& n1, const Node& n2) ;
	static int getIndex(const int X, const int Y) ;
public:
	Pathfinder();
	~Pathfinder();

	bool startPathfinding(std::vector<Node>& nodes, float& pathfind_time, bool diagonal = true, Node* start_node = nullptr, Node* end_node = nullptr);
};

#endif