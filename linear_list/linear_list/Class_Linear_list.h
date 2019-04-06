#pragma once

template <class T>
class linear_list
{
public:
	linear_list();                    //�������Ա�ռ��С
	~linear_list();

	int Append();                     //ĩβ����һ��Ԫ��
	int Insert(int position);         //����һ��Ԫ��
	int Delete(int position);         //ɾ��һ��Ԫ��
	int Clear();                      //ɾ������Ԫ��
	int Loaction(int position);       //�鿴����һ��Ԫ��
	int Find(T test_data);            //�ⶨ�ض���Ԫ��
	int Length();                     //ͳ�����Ա���
	bool Empty();                     //���Ա��Ƿ�Ϊ��
	int Show();                       //��ʾ����Ԫ��
	bool Resize();                    //�������Ա�ռ�

private:
	int Maxsize;                      //���Ա����ռ�
	T data;                           //����
};

