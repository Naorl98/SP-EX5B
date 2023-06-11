#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container): container(&container), Pindex(0) {}  
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, size_t Pindex): container(&container), Pindex(Pindex) {}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other): container(other.container), Pindex(other.Pindex) {}


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{
 if(container != other.container) throw std::runtime_error("Containers are not the same");
    if(this != &other)
    {
        Pindex = other.Pindex;       
        container = other.container;
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*()
{
return *(*container).PsortElement[Pindex];}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
    return Pindex == other.Pindex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    return Pindex != other.Pindex;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    return Pindex < other.Pindex;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    return Pindex > other.Pindex;
}


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if( Pindex >= (*container).PsortElement.size()) throw std::runtime_error("out of bound");
    ++Pindex;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(*this);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
return PrimeIterator(*container, (*container).PsortElement.size());
}