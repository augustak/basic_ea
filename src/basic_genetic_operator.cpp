#include "basic_genetic_operator.hpp"

#include <cstdlib>
#include <cassert>

namespace ea
{

std::vector<basic_genotype*> basic_genetic_operator::operator()(
        const basic_genotype* left_parent, const basic_genotype* right_parent)
{
    genotype_pair children = one_crossover(left_parent, right_parent);
    mutation(children.first);
    mutation(children.second);
    genotype_vector ret;
    ret.push_back(children.first);
    ret.push_back(children.second);
    return ret;
}

void mutation(basic_genotype* gen)
{
    for(std::size_t i = 0; i < gen->size(); ++i)
    {
        if(rand() < RAND_MAX/(int)gen->size()) ((*gen)[i] == 1) ? (*gen)[i] = 0 : (*gen)[i] = 1;
    }
}

genotype_pair one_crossover(const basic_genotype* left_parent, const basic_genotype* right_parent)
{
    assert(left_parent->size() == right_parent->size());
    std::size_t split = rand() % left_parent->size();
    std::vector<bool> dna1;
    std::vector<bool> dna2;
    for(std::size_t i = 0; i < split; ++i)
    {
        dna1.push_back((*left_parent)[i]);
        dna2.push_back((*right_parent)[i]);
    }
    for(std::size_t i = split; i < right_parent->size(); ++i)
    {
        dna1.push_back((*right_parent)[i]);
        dna2.push_back((*left_parent)[i]);
    }
    return std::make_pair(new basic_genotype(dna1), new basic_genotype(dna2));
}

genotype_pair two_crossover(const basic_genotype* left_parent, const basic_genotype* right_parent)
{
    assert(left_parent->size() == right_parent->size());
    std::size_t split1 = rand() % left_parent->size();
    std::size_t split2 = rand() % left_parent->size();
    if(split2 < split1) std::swap(split1, split2);
    std::vector<bool> dna1;
    std::vector<bool> dna2;
    for(std::size_t i = 0; i < split1; ++i)
    {
        dna1.push_back((*left_parent)[i]);
        dna2.push_back((*right_parent)[i]);
    }
    for(std::size_t i = split1; i < split2; ++i)
    {
        dna1.push_back((*right_parent)[i]);
        dna2.push_back((*left_parent)[i]);
    }
    for(std::size_t i = split2; i < left_parent->size(); ++i)
    {
        dna1.push_back((*left_parent)[i]);
        dna2.push_back((*right_parent)[i]);
    }
    return std::make_pair(new basic_genotype(dna1), new basic_genotype(dna2));
}

}
