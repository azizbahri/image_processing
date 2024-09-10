#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <AvCapture.hpp>

#define VIDEO_SRC "/home/aziz/dev/project/media/SOS70007.MOV"

int main()
{
    try
    {
        /* code */
        av::AvCapture cap(VIDEO_SRC, "main video");

        cap.begin();

        std::cout << "frame end" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}