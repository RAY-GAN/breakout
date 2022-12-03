
#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <sstream>

namespace gm {

	const int WinScore = 3;

	class UI
	{
	private:
		

		sf::Font font;
		sf::Text Scoredisplay;
		sf::Text Livedisplay;
		sf::Text GameOver;

	public:

		int live;
		int score;

		UI();

		void update(sf::RenderWindow& window, float deltaTime);

		void render(sf::RenderWindow& window, float deltaTime);

		~UI();


	};
}

#endif

