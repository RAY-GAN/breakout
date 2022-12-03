// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"


// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;





// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), PlayerPaddle(Vector2f(400, 400), Vector2f(100, 35)), Ball(PlayerPaddle.getPosition() + Vector2f(50, -30), Vector2f(20, 20)), GameUI(), GameSounds() {
	// Set our fps to 60
	Player = PlayerController(&PlayerPaddle);
	normaltexture.loadFromFile("cracked brick.PNG");
	normalsound.loadFromFile("break.wav");
	toughtexture.loadFromFile("brick.PNG");
	toughsound.loadFromFile("shatter.wav");

	GameUI.live = 3;
	GameUI.score = 0;

	level = new Level(&normal_brick, &tough_brick, &Ball);
	level->normal = &normal_brick;
	level->tough = &tough_brick;

	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		Player.HandleInput(event);

		float n;
		int r;
		r = rand();
		if (r % 2 == 0) {
			n = 1;
		}
		else {
			n = -1;
		}


		if (event.type == Event::MouseButtonPressed) {
			Ball.notattached = true;
			Ball.setVelocity(Vector2f(float(rand() % (5 - 2 + 1) + 2) * n, -float(rand() % (5 - 2 + 1) + 2)));
		}

		//sapce to reset the game
		
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {

	

	// Update our paddles 
	Player.update(window, deltaTime);
	Ball.update(window, deltaTime);
	level->update(window, deltaTime);

	if (Ball.notattached == false) {
		Ball.setPosition(PlayerPaddle.getPosition() + Vector2f(50, -30));
	}

	// detect collision
	if (PlayerPaddle.collide(Vector2f(Mouse::getPosition(window)))) {
		PlayerPaddle.setFillColor(Color::Green);
	}
	else {
		PlayerPaddle.setFillColor(Color::White);
	}

	

	if (Ball.collide(Vector2f(Mouse::getPosition(window)))) {
		Ball.setFillColor(Color::Green);
	}
	else {
		Ball.setFillColor(Color::White);
	}


	// Bounce if ball hits the paddles
	if (PlayerPaddle.collide(Ball.getCollider())) {
		Ball.setFillColor(Color::Blue);
		Ball.Bounce(&PlayerPaddle, true);
		GameSounds.sfxBuffer.loadFromFile("paddle_bounce.wav");
		GameSounds.PlaySFX();
	}


	//score update

	
	GameUI.live = Ball.health;
	GameUI.score = Ball.score;
	GameUI.update(window, deltaTime);

	//Wall bounce sound effect

	if (Ball.getPosition().x >= GameWidth) {
		GameSounds.sfxBuffer.loadFromFile("wall_bounce.wav");
		GameSounds.PlaySFX();
	}
	else if (Ball.getPosition().x <= 0) {
		GameSounds.sfxBuffer.loadFromFile("wall_bounce.wav");
		GameSounds.PlaySFX();
	}

	//game over sound effect
	if (Ball.getPosition().y > GameHeight) {
		GameSounds.sfxBuffer.loadFromFile("ball_lost.wav");
		GameSounds.PlaySFX();
		Ball.health--;
		Ball.setPosition(PlayerPaddle.getPosition() + Vector2f(50, -30));
		Ball.setVelocity(Vector2f(0, 0));
		Ball.notattached = false;
	}

	if (Ball.health <= 0) {
		GameSounds.sfxBuffer.loadFromFile("gameover.wav");
		GameSounds.PlaySFX();
	}

	if ((level->getBricks())->size() == 0) {
		GameSounds.sfxBuffer.loadFromFile("level complete.wav");
		GameSounds.PlaySFX();
		level->reset(&normal_brick,&tough_brick);
		Ball.setPosition(PlayerPaddle.getPosition() + Vector2f(50, -30));
		Ball.setVelocity(Vector2f(0, 0));
		Ball.notattached = false;
	}

}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our paddles and ball
	PlayerPaddle.render(window, deltaTime);
	Ball.render(window, deltaTime);
	GameUI.render(window, deltaTime);
	level->render(window, deltaTime);
	// Display the window buffer for this frame
	window.display();
}



// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {
	delete level;
}
