#ifndef BASIC_PARENT_SELECTION_HPP
#define BASIC_PARENT_SELECTION_HPP

#include <utility>

#include "basic_individual.hpp"

namespace ea
{

class basic_parent_selection
{
    public:
        virtual ~basic_parent_selection() {}
        virtual individual_pair_vector operator()(const individual_vector&);
};

}

#endif
