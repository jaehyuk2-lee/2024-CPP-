#pragma once
#include "player.h"

//�Ʒ��� �ڵ常 �����Ұ�.
class Student : public Player {
private:
	string name;
	int sum; // ���� ���� ī�� ������ ���� ������ ��� ����
	int MyCount[14]; // ���� ���� ī���� ������ �����ϴ� �迭, index 0�� 1�� ���Ǵ� Ace, 1�� 11�� ���Ǵ� Ace
	int PlayingCard[13]; // ��ü �÷��� ī���� ������ �����ϴ� �迭, ��ü ī�带 ������ �� ���� �����Ҵ�
	int rSize; // ���� ī���� ����
	Card dealerCard; // ������ ������ ī��
public:
	Student() {
		name = "2021111971 ������"; // �÷��̾� �̸� ����
		sum = 0; // ���� ���� ī���� value�� ���� �����ϴ� ��� ����
		for (int i = 0; i < 14; i++) {
			MyCount[i] = 0;
		} // ���� ī�� ���� 0���� �ʱ�ȭ 
		for (int i = 0; i < 13; i++) {
			PlayingCard[i] = 0;
		} // ��ü �÷��� ī�� ���� �ʱ�ȭ
	} 
	/*
	* � �ൿ�� ���� ��ȯ�ϴ� �żҵ�
	* HIT = ī�带 ��� �ްڴ�.
	* STAND = ī�� �ޱ⸦ ���߰ڴ�.
	*/
	Action checkAction() {
		double nextCard = 0; // ������ ���� ī���� ����� ����ϴ� ����
		// ī�� ���� ����

		if (MyCount[1] >= 1) { // �� �ڵ忡 11�� ���Ǵ� Ace�� ���� ��
			if (sum >= 19) {
				nextCard = 0;
				for (int i = 0; i < 2; i++) {
					nextCard += PlayingCard[i];
				} // Ace 2  -> 20 21
				nextCard /= rSize; // ���� ī�忡�� �� ī�尡 ���� Ȯ��

				if (nextCard >= 0.5) return Action::HIT; // Ȯ���� 0.5 �̻��� �� HIT
				return Action::STAND; // �׷��� ������ STAND
			} 

			else if (sum == 18) { // Ace�� 7�� �� 
				if (dealerCard.getValue() == 9 || dealerCard.getValue() == 10 || dealerCard.getValue() == 11 || dealerCard.getValue() == 12 || dealerCard.getValue() == 13 || dealerCard.getValue() == 1) {
					// �� ���� ���� 18, ������ ������ ī�尡 9, 10���� ���Ǵ� ī��, Ace�� ��
					// ������ ī�� ���� 18�̻��� Ȯ���� 6/13 �뷫 1/2
					// Ace�� �����ϹǷ� ������ �� �޾��� �� ���� �ö� Ȯ�� 3/13

					return Action::HIT; // �·��� ���̱� ���� ī�带 �� �޴� ���� �ո���
				}
				else { // ������ ������ ī�尡 ���� �� HIT�� ī������ �ö󰡴� Ȯ���� ���
					nextCard = 0;
					for (int i = 0; i < 3; i++) {
						nextCard += PlayingCard[i];
					} // Ace 2 3 -> 19 20 21
					nextCard /= rSize; // ���� ī�忡�� �� ī�尡 ���� Ȯ��

					if (nextCard >= 0.5) return Action::HIT; // Ȯ���� 0.5 �̻��� �� HIT
					return Action::STAND;
				}
			}
			return Action::HIT; // �� �ܿ��� HIT
		}
		else {
			// �� �ڵ忡 Ace�� ���ų� 1�� ���Ǵ� Ace�� ���� ��
			// 21�ʰ��� �ٷ� ����Ʈ
			if (sum >= 17) {
				nextCard = 0;
				for (int i = 0; i < 4; i++) {
					nextCard += PlayingCard[i];
				} // Ace 2 3 4  -> 18 19 20 21
				nextCard /= rSize; // ���� ī�忡�� �� ī�尡 ���� Ȯ��

				if (nextCard >= 0.7) return Action::HIT; // Ȯ���� 0.7 �̻��� �� HIT
				// Ace�� ���� 21�ʰ� �� �ٷ� ����Ʈ�̱� ������ 4���� ��찡 ���� Ȯ���� ����� Ŭ ��
				// HIT�� �õ�
				return Action::STAND; // �׷��� ������ STAND
			}

			else if (sum >= 13 && sum <= 16) {
				if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
					// �� ī���� ���� 13~16 ������ �� ������ ������ ī�尡 ���ٸ�
					// ������ �� 17�̻��� ���߱� ���� ī�带 ������ ���� Ȯ���� Ŀ����,
					// ����Ʈ�� �߻�Ȯ���� Ŀ����
					// ���� STAND�ϴ� ���� �ո���

					switch (sum) {
						// sum�� ���̽� ���� ����Ʈ�� ���� ���� Ȯ���� ����� 
						// �� Ȯ���� ���� �̻��̸� HIT�Ѵ�
					case 13:
						nextCard = 0;
						for (int i = 0; i < 8; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// ����Ʈ�� ���� �ʴ� ī�尡 ���� ����� �� 

						if (nextCard >= 0.5) return Action::HIT;
						// ����Ʈ�� ���� ���� ��찡 0.5 �̻��̸� HIT
						return Action::STAND; // �׷��� ������ STAND
					case 14:
						nextCard = 0;
						for (int i = 0; i < 7; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// ����Ʈ�� ���� �ʴ� ī�尡 ���� ����� �� 

						if (nextCard >= 0.5) return Action::HIT;
						// ����Ʈ�� ���� ���� ��찡 0.5 �̻��̸� HIT
						return Action::STAND; // �׷��� ������ STAND
					case 15:
						nextCard = 0;
						for (int i = 0; i < 6; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// ����Ʈ�� ���� �ʴ� ī�尡 ���� ����� �� 

						if (nextCard >= 0.5) return Action::HIT;
						// ����Ʈ�� ���� ���� ��찡 0.5 �̻��̸� HIT
						return Action::STAND; // �׷��� ������ STAND
					case 16:
						nextCard = 0;
						for (int i = 0; i < 5; i++) {
							nextCard += PlayingCard[i];
						}
						nextCard /= rSize;
						// ����Ʈ�� ���� �ʴ� ī�尡 ���� ����� �� 

						if (nextCard >= 0.5) return Action::HIT;
						// ����Ʈ�� ���� ���� ��찡 0.5 �̻��̸� HIT
						return Action::STAND; // �׷��� ������ STAND
					}
				}
				else return Action::HIT; // ������ ī�尡 ����� ū ��� HIT
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
			
			return Action::HIT; // ���� 12������ ��� ������ HIT
		}
	}

	/*
	* ���� ��� ��¿� ����� �̸��� ��ȯ�ϴ� �żҵ�
	*/
	string getName() {
		return name;
	}

	/*
	* ������ ���� ī�尡 ���� �� �� �ִ� �żҵ�
	*/
	void notifyDealerCard(Card card) {
		//cout << "���� ī�� ����" << "(" << getName(card.getShape()) << ", " << card.getValue() << ")" << endl;
		dealerCard = card; // ������ ������ ī�� ����
		PlayingCard[dealerCard.getValue() - 1]--; // ��ü �÷��� ī�忡��, ���� ī�� ����
		rSize--; // �÷��� ī�� ���� -1
	}

	/*
	* �ٸ� �÷��̾ ���� ī�尡 ���� �� �� �ִ� �żҵ�
	*/
	void notifyOtherPlayerCard(Card card) {
		//cout << "�ٸ� �÷��̾� ī��" << "(" << getName(card.getShape()) << ", " << card.getValue() << ")" << endl;
		PlayingCard[card.getValue() - 1]--; // �ٸ� �÷��̾ ���� ī�� ����
		rSize--; // �÷��� ī�� ���� -1
	}

	/*
	* ���� ���� ī�尡 ���� �� �� �ִ� �żҵ�
	*/
	void notifyMyCard(Card card) {
		//cout << "���� ī��" << "(" << getName(card.getShape()) << ", " << card.getValue() << ")" << endl;
		PlayingCard[card.getValue() - 1]--; // ���� ���� ī�� ����
		rSize--; // �÷��� ī�� ���� -1

		if (card.getValue() == 1) {
			sum += 11; // Ace�� 11�� ���� ���
			MyCount[1]++; // 11�� ��� �Ǵ� Ace ���� + 1
		}
		else if (card.getValue() >= 10) {
			sum += 10; // K, Q, J �� 10���� ���
			MyCount[card.getValue()]++; // ī�� ���� + 1
		}
		else {
			sum += card.getValue(); // value ��ŭ �տ� �߰�
			MyCount[card.getValue()]++; // ī�� ���� + 1
		}

		while (sum > 21 && MyCount[1] > 0) {
			// Ace�� ���� �ְ�, ���� 21�̻��� �� 
			sum -= 10; // Ace�� 1�� ���
			MyCount[1]--; // 11�� ���Ǵ� Ace - 1
			MyCount[0]++; // 1�� ���Ǵ� Ace + 1
		}
	}

	/*
	* ������ ����ϴ� ī�� ���̸� ���� ������
	* ��� �÷��� ī��� ����������� �˷��ִ� �żҵ�
	*/
	void notifyCardReset(int cardDeck) {
		//cout << "--- �÷��� ī�� �ʱ�ȭ ---" << endl;
		for (int i = 0; i < 13; i++) {
			PlayingCard[i] = 4 * cardDeck;
		} // ī�幮�� * ��Ŀ ���� ���� = ���� ����
		rSize = 4 * cardDeck * 13; // 13���� ���� ����
	}

	/*
	* �ѹ��� ���尡 �������� �˷��ִ� �żҵ�
	*/
	void notifyCompletedRound() {
		//cout << "---------- ���� ���� ----------" << endl;
		sum = 0; // �� �ʱ�ȭ 
	}

	/*
	* ī���� ����� ���ڿ��� �����ϴ� �޼ҵ�
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