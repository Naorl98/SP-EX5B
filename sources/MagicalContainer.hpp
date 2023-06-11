#include <vector>
#include <iostream>
#include <algorithm>
#include <error.h>

namespace ariel
{
    class MagicalContainer 
    {
        private:
            std::vector<int> elements;
            std::vector<int*> PsortElement;

        public:
            bool isPrime(int num);       
            size_t size() const;    
            void addElement(int elem);
            void removeElement(int elem);
            MagicalContainer() = default;            
            // destructor
            ~MagicalContainer(); 
            class AscendingIterator
            {
                private:
                    MagicalContainer * container;
                    size_t index;
                public:
                    AscendingIterator(MagicalContainer& container);
                    AscendingIterator(MagicalContainer& container, size_t index);
                    AscendingIterator(const AscendingIterator& other);
                    ~AscendingIterator() = default;
                    AscendingIterator(AscendingIterator&&) noexcept;
                    AscendingIterator& operator=(AscendingIterator&&) noexcept;
                    AscendingIterator& operator=(const AscendingIterator& other);
                    AscendingIterator& operator++();
                    AscendingIterator begin();
                    AscendingIterator end();                   
                    bool operator==(const AscendingIterator& other) const;
                    bool operator!=(const AscendingIterator& other) const;
                    bool operator<(const AscendingIterator& other) const;
                    bool operator>(const AscendingIterator& other) const;
                    int operator*();
            };

            class PrimeIterator
            {
                private:
                    MagicalContainer * container;
                    size_t Pindex;

                public:
                    PrimeIterator(MagicalContainer& container);
                    PrimeIterator(MagicalContainer& container, size_t index);
                    PrimeIterator(const PrimeIterator& other);
                    ~PrimeIterator() = default;
                    PrimeIterator(PrimeIterator&&) noexcept;
                    PrimeIterator& operator=(PrimeIterator&&) noexcept;
                    PrimeIterator& operator=(const PrimeIterator& other);                   
                    PrimeIterator begin();
                    PrimeIterator end();
                    PrimeIterator& operator++();
                    bool operator==(const PrimeIterator& other) const;
                    bool operator!=(const PrimeIterator& other) const;
                    bool operator>(const PrimeIterator& other) const;
                    bool operator<(const PrimeIterator& other) const;
                    int operator*();

            };

            class SideCrossIterator
            {
                private:
                    MagicalContainer * container;
                    size_t index;

                public:
                    SideCrossIterator(MagicalContainer& container);
                    SideCrossIterator(MagicalContainer& container, size_t index);
                    SideCrossIterator(const SideCrossIterator& other);
                    ~SideCrossIterator() = default;
                    SideCrossIterator(SideCrossIterator&&) noexcept;
                    SideCrossIterator& operator=(SideCrossIterator&&) noexcept;
                    SideCrossIterator& operator=(const SideCrossIterator& other);
                    SideCrossIterator& operator++();
                    SideCrossIterator begin();
                    SideCrossIterator end();
                    bool operator==(const SideCrossIterator& other) const;
                    bool operator!=(const SideCrossIterator& other) const;
                    bool operator>(const SideCrossIterator& other) const;
                    bool operator<(const SideCrossIterator& other) const;
                    int operator*();
            };
    };
}