#include <iostream>
#include "ChatGPT/include/ChatGPT.h"
#include "ChatGPT/include/Error.h"

int main(int args,char** argv){
    //API token as argument
    OpenAI::ChatGPT chatGpt{argv[1]};
    try {
        //type of user and the message to ask
        auto response = chatGpt.askChatGPT("user","Give me 5 words");
        //Iterate all answers
        for(const auto& choice:response.choices){
            std::cout<<choice.message.content;
        }
    }catch(OpenAI::Error& e){
        //JSON error returned by the server
        std::cout<<e.what();
    }
}