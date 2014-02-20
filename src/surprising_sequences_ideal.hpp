#ifndef SURPRISING_SEQUENCES_IDEAL_HPP
#define SURPRISING_SEQUENCES_IDEAL_HPP

#include "basic_ideal_individual.hpp"

namespace ea
{

class surprising_sequences_ideal : public basic_ideal_individual
{
    public:
        virtual bool operator()(basic_individual*) const;
};

}

#endif
