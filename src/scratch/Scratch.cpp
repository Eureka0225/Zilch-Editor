#include "Scratch.h"
#include <filesystem>
#include <thread>
#include <deque>

#include "ScratchSprite.h"
#include "../widget/MainWindow.h"
#include "../widget/ScriptPart.h"
#include "../widget/StageView.h"
#include "../logger/Logger.h"
#include "../util/Thread.h"

/**
 * @brief Scratch::Scratch - Constructor.
 */
Scratch::Scratch() {	
	//Test code, it will be written into plugin in release.
	BlockCategory.push_back(new ScratchBlockCategory("Motion", 0x4C97FF));
	BlockCategory.push_back(new ScratchBlockCategory("Event", 0xFDD200));

	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "add 10 to x", ScratchBlockType::BODY_BLOCK, [](ScratchObject* Object)->void {
		auto Sprite = static_cast<ScratchSprite*>(Object)->Item;
		Sprite->move(Sprite->x() + 10, Sprite->y());
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "add 10 to y", ScratchBlockType::BODY_BLOCK, [](ScratchObject* Object)->void {
		auto Sprite = static_cast<ScratchSprite*>(Object)->Item;
		Sprite->move(Sprite->x(), Sprite->y() + 10);
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "sub 10 to x", ScratchBlockType::BODY_BLOCK, [](ScratchObject* Object)->void {
		auto Sprite = static_cast<ScratchSprite*>(Object)->Item;
		Sprite->move(Sprite->x() - 10, Sprite->y());
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "sub 10 to y", ScratchBlockType::BODY_BLOCK, [](ScratchObject* Object)->void {
		auto Sprite = static_cast<ScratchSprite*>(Object)->Item;
		Sprite->move(Sprite->x(), Sprite->y() - 10);
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[1], "When program start", ScratchBlockType::HEAD_BLOCK, [](ScratchObject*)->void {

	}));

	//Stage.CreateNewSprite();
}

/**
 * @brief Scratch::~Scratch - Destructor.
 */
Scratch::~Scratch() {
	for (size_t i = 0; i < BlockCategory.size(); i++) {
		delete BlockCategory[i];
	}
	BlockCategory.clear();
	for (size_t i = 0; i < Block.size(); i++) {
		delete Block[i];
	}
	Block.clear();
}

/**
 * @brief Scratch::ProgramRun - Run program.
 */
void Scratch::ProgramRun() {
	std::deque<Thread*> Threads;
	for (const auto &c : this->Stage.BlockList) {
		if (c->Block->Name == "When program start") {
			Threads.push_back(new Thread([&c, this]()->void { c->Run(&this->Stage); }));
		}
	}
	for (const auto &c0 : this->Stage.Sprite) {
		for (const auto &c1 : c0->BlockList) {
			if (c1->Block->Name == "When program start") {
				Threads.push_back(new Thread([&c0, &c1]()->void { c1->Run(c0); }));
			}
		}
	}
	for (auto i = Threads.begin(); i != Threads.end(); i++) {
		(*i)->run();
	}
}

/**
 * @brief Scratch::ProgramStop - Stop program running forcefully.
 */
void Scratch::ProgramStop() {

}
