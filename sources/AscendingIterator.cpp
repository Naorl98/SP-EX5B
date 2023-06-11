#include "MagicalContainer.hpp"
#include <stdexcept>
#include <vector>
using namespace ariel;
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container): container(&container), index(0){} 
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index): container(&container), index(index) {}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): container(other.container), index(other.index) {}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
 if(container != other.container) throw std::runtime_error("Containers are not the same");

    if(this != &other)
    {
        index = other.index;
        container = other.container;
    }
    return *this;
}

int MagicalContainer::AscendingIterator::operator*()
{
    return (*container).elements[index];;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    return index != other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    return index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    return index < other.index;
}




MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    // inc index
if( index == container->size()) throw std::runtime_error("overflow");
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(*this);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(*container, (*container).size());

}