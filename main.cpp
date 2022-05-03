#include <cstdlib>
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;
bool clicking;
int x;
int y;


void save_current_cursor_pos();
void stop_clicker();
void exit_app();
void do_clicking();
void do_main_loop();


int main()
{
	clicking = false;
	system("TITLE Mouse Clicker by sandaasu");
	cout << "======================================================" << endl;
	cout << "[ HOTKEYS ]" << endl << endl;
	cout << "NumPad1 = save mouse position" << endl;
	cout << "NumPad2 = activate autoclicker on saved position" << endl;
	cout << "NumPad3 = STOP" << endl;
	cout << "Escape  = Close" << endl << endl << endl;
	cout << " " << endl << endl;
	cout << "======================================================" << endl;
	cout << " " << endl << endl;
	cout << "[ LOG ] " << endl << endl;
	do_main_loop();

	return EXIT_SUCCESS;
}


void save_current_cursor_pos()
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	x = cursorPos.x;
	y = cursorPos.y;
	cout << "Mouse X = " << x << endl;
	cout << "Mouse Y = " << y << endl;
	Sleep(500);
}


void stop_clicker()
{
	clicking = false;
	Sleep(500);
	cout << "Stopping the clicker.." << endl;
}


void exit_app()
{
	cout << "Bye Bye <3 " << endl;
	clicking = false;
	Sleep(1000);
	system("exit");
}


void do_clicking()
{
	int32_t random_sleep = ((rand() & 10) * 100) + 1000;
	Sleep(random_sleep);

	SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

	if (GetAsyncKeyState(VK_NUMPAD3))
		stop_clicker();

	if (GetAsyncKeyState(VK_ESCAPE))
		exit_app();
}


void do_main_loop()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
			save_current_cursor_pos();

		if (GetAsyncKeyState(VK_ESCAPE))
			exit_app();

		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			cout << "Clicking !" << endl;
			clicking = true;

			while (clicking)
			{
				if (!clicking) break;

				do_clicking();
			}
		}

	}
}
