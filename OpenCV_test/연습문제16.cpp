#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    // start지점과 end지점 static으로 구현
    static Point p_start;
    static Point p_end;

    // 원본 이미지 복사
    Mat processed_image = img.clone();

    static bool click = false;

    if (event == EVENT_LBUTTONDOWN)
    {
        // 마우스를 누르고 있을 때만
        click = true;

        p_start = Point(x, y);
    }

    if (event == EVENT_LBUTTONUP)
    {
        // 마우스를 때면 다시 드래그포인트를 잡아야함
        click = false;
    }

    if (event == EVENT_MOUSEMOVE)
    {
        if (click == true)
        {
            p_end = Point(x, y);


            // 예외처리 범위 지정
            if (p_end.x < 0)
            {
                p_end.x = 0;
            }

            if (p_end.x > img.cols - 1)
            {
                p_end.x = img.cols - 1;
            }

            if (p_end.y < 0)
            {
                p_end.y = 0;
            }

            if (p_end.y > img.rows - 1)
            {
                p_end.y = img.rows - 1;
            }



            // 범위 지정
            Mat roi = processed_image(Rect(p_start, p_end));

            // 좌우 반전 뒤집기
            //flip(sub, sub, 1);

            // 색상 반전
            bitwise_not(roi, roi);

            // 서브 이미지 window
            //imshow("processed_image", processed_image);
        }
    }

    // 메인 이미지 window
    //imshow("main_image", img);
    imshow("main_image", processed_image);
}

int main()
{
    img = imread("image/bit_test.jpg", IMREAD_COLOR);
    CV_Assert(img.data);

    // set window name
    namedWindow("main_image", WINDOW_AUTOSIZE);

    // mousecallback 함수를 윈도우에 연결
    setMouseCallback("main_image", onMouse);

    waitKey();
    return 0;
}