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
	system("title CSGˢ��������");
	cout<<"��ӭʹ��CSG�Ŷӳ�Ʒ��ˢ��������\n----------------------------\nʹ��ǰ��ȷ������ֻ��ѿ���ADB����,���ѽ���fastbootģʽ\n���������ӵ���!!(���ص�)\n----------------------------\n";
	system("pause");
	cout<<"��ѡ��������ӷ�ʽ��1.ADB(Recovery)    2.Fastboot\n";
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
		cout<<"�ⲻ��һ��ѡ����˳����¿�ʼ��~\n";
	} 
	return 0;
}

void adb()
{
	system("cls");
	system("title ADB Mode");
	cout<<"��ע���Ƿ����xxxxxxx device����ʾ\n���û�У������²�������߻�һ���ӿ�\n�����߿����ǲ��Ǹո�ѡ����\n";
	system("adb devices");
	cout<<"\n------------------\n";
	system("pause");
	cout<<"\n��ѡ���ܣ�\n1.����system��ȥ��bootУ�飩\n2.��װAPP\n3.����ϵͳ���棨Ŀǰ������OPPO���ͣ�A21�汾�Ժ������ʧЧ��\n";
	cin>>tmp;
	switch(tmp)
	{
		default : cout<<"����һ��ѡ����~";
		case 1 : adb1();break;
		case 2 : adb2();break;
		case 3 : adb3();break;
	}
}


void adb1()//system
{
	//
	system("cls");
	cout<<"������������С�׵��豸���ɷ�ֹ�ָ��ٷ�Recovery\n\n----------------------------\n\n";
	cout<<"�����������ʼ���У��";
	system("pause>nul");
	system("cls");
	system("adb root");
	system("adb disable-verity");
	cout<<"���»س������豸\n";
	system("pause>nul");
	system("adb reboot");
}

void adb2()//app
{
	//
	system("cls");
	cout<<"�뽫��Ҫ��װ��APP�ļ�����Ϊapp.apk���ƶ���ͬһĿ¼��\n��ɲ����밴�����\n----------------------------\n\n";
	system("pause");
	cout<<"��ʼ��װ���APP��~��ȴ�Success����ʾ����~\n\n";
	system("adb install -r app.apk");
}

void adb3()//����ϵͳ���� 
{
	//
	system("cls");
	cout<<"������Ŀǰ������OPPO������ϵͳ�ȴ�����\n��Ҳ���Խ����ϵͳ������������������csgstudio@outlook.com\n\nԭ���ǽ���ϵͳ������\n���������Ȱ�װ����������������������޷��������棡��\n\n";
	cout<<"��ѡ�����ϵͳ�汾��\n1.A21����ǰ    2.A21�Ժ�\n";
	cin>>tmp;
	if (tmp == 1)
	{
		//
		cout<<"��ѡ��\n1.����OPPO Launcher\n2.�ָ�OPPO Launcher\n\n";
		cin>>tmp;
		if (tmp == 1)
		{
			cout<<"\n\n��ѡ���˽���OPPO Launcher�����ٴ�ȷ�����Ѿ���װ������������\n\nȷ���밴�����\n";
			system("pause>nul");
			cout<<"\n��ʼִ��adb������Ժ�\n\n";
			system("adb shell pm disable-user com.oppo.launcher");
		}
		if (tmp == 2)
		{
			cout<<"\n\n��ѡ���˻ָ�OPPO Launcher������Ϊ��ָ�\n";
			system("adb shell pm enable com.oppo.launcher");
		}
	}
	else
	{
		//
		cout<<"A21֮��汾�޷�ֱ��ͨ��ADB�������ϵͳ���棬���ṩ���ַ�����\n1.�������    2.����յ���\n";
		cin>>tmp;
		if (tmp == 1)
		{
			system("cls");
			cout<<"ע������\n----------------------------\n";
			cout<<"1.�����ֻ�ȥ���ֻ�SIM����С���û����ڿ�����ѡ���йر�[MIUI�Ż�]\n";
			cout<<"2.�����ֻ�[����-�˻�]��ɾ��*����*�˻����������Google/С��/��Ϊ��ϵͳ�˺ţ���ɺ�����µ�¼��\n";
			cout<<"3.�����֮ǰ���ù����û����ֻ��Դ��ÿ�ģʽ��Ӧ��˫���ȣ�Ҳ��Ҫһ���رջ�ɾ������ɺ�����´򿪣�\n";
			cout<<"\n�������������밴���������";
			system("pause>nul");
			cout<<"����Success֮��������ͳɹ�����\n";
			system("adb shell dpm set-device-owner com.catchingnow.icebox/.receiver.DPMReceiver");
			cout<<"\n���ʧ�ܣ�����ϸ������������Ƿ�ȱ©��\n�������Ȩ�ޣ��ⶳ����Ӧ�ã�Ȼ�󵽱�����������ж�أ�ȷ�Ϻ󼴿ɽ��";
		}
		if (tmp == 2)
		{
			//
			system("cls");
			cout<<"ע������\n----------------------------\n";
			cout<<"1.�����ֻ�[����-�˻�]��ɾ��*����*�˻����������Google/С��/��Ϊ��ϵͳ�˺ţ���ɺ�����µ�¼��\n";
			cout<<"2.�����֮ǰ���ù����û����ֻ��Դ��ÿ�ģʽ��Ӧ��˫���ȣ�Ҳ��Ҫһ���رջ�ɾ������ɺ�����´򿪣�\n";
			cout<<"\n�������������밴���������";
			system("pause>nul");
			cout<<"����Success֮��������ͳɹ�����\n";
			system("adb shell dpm set-device-owner me.yourbay.airfrozen/.main.core.mgmt.MDeviceAdminReceiver");
			cout<<"\n���ʧ�ܣ�����ϸ������������Ƿ�ȱ©��\n����յ���Ȩ�ޣ��ⶳ����Ӧ�ã�Ȼ�󵽿յ�����������ж�أ�ȷ�Ϻ󼴿ɽ��";
		}
	}
}

void fsb()//
{
	//
	system("cls");
	system("title Fastboot Mode");
	cout<<"��ע���Ƿ����xxxxxxx fastboot����ʾ\n���û�У������²�������߻�һ���ӿ�\n�����߿����ǲ��Ǹո�ѡ����\n";
	system("fastboot devices");
	cout<<"\n------------------\n";
	system("pause");
	cout<<"\n��ѡ���ܣ�\n1.ˢ��recovery\n2.ˢ�뾵��boot/system��\n3.����Bootloader\n";
	cin>>tmp;
	switch(tmp)
	{
		default : cout<<"����һ��ѡ����~";
		case 1 : fsb1();break;
		case 2 : fsb2();break;
		case 3 : fsb3();break;
	}
}

void fsb1()//rec
{
	//
	system("cls");
	cout<<"�뽫��Ҫˢ���Recovery�ļ�����Ϊrecovery.img���ƶ���ͬһĿ¼��\n��������ʱ��֧��A/B�����豸����Google Pixel��һ��6�ȣ�\n��ɲ����밴�����\n----------------------------\n\n";
	system("pause");
	cout<<"��ʼˢ��recovery~\nˢ���Զ�����recovery\n\n";
	system("fastboot flash recovery recovery.img");
	system("fastboot boot recovery.img");
}

void fsb2()//boot/system
{
	//
	system("cls");
	cout<<"����Ȼ˵recoveryҲ�Ǿ��񣬵����һ�����������ֿ��ˣ�\n��ѡ����Ҫˢ��ľ��������\n1.boot\n2.system\n\n";
	cin>>tmp;
	if (tmp == 1)
	{
		cout<<endl<<"�뽫��Ҫˢ���boot�ļ�����Ϊboot.img���ƶ���ͬһĿ¼��\nA/B�����Ļ��Ϳ��ܻ���������Google Pixel��һ��6�ȣ�\n��ɲ����밴�����\n----------------------------\n\n";
		system("fastboot flash boot boot.img");
	}
	else if (tmp == 2)
	{
		cout<<endl<<"�뽫��Ҫˢ���system�ļ�����Ϊsystem.img���ƶ���ͬһĿ¼��\nA/B�����Ļ��Ϳ��ܻ���������Google Pixel��һ��6�ȣ�\n��ɲ����밴�����\n----------------------------\n\n";
		system("fastboot flash system system.img");
	}
	else
	{
		cout<<"\n���������һ��ѡ�";
	}
}

void fsb3()//bl
{
	//
	system("cls");
	cout<<"�ٴ����ѣ���С�׺ͻ�Ϊ�������Ƶ���������������Ҳ�������233\n\n��ô��׼�������𣿰�����������ɣ�\n";
	system("pause");
	cout<<"\n��ô��ʼ�����ȵ�����Bootloader Lock State : UNLOCKED���ǳɹ�����\n�������»��Ƴ�BL�������ܣ������ڴ�~\n\n";
	system("fastboot oem unlock");
}



















