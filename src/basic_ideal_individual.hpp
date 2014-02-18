#ifndef BASIC_IDEAL_INDIVIDUAL
#define BASIC_IDEAL_INDIVIDUAL

#include "basic_individual.hpp"

namespace ea
{

class basic_ideal_individual
{
    public:
        virtual ~basic_ideal_individual() {}
        virtual bool operator()(basic_individual*) const;
};

}

#endif
