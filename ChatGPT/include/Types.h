#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

namespace OpenAI {
    using json = nlohmann::json;

    struct ChatCompletion {
        std::string id;
        std::string object;
        int created;
        std::string model;
        struct Usage {
            int prompt_tokens;
            int completion_tokens;
            int total_tokens;
        } usage;
        struct Choice {
            struct Message {
                std::string role;
                std::string content;
            } message;
            std::string finish_reason;
            int index;
        };
        std::vector<Choice> choices;
    };

    inline void from_json(const json &j, ChatCompletion &c) {
        j.at("id").get_to(c.id);
        j.at("object").get_to(c.object);
        j.at("created").get_to(c.created);
        j.at("model").get_to(c.model);
        j.at("usage").at("prompt_tokens").get_to(c.usage.prompt_tokens);
        j.at("usage").at("completion_tokens").get_to(c.usage.completion_tokens);
        j.at("usage").at("total_tokens").get_to(c.usage.total_tokens);
        for(auto choice:j.at("choices")) {
            ChatCompletion::Choice current;
            choice.at("message").at("role").get_to(current.message.role);
            choice.at("message").at("content").get_to(current.message.content);
            if(choice.at("finish_reason").is_string()) {
                choice.at("finish_reason").get_to(current.finish_reason);
            }else{
                current.finish_reason="null";
            }
            choice.at("index").get_to(current.index);
            c.choices.push_back(current);
        }
    }
}
