// 차량 번호판 객체 검출

#include <opencv2/opencv.hpp>

// io헤더파일을 이용했음
#include <io.h>

using namespace std;
using namespace cv;

void load_filename(string path, vector<string>& filenames)
{
   // _finddata_t 구조체 선언

   //struct _finddata_t {
   //   unsigned    attrib;         /* 파일 특성            */

   //  파일을 만든 시간
   //   time_t      time_create;    /* -1 for FAT file systems */

   //  마지막 파일 액세스 시간
   //   time_t      time_access;    /* -1 for FAT file systems */

   //  마지막으로 파일을 쓴 시간   
   //  기본 : UTC 형식, 현지 시간 변환 : localtime_s
   //   time_t      time_write;

   //  파일의 길이(바이트)
   //   _fsize_t    size;
   //   char        name[260];
   //};


   // filespec : 검색식
   // 첫 파일을 찾고 해당 정보를fileinfo 저장한다음 검색 핸들을 리턴
   // 해당 조건의 파일이 없을 시 -1
   //long _findfirst(char* filespec, struct _finddata_t* fileinfo);


   // _findfirst함수로 searching 후에
   // _findnext로 조건이 일치하는 파일을 찾을 수 있음
   // 해당 조건의 파일이 없을 시 -1
   //int _findnext(long handle, struct _finddata_t* fileinfo);
   
   // 검색 핸들의 종료
   //int _findclose(long handle);


   struct _finddata_t fd;
   int result = 1;

   // intptr_t = long long
   intptr_t handle;

   if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
   {
      cout << "No file in directory!" << endl;
      return;
   }

   while(result != -1)
   {
      //cout << fd.name << endl;

      // 파일이 맞는지 확인
      // 만약 디렉토리라면 push back을 실행하지 않음
      if ((fd.attrib & _A_SUBDIR) == false)
      {
         filenames.push_back(fd.name);
      }
      result = _findnext(handle, &fd);
   }
   _findclose(handle);
}

//void load_filename(string path, vector<string>& filenames)
//{
//   // _finddata_t 구조체 선언
//   
//   //struct _finddata_t {
//   //   unsigned    attrib;         /* 파일 특성            */
//
//   //  파일을 만든 시간
//   //   time_t      time_create;    /* -1 for FAT file systems */
//
//   //  마지막 파일 액세스 시간
//   //   time_t      time_access;    /* -1 for FAT file systems */
//
//   //  마지막으로 파일을 쓴 시간   
//   //  기본 : UTC 형식, 현지 시간 변환 : localtime_s
//   //   time_t      time_write;
//
//   //  파일의 길이(바이트)
//   //   _fsize_t    size;
//   //   char        name[260];
//   //};
//
//   struct _finddata_t fd;
//
//   // intptr_t = long long
//   intptr_t handle;
//
//   if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
//   {
//      cout << "No file in directory!" << endl;
//      return;
//   }
//
//   do
//   {
//      //cout << fd.name << endl;
//      if ((fd.attrib & _A_SUBDIR) == false)
//      {
//         filenames.push_back(fd.name);
//      }
//
//   } while (_findnext(handle, &fd) == 0);
//   _findclose(handle);
//}

void load_image(string path, string search_type, vector<Mat>& images, int flags = 1)
{
   // 순차적인 filename을 받고 싶어 vector로 구현함
   vector<string> filenames;

   // os.path.join이 없어 그냥 string operator로 연산함
   load_filename(path + search_type, filenames);


   // for_each문 내부에 람다 함수 선언
   for_each(filenames.begin(), filenames.end(),
      
      // 규모가 작은것 같아 모두 참조(&)대신 각각의 값을 참조시켜봤음
      [&path, &images, &flags](string filename)
      {
         // flags 값은 imread flags를 차용
         Mat img = imread(path + filename, flags);
         images.push_back(img);
      }
   );
}

int main()
{
   string path = "test_car/";
   string search_type = "*.*";
   vector<Mat> images;

   load_image(path, search_type, images, 1);

   // 유동적인 for_each문처럼 보이기 위해 미리 지정
   int images_begin = 0;
   int images_end = images.size() - 1;


   // getchar -> getint
   int ch;

   // 처음 시작 구간
   int start = 0;
   while (true)
   {
      // 화살표키를 받기 위해 waitKeyEx를 사용
      ch = waitKeyEx();

      //// ch 값 확인
      //cout << ch << endl;

      //// 16진수 값 확인
      //cout << hex << ch << endl;

      if (ch == 0x260000)
      {
         //cout << "윗 방향키" << endl;
         if (start < images_end)
         {
            start = start + 1;
         }
      }
      else if (ch == 0x280000)
      {
         //cout << "아래 방향키" << endl;
         if (images_begin < start)
         {
            start = start - 1;
         }
      }

      else if (ch == 27)
      {
         //cout << "exit" << endl;
         break;
      }
      
      // 원본 영상
      imshow("main_orimage", images[start]);


      // 원본 영상데이터를 가공하는 형식
      // 메인에서 사용해봄
      Mat gray, sobel, th_img, morph;

      Mat kernal(5, 25, CV_8UC1, Scalar(1));
      cvtColor(images[start], gray, COLOR_BGR2GRAY);

      // blur - noise 제거
      blur(gray, gray, Size(5, 5));
      
      // sobel
      Sobel(gray, gray, CV_8U, 1, 0, 3);

      // thres
      threshold(gray, th_img, 120, 255, THRESH_BINARY);

      // morph
      morphologyEx(th_img, morph, MORPH_CLOSE, kernal);

      imshow("thres", th_img);
      imshow("open", morph);

   }

   return 0;
}