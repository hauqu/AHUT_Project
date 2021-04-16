#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "����������Բ��"


//--------------------��ȫ�ֺ����������֡�---------------------
//     ������ȫ�ֺ���������
//----------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param);


bool g_bDrawingBox = false;//�Ƿ���л���

int main(int argc, char** argv)
{
	//׼������
	
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	
	srcImage = Scalar::all(0);
	// �����������ص�����
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);
	// ������ѭ���������л��Ƶı�ʶ��Ϊ���ʱ����л���
	while (1)
	{
		srcImage.copyTo(tempImage);       // ����Դͼ����ʱ����
		if (g_bDrawingBox)
		{

		}
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27)            // ����ESC���������˳�
			break;
	}
	return 0;
}
//------------------------��on_MouseHandle(����)��------------
//     ���������ص����������ݲ�ͬ������¼����в�ͬ�Ĳ���
//-----------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	switch (event)
	{
	case EVENT_MOUSEMOVE:
	{
		
			//cout << "(" << x << "," << y << ")" << endl;
	}
	break;
	// ���������Ϣ
	case EVENT_LBUTTONDOWN:
	{
		
		
		cout << "(" << x << "," << y << ")" << endl;
	}
	break;
	//���̧����Ϣ
	case EVENT_LBUTTONUP:
	{
		cout << "(" << x << "," << y << ")" << endl;
	
	}
	break;
	}
}

