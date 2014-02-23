#include "csv_writer.hpp"

#include <cstdarg>
#include <limits>
#include <iostream>
namespace ea
{

csv_writer::csv_writer(const std::string& out) :
    out_file(out + ".csv")
{
}

void csv_writer::write_title(std::size_t count, ...)
{
    va_list args;
    va_start(args, count);
    if(out_file.is_open())
    {
        for(std::size_t i = 0; i < count; ++i)
        {
            out_file << va_arg(args, char*);
            if(i != count-1) out_file << ",";
        }
        out_file << std::endl;
    }
    va_end(args);
}

void csv_writer::write(std::size_t count, ...)
{
    va_list args;
    va_start(args, count);
    if(out_file.is_open())
    {
        for(std::size_t i = 0; i < count; ++i)
        {
            out_file << va_arg(args, double);
            if(i!=count-1) out_file << ",";
        }
        out_file << '\n';
    }
    va_end(args);
}

}
