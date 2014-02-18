#ifndef ONE_MAX_IDEAL_HPP
#define ONE_MAX_IDEAL_HPP

#include "basic_ideal_individual.hpp"

namespace ea
{

class one_max_ideal : public basic_ideal_individual
{
    public:
        virtual bool operator()(basic_individual*) const;
};

}

#endif
