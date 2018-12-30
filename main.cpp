#include <iostream>
#include <windows.h>

using namespace std;
//

int tmp;
void adb();
void fsb();

void adb1(void);
void adb2(void);
void adb3(void);

void fsb1(void);
void fsb2(void);
void fsb3(void);

int main()
{
	//
	cout<<"Copyright 2018 CSG Studio Reserved.\n";
	system("title CSG刷机工具箱");
	cout<<"欢迎使用CSG团队出品的刷机工具箱\n----------------------------\n使用前请确认你的手机已开启ADB调试,或已进入fastboot模式\n并且已连接电脑!!(划重点)\n----------------------------\n";
	system("pause");
	cout<<"请选择你的连接方式：1.ADB(Recovery)    2.Fastboot\n";
	cin>>tmp;
	if (tmp == 1)
	{
		adb();
	}
	else if (tmp == 2)
	{
		fsb();
	}
	else
	{
		cout<<"这不是一个选项，请退出重新开始噢~\n";
	} 
	return 0;
}

void adb()
{
	system("cls");
	system("title ADB Mode");
	cout<<"请注意是否出现xxxxxxx device的提示\n如果没有，请重新插拔数据线或换一个接口\n（或者看看是不是刚刚选错了\n";
	system("adb devices");
	cout<<"\n------------------\n";
	system("pause");
	cout<<"\n请选择功能：\n1.解锁system（去除boot校验）\n2.安装APP\n3.更换系统桌面（目前仅适配OPPO机型，A21版本以后可能已失效）\n";
	cin>>tmp;
	switch(tmp)
	{
		default : cout<<"不是一个选项噢~";
		case 1 : adb1();break;
		case 2 : adb2();break;
		case 3 : adb3();break;
	}
}


void adb1()//system
{
	//
	system("cls");
	cout<<"本功能适用于小米等设备，可防止恢复官方Recovery\n\n----------------------------\n\n";
	cout<<"按下任意键开始解除校验";
	system("pause>nul");
	system("cls");
	system("adb root");
	system("adb disable-verity");
	cout<<"按下回车重启设备\n";
	system("pause>nul");
	system("adb reboot");
}

void adb2()//app
{
	//
	system("cls");
	cout<<"请将你要安装的APP文件名改为app.apk并移动至同一目录下\n完成操作请按任意键\n----------------------------\n\n";
	system("pause");
	cout<<"开始安装你的APP咯~请等待Success的提示出现~\n\n";
	system("adb install -r app.apk");
}

void adb3()//更换系统桌面 
{
	//
	system("cls");
	cout<<"本功能目前仅适配OPPO，其他系统等待适配\n你也可以将你的系统的启动器包名发送至csgstudio@outlook.com\n\n原理是禁用系统启动器\n所以请事先安装好其他启动器，否则可能无法进入桌面！！\n\n";
	cout<<"请选择你的系统版本：\n1.A21及以前    2.A21以后\n";
	cin>>tmp;
	if (tmp == 1)
	{
		//
		cout<<"请选择：\n1.禁用OPPO Launcher\n2.恢复OPPO Launcher\n\n";
		cin>>tmp;
		if (tmp == 1)
		{
			cout<<"\n\n你选择了禁用OPPO Launcher，请再次确认你已经安装了其他启动器\n\n确认请按任意键\n";
			system("pause>nul");
			cout<<"\n开始执行adb命令，请稍后\n\n";
			system("adb shell pm disable-user com.oppo.launcher");
		}
		if (tmp == 2)
		{
			cout<<"\n\n你选择了恢复OPPO Launcher，正在为你恢复\n";
			system("adb shell pm enable com.oppo.launcher");
		}
	}
	else
	{
		//
		cout<<"A21之后版本无法直接通过ADB命令禁用系统桌面，现提供两种方法：\n1.激活冰箱    2.激活空调狗\n";
		cin>>tmp;
		if (tmp == 1)
		{
			system("cls");
			cout<<"注意事项\n----------------------------\n";
			cout<<"1.索尼手机去除手机SIM卡；小米用户请在开发者选项中关闭[MIUI优化]\n";
			cout<<"2.进入手机[设置-账户]，删除*所有*账户，包括你的Google/小米/华为等系统账号（完成后可重新登录）\n";
			cout<<"3.如果你之前设置过多用户或手机自带访客模式、应用双开等，也需要一并关闭或删除（完成后可重新打开）\n";
			cout<<"\n完成上述步骤后请按任意键继续";
			system("pause>nul");
			cout<<"出现Success之类的字样就成功啦！\n";
			system("adb shell dpm set-device-owner com.catchingnow.icebox/.receiver.DPMReceiver");
			cout<<"\n如果失败，请仔细检查上述过程是否缺漏；\n解除冰箱权限：解冻所有应用，然后到冰箱设置里点击卸载，确认后即可解除";
		}
		if (tmp == 2)
		{
			//
			system("cls");
			cout<<"注意事项\n----------------------------\n";
			cout<<"1.进入手机[设置-账户]，删除*所有*账户，包括你的Google/小米/华为等系统账号（完成后可重新登录）\n";
			cout<<"2.如果你之前设置过多用户或手机自带访客模式、应用双开等，也需要一并关闭或删除（完成后可重新打开）\n";
			cout<<"\n完成上述步骤后请按任意键继续";
			system("pause>nul");
			cout<<"出现Success之类的字样就成功啦！\n";
			system("adb shell dpm set-device-owner me.yourbay.airfrozen/.main.core.mgmt.MDeviceAdminReceiver");
			cout<<"\n如果失败，请仔细检查上述过程是否缺漏；\n解除空调狗权限：解冻所有应用，然后到空调狗设置里点击卸载，确认后即可解除";
		}
	}
}

void fsb()//
{
	//
	system("cls");
	system("title Fastboot Mode");
	cout<<"请注意是否出现xxxxxxx fastboot的提示\n如果没有，请重新插拔数据线或换一个接口\n（或者看看是不是刚刚选错了\n";
	system("fastboot devices");
	cout<<"\n------------------\n";
	system("pause");
	cout<<"\n请选择功能：\n1.刷入recovery\n2.刷入镜像（boot/system）\n3.解锁Bootloader\n";
	cin>>tmp;
	switch(tmp)
	{
		default : cout<<"不是一个选项噢~";
		case 1 : fsb1();break;
		case 2 : fsb2();break;
		case 3 : fsb3();break;
	}
}

void fsb1()//rec
{
	//
	system("cls");
	cout<<"请将你要刷入的Recovery文件名改为recovery.img并移动至同一目录下\n本功能暂时不支持A/B分区设备（如Google Pixel、一加6等）\n完成操作请按任意键\n----------------------------\n\n";
	system("pause");
	cout<<"开始刷入recovery~\n刷完自动进入recovery\n\n";
	system("fastboot flash recovery recovery.img");
	system("fastboot boot recovery.img");
}

void fsb2()//boot/system
{
	//
	system("cls");
	cout<<"（虽然说recovery也是镜像，但是我还是特意把它分开了）\n请选择你要刷入的镜像分区：\n1.boot\n2.system\n\n";
	cin>>tmp;
	if (tmp == 1)
	{
		cout<<endl<<"请将你要刷入的boot文件名改为boot.img并移动至同一目录下\nA/B分区的机型可能会凉凉（如Google Pixel、一加6等）\n完成操作请按任意键\n----------------------------\n\n";
		system("fastboot flash boot boot.img");
	}
	else if (tmp == 2)
	{
		cout<<endl<<"请将你要刷入的system文件名改为system.img并移动至同一目录下\nA/B分区的机型可能会凉凉（如Google Pixel、一加6等）\n完成操作请按任意键\n----------------------------\n\n";
		system("fastboot flash system system.img");
	}
	else
	{
		cout<<"\n这根本不是一个选项！";
	}
}

void fsb3()//bl
{
	//
	system("cls");
	cout<<"再次提醒！！小米和华为机型请绕道，否则机子死了我不负责任233\n\n那么，准备好了吗？按任意键继续吧？\n";
	system("pause");
	cout<<"\n那么开始咯！等到出现Bootloader Lock State : UNLOCKED就是成功啦！\n后续更新会推出BL回锁功能，敬请期待~\n\n";
	system("fastboot oem unlock");
}



















