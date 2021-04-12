#define _CRT_SECURE_NO_WARNINGS 1

/*	1.所有的windows数据类型都是有c/c++c基本数据类型经过类型重定义typedef得到的 SDK中定义的
	2.	DWORD --unsigned long
		HANDLE --void* :typedef PVOID HANDLE ,PVOID --void* :typedef void* PVOID
	3.windows命名规律
		BYTE,CHAR,WORD,SHORT,INT
		指针类型的命名方式是其指向的数据类型前加"LP"或"P"-如：LPWORD,PWORD
		句柄类型在其对象名前面加"H"。如位图BYTEMAP对应句柄为"HBYTEMAP"
		无符号类型以"U"
		常量类型以"C"
		字符串是"STR"
	4.常用的Windows编程数据类型①:
		WPARAM:消息的W参数
		LPARAM:消息的L参数
		INT:32位有符号整型数据类型
		INT32:32位符号整型
		INT64:64位符号整型
		INT_PTR:指向INT数据类型的指针类型
		UINT:无符号INT
	4.2常用的Windows编程数据类型②:
		HANDLE:对象的句柄,最基本的句柄类型
		HICON:图标的句柄
		HINSTANCE:程序实例的句柄
		HKEY:注册表键的句柄
		HMODULE:模块的句柄
		HWND:窗口的句柄
		BOOL:布尔型变量
		BYTE:字节类型（8位)
		CONST:常量
		FLOAT:浮点数据类型
		SIZET:表示内存大小，以字节为单位，其最大值是CPU最大寻址范围
		VOID:无类型,相当于标准C语言中的void
		WINAPI:Windows API的函数调用方式，常见于SDK头文件中对API函数的声明中，相当于stdcall （再严格地说，这不是数据类型，而是一种函数调用约定
	常用的Windows编程数据类型③:
		LPSTR:字符指针,也就是字符串变量
		LPCSTR:字符串常量
		LPCTSTR:根据环境配置,如果定义了UNICODE宏,则是LPCWSTR类型,否则则为LPCSTR类型
		LPCWSTR:UNICODE字符串常量
		LPDWORD:指向DWORD类型数据的指针
		CHAR:8比特字节
		TCHAR:如果定义了UNICODE，则为WCHAR,否则为CHAR
		UCHAR:UCHAR:
		WCHAR:16位Unicode字符
*/