#include "PlugHolder.hpp"

plt::PlugHolder::PlugHolder(sf::Texture& t, size_t inN, size_t outN, const char* typeName, bool initRenderer) :
	 BasePart(inN, outN, typeName, initRenderer)
{
	this->getRenderer()->setTexture(t);
}

plt::PlugHolder::Ptr plt::PlugHolder::create(sf::Texture& t, size_t inN, size_t outN)
{
	return std::make_shared<PlugHolder>(t, inN, outN);
}

plt::PlugHolder::Ptr plt::PlugHolder::copy(PlugHolder::ConstPtr widget)
{
	if (widget)
		return std::static_pointer_cast<PlugHolder>(widget->clone());
	else
		return nullptr;
}

tgui::Widget::Ptr plt::PlugHolder::clone() const
{
	return std::make_shared<PlugHolder>(*this);
}

bool plt::PlugHolder::eval()
{
	std::vector<bool> is;

	for (auto& p : inputs)
	{
		if (p.first == nullptr || !p.first->eval())
		   return false;

		   is.push_back(p.first->getOutput(p.second));
	}

	if (connected == nullptr)
		return false;

	this->outputs = connected->eval(is);
	evaled = true;

	return true;
}

bool plt::PlugHolder::canAccept(tgui::Vector2f mPos, Plug* plug)
{
	return this->isMouseOnWidget(mPos) && plug->getInputCount() == ins && plug->getOutputCount() == outs;
}