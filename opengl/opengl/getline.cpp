//#include<cmath>
//#include<vector>
//using namespace std;
//bool intervel(double a, double b, double c)//a�Ƿ��ڡ�b��c��������
//{
//	double d = c - b;
//	if (d >= 0) {
//		double e = a - b;
//		if (e > 0 && e < d)
//			return true;
//	}
//	else {
//		double e = a - b;
//		if (e < 0 && e > d)
//			return true;
//	}
//	return false;
//}
//vector<vector<double>> getline(vector<vector<double>> &point, double per, bool &is)
//{
//	vector<vector<double>> result;
//	vector<int> tem = { 0, 0,0,0 };//���������ĸ����е���������
//	int i = 0;
//	if (intervel(per, point[0][3], point[1][3])) {
//		tem[i] = 1;
//		i++;
//	}
//	if (intervel(per, point[1][3], point[2][3])) {
//		tem[i] = 2;
//		i++;
//	}
//	if (intervel(per, point[2][3], point[3][3])) {
//		tem[i] = 3;
//		i++;
//	}
//	if (intervel(per, point[3][3], point[0][3])) {
//		tem[i] = 4;
//		i++;
//	}
//	if (i == 0)//ֻ��һ����ֵ��
//	{
//		is = false;
//		return result;
//	}
//	else if (i == 1)
//	{
//		if (per == point[0][3])
//		{
//			if (tem[0] == 2)
//				tem[1] = 4;
//			else
//				tem[1] = 0;
//		}
//		else if (per == point[1][3])
//		{
//			if (tem[0] == 3)
//				tem[1] = 1;
//			else
//				tem[1] = 2;
//		}
//		else if (per == point[2][3])
//		{
//			if (tem[0] == 1)
//				tem[1] = 3;
//			else
//				tem[1] = 2;
//		}
//		else if (per == point[3][3])
//		{
//			if (tem[0] == 1)
//				tem[1] = 3;
//			else
//				tem[1] = 4;
//		}
//		else
//		{
//			is = false;
//			return result;
//		}
//	}
//	else if (i > 3)//����������ֵ��
//	{
//		is = false;
//		return result;
//	}
//	if (tem[0] == 1 && tem[1] == 2)
//	{
//		int i1, i2, j1, j2, k, mode;
//		if (point[0][3] > point[1][3])//���ڵı� �������
//		{
//			mode = 0;
//			i1 = 1;
//			i2 = 0;
//			j1 = 1;
//			j2 = 2;
//			k = 3;
//		}
//		else
//		{
//			mode = 1;
//			i1 = 0;
//			i2 = 1;
//			j1 = 2;
//			j2 = 1;
//			k = 3;
//		}
//		if (mode == 0)
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i1][3] - per) / (point[i1][3] - point[i2][3]);
//			double x1 = point[i2][0] - point[i1][0];//����Ĳ�ֵ
//			double y1 = point[i2][1] - point[i1][1];
//			double z1 = point[i2][2] - point[i1][2];
//			coord.push_back(point[i1][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i1][1] + y1*pro);
//			coord.push_back(point[i1][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (point[k][0] - point[i2][0]);//�ȷֵ������ܲ�ֵ
//			double y2 = (point[k][1] - point[i2][1]);
//			double z2 = (point[k][2] - point[i2][2]);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((point[k][3] - point[i2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[i1][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			x2 = (point[j2][0] - point[k][0]);//�ȷֵ������ܲ�ֵ
//			y2 = (point[j2][1] - point[k][1]);
//			z2 = (point[j2][2] - point[k][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[k][3] + ((point[j2][3] - point[k][3]) / 10)*double(i);//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[i1][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[k][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[k][1] + y2 / 10 * i;
//				z1 = point[k][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x1 = point[j1][0] - point[j2][0];//����Ĳ�ֵ
//			y1 = point[j1][1] - point[j2][1];
//			z1 = point[j1][2] - point[j2][2];
//			coord.push_back(point[j2][0] + x1*pro);//��ֹ������
//			coord.push_back(point[j2][1] + y1*pro);
//			coord.push_back(point[j2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		else
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i2][3] - per) / (point[i2][3] - point[i1][3]);
//			double x1 = point[i1][0] - point[i2][0];//����Ĳ�ֵ
//			double y1 = point[i1][1] - point[i2][1];
//			double z1 = point[i1][2] - point[i2][2];
//			coord.push_back(point[i2][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i2][1] + y1*pro);
//			coord.push_back(point[i2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (x1*pro);//�ȷֵ������ܲ�ֵ
//			double y2 = (y1*pro);
//			double z2 = (z1*pro);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[k][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x2 = pro*(point[j1][0] - point[j2][0]);//�ȷֵ������ܲ�ֵ
//			y2 = pro*(point[j1][1] - point[j2][1]);
//			z2 = pro*(point[j1][2] - point[j2][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[j2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[k][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[j2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[j2][1] + y2 / 10 * i;
//				z1 = point[j2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			coord.push_back(point[j2][0] + x2);//��ֹ������
//			coord.push_back(point[j2][1] + y2);
//			coord.push_back(point[j2][2] + z2);
//			result.push_back(coord);
//			coord.clear();
//		}
//	}
//	else if (tem[0] == 2 && tem[1] == 3)
//	{
//		int i1, i2, j1, j2, k, mode;
//		if (point[1][3] > point[2][3])//���ڵı� �������
//		{
//			mode = 0;
//			i1 = 2;
//			i2 = 1;
//			j1 = 2;
//			j2 = 3;
//			k = 0;
//		}
//		else
//		{
//			mode = 1;
//			i1 = 1;
//			i2 = 2;
//			j1 = 3;
//			j2 = 2;
//			k = 0;
//		}
//		if (mode == 0)
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i1][3] - per) / (point[i1][3] - point[i2][3]);
//			double x1 = point[i2][0] - point[i1][0];//����Ĳ�ֵ
//			double y1 = point[i2][1] - point[i1][1];
//			double z1 = point[i2][2] - point[i1][2];
//			coord.push_back(point[i1][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i1][1] + y1*pro);
//			coord.push_back(point[i1][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (point[k][0] - point[i2][0]);//�ȷֵ������ܲ�ֵ
//			double y2 = (point[k][1] - point[i2][1]);
//			double z2 = (point[k][2] - point[i2][2]);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((point[k][3] - point[i2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[i1][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			x2 = (point[j2][0] - point[k][0]);//�ȷֵ������ܲ�ֵ
//			y2 = (point[j2][1] - point[k][1]);
//			z2 = (point[j2][2] - point[k][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[k][3] + ((point[j2][3] - point[k][3]) / 10)*double(i);//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[i1][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[k][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[k][1] + y2 / 10 * i;
//				z1 = point[k][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x1 = point[j1][0] - point[j2][0];//����Ĳ�ֵ
//			y1 = point[j1][1] - point[j2][1];
//			z1 = point[j1][2] - point[j2][2];
//			coord.push_back(point[j2][0] + x1*pro);//��ֹ������
//			coord.push_back(point[j2][1] + y1*pro);
//			coord.push_back(point[j2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		else
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i2][3] - per) / (point[i2][3] - point[i1][3]);
//			double x1 = point[i1][0] - point[i2][0];//����Ĳ�ֵ
//			double y1 = point[i1][1] - point[i2][1];
//			double z1 = point[i1][2] - point[i2][2];
//			coord.push_back(point[i2][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i2][1] + y1*pro);
//			coord.push_back(point[i2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (x1*pro);//�ȷֵ������ܲ�ֵ
//			double y2 = (y1*pro);
//			double z2 = (z1*pro);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[k][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x2 = pro*(point[j1][0] - point[j2][0]);//�ȷֵ������ܲ�ֵ
//			y2 = pro*(point[j1][1] - point[j2][1]);
//			z2 = pro*(point[j1][2] - point[j2][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[j2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[k][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[j2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[j2][1] + y2 / 10 * i;
//				z1 = point[j2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			coord.push_back(point[j2][0] + x2);//��ֹ������
//			coord.push_back(point[j2][1] + y2);
//			coord.push_back(point[j2][2] + z2);
//			result.push_back(coord);
//			coord.clear();
//		}
//	}
//	else if (tem[0] == 3 && tem[1] == 4)
//	{
//		int i1, i2, j1, j2, k, mode;
//		if (point[2][3] > point[3][3])//���ڵı� �������
//		{
//			mode = 0;
//			i1 = 3;
//			i2 = 2;
//			j1 = 3;
//			j2 = 0;
//			k = 1;
//		}
//		else
//		{
//			mode = 1;
//			i1 = 2;
//			i2 = 3;
//			j1 = 0;
//			j2 = 3;
//			k = 1;
//		}
//		if (mode == 0)
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i1][3] - per) / (point[i1][3] - point[i2][3]);
//			double x1 = point[i2][0] - point[i1][0];//����Ĳ�ֵ
//			double y1 = point[i2][1] - point[i1][1];
//			double z1 = point[i2][2] - point[i1][2];
//			coord.push_back(point[i1][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i1][1] + y1*pro);
//			coord.push_back(point[i1][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (point[k][0] - point[i2][0]);//�ȷֵ������ܲ�ֵ
//			double y2 = (point[k][1] - point[i2][1]);
//			double z2 = (point[k][2] - point[i2][2]);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 10; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((point[k][3] - point[i2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[i1][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			x2 = (point[j2][0] - point[k][0]);//�ȷֵ������ܲ�ֵ
//			y2 = (point[j2][1] - point[k][1]);
//			z2 = (point[j2][2] - point[k][2]);
//			for (int i = 1; i <= 10; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[k][3] + ((point[j2][3] - point[k][3]) / 10)*double(i);//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[i1][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[k][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[k][1] + y2 / 10 * i;
//				z1 = point[k][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x1 = point[j1][0] - point[j2][0];//����Ĳ�ֵ
//			y1 = point[j1][1] - point[j2][1];
//			z1 = point[j1][2] - point[j2][2];
//			coord.push_back(point[j2][0] + x1*pro);//��ֹ������
//			coord.push_back(point[j2][1] + y1*pro);
//			coord.push_back(point[j2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		else
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i2][3] - per) / (point[i2][3] - point[i1][3]);
//			double x1 = point[i1][0] - point[i2][0];//����Ĳ�ֵ
//			double y1 = point[i1][1] - point[i2][1];
//			double z1 = point[i1][2] - point[i2][2];
//			coord.push_back(point[i2][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i2][1] + y1*pro);
//			coord.push_back(point[i2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (x1*pro);//�ȷֵ������ܲ�ֵ
//			double y2 = (y1*pro);
//			double z2 = (z1*pro);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[k][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x2 = pro*(point[j1][0] - point[j2][0]);//�ȷֵ������ܲ�ֵ
//			y2 = pro*(point[j1][1] - point[j2][1]);
//			z2 = pro*(point[j1][2] - point[j2][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[j2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[k][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[j2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[j2][1] + y2 / 10 * i;
//				z1 = point[j2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			coord.push_back(point[j2][0] + x2);//��ֹ������
//			coord.push_back(point[j2][1] + y2);
//			coord.push_back(point[j2][2] + z2);
//			result.push_back(coord);
//			coord.clear();
//		}
//	}
//	else if (tem[0] == 1 && tem[1] == 4)
//	{
//		int i1, i2, j1, j2, k, mode;
//		if (point[1][3] > point[0][3])//���ڵı� �������
//		{
//			mode = 0;
//			i1 = 0;
//			i2 = 1;
//			j1 = 0;
//			j2 = 3;
//			k = 2;
//		}
//		else
//		{
//			mode = 1;
//			i1 = 1;
//			i2 = 0;
//			j1 = 3;
//			j2 = 0;
//			k = 2;
//		}
//		if (mode == 0)
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i1][3] - per) / (point[i1][3] - point[i2][3]);
//			double x1 = point[i2][0] - point[i1][0];//����Ĳ�ֵ
//			double y1 = point[i2][1] - point[i1][1];
//			double z1 = point[i2][2] - point[i1][2];
//			coord.push_back(point[i1][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i1][1] + y1*pro);
//			coord.push_back(point[i1][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (point[k][0] - point[i2][0]);//�ȷֵ������ܲ�ֵ
//			double y2 = (point[k][1] - point[i2][1]);
//			double z2 = (point[k][2] - point[i2][2]);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((point[k][3] - point[i2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[i1][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			x2 = (point[j2][0] - point[k][0]);//�ȷֵ������ܲ�ֵ
//			y2 = (point[j2][1] - point[k][1]);
//			z2 = (point[j2][2] - point[k][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[k][3] + ((point[j2][3] - point[k][3]) / 10)*double(i);//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[i1][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[k][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[k][1] + y2 / 10 * i;
//				z1 = point[k][2] + z2 / 10 * i;
//				double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[i1][1] - y1;
//				double z3 = point[i1][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x1 = point[j1][0] - point[j2][0];//����Ĳ�ֵ
//			y1 = point[j1][1] - point[j2][1];
//			z1 = point[j1][2] - point[j2][2];
//			coord.push_back(point[j2][0] + x1*pro);//��ֹ������
//			coord.push_back(point[j2][1] + y1*pro);
//			coord.push_back(point[j2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		else
//		{
//			vector<double> coord;  //�¶ȵȷֵ�����
//			double pro = (point[i2][3] - per) / (point[i2][3] - point[i1][3]);
//			double x1 = point[i1][0] - point[i2][0];//����Ĳ�ֵ
//			double y1 = point[i1][1] - point[i2][1];
//			double z1 = point[i1][2] - point[i2][2];
//			coord.push_back(point[i2][0] + x1*pro);//��ʼ������
//			coord.push_back(point[i2][1] + y1*pro);
//			coord.push_back(point[i2][2] + z1*pro);
//			result.push_back(coord);
//			coord.clear();
//			double x2 = (x1*pro);//�ȷֵ������ܲ�ֵ
//			double y2 = (y1*pro);
//			double z2 = (z1*pro);
//			double part_per = 0;  //�ȷֵ����
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[i2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = abs((part_per - per) / (part_per - point[k][3]));//�ȷ����ϵ���ֵ�ı���
//				x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[i2][1] + y2 / 10 * i;
//				z1 = point[i2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			x2 = pro*(point[j1][0] - point[j2][0]);//�ȷֵ������ܲ�ֵ
//			y2 = pro*(point[j1][1] - point[j2][1]);
//			z2 = pro*(point[j1][2] - point[j2][2]);
//			for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//			{
//				part_per = point[j2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//				pro = (part_per - per) / (part_per - point[k][3]);//�ȷ����ϵ���ֵ�ı���
//				x1 = point[j2][0] + x2 / 10 * i;       //�ȷֵ������
//				y1 = point[j2][1] + y2 / 10 * i;
//				z1 = point[j2][2] + z2 / 10 * i;
//				double x3 = point[k][0] - x1;//�ȷ��߲�ֵ
//				double y3 = point[k][1] - y1;
//				double z3 = point[k][2] - z1;
//				coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//				coord.push_back(y1 + y3*pro);
//				coord.push_back(z1 + z3*pro);
//				result.push_back(coord);
//				coord.clear();
//			}
//			pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//			coord.push_back(point[j2][0] + x2);//��ֹ������
//			coord.push_back(point[j2][1] + y2);
//			coord.push_back(point[j2][2] + z2);
//			result.push_back(coord);
//			coord.clear();
//		}
//	}
//	else if (tem[0] == 1 && tem[1] == 3)
//	{
//		int i1 = 0, i2, j1 = 0, j2;//���µ����ڵı߽�С���Ǹ��˵�λ��1  ��С�Ķ˵�һ����ͬ��
//		if (point[0][3] >= point[1][3]) {
//			i1 = 1;
//			i2 = 0;
//		}
//		else {
//			i1 = 0;
//			i2 = 1;
//		}
//		if (point[2][3] >= point[3][3]) {
//			j1 = 3;
//			j2 = 2;
//		}
//		else {
//			j1 = 2;
//			j2 = 3;
//		}
//		vector<double> coord;  //�¶ȵȷֵ�����
//		double pro = (point[i2][3] - per) / (point[i2][3] - point[i1][3]);
//		double x1 = point[i1][0] - point[i2][0];//����Ĳ�ֵ
//		double y1 = point[i1][1] - point[i2][1];
//		double z1 = point[i1][2] - point[i2][2];
//		coord.push_back(point[i2][0] + x1*pro);//��ʼ������
//		coord.push_back(point[i2][1] + y1*pro);
//		coord.push_back(point[i2][2] + z1*pro);
//		result.push_back(coord);
//		coord.clear();
//		double x2 = (point[j2][0] - point[i2][0]);//�ȷֵ������ܲ�ֵ
//		double y2 = (point[j2][1] - point[i2][1]);
//		double z2 = (point[j2][2] - point[i2][2]);
//		double part_per = 0;  //�ȷֵ����
//		for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//		{
//			part_per = point[i2][3] + ((point[j2][3] - point[i2][3]) / 10)*i;//�ȷֵ���¶�
//			pro = abs((part_per - per) / (part_per - point[i1][3]));//�ȷ����ϵ���ֵ�ı���
//			x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//			y1 = point[i2][1] + y2 / 10 * i;
//			z1 = point[i2][2] + z2 / 10 * i;
//			double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//			double y3 = point[i1][1] - y1;
//			double z3 = point[i1][2] - z1;
//			coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//			coord.push_back(y1 + y3*pro);
//			coord.push_back(z1 + z3*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//		x2 = pro*(point[j1][0] - point[j2][0]);//�ȷֵ������ܲ�ֵ
//		y2 = pro*(point[j1][1] - point[j2][1]);
//		z2 = pro*(point[j1][2] - point[j2][2]);
//		for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//		{
//			part_per = point[j2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//			pro = (part_per - per) / (part_per - point[i1][3]);//�ȷ����ϵ���ֵ�ı���
//			x1 = point[j2][0] + x2 / 10 * i;       //�ȷֵ������
//			y1 = point[j2][1] + y2 / 10 * i;
//			z1 = point[j2][2] + z2 / 10 * i;
//			double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//			double y3 = point[i1][1] - y1;
//			double z3 = point[i1][2] - z1;
//			coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//			coord.push_back(y1 + y3*pro);
//			coord.push_back(z1 + z3*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//		coord.push_back(point[j2][0] + x2);//��ֹ������
//		coord.push_back(point[j2][1] + y2);
//		coord.push_back(point[j2][2] + z2);
//		result.push_back(coord);
//		coord.clear();
//	}
//	else if (tem[0] == 2 && tem[1] == 4)
//	{
//		int i1 = 0, i2, j1 = 0, j2;//���µ����ڵı߽�С���Ǹ��˵�λ��1  ��С�Ķ˵�һ����ͬ��
//		if (point[1][3] >= point[2][3]) {
//			i1 = 2;
//			i2 = 1;
//		}
//		else {
//			i1 = 1;
//			i2 = 2;
//		}
//		if (point[3][3] >= point[0][3]) {
//			j1 = 0;
//			j2 = 3;
//		}
//		else {
//			j1 = 3;
//			j2 = 0;
//		}
//		vector<double> coord;  //�¶ȵȷֵ�����
//		double pro = (point[i2][3] - per) / (point[i2][3] - point[i1][3]);
//		double x1 = point[i1][0] - point[i2][0];//����Ĳ�ֵ
//		double y1 = point[i1][1] - point[i2][1];
//		double z1 = point[i1][2] - point[i2][2];
//		coord.push_back(point[i2][0] + x1*pro);//��ʼ������
//		coord.push_back(point[i2][1] + y1*pro);
//		coord.push_back(point[i2][2] + z1*pro);
//		result.push_back(coord);
//		coord.clear();
//		double x2 = (point[j2][0] - point[i2][0]);//�ȷֵ������ܲ�ֵ
//		double y2 = (point[j2][1] - point[i2][1]);
//		double z2 = (point[j2][2] - point[i2][2]);
//		double part_per = 0;  //�ȷֵ����
//		for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//		{
//			part_per = point[i2][3] + ((point[j2][3] - point[i2][3]) / 10)*i;//�ȷֵ���¶�
//			pro = abs((part_per - per) / (part_per - point[i1][3]));//�ȷ����ϵ���ֵ�ı���
//			x1 = point[i2][0] + x2 / 10 * i;       //�ȷֵ������
//			y1 = point[i2][1] + y2 / 10 * i;
//			z1 = point[i2][2] + z2 / 10 * i;
//			double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//			double y3 = point[i1][1] - y1;
//			double z3 = point[i1][2] - z1;
//			coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//			coord.push_back(y1 + y3*pro);
//			coord.push_back(z1 + z3*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//		x2 = pro*(point[j1][0] - point[j2][0]);//�ȷֵ������ܲ�ֵ
//		y2 = pro*(point[j1][1] - point[j2][1]);
//		z2 = pro*(point[j1][2] - point[j2][2]);
//		for (int i = 1; i <= 9; i++)//ʮ���ȷֵ�
//		{
//			part_per = point[j2][3] + ((per - point[j2][3]) / 10)*i;//�ȷֵ���¶�
//			pro = (part_per - per) / (part_per - point[i1][3]);//�ȷ����ϵ���ֵ�ı���
//			x1 = point[j2][0] + x2 / 10 * i;       //�ȷֵ������
//			y1 = point[j2][1] + y2 / 10 * i;
//			z1 = point[j2][2] + z2 / 10 * i;
//			double x3 = point[i1][0] - x1;//�ȷ��߲�ֵ
//			double y3 = point[i1][1] - y1;
//			double z3 = point[i1][2] - z1;
//			coord.push_back(x1 + x3*pro);//�ȷ������¶�����
//			coord.push_back(y1 + y3*pro);
//			coord.push_back(z1 + z3*pro);
//			result.push_back(coord);
//			coord.clear();
//		}
//		pro = (point[j2][3] - per) / (point[j2][3] - point[j1][3]);
//		coord.push_back(point[j2][0] + x2);//��ֹ������
//		coord.push_back(point[j2][1] + y2);
//		coord.push_back(point[j2][2] + z2);
//		result.push_back(coord);
//		coord.clear();
//	}
//	else
//	{
//		is = false;
//		return result;
//	}
//	return result;
//}