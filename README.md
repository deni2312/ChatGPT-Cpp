
#  ChatGPT-Cpp



<p align="left">A header-only version of ChatGPT Official API written in C++

* [Getting started.](#getting-started)
* [Writing your first bot](#writing-your-first-bot)

## Getting started.

<h2> Steps </h2>

This API is tested with C++ 17, on linux g++ and on Visual Studio 2022.

* Install dependencies with VCPKG
 ```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg install nlohmann-json
vcpkg install cpr
vcpkg integrate install
```  

* Clone the repository
```bash
git clone https://github.com/deni2312/ChatGPT-Cpp.git
```

* With CMake:
```bash
cd ChatGPT-Cpp
mkdir build
cd build
cmake -B build/ -S . -DCMAKE_TOOLCHAIN_FILE=vcpkgdirectory/scripts/buildsystems/vcpkg.cmake
cd build
cmake --build .
./ChatGPT
```  
Change vcpkgdirectory with the relative or absolute path of vcpkg

## Writing your first bot

<h3>Ask something!</h3>

```c++
#include <iostream>
#include "include/ChatGPT.h"
#include "include/Error.h"

int main(int args,char** argv){
    //API token as argument
    OpenAI::ChatGPT chatGpt{argv[1]};
    try {
        //type of user and the message to ask
        auto response = chatGpt.sendRequest("user","Give me 5 words");
        //Iterate all answers
        for(const auto& choice:response.choices){
            std::cout<<choice.message.content;
        }
    }catch(OpenAI::Error& e){
        //JSON error returned by the server
        std::cout<<e.what();
    }
}

```
Feel free to send feedbacks and open issues to improve the library.
