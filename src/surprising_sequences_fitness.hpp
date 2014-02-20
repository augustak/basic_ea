#ifndef SURPRISING_SEQUENCES_FITNESS_HPP
#define SURPRISING_SEQUENCES_FITNESS_HPP

#include "basic_phenotype.hpp"
#include "basic_fitness.hpp"

namespace ea
{

class pair
{
    public:
        pair(unsigned int aa, unsigned int bb) : a(aa), b(bb) {}
        unsigned int a;
        unsigned int b;
        bool operator==(const pair& rhs) const { return a==rhs.a && b==rhs.b; }
};

class triple
{
    public:
        triple(unsigned int aa, unsigned int bb, unsigned int dd) :
            a(aa), b(bb), d(dd) {}
        unsigned int a;
        unsigned int b;
        unsigned int d;
        bool operator==(const triple& rhs) const
        {
            return a==rhs.a && b==rhs.b && d==rhs.d;
        }
};

class surprising_sequences_local_fitness : public basic_fitness
{
    public:
        virtual ~surprising_sequences_local_fitness() {}
        virtual int operator()(const basic_phenotype*) const;
};

class surprising_sequences_global_fitness : public basic_fitness
{
    public:
        virtual ~surprising_sequences_global_fitness() {}
        virtual int operator()(const basic_phenotype*) const;
};

unsigned int local_conflicts(const basic_phenotype*);
unsigned int global_conflicts(const basic_phenotype*);

constexpr unsigned int max_local_fitness(unsigned int length)
{
    return length - 2;
}

constexpr unsigned int max_global_fitness(unsigned int length)
{
    return ((length-2) * (length-2) + (length-2))/2;
}

}

#endif
