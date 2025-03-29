///String 관련 함수.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
///문자열 찾기
///string.find()
//특정 문자열을 찾는다. 만약 특정 위치부터 문자열을 찾는다면
///string.find("문자열", 탐색시작위치)
//를 사용하여 특정위치부터 해당 문자열을 찾을 수 있다.
//만약 찾지못하면 string::npos를 반환한다.
///string.back()
//문자열의 맨 마지막 문자를 반환한다.

///문자열 추가
/// + or += 연산자
//특정 문자열뒤에 추가한다.
///string.insert(위치, "문자열")
//특정위치에 특정 문자열을 추가한다.

///문자열 수정(추가도 됨)
///[] 연산자
//[]를 통해 임의 접근후 수정할수 있다. 
///string.replace(위치, 수정하려는 원래 문자열의 길이, "문자열")

///문자열 삭제
///string.erase(인덱스, 삭제할 문자의 갯수);
///string.erase(string::iterator, 삭제할 문자의 갯수);	//오버로딩
//특정 문자열을 삭제할수 있다.
///pop_back()
//문자열의 맨 마지막 문자 하나를 삭제할 수 있다.
///std::remove(string::iterator start, string::iterator end, 문자)
//시작~끝을 탐색하며 l가 아닌 문자들을 앞으로 당긴다, 유효 문자의 새로운 끝의 index를 반환한다.

int main()
{
	string sung = "SungDongJae";
	vector<int> indexs;
	auto e = sung.find("Dong");
	cout << e << endl;

	//찾기
	int pos = 0;
	string targetStr = "ng";
	while ((pos = sung.find(targetStr, pos)) != string::npos)
	{
		indexs.push_back(pos);
		pos += targetStr.size();	  //ng의 크기
	}

	//추가, 수정
	sung.insert(4, " hi ");			//Sung hi DongJae
	targetStr.replace(1, 0, "hello");	//nhellog
	targetStr.replace(1, 4, "hello");	//nhelloog

	//삭제
	string::iterator e1 = std::remove(targetStr.begin(), targetStr.end(), 'l');	//nheoogog
	targetStr.erase(e1, targetStr.end());										//nheoog
	targetStr.erase(1, 4);														//ng

}