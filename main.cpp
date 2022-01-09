//
//  main.cpp
//  image-sequence
//
//  Created by Laurence Abanes on 2022/01/09.
//

#include <iostream>
#include <filesystem>
#include "image_extractor.hpp"

namespace fs = std::filesystem;

int main()
{
    string cwd = fs::current_path();
    vector<string> videos;
    
    for (auto& video : fs::directory_iterator(cwd + "/data/source/"))
    {
        string destination = cwd + "data/output/";
        destination.append(fs::path(video).filename());
        destination.erase(destination.length() - 4, 4);
        fs::create_directories(destination);
        
        extractFrame(video.path(), destination);
    }
    
    return 0;
}
