#include "Minecraft/Register.h"

namespace Minecraft
{
    std::vector<Block*> Register::registeredBlocks;

    void Register::RegisterBlock(Block* block)
    {
        registeredBlocks.push_back(block);
    }

    std::vector<Block*>& Register::GetRegisteredBlocks()
    {
        return registeredBlocks;
    }
}