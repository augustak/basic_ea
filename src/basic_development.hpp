#ifndef BASIC_DEVELOPMENT_HPP
#define BASIC_DEVELOPMENT_HPP

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"

namespace ea
{

class basic_development
{
    public:
        virtual ~basic_development() {}
        virtual basic_phenotype* operator()(const basic_genotype*) const;
};

}

#endif
