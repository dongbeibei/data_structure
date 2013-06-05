/*



*/

#ifndef __STRING_H
#define __STRING_H

#include "../base.h"

typedef struct
{
	char	*ch;
	int		length;
}HString;

class String
{
public:
	//构造函数
	String();
	//析构函数
	~Srting();

	//返回主串的长度
	int StrLength();
	//用T生成主串
	bool StrAssign(char *T);
	//将T复制为主串
	bool StrCopy(String &T);
	//判断主串是否为空
	bool StrEmpty();
	//将主串和T作对比
	int StrCompare(String &T);
	//清空主串
	bool ClearString();
	//将主串由S1和S2连接而成
	bool Concat(String &S1, String &S2);
	//用Sub返回主串的第pos个字符起长度为len的子串
	bool SubString(String &Sub, int pos, int len);

	//返回主串中第pos个字符之后第一次出现子串T的位置，否则返回0
	int Index(String &T, int pos);
	//用V替换主串中出现的所有与T相等的不重叠的子串，返回num替换个数
	bool Replace(String &T, String &V, int &num);
	//在字符串的第pos个字符之前插入串T
	bool StrInsert(int pos, String &T);
	//将字符串中第pos个字符起长度为len的子串删除
	bool StrDelete(int pos, int len);

private:
	//字符串初始化函数，被构造函数所调用
	bool InitString();
	//销毁字符串，被析构函数所调用
	bool DestoryString();

	//私有数据:string
	HString str;
};

#endif
