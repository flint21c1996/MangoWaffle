///String ���� �Լ�.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
///���ڿ� ã��
///string.find()
//Ư�� ���ڿ��� ã�´�. ���� Ư�� ��ġ���� ���ڿ��� ã�´ٸ�
///string.find("���ڿ�", Ž��������ġ)
//�� ����Ͽ� Ư����ġ���� �ش� ���ڿ��� ã�� �� �ִ�.
//���� ã�����ϸ� string::npos�� ��ȯ�Ѵ�.
///string.back()
//���ڿ��� �� ������ ���ڸ� ��ȯ�Ѵ�.

///���ڿ� �߰�
/// + or += ������
//Ư�� ���ڿ��ڿ� �߰��Ѵ�.
///string.insert(��ġ, "���ڿ�")
//Ư����ġ�� Ư�� ���ڿ��� �߰��Ѵ�.

///���ڿ� ����(�߰��� ��)
///[] ������
//[]�� ���� ���� ������ �����Ҽ� �ִ�. 
///string.replace(��ġ, �����Ϸ��� ���� ���ڿ��� ����, "���ڿ�")

///���ڿ� ����
///string.erase(�ε���, ������ ������ ����);
///string.erase(string::iterator, ������ ������ ����);	//�����ε�
//Ư�� ���ڿ��� �����Ҽ� �ִ�.
///pop_back()
//���ڿ��� �� ������ ���� �ϳ��� ������ �� �ִ�.
///std::remove(string::iterator start, string::iterator end, ����)
//����~���� Ž���ϸ� l�� �ƴ� ���ڵ��� ������ ����, ��ȿ ������ ���ο� ���� index�� ��ȯ�Ѵ�.

int main()
{
	string sung = "SungDongJae";
	vector<int> indexs;
	auto e = sung.find("Dong");
	cout << e << endl;

	//ã��
	int pos = 0;
	string targetStr = "ng";
	while ((pos = sung.find(targetStr, pos)) != string::npos)
	{
		indexs.push_back(pos);
		pos += targetStr.size();	  //ng�� ũ��
	}

	//�߰�, ����
	sung.insert(4, " hi ");			//Sung hi DongJae
	targetStr.replace(1, 0, "hello");	//nhellog
	targetStr.replace(1, 4, "hello");	//nhelloog

	//����
	string::iterator e1 = std::remove(targetStr.begin(), targetStr.end(), 'l');	//nheoogog
	targetStr.erase(e1, targetStr.end());										//nheoog
	targetStr.erase(1, 4);														//ng

}