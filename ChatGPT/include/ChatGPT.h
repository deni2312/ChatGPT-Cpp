#include <string>
#include "Types.h"
namespace OpenAI {
    class ChatGPT {
    public:
        explicit ChatGPT(const std::string& token);
        OpenAI::ChatCompletion sendRequest(const std::string& role,const std::string& content);
    private:
        std::string m_token;
        std::string m_link;
    };
}
