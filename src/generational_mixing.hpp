#ifndef GENERATIONAL_MIXING_HPP
#define GENERATIONAL_MIXING_HPP

#include "basic_adult_selection.hpp"

namespace ea
{

class generational_mixing : public basic_adult_selection
{
    public:
        virtual void operator()(const std::vector<basic_individual*>&,
                std::vector<basic_individual*>&) const;
};

}

#endif
