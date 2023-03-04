#include <string>
#include "Types.h"
namespace OpenAI {
    class ChatGPT {
    public:
        explicit ChatGPT(const std::string& token);
        OpenAI::ChatCompletion askChatGPT(const std::string& role, const std::string& content);
        std::string askWhisper(const std::string& audio_path);
    private:
        std::string m_token;
        std::string m_link;
    };
}
