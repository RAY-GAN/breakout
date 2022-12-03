#include "SoundManager.h"

using namespace sf;
using namespace gm;


SoundManager::SoundManager() {
	sfx.setBuffer(sfxBuffer);
}

void SoundManager::PlaySFX() {
	sfx.play();
}

SoundManager::~SoundManager() {

}