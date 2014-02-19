#ifndef ONE_MAX_DEVELOPMENT_HPP
#define ONE_MAX_DEVELOPMENT_HPP

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"
#include "basic_development.hpp"

namespace ea
{

class one_max_development : public basic_development
{
    public:
        virtual ~one_max_development() {}
        virtual basic_phenotype* operator()(const basic_genotype*) const;
};

}

#endif
