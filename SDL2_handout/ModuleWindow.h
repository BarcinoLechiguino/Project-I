#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

// TODO 1: Create the declaration of ModuleWindow class
class ModuleWindow : public Module
{	 
	//int method();//Declares a method
	bool Init() override;
	bool CleanUp() override;

	//mwin->init();
};

#endif // __ModuleWindow_H__