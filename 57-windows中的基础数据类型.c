#define _CRT_SECURE_NO_WARNINGS 1

/*	1.���е�windows�������Ͷ�����c/c++c�����������;��������ض���typedef�õ��� SDK�ж����
	2.	DWORD --unsigned long
		HANDLE --void* :typedef PVOID HANDLE ,PVOID --void* :typedef void* PVOID
	3.windows��������
		BYTE,CHAR,WORD,SHORT,INT
		ָ�����͵�������ʽ����ָ�����������ǰ��"LP"��"P"-�磺LPWORD,PWORD
		����������������ǰ���"H"����λͼBYTEMAP��Ӧ���Ϊ"HBYTEMAP"
		�޷���������"U"
		����������"C"
		�ַ�����"STR"
	4.���õ�Windows����������͢�:
		WPARAM:��Ϣ��W����
		LPARAM:��Ϣ��L����
		INT:32λ�з���������������
		INT32:32λ��������
		INT64:64λ��������
		INT_PTR:ָ��INT�������͵�ָ������
		UINT:�޷���INT
	4.2���õ�Windows����������͢�:
		HANDLE:����ľ��,������ľ������
		HICON:ͼ��ľ��
		HINSTANCE:����ʵ���ľ��
		HKEY:ע�����ľ��
		HMODULE:ģ��ľ��
		HWND:���ڵľ��
		BOOL:�����ͱ���
		BYTE:�ֽ����ͣ�8λ)
		CONST:����
		FLOAT:������������
		SIZET:��ʾ�ڴ��С�����ֽ�Ϊ��λ�������ֵ��CPU���Ѱַ��Χ
		VOID:������,�൱�ڱ�׼C�����е�void
		WINAPI:Windows API�ĺ������÷�ʽ��������SDKͷ�ļ��ж�API�����������У��൱��stdcall �����ϸ��˵���ⲻ���������ͣ�����һ�ֺ�������Լ��
	���õ�Windows����������͢�:
		LPSTR:�ַ�ָ��,Ҳ�����ַ�������
		LPCSTR:�ַ�������
		LPCTSTR:���ݻ�������,���������UNICODE��,����LPCWSTR����,������ΪLPCSTR����
		LPCWSTR:UNICODE�ַ�������
		LPDWORD:ָ��DWORD�������ݵ�ָ��
		CHAR:8�����ֽ�
		TCHAR:���������UNICODE����ΪWCHAR,����ΪCHAR
		UCHAR:UCHAR:
		WCHAR:16λUnicode�ַ�
*/