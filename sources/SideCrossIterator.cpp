#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): container(&container), index(0) {}  
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t index): container(&container), index(index) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other): container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    if(container != other.container) throw std::runtime_error("Containers r not the same");
    if(this != &other)
    {
        index = other.index;
        container = other.container;
    }
    return *this;
}
int MagicalContainer::SideCrossIterator::operator*()
{
return (*(this->container)).elements[index];}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    return index < other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    return index > other.index;
}



MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    // inc the index and get the next one
    size_t half = (*container).elements.size() / 2;
    size_t  sizeofcont = (*container).elements.size();
    //if index is equal to size so eror
    if (index == sizeofcont) throw std::runtime_error("overflow");
// if index equal to half so we r finish
    if( index == half)
    {
        index = sizeofcont;
        return *this;
    }
    if( index > half)
    {
        index = sizeofcont - index;
        return *this;
    }
    if( index < half)
    {
        index = sizeofcont - index - 1;
        return *this;
    }

    return *this;
}



MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    //return index 0
	return SideCrossIterator((*this->container));
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
return SideCrossIterator(*this->container, (*container).elements.size());  
}