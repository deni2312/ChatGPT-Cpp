#include <iostream>
#include "include/ChatGPT.h"
#include "include/Error.h"

int main(int args,char** argv){
    OpenAI::ChatGPT chatGpt{argv[1]};
    try {
        auto response = chatGpt.sendRequest("user","Give me 5 words");
        for(auto choice:response.choices){
            std::cout<<choice.message.content;
        }
    }catch(OpenAI::Error& e){
        std::cout<<e.what();
    }
}