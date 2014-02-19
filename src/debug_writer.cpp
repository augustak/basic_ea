#include "debug_writer.hpp"

#include <cstdarg>
#include <iostream>
#include <fstream>

namespace ea
{

debug_writer::debug_writer(const std::string& out) : filename_(out)
{
    if(out == "stdout")
    {
        out_stream_ = &std::cout;
    }
    else if(out == "stderr")
    {
        out_stream_ = &std::cerr;
    }
    else
    {
        out_stream_ = new std::ofstream();
        dynamic_cast<std::ofstream*>(out_stream_)->open(filename_.c_str());
    }
}

debug_writer::~debug_writer()
{
    if(out_stream_ != &std::cout && out_stream_ != &std::cerr)
    {
        dynamic_cast<std::ofstream*>(out_stream_)->close();
        delete out_stream_;
    }
}

void debug_writer::write(std::size_t count, ...)
{
    va_list args;
    va_start(args, count);
    for(std::size_t i = 0; i < count; ++i)
    {
        *out_stream_ << va_arg(args, char*);
    }
    *out_stream_ << std::endl;
    va_end(args);
}

}
