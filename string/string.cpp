/*
 * the implementation of the Class String
 */


#include <iostream>
#include "string.h"

using std::cout;
using std::endl;

//构造函数
String::String()
{
	InitString();
}

//析构函数
String::~Srting()
{
	DestoryString();
}



//返回主串的长度
int String::StrLength()
{
	return str.length;
}

//用T生成主串
bool String::StrAssign(char *T)
{
	int i;
	char *c;
	
	if(str.ch)
		free(str.ch);
	for(i=0,c=T ; c ; ++i, ++c);
	if(!i)
	{
		str.ch = NULL;
		str.length = 0;
	}
	else
	{
		if(!(str.ch = (char *)malloc(i*sizeof(char))))
		{
			std::cout<<"malloc fail, Assign fail"<<std::endl;
			return ERROR;
		}
		for(int j=0 ; j<i ; j++)
			str.ch[i] = T[i];
		str.length = i;
	}

	return OK;
}

//将T复制为主串
bool String::StrCopy(String &T)
{
	StrAssign(T.str.ch);
}

//判断主串是否为空
bool String::StrEmpty()
{
	if(0 == str.length)
		return OK;
	else
		return ERROR;
}

//将主串和T作对比
int String::StrCompare(String &T)
{
	for(int i=0 ; i<str.length && i<T.str.length ; ++i)
		if(str.ch[i] != T.str.ch[i])
			return str.ch[i] - T.str.ch[i];

	return str.length - T.str.length;
}

//清空主串
bool String::ClearString()
{
	if(str.ch)
	{
		free(str.ch);
		str.ch = NULL;
	}
	str.length = 0;

	return OK;
}

//将主串由S1和S2连接而成
bool String::Concat(String &S1, String &S2)
{
	int i;

	if(str.ch)
		free(str.ch);
	if(!(str.ch = (char *)malloc((S1.str.length+S2.str.length)*sizeof(char))))
	{
		std::cout<<"malloc fail, Concat fail"<<std::endl;
		return ERROR;
	}

	for(i=0 ; i<S1.str.length ; ++i)
		str.ch[i] = S1.str.ch[i];
	str.length = S1.str.length + S2.str.length;
	for(int j=0 ; i<str.length ; ++i,++j)
		str.ch[i] = S2.str.ch[j];

	return OK;
}

//用Sub返回主串的第pos个字符起长度为len的子串
bool String::SubString(String &Sub, int pos, int len)
{
	if(pos<1 || pos>str.length || len<0 || len>str.length-pos+1)
		return ERROR;

	if(Sub.str.ch)
		free(Sub.str.ch);

	if(!len)
	{
		Sub.str.ch = NULL;
		Sub.str.length = 0;
	}
	else
	{
		Sub.str.ch = (char *)malloc(len*sizeof(char));
		int i=0, j=pos-1;
		for( ; i<len ; ++i,++j)
			Sub.str[i] = str.ch[j];
	}

	return OK;
}



//返回主串中第pos个字符之后第一次出现子串T的位置，否则返回0
int String::Index(String &T, int pos)
{
	if(pos > 0)
	{
		int n = StrLength();
		int m = T.StrLength();
		int i = pos;

		String Sub;
		while(i <= n-m+1)
		{
			SubString(Sub, i, m);
			if(Sub.StrCompare(T) != 0)
				++i;
			else
				return i;
		}
	}

	return 0;
}

//用V替换主串中出现的所有与T相等的不重叠的子串，返回num替换个数
bool String::Replace(String &T, String &V, int &num)
{
	int i = 0;
	int n = StrLength();
	int m = T.StrLength();
	String Sub;

	num = 0;

	while(i <= n-m+1)
	{
		SubString(Sub, i, m);
		if(Sub.StrCompare(T) != 0)
			++i;
		else
		{
			StrDelete(i+1, m);
			StrInsert(i+1, V);
			i += V.StrLength();
			num++;
		}
	}

	return num;
}

//在字符串的第pos个字符之前插入串T
bool String::StrInsert(int pos, String &T)
{
	if(pos<1 || pos>str.length+1)
		return ERROR;

	if(T.length)
	{
		if(!(str.ch = (char *)realloc(str.ch, (str.length+T.str.length)*sizeof(char))))
		{
			std::cout<<"malloc fail, StrInsert fail"<<std::endl;
			return ERROR;
		}
		int i = str.length-1;
		int j = i+T.str.length;
		for( ; i>pos-1 ; --i,--j)
			str.ch[j] = str.ch[i];
		for(i=T.str.length-1 ; i>=0 ; --i,--j)
			str.ch[j] = T.str.ch[i];

		str.length += T.str.length;
	}

	return OK;
}

//将字符串中第pos个字符起长度为len的子串删除
bool String::StrDelete(int pos, int len)
{
	if(pos<1 || pos>str.length-1 || len<0 || pos+len>str.length+1)
		return ERROR;

	int i = 0;
	for( ; i<len-1 ; ++i,++pos)
		str.ch[pos-1] = str.ch[pos-1+i];

	return OK;
}



//字符串初始化函数，被构造函数所调用
bool String::InitString()
{
	str.ch = (char *)malloc(sizeof(char));
	if(!str.ch)
	{
		std::cout<<"malloc fail, init fail"<<std::endl;
		return ERROR;
	}
	str.length = 0;

	return OK;
}

//销毁字符串，被析构函数所调用
bool String::DestoryString()
{
	free(str.ch);
	str.ch = NULL;
	str.length = 0;

	return OK;
}
