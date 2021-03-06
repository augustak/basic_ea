#include "basic_development.hpp"

#include <cmath>
#include <vector>
#include <iostream>

namespace ea
{

basic_phenotype* basic_development::operator()(const basic_genotype* gen) const
{
    std::vector<unsigned int> data;
    for(std::size_t i = 0; i < gen->size()/BIT_CHUNK_SIZE; i+=BIT_CHUNK_SIZE)
    {
        unsigned int pheno = 0;
        for(std::size_t j = i, k = 0; j < i+BIT_CHUNK_SIZE; ++j, ++k)
        {
            if((*gen)[j] == 1) pheno += std::pow(2, k);
        }
        data.push_back(pheno);
    }
    if(gen->size()%BIT_CHUNK_SIZE != 0)
    {
        unsigned int pheno = 0;
        for(std::size_t i = BIT_CHUNK_SIZE*(gen->size()/BIT_CHUNK_SIZE), 
                k = 0; i < gen->size(); ++i, ++k)
        {
            if((*gen)[i] == 1) pheno += std::pow(2, k);
        }
        data.push_back(pheno);
    }
    return new basic_phenotype(data);
}

}
