#define _CRT_SECURE_NO_WARNINGS 1
#include<windows.h>
#include<tchar.h>
#pragma comment (lib,"Urlmon.lib")
//1.�Զ������ļ������� URLDownloadToFile;ע�⣬���������ʵ�÷��㣬�����������ȫ������Ϊ���к���
/*	����ԭ�ͣ�
	HRESULT URLDownloadToFile(LPUNKNOWN pcaller,
								LPCTSTR SzURL,
								LPCTSTR szFileName,
								DWORD dwReserved,
								LPBINDSTATUSCALLBACK lpfnCB);
		pCaller: Pointer to the controlling lUnknown interface of the calling Microsoft ActiveX component (if the caller is an ActiveX compor//�ò���ΪActiveX�ؼ��Ľӿ�ָ�룬�����ǰ������ActiveX�ؼ���дNULL �Ϳ����ˡ�
		sZURL:�ò���ΪҪ���ص�url��ַ������Ϊ�ա�
		szFileName:�����ļ��󣬱�����ļ����֣������ļ��ľ���·����Ϣ��
		dwReserved:�����ֶΣ�����Ϊ0��
		lpfnCB:Pointer to the caller's lBindStatusCallback interface. URLDownloadToFile calls this interface's lBindStatusCallback:OnProgress methoc//���ؽ���״̬�ص��ӿڵ�ָ�롣���Ҫʵʱ���������ļ���״̬��ô��Ҫ�õ���������ˡ�
	����ֵ:
		s_OK:�ɹ�����;
		E_OUTOFMEMORY:���������Ȳ���������û���㹻���ڴ���������صĲ���;INET_E_DOWNLOAD_FAILURE:ָ������Դ���߻ص��ӿ������⡣
	ͷ�ļ�
		#pragma comment(lib,"Urlmon.lib)"

*/
//2.�Զ�ִ���ļ������� ShellExecuteEX
/*
	����ԭ�ͣ�
	BOOL ShellExecuteEx(_Inout_ SHELLEXECUTEINFO *pExecInfo);

	HELLEXECUTEINFO �ṹ���ԭ�ͣ�

	typedef struct _SHELLEXECUTEINFO
		DWORD cbsize;	//�ṹ��С,sizeof(SHELLEXECUTEINFO)
		ULONG fMask ;//ָ���ṹ��Ա����Ч��
		HND hwnd ;	 / /�����ھ�������ʱ��ʾ���󸸴��ڵľ��������ΪNULLL
		PCTSTR lpVerb;//ָ���ú�����ִ�ж���
		LPCTSTR 1pFile;	//��������·��
		LPCTSTR lpParameters;	//ִ�в���������ΪNULL
		LPCTSTR lpDirectory;//����Ŀ¼������ΪMULL
		int nShow;//��ʾ��ʽ
		HINSTANCE hInstApp;		//���������SEE_MASK_NOCLOSEPROCESS ,���ҵ��óɹ����ֵ����32������ʧ���߱����ô���ֵ
		LFVOTD lpIDList;		//ITEHTDLIST�ṹ�ĵ�ַ���洢��Ա���ر��ʶ������flask������SEE_ASK_IDLIST��SEE_NASK_IVOKEIDLISTʱ�������
		LPCTSTR lpClass;//ָ���ļ��������ֻ�GuID����fMask������SEE_MASK_CLASSNAMEʱ�������
		HKEY hkeyClass;		//�������ϵͳע����ļ����͵�Handle����fMask������SEE_MASK_HOTKEYʱ�������
		DMORDdnwfotKkey;		/ /������ȼ���������λ�洢����ؼ���(��ey Code)����λ�洢�޸ı�־λ(HOTKEYF_)����fmask������SEE_MASX_HOTKEYʱ�������
		
		union
			{	
				HANDLE hIcon;	/ /ȡ�ö�Ӧ�ļ����͵�ͼ���Handle����fMask������SEE_MASK_ICONʱ�������
				HNDLE Monitor;	/	/���ĵ���ʾ����ʾ���ϵ�Handle����fMask������SEE_MASK_HMONITORʱ�������}DUIMITYUNIONNAME;
				HANDLE hProcess;	//ָ���������ĳ���ľ������fMask����ΪSEE_MASK_NOCLOSEPROCESs�����ֵΪNULL��
								//��������û����������ʹfMask��ΪSEE_MASK_NOCLOSEPROCESs����ֵҲ��ΪNULL��
								//���û���´������̣�Ҳ��Ϊ��
			}SHELLEXECUTEINFO,*LPSHELLEXECUTEINFO;

		��������ֵ��
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
	//p.lpFile = _T("calc");�򿪼�����
	p.cbSize = sizeof(SHELLEXECUTEINFO);
	p.nShow = SW_SHOW;
	p.fMask = SEE_MASK_NOCLOSEPROCESS;
	p.lpVerb = _T("open");
	if ( ShellExecuteEx(&p)){//��ִ�д��ļ��ɹ�
		if (p.hProcess){
			WaitForSingleObject(p.hProcess, INFINITE);//�ȴ�ִ�����
		}
	}
	/*else{
		CString s;
		s.Format(_T("shellexecutreEX err,erro code:%d"), GetLastError());
		MessageBox(s);
	}*/
	return 0;
}