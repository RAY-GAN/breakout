#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>


namespace gm {
	class SoundManager
	{
	public:
		sf::SoundBuffer sfxBuffer;
		sf::Sound sfx;

		SoundManager();

		void PlaySFX();

		~SoundManager();
	};
}

#endif

