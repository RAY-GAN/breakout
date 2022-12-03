#// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>


 /* Our Includes */
#include "Paddle.h"
#include "Ball.h"
#include "PlayerController.h"
#include "Brick.h"
#include "Level.h"
#include "UI.h"
#include "SoundManager.h"


// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GameWidth = 640;
	const int GameHeight = 640;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;

		sf::Texture normaltexture;
		sf::Texture toughtexture;
		sf::SoundBuffer normalsound;
		sf::SoundBuffer toughsound;

		BrickType normal_brick = {
			1,
			&normaltexture,
			sf::Color::White,
			&normalsound
		};

		BrickType tough_brick = {
			2,
			&toughtexture,
			sf::Color::White,
			&toughsound
		};


		// Our game objects
		Paddle PlayerPaddle;
		Ball Ball;
		PlayerController Player;
		Level* level;

		UI GameUI;
		SoundManager GameSounds;

	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();

		

		// Destructor
		~Game();
	};
}

#endif


