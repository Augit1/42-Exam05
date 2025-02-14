#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it)
		delete it->second;
	targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		targets[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType(const std::string& type)

