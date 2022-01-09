//
//  image_extractor.cpp
//  image-sequence
//
//  Created by Laurence Abanes on 2022/01/09.
//

#include "image_extractor.hpp"

const string SEQUENCE = "000000";

void extractFrame(const string input_video, string destination)
{
    try
    {
        vector<int> compression_params;
        compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
        
        cv::VideoCapture cap(input_video);
        if (!cap.isOpened())
            throw "Could not load vide file!";
        
        for (int i=0; i<cap.get(cv::CAP_PROP_FRAME_COUNT); i++)
        {
            cv::Mat frame;
            cap >> frame;
            
            string image_cnt = SEQUENCE + to_string(i);
            
            if (image_cnt.length() > 10)
                image_cnt.erase(2, image_cnt.length() - 10);
            
            string file_name = destination + "/" + image_cnt + ".jpg";
            cv::imwrite(file_name, frame, compression_params);
        }
    }
    catch (const exception& e)
    {
        throw e.what();
    }
}
