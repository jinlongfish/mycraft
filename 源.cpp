#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSTAR 400	// 星星总数

void printLetter(char letter);
void deleteLetter();

LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0 && wParam == WM_LBUTTONDOWN || wParam == WM_LBUTTONUP ||
		wParam == WM_RBUTTONDOWN || wParam == WM_RBUTTONUP)
	{
		return 1;
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}



// 打开默认浏览器并导航到指定网址
void openURL(const char* url) {
	// 使用系统默认的浏览器打开指定网址
	ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);

	// 获取浏览器窗口句柄
	HWND browserWindow = FindWindowA("Chrome_WidgetWin_1", NULL);

	
}







void printLetter(char letter)
{
	printf("%c", letter); // 打印字符
}

void deleteLetter()
{
	printf("\b \b"); // 逐个删除字符
}






// 延迟一段时间
void delay(int milliseconds) {
	Sleep(milliseconds);
}








LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION && (wParam == WM_SYSKEYDOWN || wParam == WM_SYSKEYUP)) {
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

		if (p->vkCode == VK_MENU) {
			return 1; // 禁止Alt键的按下和释放事件
		}
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}



int main(int argc, char* argv[])
{
	int sleepcount = 0;
	const char* url = "https://fastcdn.mihoyo.com/content-v2/hk4e/123401/124a3679c64c4f65c30b6a5e34bc619d_5553679192264566999.mp4";
	char message[] = "本程序仅供娱乐，请勿滥用！！\n yuan shen ma shang qi dong......";
	int length = strlen(message);
	int i;


	//ShellExecute(NULL, "open", "C:\Windows\\System32\\Taskmgr.exe", NULL, NULL, 0);

	HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
	MSG msg;

	//HWND taskManager = FindWindow("TaskManagerWindow", NULL);
	//if (taskManager != NULL) {
	//	SendMessage(taskManager, WM_CLOSE, 0, 0);

	HHOOK mouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, GetModuleHandle(NULL), 0);
	if (mouseHook == NULL)
	{
		printf("无法设置鼠标钩子\n");
		return 1;
	}


			
	RECT rect;
	int times = 15;
	int timea = 10000;



	for (i = 0; i < length; i++) {
		printLetter(message[i]);
		Sleep(100); // 延迟500ms
	}

	Sleep(2000); // 等待2秒

	for (i = length - 1; i >= 0; i--) {
		deleteLetter();
		Sleep(75); // 延迟500ms
	}

	openURL(url);



	while (sleepcount <= times)
	{
		rect.bottom = 1;
		rect.right = 1;
		ClipCursor(&rect);
		::Sleep(1000);//15000
		sleepcount++;


		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



		ClipCursor(NULL);
		UnhookWindowsHookEx(hook);




		UnhookWindowsHookEx(mouseHook);
		return 0;
}

//ShellExecute(NULL ,"open" , "C:\Windows\\System32\\Taskmgr.exe" , NULL , NULL , 0);



