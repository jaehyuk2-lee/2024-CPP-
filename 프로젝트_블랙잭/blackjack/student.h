#pragma once
#include "player.h"

//아래의 코드만 수정할것.
class Student : public Player {
private:
	string name;
	int sum; // 내가 가진 카드 숫자의 합을 저장할 멤버 변수
	int MyCount[14]; // 내가 가진 카드의 개수를 저장하는 배열, index 0은 1로 계산되는 Ace, 1은 11로 계산되는 Ace
	int PlayingCard[13]; // 전체 플레잉 카드의 개수를 저장하는 배열, 전체 카드를 생성할 때 마다 동적할당
	int rSize; // 현재 카드의 개수
	Card dealerCard; // 딜러가 공개한 카드
public:
	Student() {
		name = "2021111971 이재혁"; // 플레이어 이름 설정
		sum = 0; // 내가 받은 카드의 value의 합을 저장하는 멤버 변수
		for (int i = 0; i < 14; i++) {
			MyCount[i] = 0;
		} // 나의 카드 개수 0으로 초기화 
		for (int i = 0; i < 13; i++) {
			PlayingCard[i] = 0;
		} // 전체 플레잉 카드 개수 초기화
	} 
	/*
	* 어떤 행동을 할지 반환하는 매소드
	* HIT = 카드를 계속 받겠다.
	* STAND = 카드 받기를 멈추겠다.
	*/
	Action checkAction() {
		double nextCard = 0; // 다음에 나올 카드의 기댓값을 계산하는 변수
		// 카드 개수 저장

		if (MyCount[1] >= 1) { // 내 핸드에 11로 계산되는 Ace가 있을 때
			if (sum >= 19) {
				nextCard = 0;
				for (int i = 0; i < 2; i++) {
					nextCard += PlayingCard[i];
				} // Ace 2  -> 20 21
				nextCard /= rSize; // 남은 카드에서 위 카드가 나올 확률

				if (nextCard >= 0.5) return Action::HIT; // 확률이 0.5 이상일 때 HIT
				return Action::STAND; // 그렇지 않으면 STAND
			} 

			else if (sum == 18) { // Ace와 7일 때 
				if (dealerCard.getValue() == 9 || dealerCard.getValue() == 10 || dealerCard.getValue() == 11 || dealerCard.getValue() == 12 || dealerCard.getValue() == 13 || dealerCard.getValue() == 1) {
					// 내 패의 합이 18, 딜러가 공개한 카드가 9, 10으로 계산되는 카드, Ace일 때
					// 딜러의 카드 합이 18이상일 확률은 6/13 대략 1/2
					// Ace가 존재하므로 한장을 더 받았을 때 합이 올라갈 확률 3/13

					return Action::HIT; // 승률을 높이기 위해 카드를 더 받는 것이 합리적
				}
				else { // 딜러가 공개한 카드가 낮을 때 HIT시 카드합이 올라가는 확률을 계산
					nextCard = 0;
					for (int i = 0; i < 3; i++) {
						nextCard += PlayingCard[i];
					} // Ace 2 3 -> 19 20 21
					nextCard /= rSize; // 남은 카드에서 위 카드가 나올 확률

					if (nextCard >= 0.5) return Action::HIT; // 확률이 0.5 이상일 때 HIT
					return Action::STAND;
				}
			}
			return Action::HIT; // 이 외에는 HIT
		}
		else {
			// 내 핸드에 Ace가 없거나 1로 계산되는 Ace가 있을 때
			// 21초과시 바로 버스트
			if (sum >= 17) {
				nextCard = 0;
				for (int i = 0; i < 4; i++) {
					nextCard += PlayingCard[i];
				} // Ace 2 3 4  -> 18 19 20 21
				nextCard /= rSize; // 남은 카드에서 위 카드가 나올 확률

				if (nextCard >= 0.7) return Action::HIT; // 확률이 0.7 이상일 때 HIT
				// Ace가 없어 21초과 시 바로 버스트이기 때문에 4개의 경우가 나올 확률이 충분히 클 때
				// HIT를 시도
				return Action::STAND; // 그렇지 않으면 STAND
			}

			else if (sum >= 13 && sum <= 16) {
				if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
					// 내 카드의 합이 13~16 사이일 때 딜러가 공개한 카드가 낮다면
					// 딜러가 합 17이상을 맞추기 위해 카드를 여러번 뽑을 확률이 커지고,
					// 버스트가 발생확률도 커진다
					// 따라서 STAND하는 것이 합리적

					switch (sum) {
						// sum의 케이스 별로 버스트가 나지 않을 확률을 계산해 
						// 그 확률이 절반 이상이면 HIT한다
					case 13:
						nextCard = 0;
						for (int i = 0; i < 8; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// 버스트가 나지 않는 카드가 나올 경우의 수 

						if (nextCard >= 0.5) return Action::HIT;
						// 버스트가 나지 않을 경우가 0.5 이상이면 HIT
						return Action::STAND; // 그렇지 않으면 STAND
					case 14:
						nextCard = 0;
						for (int i = 0; i < 7; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// 버스트가 나지 않는 카드가 나올 경우의 수 

						if (nextCard >= 0.5) return Action::HIT;
						// 버스트가 나지 않을 경우가 0.5 이상이면 HIT
						return Action::STAND; // 그렇지 않으면 STAND
					case 15:
						nextCard = 0;
						for (int i = 0; i < 6; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// 버스트가 나지 않는 카드가 나올 경우의 수 

						if (nextCard >= 0.5) return Action::HIT;
						// 버스트가 나지 않을 경우가 0.5 이상이면 HIT
						return Action::STAND; // 그렇지 않으면 STAND
					case 16:
						nextCard = 0;
						for (int i = 0; i < 5; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// 버스트가 나지 않는 카드가 나올 경우의 수 

						if (nextCard >= 0.5) return Action::HIT;
						// 버스트가 나지 않을 경우가 0.5 이상이면 HIT
						return Action::STAND; // 그렇지 않으면 STAND
					}
				}
				else return Action::HIT; // 딜러의 카드가 충분히 큰 경우 HIT
			}
			else if (sum == 12) {
				if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
					nextCard = 0;
					for (int i = 0; i < 9; i++) {
						nextCard += PlayingCard[i];
					} // Ace ~ 9 -> 13 ~ 21
					nextCard /= rSize;

					if (nextCard >= 0.5) return Action::HIT;
					return Action::STAND;
				}
				else {
					return Action::HIT;
				}
			}
			
			return Action::HIT; // 합이 12이하일 경우 무조건 HIT
		}
	}

	/*
	* 최종 결과 출력에 사용할 이름을 반환하는 매소드
	*/
	string getName() {
		return name;
	}

	/*
	* 딜러가 받은 카드가 뭔지 알 수 있는 매소드
	*/
	void notifyDealerCard(Card card) {
		//cout << "딜러 카드 공개" << "(" << getName(card.getShape()) << ", " << card.getValue() << ")" << endl;
		dealerCard = card; // 딜러가 공개한 카드 저장
		PlayingCard[dealerCard.getValue() - 1]--; // 전체 플레이 카드에서, 딜러 카드 제거
		rSize--; // 플레이 카드 개수 -1
	}

	/*
	* 다른 플레이어가 받은 카드가 뭔지 알 수 있는 매소드
	*/
	void notifyOtherPlayerCard(Card card) {
		//cout << "다른 플레이어 카드" << "(" << getName(card.getShape()) << ", " << card.getValue() << ")" << endl;
		PlayingCard[card.getValue() - 1]--; // 다른 플레이어가 받은 카드 제거
		rSize--; // 플레이 카드 개수 -1
	}

	/*
	* 내가 받은 카드가 뭔지 알 수 있는 매소드
	*/
	void notifyMyCard(Card card) {
		//cout << "받은 카드" << "(" << getName(card.getShape()) << ", " << card.getValue() << ")" << endl;
		PlayingCard[card.getValue() - 1]--; // 내가 받은 카드 제거
		rSize--; // 플레이 카드 개수 -1

		if (card.getValue() == 1) {
			sum += 11; // Ace를 11로 먼저 계산
			MyCount[1]++; // 11로 계산 되는 Ace 개수 + 1
		}
		else if (card.getValue() >= 10) {
			sum += 10; // K, Q, J 는 10으로 계산
			MyCount[card.getValue()]++; // 카드 개수 + 1
		}
		else {
			sum += card.getValue(); // value 만큼 합에 추가
			MyCount[card.getValue()]++; // 카드 개수 + 1
		}

		while (sum > 21 && MyCount[1] > 0) {
			// Ace를 갖고 있고, 합이 21이상일 때 
			sum -= 10; // Ace를 1로 계산
			MyCount[1]--; // 11로 계산되는 Ace - 1
			MyCount[0]++; // 1로 계산되는 Ace + 1
		}
	}

	/*
	* 딜러가 사용하는 카드 더미를 새로 만들어낼때
	* 몇개의 플레잉 카드로 만들어졌는지 알려주는 매소드
	*/
	void notifyCardReset(int cardDeck) {
		//cout << "--- 플레잉 카드 초기화 ---" << endl;
		for (int i = 0; i < 13; i++) {
			PlayingCard[i] = 4 * cardDeck;
		} // 카드문양 * 포커 덱의 개수 = 숫자 개수
		rSize = 4 * cardDeck * 13; // 13개의 숫자 존재
	}

	/*
	* 한번의 라운드가 끝났음을 알려주는 매소드
	*/
	void notifyCompletedRound() {
		//cout << "---------- 라운드 종료 ----------" << endl;
		sum = 0; // 합 초기화 
	}

	/*
	* 카드의 모양을 문자열로 리턴하는 메소드
	*/
	string getName(Shape shape) {
		switch (shape) {
		case 0:
			return "SPADE";
		case 1:
			return "HEART";
		case 2:
			return "DIAMOND";
		case 3:
			return "CLOVER";
		}
	}
};