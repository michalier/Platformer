#include "BasePart.hpp"

bool plt::BasePart::getOutput(size_t nr) const
{
	return outputs[nr - 1];
}

void plt::BasePart::connectInput(BasePart* p, size_t outNr, size_t inNr)
{
	inputs[inNr - 1].first = p;
	inputs[inNr - 1].second = outNr;
}

size_t plt::BasePart::getInputCount() const 
{ 
	return ins; 
}

size_t plt::BasePart::getOutputCount() const 
{ 
	return outs; 
}

tgui::Vector2f plt::BasePart::getInputPos(size_t nr) const
{
	float dx = this->getSize().x / (getInputCount() + 1);
	return this->getPosition() + tgui::Vector2f(nr * dx, this->getSize().y);
}

tgui::Vector2f plt::BasePart::getOutputPos(size_t nr) const
{
	float dx = this->getSize().x / (getOutputCount() + 1);
	return this->getPosition() + tgui::Vector2f(nr * dx, 0);
}

std::vector<std::pair<plt::BasePart*, size_t>> plt::BasePart::getInputs() 
{
	return inputs;
}