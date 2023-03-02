#include <string>
#include <exception>
namespace OpenAI {
    struct Error : public std::exception {
        Error(std::string error);
        const char* what() const noexcept override;
    private:
        std::string message;
    };
}