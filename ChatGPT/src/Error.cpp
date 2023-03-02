#include "../include/Error.h"
OpenAI::Error::Error(std::string error) :message{ error }
{
}

const char* OpenAI::Error::what() const noexcept
{
    return message.c_str();
}