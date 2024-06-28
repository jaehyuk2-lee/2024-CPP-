#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream fin("word.txt", ios::in | ios::binary);
	// 파일을 읽어 올 객체, 읽어올 파일의 경로를 설정
	
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	vector<string> v; // 읽어온 문자를 저장할 벡터
	string tmp; // 파일에서 읽은 문자를 임시로 저장할 변수

	while (getline(fin, tmp)) {
		v.push_back(tmp);
	}
	cout << "...words.txt 파일 로딩 완료" << endl;
	cout << "검색을 시작합니다. 단어를 입력해 주세요." << endl;
	while (1) {
		int is_exist = 0; // 찾는 단어가 존재하는지 확인하는 변수 
		cout << "단어 >> ";
		cin >> tmp; // 임시 저장에 쓴 변수를 입력 변수로 재활용
		if (tmp == "exit") break;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].find(tmp) == 0) {
				is_exist = 1;
				cout << v[i] << endl;
			}
			// 벡터를 모두 확인, 입력받는 문자열로 시작한다면 find(tmp)가 시작 index인 0을 반환
			// 입력한 문자열로 시작하는 단어임을 알 수 있음
			// 찾는 단어가 존재하므로 is_exist 1로 설정
		}
		if (!is_exist) cout << "발견할 수 없음" << endl;
		// is_exist가 여전히 0이라면, 벡터내부에 찾는 단어가 없음
	}
}