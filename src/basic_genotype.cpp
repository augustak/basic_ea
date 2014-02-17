#include "basic_genotype.hpp"

#include <cstdlib>

namespace ea
{

basic_genotype::basic_genotype(const std::vector<bool>& dna) :
    genome_(dna)
{
}

inline basic_genotype::iterator basic_genotype::begin()
{
    return genome_.begin();
}

inline basic_genotype::const_iterator basic_genotype::begin() const
{
    return genome_.begin();
}

inline basic_genotype::iterator basic_genotype::end()
{
    return genome_.end();
}

inline basic_genotype::const_iterator basic_genotype::end() const
{
    return genome_.end();
}

basic_genotype* random_basic_genotype(std::size_t size)
{
    std::vector<bool> dna;
    for(std::size_t i = 0; i < size; ++i)
    {
        if(std::rand() < RAND_MAX/2) dna.push_back(1);
        else dna.push_back(0);
    }
    return new basic_genotype(dna);
}

}
