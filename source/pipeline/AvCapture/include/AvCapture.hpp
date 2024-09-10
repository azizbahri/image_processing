#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
namespace av
{
    /**
     * @brief A Capture class
     *
     * Provide a simple interface to capture Video/Image frames
     *
     */
    class AvCapture
    {
    private:

        /**
         * @brief Control flags
         *
         */
        typedef enum {
            AV_RUN = 0,
            AV_STOP
        } progress_ctrl_flags;

        /**
         * @brief Main loop control
         *
         */
        progress_ctrl_flags progress_ctrl;
        /**
         * @brief capture object
         *
         */
        cv::VideoCapture videocapture;

        /**
         * @brief Name of this capture instance
         *
         */
        std::string capture_name;

        /**
         * @brief Current frame
         *
         */
        cv::Mat cap_cur_frame;

        /**
         * @brief Video Position Trackbars
         *
         */
        int track_bar_vid_pos;

        /**
         * @brief Frame capture loop begin
         *
         *  A self contained capture loop.
         */
        void main_loop(void);

    public:
        /**
         * @brief Open a camera for video capture
         *
         * @param index camera_id + domain_offset (CAP_*) id of the video
         * capturing device to open. To open default camera using default backend
         * just pass 0. Use a domain_offset to enforce a specific reader
         * implementation if multiple are available like cv::CAP_FFMPEG or
         * cv::CAP_IMAGES or cv::CAP_DSHOW. e.g. to open Camera 1 using
         * the MS Media Foundation API use index = 1 + cv::CAP_MSMF
         */
        AvCapture(int index);
        /**
         * @brief Construct a new Av Capture object
         *
         * Consume a CV VideoCapture object
         *
         * @param cap_src
         */
        AvCapture(cv::VideoCapture cap_src);

        /**
         * @brief Construct a new Av Capture object using file path
         *
         * @param path file path
         */
        AvCapture(std::string path, std::string name);

        /**
         * @brief begin capture loop
         *
         */
        void begin(void);

        /**
         * @brief end capture loop
         *
         */
        void end(void);

        // ~AvCapture() {};
    };
}; // namespace av
