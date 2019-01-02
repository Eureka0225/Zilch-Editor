#ifndef SCRATCHSPRITE_H
#define SCRATCHSPRITE_H

#include <string>
#include "ScratchObject.h"

class ScratchStage;
class SpriteItem;

enum class SpriteRotationStyle { FREE, LINE, NONE };

class ScratchSprite : public ScratchObject {
public:
	ScratchSprite(std::string Name);
public:
	static ScratchStage *Stage;
	SpriteItem *Item;
	SpriteRotationStyle RotationStyle;
	bool Draggable;
	bool Show;
	int Direction;
};

#endif // SCRATCHSPRITE_H
