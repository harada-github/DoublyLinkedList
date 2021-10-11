//============================================================
//
//  title  : �o�������X�g�N���X [doublyLinkedList.h]
//  Author : ���c �z��
//   Date  : 2021/10/07
//  Update : 2021/10/11
//
//============================================================
#pragma once


//============================================================
//�@�C���N���[�h
//============================================================
#include <iostream>
#include <string>
#include "iterator.h"
using namespace std;


//============================================================
//�@�\���̐錾
//============================================================
// ���уf�[�^�\����
struct RecordData
{
	int score;        // �X�R�A
	string userName;  // ���[�U�[��
};


//============================================================
//�@�N���X�錾
//============================================================
class DoublyLinkedList
{
public:
	// �m�[�h�\����
	struct Node
	{
		Node* prevPtr;         // �O�̃m�[�h�ւ̃|�C���^
		Node* nextPtr;         // ���̃m�[�h�ւ̃|�C���^

		RecordData recordData; // ���уf�[�^
	};

	DoublyLinkedList();        // �R���X�g���N�^
	~DoublyLinkedList();       // �f�X�g���N�^

	void AddTop(RecordData addRecordData);  // �擪�Ƀf�[�^��ǉ�
	void AddEnd(RecordData addRecordData);  // �����Ƀf�[�^��ǉ�
	Node* GetTopPtr(void);                  // �擪�̃m�[�h���擾
	Node* GetEndPtr(void);                  // �����̃m�[�h���擾
	void Sort(void);                        // �\�[�g�i���ёւ��j
	void Remove(int num);                   // �f�[�^�̍폜
	int GetDataCount(void);                 // �f�[�^�̐��̎擾

	
	//void Insert();// �f�[�^�̑}��

	
	//Iterator GetTopIterator();        // �擪�C�e���[�^�擾
	//ConstIterator GetConstIterator(); // �擪�R���X�g�C�e���[�^�擾
	//Iterator GetTopIterator();        // �����C�e���[�^�擾
	//ConstIterator GetConstIterator(); // �����R���X�g�C�e���[�^�擾

private:
	
	Node* thisPtr; // �m�[�h�ւ̃|�C���^
};