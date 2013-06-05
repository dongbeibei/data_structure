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
	//���캯��
	String();
	//��������
	~Srting();

	//���������ĳ���
	int StrLength();
	//��T��������
	bool StrAssign(char *T);
	//��T����Ϊ����
	bool StrCopy(String &T);
	//�ж������Ƿ�Ϊ��
	bool StrEmpty();
	//��������T���Ա�
	int StrCompare(String &T);
	//�������
	bool ClearString();
	//��������S1��S2���Ӷ���
	bool Concat(String &S1, String &S2);
	//��Sub���������ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
	bool SubString(String &Sub, int pos, int len);

	//���������е�pos���ַ�֮���һ�γ����Ӵ�T��λ�ã����򷵻�0
	int Index(String &T, int pos);
	//��V�滻�����г��ֵ�������T��ȵĲ��ص����Ӵ�������num�滻����
	bool Replace(String &T, String &V, int &num);
	//���ַ����ĵ�pos���ַ�֮ǰ���봮T
	bool StrInsert(int pos, String &T);
	//���ַ����е�pos���ַ��𳤶�Ϊlen���Ӵ�ɾ��
	bool StrDelete(int pos, int len);

private:
	//�ַ�����ʼ�������������캯��������
	bool InitString();
	//�����ַ���������������������
	bool DestoryString();

	//˽������:string
	HString str;
};

#endif
