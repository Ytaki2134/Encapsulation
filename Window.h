#pragma once
class Window
{
public:
	Window();
	virtual void Init();
	virtual void Open();
	virtual void IsOpen();
	virtual void Clear();
	virtual void Draw();

};

