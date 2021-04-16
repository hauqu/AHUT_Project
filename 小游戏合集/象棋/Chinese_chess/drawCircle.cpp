#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "【鼠标操作画圆】"


//--------------------【全局函数声明部分】---------------------
//     描述：全局函数的声明
//----------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param);


bool g_bDrawingBox = false;//是否进行绘制

int main(int argc, char** argv)
{
	//准备参数
	
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	
	srcImage = Scalar::all(0);
	// 设置鼠标操作回调函数
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);
	// 程序主循环，当进行绘制的标识符为真的时候进行绘制
	while (1)
	{
		srcImage.copyTo(tempImage);       // 复制源图到临时变量
		if (g_bDrawingBox)
		{

		}
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27)            // 按下ESC键，程序退出
			break;
	}
	return 0;
}
//------------------------【on_MouseHandle(函数)】------------
//     描述：鼠标回调函数，根据不同的鼠标事件进行不同的操作
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
	// 左键按下消息
	case EVENT_LBUTTONDOWN:
	{
		
		
		cout << "(" << x << "," << y << ")" << endl;
	}
	break;
	//左键抬起消息
	case EVENT_LBUTTONUP:
	{
		cout << "(" << x << "," << y << ")" << endl;
	
	}
	break;
	}
}

