#ifndef BIT_STRING_FITNESS_HPP
#define BIT_STRING_FITNESS_HPP

#include <vector>

#include "basic_fitness.hpp"
#include "basic_phenotype.hpp"

namespace ea
{

class bit_string_fitness : public basic_fitness
{
    public:
        bit_string_fitness(const std::vector<bool>& bit_string) :
            BIT_STRING(bit_string) {}
        virtual ~bit_string_fitness() {}
        virtual int operator()(const basic_phenotype*) const;
    private:
        const std::vector<bool> BIT_STRING;
};

}

#endif
