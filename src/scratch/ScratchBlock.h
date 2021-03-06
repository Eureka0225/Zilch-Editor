#ifndef SCRATCHBLOCK_H
#define SCRATCHBLOCK_H

#include "ScratchBlockPrototype.h"

class ScratchObject;
class BlockItem;

class ScratchBlock {
public:
	ScratchBlock(ScratchBlockPrototype *Block, ScratchBlock *LastBlock = nullptr, ScratchBlock *NextBlock = nullptr);
	~ScratchBlock();
	bool isHead();
	void Run(ScratchObject *Object);
public:
	ScratchBlockPrototype *Block;
	ScratchBlock *LastBlock;
	ScratchBlock *NextBlock;
	BlockItem *Item;
	int X;
	int Y;
};

#endif // SCRATCHBLOCK_H
