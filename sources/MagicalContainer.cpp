#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::~MagicalContainer(){
//relese all the pointers
    size_t i = 0;
    while(i<PsortElement.size()){
        delete PsortElement[i];
        i++;
    }
    
}
bool MagicalContainer::isPrime(int num)
{
    // check if the num is prime
      if (num <=1)return false;
    if (num == 2)return true;
    for (int i = 2; i * i <= num; i++)
    {
        if ((num % i) == 0)
        {

            return false;
        }
    }

    return true;
}
//comp func
bool comp(int *number, int *other){
    return *number < *other;
}   

void MagicalContainer::addElement(int element)
{
    auto iter = std::lower_bound(elements.begin(), elements.end(), element);
    elements.insert(iter, element);
    if (isPrime(element))
    {
        // new pointer
        int* Pprime = new int(element);
        
        //enter the pointer with comp func
        auto iter = lower_bound(PsortElement.begin(), PsortElement.end(), Pprime, comp);
        // insert the poiter to the vector
        PsortElement.insert(iter, Pprime);
    }
}

void MagicalContainer::removeElement(int element)
{
\
    auto iter = elements.begin();
    while( iter != elements.end())
    {
        if(*iter == element)
        {
            //if the element is exist return, else keep going
            iter = elements.erase(iter);
            return;
        }
        ++iter;
    }
    //if the element is not exist throw eror
    throw std::runtime_error("Element wasn't found");

}

size_t MagicalContainer::size() const{
    return elements.size();
}

