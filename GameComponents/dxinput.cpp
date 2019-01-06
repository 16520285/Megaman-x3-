#include "dxinput.h"
#define BUTTON_DOWN(obj,button) (obj.rgbButtons[button]&0x80)
LPDIRECTINPUT8 dinput;
LPDIRECTINPUTDEVICE8 dimouse;
LPDIRECTINPUTDEVICE8 dikeyboard;
DIMOUSESTATE mouse_state;

//keyboard input
char keys[256];
int Init_DirectInput(HWND hWnd)
{
	HRESULT result = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dinput,
		NULL

	); // khoi tao doi tuong directinput

	if (result != DI_OK) return 0;

	result = dinput->CreateDevice(GUID_SysMouse, &dimouse, NULL); //khoi tao chuot

	if (result != DI_OK) return 0;

	result = dinput->CreateDevice(GUID_SysKeyboard, &dikeyboard, NULL); // khoi tao ban phim

	if (result != DI_OK) return 0;

	return 1;
}

int Init_Mouse(HWND hWnd)
{
	HRESULT result = dimouse->SetDataFormat(&c_dfDIMouse); //set data format
	if (result != DI_OK) return 0;

	//set do muc do uu tien va an con tro chuot
	result = dimouse->SetCooperativeLevel(hWnd, DISCL_EXCLUSIVE | DISCL_FOREGROUND);
	if (result != DI_OK) return 0;

	result = dimouse->Acquire(); //gianh lay thiet bi chuot
	//if (result != DI_OK) return 0;
	return 1;
}

int Mouse_X()
{
	return mouse_state.lX;
}
int Mouse_Y()
{
	return mouse_state.lY;
}

int Mouse_Button(int button)
{
	return BUTTON_DOWN(mouse_state, button);
}
void Poll_Mouse()
{
	dimouse->GetDeviceState(sizeof(mouse_state), (LPVOID)&mouse_state);
}
void Kill_Mouse()
{
	if (dimouse != NULL)
	{
		dimouse->Unacquire();
		dimouse->Release();
		dimouse = NULL;

	}

}

//Thiet lap cho ban phim
int Init_Keyboard(HWND hWnd)
{
	HRESULT result = dikeyboard->SetDataFormat(&c_dfDIKeyboard); //set data format
	if (result != DI_OK) return 0;

	//set muc do uu tien 
	result = dikeyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (result != DI_OK) return 0;

	result = dikeyboard->Acquire(); //gianh lay thiet bi ban phim,bat dau kiem tra nut duoc nhan
	//if (result != DI_OK) return 0;
	return 1;
}
void Poll_Keyboard()
{
	dikeyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);
}
int Key_Down(int key)
{
	return (keys[key] & 0x80);

}


void Kill_Keyboard()
{
	if (dikeyboard != NULL)
	{
		dikeyboard->Unacquire();
		dikeyboard->Release();
		dikeyboard = NULL;

	}

}