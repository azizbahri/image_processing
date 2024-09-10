#include <AvCapture.hpp>
#include <sys/stat.h>
#include <exception>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

static bool fexists(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

av::AvCapture::AvCapture(cv::VideoCapture cap_src)
{
    std::cout << "testing" << std::endl;
};

av::AvCapture::AvCapture(int index)
{
    std::cout << "Using Index " << index << std::endl;
}

av::AvCapture::AvCapture(std::string path, std::string name)
{
    /* check if file exists */
    if (!fexists(path))
    {
        /* TODO: ISSUE#7 Create some exceptions */
        throw "File does not exist";
    }

    videocapture.open(path);
    if (!videocapture.isOpened())
    {
        throw "video capture failed";
    }

    capture_name = name;

    cv::namedWindow(capture_name, cv::WINDOW_AUTOSIZE);
}

void av::AvCapture::main_loop(void)
{
    for(;;)
    {
        videocapture >> cap_cur_frame;
        if(cap_cur_frame.empty())
        {
            break;
        }

        if(progress_ctrl == AV_STOP)
        {
            break;
        }
        cv::imshow(capture_name,cap_cur_frame);

        // todo: add setter for playback frame rate
        int key = cv::waitKey(33);
        if (key == 27/*ESC*/)
            break;
    }

}

void av::AvCapture::begin(void)
{
    main_loop();
}

void av::AvCapture::end(void)
{

}