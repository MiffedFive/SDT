#include <iostream>
#include <windows.h>
#include <Lmcons.h>

using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	ULONGLONG ticks = GetTickCount64();
	ULONGLONG seconds = ticks / 1000;
	ULONGLONG minutes = seconds / 60;
	ULONGLONG hours = minutes / 60;
	ULONGLONG days = hours / 24;

	cout <<
		"Система работает уже: " <<
		days << " дней " <<
		hours % 24 << " часов " <<
		minutes % 60 << " минут " <<
		seconds % 60 << " секунд " <<
		endl;

	WCHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;

	SYSTEMTIME st;
	GetLocalTime(&st);

	WCHAR buf[256];

	if (GetUserNameW(username, &size)) {
		swprintf_s(buf, 256,
			L"Имя пользователя: %ls\nТекущее время: %02d:%02d:%02d",
			username, st.wHour, st.wMinute, st.wSecond);

		MessageBoxW(NULL, buf, L"Информация", MB_OK|MB_ICONINFORMATION);
	}
	else {
		wcerr << L"Ошибка при получении имени пользователя. Код: "
			<< GetLastError() << endl;
	}

}