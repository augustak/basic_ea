#ifndef FITNESS_PROPORTIONATE_HPP
#define FITNESS_PROPORTIONATE_HPP

#include "basic_individual.hpp"
#include "basic_parent_selection.hpp"

namespace ea
{

class fitness_proportionate : public basic_parent_selection
{
    public:
        virtual individual_pair_vector operator()(const individual_vector&);
};

}

#endif
