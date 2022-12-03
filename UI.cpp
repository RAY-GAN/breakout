#include "UI.h"


using namespace sf;
using namespace gm;
using namespace std;

UI::UI() {

	

	font.loadFromFile("arial.ttf");


	Scoredisplay.setString(to_string(score));
	Livedisplay.setString(to_string(live));
	GameOver.setString("Game Over");
	Scoredisplay.setFont(font);
	Livedisplay.setFont(font);
	GameOver.setFont(font);
	Scoredisplay.setPosition(Vector2f(20.f, 100.f));
	Livedisplay.setPosition(Vector2f(580.f, 100.f));
	GameOver.setPosition(Vector2f(300.f, 400.f));

}




void UI::update(sf::RenderWindow& window, float deltaTime) {

	Scoredisplay.setString(to_string(score));
	Livedisplay.setString(to_string(live));
}

void UI::render(sf::RenderWindow& window, float deltaTime) {

	window.draw(Scoredisplay);
	window.draw(Livedisplay);
	if (live <= 0) {
		window.draw(GameOver);
	}
}


UI::~UI() {

}