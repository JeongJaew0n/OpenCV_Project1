// ���� ��ȣ�� ��ü ����

#include <opencv2/opencv.hpp>

// io��������� �̿�����
#include <io.h>

using namespace std;
using namespace cv;

void load_filename(string path, vector<string>& filenames)
{
   // _finddata_t ����ü ����

   //struct _finddata_t {
   //   unsigned    attrib;         /* ���� Ư��            */

   //  ������ ���� �ð�
   //   time_t      time_create;    /* -1 for FAT file systems */

   //  ������ ���� �׼��� �ð�
   //   time_t      time_access;    /* -1 for FAT file systems */

   //  ���������� ������ �� �ð�   
   //  �⺻ : UTC ����, ���� �ð� ��ȯ : localtime_s
   //   time_t      time_write;

   //  ������ ����(����Ʈ)
   //   _fsize_t    size;
   //   char        name[260];
   //};


   // filespec : �˻���
   // ù ������ ã�� �ش� ������fileinfo �����Ѵ��� �˻� �ڵ��� ����
   // �ش� ������ ������ ���� �� -1
   //long _findfirst(char* filespec, struct _finddata_t* fileinfo);


   // _findfirst�Լ��� searching �Ŀ�
   // _findnext�� ������ ��ġ�ϴ� ������ ã�� �� ����
   // �ش� ������ ������ ���� �� -1
   //int _findnext(long handle, struct _finddata_t* fileinfo);
   
   // �˻� �ڵ��� ����
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

      // ������ �´��� Ȯ��
      // ���� ���丮��� push back�� �������� ����
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
//   // _finddata_t ����ü ����
//   
//   //struct _finddata_t {
//   //   unsigned    attrib;         /* ���� Ư��            */
//
//   //  ������ ���� �ð�
//   //   time_t      time_create;    /* -1 for FAT file systems */
//
//   //  ������ ���� �׼��� �ð�
//   //   time_t      time_access;    /* -1 for FAT file systems */
//
//   //  ���������� ������ �� �ð�   
//   //  �⺻ : UTC ����, ���� �ð� ��ȯ : localtime_s
//   //   time_t      time_write;
//
//   //  ������ ����(����Ʈ)
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
   // �������� filename�� �ް� �;� vector�� ������
   vector<string> filenames;

   // os.path.join�� ���� �׳� string operator�� ������
   load_filename(path + search_type, filenames);


   // for_each�� ���ο� ���� �Լ� ����
   for_each(filenames.begin(), filenames.end(),
      
      // �Ը� ������ ���� ��� ����(&)��� ������ ���� �������Ѻ���
      [&path, &images, &flags](string filename)
      {
         // flags ���� imread flags�� ����
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

   // �������� for_each��ó�� ���̱� ���� �̸� ����
   int images_begin = 0;
   int images_end = images.size() - 1;


   // getchar -> getint
   int ch;

   // ó�� ���� ����
   int start = 0;
   while (true)
   {
      // ȭ��ǥŰ�� �ޱ� ���� waitKeyEx�� ���
      ch = waitKeyEx();

      //// ch �� Ȯ��
      //cout << ch << endl;

      //// 16���� �� Ȯ��
      //cout << hex << ch << endl;

      if (ch == 0x260000)
      {
         //cout << "�� ����Ű" << endl;
         if (start < images_end)
         {
            start = start + 1;
         }
      }
      else if (ch == 0x280000)
      {
         //cout << "�Ʒ� ����Ű" << endl;
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
      
      // ���� ����
      imshow("main_orimage", images[start]);


      // ���� �������͸� �����ϴ� ����
      // ���ο��� ����غ�
      Mat gray, sobel, th_img, morph;

      Mat kernal(5, 25, CV_8UC1, Scalar(1));
      cvtColor(images[start], gray, COLOR_BGR2GRAY);

      // blur - noise ����
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