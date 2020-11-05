#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    // start������ end���� static���� ����
    static Point p_start;
    static Point p_end;

    // ���� �̹��� ����
    Mat processed_image = img.clone();

    static bool click = false;

    if (event == EVENT_LBUTTONDOWN)
    {
        // ���콺�� ������ ���� ����
        click = true;

        p_start = Point(x, y);
    }

    if (event == EVENT_LBUTTONUP)
    {
        // ���콺�� ���� �ٽ� �巡������Ʈ�� ��ƾ���
        click = false;
    }

    if (event == EVENT_MOUSEMOVE)
    {
        if (click == true)
        {
            p_end = Point(x, y);


            // ����ó�� ���� ����
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



            // ���� ����
            Mat roi = processed_image(Rect(p_start, p_end));

            // �¿� ���� ������
            //flip(sub, sub, 1);

            // ���� ����
            bitwise_not(roi, roi);

            // ���� �̹��� window
            //imshow("processed_image", processed_image);
        }
    }

    // ���� �̹��� window
    //imshow("main_image", img);
    imshow("main_image", processed_image);
}

int main()
{
    img = imread("image/bit_test.jpg", IMREAD_COLOR);
    CV_Assert(img.data);

    // set window name
    namedWindow("main_image", WINDOW_AUTOSIZE);

    // mousecallback �Լ��� �����쿡 ����
    setMouseCallback("main_image", onMouse);

    waitKey();
    return 0;
}