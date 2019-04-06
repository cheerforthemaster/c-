#include <iostream>
#include <vector>
using namespace std;

int n;//��������
int m;//��Դ����
vector<vector<int>> resource;//��Դ����
vector<vector<int>> process;//��ǰÿ�������ѷ���ĸ�����Դ����
vector<vector<int>> process_need;//��ǰÿ��������Ҫ�ĸ�����Դ�������
vector<vector<int>> work;//��ǰÿ����Դ�ɷ��������
vector<bool> isfinish;//�����Ƿ����

int m_init()//��ʼ��
{
	resource.resize(m);
	for (int i = 0; i < resource.size(); i++)
	{
		resource[i].resize(1);
		resource[i][0] = 2 * n;//ÿ����Դ����Ϊ2*n
	}

	process.resize(n);
	for (int i = 0; i < process.size(); i++)
	{
		process[i].resize(m);
		for (int j = 0; j < process.size(); j++)
		{
			process[i][j] = 0;//��ʼ�ѷ������ԴΪ0
		}
	}

	process_need.resize(n);
	for (int i = 0; i < process_need.size(); i++)
	{
		process_need[i].resize(m);
		for (int j = 0; j < process_need.size(); j++)
		{
			process_need[i][j] = 0;//��ʼ��Ҫ�����ֵΪ0
		}
	}

	work.resize(m);
	for (int i = 0; i < work.size(); i++)
	{
		work[i].resize(1);
		work[i][0] = 2 * n;//ÿ����Դ�ɷ���ĳ�ʼ����Ϊ2*n
	}

	isfinish.resize(n);
	for (int i = 0; i < isfinish.size(); i++)
	{
		isfinish[i] = true;//��ʼ���н��̶�û����
	}

	return 0;
}

int Security_sequence()
{
	int num = 0;//����ɵĽ�����
	int temnum = 0;//��һ�ֱ���������ɵĽ�����
	int *sequence = new int[n];//��ȫ����
	int l = 0;//sequence���±�
	vector<vector<int>> temwork(work);//work����ʱ����
	while (num!=n)
	{
		num = 0;
		for (int i = 0; i < n; i++)
		{
			if (!isfinish[i])//����û�н���
			{
				for (int j = 0; j < m; j++)
				{
					if (process_need[i][j] - process[i][j] > temwork[j][0])//��ǰ��������һ����Դ��������
					{
						break;
					}
					if (j == m - 1)//��ǰ���̿�����ȫ����
					{
						for (int k = 0; k < m; k++)
						{
							temwork[k][0] = temwork[k][0] + process[i][j];//�ͷ���Դ
						}
						isfinish[i] = true;//�ý��̿��Խ���
						sequence[l] = i;//���밲ȫ����
						l++;
					}
				}
			}
			else
				num++;
			if (temnum == num)//������������û�б仯
			{
				break;
			}
			temnum = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << sequence[i] << endl;
	}
	work = temwork;
	return 0;
}


int main()
{
	cout << "�����ܽ�����n��";
	cin >> n;//n=3
	cout << "������Դ����m��";
	cin >> m;//=3

	m_init();

	for (int i = 0; i < n; i++)
	{
		isfinish[i] = 0;
	}

	return 0;
}