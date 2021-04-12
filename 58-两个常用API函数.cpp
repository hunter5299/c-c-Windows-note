#define _CRT_SECURE_NO_WARNINGS 1
#include<windows.h>
#include<tchar.h>
#pragma comment (lib,"Urlmon.lib")
//1.自动下载文件：函数 URLDownloadToFile;注意，这个函数简单实用方便，这个函数被安全厂商视为敏感函数
/*	函数原型：
	HRESULT URLDownloadToFile(LPUNKNOWN pcaller,
								LPCTSTR SzURL,
								LPCTSTR szFileName,
								DWORD dwReserved,
								LPBINDSTATUSCALLBACK lpfnCB);
		pCaller: Pointer to the controlling lUnknown interface of the calling Microsoft ActiveX component (if the caller is an ActiveX compor//该参数为ActiveX控件的接口指针，如果当前程序不是ActiveX控件则写NULL 就可以了。
		sZURL:该参数为要下载的url地址，不能为空。
		szFileName:下载文件后，保存的文件名字，包含文件的具体路径信息。
		dwReserved:保留字段，必需为0。
		lpfnCB:Pointer to the caller's lBindStatusCallback interface. URLDownloadToFile calls this interface's lBindStatusCallback:OnProgress methoc//下载进度状态回调接口的指针。如果要实时监视下载文件的状态那么就要用到这个参数了。
	返回值:
		s_OK:成功下载;
		E_OUTOFMEMORY:缓冲区长度不够，或者没有足够的内存来完成下载的操作;INET_E_DOWNLOAD_FAILURE:指定的资源或者回调接口有问题。
	头文件
		#pragma comment(lib,"Urlmon.lib)"

*/
//2.自动执行文件：函数 ShellExecuteEX
/*
	函数原型：
	BOOL ShellExecuteEx(_Inout_ SHELLEXECUTEINFO *pExecInfo);

	HELLEXECUTEINFO 结构体的原型：

	typedef struct _SHELLEXECUTEINFO
		DWORD cbsize;	//结构大小,sizeof(SHELLEXECUTEINFO)
		ULONG fMask ;//指定结构成员的有效性
		HND hwnd ;	 / /父窗口句柄或出错时显示错误父窗口的句柄，可以为NULLL
		PCTSTR lpVerb;//指定该函数的执行动作
		LPCTSTR 1pFile;	//操作对象路径
		LPCTSTR lpParameters;	//执行参数，可以为NULL
		LPCTSTR lpDirectory;//工作目录，可以为MULL
		int nShow;//显示方式
		HINSTANCE hInstApp;		//如果设置了SEE_MASK_NOCLOSEPROCESS ,并且调用成功则该值大于32，调用失败者被设置错误值
		LFVOTD lpIDList;		//ITEHTDLIST结构的地址，存储成员的特别标识符，当flask不包括SEE_ASK_IDLIST或SEE_NASK_IVOKEIDLIST时该项被忽略
		LPCTSTR lpClass;//指明文件类别的名字或GuID，当fMask不包括SEE_MASK_CLASSNAME时该项被忽略
		HKEY hkeyClass;		//获得已在系统注册的文件类型的Handle，当fMask不包括SEE_MASK_HOTKEY时该项被忽略
		DMORDdnwfotKkey;		/ /程序的热键关联，低位存储虚拟关键码(《ey Code)，高位存储修改标志位(HOTKEYF_)，当fmask不包括SEE_MASX_HOTKEY时该项被忽略
		
		union
			{	
				HANDLE hIcon;	/ /取得对应文件类型的图标的Handle，当fMask不包括SEE_MASK_ICON时该项被忽略
				HNDLE Monitor;	/	/将文档显示在显示器上的Handle，当fMask不包括SEE_MASK_HMONITOR时该项被忽略}DUIMITYUNIONNAME;
				HANDLE hProcess;	//指向新启动的程序的句柄。若fMask不设为SEE_MASK_NOCLOSEPROCESs则该项值为NULL。
								//但若程序没有启动，即使fMask设为SEE_MASK_NOCLOSEPROCESs，该值也仍为NULL。
								//如果没有新创建进程，也会为空
			}SHELLEXECUTEINFO,*LPSHELLEXECUTEINFO;

		函数返回值：
			true,false

	*/
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR IpCmdLine, INT nCmdShow){
	//1.
	/*HRESULT ret = URLDownloadToFile(NULL, _T("https://assets.leetcode-cn.com/aliyun-lc-upload/users/sheng-ming-ji-suan-fa/avatar_1615107938.png?x-oss-process=image%2Fresize%2Ch_40%2Cw_40"),_T("E:\\vs2013C\\123.jpg" ), 0, NULL);
	if (ret == S_OK){
		MessageBox(NULL, _T("download successed!"), _T("tip"), MB_OK);
	}
	else{
		MessageBox(NULL, _T("download faled!"), _T("tip"), MB_OK);
	}*/

	//2.
	SHELLEXECUTEINFO p;
	ZeroMemory(&p,sizeof(SHELLEXECUTEINFO));
	p.lpFile = _T("E:\\vs2013C\\123.jpg");
	//p.lpFile = _T("calc");打开计算器
	p.cbSize = sizeof(SHELLEXECUTEINFO);
	p.nShow = SW_SHOW;
	p.fMask = SEE_MASK_NOCLOSEPROCESS;
	p.lpVerb = _T("open");
	if ( ShellExecuteEx(&p)){//若执行打开文件成功
		if (p.hProcess){
			WaitForSingleObject(p.hProcess, INFINITE);//等待执行完毕
		}
	}
	/*else{
		CString s;
		s.Format(_T("shellexecutreEX err,erro code:%d"), GetLastError());
		MessageBox(s);
	}*/
	return 0;
}