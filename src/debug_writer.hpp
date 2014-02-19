#ifndef DEBUG_WRITER_HPP
#define DEBUG_WRITER_HPP

#include <string>
#include <ostream>

namespace ea
{

class debug_writer
{
    public:
        debug_writer(const std::string&);
        ~debug_writer();
        void write(std::size_t, ...);
    private:
        std::string filename_;
        std::ostream* out_stream_;
};

}

#endif
