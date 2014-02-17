#ifndef BASIC_FITNESS_HPP
#define BASIC_FITNESS_HPP

#include "basic_phenotype.hpp"

namespace ea
{

class basic_fitness
{
    public:
        virtual ~basic_fitness() {}
        virtual int operator()(const basic_phenotype*) const;
};

}

#endif
