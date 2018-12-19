#ifndef SCRATCHBLOCKPROTOTYPE_H
#define SCRATCHBLOCKPROTOTYPE_H

#include <string>
#include <functional>

class ScratchBlockCategory;

enum class ScratchBlockType {
	HEAD_BLOCK,
	BODY_BLOCK,
	TAIL_BLOCK,
	BOOL_BLOCK,
	NUMB_BLOCK,
	NULL_BLOCK
};

class ScratchBlockPrototype {
public:
	ScratchBlockPrototype(ScratchBlockCategory *Category, std::string Name, ScratchBlockType Type, std::function<void()> Function);
public:
	ScratchBlockCategory *Category;
	ScratchBlockType Type;
	std::string Name;
	std::function<void()> Function;
};

#endif // SCRATCHBLOCK_H